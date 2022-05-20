using ICSharpCode.Decompiler.CSharp.Syntax;
using ICSharpCode.Decompiler.TypeSystem;
using Mono.Cecil;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Process = System.Diagnostics.Process;

namespace Generater
{
   public static class Utils
    {

        public static void Log(string str)
        {
            Console.WriteLine(str);
        }

        public static HashSet<string> IgnoreTypeSet = new HashSet<string>();
        public static HashSet<string> IgnoreMethodsSet = new HashSet<string>();
        public static HashSet<string> CSharpForceRetainMethods = new HashSet<string>();

        //declear : static void UnityEngine_GameObject_SetActive (int thiz_h, System.Boolean value)
        //or: MonoBind.UnityEngine_GameObject_SetActive(this.Handle, value)
        public static string BindMethodName(MethodDefinition method, bool declear = false,bool withParam = true, bool isInMono = false)
        {
            var name = method.DeclaringType.FullName + "_" + GetSignName(method);

            var res = ReName(name);
            if (!declear)
                res = "MonoBind." + res;

            if (withParam)
                res += BindMethodParamDefine(method, declear, isInMono);

            return res;
        }

        //declear : (int thiz_h, System.Boolean value)
        //or:(this.Handle, value)
        public static string BindMethodParamDefine(MethodDefinition method, bool declear = false, bool isInMono = false)
        {
            var param = "(";

            if (!method.IsStatic)
            {
                if(method.DeclaringType.IsValueType)
                {
                    if (declear)
                        param += TypeResolver.Resolve(method.DeclaringType).Paramer("thiz");
                    else
                        param += "ref this";
						
					if (method.HasParameters)
                        param += ", ";
                }
                else if (!method.IsConstructor)
                {
                    if (declear)
                        param += TypeResolver.Resolve(method.DeclaringType).Paramer("thiz");
                    else
                        param += "this.Handle";
						
					if (method.HasParameters)
                        param += ", ";
                }
            }

            var lastP = method.Parameters.LastOrDefault();
            foreach (var p in method.Parameters)
            {
                var pname = GetParamName(p);

                if (declear)
                {
                    param +=  TypeResolver.Resolve(p.ParameterType, method, MemberTypeSlot.Parameter).Paramer(pname, true) + (p == lastP ? "" : ", ");
                }
                else
                {
                    param += TypeResolver.Resolve(p.ParameterType, method, MemberTypeSlot.Parameter).BoxBeforeMarshal(pname) + (p == lastP ? "" : ", ");
                }

            }
            if(method.ReturnType != null)
            {
                if(method.ReturnType.IsArray)
                {
                    //delegate defines in mono can have array other than IntPtr
                    param += $"{(!method.IsStatic || method.HasParameters ? ", " : "")}ref {(declear ? (isInMono ? "IntPtr" : "IntPtr") : "")} __retArrayPtr, ref {(declear ? "int" : "")} __arrayLen";
                }
                else if(method.ReturnType.IsStruct(false)) //add struct as ref parameter
                {
                    param += $"{(!method.IsStatic || method.HasParameters ? ", " : "")}ref {(declear ? (isInMono ? "IntPtr" : "IntPtr") : "")} __retStructPtr";
                }
            }

            param += ")";

            return param;
        }

        public static string GetParamName(ParameterDefinition parameter)
        {
            //if (parameter.ParameterType is GenericInstanceType)
            //{
            //    var gp = parameter.ParameterType as GenericInstanceType;
            //    return $"{parameter.Name}_{gp.GenericArguments.Count}ga";
            //}
            return parameter.Name;
        }
        public static string ReName(string name)
        {
            return name.Replace("::", "_").Replace(".", "_").Replace("/","_");
        }

        public static string FullName(TypeReference type)
        {
            return type.FullName.Replace("/", ".");
        }

        static Dictionary<string, List<string>> NameDic = new Dictionary<string, List<string>>();
        static string GetSignName(MethodDefinition method)
        {
            string name = method.Name;
            foreach (var generic in method.GenericParameters)
                name += "_" + generic.FullName;

            List<string> nameList;
            if(!NameDic.TryGetValue(name,out nameList))
            {
                nameList = new List<string>();
                NameDic[name] = nameList;
            }

            string fullName = method.FullName;
            int signIndex = -1;
            for(int i = 0;i< nameList.Count;i++)
            {
                if(nameList[i].Equals(fullName))
                {
                    signIndex = i;
                    break;
                }
            }
            if (signIndex < 0)
            {
                signIndex = nameList.Count;
                nameList.Add(fullName);
            }

            if (signIndex > 0)
                name += "_" + signIndex;

            return name;
        }

        public static bool Filter(FieldDefinition property)
        {
            if (!property.IsPublic)
            {
                return false;
            }
            foreach (var attr in property.CustomAttributes)
            {
                if (attr.AttributeType.Name.Equals("ObsoleteAttribute"))
                    return false;
            }
            return true;
        }

        public static bool Filter(PropertyDefinition property)
        {
            bool hasPublicOrNoneGetterSetter = (property.GetMethod == null && property.SetMethod == null)
                || ((property.GetMethod != null && property.GetMethod.IsPublic) || (property.SetMethod != null && property.SetMethod.IsPublic));
            
            if(!hasPublicOrNoneGetterSetter)
            {
                return false;
            }

            if(property.HasThis && property.Name == "Item")
            {//TODO: this indexer
                return false; 
            }

            if (!Filter(property.PropertyType))
                return false;

            foreach (var attr in property.CustomAttributes)
            {
                if (attr.AttributeType.Name.Equals("ObsoleteAttribute"))
                    return false;
            }
            return true;
        }

