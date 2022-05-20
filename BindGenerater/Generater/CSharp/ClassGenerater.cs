using Mono.Cecil;
using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Linq;

using ICSharpCode.Decompiler;
using ICSharpCode.Decompiler.CSharp;
using ICSharpCode.Decompiler.TypeSystem;
using ICSharpCode.Decompiler.CSharp.Syntax;

namespace Generater
{
    public class ClassGenerater : CodeGenerater
    {
        private TypeDefinition genType;

        private List<PropertyGenerater> properties = new List<PropertyGenerater>();
        private List<DelegateGenerater> events = new List<DelegateGenerater>();
        private List<MethodGenerater> methods = new List<MethodGenerater>();
        private Dictionary<TypeDefinition, ClassGenerater> nestType = new Dictionary<TypeDefinition, ClassGenerater>();
        private bool hasDefaultConstructor = false;
        private bool isCopyOrignNodes;
        private bool isCopyFullOrignalNodes;
        private StreamWriter FileStream;

        public HashSet<string> RefNameSpace = new HashSet<string>();
        

        Dictionary<int, AstNode> retainDic = new Dictionary<int, AstNode>();
        public TokenMapVisitor nodesCollector;

        public Dictionary<int, AstNode> TokenMap {  get { return nodesCollector.TokenMap; } }
        public Dictionary<int, AstNode> RetainDic {  get { return retainDic; } }
        public TypeDefinition GenType { get { return genType; } }

        private ClassGenerater parent = null;
        private CSCGenerater compiler = null;

        private CS curWriter = null;

        public ClassGenerater(TypeDefinition type, CSCGenerater compiler)
        {
            this.compiler = compiler;
            genType = type;
            //Init();
        }

        public ClassGenerater(TypeDefinition type, ClassGenerater parent = null)
        {
            this.parent = parent;
            genType = type;
            Init();
        }

        public void Init() 
        { 
            RefNameSpace.Add("System");
            RefNameSpace.Add("PureScript.Mono");
            RefNameSpace.Add("System.Runtime.CompilerServices");
            RefNameSpace.Add("System.Runtime.InteropServices");
            RefNameSpace.Add($"Binder.mono.{genType.Module.Name}".Replace(".dll", "").Replace(".", "_"));

            if (parent == null)
            {
                var dir = Path.Combine(Binder.OutDir, "Mono_" + genType.Module.Assembly.Name.Name);
                if (!Directory.Exists(dir))
                {
                    Directory.CreateDirectory(dir);
                }
                var filePath = Path.Combine(dir, $"Gen.{TypeFullName()}.cs");
                compiler.AddSource(filePath);
                FileStream = File.CreateText(filePath);
            }
            else
            {
                FileStream = parent.FileStream;
            }

            isCopyOrignNodes = CheckCopyOrignNodes(genType);
            GetCopyPartOrignNodes();
            if (isCopyFullOrignalNodes)
            {
                return;
            }

            if (genType.BaseType != null)
            {
                RefNameSpace.Add(genType.BaseType.Namespace);
            }

            foreach (var t in genType.NestedTypes)
            {
                if (t.Name.StartsWith("<") || !Utils.Filter(t))
                    continue;
                if ((t.IsPublic || t.IsNestedPublic) && !Utils.IsObsolete(t))
                {
                    var nestGen = new ClassGenerater(t, this);
                    nestType[t] = nestGen;
                    RefNameSpace.UnionWith(nestGen.RefNameSpace);
                }
            }

            if (!isCopyOrignNodes)
            {
                foreach (FieldDefinition field in genType.Fields)
                {
                    // if (isFullValueType && !field.IsStatic)
                    //    continue;
                    if (Utils.Filter(field))
                    {
                        if(field.FieldType.Resolve().IsDelegate())
                        {
                            if (Utils.Filter(field.FieldType))
                            {
                                events.Add(new DelegateGenerater(field, this));
                                RefNameSpace.Add(field.FieldType.Namespace);
                            }
                        }else
                        {
                            properties.Add(new PropertyGenerater(field, this));
                            RefNameSpace.Add(field.FieldType.Namespace);
                        }
                        
                    }

                }
            }

            foreach(var e in genType.Events)
            {
                if(Utils.Filter(e))
                {
                    events.Add(new DelegateGenerater(e, this));
                    RefNameSpace.Add(e.EventType.Namespace);
                }
            }

            foreach (PropertyDefinition prop in genType.Properties)
            {
                if (Utils.Filter(prop) && !IsCopyOrignNode(prop))
                {
                    var pt = prop.PropertyType.Resolve();
                    if (pt.IsDelegate())
                    {
                        events.Add(new DelegateGenerater(prop, this));
                    }
                    else
                    {
                        if (!HasProperty(prop))
                        {
                            properties.Add(new PropertyGenerater(prop, this));
                            RefNameSpace.Add(prop.PropertyType.Namespace);
                        }
                    }
                }
            }

            if(!genType.IsDelegate())
            {
                foreach (MethodDefinition method in genType.Methods)
                {
                    if (method.IsConstructor && method.Parameters.Count == 0) //防止base type的ctor被声明为private，子类无法定义默认的ctor
                    {
                        if (method.IsPublic)
                        {
                            hasDefaultConstructor = true;
                        }
                    }
                        

                    if (IsCopyOrignNode(method))
                    {
                        continue;
                    }
                    CheckInterface(method);
                    if ((Utils.IsVisibleToOthers(method) || Utils.IsInternalCallVisibleToOthers(method)) && !method.IsGetter && !method.IsSetter && !method.IsAddOn && !method.IsRemoveOn && !HasMethod(method))
                    {
                        var methodGener = new MethodGenerater(method, this, false, methods);
                        //methods.Add(methodGener);
                        RefNameSpace.UnionWith(Utils.GetNameSpaceRef(method));
                    }
                }
            }
        }

