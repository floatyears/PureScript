using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Mono.Cecil;
using System.IO;
using ICSharpCode.Decompiler;
using ICSharpCode.Decompiler.CSharp;
using ICSharpCode.Decompiler.TypeSystem;

namespace Generater
{
    /// <summary>
    /// prefab或者场景资源的 脚本对象的反序列化过程是在Unity引擎内实现
    /// mono内运行的interp dlls无法实现这个过程，所以这些interp dlls内的MonoBehaviour/ScriptableObject必须在il2cpp一侧也要有此定义，不然无法正确进行反序列化
    /// 最后在实例化资源对象的过程中，再将il2cpp内的脚本对象的数据复制一份到mono
    /// </summary>
    public class MonoBehaviorProxyManager
    {
        private static string originDir;
        private static string dllRefDir;
        private static string managedDir;
        static HashSet<ModuleDefinition> moduleSet = new HashSet<ModuleDefinition>();
        static ModuleDefinition curModule;
        static HashSet<TypeReference> moduleTypes;
        static Queue<CodeGenerater> generaters = new Queue<CodeGenerater>();
        static Dictionary<string, TypeReference> types = new Dictionary<string, TypeReference>();
        public static DecompilerSettings DecompilerSetting;
        public static Dictionary<string, CSharpDecompiler> DecompilerDic = new Dictionary<string, CSharpDecompiler>();

        public static string DllRefDir {  get { return dllRefDir; } }

        public static void Init(string _originDir, string _managedDir, string _dllRefDir)
        {
            originDir = _originDir;
            managedDir = _managedDir;
            dllRefDir = _dllRefDir;
        }

        public static void GenIL2CppImplement(string dll)
        {
            var dllPath = Path.Combine(originDir, dll);
            
            DecompilerSetting = new DecompilerSettings(LanguageVersion.CSharp7);
            DecompilerSetting.ThrowOnAssemblyResolveErrors = false;
            DecompilerSetting.UseExpressionBodyForCalculatedGetterOnlyProperties = false;

            DefaultAssemblyResolver resolver = new DefaultAssemblyResolver();
            resolver.AddSearchDirectory(originDir);
            ReaderParameters parameters = new ReaderParameters()
            {
                AssemblyResolver = resolver,
                ReadSymbols = false,
            };

            curModule = ModuleDefinition.ReadModule(dllPath, parameters);
            moduleSet.Add(curModule);

            var compiler = CSCGeneraterManager.GetMonoBehaviourProxyWrapper(dll);

            foreach (var refAssembly in curModule.AssemblyReferences)
            {
                compiler.AddReference(refAssembly.Name + ".dll");
            }
            //compiler.RemoveReference(curModule.Name);
            moduleTypes = new HashSet<TypeReference>(curModule.Types);


            var monoBehaviourTypes = curModule.Types.ToList().FindAll(x => x.IsSubclassOf("UnityEngine.MonoBehaviour"));
            var scriptableObjectTypes = curModule.Types.ToList().FindAll(x => x.IsSubclassOf("UnityEngine.ScriptableObject"));

            foreach (TypeDefinition type in monoBehaviourTypes)
            {
                if (!Utils.IsTypeSerializable(type))
                    continue;

                AddType(type);
            }

            foreach (TypeDefinition type in scriptableObjectTypes)
            {
                if (!Utils.IsTypeSerializable(type))
                    continue;

                AddType(type);
            }

            while (generaters.Count > 0)
            {
                var gener = generaters.Dequeue();
                if (gener != null)
                    gener.GenerateCode();
            }
            generaters.Clear();

            
            //var file = $"Gen.il2cpp.MonoBehaviourProxy.cs";
            //var dir1 = Path.Combine(Binder.OutDir, "IL2Cpp", file);
            //Directory.CreateDirectory(dir1);
            //var path = Path.Combine(dir1, name);
            //var writer = File.CreateText(path);
        }

        public static void AddType(TypeDefinition type)
        {
            if (type == null || !moduleTypes.Contains(type))
                return;

            if (types.ContainsKey(type.FullName))
                return;
            types[type.FullName] = type;

            if (!Utils.IsTypeSerializable(type))
                return;

            var compiler = CSCGeneraterManager.GetMonoBehaviourProxyWrapper(type.Module.Name);
            generaters.Enqueue(new MonoBehaviorProxyGenerator(type, compiler));

        }

        public static CSharpDecompiler GetDecompiler(string module)
        {
            CSharpDecompiler decompiler = null;

            if (DecompilerDic.TryGetValue(module, out decompiler))
                return decompiler;

            var dllPath = Path.Combine(originDir, module);
            decompiler = new CSharpDecompiler(dllPath, DecompilerSetting);
            DecompilerDic[module] = decompiler;
            return decompiler;
        }

        public static void End()
        {

            foreach (var m in moduleSet)
                m.Dispose();

            moduleSet.Clear();
        }
    }
}