        public static bool IsGenericMethodWithoutGenericType(MethodReference methodRef, List<MethodDefinition> calledMethods, List<MethodDefinition> refMethods = null)
        {
            if(refMethods == null)
            {
                refMethods = new List<MethodDefinition>(16);
            }
            var method = methodRef.Resolve();

            if(methodRef is GenericInstanceMethod)
            {
                var methodInst = (GenericInstanceMethod)methodRef;
                foreach(var g in methodInst.GenericArguments)
                {
                    if(g is GenericInstanceType)
                    {
                        var gt = (GenericInstanceType)g;
                        if (gt.HasGenericArguments)
                        {
                            return false;
                        }
                    }
                }
            }
            if (method.HasBody)
            {
                for (int i = 0; i < method.Body.Instructions.Count; i++)
                {
                    var il = method.Body.Instructions[i];
                    if (il.OpCode.Code == Mono.Cecil.Cil.Code.Call || il.OpCode.Code == Mono.Cecil.Cil.Code.Callvirt)
                    {
                        var cmethod = il.Operand as MethodReference;
                        var methodDef = cmethod.Resolve();
                        if (refMethods.Contains(methodDef))
                        {
                            continue;
                        }
                        else
                        {
                            refMethods.Add(methodDef);
                        }
                        if (!methodDef.DeclaringType.FullName.StartsWith("System.Nullable") && !Utils.Filter(methodDef.DeclaringType))
                        {
                            return false;
                        }
                        //if (cmethod.DeclaringType.HasGenericParameters)
                        //{
                        //    Console.WriteLine("ignoreMethod: " + cmethod.FullName);
                        //    return false;
                        //}
                        if (cmethod.FullName.StartsWith("System.Reflection"))
                        {
                            return false;
                        }
                        if (methodDef.IsConstructor)
                        {
                            //System以外的对象不能被直接进行构造。存在下面两种情况：
                            //如果要在mono/il2cpp之间进行传递，WObject的ctor不能直接使用。
                            //如果只在mono层内存在的对象，则不建议在wrapper层使用
                            if (!methodDef.DeclaringType.FullName.StartsWith("System"))
                            {
                                return false;
                            }
                        }
                        if (methodDef.IsInternalCall)
                        {
                            //Binder.AddMethod(cmethod);
                            calledMethods.Add(cmethod.Resolve());
                            continue;
                        }
                        if (cmethod.GenericParameters != null && cmethod.GenericParameters.Count > 0)
                        {
                            if (!IsGenericMethodWithoutGenericType(cmethod, calledMethods, refMethods))
                            {
                                return false;
                            }
                        }
                        else
                        {
                            //if (methodDef.IsGetter || methodDef.IsSetter)
                            //{
                            //    //TODO: property
                            //    return false;
                            //}
                            if (!Filter(methodDef, DllRuntime.Mono, refMethods))
                            {
                                return false;
                            }

                            if (methodDef.IsPublic)
                            {
                                //Binder.AddMethod(cmethod);
                                calledMethods.Add(cmethod.Resolve());
                            }
                            else
                            {
                                if (CheckMethodNoAffectsToSelf(methodDef, calledMethods, refMethods))
                                {
                                    //Binder.AddMethod(cmethod);
                                    calledMethods.Add(cmethod.Resolve());
                                }
                                else
                                {
                                    return false;
                                }
                            }
                        }
                    }
                    else if (il.OpCode.Code == Mono.Cecil.Cil.Code.Ldsfld || il.OpCode.Code == Mono.Cecil.Cil.Code.Stsfld) //访问泛型的static field字段，泛型类型不支持
                    {
                        var fieldRef = il.Operand as FieldReference;
                        if(fieldRef.DeclaringType is GenericInstanceType)
                        {
                            return false;
                        }
                    }
                    else if (il.OpCode.Code == Mono.Cecil.Cil.Code.Ldfld || il.OpCode.Code == Mono.Cecil.Cil.Code.Stfld
                        || il.OpCode.Code == Mono.Cecil.Cil.Code.Ldflda) //访问自身的field
                    {
                        var fieldRef = il.Operand as FieldReference;
                        if (fieldRef.DeclaringType.FullName == method.DeclaringType.FullName)
                        {
                            return false;
                        }
                    }
                    else if (il.OpCode.Code == Mono.Cecil.Cil.Code.Sizeof) //mono和il2cpp的类型字段不一样，用sizeof会有问题
                    {
                        if (il.Operand is GenericParameter)
                        {
                            return false;
                        }
                    }
                    else if (il.OpCode.Code == Mono.Cecil.Cil.Code.Initobj)
                    {
                        var initobj = il.Operand as TypeReference;
                        if (initobj.HasGenericParameters)
                        {
                            Console.WriteLine("ignoreMethod: " + initobj.FullName);
                            return false;
                        }
                    }
                    
                }
            }
            return true;
        }

        public static bool CheckMethodOnlyCallInternal(MethodDefinition method, List<MethodDefinition> calledMethods, List<MethodDefinition> refMethods = null)
        {
            if (refMethods == null)
            {
                refMethods = new List<MethodDefinition>(16);
            }
            if (method.HasBody)
            {
                for (int i = 0; i < method.Body.Instructions.Count; i++)
                {
                    var il = method.Body.Instructions[i];
                    if (il.OpCode.Code == Mono.Cecil.Cil.Code.Call || il.OpCode.Code == Mono.Cecil.Cil.Code.Callvirt)
                    {
                        var cmethod = il.Operand as MethodReference;
                        var methodDef = cmethod.Resolve();
                        if (refMethods.Contains(methodDef))
                        {
                            continue;
                        }
                        else
                        {
                            refMethods.Add(methodDef);
                        }

                        //{T}/{T[]}类型的参数可以作为函数返回值
                        if (!methodDef.ReturnType.IsGenericParameter())
                        {
                            if (!Utils.Filter(methodDef.ReturnType))
                            {
                                return false;
                            }
                        }
                        
                        if (methodDef.IsInternalCall)
                        {
                            //Binder.AddMethod(methodDef);
                            calledMethods.Add(methodDef);
                        }
                        else
                        {
                            //调用自身的pulic函数可以优化
                            if(methodDef.IsPublic && methodDef.DeclaringType == method.DeclaringType && (!methodDef.DeclaringType.IsNested || methodDef.DeclaringType.IsNestedPublic) && Utils.Filter(methodDef, DllRuntime.Mono, refMethods))
                            {
                                calledMethods.Add(methodDef);
                            }
                            else
                            {
                                if (!CheckMethodOnlyCallInternal(methodDef, calledMethods, refMethods))
                                {
                                    return false;
                                }
                                else
                                {
                                    //Binder.AddMethod(methodDef);
                                    calledMethods.Add(methodDef);
                                }
                            }
                            
                        }
                    }
                    else
                    {
                        if (il.OpCode.Code == Mono.Cecil.Cil.Code.Ldfld || il.OpCode.Code == Mono.Cecil.Cil.Code.Ldsfld
                            || il.OpCode.Code == Mono.Cecil.Cil.Code.Ldflda || il.OpCode.Code == Mono.Cecil.Cil.Code.Ldsflda
                            || il.OpCode.Code == Mono.Cecil.Cil.Code.Stfld || il.OpCode.Code == Mono.Cecil.Cil.Code.Stsfld
                            || il.OpCode.Code == Mono.Cecil.Cil.Code.Initobj || il.OpCode.Code == Mono.Cecil.Cil.Code.Newobj
                            || il.OpCode.Code == Mono.Cecil.Cil.Code.Newarr)
                        {
                            return false;
                        }
                    }
                }
            }
            return true;
        }

