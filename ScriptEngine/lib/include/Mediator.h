#ifndef ___marshal_h
#define ___marshal_h

#include "runtime.h"
#include "il2cpp_support.h"
#include "wrapper.h"

#define CLASS_MASK_UNITY_NATIVE (1<<2)
#define CLASS_MASK_WRAPPER (1<<3)
#define ENABLE_DEBUG 0

#define FIELD_ATTRIBUTE_FIELD_ACCESS_MASK     0x0007
#define FIELD_ATTRIBUTE_COMPILER_CONTROLLED   0x0000
#define FIELD_ATTRIBUTE_PRIVATE               0x0001
#define FIELD_ATTRIBUTE_FAM_AND_ASSEM         0x0002
#define FIELD_ATTRIBUTE_ASSEMBLY              0x0003
#define FIELD_ATTRIBUTE_FAMILY                0x0004
#define FIELD_ATTRIBUTE_FAM_OR_ASSEM          0x0005
#define FIELD_ATTRIBUTE_PUBLIC                0x0006

#define FIELD_ATTRIBUTE_STATIC                0x0010
#define FIELD_ATTRIBUTE_INIT_ONLY             0x0020
#define FIELD_ATTRIBUTE_LITERAL               0x0040
#define FIELD_ATTRIBUTE_NOT_SERIALIZED        0x0080
#define FIELD_ATTRIBUTE_SPECIAL_NAME          0x0200
#define FIELD_ATTRIBUTE_PINVOKE_IMPL          0x2000

