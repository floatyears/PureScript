﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Mono.Cecil;
using System.IO;
using ICSharpCode.Decompiler;
using ICSharpCode.Decompiler.CSharp;
using ICSharpCode.Decompiler.TypeSystem;
using ICSharpCode.Decompiler.CSharp.Syntax;
namespace Generater
{
    /// <summary>
    /// prefab或者场景资源的 脚本对象的反序列化过程是在Unity引擎内实现
    /// mono内运行的interp dlls无法实现这个过程，所以这些interp dlls内的MonoBehaviour/ScriptableObject必须在il2cpp一侧也要有此定义，不然无法正确进行反序列化
    /// 最后在实例化资源对象的过程中，再将il2cpp内的脚本对象的数据复制一份到mono
    /// </summary>
    public class MonoBehaviorProxyGenerator : CodeGenerater
    {
        private TypeDefinition genType;

        //private List<PropertyGenerater> properties = new List<PropertyGenerater>();
        //private List<DelegateGenerater> events = new List<DelegateGenerater>();
        private List<MethodDefinition> methods = new List<MethodDefinition>();
        private List<FieldDefinition> fields = new List<FieldDefinition>();
        private Dictionary<TypeDefinition, MonoBehaviorProxyGenerator> nestType = new Dictionary<TypeDefinition, MonoBehaviorProxyGenerator>();
        private bool hasDefaultConstructor = false;
        private bool isCopyOrignType;
        private bool isFullRetainType;
        private StreamWriter FileStream;

        public HashSet<string> RefNameSpace = new HashSet<string>();


        Dictionary<int, AstNode> retainDic = new Dictionary<int, AstNode>();
        public TokenMapVisitor nodesCollector;
        private CSharpDecompiler decompiler;

        private MonoBehaviorProxyGenerator parent = null;
        private CSCGenerater compiler = null;

        public MonoBehaviorProxyGenerator(TypeDefinition type, CSCGenerater compiler)
        {
            this.compiler = compiler;
            genType = type;
            Init();
        }

        public MonoBehaviorProxyGenerator(TypeDefinition type, MonoBehaviorProxyGenerator parent = null)
        {
            this.parent = parent;
            genType = type;
            Init();
        }

