using Mono.Cecil;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Generater
{
    public class MethodResolver
    {
        public static BaseMethodResolver Resolve(MethodDefinition _method)
        {

            var firstParam = _method.Parameters.FirstOrDefault()?.ParameterType?.Resolve();
            if (_method.IsConstructor)
                return new ConstructorMethodResolver(_method);
            if (_method.IsSetter)
            {
                if (firstParam != null && firstParam.IsDelegate())
                    return new AddOnMethodResolver(_method,false);
                else
                    return new SetterMethodResolver(_method);
            }
            if (_method.IsGetter)
                return new GetterMethodResolver(_method);

            if(_method.IsAddOn)
                return new AddOnMethodResolver(_method, true);
            if (_method.IsRemoveOn)
                return new RemoveOnMethodResolver(_method);

            if (EventMethodResolver.IsUnityEventMethod(_method))
                return new EventMethodResolver(_method);

            return new BaseMethodResolver(_method);
        }
    }

    public class BaseMethodResolver
    {
        protected MethodDefinition method;
        public BaseMethodResolver(MethodDefinition _method)
        {
            method = _method;
        }

        public virtual string ReturnType()
        {
            if (CS.Writer.WriterType == CodeWriter.CodeWriterType.UnityBind)
            {
                if (method.ReturnType.IsArray || method.ReturnType.IsStruct(false))
                {
                    return "void";
                } 
                else
                {
                    return TypeResolver.Resolve(method.ReturnType).TypeName(true);
                }
            }
            else
            {
                if(Utils.IsBlittableType(method.ReturnType))
                {
                    return TypeResolver.Resolve(method.ReturnType).TypeName();
                }
                else
                {
                    if (method.ReturnType.IsVoid())
                    {
                        return "void";
                    }
                    else
                    {
                        return "IntPtr";// TypeResolver.Resolve(method.ReturnType).TypeName();
                    }
                }
            }
        }

        protected string GetParamName(ParameterDefinition parameter)
        {
            return Utils.GetParamName(parameter);
        }

        /// <summary>
        /// var res = MonoBind.UnityEngine_GameObject_GetComponent_1(this.Handle, type);
        /// var resObj = ObjectStore.Get<Component>(res);
		/// return resObj;
        /// </summary>
        /// <returns> resObj </returns>
        public virtual string MonoImplement(string name)
        {
            foreach (var param in method.Parameters)
            {
                var td = param.ParameterType.Resolve();
                if (td != null && td.IsDelegate())
                {
                    var _member = DelegateResolver.LocalMamberName(GetParamName(param), method);
                    CS.Writer.WriteLine($"{_member} = {GetParamName(param)}");
                    if (!method.IsStatic)
                        CS.Writer.WriteLine($"ObjectStore.RefMember(this,ref {_member}_ref,{_member})"); // resist gc
                }
            }

            if (method.ReturnType.IsVoid())
            {
                CS.Writer.WriteLine(Utils.BindMethodName(method));
                return "";
            }

            var retTypeResolver = TypeResolver.Resolve(method.ReturnType, method, MemberTypeSlot.ReturnType, MethodTypeSlot.GeneratedMethod);
            var retName = retTypeResolver.LocalVariable(name, true);

            if(method.ReturnType != null)
            {
                if (method.ReturnType.IsArray)
                {
                    retName = null;
                    CS.Writer.WriteLine("int __arrayLen = -1");
                    CS.Writer.WriteLine($"IntPtr __retArrayPtr = new IntPtr(0)");
                }
                else if(method.ReturnType.IsStruct(false))
                {
                    retName = null;
                    //CS.Writer.WriteLine($"{Utils.FullName(method.ReturnType)} __retStruct");
                    CS.Writer.WriteLine($"IntPtr __retStructPtr = new IntPtr(0)");
                }
            }
             
            CS.Writer.WriteLine($"{(!string.IsNullOrEmpty(retName) ? (retName + " = ") : "")}{Utils.BindMethodName(method)}");
            retName = retTypeResolver.UnboxAfterMarhsal(name);
            return retName;
        }

        /// <summary>
        /// var thizObj = (GameObject)ObjectStore.Get(thiz_h);
		/// var value = thizObj.GetComponent(type);
        /// var value_h = ObjectStore.Store(value);
		/// return value_h;
        /// </summary>
        /// <returns> value_h </returns>
        public virtual string IL2CppImplement(string name)
        {
            var thizObj = GetThizObj();

            if (method.ReturnType.IsVoid())
                CS.Writer.WriteLine("", false);
            else
                CS.Writer.WriteLine($"var {name} = ", false);

            string paramSeparation = ",";

            if (method.Name == "op_Implicit")
                CS.Writer.Write($"");
            else if (method.Name == "op_Equality")
                paramSeparation = "==";
            else if (method.Name == "op_Inequality")
                paramSeparation = "!=";

            else if (method.Name == "op_Addition")
                paramSeparation = "+";
            else if (method.Name == "op_Subtraction")
                paramSeparation = "-";
            else if (method.Name == "op_Multiply")
                paramSeparation = "*";
            else if (method.Name == "op_Division")
                paramSeparation = "/";
            else if (method.Name == "op_LessThan")
                paramSeparation = "<";
            else if (method.Name == "op_GreaterThan")
                paramSeparation = ">";
            else if (method.Name == "op_GreaterThanOrEqual")
                paramSeparation = ">=";
            else if (method.Name == "op_LessThanOrEqual")
                paramSeparation = "<=";
            else if (method.Name == "op_Explicit")
                CS.Writer.Write($"({TypeResolver.Resolve(method.ReturnType).RealTypeName()})");
            else if (method.Name == "op_UnaryNegation")
                CS.Writer.Write($"-");

            

            else
                CS.Writer.Write($"{thizObj}.{method.Name}");

            CS.Writer.Write($"(");
            var lastP = method.Parameters.LastOrDefault();
            foreach (var p in method.Parameters)
            {
                var value = TypeResolver.Resolve(p.ParameterType, method, MemberTypeSlot.Parameter).UnboxAfterMarhsal(GetParamName(p), true);
                if (p.IsIn)
                    value = value.Replace("ref ", "in ");

                CS.Writer.Write(value);
                if (lastP != p)
                    CS.Writer.Write(paramSeparation);
            }
            CS.Writer.Write(");");

            return TypeResolver.Resolve(method.ReturnType).BoxBeforeMarshal(name);
        }

        protected string GetThizObj()
        {
            if (method.IsStatic)
                return method.DeclaringType.FullName.Replace("/",".");
            else
                return TypeResolver.Resolve(method.DeclaringType).UnboxAfterMarhsal("thiz", true);
        }
    }

    public class ConstructorMethodResolver : BaseMethodResolver
    {
        bool IsValueTypeConstructor;
        public ConstructorMethodResolver(MethodDefinition _method) : base(_method)
        {
            IsValueTypeConstructor = Utils.IsFullValueType(method.DeclaringType);
        }

        public override string ReturnType()
        {
            if(IsValueTypeConstructor)
                return "void";

            return "IntPtr";
        }

        /// <summary>
        /// var value = new GameObject(name);
		/// var valueHandle = ObjectStore.Store(value);
		/// return valueHandle;
        /// </summary>
        /// <returns> valueHandle </returns>
        public override string IL2CppImplement(string name)
        {

            if(!IsValueTypeConstructor)
            {
                CS.Writer.WriteLine($"var {name} = new {TypeResolver.Resolve(method.DeclaringType).RealTypeName()}(", false);
                var lastP = method.Parameters.LastOrDefault();
                foreach (var p in method.Parameters)
                {
                    var value = TypeResolver.Resolve(p.ParameterType, method, MemberTypeSlot.Parameter).UnboxAfterMarhsal(p.Name, true);
                    if (p.IsIn)
                        value = value.Replace("ref ", "in ");

                    CS.Writer.Write(value);
                    if (lastP != p)
                        CS.Writer.Write(",");
                }
                CS.Writer.Write(");");

                CS.Writer.WriteLine($"var {name}Handle = ObjectStore.Store({name})");
                return $"{name}Handle";
            }
            else
            {
                //if (UnityEngine_Vector3__ctor_94_info == null)
                //    UnityEngine_Vector3__ctor_94_info = typeof(UnityEngine.Vector3).GetConstructor(new Type[] { typeof(System.Single), typeof(System.Single), typeof(System.Single) });
                //UnityEngine_Vector3__ctor_94_info.Invoke(thiz, System.Reflection.BindingFlags.Default, Type.DefaultBinder, new object[] { x, y, z }, null);

                /*var infoName = Utils.BindMethodName(method, true, false) + "_info";
                CS.Writer.WriteLine($"if({infoName} == null)", false);
                CS.Writer.Write($"{infoName} = typeof({TypeResolver.Resolve(method.DeclaringType).RealTypeName()}).GetConstructor(new Type[] {{ ");
                var lastP = method.Parameters.LastOrDefault();
                foreach (var p in method.Parameters)
                {
                    CS.Writer.Write($"typeof({TypeResolver.Resolve(p.ParameterType).RealTypeName()})");
                    if (lastP != p)
                        CS.Writer.Write(",");
                }
                CS.Writer.Write(" });");

                CS.Writer.WriteLine($"{infoName}.Invoke(thiz, System.Reflection.BindingFlags.Default, Type.DefaultBinder, new object[] {{", false);
                lastP = method.Parameters.LastOrDefault();
                foreach (var p in method.Parameters)
                {
                    CS.Writer.Write(TypeResolver.Resolve(p.ParameterType).Unbox(p.Name, true));
                    if (lastP != p)
                        CS.Writer.Write(",");
                }
                CS.Writer.Write("}, null);");*/

                CS.Writer.WriteLine($"var n = new {TypeResolver.Resolve(method.DeclaringType).RealTypeName()}(",false);
                var lastP = method.Parameters.LastOrDefault();
                foreach (var p in method.Parameters)
                {
                    CS.Writer.Write(TypeResolver.Resolve(p.ParameterType, method, MemberTypeSlot.Parameter).UnboxAfterMarhsal(p.Name, true));
                    if (lastP != p)
                        CS.Writer.Write(",");
                }
                CS.Writer.Write(");");
                CS.Writer.WriteLine("thiz = n");
                return "";
            }
        }
    }

    public class SetterMethodResolver : BaseMethodResolver
    {
        public SetterMethodResolver(MethodDefinition _method) : base(_method)
        {
        }

        /// <summary>
        /// var thizObj = (GameObject)ObjectStore.Get(thiz);
		/// thizObj.layer = value;
        /// </summary>
        /// <returns> valueHandle </returns>
        public override string IL2CppImplement(string name)
        {
            name = "value";
            var thizObj = GetThizObj();
            var propertyName = method.Name.Substring("set_".Length);
            var valueName = TypeResolver.Resolve(method.Parameters.First().ParameterType, method, MemberTypeSlot.Parameter).UnboxAfterMarhsal(name, true);
            CS.Writer.WriteLine($"{thizObj}.{propertyName} = {valueName}");
            return "";
        }
    }

    public class GetterMethodResolver : BaseMethodResolver
    {
        public GetterMethodResolver(MethodDefinition _method) : base(_method)
        {
        }

        /// <summary>
        /// var thizObj = (GameObject)ObjectStore.Get(thiz);
		/// var value = thizObj.layer;
		/// return value;
        /// </summary>
        /// <returns> value </returns>
        public override string IL2CppImplement(string name)
        {
            var thizObj = GetThizObj();
            var propertyName = method.Name.Substring("get_".Length);
            CS.Writer.WriteLine($"var {name} = {thizObj}.{propertyName}");
            return TypeResolver.Resolve(method.ReturnType, method).BoxBeforeMarshal(name);
        }
    }

    public class AddOnMethodResolver : BaseMethodResolver
    {
        bool isEvent;
        string propertyName;
        string uniqueName;
        public AddOnMethodResolver(MethodDefinition _method,bool _event) : base(_method)
        {
            isEvent = _event;

            propertyName = method.Name.Substring(4);//trim "add_" or "set_"
            uniqueName = method.DeclaringType.Name.Replace("/", "_") + "_" + propertyName;
        }

        /*
        
    [MonoPInvokeCallback(typeof(UnityEngine_Application_logMessageReceived_Type))]
	static void UnityEngine_Application_logMessageReceived (IntPtr value_p)
	{
        logMessageReceived = Marshal.GetDelegateForFunctionPointer<Action<int, int, int>>(value_p);
        UnityEngine.Application.logMessageReceived += OnlogMessageReceived;
	}
             */
        public override string IL2CppImplement(string name)
        {
            
            var isStatic = method.IsStatic;
            var type = method.Parameters.FirstOrDefault().ParameterType;

            name = "value";
            var thizObj = GetThizObj();

            var res = TypeResolver.Resolve(type,method).UnboxAfterMarhsal(name);

            //CS.Writer.WriteLine($"{uniqueName} = Marshal.GetDelegateForFunctionPointer<{eventDeclear}>({name}_p)");

            var actionTarget = res;// isStatic ? $"{res}" : $"{thizObj}.On{uniqueName}";
            var op = isEvent ? "+=" : "=";
            CS.Writer.WriteLine($"{thizObj}.{propertyName} {op} {actionTarget}");
            
            return "";
        }
    }

    public class RemoveOnMethodResolver : BaseMethodResolver
    {
        string propertyName;
        string uniqueName;
        public RemoveOnMethodResolver(MethodDefinition _method) : base(_method)
        {
            propertyName = method.Name.Substring("remove_".Length);
            uniqueName = method.DeclaringType.Name.Replace("/", "_") + "_" + propertyName;
        }
        
        public override string IL2CppImplement(string name)
        {
            name = "value";
            var thizObj = GetThizObj();
            //var isStatic = method.IsStatic;

            var type = method.Parameters.FirstOrDefault().ParameterType;
            var res = TypeResolver.Resolve(type,method).UnboxAfterMarhsal(name);

            var actionTarget = res;// isStatic ? $"On{uniqueName}" : $"{thizObj}.On{uniqueName}";
            CS.Writer.WriteLine($"{thizObj}.{propertyName} -= {actionTarget}");
            return "";
        }
    }

    public class EventMethodResolver : BaseMethodResolver
    {
        enum EventType
        {
            none,
            addon,
            removeon,
        }
        EventType eventType;
        public EventMethodResolver(MethodDefinition _method) : base(_method)
        {
            if(_method.DeclaringType.IsSubclassOf("UnityEngine.Events.UnityEventBase"))
            {
                if (_method.Name == "AddListener")
                    eventType = EventType.addon;
                else if (_method.Name == "RemoveListener")
                    eventType = EventType.removeon;
            }
        }

        public static bool IsUnityEventMethod(MethodDefinition _method)
        {
            var firstParam = _method.Parameters.FirstOrDefault()?.ParameterType?.Resolve();
            if (_method.Parameters.Count == 1 && firstParam != null && firstParam.IsDelegate())
            {
                if (_method.DeclaringType.IsSubclassOf("UnityEngine.Events.UnityEventBase"))
                {
                    if (_method.Name == "AddListener" || _method.Name == "RemoveListener")
                        return true;
                }
            }
            return false;
        }

        public override string MonoImplement(string name)
        {
            if(eventType == EventType.none)
                return base.MonoImplement(name);

            var firstParam = method.Parameters.FirstOrDefault();
            string _member = DelegateResolver.LocalMamberName(firstParam.Name, method);

            var res = "";

            if (eventType == EventType.addon)
            {
                CS.Writer.WriteLine($"bool attach = ({_member} == null)");
                CS.Writer.WriteLine($"{_member} += {firstParam.Name}");
                CS.Writer.Start("if(attach)");
            }
            else
            {
                CS.Writer.WriteLine($"{_member} -= {firstParam.Name}");
                CS.Writer.Start($"if({_member} == null)");
            }

            res = base.MonoImplement(name);

            if (!method.IsStatic)
                CS.Writer.WriteLine($"ObjectStore.RefMember(this,ref {_member}_ref,{_member})"); // resist gc

            CS.Writer.End(); //if(attach)

            return res;

        }

    }
}

