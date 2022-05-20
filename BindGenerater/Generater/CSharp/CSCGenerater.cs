using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Mono.Cecil;

namespace Generater
{
    public class CSCGeneraterManager
    {
        public static string[] addtionFlag = new string[]
        {
            "-t:library",
            "-unsafe",
        };
        public static string[] addtionRef = new string[]
        {
            "mscorlib.dll",
            "System.dll",
            //"UnityEngine.CoreModule.dll",
            //"PureScript.dll",
        };

        public static string CSCPath = "csc";


        private static string[] AdapterSrc = new string[]
        {
            "glue/IL2Cpp/Binder.il2cpp.cs",
            "Tools/CustomBinder.cs",
            "Tools/ObjectStore.cs",
        };

        private static string[] AdapterWrapperSrc = new string[]
        {
            "Tools/CustomBinder.cs",
            "Tools/ObjectStore.wrapper.cs",
            "Tools/ScriptEngine.cs",

        };

        private static CSCGenerater adapterCompiler;
        //public static CSCGenerater AdapterWrapperCompiler;
        private static string monoManagedDir;
        private static string il2cppManagedDir;
        public static string AdapterDir;
        public static string OriginDir;
        private static HashSet<string> IgnoreRefSet = new HashSet<string>();
        private static Dictionary<string, CSCGenerater> wrapperDic = new Dictionary<string, CSCGenerater>();
        private static Dictionary<string, CSCGenerater> monoBehaviourProxyDic = new Dictionary<string, CSCGenerater>();
        private static List<BindGenerater.AsesemblyCheck> asesemblyCheck;
        public static Mono.Cecil.AssemblyDefinition corlib;
        private static BindGenerater.BuildTargetPlatform targetPlatform;

        public static void Init(string cscDir, string adapterDir, string originDir, string _monoManagedDir, string _il2cppManagedDir, BindGenerater.BuildTargetPlatform platform, HashSet<string> ignoreRefSet, List<BindGenerater.AsesemblyCheck> assemblyChk)
        {
            CSCPath = Path.Combine(cscDir, Utils.IsWin32() ? "csc.exe" : "csc");
            monoManagedDir = _monoManagedDir;
            il2cppManagedDir = _il2cppManagedDir;
            AdapterDir = adapterDir;
            IgnoreRefSet = ignoreRefSet;
            OriginDir = originDir;
            targetPlatform = platform;

            var wrapperComp = GetMonoWrapperCompiler("Adapter.wrapper.dll", true);
            foreach (var file in AdapterWrapperSrc)
                wrapperComp.AddSource(Path.Combine(adapterDir, file));

            asesemblyCheck = assemblyChk;

            corlib = AssemblyDefinition.ReadAssembly(Path.Combine(monoManagedDir, "mscorlib.dll"));
        }

        public static CSCGenerater GetIL2CppAdapterCompiler()
        {
            if(adapterCompiler == null)
            {
                adapterCompiler = new CSCGenerater(Path.Combine(il2cppManagedDir, "Adapter.gen.dll"), DllRuntime.IL2Cpp, il2cppManagedDir);
                adapterCompiler.AddPlatformDefine(targetPlatform);

                foreach (var file in AdapterSrc)
                    adapterCompiler.AddSource(Path.Combine(AdapterDir, file));
                adapterCompiler.refSet.Add("PureScript.dll");
            }

            return adapterCompiler;
        }

        public static CSCGenerater GetMonoWrapperCompiler(string dllName, bool createWhenNULL = false)
        {
            if (!wrapperDic.TryGetValue(dllName, out var adapterWrapperCompiler))
            {
                if(!createWhenNULL)
                {
                    return null;
                }
                adapterWrapperCompiler = new CSCGenerater(Path.Combine(monoManagedDir, dllName), DllRuntime.Mono, monoManagedDir);
                //foreach (var file in AdapterWrapperSrc)
                //    AdapterWrapperCompiler.AddSource(Path.Combine(AdapterDir, file));
                adapterWrapperCompiler.AddDefine("WRAPPER_SIDE");
                adapterWrapperCompiler.AddPlatformDefine(targetPlatform);

                wrapperDic[dllName] = adapterWrapperCompiler;

                if (dllName != "Adapter.wrapper.dll")
                    adapterWrapperCompiler.AddReference("Adapter.wrapper.dll");
            }
            return adapterWrapperCompiler;
        }