        /// <summary>
        /// 函数不访问自身的field，这样的函数可以安全的only in mono。
        /// </summary>
        /// <param name="method"></param>
        /// <param name="refMethods"></param>
        /// <returns></returns>
        public static bool CheckMethodNoAffectsToSelf(MethodDefinition method, List<MethodDefinition> calledMethods, List<MethodDefinition> refMethods = null)
        {
            if(refMethods == null)
            {
                refMethods = new List<MethodDefinition>(16);
            }
            if (method.HasBody)
            {
                for (int i = 0; i < method.Body.Instructions.Count; i++)
                {
                    var il = method.Body.Instructions[i];
                    if (il.OpCode.Code == Mono.Cecil.Cil.Code.Ldfld || il.OpCode.Code == Mono.Cecil.Cil.Code.Ldsfld 
                        || il.OpCode.Code == Mono.Cecil.Cil.Code.Ldflda || il.OpCode.Code == Mono.Cecil.Cil.Code.Ldsflda)
                    {
                        var field = il.Operand as FieldReference;
                        //访问自身的成员
                        if (field.DeclaringType.FullName == method.DeclaringType.FullName)
                        {
                            return false;
                        }
                    }
                    else if (il.OpCode.Code == Mono.Cecil.Cil.Code.Stfld || il.OpCode.Code == Mono.Cecil.Cil.Code.Stsfld)
                    {
                        var field = il.Operand as FieldReference;
                        //访问自身的成员
                        if (field.DeclaringType.FullName == method.DeclaringType.FullName)
                        {
                            return false;
                        }
                    }
                    else if (il.OpCode.Code == Mono.Cecil.Cil.Code.Callvirt || il.OpCode.Code == Mono.Cecil.Cil.Code.Call)
                    {
                        var cmethod = il.Operand as MethodReference;
                        var methodDef = cmethod.Resolve();
                        if (refMethods.Contains(methodDef))
                        {
                            continue;
                        }
                        else
                        {
                            refMethods.Add(methodDef);
                        }
                        if (methodDef.IsInternalCall)
                        {
                            //Binder.AddMethod(methodDef);
                            calledMethods.Add(methodDef);
                            continue;
                        }
                        
                        //访问non public函数
                        if(!methodDef.IsPublic || (methodDef.DeclaringType.IsNotPublic && (methodDef.IsPublic || methodDef.IsFamily)))
                        {
                            //if (methodDef.DeclaringType.FullName == method.DeclaringType.FullName)
                            {
                                if (!CheckMethodNoAffectsToSelf(methodDef, calledMethods, refMethods))
                                {
                                    return false;
                                }
                                return false;
                            }
                        }
                        
                        //mono侧内不能用reflection，访问到的函数或者字段可能有误
                        if (cmethod.FullName.Contains("System.Reflection"))
                        {
                            return false;
                        }

                        //interface的函数
                        //if (methodDef.DeclaringType.IsInterface)
                        //{
                        //    if (!Filter(methodDef, DllRuntime.Mono, methods))
                        //    {
                        //        return false;
                        //    }
                        //}

                        //if (!Filter(methodDef, DllRuntime.Mono) || !CheckMethodNoAffectsToSelf(methodDef))
                        //{
                        //    return false;
                        //}
                    }else if(il.OpCode.Code == Mono.Cecil.Cil.Code.Newobj)
                    {
                        var ctorMethod = (il.Operand as MethodReference).Resolve();
                        if (ctorMethod != null)
                        {
                            calledMethods.Add(ctorMethod);
                            //Binder.AddMethod(ctorMethod);
                        }

                    }
                }
            }

            return true;
        }

        public static bool IsMethodHasParamArgument(MethodDefinition method)
        {
            foreach(var p in method.Parameters)
            {
                if(p.IsOut || p.CustomAttributes.Any(x => x.AttributeType.Name == "ParamArrayAttribute"))
                {
                    return true;
                }
            }
            return false;
        }

        public static bool IsMethodImplInterface(MethodDefinition method)
        {
            foreach(var i in method.DeclaringType.Interfaces)
            {
                foreach(var m in i.InterfaceType.Resolve().Methods)
                {
                    if(m.CompareSignature(method))
                    {
                        return true;
                    }
                }
            }
            return false;
        }

        public static bool IsMethodCalledBySelf(MethodDefinition method)
        {
            var dt = method.DeclaringType;
            foreach (var m in dt.Methods)
            {
                if (m.HasBody)
                {
                    for (int i = 0; i < m.Body.Instructions.Count; i++)
                    {
                        var il = m.Body.Instructions[i];
                        if (il.OpCode.Code == Mono.Cecil.Cil.Code.Callvirt || il.OpCode.Code == Mono.Cecil.Cil.Code.Call)
                        {
                            var cmethod = il.Operand as MethodReference;
                            if (cmethod.MetadataToken.ToInt32() == method.MetadataToken.ToInt32())
                            {
                                return true;
                            }
                        }
                    }
                }
            }
            return false;
        }

