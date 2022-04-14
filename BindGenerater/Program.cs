﻿using Generater;
using Generater.C;
using Mono.Cecil;
using Newtonsoft.Json;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


namespace BindGenerater
{
    public class AsesemblyCheck
    {
        public string Assembly;
        public string Source;
        public string Filter;
    }

    class Program
    {

        class BindOptions
        {
            public string ScriptEngineDir;
            public HashSet<string> AdapterSet;
            public HashSet<string> InterpSet;
            public HashSet<string> Entry;
            public List<AsesemblyCheck> AssembliesCheck;
        }
        public enum BindTarget
        {
            Adapter,
            All,
        }

        public enum TargetPlatform
        {
            Android,
            iOS,
            StandaloneWindows,
            StandaloneWindows64,
        }

        static BindOptions options;

        public static string ToolsetPath;
        public static BindTarget Mode;
        public static TargetPlatform Platform;

        static int Main(string[] args)
        {
            //TestWriter();
            //return;
            Console.WriteLine("OS: " + Environment.OSVersion);

            //StartBinder(args);
            //StartTestBinder();
             try
             {
                 StartBinder(args);
                 //StartTestBinder();
                 Utils.Log("Binder All Done..");
             }
             catch(Exception e)
             {
                 Console.Error.WriteLine(e.ToString());
                //Console.ReadKey();
                 return 2;
            }
            return 0;
        }

        static void StartBinder(string[] args)
        {
            if (args.Length < 2)
                return;
            var configFile = args[0];
            ToolsetPath = args[1];
            if (args.Length >= 3)
                Mode = (BindTarget)Enum.Parse(typeof(BindTarget), args[2]);
            else
                Mode = BindTarget.All;
            if(args.Length >= 4)
                Platform = (TargetPlatform)Enum.Parse(typeof(TargetPlatform), args[3]);
            else
                Platform = TargetPlatform.Android;

            Console.WriteLine("start binder..");
            Directory.SetCurrentDirectory(Path.GetDirectoryName(configFile));

            var json = File.ReadAllText(configFile);
            options = JsonConvert.DeserializeObject<BindOptions>(json);

            string managedDir = Path.Combine(options.ScriptEngineDir, "Managed");
            string orignDir = Path.Combine(options.ScriptEngineDir, "Managed_orign");
            string adapterDir = Path.Combine(options.ScriptEngineDir, "Adapter");
            string platformLibDir = Path.Combine(options.ScriptEngineDir, "Tools");

            Utils.CopyDir(orignDir, managedDir, ".dll");
            ReplaceMscorlib("lib", managedDir);

            Binder.Init(Path.Combine(adapterDir, "glue"));
            CSCGenerater.Init(ToolsetPath, adapterDir, managedDir, options.AdapterSet, options.AssembliesCheck);
            CBinder.Init(Path.Combine(options.ScriptEngineDir, "generated"));
            AOTGenerater.Init(options.ScriptEngineDir);

            var entryAssembly = AssemblyDefinition.ReadAssembly(Path.Combine(orignDir, options.Entry.First()));
            CSCGenerater.corlib = AssemblyDefinition.ReadAssembly(Path.Combine(Path.GetDirectoryName(entryAssembly.MainModule.FileName), "mscorlib.dll"));
            var assemblySet = new HashSet<string>();
            foreach(var entry in options.Entry)
            {
                Utils.CollectMonoAssembly(entry, orignDir, options.AdapterSet, assemblySet);
            }

            options.AdapterSet.UnionWith(assemblySet.Where(assem => assem.StartsWith("UnityEngine.") || assem.StartsWith("Unity.")));

            foreach (var assembly in options.AdapterSet)
            {
                if (Config.Instance.IgnoreAssemblySet.Contains(assembly))
                    continue;

                var filePath = Path.Combine(orignDir, assembly);

                if(File.Exists(filePath))
                {
                    Binder.Bind(filePath);
                }
                
            }
            Binder.End();
            CSCGenerater.End();

            if (Mode == BindTarget.All)
            {
               // CBinder.Bind(CSCGenerater.AdapterWrapperCompiler.outName);

                foreach (var filePath in Directory.GetFiles(managedDir))
                {
                    var file = Path.GetFileName(filePath);
                    if (file.EndsWith(".dll") && !Config.Instance.IgnoreAssemblySet.Contains(file))
                    {
                        if(options.InterpSet.Contains(file))
                        {
                            Console.WriteLine("interp: " + file);
                            ICallGenerater.AddReloableAssembly(file);
                        }
                        else if (options.AdapterSet.Contains(file) || file == "Adapter.wrapper.dll")
                        {
                            if (file.StartsWith("UnityEngine."))
                            {
                                CBinder.Bind(filePath);
                            }

                            Console.WriteLine("aot: " + file);
                            AOTGenerater.AddAOTAssembly(filePath);
                        }
                    }
                }

                CBinder.End();
                AOTGenerater.End();
            }


        }

        public static void ReplaceMscorlib(string libDir, string outDir)
        {
            var srcDir = Path.Combine(libDir, Platform == TargetPlatform.Android ? "Android" : (Platform == TargetPlatform.iOS ? "iOS" : "win32"));// Path.Combine(libDir, Utils.IsWin32() ? "win32" : "iOS");

            DirectoryInfo dir = new DirectoryInfo(srcDir);

            foreach (var fi in dir.GetFiles())
            {
                var tarPath = Path.Combine(outDir, fi.Name);
                if (File.Exists(tarPath) || fi.Name == "netstandard.dll") // netstandard reserved for unity2020 build bug
                {
                    File.Copy(Path.Combine(srcDir, fi.Name), tarPath, true);
                    AOTGenerater.AddAOTAssembly(tarPath);
                }
            }
        }



        static void StartTestBinder()
        {
            string managedDir = "Managed";

            TestBinder.Init(@"test\");

            foreach (var filePath in Directory.GetFiles(managedDir))
            {
                var file = Path.GetFileName(filePath);

                if (file.EndsWith(".dll") && !Config.Instance.IgnoreAssemblySet.Contains(file))
                {
                    TestBinder.TestBind(filePath);
                }
            }
            TestBinder.End();
        }

        //Try to modify
        static void TestWriter()
        {
            using (new CS(new CodeWriter(File.CreateText("TestWriter.txt"))))
            {
                CS.Writer.Start("Test");
                CS.Writer.WriteLine("1");
                CS.Writer.WriteLine("3");
                CS.Writer.WritePreviousLine("2");

                CS.Writer.CreateLinePoint("//aa");

                CS.Writer.WriteLine("4");

                var writer2 = new CodeWriter(File.CreateText("TestWriter2.txt"));
                using (new CS(writer2))
                {
                    CS.Writer.WriteLine("write Test2 file..");
                }

                CS.Writer.WriteLine("5");

                using (new LP(CS.Writer.GetLinePoint("//aa")))
                {
                    CS.Writer.Start("LinePointTest");
                    CS.Writer.WriteLine("aa 1");
                    CS.Writer.WriteLine("aa 2");
                    var resolverRes = new ClassResolver(null, new MemberTypeContext(MemberTypeSlot.None, MethodTypeSlot.None, null)).Box("testObj");
                    CS.Writer.WriteLine($"return {resolverRes}");
                    CS.Writer.End();
                }

                CS.Writer.WriteLine("6");

                var cResolverRes = new Generater.C.StringResolver(null, false).Box("testStr");
                CS.Writer.WriteLine($"return {cResolverRes}");

                CS.Writer.End();

                using (new CS(writer2))
                {
                    CS.Writer.WriteLine("write Test2 file once more...", false);
                }
            }
        }
    }
}