        public void AddMethodCalledByOthers(MethodReference method)
        {
            var methodDef = method as MethodDefinition;
            if (methodDef != null)
            {
                //默认会构造一个ctor，不用特殊引用
                if(methodDef.IsConstructor && methodDef.Parameters.Count == 0)
                {
                    return;
                }
                if(methodDef.IsGetter || methodDef.IsSetter)
                {
                    foreach(var p in methodDef.DeclaringType.Properties)
                    {
                        if((p.SetMethod != null && p.SetMethod.FullName == methodDef.FullName) || (p.GetMethod != null && p.GetMethod.FullName == methodDef.FullName))
                        {
                            if(!HasProperty(p)) 
                            {
                                properties.Add(new PropertyGenerater(p, this, true));
                                RefNameSpace.Add(p.PropertyType.Namespace);
                            }
                            return;
                        }
                    }
                }
                if (!HasMethod(methodDef))
                {
                    new MethodGenerater(methodDef, this, true, methods);
                    RefNameSpace.UnionWith(Utils.GetNameSpaceRef(methodDef));
                }
            }
        }

        private bool HasMethod(MethodDefinition method)
        {
            return methods.Find(x => x.GenMethodDef.FullName == method.FullName) != null || retainDic.ContainsKey(method.MetadataToken.ToInt32());
        }

        private bool HasProperty(PropertyDefinition property)
        {
            return properties.Find(x => x.PropName == property.FullName) != null || retainDic.ContainsKey(property.MetadataToken.ToInt32());
        }

        public DllRuntime GetRuntime()
        {
            DllRuntime ret = DllRuntime.None;
            if(compiler != null)
            {
                ret = compiler.Runtime;
            }
            else
            {
                var parent = this.parent;
                while(parent != null)
                {
                    if(parent.parent != null)
                    {
                        parent = parent.parent;
                    }
                    else
                    {
                        break;
                    }
                }
                if(parent != null)
                {
                    ret = parent.GetRuntime();
                }
            }
            if(ret == DllRuntime.None)
            {
                throw new Exception("compiler must have a runtime");
            }
            return ret;
        }

        public override string TypeFullName()
        {
            return genType.FullName.Replace("`","_");
        }

        private void GenNested(CS writer)
        {
            if (nestType.Count <= 0)
            {
                return;
            }

            foreach (var t in nestType.Values)
            {
                t.GenerateCode(writer);
            }
            writer.CurWriter.Flush();

        }

