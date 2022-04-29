using Mono.Cecil;
using System.Collections;
using System.Collections.Generic;

namespace Generater
{
    public class DelegateGenerater : CodeGenerater
    {
        string genName;
        TypeReference genType;
        TypeReference declarType;
        bool isStatic;
        bool isEvent;
        bool isField = false;
        MethodDefinition addMethod;
        MethodDefinition removeMethod;

        MethodDefinition setMethod;
        MethodDefinition getMethod;

        bool genProxyDelegate = true;
        ClassGenerater classGenerater;

        List<MethodGenerater> methods = new List<MethodGenerater>();
        public DelegateGenerater(EventDefinition e, ClassGenerater parent)
        {
            genName = e.Name;
            genType = e.EventType;
            declarType = e.DeclaringType;
            classGenerater = parent;

            if (e.AddMethod != null)
            {
                addMethod = e.AddMethod;
                methods.Add(new MethodGenerater(e.AddMethod, parent));
                isStatic = e.AddMethod.IsStatic;
            }

            if (e.RemoveMethod != null)
            {
                removeMethod = e.RemoveMethod;
                methods.Add(new MethodGenerater(e.RemoveMethod, parent));
                isStatic = e.RemoveMethod.IsStatic;
            }
            isEvent = true;

        }

        public DelegateGenerater(PropertyDefinition prop, ClassGenerater parent)
        {
            genName = prop.Name;
            genType = prop.PropertyType;
            declarType = prop.DeclaringType;
            classGenerater = parent;

            if (prop.SetMethod != null)
            {
                setMethod = prop.SetMethod;
                methods.Add(new MethodGenerater(prop.SetMethod, parent));
                isStatic = prop.SetMethod.IsStatic;
            }

            if (prop.GetMethod != null)
            {
                getMethod = prop.GetMethod;
                if(genProxyDelegate) //非proxy模式只需要生成简单的get
                {
                    methods.Add(new MethodGenerater(prop.GetMethod, parent));
                }
                isStatic = prop.GetMethod.IsStatic;
            }
            isEvent = false;
        }

        public DelegateGenerater(FieldDefinition field, ClassGenerater parent)
        {
            genName = field.Name;
            genType = field.FieldType;
            declarType = field.DeclaringType;
            classGenerater = parent;

            if (!field.IsInitOnly)
            {
                //TODO:这里构造一个setter 和 getter，field的状态还是在il2cpp层持有
                var corlib = CSCGeneraterManager.corlib;// AssemblyDefinition.ReadAssembly(Path.Combine(Path.GetDirectoryName(genField.FieldType.Module.FileName), "mscorlib.dll"));

                setMethod = new MethodDefinition("set_" + genName, MethodAttributes.Public, corlib.MainModule.GetType("System", "Void"));
                setMethod.DeclaringType = field.DeclaringType;
                setMethod.Body = new Mono.Cecil.Cil.MethodBody(setMethod);
                setMethod.IsSetter = true;
                //setMethod.IsPublic = field.IsPublic;
                setMethod.IsStatic = field.IsStatic;
                //setMethod.IsCompilerControlled = true;
                var parameters = setMethod.Parameters;
                parameters.Add(new ParameterDefinition("value", ParameterAttributes.None, genType));
                methods.Add(new MethodGenerater(setMethod, parent, MethodType.GeneratedByDelegate));
            }


            getMethod = new MethodDefinition("get_" + genName, MethodAttributes.Public, genType);
            getMethod.DeclaringType = field.DeclaringType;
            getMethod.Body = new Mono.Cecil.Cil.MethodBody(getMethod);
            getMethod.IsGetter = true;
            //getMethod.IsPublic = field.IsPublic;
            getMethod.IsStatic = field.IsStatic;
            //getMethod.IsCompilerControlled = true;
            var parameters1 = getMethod.Parameters;
            methods.Add(new MethodGenerater(getMethod, parent, MethodType.GeneratedByDelegate));

            isStatic = field.IsStatic;
            isEvent = false;
            isField = true;
        }


