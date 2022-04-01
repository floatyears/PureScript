using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Generater
{
    public class CSCGenerater
    {
        static string[] addtionFlag = new string[]
        {
            "-t:library",
            "-unsafe",
        };
        static string[] addtionRef = new string[]
        {
            "mscorlib.dll",
            //"UnityEngine.CoreModule.dll",
            //"PureScript.dll",
        };

        private static string CSCPath = "csc";


        private static string[] AdapterSrc = new string[]
        {
            "glue/Binder.impl.cs",
            "Tools/CustomBinder.cs",
            "Tools/ObjectStore.cs",
        };

        private static string[] AdapterWrapperSrc = new string[]
        {
            "Tools/CustomBinder.cs",
            "Tools/ObjectStore.wrapper.cs",
            "Tools/ScriptEngine.cs",
            
        };

        public static CSCGenerater AdapterCompiler;
        public static CSCGenerater AdapterWrapperCompiler;
        private static string OutDir;
        private static string DllRefDir;
        private static string AdapterDir;
        private static HashSet<string> IgnoreRefSet = new HashSet<string>();
        private static Dictionary<string, CSCGenerater> WrapperDic = new Dictionary<string, CSCGenerater>();
        private static List<BindGenerater.AsesemblyCheck> asesemblyCheck;
        public static Mono.Cecil.AssemblyDefinition corlib;

        public static void Init(string cscDir,string adapterDir, string outDir, HashSet<string> ignoreRefSet, List<BindGenerater.AsesemblyCheck> assemblyChk)
        {
            CSCPath = Path.Combine(cscDir, Utils.IsWin32() ? "csc.exe":"csc") ;
            OutDir = outDir;
            DllRefDir = outDir;
            AdapterDir = adapterDir;
            IgnoreRefSet = ignoreRefSet;
            AdapterCompiler = new CSCGenerater(Path.Combine(outDir, "Adapter.gen.dll"));
            
            foreach(var file in AdapterSrc)
                AdapterCompiler.AddSource(Path.Combine(adapterDir,file));
            AdapterCompiler.refSet.Add("PureScript.dll");

            SetWrapper("Adapter.wrapper.dll");
            foreach (var file in AdapterWrapperSrc)
                AdapterWrapperCompiler.AddSource(Path.Combine(adapterDir, file));

            asesemblyCheck = assemblyChk;
        }

        public static void SetWrapper(string dllName)
        {
            if (!WrapperDic.TryGetValue(dllName,out AdapterWrapperCompiler))
            {
                AdapterWrapperCompiler = new CSCGenerater(Path.Combine(OutDir, dllName));
                //foreach (var file in AdapterWrapperSrc)
                //    AdapterWrapperCompiler.AddSource(Path.Combine(AdapterDir, file));
                AdapterWrapperCompiler.AddDefine("WRAPPER_SIDE");
                if (!Utils.IsWin32())
                    AdapterWrapperCompiler.AddDefine("IOS");

                WrapperDic[dllName] = AdapterWrapperCompiler;

                if (dllName != "Adapter.wrapper.dll")
                    AdapterWrapperCompiler.AddReference("Adapter.wrapper.dll");
            }
        }

        public static void End()
        {
            AdapterCompiler.Gen();
            //AdapterWrapperCompiler.Gen();
            var list = GetSortedList();
            foreach (var wrapper in list)
            {
                wrapper.Gen();
            }

            for(var i = 0; i < asesemblyCheck.Count; i++)
            {
                var check = asesemblyCheck[i];
                var checker = new CSCGenerater(Path.Combine(OutDir, check.Assembly));
                checker.AddReference(AdapterCompiler.outName);
                checker.AddReference("System.dll");
                checker.AddReference("System.Core.dll");
                foreach (var wrapper in list)
                {
                    checker.AddReference(wrapper.outName);
                }
                for(int j = 0; j < i; j++)
                {
                    checker.AddReference(Path.Combine(OutDir, asesemblyCheck[j].Assembly));
                }
                foreach (var f in Directory.GetFiles(check.Source, check.Filter, SearchOption.AllDirectories))
                {
                    checker.AddSource(f);
                }
                checker.AddDefine("UNITY_ANDROID");
                checker.Gen();
            }
        }

        private static List<CSCGenerater> GetSortedList()
        {
            foreach (var wrapper in WrapperDic.Values)
            {
                CountRef(wrapper);
            }
            var list = new List<CSCGenerater>(WrapperDic.Values);
            list.Sort((a, b) => { return b.RefCount - a.RefCount; });
            return list;
        }

        private static void CountRef(CSCGenerater gener)
        {
            foreach (var depend in gener.refSet)
            {
                if (WrapperDic.TryGetValue(depend, out var dependGener))
                {
                    dependGener.RefCount++;
                    CountRef(dependGener);
                }
            }
        }


        public string outName { get; private set; }
        public HashSet<string> refSet = new HashSet<string>();
        public int RefCount = 0;
        HashSet<string> srcSet = new HashSet<string>();
        HashSet<string> defineSet = new HashSet<string>();

        public CSCGenerater(string targetName)
        {
            outName = Path.GetFullPath(targetName);
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

        public void Gen()
        {
            var fName = $"{Path.GetFileName(outName)}.txt";
            using(var config = File.CreateText(fName))
            {
                config.WriteLine($"-out:{outName}");
                foreach (var flag in addtionFlag)
                    config.WriteLine(flag);
                foreach (var refFile in addtionRef)
                    config.WriteLine($"-r:{Path.Combine(DllRefDir, refFile)}");
                foreach (var refFile in refSet)
                    config.WriteLine($"-r:{Path.Combine(DllRefDir, refFile)}");
                foreach (var define in defineSet)
                    config.WriteLine($"-define:{define}");

                var netstandFile = Path.Combine(OutDir, "netstandard.dll");
                if(File.Exists(netstandFile))
                    config.WriteLine($"-r:{Path.Combine(DllRefDir, netstandFile)}");

                foreach (var src in srcSet)
                    config.WriteLine(src);
            }

            int res = Utils.RunCMD(CSCPath, new string[] { $"@{fName}" });
            if (res != 0)
                throw new Exception($"Run CSC error,with: {CSCPath} @{fName}");
        }
        /*public void AddTypeForwardedTo(string typeName)
        {

        }*/
    }
}