        public override void GenerateCode(CS writer)
        {
            bool newWriter = false;
            if(writer == null)
            {
                newWriter = true;
                writer = new CS(new CodeWriter(FileStream));
            }
            //using (new CS(new CodeWriter(FileStream)))
            {
                base.GenerateCode();

                if (isCopyOrignNodes)
                {
                    GenerateFullOriginalNodes();
                    if (newWriter)
                    {
                        writer.CurWriter.EndAll();
                    }
                    else
                    {
                        if (genType.IsNested) //这里完全copy，不用手动end
                        {
                            //writer.CurWriter.End();
                        }
                    }
                    //if (!genType.IsStruct() || isCopyFullOrignalNodes)
                    {
                        if (newWriter)
                        {
                            writer.Dispose();
                        }
                        return;
                    }
                }

                if(!genType.IsNested)
                {
                    if(!isCopyOrignNodes)
                    {
                        writer.CurWriter.CreateLinePoint("//namespace");
                        RefNameSpace.ExceptWith(Config.Instance.StripUsing);
                        foreach (var ns in RefNameSpace)
                        {
                            if (!string.IsNullOrEmpty(ns))
                            {
                                writer.CurWriter.WriteLine($"using {ns}");
                            }
                        }
                        writer.CurWriter.WriteLine("using System.Runtime.InteropServices");
                        writer.CurWriter.WriteLine("using Object = UnityEngine.Object");
                    }

                    if (!string.IsNullOrEmpty(genType.Namespace))
                    {
                        writer.CurWriter.Start($"namespace {genType.Namespace}");
                    }
                }

                //if (!isCopyOrignType)
                //    CS.Writer.WriteLine($"[WrapperClass(\"{Binder.curModule.Name}\")]", false);

                //Utils.TokenMap = nodesCollector.TokenMap;
                string classDefine = Utils.GetMemberDelcear(genType, nodesCollector.TokenMap, stripInterfaceSet);
                if(Binder.retainTypes.Contains(genType.FullName))
                {
                    classDefine = classDefine.Replace("internal ", "public ");
                }

                bool isStatic = genType.IsAbstract && genType.IsSealed;
                if (genType.BaseType != null && !isStatic && !genType.IsStruct())
                {
                    if (genType.BaseType.FullName == "System.Object")
                    {
                        var index = classDefine.IndexOf(":");
                        if (index > 0)
                        {
                            classDefine = classDefine.Replace(":", ": WObject,");
                        }
                        else
                        {
                            classDefine += ": WObject";
                        }
                    }
                    else
                    {
                        Binder.AddType(genType.BaseType.Resolve());
                    }
                }

                writer.CurWriter.Start(classDefine);


                writer.CurWriter.CreateLinePoint("//member");
                /*CS.Writer.Start($"internal {genType.Name}(int handle,IntPtr ptr): base(handle, ptr)");
                CS.Writer.End();*/

                foreach (var p in properties)
                {
                    p.GenerateCode();
                }

                foreach(var e in events)
                {
                    e.GenerateCode();
                }

                if(!hasDefaultConstructor && !genType.IsSealed && !genType.IsInterface)
                {
                    writer.CurWriter.WriteLine($"public {genType.Name}()" + " { }", false);
                }

                if(genType.IsClass && !genType.IsValueType && !isStatic)
                {
                    writer.CurWriter.WriteLine($"protected override System.Type GetWType() {{ return typeof({genType.Name}); }}", false);
                }

                foreach (var m in methods)
                {
                    m.GenerateCode();
                }
                
                GeneratePartOriginalNodes();

                GenNested(writer);

                if (newWriter)
                {
                    writer.CurWriter.EndAll();
                }else
                {
                    if (genType.IsNested)
                    {
                        writer.CurWriter.End();
                    }
                }
            }

            if (newWriter)
            {
                writer.Dispose();
            }
        }

        bool CheckCopyOrignNodes(TypeDefinition type)
        {
            isCopyFullOrignalNodes = Binder.retainTypes.Contains(type.FullName);
            isCopyFullOrignalNodes |= Binder.retainTypes.Contains(type.Namespace);

            isCopyFullOrignalNodes |= type.DoesSpecificTypeImplementInterface("IEnumerator");

            isCopyFullOrignalNodes |= Utils.IsAttribute(type);

            isCopyFullOrignalNodes |= type.IsStruct();

            isCopyFullOrignalNodes |= Utils.IsException(type);
            //TODO: interface full retain
            isCopyFullOrignalNodes |= type.IsInterface;

            if (type.IsEnum || type.IsDelegate() ||/* type.IsInterface || */Utils.IsAttribute(type) || type.IsStruct())
                return true;

            if (Utils.IsFullValueType(type) || isCopyFullOrignalNodes)
                return true;

            return false;
        }