        public static void CompileAdapterAndWrapperDll()
        {
            adapterCompiler.CompileDll();
            //AdapterWrapperCompiler.Gen();
            var list = GetSortedList(wrapperDic);
            foreach (var wrapper in list)
            {
                wrapper.CompileDll();
            }

            for (var i = 0; i < asesemblyCheck.Count; i++)
            {
                var check = asesemblyCheck[i];
                var checker = new CSCGenerater(Path.Combine(monoManagedDir, check.Assembly), DllRuntime.Mono, monoManagedDir);
                checker.AddReference(adapterCompiler.outName);
                checker.AddReference("System.dll");
                checker.AddReference("System.Core.dll");
                foreach (var wrapper in list)
                {
                    checker.AddReference(wrapper.outName);
                }
                for (int j = 0; j < i; j++)
                {
                    checker.AddReference(Path.Combine(monoManagedDir, asesemblyCheck[j].Assembly));
                }
                foreach (var f in Directory.GetFiles(check.Source, check.Filter, SearchOption.AllDirectories))
                {
                    checker.AddSource(f);
                }
                checker.AddPlatformDefine(targetPlatform);
                checker.CompileDll();
            }
        }

        public static void CompileIL2CppMonoBehaviourProxyDll()
        {
            var list = GetSortedList(monoBehaviourProxyDic);
            foreach (var wrapper in list)
            {
                wrapper.CompileDll();
            }
        }

        private static List<CSCGenerater> GetSortedList(Dictionary<string, CSCGenerater> dic)
        {
            foreach (var wrapper in dic.Values)
            {
                CountRef(wrapper, dic);
            }
            var list = new List<CSCGenerater>(dic.Values);
            list.Sort((a, b) => { return b.RefCount - a.RefCount; });
            return list;
        }

        private static void CountRef(CSCGenerater gener, Dictionary<string, CSCGenerater> dic)
        {
            foreach (var depend in gener.refSet)
            {
                if (dic.TryGetValue(depend, out var dependGener))
                {
                    dependGener.RefCount++;
                    CountRef(dependGener, dic);
                }
            }
        }

        public static CSCGenerater GetMonoBehaviourProxyWrapper(string dllName)
        {
            if (!monoBehaviourProxyDic.TryGetValue(dllName, out var monoBehaviourProxyCompiler))
            {
                monoBehaviourProxyCompiler = new CSCGenerater(Path.Combine(il2cppManagedDir, dllName), DllRuntime.IL2Cpp, il2cppManagedDir);
                //foreach (var file in AdapterWrapperSrc)
                //    AdapterWrapperCompiler.AddSource(Path.Combine(AdapterDir, file));
                monoBehaviourProxyCompiler.AddPlatformDefine(targetPlatform);

                monoBehaviourProxyDic[dllName] = monoBehaviourProxyCompiler;

                monoBehaviourProxyCompiler.AddReference("PureScript.dll");
                if (dllName != "Adapter.gen.dll")
                    monoBehaviourProxyCompiler.AddReference("Adapter.gen.dll");
            }

            return monoBehaviourProxyCompiler;
        }

    }

    public enum DllRuntime
    {
        None = 0,
        Mono = 0x1,
        IL2Cpp = 0x2,
        MonoAndIL2Cpp = 0x3,
    }

    public class CSCGenerater 
    { 
        public string outName { get; private set; }
        public HashSet<string> refSet = new HashSet<string>();
        public int RefCount = 0;
        HashSet<string> srcSet = new HashSet<string>();
        HashSet<string> defineSet = new HashSet<string>();
        private string dllRefDir = null;

        public DllRuntime Runtime { private set; get; }