        /*
        public static event global::UnityEngine.Application.LogCallback logMessageReceived
		{
			add
			{
                bool add = _logMessageReceived == null;
                _logMessageReceived += value;
                if(add)
                {
                    var value_p = Marshal.GetFunctionPointerForDelegate(logMessageReceivedAction);
                    MonoBind.UnityEngine_Application_add_logMessageReceived(value_p);
                }
			}
			remove
			{
                _logMessageReceived -= value;
                if(_logMessageReceived == null)
                {
                    var value_p = Marshal.GetFunctionPointerForDelegate(logMessageReceivedAction);
                    MonoBind.UnityEngine_Application_remove_logMessageReceived(value_p);
                }
			}
		}
             */
        public override void GenerateCode()
        {
            if(genProxyDelegate)
            {
                _GenWithProxyDelegate();
            }
            else
            {
                _Gen();
            }
        }
        public void _GenWithProxyDelegate()
        {
            var name = genName;

            var flag = isStatic ? "static" : "";
            flag += isEvent ? " event" : "";
            var type = genType; // LogCallback(string condition, string stackTrace, LogType type);

            var eventTypeName = TypeResolver.Resolve(type).RealTypeName();
            if (type.IsGenericInstance)
                eventTypeName = Utils.GetGenericTypeName(type);

            //public static event LogCallback logMessageReceived
            CS.Writer.Start($"public {flag} {eventTypeName} {name}");

            if(isEvent)
            {
                GenEventMethods(name);
            }
            else
            {
                GenPropertyMethods(name);
            }

            CS.Writer.End();
        }

        private void GenEventMethods(string name)
        {
            var type = genType;
            IMemberDefinition context = null;
            var targetHandle = isStatic ? "" : "this.Handle, ";
            if (addMethod != null)
            {
                context = addMethod;
                string _member = DelegateResolver.LocalMamberName(name, addMethod); // _logMessageReceived

                CS.Writer.Start("add");
                CS.Writer.WriteLine($"bool attach = ({_member} == null)");

                CS.Writer.WriteLine($"{_member} += value");

                CS.Writer.Start("if(attach)");

                if (!isStatic)
                    CS.Writer.WriteLine($"ObjectStore.RefMember(this,ref {_member}_ref,{_member})"); // resist gc

                var res = TypeResolver.Resolve(type, context).BoxBeforeMarshal(name);

                CS.Writer.WriteLine(Utils.BindMethodName(addMethod, false, false) + $"({targetHandle}{res})");
                //var value_p = Marshal.GetFunctionPointerForDelegate(logMessageReceivedAction);
                //MonoBind.UnityEngine_Application_add_logMessageReceived(value_p);
                CS.Writer.WriteLine("ScriptEngine.CheckException()");
                CS.Writer.End(); //if(attach)
                CS.Writer.End(); // add
            }
            if (removeMethod != null)
            {
                if(context == null) // add/remove share the same box member
                {
                    context = removeMethod;
                }

                string _member = DelegateResolver.LocalMamberName(name, removeMethod); // _logMessageReceived

                CS.Writer.Start("remove");
                CS.Writer.WriteLine($"{_member} -= value");

                CS.Writer.Start($"if({_member} == null)");

                if (!isStatic)
                    CS.Writer.WriteLine($"ObjectStore.RefMember(this,ref {_member}_ref,{_member})"); // resist gc

                var res = TypeResolver.Resolve(type, context).BoxBeforeMarshal(name);
                CS.Writer.WriteLine(Utils.BindMethodName(removeMethod, false, false) + $"({targetHandle}{res})");
                CS.Writer.WriteLine("ScriptEngine.CheckException()");
                CS.Writer.End(); //if(attach)
                CS.Writer.End(); // remove
            }
        }

        private void GenPropertyMethods(string name)
        {
            var type = genType;
            IMemberDefinition context = null;

            bool shareSameMember = isField;
            string _member = null;
            if (setMethod != null)
            {
                context = setMethod;
                _member = DelegateResolver.LocalMamberName(name, setMethod); // _logMessageReceived

                CS.Writer.Start("set");
                CS.Writer.WriteLine($"bool attach = ({_member} == null)");

                CS.Writer.WriteLine($"{_member} = value");

                CS.Writer.Start("if(attach)");

                if (!isStatic)
                    CS.Writer.WriteLine($"ObjectStore.RefMember(this,ref {_member}_ref,{_member})"); // resist gc

                var res = TypeResolver.Resolve(type, context).BoxBeforeMarshal(name);

                var targetHandle = isStatic ? "" : "this.Handle, ";
                CS.Writer.WriteLine(Utils.BindMethodName(setMethod, false, false) + $"({targetHandle}{res})");
                //var value_p = Marshal.GetFunctionPointerForDelegate(logMessageReceivedAction);
                //MonoBind.UnityEngine_Application_add_logMessageReceived(value_p);
                CS.Writer.WriteLine("ScriptEngine.CheckException()");
                CS.Writer.End(); //if(attach)
                CS.Writer.End(); // add
            }
            if (getMethod != null)
            {
                context = getMethod;
                if(!(shareSameMember && !string.IsNullOrEmpty(_member)))
                { 
                    _member = DelegateResolver.LocalMamberName(name, getMethod); // _logMessageReceived
                }

                CS.Writer.Start("get");

                var targetHandle = isStatic ? "" : "this.Handle";
                CS.Writer.WriteLine($"var {name}_p = {Utils.BindMethodName(getMethod, false, false)}({targetHandle})");
                var res = TypeResolver.Resolve(type, context).UnboxAfterMarhsal(name);
                CS.Writer.WriteLine("ScriptEngine.CheckException()");
                //CS.Writer.WriteLine($"{_member} -= {res}"); //
                //CS.Writer.WriteLine($"{_member} += {res}");

                //if (!isStatic)
                //    CS.Writer.WriteLine($"ObjectStore.RefMember(this,ref {_member}_ref,{_member})"); // resist gc

                CS.Writer.WriteLine($"return {_member}");
                CS.Writer.End(); //get
            }
        }

