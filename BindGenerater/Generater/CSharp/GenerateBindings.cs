using Mono.Cecil;
using System.Collections;
using System.Collections.Generic;
using System.IO;

namespace Generater
{
    public class BindingGenerater
    {
        public string Name;
        public int Offset;
        HashSet<MethodDefinition> methods = new HashSet<MethodDefinition>();
        HashSet<string> delegateDefines = new HashSet<string>();

        StreamWriter Writer;

        public BindingGenerater(string name,int _offset,StreamWriter writer)
        {
            Name = name;
            Offset = _offset;
            Writer = writer;
        }

        public void AddMethod(MethodDefinition method)
        {
            methods.Add(method);
        }

        public void AddDelegateDefine(string defineStr)
        {
            delegateDefines.Add(defineStr);
        }

        private void GenDefines(bool isMonoBind = false)
        {
            // method define
            foreach (var method in methods)
            {
                CS.Writer.WriteLine("[UnmanagedFunctionPointer(CallingConvention.Cdecl)]", false);
                //MethodResolver.Resolve(method).DefineDelegate();
                var flag = Utils.IsUnsafeMethod(method) ? " unsafe " : " ";
                CS.Writer.WriteLine($"public{flag}delegate {MethodResolver.Resolve(method).ReturnType()} {Utils.BindMethodName(method, true, false, isMonoBind)}_Type {Utils.BindMethodParamDefine(method, true, isMonoBind)}");
            }

            // delegate define
            foreach (var define in delegateDefines)
            {
                CS.Writer.WriteLine(define);
            }
        }

        public void GenWrapper()
        {
            var nsSet = Utils.GetNameSpaceList(methods);
            if(methods.Count > 0)
            {
                nsSet.Add("System.Runtime.InteropServices");
                nsSet.Add("System.Collections.Generic");
                nsSet.Add("Object = UnityEngine.Object");
                nsSet.Add("Random = UnityEngine.Random");
            }
            nsSet.Add("System");

            using (new CS(new CodeWriter(Writer)))
            {

                foreach (var ns in nsSet)
                    CS.Writer.WriteLine($"using {ns}");

                GenDefines(true);

                // wrapper imple
                //CS.Writer.WriteLine("using PureScript.Mono");

                CS.Writer.Start("internal static partial class MonoBind");

                foreach (var method in methods)
                {
                    var methodName = Utils.BindMethodName(method, true, false, true);
                    CS.Writer.WriteLine($"public static {methodName}_Type {methodName}");
                }

                CS.Writer.Start("static MonoBind()");
                CS.Writer.WriteLine("InitBind(PureScript.Mono.ScriptEngine.GetFuncPointer())");
                CS.Writer.End();

                CS.Writer.Start("public static void InitBind(IntPtr memory)");
                //CS.Writer.Start("if(memory == IntPtr.Zero)");
                //CS.Writer.WriteLine("memory = GetManageFuncPtr()");
                //CS.Writer.End();

                foreach (var method in methods)
                {
                    var methodName = Utils.BindMethodName(method, true, false, true);
                    CS.Writer.WriteLine($"{methodName} = Marshal.GetDelegateForFunctionPointer<{methodName}_Type>(Marshal.ReadIntPtr(memory, {Offset} * IntPtr.Size ))");
                    Offset++;
                }

                CS.Writer.EndAll();
            }
        }