        public void SetDllRefDir(string dir)
        {
            dllRefDir = dir;
        }

        public CSCGenerater(string destPath, DllRuntime runtime, string refDir)
        {
            outName = Path.GetFullPath(destPath);
            Runtime = runtime;
            dllRefDir = refDir;
        }

        public void SetRuntime(DllRuntime runtime)
        {
            Runtime = runtime;
        }

        public void AddCustomAttributes(Mono.Collections.Generic.Collection<CustomAttribute> customAttributes, string sourceDir)
        {
            var assemblyInfo = Path.Combine(sourceDir, "AssemblyInfo.cs");
            var writer = new CodeWriter(File.CreateText(assemblyInfo), Runtime == DllRuntime.Mono ? CodeWriter.CodeWriterType.MonoBind : CodeWriter.CodeWriterType.UnityBind);
            writer.WriteLine("using System.Runtime.CompilerServices");
            writer.WriteLine("using UnityEngine");

            foreach (var attr in customAttributes)
            {
                if(attr.AttributeType.Name == "InternalsVisibleToAttribute")
                {
                    if(attr.ConstructorArguments.Count > 0)
                    {
                        writer.WriteLine($"[assembly: InternalsVisibleTo(\"{attr.ConstructorArguments[0].Value}\")]", false);
                    }
                }
            }
            writer.Flush();
            AddSource(assemblyInfo);
        }

        public void AddReference(string target)
        {
            //if(!IgnoreRefSet.Contains(target))
                refSet.Add(target.Replace("\\", "/"));
        }
        public void RemoveReference(string target)
        {
            //if(!IgnoreRefSet.Contains(target))
            refSet.Remove(target);
        }

        public void AddSource(string file)
        {
            var path = Path.GetFullPath(file).Replace("\\", "/");
            srcSet.Add(path);
        }

        public void AddDefine(string define)
        {
            defineSet.Add(define);
        }

        public void AddPlatformDefine(BindGenerater.BuildTargetPlatform platform)
        {
            if (platform == BindGenerater.BuildTargetPlatform.iOS)
            {
                AddDefine("IOS");
                AddDefine("UNITY_IOS");
            }
            else if(platform == BindGenerater.BuildTargetPlatform.Android)
            {
                AddDefine("UNITY_ANDROID");
            }
            else if (platform == BindGenerater.BuildTargetPlatform.StandaloneWindows)
            {
                AddDefine("UNITY_WIN");
            }
            else if (platform == BindGenerater.BuildTargetPlatform.StandaloneWindows64)
            {
                AddDefine("UNITY_WIN64");
            }
        }

        public void CompileDll()
        {
            var fName = $"{Path.GetFileName(outName)}.txt";
            using (var config = File.CreateText(fName))
            {
                config.WriteLine($"-out:{outName}");
                foreach (var flag in CSCGeneraterManager.addtionFlag)
                    config.WriteLine(flag);
                foreach (var refFile in CSCGeneraterManager.addtionRef)
                    config.WriteLine($"-r:{Path.GetFullPath(Path.Combine(dllRefDir, refFile))}");
                foreach (var refFile in refSet)
                    config.WriteLine($"-r:{Path.GetFullPath(Path.Combine(dllRefDir, refFile))}");
                foreach (var define in defineSet)
                    config.WriteLine($"-define:{define}");
                if(true)
                {
                    config.WriteLine($"-debug:embedded");
                }

                var netstandFile = Path.Combine(dllRefDir, "netstandard.dll");
                if(File.Exists(netstandFile))
                    config.WriteLine($"-r:{Path.Combine(dllRefDir, netstandFile)}");

                foreach (var src in srcSet)
                    config.WriteLine(src);
            }

            int res = Utils.RunCMD(CSCGeneraterManager.CSCPath, new string[] { $"@{fName}" });
            if (res != 0)
                throw new Exception($"Run CSC error,with: {CSCGeneraterManager.CSCPath} @{fName}");
        }
        /*public void AddTypeForwardedTo(string typeName)
        {

        }*/
    }
}