        public void _Gen()
        {
            var name = genName;

            var flag = isStatic ? "static" : "";
            flag += isEvent ? " event" : "";
            var type = genType; // LogCallback(string condition, string stackTrace, LogType type);

            var eventTypeName = TypeResolver.Resolve(type).RealTypeName();
            if (type.IsGenericInstance)
                eventTypeName = Utils.GetGenericTypeName(type);

            
            IMemberDefinition context = null ;

            //public static event LogCallback logMessageReceived
            CS.Writer.Start($"public {flag} {eventTypeName} {name}");

            var targetHandle = isStatic ? "" : "this.Handle, ";
            if (addMethod != null || setMethod != null)
            {
                var method = isEvent ? addMethod : setMethod;
                context = method;
                string _member = DelegateResolver.LocalMamberName(name, method); // _logMessageReceived

                var op = isEvent ? "+=" : "=";
                CS.Writer.Start(isEvent ? "add" : "set");
                if(addMethod != null)
                    CS.Writer.WriteLine($"bool attach = ({_member} == null)");
                else
                    CS.Writer.WriteLine($"bool attach = ({_member} != value)");

                CS.Writer.WriteLine($"{_member} {op} value");

                CS.Writer.Start("if(attach)");

                if (!isStatic)
                    CS.Writer.WriteLine($"ObjectStore.RefMember(this,ref {_member}_ref,{_member})"); // resist gc

                var res = TypeResolver.Resolve(type, context).BoxBeforeMarshal(name);
                
                CS.Writer.WriteLine(Utils.BindMethodName(method, false, false) + $"({targetHandle}{res})");
                //var value_p = Marshal.GetFunctionPointerForDelegate(logMessageReceivedAction);
                //MonoBind.UnityEngine_Application_add_logMessageReceived(value_p);
                CS.Writer.WriteLine("ScriptEngine.CheckException()");
                CS.Writer.End(); //if(attach)
                CS.Writer.End(); // add
            }
            if(removeMethod != null)
            {
                if(context == null)
                    context = removeMethod;

                string _member = DelegateResolver.LocalMamberName(name, removeMethod); // _logMessageReceived

                CS.Writer.Start("remove");
                CS.Writer.WriteLine($"{_member} -= value");

                CS.Writer.Start($"if({_member} == null)");

                if (!isStatic)
                    CS.Writer.WriteLine($"ObjectStore.RefMember(this,ref {_member}_ref,{_member})"); // resist gc

                var res = TypeResolver.Resolve(type, context).BoxBeforeMarshal(name);
                CS.Writer.WriteLine(Utils.BindMethodName(removeMethod, false, false) + $"({targetHandle}{res})");
                CS.Writer.WriteLine("ScriptEngine.CheckException()");
                CS.Writer.End(); //if(attach)
                CS.Writer.End(); // remove
            }
            else if (getMethod != null)
            {
                string _member = DelegateResolver.LocalMamberName(name, getMethod); // _logMessageReceived

                CS.Writer.Start("get");
                CS.Writer.WriteLine($"return {_member}");
                CS.Writer.End(); //get
            }

            CS.Writer.End();
        }

        static string GetEventFieldName(MethodDefinition method)
        {
            var name = method.Name;
            if (name.StartsWith("add_"))
                name = name.Substring("add_".Length);
            else if (name.StartsWith("remove_"))
                name = name.Substring("remove_".Length);
            return name;
        }



    }
}