        //public static bool IsMethodOnlyExeInMono(MethodDefinition method)
        //{
        //    return method.IsInternalCall || ((!method.IsPublic || (method.DeclaringType.IsNotPublic && (method.IsPublic || method.IsFamily))) && Utils.CheckMethodNoAffectsToSelf(method));
        //}

        public static MethodDefinition GetMethodByToken(TypeDefinition typeDefinition, int token)
        {
            foreach (var m in typeDefinition.Methods)
            {
                if (m.MetadataToken.ToInt32() == token)
                {
                    return m;
                }
            }
            return null;
        }

        public static bool FilterStructMethod(MethodDefinition method, List<MethodDefinition> calledMethods = null)
        {
            if(method == null)
            {
                return false;
            }
            foreach(var m in IgnoreMethodsSet)
            {
                if (method.FullName.StartsWith(m))
                {
                    return false;
                }
            }

            if (method.HasGenericParameters)
            {
                if (Utils.IsGenericMethodWithoutGenericType(method, calledMethods))
                {
                    return true;
                }
            }
            else
            {
                if (method.IsInternalCall)
                {
                    if(calledMethods != null)
                    {
                        calledMethods.Add(method);
                    }
                    return true;
                }
                else
                {
                    HashSet<MethodDefinition> calledM = new HashSet<MethodDefinition>(4);
                    if (method.HasBody)
                    {
                        for (int i = 0; i < method.Body.Instructions.Count; i++)
                        {
                            var il = method.Body.Instructions[i];
                            if (il.OpCode.Code == Mono.Cecil.Cil.Code.Call || il.OpCode.Code == Mono.Cecil.Cil.Code.Callvirt)
                            {
                                var methodDef = (il.Operand as Mono.Cecil.MethodReference).Resolve();
                                if (!methodDef.DeclaringType.FullName.StartsWith("System.Nullable") && !Utils.Filter(methodDef.DeclaringType))
                                {
                                    return false;
                                }
                                if (methodDef != null && methodDef.HasGenericParameters)
                                {
                                    if (!Utils.IsGenericMethodWithoutGenericType(methodDef, calledMethods))
                                    {
                                        return false;
                                    }
                                }
                                calledM.Add(methodDef);
                            }
                        }
                    }

                    if (/*Utils.Filter(m, DllRuntime.Mono) && */(method.IsPublic || method.IsAssembly || (method.IsPrivate && (method.IsConstructor || Utils.IsMethodCalledBySelf(method) || Utils.IsMethodImplInterface(method)))))
                    {
                        if(calledMethods != null)
                        {
                            calledMethods.AddRange(calledM);
                        }
                        return true;
                    }
                }
            }
            return false;
        }

        public static bool Filter(MethodDefinition method, DllRuntime runtime, List<MethodDefinition> checkedMethods = null)
        {
            foreach (var m in IgnoreMethodsSet)
            {
                if (method.FullName.StartsWith(m))
                {
                    return false;
                }
            }
            if (checkedMethods == null)
            {
                checkedMethods = new List<MethodDefinition>(16);
            }
            if (!Filter(method.DeclaringType))
            {
                return false;
            }

            if (runtime == DllRuntime.IL2Cpp) 
            {
                if (method.DeclaringType.IsNotPublic)
                {
                    return false;
                }
            }else if(runtime == DllRuntime.Mono)
            {
                if (!(method.IsInternalCall || method.DeclaringType.IsPublic || method.DeclaringType.IsNestedPublic || (method.DeclaringType.IsNotPublic && (method.IsFamily || method.IsPublic))))
                {
                    return false;
                }
            }

            //generic parameter vs generic instance
            if (!method.ReturnType.IsGenericParameter)
            {
                if (!Filter(method.ReturnType))
                {
                    return false;
                }
            }

            if (IsObsolete(method))
                return false;

            if (method.GenericParameters != null && method.GenericParameters.Count > 0)
            {
                if(runtime == DllRuntime.Mono)
                {
                    var calledMethods = new List<MethodDefinition>();
                    if (!IsGenericMethodWithoutGenericType(method, calledMethods, checkedMethods))
                    {
                        return false;
                    }
                    else
                    {
                        foreach(var m in calledMethods)
                        {
                            Binder.AddMethod(m);
                        }
                    }
                }
                else //il2cpp侧不支持泛型函数
                {
                    return false;
                }
            }

            foreach (var p in method.Parameters)
            {
                //TODO: params关键字修饰的参数不支持(只在mono侧的可以)
                if ((method.IsConstructor || runtime == DllRuntime.IL2Cpp) && p.CustomAttributes.Any(x => x.AttributeType.Name == "ParamArrayAttribute"))
                {
                    return false;
                }
                if (p.ParameterType.IsByReference && !p.ParameterType.GetElementType().IsValueType)
                {
                    return false;
                }
                if (p.ParameterType.IsPointer && method.IsConstructor && method.DeclaringType.IsStruct())
                {
                    return false;
                }
                if (method.IsConstructor && p.ParameterType.Resolve().IsDelegate()) //ctor不支持带delegate的参数
                {
                    return false;
                }

                if (p.IsOut)
                {
                    var refType = p.ParameterType.Resolve();
                    if (runtime == DllRuntime.Mono && (refType.IsValueType || refType.IsSubclassOf("UnityEngine.Object") || (refType.IsArray && (p.ParameterType as Mono.Cecil.ArrayType).ElementType.Resolve().IsSubclassOf("UnityEngine.Object"))))
                    {

                    }
                    else
                    {
                        return false;
                    }
                }
                if (!p.ParameterType.IsGenericParameter)
                {
                    if (!Filter(p.ParameterType))
                    {
                        return false;
                    }
                }
                
            }

            if (method.ReturnType.FullName == "System.Threading.Tasks.Task") // async
            {
                return false;
            }

            return true;
        }

        public static bool Filter(EventDefinition genEvent)
        {
            if (!Filter(genEvent.EventType))
                return false;
            var gType = genEvent.EventType as GenericInstanceType;

            if (genEvent.AddMethod != null && !genEvent.AddMethod.IsPublic)
                return false;

            if (IsObsolete(genEvent))
                return false;

            if(gType != null)
            {
                foreach (var p in gType.GenericArguments)
                {
                    if (p.IsGenericInstance || !Filter(p))
                        return false;
                }
            }
            return true;
        }

