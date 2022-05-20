using Generater.C;
using ICSharpCode.Decompiler;
using ICSharpCode.Decompiler.CSharp;
using ICSharpCode.Decompiler.TypeSystem;
using Mono.Cecil;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Generater
{
    public static class Binder
    {
        static Queue<CodeGenerater> generaters = new Queue<CodeGenerater>();
        static Dictionary<string, TypeReference> types = new Dictionary<string, TypeReference>();
        static HashSet<ModuleDefinition> moduleSet = new HashSet<ModuleDefinition>();
        static HashSet<TypeReference> moduleTypes;
        static HashSet<TypeReference> refTypes = new HashSet<TypeReference>();

        public static string OutDir;

        private static Dictionary<string, CSharpDecompiler> decompilerDic = new Dictionary<string, CSharpDecompiler>();
        public static DecompilerSettings DecompilerSetting;
        public static string ManagedDir;
        public static ModuleDefinition curModule;

        public static HashSet<string> UnityCoreModuleSet = new HashSet<string>
        {
            "UnityEngine.SharedInternalsModule.dll",
            "UnityEngine.CoreModule.dll"
        };

        public static HashSet<string> retainTypes = Config.Instance.ForceRetainTypes;

        public static void Init(string outDir)
        {
            OutDir = outDir;
            if (Directory.Exists(outDir))
            {
                Directory.Delete(outDir, true);
            }
            Directory.CreateDirectory(outDir);

            Utils.IgnoreTypeSet.UnionWith(Config.Instance.CSharpIgnorTypes);

            Utils.IgnoreMethodsSet.UnionWith(Config.Instance.CSharpIgnorMethods);
            Utils.CSharpForceRetainMethods.UnionWith(Config.Instance.CSharpForceRetainMethods);

            DecompilerSetting = new DecompilerSettings(LanguageVersion.CSharp7);
            DecompilerSetting.ThrowOnAssemblyResolveErrors = false;
            DecompilerSetting.UseExpressionBodyForCalculatedGetterOnlyProperties = false;
        }

        public static void Start()
        {
            GenerateBindings.StartIL2CppAdpater();
        }

        public static void End()
        {
            TypeResolver.WrapperSide = false;
            GenerateBindings.End();

            foreach (var m in moduleSet)
                m.Dispose();

            moduleSet.Clear();
        }

        public static void Bind(string dllPath)
        {
            var file = Path.GetFileName(dllPath);

            ManagedDir = Path.GetDirectoryName(dllPath);
            DefaultAssemblyResolver resolver = new DefaultAssemblyResolver();
            resolver.AddSearchDirectory(ManagedDir);
            ReaderParameters parameters = new ReaderParameters()
            {
                AssemblyResolver = resolver,
                ReadSymbols = false,
            };

            var curAssem = AssemblyDefinition.ReadAssembly(dllPath, parameters);
            curModule = ModuleDefinition.ReadModule(dllPath, parameters);
            moduleSet.Add(curModule);
            ICallGenerater.AddWrapperAssembly(curModule.Assembly.Name.Name);
            var wrapperCompiler = CSCGeneraterManager.GetMonoWrapperCompiler(file, true);
            GenerateBindings.StartMonoWraper(file, wrapperCompiler);

            var adapterCompiler = CSCGeneraterManager.GetIL2CppAdapterCompiler();
            adapterCompiler.AddReference(curModule.Name);
            foreach(var refAssembly in curModule.AssemblyReferences )
            {
                adapterCompiler.AddReference(refAssembly.Name + ".dll");
                wrapperCompiler.AddReference(refAssembly.Name + ".dll");
            }
            wrapperCompiler.RemoveReference(curModule.Name);

            wrapperCompiler.AddCustomAttributes(curAssem.CustomAttributes, Path.Combine(Binder.OutDir, "Mono_" + curAssem.Name.Name));

            moduleTypes = new HashSet<TypeReference>(curModule.Types);

            foreach (TypeDefinition type in moduleTypes)
            {
                if ((!type.IsPublic || type.IsInterface) && !retainTypes.Contains(type.FullName))
                    continue;

                AddType(type);
            }

            TypeResolver.WrapperSide = true;

            while(generaters.Count > 0)
            {
                var gener = generaters.Dequeue();
                if (gener != null)
                    gener.GenerateCode();
            }
            generaters.Clear();

            GenerateBindings.Gen();
        }

        public static void AddType(TypeDefinition type)
        {
            if (type == null || !moduleTypes.Contains(type))
                return;

            if (types.ContainsKey(type.FullName))
                return;
            types[type.FullName] = type;

            if (!Utils.Filter(type))
                return;

            var compiler = CSCGeneraterManager.GetMonoWrapperCompiler(type.Module.Name, false);
            var classGenerater = new ClassGenerater(type, compiler);
            generaters.Enqueue(classGenerater);
            classGenerater.Init();
        }

        public static void AddMethod(MethodReference method)
        {
            var type = method.DeclaringType;
            if (type == null || !moduleTypes.Contains(type))
                return;

            if (!types.ContainsKey(type.FullName))
            {
                AddType(type.Resolve());
            }

            ClassGenerater generater = null;
            foreach (var x in generaters)
            {
                if(x is ClassGenerater && (x as ClassGenerater).GenType == type)
                {
                    generater = x as ClassGenerater;
                }
            }
            if (generater != null)
            {
                generater.AddMethodCalledByOthers(method);
            }
        }

        public static void AddTypeRef(TypeReference type)
        {
            refTypes.Add(type);
            var td = type.Resolve();
            if (td == null)
                return;
            AddType(td);
        }

        public static CSharpDecompiler GetDecompiler(string module)
        {
            CSharpDecompiler decompiler = null;
            
            if (decompilerDic.TryGetValue(module, out decompiler))
                return decompiler;

            var dllPath = Path.Combine(ManagedDir, module);
            decompiler = new CSharpDecompiler(dllPath, DecompilerSetting);
            decompilerDic[module] = decompiler;
            return decompiler;
        }
        
    }
}