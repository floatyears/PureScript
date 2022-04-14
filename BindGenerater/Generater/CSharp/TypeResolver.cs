using Mono.Cecil;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Generater
{
    [Flags]
    public enum MemberTypeSlot
    {
        None = 0,

        LocalVar = 0x1,

        Parameter = 0x2,

        ReturnType = 0x4,
    }

    public enum MethodTypeSlot
    {
        None = 0,

        GeneratedMethod = 1,

        GeneratedDelegate = 2,
    }

    public class MemberTypeContext
    {
        private MemberTypeSlot typeSlot;
        private MethodTypeSlot methodType;
        private IMemberDefinition context;

        public MemberTypeContext(MemberTypeSlot typeSlot, MethodTypeSlot methodTypeSlot, IMemberDefinition memberDef)
        {
            this.typeSlot = typeSlot;
            this.methodType = methodTypeSlot;
            this.context = memberDef;
        }

        public IMemberDefinition memberDefinition { get { return context; } }

        public bool IsGeneratedDelegate
        {
            get
            {
                return methodType == MethodTypeSlot.GeneratedDelegate;
            }
        }

        public bool IsGenerated
        {
            get
            {
                return methodType == MethodTypeSlot.GeneratedDelegate || methodType == MethodTypeSlot.GeneratedMethod;
            }
        }

        public bool IsReturnType
        {
            get
            {
                return (typeSlot & MemberTypeSlot.ReturnType) > 0;
            }
        }

        public bool IsParamerterType
        {
            get
            {
                return (typeSlot & MemberTypeSlot.Parameter) > 0;
            }
        }

    }

    public class TypeResolver
    {
        public static bool WrapperSide;
        public static BaseTypeResolver Resolve(TypeReference _type, IMemberDefinition _context = null, MemberTypeSlot slot = 0, MethodTypeSlot methodType = 0)
        {
            var type = _type.Resolve();
            var context = new MemberTypeContext(slot, methodType, _context);

            if (Utils.IsDelegate(_type))
                return new DelegateResolver(_type, context);

            if (_type.Name.Equals("Void"))
                return new VoidResolver(_type, context);

           // if (_type.Name.StartsWith("List`"))
           //     return new ListResolver(_type);
            if(_type.IsArray)
            {
                return new ArrayResolver(_type, context);
            }

            if (_type.Name.Equals("String") || _type.FullName.Equals("System.Object"))
                return new StringResolver(_type, context);
            if (type != null && type.IsEnum)
                return new EnumResolver(_type, context);

            if (_type.IsGenericParameter || _type.IsGenericInstance || type == null)
                return new GenericResolver(_type, context);

            if (_type.IsPrimitive || _type.IsPointer)
                return new BaseTypeResolver(_type, context);

            if (_type.FullName.StartsWith("System."))
                return new SystemResolver(_type, context);

            if (_type.IsValueType || (_type.IsByReference && _type.GetElementType().IsValueType))
                return new StructResolver(_type, context);

            return new ClassResolver(_type, context);

        }
    }

    public class BaseTypeResolver
    {

        protected TypeReference type;

        public object data;

        public MemberTypeContext context {  get; private set; }

        public BaseTypeResolver(TypeReference _type, MemberTypeContext _context)
        {
            type = _type;
            context = _context;
        }

        public virtual string ParamerSuffix()
        {
            return string.Empty;
        }

        public virtual string Paramer(string name, bool checkBlittable = false)
        {
            return $"{TypeName(checkBlittable)} {name}{ParamerSuffix()}";
        }

        public virtual string LocalVariable(string name, bool checkBlittable = false)
        {
            if(checkBlittable && !Utils.IsBlittableType(type))
            {
                return $"IntPtr {name}{ParamerSuffix()}";
            }
            else
            {
                return Paramer(name);
            }
        }

        public virtual string TypeName(bool checkBlittable = false)
        {
            return RealTypeName(checkBlittable);
        }

        protected string Alias()
        {
            var tName = type.FullName;
            var et = type.GetElementType();
            if (et != null)
                tName = et.FullName;
            switch (tName)
            {
                case "System.Void":
                    tName = "void";
                    break;
                case "System.Int32":
                    tName = "int";
                    break;
                case "System.Object":
                    tName = "object";
                    break;

                default:
                    if (!tName.StartsWith("System") && !type.IsGeneric())
                        tName = "global::" + tName;

                    break;
            }

            if (et != null)
                tName = type.FullName.Replace(et.FullName, tName);

            var genericIndex = tName.IndexOf('`');
            if(genericIndex > 0)
            {
                tName = tName.Remove(genericIndex, 2);
            }

            return tName.Replace("/",".");
        }

        public virtual string Unbox(string name,bool previous = false)
        {
            if (type.IsByReference)
                return "ref " + name;
            else
                return name;
        }
        public virtual string Box(string name)
        {
            if (type.IsByReference)
                return "ref " + name;
            else
                return name;
        }

        public string RealTypeName(bool checkBlittable = false)
        {
            var et = type.GetElementType();

            var tName = Alias();

            if (type.IsByReference && (et.IsValueType || et.IsGeneric()))
                tName = "ref " + tName.Replace("&", "");

            return tName;
        }
    }

    public class VoidResolver : BaseTypeResolver
    {
        public VoidResolver(TypeReference type, MemberTypeContext context) : base(type, context)
        {
        }

        public override string Box(string name)
        {
            return "";
        }

        public override string TypeName(bool checkBlittable = false)
        {
            return $"void";
        }
    }

    public class EnumResolver : BaseTypeResolver
    {
        public EnumResolver(TypeReference type, MemberTypeContext context) : base(type, context)
        {
        }
        
        public override string TypeName(bool checkBlittable = false)
        {
            return "int";
        }

        /// <summary>
        /// var type_e = (PrimitiveType)type;
        /// </summary>
        /// <returns> type_e </returns>
        public override string Box(string name)
        {
            CS.Writer.WriteLine($"var {name}_e = (int) {name}");
            return $"{name}_e";
        }

        /// <summary>
        /// var type_e = (int) type;
        /// </summary>
        /// <returns> type_e </returns>
        public override string Unbox(string name,bool previous)
        {
            var unboxCmd = $"var {name}_e = ({RealTypeName()}){name}";
            if (previous)
                CS.Writer.WritePreviousLine(unboxCmd);
            else
                CS.Writer.WriteLine(unboxCmd);
            return $"{name}_e";
        }
    }

    public class ArrayResolver : BaseTypeResolver
    {
        public ArrayResolver(TypeReference type, MemberTypeContext context) : base(type, context)
        {

        }

        public override string TypeName(bool checkBlittable = false)
        {
            if (checkBlittable && !Utils.IsBlittableType(type))
            {
                return "IntPtr";
            }
            else
            {
                return base.TypeName();
            }
        }

        /// <summary>
        /// 理论上自动生成的delegate的，返回值是从mono传入到il2cpp，il2cpp再传回到mono，所以这里只需要传递gchandle
        /// </summary>
        /// <param name="name"></param>
        /// <param name="previous"></param>
        /// <returns></returns>
        public override string Unbox(string name, bool previous)
        {
            if (CS.Writer.WriterType == CodeWriter.CodeWriterType.MonoBind)
            {
                if (context.IsGenerated && !context.IsParamerterType)
                {
                    if (context.IsGeneratedDelegate)
                    {
                        CS.Writer.WriteLine($"var {name}_gchandle = GCHandle.FromIntPtr({name})");
                        CS.Writer.WriteLine($"var {name}_p = ({name}_gchandle != null) ? ({Utils.FullName(type)}){name}_gchandle.Target : null;");
                        CS.Writer.WriteLine($"if({name}_gchandle != null){{ {name}_gchandle.Free();}}");
                        //CS.Writer.WriteLine($"var {name}_p = ({Utils.FullName(type)})Marshal.PtrToStructure({name}, typeof({Utils.FullName(type)}))");
                        return $"{name}_p";
                    }
                    else
                    {
                        //if (Utils.IsBlittableType(type.GetElementType()) && !type.GetElementType().Resolve().IsEnum)
                        //{
                        //    var typeName = Utils.FullName(type.GetElementType());
                        //    CS.Writer.WriteLine($"var {name}_arr = __arrayLen >= 0 ? new {typeName}[__arrayLen] : ({Utils.FullName(type)})null");
                        //    CS.Writer.WriteLine($"if({name}_arr != null) Marshal.Copy({name}, {name}_arr, 0, __arrayLen);");
                        //    //CS.Writer.WriteLine($"var {name}_p = ({Utils.FullName(type)})Marshal.PtrToStructure({name}, typeof({Utils.FullName(type)}))");
                        //    return $"{name}_arr";
                        //}
                        //else if (Utils.IsFullValueType(type.GetElementType()))//结构体的
                        //{
                        //    var typeName = Utils.FullName(type.GetElementType());
                        //    CS.Writer.WriteLine($"var {name}_arr = __arrayLen >= 0 ? new {typeName}[__arrayLen] : ({Utils.FullName(type)})null");
                        //    CS.Writer.WriteLine($"var {name}_size = Marshal.SizeOf(typeof({typeName}))");
                        //    CS.Writer.WriteLine($"for(int i = 0; i < __arrayLen; i++){{", false);
                        //    CS.Writer.WriteLine($"{name}_arr[i] = ({typeName})Marshal.PtrToStructure(new IntPtr({name}.ToInt64() + i * {name}_size), typeof({typeName}))");
                        //    CS.Writer.WriteLine($"}}", false);

                        //    return $"{name}_arr";
                        //}else
                        //{
                        //    var typeName = Utils.FullName(type.GetElementType());
                        //    CS.Writer.WriteLine($"var {name}_arr = __arrayLen >= 0 ? new {typeName}[__arrayLen] : ({Utils.FullName(type)})null");
                        //    CS.Writer.WriteLine($"var {name}_size = Marshal.SizeOf(typeof({typeName}))");
                        //    CS.Writer.WriteLine($"for(int i = 0; i < __arrayLen; i++){{", false);
                        //    CS.Writer.WriteLine($"{name}_arr[i] = ({typeName})Marshal.PtrToStructure(new IntPtr({name}.ToInt64() + i * {name}_size), typeof({typeName}))");
                        //    CS.Writer.WriteLine($"}}", false);

                        //    return $"{name}_arr";
                        //}
                        //以上是marshal，下面的是internal call，internal call要注意gc时的内存

                        CS.Writer.WriteLine($"var {name}_arr = ObjectStore.GetObjectByPtrMono(__retArrayPtr) as {Utils.FullName(type)}");
                        return $"{name}_arr";

                    }
                }
                else
                {
                    return base.Unbox(name, previous);
                }
            }
            else
            {
                return base.Unbox(name, previous);
            }
            
        }

        /// <summary>
        /// 理论上自动生成的delegate的，返回值是从mono传入到il2cpp，il2cpp再传回到mono，所以这里只需要传递gchandle
        /// </summary>
        /// <param name="name"></param>
        /// <returns></returns>
        public override string Box(string name)
        {
            if (CS.Writer.WriterType == CodeWriter.CodeWriterType.MonoBind && context.IsGenerated && context.IsReturnType)
            {
                
                CS.Writer.WriteLine($"var {name}_p = GCHandle.ToIntPtr(GCHandle.Alloc({name}))"); 
                //CS.Writer.WriteLine($"var {name}_p = Marshal.StructureToPtr({name}))");
                return $"{name}_p";
            }
            else
            {
                return base.Box(name);
            }
        }
    }

    public class AttributeResolver : BaseTypeResolver
    {
        public AttributeResolver(TypeReference type, MemberTypeContext context) : base(type, context)
        {

        }
    }

    public class ClassResolver : BaseTypeResolver
    {
        public ClassResolver(TypeReference type, MemberTypeContext context) : base(type, context)
        {
        }

        public override string ParamerSuffix()
        {
            return "_h";
        }
        //public override string Paramer(string name)
        //{
        //    return $"{TypeName()} {name}_h";
        //}

        public override string TypeName(bool checkBlittable = false)
        {
            return "IntPtr";
        }

        /// <summary>
        /// var value_h = ObjectStore.Store(value);
        /// </summary>
        /// <returns> value_h </returns>
        public override string Box(string name)
        {
            if(TypeResolver.WrapperSide)
            {
                if (type.Resolve().IsInterface)
                {
                    CS.Writer.WriteLine($"var {name}_h = ({name} as WObject).__GetHandle()");
                }
                else
                {
                    CS.Writer.WriteLine($"var {name}_h = {name}.__GetHandle()");
                }
            }
            else
                CS.Writer.WriteLine($"var {name}_h = ObjectStore.Store({name})");
            return $"{name}_h";
        }

        /// <summary>
        /// var resObj = ObjectStore.Get<GameObject>(res);
        /// </summary>
        /// <returns> resObj </returns>
        public override string Unbox(string name, bool previous)
        {
            var unboxCmd = "";
            if (TypeResolver.WrapperSide && type.Resolve().IsInterface)
            {
                unboxCmd = $"var {name}Obj = ObjectStore.Get<WObject>({name}_h) as {RealTypeName()}";
            }
            else
            {
                unboxCmd = $"var {name}Obj = ObjectStore.Get<{RealTypeName()}>({name}_h)";
            }
            if (previous)
                CS.Writer.WritePreviousLine(unboxCmd);
            else
                CS.Writer.WriteLine(unboxCmd);
            return $"{name}Obj";
        }
    }

    public class ListResolver : BaseTypeResolver
    {
        BaseTypeResolver resolver;
        TypeReference genericType;
        public ListResolver(TypeReference type, MemberTypeContext context) : base(type, context)
        {
            var genericInstace = type as GenericInstanceType;
            genericType = genericInstace.GenericArguments.First();
            resolver = TypeResolver.Resolve(genericType);
        }

        public override string TypeName(bool checkBlittable = false)
        {
            return $"List<{resolver.TypeName()}>";
        }

        public override string Box(string name)
        {
            CS.Writer.WriteLine($"{TypeName()} {name}_h = new {TypeName()}()");
            CS.Writer.Start($"foreach (var item in { name})");
            var res = resolver.Box("item");
            CS.Writer.WriteLine($"{name}_h.add({res})");
            CS.Writer.End();
            return $"{name}_h";
        }
        public override string Unbox(string name, bool previous)
        {
            using (new LP(CS.Writer.CreateLinePoint("//list unbox", previous)))
            {
                var relTypeName = $"List<{TypeResolver.Resolve(genericType).RealTypeName()}>";
                CS.Writer.WriteLine($"{relTypeName} {name}_r = new {relTypeName}()");
                CS.Writer.Start($"foreach (var item in { name})");
                var res = resolver.Unbox("item");
                CS.Writer.WriteLine($"{name}_r.add({res})");
                CS.Writer.End();
            }

            return $"{name}_r";
        }
    }

    public class DelegateResolver : BaseTypeResolver
    {
        bool isStaticMember;
        TypeReference declarType;
        MethodDefinition contextMember;
        string uniqueName;
        int paramCount;
        bool returnValue;

        static HashSet<string> BoxedMemberSet = new HashSet<string>();
        static HashSet<string> UnBoxedMemberSet = new HashSet<string>();

        private static string _Member(string name)
        {
            return $"_{name}";
        }
        private static string _Action(string name)
        {
            return $"{name}Action";
        }

        public static string LocalMamberName(string name, MethodDefinition context)
        {
            var uniq = FullMemberName(context);
            return _Member($"{uniq}_{name}");
        }

        public DelegateResolver(TypeReference type, MemberTypeContext context) : base(type, context)
        {
            var method = context.memberDefinition as MethodDefinition;
            if (method != null)
            {
                //if(!method.IsCompilerControlled)
                {
                    contextMember = method;
                    isStaticMember = method.IsStatic;
                    declarType = method.DeclaringType;
                    paramCount = method.Parameters.Count;
                    returnValue = !method.ReturnType.IsVoid();
                    uniqueName = FullMemberName(method);
                }
            }
            else
            {
                isStaticMember = false;
            }
        }

        static string FullMemberName(MethodDefinition method)
        {
            var methodName = method.Name;
            if (method.IsAddOn) // || method.IsSetter || method.IsGetter)
                methodName = methodName.Substring("add_".Length);//trim "add_" or "set_"
            else if (method.IsRemoveOn)
                methodName = methodName.Substring("remove_".Length);//trim "remove_"

            // Special to AddListener / RemoveListener
            else if (method.Parameters.Count == 1 && methodName.StartsWith("Add"))
                methodName = methodName.Substring("Add".Length);// trim "Add"  
            else if (method.Parameters.Count == 1 && methodName.StartsWith("Remove"))
                methodName = methodName.Substring("Remove".Length);// trim "Remove"  

            return method.DeclaringType.Name.Replace("/", "_") + "_" + methodName.Replace(".", "_");
        }

        public override string ParamerSuffix()
        {
            return "_p";
        }
        //public override string Paramer(string name)
        //{
        //    return $"{TypeName()} {name}_p";
        //}

        public override string TypeName(bool checkBlittable = false)
        {
            return "IntPtr";
        }

        /*
        static event global::UnityEngine.Application.LogCallback _logMessageReceived;
        static Action<int, int, int> logMessageReceivedAction = OnlogMessageReceived;
        static void OnlogMessageReceived(int arg0,int arg1,int arg2)
        {
            _logMessageReceived(unbox(arg0), unbox(arg1), unbox(arg2));
        }
         */
        bool WriteBoxedMember(string name)
        {
            bool isUnityBind = CS.Writer.WriterType == CodeWriter.CodeWriterType.UnityBind;
            if (contextMember == null)
                return false;

            var varName = uniqueName + name;
            if (BoxedMemberSet.Contains(varName))
                return true;
            BoxedMemberSet.Add(varName);

            string _member = _Member(name);// _logMessageReceived
            string _action = _Action(name);// logMessageReceivedAction

            var flag = (isUnityBind || isStaticMember) ? "static" : "";
            var eventTypeName = TypeResolver.Resolve(type).RealTypeName();
            if (type.IsGenericInstance)
                eventTypeName = Utils.GetGenericTypeName(type);

            var eventDeclear = Utils.GetDelegateWrapTypeName(type, isStaticMember ? null : declarType); //Action <int,int,int>
            var paramTpes = Utils.GetDelegateParams(type, isStaticMember ? null : declarType, out var returnType); // string , string , LogType ,returnType
            var returnTypeName = returnType != null ? TypeResolver.Resolve(returnType, null, MemberTypeSlot.ReturnType, MethodTypeSlot.GeneratedDelegate).TypeName(CS.Writer.WriterType == CodeWriter.CodeWriterType.MonoBind) : "void";

            //static event global::UnityEngine.Application.LogCallback _logMessageReceived;
            CS.Writer.WriteLine($"public {flag} {eventTypeName} {_member}");

            if(!isUnityBind && !isStaticMember)
                CS.Writer.WriteLine($"public GCHandle {_member}_ref"); // resist gc

            //static Action<int, int, int> logMessageReceivedAction = OnlogMessageReceived;
            CS.Writer.WriteLine($"static {eventDeclear} {_action} = On{name}");

            //static void OnlogMessageReceived(int arg0,int arg1,int arg2)
            if(isUnityBind)
            {
                CS.Writer.WriteLine($"[MonoPInvokeCallback(typeof({eventDeclear}))]", false);
            }
            var eventFuncDeclear = $"static {returnTypeName} On{name}(";

            for (int i = 0; i < paramTpes.Count; i++)
            {
                var p = paramTpes[i];
                eventFuncDeclear += TypeResolver.Resolve(p).LocalVariable($"arg{i}");
                if (i != paramTpes.Count - 1)
                {
                    eventFuncDeclear += ",";
                }
            }
            eventFuncDeclear += ")";

            CS.Writer.Start(eventFuncDeclear);
            CS.Writer.WriteLine("Exception __e = null");
            CS.Writer.Start("try");
            //_logMessageReceived(unbox(arg0), unbox(arg1), unbox(arg2));
            var callCmd = $"{_member}(";
            var targetObj = "";
            var checkCond = "";
            for (int i = 0; i < paramTpes.Count; i++)
            {
                var p = paramTpes[i];
                var param = TypeResolver.Resolve(p, null, MemberTypeSlot.Parameter, MethodTypeSlot.GeneratedDelegate).Unbox($"arg{i}");

                if (i == 0 && !isStaticMember)
                {
                    if(isUnityBind)
                    {
                        checkCond = $"if({param} == {_member}.Target) ";
                    }
                    else
                    {
                        targetObj = param + ".";
                    }
                    continue;
                }

                callCmd += param;
                if (i != paramTpes.Count - 1)
                    callCmd += ",";
            }
            callCmd += ")";

            if (!string.IsNullOrEmpty(targetObj))
                callCmd = targetObj + callCmd;
            
            if (returnType != null)
            {
                CS.Writer.WriteLine($"var res = default({Utils.FullName(returnType)})");
                callCmd = $"res = " + callCmd;
            }
            if (!string.IsNullOrEmpty(checkCond))
                callCmd = checkCond + callCmd;

            CS.Writer.WriteLine(callCmd);
            if (returnType != null)
            {
                var res = TypeResolver.Resolve(returnType, null, MemberTypeSlot.ReturnType, MethodTypeSlot.GeneratedDelegate).Box("res");
                CS.Writer.WriteLine($"return {res}");
            }
            CS.Writer.End();//try
            CS.Writer.Start("catch(Exception e)");
            CS.Writer.WriteLine("__e = e");
            CS.Writer.End();//catch
            CS.Writer.WriteLine("if(__e != null)", false);
            CS.Writer.WriteLine("ScriptEngine.OnException(__e)");
            if (returnType != null)
                CS.Writer.WriteLine($"return default({returnTypeName})");

            CS.Writer.End();//method

            return true;
        }

        /*
        static Action <int,int,int> logMessageReceived;
        static Action <int,int,int> logMessageReceivedAction;
        static void OnlogMessageReceived(string arg0, string arg1, LogType arg2)
        {
            logMessageReceived(box(arg0), box(arg1), box(arg2));
        }

         */
        bool WriteUnboxedMember(string name)
        {
            if (contextMember == null)
                return false;

            var varName = uniqueName + name;

            if (UnBoxedMemberSet.Contains(varName))
                return false;
            UnBoxedMemberSet.Add(varName);

            string _member = _Member(name);// _logMessageReceived
            string _action = _Action(name);// logMessageReceivedAction

            var eventTypeName = TypeResolver.Resolve(type).RealTypeName();
            var paramTpes = Utils.GetDelegateParams(type, isStaticMember ? null : declarType, out var returnType); // string , string , LogType ,returnType
            var returnTypeName = returnType != null ? TypeResolver.Resolve(returnType).RealTypeName() : "void";
            var eventDeclear = Utils.GetDelegateWrapTypeName(type, isStaticMember ? null : declarType); //Action <int,int,int>

            //static void OnlogMessageReceived(string arg0, string arg1, LogType arg2)
            //mono bind内非static的delegate需要返回当前的实例对象而不是static的对象
            bool isMonoBind = CS.Writer.WriterType == CodeWriter.CodeWriterType.MonoBind;
            bool isMonoBindInstanceGetter = CS.Writer.WriterType == CodeWriter.CodeWriterType.MonoBind && !isStaticMember && contextMember.IsGetter;
            var eventFuncDeclear = $"{(isMonoBindInstanceGetter ? "" : "static")} {returnTypeName} On{name}(";
            for (int i = 0; i < paramTpes.Count; i++)
            {
                if(isMonoBindInstanceGetter && i == 0)
                {
                    continue;
                }
                var p = paramTpes[i];
                if (!isStaticMember && i == 0)
                    eventFuncDeclear += "this ";
                eventFuncDeclear += $"{TypeResolver.Resolve(p).RealTypeName()} arg{i}";
                if (i != paramTpes.Count - 1)
                {
                    eventFuncDeclear += ",";
                }
            }
            eventFuncDeclear += ")";

            //mono bind内非static的delegate需要返回当前的实例对象而不是static的对象
            CS.Writer.WriteLine($"{(isMonoBindInstanceGetter ? "" : "static")} {(isMonoBind ? eventTypeName : eventDeclear)} {_member}"); //mono层内自己的函数指针单独保存
            //这个的目的是用一个delegate单独存储指向il2cpp的函数指针，
            CS.Writer.WriteLine($"{(isMonoBindInstanceGetter ? "" : "static")} {eventDeclear} {_action}");

            CS.Writer.Start(eventFuncDeclear);

            var callCmd = $"{_action}(";
            if (returnType != null)
            {
                var localVar = TypeResolver.Resolve(returnType, null, MemberTypeSlot.ReturnType, MethodTypeSlot.GeneratedDelegate).Paramer("res", CS.Writer.WriterType == CodeWriter.CodeWriterType.MonoBind);
                if(localVar.StartsWith("ref "))
                    localVar = localVar.Replace("ref ", "");
                callCmd = localVar + " = " + callCmd;
            }

            for (int i = 0; i < paramTpes.Count; i++)
            {
                var p = paramTpes[i];
                callCmd += TypeResolver.Resolve(p, null, MemberTypeSlot.Parameter, MethodTypeSlot.GeneratedDelegate).Box(isMonoBindInstanceGetter && i == 0 ? "this" : $"arg{i}");

                if (i != paramTpes.Count - 1)
                    callCmd += ",";
            }

            callCmd += ")";
            CS.Writer.WriteLine(callCmd);
            CS.Writer.WriteLine("ScriptEngine.CheckException()");
            if (returnType != null)
            {
                var res = TypeResolver.Resolve(returnType, null, MemberTypeSlot.ReturnType, MethodTypeSlot.GeneratedDelegate).Unbox("res");
                CS.Writer.WriteLine($"return {res}");
            }

            CS.Writer.End();
            return true;
        }

        public override string Box(string name)
        {
            var memberUniqueName = $"{uniqueName}_{name}";
            bool writeBoxed = false;
            bool isUnityBind = CS.Writer.WriterType == CodeWriter.CodeWriterType.UnityBind;
            using (new LP(CS.Writer.GetLinePoint(!isUnityBind ? "//member" : "//Method")))
            {
                writeBoxed = WriteBoxedMember(memberUniqueName);
            }
            
            var _action = _Action(memberUniqueName);
            var _member = _Member(memberUniqueName);
            if(isUnityBind)
            {
                CS.Writer.WriteLine($"{_member} = {name}");
            }
            CS.Writer.WriteLine($"var {memberUniqueName}_p = {(writeBoxed ? _action : name)} != null ? Marshal.GetFunctionPointerForDelegate({(writeBoxed ? _action : name)}) : IntPtr.Zero");
            return $"{memberUniqueName}_p";
        }

        
        public override string Unbox(string name, bool previous)
        {
            var memberUniqueName = $"{uniqueName}_{name}";
            bool writeUnboxed = false;
            var isMonoBindInstanceGetter = CS.Writer.WriterType == CodeWriter.CodeWriterType.MonoBind && !isStaticMember && contextMember.IsGetter;
            if(!contextMember.IsRemoveOn)
            {
                var isMonoBindGetterSetter = CS.Writer.WriterType == CodeWriter.CodeWriterType.MonoBind && contextMember != null && (contextMember.IsSetter || contextMember.IsGetter);
                using (new LP(CS.Writer.GetLinePoint(isMonoBindGetterSetter ? "//member" : "//Method")))
                {
                    writeUnboxed = WriteUnboxedMember(memberUniqueName);
                }

                var _action = _Action(memberUniqueName);
                string _member = _Member(memberUniqueName);// _logMessageReceived

                string ptrName = $"{name}_p";

                var eventDeclear = Utils.GetDelegateWrapTypeName(type, isStaticMember ? null : declarType);

                var unboxCmd = $"{(writeUnboxed ? _action : _member)} = {ptrName} == IntPtr.Zero ? null: Marshal.GetDelegateForFunctionPointer<{eventDeclear}>({ptrName})";
                if (previous)
                    CS.Writer.WritePreviousLine(unboxCmd);
                else
                    CS.Writer.WriteLine(unboxCmd);
            } 

            var resCmd = $"On{memberUniqueName}";
            if (!isStaticMember && !isMonoBindInstanceGetter)
                resCmd = "thizObj." + resCmd;

            return resCmd;
        }
    }

    public class StructResolver : BaseTypeResolver
    {

        public StructResolver(TypeReference type, MemberTypeContext context) : base(type, context)
        {
        }

        public override string Paramer(string name, bool checkBlittable = false)
        {
            if(type.IsByReference)
                return base.Paramer(name, checkBlittable);
            else 
                return "ref " + base.Paramer(name, checkBlittable);
        }

        public override string LocalVariable(string name, bool checkBlittable = false)
        {
            if(checkBlittable)
            {
                return $"IntPtr {name}{ParamerSuffix()}";
            }
            else
            {
                return base.Paramer(name);
            }
            
        }


        public override string Box(string name)
        {
            name = base.Box(name);
            if (!context.IsGeneratedDelegate && TypeResolver.WrapperSide && !name.StartsWith("ref "))
            {
                name = "ref " + name;
            }

            return name;
        }

        public override string Unbox(string name, bool previous = false)
        {
            if (context.IsGenerated && !context.IsParamerterType) //作为返回值
            {
                if (context.IsGeneratedDelegate)
                {
                    CS.Writer.WriteLine($"var {name}_gchandle = GCHandle.FromIntPtr({name})");
                    CS.Writer.WriteLine($"var {name}_p = ({name}_gchandle != null) ? ({Utils.FullName(type)}){name}_gchandle.Target : null");
                    CS.Writer.WriteLine($"if({name}_gchandle != null){{ {name}_gchandle.Free(); }}");
                    //CS.Writer.WriteLine($"var {name}_p = ({Utils.FullName(type)})Marshal.PtrToStructure({name}, typeof({Utils.FullName(type)}))");
                    return $"{name}_p";
                }
                else
                {
                    CS.Writer.WriteLine($"var {name}_st = ({Utils.FullName(type)})ObjectStore.GetObjectByPtrMono(__retStructPtr)");
                    //CS.Writer.WriteLine($"var {name}_p = ({Utils.FullName(type)})Marshal.PtrToStructure({name}, typeof({Utils.FullName(type)}))");
                    return $"{name}_st";
                }
            }
            else
            {
                return base.Unbox(name, previous);
            }
            //if (CS.Writer.WriterType == CodeWriter.CodeWriterType.MonoBind && !context.IsGeneratedDelegate)
            //{
            //    CS.Writer.WriteLine($"var {name}_p = {name} != null ? ({Utils.FullName(type)})Marshal.PtrToStructure({name}, typeof({Utils.FullName(type)})) : default({Utils.FullName(type)})");
            //    return $"{name}_p";
            //}
            //else
            //{
            //    return base.Unbox(name, previous);
            //}
        }
    }

    public class StringResolver : BaseTypeResolver
    {
        public StringResolver(TypeReference type, MemberTypeContext context) : base(type, context)
        {
        }

        public override string TypeName(bool checkBlittable = false)
        {
            if (checkBlittable && !Utils.IsBlittableType(type))
            {
                return "IntPtr";
            }
            else
            {
                return base.TypeName();
            }
        }

        /*public override string TypeName()
        {
            if (type.Name.Equals("Object"))
                return "object";

            return base.TypeName();
        }*/
        public override string Unbox(string name, bool previous = false)
        {
            //mono侧的生成的delegate的参数不用marshal
            if(CS.Writer.WriterType == CodeWriter.CodeWriterType.MonoBind && !context.IsParamerterType)
            {
                CS.Writer.WriteLine($"var {name}_p = Marshal.PtrToStringAnsi({name})");
                return $"{name}_p";
            }else
            {
                return base.Unbox(name, previous);
            }
            
        }

        public override string Box(string name)
        {
            //mono侧的生成的delegate的参数不用marshal
            if (CS.Writer.WriterType == CodeWriter.CodeWriterType.MonoBind && context.IsReturnType)
            {
                CS.Writer.WriteLine($"var {name}_p = Marshal.StringToHGlobalAnsi({name})");
                return $"{name}_p";
            }
            else
            {
                return base.Box(name);
            }
        }
    }

    public class SystemResolver : BaseTypeResolver
    {
        public SystemResolver(TypeReference type, MemberTypeContext context) : base(type, context)
        {
        }

        /* public override string TypeName()
         {
             if (type.Name.Equals("Object"))
                 return "object";

             return base.TypeName();
         }*/
        public override string Unbox(string name, bool previous = false)
        {
            if(!Utils.IsBlittableType(type) && CS.Writer.WriterType == CodeWriter.CodeWriterType.MonoBind)
            {
                if (type.IsStruct(false))
                {
                    CS.Writer.WriteLine($"var {name}_st = ({Utils.FullName(type)})ObjectStore.GetObjectByPtrMono(__retStructPtr)");
                    //CS.Writer.WriteLine($"var {name}_p = ({Utils.FullName(type)})Marshal.PtrToStructure({name}, typeof({Utils.FullName(type)}))");
                    return $"{name}_st";
                }
                else
                {
                    CS.Writer.WriteLine($"var {name}_p = ({Utils.FullName(type)})Marshal.PtrToStructure({name}, typeof({Utils.FullName(type)}))");
                    return $"{name}_p";
                }
            }
            else
            {
                return base.Unbox(name, previous);
            }
        }
    }

    public class GenericResolver : BaseTypeResolver
    {
        public GenericResolver(TypeReference type, MemberTypeContext context) : base(type, context)
        {
        }

    }
}
