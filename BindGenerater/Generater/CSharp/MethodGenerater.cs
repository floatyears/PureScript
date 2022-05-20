using Mono.Cecil;
using System.Collections;
using System.Collections.Generic;
using System.Linq;

namespace Generater
{
    public enum MethodType
    {
        None = 0,
        GeneratedByDelegate = 1,
        GeneratedByField = 2,
    }

    public class MethodGenerater : CodeGenerater
    {
        MethodDefinition genMethod;
        CodeWriter writer;
        MethodType methodType;

        bool isNotImplement = false;
        ClassGenerater classGenerater;
        bool isCalledByOthers = false;
        bool isOnlyExeInMono = false;

        public MethodDefinition GenMethodDef { get { return genMethod; } }

        public MethodGenerater(MethodDefinition method, ClassGenerater parent, bool isCalledByOthers = false, List<MethodGenerater> methods = null)
        {
            genMethod = method;
            classGenerater = parent;
            this.isCalledByOthers = isCalledByOthers;
            if(methods != null)
            {
                methods.Add(this);
            }
            Init();
        }

        public MethodGenerater(MethodDefinition method, ClassGenerater parent, MethodType methodType)
        {
            genMethod = method;
            this.methodType = methodType;
            classGenerater = parent;
            Init();
        }

        private void Init() 
        {
            //非public的函数或者internal type的public函数只能在mono内
            isOnlyExeInMono = false;
            if (genMethod.IsInternalCall)
            {
                isOnlyExeInMono = true;
            }
            else 
            { 
                //作为binder层的优化，如果只调用了internal call，则可以不通过binder
                var calledMethods = new List<MethodDefinition>();
                if (genMethod.IsPublic)
                {
                    if(genMethod.IsSetter || genMethod.IsGetter)
                    {

                    }else
                    {
                        isOnlyExeInMono = Utils.CheckMethodOnlyCallInternal(genMethod, calledMethods);
                        if (calledMethods.Count(x => x.IsInternalCall) > 1)
                        {

                        }
                    }
                }
                else
                {
                    isOnlyExeInMono = Utils.CheckMethodNoAffectsToSelf(genMethod, calledMethods);
                }
                if (isOnlyExeInMono)
                {
                    foreach (var m in calledMethods)
                    {
                        Binder.AddMethod(m);
                    }
                }
            }
            
            isNotImplement = !Utils.Filter(genMethod, classGenerater.GetRuntime());

            isNotImplement |= genMethod.IsConstructor && genMethod.DeclaringType.IsSubclassOf("UnityEngine.Component"); // UnityEngine.Component cant be new..


            if (isNotImplement)//maybe generate a empty method?
            {
                return;
            }


            if (!CheckMethodNeedGen())
            {
                return;
            }

            if (genMethod.IsConstructor && genMethod.DeclaringType.IsAbstract)
            {
                return;
            }

            foreach (var p in genMethod.Parameters)
            {
                var type = p.ParameterType;
                Binder.AddType(type.Resolve());
            }
            Binder.AddType(genMethod.ReturnType.Resolve());

            foreach(var gp in genMethod.GenericParameters)
            {
                foreach(var c in gp.Constraints)
                {
                    Binder.AddType(c.ConstraintType.Resolve());
                }
            }

            //binding的函数只能是public
            //所有通过isCalledByOthers的函数，都不能通过bind层进行调用，只能在mono层内部调用
            if (!genMethod.IsAbstract && !isNotImplement && Utils.IsVisibleToOthers(genMethod))
            {
                GenerateBindings.AddMethod(genMethod);
            }
        }

        private bool CheckMethodNeedGen()
        {
            return (isCalledByOthers || Utils.IsInternalCallVisibleToOthers(genMethod) || Utils.IsVisibleToOthers(genMethod) || genMethod.DeclaringType.IsInterface);
        }

        public override void GenerateCode(CS _writer = null)
        {
            if (isNotImplement)// && !isOnlyExeInMono)
                return;

            writer = CS.Writer;
            base.GenerateCode();

            if (!CheckMethodNeedGen())
                return;
            if (genMethod.IsConstructor && genMethod.DeclaringType.IsAbstract)
                return;

            if (genMethod.IsGetter)
                GenGeter();
            else if (genMethod.IsSetter)
                GenSeter();
            else if (genMethod.IsAddOn)
                GenAddOn();
            else if (genMethod.IsRemoveOn)
                GenRemoveOn();
            else if (genMethod.IsAbstract)
                GenAbstract();
            else
                GenMethod();
        }

        void GenGeter()
        {
            if (genMethod.ImplAttributes == MethodImplAttributes.InternalCall)
            {
                writer.WriteLine("[MethodImpl(MethodImplOptions.InternalCall)]", false);
                writer.WriteLine("get");
                return;
            }
            if (genMethod.IsAbstract)
            {
                writer.WriteLine("get");
                return;
            }
            
            writer.Start("get");
            if(isNotImplement)
            {
                WriteNotImplemented();
            }
            else
            {
                var res = MethodResolver.Resolve(genMethod).MonoImplement("ret");
                writer.WriteLine("ScriptEngine.CheckException()");
                writer.WriteLine($"return {res}");
            }
            
            writer.End();
        }