        public static bool IsObsolete(ICustomAttributeProvider method)
        {
            foreach (var attr in method.CustomAttributes)
            {
                if (attr.AttributeType.Name.Equals("ObsoleteAttribute"))
                {
                    if(attr.ConstructorArguments.Count == 2)
                    {
                        bool error = (bool)attr.ConstructorArguments[1].Value ;
                        return error;
                    }
                }
            }

            return false;
        }

        private static HashSet<TypeReference> DropTypes = new HashSet<TypeReference>();
        public static bool Filter(TypeReference type)
        {
            if (DropTypes.Contains(type))
            {
                return false;
            }
                

            if (Binder.retainTypes.Contains(type.FullName))
            {
                return true;
            }

            //mono的stream对象和il2cpp的stream对象不兼容
            if (type.FullName.StartsWith("System.IO.Stream"))
            {
                return false;
            }

            foreach (var t in IgnoreTypeSet)
            {
                if (type.FullName.Contains(t))
                {
                    Log("ignorType: " + type.FullName);
                    DropTypes.Add(type);
                    return false;
                }
            }

            if(IsDelegate(type))
            {
                var tList = GetDelegateParams(type, null, out var rType);
                tList.Add(rType);
                foreach(var t in tList)
                {
                    if(t != null && !Utils.Filter(t))
                    {
                        Log("ignorType: " + type.FullName);
                        DropTypes.Add(type);
                        return false;
                    }
                }
            }

            if (type.IsGeneric() && !(IsDelegate(type))) // 
            {
                
                var typeDef = type.Resolve();
                if (typeDef != null && typeDef.IsInterface) //nullable作为特殊的泛型可以支持
                {
                    var a = 1;
                }
                else
                {
                    //if (type.IsGenericParameter)
                    //{
                    //    var b = 1;
                    //}else
                    {
                        Log("ignorType: " + type.FullName);
                        DropTypes.Add(type);
                        return false;
                    }
                    
                }
                
            }

            if (IsException(type))
            {
                if(type.FullName != "System.Exception")
                {
                    var exType = type.Resolve();
                    foreach (var f in exType.Fields)
                    {
                        var ft = f.FieldType.Resolve();
                        if (!(ft.IsPrimitive || ft.FullName == "System.String" || ft.IsEnum))
                        {
                            Log("ignorType: " + type.FullName);
                            DropTypes.Add(type);
                            return false;
                        }
                    }
                }
            }

            var td = type.Resolve();
            if (type.IsArray)
            {
                var arrayType = type as Mono.Cecil.ArrayType;
                var eleType = arrayType.ElementType; 
                if(IsDelegate(eleType) || eleType.IsArray || !Utils.Filter(eleType) || arrayType.Rank != 1)
                {
                    Log("ignorType: " + type.FullName);
                    DropTypes.Add(type);
                    return false;
                }
            }

            //if (IsAttribute(type))
            //{
            //    var atype = type.Resolve();
            //    foreach (var f in atype.Fields)
            //    {
            //        var ft = f.FieldType.Resolve();
            //        if (!(ft.IsPrimitive || ft.FullName == "System.String" || ft.IsEnum))
            //        {
            //            Log("ignorType: " + type.FullName);
            //            DropTypes.Add(type);
            //            return false;
            //        }
            //    }
            //}

            if (td != null && (IsObsolete(td)))// || td.IsInterface))
            {
                Log("ignorType: " + type.FullName);
                DropTypes.Add(type);
                return false;
            }

            //if(td != null && td.IsInterface)
            //{
            //    foreach(var f in td.Fields)
            //    {
            //        if(f.FieldType.Resolve() != td && !Utils.Filter(f.FieldType))
            //        {
            //            DropTypes.Add(type);
            //            return false;
            //        }
            //    }

            //    foreach (var f in td.Properties)
            //    {
            //        if (f.PropertyType.Resolve() != td && !Utils.Filter(f.PropertyType))
            //        {
            //            DropTypes.Add(type);
            //            return false;
            //        }
            //    }

            //    foreach (var f in td.Methods)
            //    {
            //        foreach(var p in f.Parameters)
            //        {
            //            if(p.ParameterType.Resolve() != td && !Utils.Filter(p.ParameterType))
            //            {
            //                DropTypes.Add(type);
            //                return false;
            //            }
            //        }
            //        if (f.ReturnType.Resolve() != td && !Utils.Filter(f.ReturnType))
            //        {
            //            DropTypes.Add(type);
            //            return false;
            //        }
            //    }
            //}

            if (td != null && td.IsStruct())
            {
                if(!IsFullValueType(td))
                {
                    Log("ignorType: " + type.FullName);
                    DropTypes.Add(type);
                    return false;
                }
                foreach (var f in td.Fields)
                {
                    if (!f.IsStatic && !Utils.Filter(f.FieldType))
                    {
                        Log("ignorType: " + type.FullName);
                        DropTypes.Add(type);
                        return false;
                    }
                }
            }


            var ct = type.BaseType();
            while (ct != null)
            {
                //exception不用检查
                if (ct != null && ct.FullName == "System.Exception")
                {
                    break;
                }
                if (!Filter(ct))
                {
                    Log($"ignorType: {type.FullName} base {ct.FullName}");
                    DropTypes.Add(type);
                    return false;
                }

                ct = ct.BaseType();
            }

            return true;
        }

        public static bool Filter(ITypeDefinition type)
        {
            var tName = type.FullTypeName.ReflectionName.Replace("+", "/");
            TypeReference tref = Binder.curModule.GetType(tName);
            if (tref == null)
                Binder.curModule.TryGetTypeReference(tName, out tref);
            if(tref != null)
            {
                return Filter(tref);
            }

            return true;
        }

        public static bool IsAttribute(TypeReference type)
        {
            var td = type.Resolve();
            if (td == null)
                return false;
            if (type.Name == "Attribute")
                return true;

            if (td.BaseType != null && IsAttribute(td.BaseType))
                return true;

            return false;
            
        }

