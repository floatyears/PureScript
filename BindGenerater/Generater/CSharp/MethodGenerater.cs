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
        GeneratedByField = 1,
    }

    public class MethodGenerater : CodeGenerater
    {
        MethodDefinition genMethod;
        CodeWriter writer;
        MethodType methodType;

        bool isNotImplement = false;
        ClassGenerater classGenerater;

        public MethodGenerater(MethodDefinition method, ClassGenerater parent)
        {
            genMethod = method;
            classGenerater = parent;
            Init();
        }

        public MethodGenerater(MethodDefinition method, ClassGenerater parent, MethodType methodType = MethodType.None)
        {
            genMethod = method;
            this.methodType = methodType;
            classGenerater = parent;
            Init();
        }

        private void Init()
        {
            isNotImplement = !Utils.Filter(genMethod);

            isNotImplement |= genMethod.IsConstructor && genMethod.DeclaringType.IsSubclassOf("UnityEngine.Component"); // UnityEngine.Component cant be new..

            if (isNotImplement)//maybe generate a empty method?
                return;

            if (!Utils.IsVisibleToOthers(genMethod) && !genMethod.DeclaringType.IsInterface)
                return;
            if (genMethod.IsConstructor && genMethod.DeclaringType.IsAbstract)
                return;

            foreach (var p in genMethod.Parameters)
            {
                var type = p.ParameterType;
                Binder.AddType(type.Resolve());
            }
            Binder.AddType(genMethod.ReturnType.Resolve());

            if (!genMethod.IsAbstract && !isNotImplement)
                GenerateBindings.AddMethod(genMethod);
        }

        public override void GenerateCode()
        {
            if (isNotImplement)
                return;

            writer = CS.Writer;
            base.GenerateCode();

            if (!Utils.IsVisibleToOthers(genMethod) && !genMethod.DeclaringType.IsInterface)
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
            if(!genMethod.HasBody)
            {
                writer.WriteLine(declear);
                return;
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