        void GenerateFullOriginalNodes()
        {
            bool isNested = genType.IsNested;
            
            HashSet<string> IgnoreNestType = new HashSet<string>();

            //if (!(isNested && IsCopyOrignType(genType.DeclaringType)))
            {
                var tName = genType.FullName.Replace("/", "+");
                var name = new FullTypeName(tName);
                var decompiler = Binder.GetDecompiler(genType.Module.Name);
                AstNode syntaxTree;

                if (isNested)
                {
                    ITypeDefinition typeInfo = decompiler.TypeSystem.MainModule.Compilation.FindType(name).GetDefinition();
                    var tokenOfFirstMethod = typeInfo.MetadataToken;
                    syntaxTree = decompiler.Decompile(tokenOfFirstMethod);
                }
                else
                {
                    syntaxTree = decompiler.DecompileType(name);
                }

                StringWriter w = new StringWriter();
                CustomOutputVisitor outVisitor;

                if(isCopyFullOrignalNodes)
                {
                    if (genType.IsStruct())
                    {
                        outVisitor = new StructOutputVisitor(this, decompiler, isNested, w, Binder.DecompilerSetting.CSharpFormattingOptions);
                    }
                    else if (genType.IsInterface)
                    {
                        outVisitor = new InterfaceOutputVisitor(this, decompiler, isNested, w, Binder.DecompilerSetting.CSharpFormattingOptions);
                    }
                    else
                    {
                        outVisitor = new CustomOutputVisitor(isNested, w, Binder.DecompilerSetting.CSharpFormattingOptions);
                    }
                }
                else
                {
                    outVisitor = new BlittablePartOutputVisitor(isNested, w, Binder.DecompilerSetting.CSharpFormattingOptions);
                }

                outVisitor.isFullRetain = isCopyFullOrignalNodes;
                outVisitor.checkTypeRefVisitor = new CheckTypeRefVisitor(CheckRefType);
                bool isStatic = genType.IsAbstract && genType.IsSealed;
                if (genType.BaseType != null && !isStatic && genType.IsClass)
                {
                    if (genType.BaseType.FullName == "System.Object")
                        outVisitor.AddWObject = true;
                }

                syntaxTree.AcceptVisitor(outVisitor);

                if (outVisitor is StructOutputVisitor)
                {
                    var structVisitor = outVisitor as StructOutputVisitor;
                    var tmp1 = new HashSet<string>(structVisitor.NamespaceRef);
                    tmp1.ExceptWith(RefNameSpace);
                    if (tmp1.Count > 0)
                    {
                        foreach (var t in tmp1)
                        {
                            if(!string.IsNullOrEmpty(t))
                            {
                                CS.Writer.WriteHead($"using {t}");
                            }
                        }
                    }
                    RefNameSpace.UnionWith(tmp1);

                    foreach (var m in structVisitor.CalledMethods)
                    {
                        Binder.AddMethod(m);
                    }
                }

                if (!isNested)
                {
                    RefNameSpace.UnionWith(outVisitor.nestedUsing);
                    RefNameSpace.ExceptWith(Config.Instance.StripUsing);
                    foreach (var ns in RefNameSpace)
                    {
                        if (!string.IsNullOrEmpty(ns))
                        {
                            CS.Writer.WriteHead($"using {ns}");
                        }
                    }
                }

                var txt = w.ToString();
                CS.Writer.WriteLine(txt, false);

                AddRefType(outVisitor.InternalTypeRef);
            }
        }