        public static bool IsException(TypeReference type)
        {
            var td = type.Resolve();
            if (td == null)
                return false;
            if (type.Name == "Exception")
                return true;

            if (td.BaseType != null && IsException(td.BaseType))
                return true;

            return false;

        }

        // [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
        // public delegate int UnityEngineGameObjectMethodCreatePrimitiveUnityEnginePrimitiveTypeDelegateType(int typeint);
        static void AppendDelegateType(MethodDefinition method, CodeWriter writer)
        {
            writer.Write("[UnmanagedFunctionPointer(CallingConvention.Cdecl)]\n");
            writer.Write($"delegate ");

            // Return type
           /* if (IsFullValueType(method.ReturnType.Resolve()))
            {
                AppendCsharpTypeFullName(
                    returnType,
                    output);
            }
            else
            {
                output.Append("int");
            }*/
        }

        enum TypeKind
        {
            // No type (e.g. a global function)
            None,

            // An instance of any class
            Class,

            // A struct that must be managed. This includes types like
            // RaycastHit which have class fields (Transform) and types with no
            // C++ equivalent like decimal.
            ManagedStruct,

            // A struct that can be copied between C#/C++. These are types like
            // Vector3 with only non-class fields and a C++ equivalent can be
            // generated.
            FullStruct,

            // Any enum
            Enum,

            // Any primitive (e.g. int) except pointers
            Primitive,

            // A pointer to any type, either X*, IntPtr, or UIntPtr
            Pointer
        }

        static TypeKind GetTypeKind(TypeDefinition type)
        {
            /*if (type == typeof(void))
            {
                return TypeKind.None;
            }*/

            if (type.IsPointer)
            {
                return TypeKind.Pointer;
            }

            if (type.IsEnum)
            {
                return TypeKind.Enum;
            }

            if (type.IsPrimitive)
            {
                return TypeKind.Primitive;
            }

            if (!type.IsValueType)
            {
                return TypeKind.Class;
            }

            // Decimal (currently) can't be represented on the C++ side, so
            // don't count it as a full struct
            if ( IsFullValueType(type))
            {
                return TypeKind.FullStruct;
            }

            return TypeKind.ManagedStruct;
        }

        

        public static bool IsDelegate(TypeReference type)
        {

            TypeReference curType = type;
            while(curType != null)
            {
                if (curType.FullName.Equals("System.Delegate") || curType.FullName.Equals("System.MulticastDelegate"))
                    return true;

                var tDef = curType.Resolve();
                if (tDef != null)
                    curType = tDef.BaseType;
                else
                    return false;
            }

            return false;
        }

        public static string GetGenericTypeName(TypeReference type, bool boxedType = false)
        {
            var gType = type as GenericInstanceType;
            if (!type.Name.Contains("`") || gType == null)
                return type.Name;

            var typeName = TypeResolver.Resolve(type).RealTypeName();
            var baseType = typeName.Substring(0, typeName.IndexOf('<'));

            var param = "<";

            for(int i = 0;i< gType.GenericArguments.Count;i++)
            {
                var p = gType.GenericArguments[i];

                var pName = boxedType ? TypeResolver.Resolve(p).TypeName() : TypeResolver.Resolve(p).RealTypeName();
                if (p.IsGenericInstance)
                    pName = Utils.GetGenericTypeName(p, boxedType);

                param += pName + (i == gType.GenericArguments.Count -1 ? "" : ", ");
            }
            param += ">";
            return baseType + param;
        }

        public static TypeReference GetGenericParamTyep(GenericParameter paramType, GenericInstanceType instanceType)
        {
            if (paramType == null || instanceType == null)
                return null;

            var postion = paramType.Position;
            if (postion >= 0 && postion < instanceType.GenericArguments.Count)
                return instanceType.GenericArguments[postion];
            return null;
        }

        /// <summary>
        /// GetDelegateParams
        /// </summary>
        /// <param name="type">delegate type</param>
        /// <param name="delegateTarget">static:null    else:delegate.Target</param>
        /// <param name="returnType">void:null    else:return type</param>
        /// <returns></returns>
        public static List<TypeReference> GetDelegateParams(TypeReference type, TypeReference delegateTarget, out TypeReference returnType)
        {
            List<TypeReference> types = new List<TypeReference>();

            if (delegateTarget != null)
                types.Add(delegateTarget);

            var invokMethod = type.Resolve().Methods.Where(m => m.Name == "Invoke").FirstOrDefault();
            if (type.IsGenericInstance)
            {
                var gType = type as GenericInstanceType;
                invokMethod = gType.Resolve().Methods.Where(m => m.Name == "Invoke").FirstOrDefault();
                //types.AddRange(gType.GenericArguments);
                //returnType = null;

                //if (type.Name.StartsWith("Func"))
                //{
                //    returnType = types.Last();
                //    types.Remove(returnType);
                //}
                //return types;
            }

            if(invokMethod != null)
            {
                foreach (var p in invokMethod.Parameters)
                {
                    if (p.ParameterType.IsGenericParameter)
                        types.Add(GetGenericParamTyep(p.ParameterType as GenericParameter, type as GenericInstanceType));
                    else
                        types.Add(p.ParameterType);
                }

                if (invokMethod.ReturnType.IsVoid())
                    returnType = null;
                else
                    returnType = invokMethod.ReturnType;
            }
            else
            {
                returnType = null;
            }
            
            return types;
        }

        static Dictionary<string, string> delegateSignDic = new Dictionary<string, string>();