        public void Init()
        {
            RefNameSpace.Add("System");
            RefNameSpace.Add("PureScriptProxy");
            RefNameSpace.Add("System.Runtime.CompilerServices");
            RefNameSpace.Add("System.Runtime.InteropServices");

            if (parent == null)
            {
                var dir = Path.Combine(Binder.OutDir, "IL2Cpp_" + genType.Module.Assembly.Name.Name);
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

            CheckNodes();

            if (genType.BaseType != null)
            {
                RefNameSpace.Add(genType.BaseType.Namespace);
            }

            foreach (var t in genType.NestedTypes)
            {
                if (t.Name.StartsWith("<")) // || !Utils.Filter(t))
                    continue;
                if ((t.IsPublic || t.IsNestedPublic) && !Utils.IsObsolete(t) && Utils.IsTypeSerializable(t))
                {
                    var nestGen = new MonoBehaviorProxyGenerator(t, this);
                    nestType[t] = nestGen;
                    RefNameSpace.UnionWith(nestGen.RefNameSpace);
                }
            }

            foreach (FieldDefinition field in genType.Fields)
            {
                // if (isFullValueType && !field.IsStatic)
                //    continue;
                if (Utils.IsFieldSerializable(field))
                {
                    if (field.FieldType.Resolve().IsDelegate())
                    {
                        //if (Utils.Filter(field.FieldType))
                        //{
                        //    events.Add(new DelegateGenerater(field));
                        //    RefNameSpace.Add(field.FieldType.Namespace);
                        //}
                    }
                    else
                    {
                        //properties.Add(new PropertyGenerater(field));
                    }
                    RefNameSpace.Add(field.FieldType.Namespace);

                    fields.Add(field);

                    MonoBehaviorProxyManager.AddType(field.DeclaringType);
                }

            }
            var tokens = new TokenMapVisitor();

            var baseMethods = genType.BaseType.Resolve().Methods;
            foreach (var method in baseMethods)
            {
                if (method.IsAbstract)
                {
                    foreach(var m in genType.Methods)
                    {
                        if (m.CompareSignature(method))
                        {
                            //var declear = Utils.GetMemberDelcear(m, nodesCollector.TokenMap);
                            methods.Add(m);
                            RefNameSpace.Add(m.ReturnType.Namespace);
                            foreach(var p in m.Parameters)
                            {
                                RefNameSpace.Add(p.ParameterType.Namespace);
                            }
                        }
                    }
                }
            }

            //foreach (var e in genType.Events)
            //{
            //    if (Utils.Filter(e))
            //    {
            //        events.Add(new DelegateGenerater(e));
            //        RefNameSpace.Add(e.EventType.Namespace);
            //    }
            //}

        }

        void CheckNodes()
        {
            decompiler = MonoBehaviorProxyManager.GetDecompiler(genType.Module.Name);

            var tName = genType.FullName.Replace("/", "+");
            var name = new FullTypeName(tName);
            ITypeDefinition typeInfo = decompiler.TypeSystem.MainModule.Compilation.FindType(name).GetDefinition();
            var tokenOfType = typeInfo.MetadataToken;
            var st = decompiler.Decompile(tokenOfType);

            nodesCollector = new TokenMapVisitor();
            st.AcceptVisitor(nodesCollector);

        }

        public override void GenerateCode(CS writer = null)
        {
            using (new CS(new CodeWriter(FileStream)))
            {
                base.GenerateCode();

                //write namespace
                if (!genType.IsNested)
                {
                    RefNameSpace.ExceptWith(Config.Instance.StripUsing);
                    foreach (var ns in RefNameSpace)
                    {
                        if (!string.IsNullOrEmpty(ns))
                        {
                            CS.Writer.WriteLine($"using {ns}");
                        }
                    }
                    CS.Writer.WriteLine("using System.Runtime.InteropServices");
                    CS.Writer.WriteLine("using Object = UnityEngine.Object");
                    CS.Writer.CreateLinePoint("//namespace");

                    if (!string.IsNullOrEmpty(genType.Namespace))
                    {
                        CS.Writer.Start($"namespace {genType.Namespace}");
                    }
                }

                //var stripInterfaceSet = new HashSet<string>(genType.Interfaces.Select(x => x.InterfaceType.Name));
                string classDefine = GetMemberDelcear(genType); //remove all interfaces
                if (genType.BaseType.FullName == "UnityEngine.MonoBehaviour")
                {
                    classDefine = classDefine.Replace("MonoBehaviour", "__MonoBehaviourProxy");
                }
                CS.Writer.Start(classDefine);

                //write all serializable field
                foreach (var f in fields)
                {
                    CS.Writer.WriteLine(GetMemberDelcear(f), false);
                }

                foreach(var m in methods)
                {
                    CS.Writer.Start(GetMemberDelcear(m));
                    if(m.ReturnType.FullName != "System.Void")
                    {
                        CS.Writer.WriteLine($"return default({m.ReturnType.FullName})");
                    }
                    CS.Writer.End();
                }

                //var lp = CS.Writer.GetLinePoint("//namespace");
                //CS.Writer.UsePointer(lp);
                //foreach (var ns in output.NamespaceRef)
                //{
                //    CS.Writer.WriteLine($"using {ns}");
                //}
                //CS.Writer.UnUsePointer(lp);

                GenNested();

                CS.Writer.EndAll();
            }
                
        }


        private void GenNested()
        {
            if (nestType.Count <= 0)
                return;

            CS.Writer.Flush();
            foreach (var t in nestType.Values)
            {
                t.GenerateCode();
            }
        }

        public static void End()
        {
            //foreach (var m in moduleSet)
            //    m.Dispose();

            //moduleSet.Clear();
        }


        public string GetMemberDelcear(IMemberDefinition member)
        {
            var method = member as MethodDefinition;
            if (method != null)
            {
                if (method.IsConstructor && method.Parameters.Count == 0)
                {
                    return $"public {method.DeclaringType.Name}()";
                }
            }

            var token = member.MetadataToken.ToInt32();
            StringWriter writer = new StringWriter();
            var output = new MonoProxyMemberDeclearVisitor(decompiler, writer, Binder.DecompilerSetting.CSharpFormattingOptions);
            if (nodesCollector.TokenMap != null && nodesCollector.TokenMap.TryGetValue(token, out var map))
            {
                map.AcceptVisitor(output);
                if(output.NamespaceRef.Count > 0)
                {
                    
                }
            }
            else
            {
                Console.WriteLine("Key Not Found: " + member.ToString());
            }
            //TokenMap[token].AcceptVisitor(output);
            return writer.ToString();
        }

        public override string TypeFullName()
        {
            return genType.FullName.Replace("`", "_");
        }
    }
}