        void GenSeter()
        {
            if (genMethod.ImplAttributes == MethodImplAttributes.InternalCall)
            {
                writer.WriteLine("[MethodImpl(MethodImplOptions.InternalCall)]", false);
                writer.WriteLine("set");
                return;
            }
            if (genMethod.IsAbstract)
            {
                writer.WriteLine("set");
                return;
            }

            
            writer.Start("set");
            if (isNotImplement)
            {
                WriteNotImplemented();
            }
            else
            {
                MethodResolver.Resolve(genMethod).MonoImplement("");
                writer.WriteLine("ScriptEngine.CheckException()");
            }
                
            writer.End();
        }

        void GenAddOn()
        {
            writer.Start("add");
            if (isNotImplement)
            {
                WriteNotImplemented();
            }
            else
            {
                MethodResolver.Resolve(genMethod).MonoImplement("");
                writer.WriteLine("ScriptEngine.CheckException()");
            }
                
            writer.End();
        }

        void GenRemoveOn()
        {
            writer.Start("remove");
            if (isNotImplement)
            {
                WriteNotImplemented();
            }
            else
            {
                MethodResolver.Resolve(genMethod).MonoImplement("");
                writer.WriteLine("ScriptEngine.CheckException()");
            }
            writer.End();
        }

        void GenMethod()
        {
            var declear = GetMethodDelcear();
            if (!genMethod.HasBody)
            {
                if (genMethod.CustomAttributes.Any(x => x.AttributeType.Name == "VisibleToOtherModulesAttribute"))
                {
                    declear = declear.Replace("internal", "public");
                }
                writer.WriteLine(declear);
                return;
            }

            //只在mono层存在的函数
            if (genMethod.HasGenericParameters || isOnlyExeInMono)
            {
                if(classGenerater.TokenMap.TryGetValue(genMethod.MetadataToken.ToInt32(), out var methodAst))
                {
                    var tmpWriter = new System.IO.StringWriter();
                    var outputVisitor = new CustomOutputVisitor(false, tmpWriter, Binder.DecompilerSetting.CSharpFormattingOptions);
                    methodAst.AcceptVisitor(outputVisitor);
                    
                    //using(new LP(writer.GetLinePoint("//namespace")))
                    //{
                    //    //foreach(var ns in outputVisitor.InternalTypeRef)
                    //    //{
                    //    //    if (!classGenerater.RefNameSpace.Contains(ns))
                    //    //    {
                    //    //        classGenerater.RefNameSpace.Add(ns);
                    //    //        writer.WriteLine($"using {ns}");
                    //    //    }
                    //    //}
                    //}
                    writer.WriteLine(tmpWriter.ToString(), false);
                }
                else
                {
                    if(genMethod.Name != ".ctor") //隐式的构造函数
                    {
                        throw new System.Exception("Method SyntaxTree not found");
                    }
                }
                return;
            }
            else
            {
                if (!(genMethod.IsPublic && (genMethod.DeclaringType.IsPublic || genMethod.DeclaringType.IsNestedPublic) && !Utils.IsMethodHasParamArgument(genMethod))) //binding的函数，declaring type必须为public
                {
                    return;
                }
            }
            //if(genMethod.CustomAttributes.Any(x=>x.AttributeType.Name == "RequiredByNativeCodeAttribute"))
            //{
            //    writer.WriteLine("[UnityEngine.Scripting.RequiredByNativeCode]", false);
            //}

            writer.Start(declear);

            if (isNotImplement)
            {
                WriteNotImplemented();
                writer.End();
                return;
            }

            if (genMethod.IsConstructor)
            {
                if(genMethod.DeclaringType.IsValueType)
                {
                    CS.Writer.WriteLine(Utils.BindMethodName(genMethod));
                    writer.WriteLine("ScriptEngine.CheckException()");
                }
                else
                {
                    CS.Writer.Start($"if(typeof({genMethod.DeclaringType.Name}) == GetWType())");
                    CS.Writer.WriteLine($"var h = {Utils.BindMethodName(genMethod)}");
                    writer.WriteLine("ScriptEngine.CheckException()");
                    CS.Writer.WriteLine($"SetHandle(h)");
                    CS.Writer.WriteLine("ObjectStore.Store(this, h)");
                    CS.Writer.End();
                }
            }
            else
            {
                var res = MethodResolver.Resolve(genMethod).MonoImplement("res");
                writer.WriteLine("ScriptEngine.CheckException()");
                writer.WriteLine($"return {res}");
            }
            
            writer.End();
        }

        void GenAbstract()
        {
            writer.WriteLine(GetMethodDelcear());
        }


        string GetMethodDelcear()
        {
            string declear = Utils.GetMemberDelcear(genMethod, classGenerater.TokenMap);

            if (genMethod.IsConstructor)
            {
                if(genMethod.DeclaringType.IsValueType)
                {
                    declear += ":this()";
                }
            }

            return declear;
        }

        void WriteNotImplemented()
        {
            CS.Writer.WriteLine("throw new System.NotImplementedException()");
        }

    }
}