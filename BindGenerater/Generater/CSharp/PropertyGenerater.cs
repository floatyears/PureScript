using Mono.Cecil;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace Generater
{
    public class PropertyGenerater : CodeGenerater
    {
        PropertyDefinition genProperty;
        FieldDefinition genField;
 
        bool isStatic;
        bool isAbstract;
        bool isOverride;
        bool isVirtual;
        bool isConst;

        List<MethodGenerater> methods = new List<MethodGenerater>();

        public PropertyGenerater(PropertyDefinition property)
        {
            genProperty = property;
            if (genProperty.GetMethod != null && genProperty.GetMethod.IsPublic )
            {
                isStatic = genProperty.GetMethod.IsStatic;
                isAbstract = genProperty.GetMethod.IsAbstract;
                isOverride = genProperty.GetMethod.IsOverride();
                isVirtual = genProperty.GetMethod.IsVirtual && !genProperty.DeclaringType.IsValueType;
                methods.Add(new MethodGenerater(genProperty.GetMethod));
            }
            if (genProperty.SetMethod != null && genProperty.SetMethod.IsPublic )
            {
                isStatic = genProperty.SetMethod.IsStatic;
                isAbstract = genProperty.SetMethod.IsAbstract;
                isOverride = genProperty.SetMethod.IsOverride();
                isVirtual = genProperty.SetMethod.IsVirtual && !genProperty.DeclaringType.IsValueType;
                methods.Add(new MethodGenerater(genProperty.SetMethod));
            }

        }

        public PropertyGenerater(FieldDefinition field)
        {//TODO: PropertyGenerater(FieldDefinition field)
            genField = field;
            if(!Utils.Filter(genField.FieldType) || Utils.IsDelegate(genField.DeclaringType)) //delegate是作为函数指针传递，mono只能传递static的delegate到unmanaged code
                return;

            var genName = field.Name;
            var genType = field.FieldType;
            isConst = genField.HasConstant;
            if(!genField.HasConstant)
            {
                if (!genField.IsInitOnly)
                {
                    //TODO:这里构造一个setter 和 getter，field的状态还是在il2cpp层持有
                    var corlib = CSCGenerater.corlib;// AssemblyDefinition.ReadAssembly(Path.Combine(Path.GetDirectoryName(genField.FieldType.Module.FileName), "mscorlib.dll"));

                    var setMethod = new MethodDefinition("set_" + genName, MethodAttributes.Public, corlib.MainModule.GetType("System", "Void"));
                    setMethod.DeclaringType = field.DeclaringType;
                    setMethod.Body = new Mono.Cecil.Cil.MethodBody(setMethod);
                    setMethod.IsSetter = true;
                    setMethod.IsPublic = genField.IsPublic;
                    setMethod.IsStatic = genField.IsStatic;
                    setMethod.Attributes |= MethodAttributes.CompilerControlled;
                    var parameters = setMethod.Parameters;
                    parameters.Add(new ParameterDefinition("value", ParameterAttributes.None, genType));
                    methods.Add(new MethodGenerater(setMethod));
                }


                var getMethod = new MethodDefinition("get_" + genName, MethodAttributes.Public, genType);
                getMethod.DeclaringType = field.DeclaringType;
                getMethod.Body = new Mono.Cecil.Cil.MethodBody(getMethod);
                getMethod.IsGetter = true;
                getMethod.IsPublic = genField.IsPublic;
                getMethod.IsStatic = genField.IsStatic;
                getMethod.Attributes |= MethodAttributes.CompilerControlled;
                var parameters1 = getMethod.Parameters;
                methods.Add(new MethodGenerater(getMethod));
            }    

            isStatic = genField.IsStatic;
            isAbstract = false;
            isOverride = false;
            isVirtual = !field.DeclaringType.IsValueType;
        }



        public override void Gen()
        {
            base.Gen();
            if (!isConst && methods.Count < 1)
                return;

            if (genProperty != null)
                GenProperty();

            if(genField != null)
                GenField();

        }

        void GenProperty()
        {

            var declear = Utils.GetMemberDelcear(genProperty);

            //TODO:mono cecil库貌似无法获取到property的extern属性，所以假定internal call肯定是extern
            if((genProperty.GetMethod != null && genProperty.GetMethod.ImplAttributes == MethodImplAttributes.InternalCall) 
                || (genProperty.SetMethod != null && genProperty.SetMethod.ImplAttributes == MethodImplAttributes.InternalCall))
            {
                declear = declear.Replace("public", "public extern");
            }
            CS.Writer.Start(declear);

            foreach (var m in methods)
                m.Gen();

            CS.Writer.End();
        }

        void GenField()
        {
            var declear = Utils.GetMemberDelcear(genField);
            if (isConst)
            {
                CS.Writer.Write(declear);
                return;
            }

            //HACK: field需要转换为property的形式
            declear = declear.Replace("\r", "").Replace("\n", "").Replace(";", "")
                .Replace("[NonSerialized]", "").Replace("[Serializable]", "")
                .Replace("const", "static").Replace("readonly", "");
            if (declear.IndexOf("=") > 0)
            {
                declear = declear.Substring(0, declear.IndexOf("="));
            }
            CS.Writer.Start(declear);

            foreach (var m in methods)
                m.Gen();

            CS.Writer.End();
        }

    }
}