#if defined(__cplusplus)
extern "C"
{
#endif // __cplusplus

	typedef struct WObjectHead
	{
		void* __align1;
		void* __align2;
		void* objectPtr;
	}WObjectHead;

    typedef struct WrapperHead
    {
        WObjectHead objHead;
        int32_t handle;
    }WrapperHead;

	typedef struct Il2CppObject
	{
		union
		{
			Il2CppClass* klass;
			void* vtable;
		};
		void* monitor;
	} Il2CppObject;

	typedef struct Il2CppReflectionType
	{
		Il2CppObject object;
		const Il2CppType* type;
	} Il2CppReflectionType;


	typedef struct _MonoReflectionType {
		MonoObject object;
		MonoType* type;
	} _MonoReflectionType;

	struct _MonoType {
		union {
			MonoClass* klass; /* for VALUETYPE and CLASS */
			MonoType* type;   /* for PTR */
			MonoArrayType* array; /* for ARRAY */
			MonoMethodSignature* method;
			MonoGenericParam* generic_param; /* for VAR and MVAR */
			MonoGenericClass* generic_class; /* for GENERICINST */
		} data;
		unsigned int attrs : 16; /* param attributes or field flags */
		MonoTypeEnum type : 8;
		unsigned int has_cmods : 1;
		unsigned int byref : 1;
		unsigned int pinned : 1;  /* valid when included in a local var signature */
	};

    
	void bind_mono_il2cpp_object(MonoObject* mono, Il2CppObject* il2cpp);
	MonoObject* get_mono_object_impl(Il2CppObject* il2cpp, MonoClass* m_class,bool decide_class);
    MonoObject* get_mono_object(Il2CppObject* il2cpp, MonoClass* m_class);
	Il2CppObject* get_il2cpp_object(MonoObject* mono,Il2CppClass* m_class);
	Il2CppObject* get_il2cpp_object_with_ptr(void* objPtr);
	void* get_il2cpp_internal_ptr(Il2CppObject* obj);

	MonoString* get_mono_string(Il2CppString* str);
	Il2CppString* get_il2cpp_string(MonoString* str);
	MonoArray* get_mono_array_with_serializable(Il2CppArray* array);
	MonoArray* get_mono_array(Il2CppArray * array);
	MonoArray* get_mono_array_impl(Il2CppArray* array, bool includeSerializable);
	Il2CppArray* get_il2cpp_array(MonoArray* array);
	void copy_array_i2_mono(Il2CppArray* i2_array, MonoArray* mono_array);
	void copy_il2cpp_struct_to_mono(Il2CppObject* il2cppObj, MonoObject* monoObj);
	void copy_il2cpp_struct_to_mono_raw(void* il2cppObj, MonoObject* monoObj);
	void copy_il2cpp_class_data_to_mono(Il2CppObject* i2obj, MonoObject* mobj);
	void copy_mono_struct_to_il2cpp(MonoObject* monoObj, Il2CppObject* il2cppObj);
	void copy_mono_struct_to_il2cpp_raw(void* monoData, Il2CppObject* il2cppObj);
	void get_mono_struct(Il2CppObject* i2struct, MonoObject** monoStruct, Il2CppReflectionType* i2type, int32_t i2size);
	void get_mono_struct_raw(void* i2struct, MonoObject** monoStruct, Il2CppReflectionType* i2type, int32_t i2size);
	void get_il2cpp_struct(MonoObject* monoStruct, Il2CppObject** i2struct, const Il2CppType* i2type, int32_t msize);
	void get_il2cpp_struct_raw(void* monoStruct, Il2CppObject** i2struct, const Il2CppType* i2type, int32_t msize);

	bool inline is_primitive_il2cpp(const Il2CppType* type)
	{
		if (type == NULL)
		{
			platform_log("[is_primitive_il2cpp] type is null");
			return false;
		}
		return !type->byref && ((type->type >= IL2CPP_TYPE_BOOLEAN && type->type <= IL2CPP_TYPE_R8) || (type->type >= IL2CPP_TYPE_I && type->type <= IL2CPP_TYPE_U));
	}


	bool inline is_struct_type_il2cpp(const Il2CppType* type)
	{
		if (type == NULL)
		{
			platform_log("[is_struct_type_il2cpp] type is null");
			return false;
		}
		return !type->byref && type->type == MONO_TYPE_VALUETYPE && !is_primitive_il2cpp(type);
	}

	bool inline is_primitive(MonoType* type)
	{
		if (type == NULL)
		{
			platform_log("[is_primitive] type is null");
			return false;
		}
		return !type->byref && ((type->type >= MONO_TYPE_BOOLEAN && type->type <= MONO_TYPE_R8) || (type->type >= MONO_TYPE_I && type->type <= MONO_TYPE_U));
	}

	int32_t get_primitive_type_size(MonoType* type);

	bool inline is_struct_type(MonoType* type)
	{
		if (type == NULL)
		{
			platform_log("[is_struct_type] type is null");
			return false;
		}
		return !type->byref && type->type == MONO_TYPE_VALUETYPE && !is_primitive(type);
	}

	bool inline is_struct(MonoClass* klass)
	{
		platform_log("check struct1: %s", mono_class_get_name(klass));
		MonoType* type = mono_class_get_type(klass);
		return is_struct_type(type);
	}

	bool is_full_value_struct_type(MonoType* type);
	bool is_full_value_struct(MonoClass* klass);

	MonoImage* mono_get_image(const char* assembly);
	MonoClass* mono_get_class(MonoImage* image, const char* _namespace, const char* name);
	MonoClass* mono_search_class(const char* assembly, const char* _namespace, const char* name);
	MonoMethod* mono_lookup_method(const char* method_name, MonoClass *kclass, int param_count);
	
	Il2CppClass* get_il2cpp_class(MonoClass* mclass);
	MonoClass* get_mono_class(Il2CppClass* mclass);

	//System.Type
	Il2CppReflectionType* get_il2cpp_reflection_type(MonoReflectionType * type);
	MonoReflectionType* get_mono_reflection_type(Il2CppReflectionType * type);

    //wrapper
    MonoObject* get_mono_wrapper_object(Il2CppObject* il2cpp, MonoClass* m_class);
	MonoObject* get_mono_wrapper_object_delay_init(Il2CppObject* il2cpp, MonoClass* m_class, bool delay_init);
    Il2CppClass* get_monobehaviour_wrapper_class();
    Il2CppReflectionType* get_monobehaviour_wrapper_rtype();
    void call_wrapper_init(Il2CppObject* il2cpp, MonoObject* mono);
	bool need_monobehaviour_wrap(const char* asm_name, MonoClass* m_class);

	//proxy
	Il2CppReflectionType* get_monobehaviour_proxy_rtype();
	Il2CppClass* get_monobehaviour_proxy_class();

	//Exception
	MonoException* get_mono_exception(Il2CppException* il2cpp);
	Il2CppException* get_il2cpp_exception(MonoException* mono);
	void check_il2cpp_exception(Il2CppException* il2cpp);
	void check_mono_exception(MonoException* mono);
	void raise_mono_exception_runtime(const char* msg);
	void raise_il2cpp_exception_runtime(const char* msg);


	bool is_unity_name_space(const char* ns);

#if ENABLE_DEBUG
	const char* debug_mono_obj(MonoObject* obj);
	const char* debug_mono_method(MonoMethod* method);
	const char* debug_il2cpp_obj(Il2CppObject* obj);
#else
#define debug_mono_obj(obj)  
#define debug_mono_method(method)   
#define debug_il2cpp_obj(obj) 
#endif
  
	

	void insert_assembly_map(const char* src, const char* tar);
	void insert_reloadable(const char* assembly, const char* info);
	bool is_reloadable(const char* assembly);

#if defined(__cplusplus)
}
#endif // __cplusplus
#endif