        public void GenImpl()
        {
            var nsSet = Utils.GetNameSpaceList(methods);
            nsSet.Add("System.Runtime.InteropServices");
            nsSet.Add("System.Collections.Generic");
            nsSet.Add("Object = UnityEngine.Object");
            nsSet.Add("Random = UnityEngine.Random");
            nsSet.Add("PureScript");
            nsSet.Add("AOT");
            nsSet.Add("System");


            using (new CS(new CodeWriter(Writer, CodeWriter.CodeWriterType.UnityBind)))
            {
                foreach (var ns in nsSet)
                    CS.Writer.WriteLine($"using {ns}");

                CS.Writer.Start("public static unsafe class UnityBind");

                foreach (var method in methods)
                {
                    var methodName = Utils.BindMethodName(method, true, false);
                    CS.Writer.WriteLine($"static readonly {methodName}_Type {methodName}Delegate = new {methodName}_Type({methodName})");
                }

                CS.Writer.Start("public static IntPtr BindFunc()");
                CS.Writer.WriteLine($"IntPtr memory = Marshal.AllocHGlobal({methods.Count + 1} * IntPtr.Size)");

                foreach (var method in methods)
                {
                    var methodName = Utils.BindMethodName(method, true, false) + "Delegate";
                    CS.Writer.WriteLine($"Marshal.WriteIntPtr(memory, {Offset} * IntPtr.Size, Marshal.GetFunctionPointerForDelegate({methodName}))");
                    Offset++;
                }

                CS.Writer.WriteLine($"Custom.Ser(memory + {Offset} * IntPtr.Size)");
                CS.Writer.WriteLine("return memory");
                CS.Writer.End();

                foreach (var method in methods)
                {
                    var methodName = Utils.BindMethodName(method, true, false);


                    CS.Writer.CreateLinePoint("//Method");

                    CS.Writer.WriteLine($"[MonoPInvokeCallback(typeof({methodName}_Type))]", false);
                    CS.Writer.Start($"static {MethodResolver.Resolve(method).ReturnType()} {methodName} {Utils.BindMethodParamDefine(method, true)}");

                    CS.Writer.WriteLine("Exception __e = null");
                    CS.Writer.Start("try");

                    var reName = MethodResolver.Resolve(method).IL2CppImplement("_value");
                    if (method.ReturnType != null)
                    {
                        if (method.ReturnType.IsArray)
                        {
                            CS.Writer.WriteLine($"__arrayLen = {reName} != null ? {reName}.Length : -1");
                            CS.Writer.WriteLine($"if({reName} != null) {{ ObjectStore.GetReturnArrayToMono({reName}, ref __retArrayPtr); }} ");
                            reName = null; //return value is assigned with out parameter
                        }
                        else if (method.ReturnType.IsStruct(false))
                        {
                            CS.Writer.WriteLine($"var {reName}_gchandle = GCHandle.Alloc(_value, GCHandleType.Pinned); ");
                            CS.Writer.WriteLine($"ObjectStore.GetReturnStructToMono({reName}_gchandle.AddrOfPinnedObject(), ref __retStructPtr, typeof({Utils.FullName(method.ReturnType)}), Marshal.SizeOf<{Utils.FullName(method.ReturnType)}>())");
                            CS.Writer.WriteLine($"{reName}_gchandle.Free()");
                            //outStruct = $"__retStruct = default({Utils.FullName(method.ReturnType)})";
                            reName = null; //return value is assigned with out parameter
                        }
                    }
                    if (!string.IsNullOrEmpty(reName))
                        CS.Writer.WriteLine($"return {reName}");
                    CS.Writer.End();//try
                    CS.Writer.Start("catch(Exception _e_)");
                    CS.Writer.WriteLine("__e = _e_");
                    CS.Writer.End();//catch

                    CS.Writer.WriteLine("if(__e != null) { ScriptEngine.OnException(__e); }", false);
                    if (!string.IsNullOrEmpty(reName))
                        CS.Writer.WriteLine($"return default({MethodResolver.Resolve(method).ReturnType()})");

                    CS.Writer.End();//method

                }

                CS.Writer.End();//UnityBind

                GenDefines();

                CS.Writer.EndAll();
            }
        }
    }

    public static class GenerateBindings
    {
        static BindingGenerater il2cppGenerater;
        static BindingGenerater monoWrapGenerater;

        public static void StartMonoWraper(string file, CSCGenerater wrapperCompiler)
        {
            var name = $"Binder.mono.{file.Replace(".dll",".cs")}";
            file = file.Replace(".dll", "");
            var dir1 = Path.Combine(Binder.OutDir, "Mono_" + file);
            Directory.CreateDirectory(dir1);
            var path = Path.Combine(dir1, name);
            var writer = File.CreateText(path);
            var offset = monoWrapGenerater != null ? monoWrapGenerater.Offset : 0;
            monoWrapGenerater = new BindingGenerater(name, offset, writer);

            wrapperCompiler.AddSource(path);
        }

        public static void StartIL2CppAdpater()
        {
            var il2cppName = "Binder.il2cpp.cs";
            var dir = Path.Combine(Binder.OutDir, "IL2Cpp");
            if (!Directory.Exists(dir))
            {
                Directory.CreateDirectory(dir);
            }
            var il2cppWriter = File.CreateText(Path.Combine(Binder.OutDir, "IL2Cpp", il2cppName));
            il2cppGenerater = new BindingGenerater("Binder.il2cpp", 0, il2cppWriter);
        }

        public static void AddMethod(MethodDefinition method)
        {
            il2cppGenerater.AddMethod(method);
            monoWrapGenerater.AddMethod(method);
        }

        public static void AddDelegateDefine(string defineStr, string wrapDefineStr)
        {
            il2cppGenerater.AddDelegateDefine(defineStr);
            monoWrapGenerater.AddDelegateDefine(wrapDefineStr);
        }

        public static void Gen()
        {
            monoWrapGenerater.GenWrapper();
        }
        public static void End()
        {
            il2cppGenerater.GenImpl();
        }
    }
}