        public static string GetDelegateWrapTypeName(TypeReference type, TypeReference delegateTarget, bool forMarshal = false)
        {
            var paramTpes = Utils.GetDelegateParams(type, delegateTarget, out var returnType);

            var paramDeclear = "(";
            for (int i = 0; i < paramTpes.Count; i++)
            {
                var p = paramTpes[i];
                paramDeclear += $"{TypeResolver.Resolve(p, null, MemberTypeSlot.Parameter).TypeName(forMarshal)} arg{i} "; //TODO: TypeResolver.Resolve(p).Paramer($"arg{i}");
                if (i != paramTpes.Count - 1)
                    paramDeclear += ",";
            }
            paramDeclear += ")";

            var retTypeResolver = returnType != null ? TypeResolver.Resolve(returnType, null, MemberTypeSlot.ReturnType, MethodTypeSlot.GeneratedMethod) : null;
            //il2cpp内的定义仍然保持原样，因为在生成cpp文件时，非blittable都以指针形式存在
            var returnName = returnType == null ? "void" : retTypeResolver.TypeName(forMarshal);
            //mono内的delegate，如果返回值是非blittable类型，必须要定义为IntPtr，避免Marshal将返回值释放掉，返回空指针。
            //var returnNameWrap = returnType == null ? "void" : retTypeResolver.TypeName(true); 
            var sign = type.FullName + paramDeclear + returnName + (forMarshal ? "_forMarshal" : "");
            var delegateName = "";
            if(!delegateSignDic.TryGetValue(sign,out delegateName))
            {
                delegateName = "Delegate" + sign.GetHashCode().ToString("x");
                delegateSignDic[sign] = delegateName;
            }
            
            var define = $"public delegate {returnName} {delegateName} {paramDeclear}";
            //var wrapDefine = $"public delegate {returnNameWrap} {delegateName} {paramDeclear}";

            GenerateBindings.AddDelegateDefine(define, define);

            return delegateName;
        }

        
        public static HashSet<string> GetNameSpaceList(HashSet<MethodDefinition> methods)
        {
            HashSet<string> nsSet = new HashSet<string>();
            foreach(var method in methods)
            {
                nsSet.UnionWith(GetNameSpaceRef(method));
            }
            return nsSet;
        }

        public static HashSet<string> GetNameSpaceRef(MethodDefinition method)
        {
            HashSet<string> set = new HashSet<string>();
            if(method.DeclaringType != null)
                set.Add(method.DeclaringType.Namespace);

            if (method.ReturnType != null)
                set.Add(method.ReturnType.Namespace);

            foreach (var p in method.Parameters)
            {
                set.Add(p.ParameterType.Namespace);
            }

            foreach(var attr in method.CustomAttributes)
            {
                var ns = attr.AttributeType.Namespace;
                if (ns.StartsWith("System"))
                    set.Add(ns);
            }

            set.Remove("");
            return set;
        }

        public static bool IsManagedValueType(TypeReference _type)
        {
            return _type.IsValueType && !IsFullValueType(_type);
        }

        public static bool IsFullValueType(IType _type)
        {
            var tn = _type.GetDefinition().FullTypeName.ReflectionName.Replace("+", "/");

            var td = Binder.curModule.GetType(tn);
            if (td != null)
                return IsFullValueType(td);
            else if (Binder.curModule.TryGetTypeReference(tn, out var tref))
                return IsFullValueType(tref);

            return false;
        }

        public static bool IsFullValueType(TypeReference _type)
        {
            if (_type.IsPointer)
                _type = _type.GetElementType();
            var type = _type.Resolve();
            
            if (type == null)
                return false;

            if (_type.IsPrimitive || type.IsEnum || _type.IsVoid())
            {
                return true;
            }

            if (!_type.IsValueType)
            {
                return false;
            }

            foreach (var field in type.Fields)
            {
                if (!field.IsStatic && !IsFullValueType(field.FieldType))
                {
                    return false;
                }
            }

            return true;
        }


        public static bool IsBlittableType(TypeReference _type)
        {
            if (_type.IsPointer)
                _type = _type.GetElementType();
            var type = _type.Resolve();

            if (type == null)
                return false;

            if (!_type.IsArray && (_type.IsPrimitive || type.IsEnum))
            {
                return true;
            }
            return false;
        }

        public static bool IsUnsafeMethod(MethodDefinition method)
        {
            if (method.ReturnType.IsPointer)
                return true;
            foreach (var p in method.Parameters)
            {
                if (p.ParameterType.IsPointer)
                    return true;
            }

            return false;
        }

        private static FieldDefinition GetFirstParam(TypeDefinition type)
        {
            foreach (var p in type.Fields)
            {
                if (!p.IsStatic)
                    return p;
            }
            return null;
        }

        
        public static bool HaveHeadPtr(TypeReference _type)
        {
            if (_type.IsArray || _type.IsByReference || _type.IsPointer)
                return HaveHeadPtr(_type.GetElementType());

            if (_type.Name.StartsWith("List`") || _type.Name.StartsWith("Action`"))
            {
                var gType = _type as GenericInstanceType;
                foreach (var p in gType.GenericArguments)
                {
                    if (!HaveHeadPtr(p))
                        return false;
                }
                return true;
            }

            if (_type.IsValueType || _type.Name == "String" || _type.Name == "Void")
                return true;


            var type = _type.Resolve();

            FieldDefinition firstParam = GetFirstParam(type);

            while (type.BaseType != null)
            {
                var p = GetFirstParam(type.BaseType.Resolve());
                if (p != null)
                    firstParam = p;

                type = type.BaseType.Resolve();
            }

            return firstParam != null && firstParam.FieldType.Name == "IntPtr";
        }

        public static HashSet<string> IcallSupportClass = new HashSet<string>();
        private static bool SupportIcallBind(TypeReference _type)
        {
            if (_type.Namespace.StartsWith("UnityEngine"))
            {
                if (IcallSupportClass.Contains(_type.Name))
                    return true;
                var ct = _type.BaseType();
                while (ct != null)
                {
                    if (SupportIcallBind(ct))
                        return true;

                    ct = ct.BaseType();
                }
            }
            return false;

        }
        public static bool IsUnityICallBind(TypeReference _type)
        {
            if(_type.Namespace.StartsWith("UnityEngine"))
            {
                if (SupportIcallBind(_type))
                    return true;

                //if (HaveHeadPtr(_type))
                //    return true;
            }

            return false;
        }

        public static bool IsVisibleToOthers(MethodDefinition method)
        {
            return method.IsPublic;// || (method.IsInternalCall || method.CustomAttributes.Any(x => x.AttributeType.Name == "VisibleToOtherModulesAttribute"));
        }