        void GetCopyPartOrignNodes()
        {
            var decompiler = Binder.GetDecompiler(genType.Module.Name);

            var tName = genType.FullName.Replace("/", "+");
            var name = new FullTypeName(tName);
            ITypeDefinition typeInfo = decompiler.TypeSystem.MainModule.Compilation.FindType(name).GetDefinition();
            var tokenOfType = typeInfo.MetadataToken;
            var st = decompiler.Decompile(tokenOfType);

            nodesCollector = new TokenMapVisitor();
            st.AcceptVisitor(nodesCollector);

            if (!Binder.UnityCoreModuleSet.Contains(genType.Module.Name))
                return;

            bool inUnsafeNS = false; // genType.Namespace.Contains("LowLevel.Unsafe");

            var retainFilter = new RetainFilter(genType, decompiler);
            retainFilter.TokenMap = nodesCollector.TokenMap;
            retainFilter.InUnsafeNS = inUnsafeNS;
            retainFilter.isFullValueType = isCopyOrignNodes;

            st.AcceptVisitor(retainFilter);
            retainDic = retainFilter.RetainDic;

            var keys = new List<int>(retainDic.Keys);
            foreach(var k in keys)
            {
                var m = Utils.GetMethodByToken(genType, k);
                if(m != null && !Utils.FilterStructMethod(m, new List<MethodDefinition>()))
                {
                    retainDic.Remove(k);
                }
            }

            if (retainDic.Count > 0)
            {
                RefNameSpace.UnionWith(retainFilter.NamespaceRef);
            }

            CheckStructMethodsCall();
        }

        private void CheckStructMethodsCall()
        {
            if (!genType.IsStruct())
            {
                return;
            }

            var methods = genType.Methods;
            foreach(var m in methods)
            {
                if (m.HasBody)
                {
                    foreach(var inst in m.Body.Instructions)
                    {
                        if(inst.OpCode.Code == Mono.Cecil.Cil.Code.Call)
                        {
                            var cmethod = inst.Operand as MethodReference;
                            var def = cmethod.Resolve();
                            if(!def.IsGetter && !def.IsSetter)
                            {
                                Binder.AddMethod(cmethod);
                            }
                        }
                    }
                }
            }
        }

        bool IsCopyOrignNode(MemberReference member)
        {
            if (retainDic.Count < 1)
                return false;

            var token = member.MetadataToken.ToInt32();
            return token != 0 && retainDic.ContainsKey(token);
        }

        void GeneratePartOriginalNodes()
        {
            if (retainDic.Count < 1)
                return ;

            CS.Writer.WriteLine("#region copy orign code nodes", false);
            var sw = new StringWriter();
            var outputVisitor = new CustomOutputVisitor(genType.IsNested, sw, Binder.DecompilerSetting.CSharpFormattingOptions);
            foreach (var node in retainDic.Values)
            {
                node.AcceptVisitor(outputVisitor);
            }
            CS.Writer.WriteLine(sw.ToString(), false);

            AddRefType(outputVisitor.InternalTypeRef);

            CS.Writer.WriteLine("#endregion", false);

        }

        void AddRefType(HashSet<string> refSet)
        {
            foreach (var rtype in refSet)
            {
                var tName = rtype.Replace("+", "/");
                var td = genType.Module.GetType(tName);
                if (td != null)
                {
                    var tdDeclear = td.DeclaringType;
                    if (tdDeclear != null && tdDeclear.MetadataToken == genType.MetadataToken)
                    {
                        nestType[td] = new ClassGenerater(td, this);
                    }
                    else if (!Utils.Filter(td))
                    {
                        //class define is invalid
                        CS.Writer.WriteLine($"{(genType.IsPublic ? "public" : "internal")} class {td.Name}{{}}", false);
                    }
                    else
                    {
                        Binder.AddType(td);
                    }
                }
                else if (genType.Module.TryGetTypeReference(tName, out var tref))
                {
                    Binder.AddTypeRef(tref);
                }
            }
        }

        bool CheckRefType(string rtype)
        {
            var tName = rtype.Replace("+", "/");
            TypeReference type = genType.Module.GetType(tName);
            if (type == null)
                genType.Module.TryGetTypeReference(tName, out type);

            var td = type.DeclaringType;
            if (td != null && td.MetadataToken == genType.MetadataToken)
                return true;

            return Utils.Filter(type);
        }

        private HashSet<string> stripInterfaceSet = new HashSet<string>();
        void CheckInterface(MethodDefinition method)
        {
            if(method.Name == "System.IDisposable.Dispose" && method.Parameters.Count == 0 && !method.IsPublic)
                stripInterfaceSet.Add("IDisposable");

            if(method.Name == "GetSurrogate" && method.Parameters.Count == 3 && !Utils.Filter(method, GetRuntime()))
                stripInterfaceSet.Add("ISurrogateSelector");

            if (method.Name == "GetEnumerator" && method.Parameters.Count == 0 && !Utils.Filter(method, GetRuntime()))
                stripInterfaceSet.Add("IEnumerable");
        }
    }
}