        public static bool IsInternalCallVisibleToOthers(MethodDefinition method)
        {
            return method.IsInternalCall && ((method.CustomAttributes.Any(x => x.AttributeType.Name == "VisibleToOtherModulesAttribute")) || CSharpForceRetainMethods.Any(x=>method.FullName.StartsWith(x)));// || method.IsAssembly);
        }


        public static bool IsFieldSerializable(FieldDefinition field)
        {
            if(field.IsPublic || field.CustomAttributes.Any(x=>x.AttributeType.Name == "SerializeFieldAttribute"))
            {
                if(field.HasConstant || field.IsStatic || field.IsInitOnly)
                {
                    return false;
                }

                var dt = field.FieldType;
                if(dt.IsArray)
                {
                    var arrayType = dt as Mono.Cecil.ArrayType;
                    var eleType = arrayType.ElementType;
                    if(IsTypeSerializable(eleType))
                    {
                        return true;
                    }
                    return false;
                }
                else
                {
                    return IsTypeSerializable(dt);
                }
            }

            return false;
        }

        public static bool IsTypeSerializable(TypeReference type)
        {
            var td = type.Resolve();
            if (!td.IsValueType)
            {
                if (td.IsSubclassOf("UnityEngine.Object"))
                {
                    return true;
                }
                else
                {
                    //non-static class which has SerializableAttribute
                    if (!(td.IsSealed && td.IsAbstract) && td.CustomAttributes.Any(x => x.AttributeType.Name == "SerializableAttribute"))
                    {
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
            else if (td.IsStruct(false))
            {
                //Unity doest not support custom struct for serialization, use class with SerializableAttribute
                if (td.Name.StartsWith("UnityEngine."))
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                if (td.IsString() || td.IsEnum || IsBlittableType(td))
                {
                    return true;
                }
                return false;
            }
        }

        public static bool IsClassSerializable(TypeReference type)
        {
            var td = type.Resolve();
            if(!td.IsClass)
            {
                return false;
            }    
            if (td.IsSubclassOf("UnityEngine.Object"))
            {
                return true;
            }
            if (!(td.IsSealed && td.IsAbstract) && td.CustomAttributes.Any(x => x.AttributeType.Name == "SerializableAttribute"))
            {
                return true;
            }
            return true;
        }


        public static int RunCMD(string cmd, string[] args, string workdir = null)
        {
            var argument = string.Join("\" \"", args);
            Console.WriteLine($"RunCMD: {cmd} {argument}");
            Process p = new Process();
            p.StartInfo.FileName = cmd;
            p.StartInfo.Arguments = argument;
            p.StartInfo.WindowStyle = System.Diagnostics.ProcessWindowStyle.Hidden;
            p.StartInfo.RedirectStandardOutput = true;
            p.StartInfo.UseShellExecute = false;
            p.StartInfo.CreateNoWindow = true;
            if (workdir != null)
                p.StartInfo.WorkingDirectory = workdir;
            else
                p.StartInfo.WorkingDirectory = Directory.GetCurrentDirectory();
            p.Start();

            while (!p.StandardOutput.EndOfStream)
            {
                string line = p.StandardOutput.ReadLine();
                Console.WriteLine(line);
            }
            p.WaitForExit();

            return p.ExitCode;
        }

        public static bool IsWin32()
        {
            OperatingSystem os = Environment.OSVersion;
            return os.Platform.ToString().StartsWith("Win");
        }

        public static void CollectMonoAssembly(string entry, string dir, HashSet<string> adapterSet,HashSet<string> outSet)
        {
            if (outSet.Contains(entry))
                return;

            var file = Path.Combine(dir, entry);
            if (!File.Exists(file))
                return;

            outSet.Add(entry);
            var assembly = AssemblyDefinition.ReadAssembly(file);
            var refs = assembly.MainModule.AssemblyReferences;
            foreach(var aref in refs)
            {
                var refName = aref.Name;
                if (!refName.EndsWith(".dll"))
                    refName += ".dll";

                //TODO:为啥Adapter的引用不计算在内，实际上entry.dll会依赖于adapter.dll
                //if (adapterSet.Contains(refName))
                //    continue;

                CollectMonoAssembly(refName, dir, adapterSet, outSet);
            }
        }


        //public static Dictionary<int, AstNode> TokenMap;
        public static string GetMemberDelcear(IMemberDefinition member, Dictionary<int, AstNode> tokenMap = null, HashSet<string> stripInterface = null)
        {
            var method = member as MethodDefinition;
            if(method != null)
            {
                if (method.IsConstructor && method.Parameters.Count == 0)
                {
                    return $"public {method.DeclaringType.Name}()";
                }
            }

            var token = member.MetadataToken.ToInt32();
            StringWriter writer = new StringWriter();
            var output = new MemberDeclearVisitor(false, writer, Binder.DecompilerSetting.CSharpFormattingOptions);
            if (stripInterface != null)
            {
                output.stripInterfaceSet = stripInterface;
            }
            if (tokenMap != null && tokenMap.TryGetValue(token, out var map))
            {
                map.AcceptVisitor(output);
            }else
            {
                Log("Key Not Found: " + member.ToString());
            }
            //TokenMap[token].AcceptVisitor(output);
            return writer.ToString();
        }

        public static void CopyDir(string src,string tar,string postfix)
        {
            if (!Directory.Exists(tar))
                Directory.CreateDirectory(tar);

            foreach (string fi in Directory.GetFiles(src))
            {
                if(fi.EndsWith(postfix))
                {
                    string fname = Path.GetFileName(fi);
                    string targetfname = Path.Combine(tar, fname);
                    File.Copy(fi, targetfname, true);
                }
            }
        }

    }

    public class NameCounter
    {
        Dictionary<string, int> nameDic = new Dictionary<string, int>();
        public string UniqueName(string name)
        {
            if (nameDic.TryGetValue(name, out var count))
            {
                count++;
                nameDic[name] = count;
                name += "_" + count;
            }
            else
            {
                nameDic[name] = 0;
            }

            return name;
        }
    }
}
