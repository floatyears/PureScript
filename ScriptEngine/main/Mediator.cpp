#include "Mediator.h"
#include "mono/metadata/object.h"
#include "mono/metadata/environment.h"
#include "mono/utils/mono-publib.h"
#include "mono/utils/mono-logger.h"
#include "mono/metadata/assembly.h"
#include "mono/metadata/mono-debug.h"
#include "mono/metadata/exception.h"
#include "mono/metadata/debug-helpers.h"
#include "mono/metadata/object-forward.h"
#include "mono/metadata/object.h"

#include <map>
#include <string>
#include <sstream>

#include "runtime.h"
//#include "internals.h"
//#include "../custom/Wrapper.h"

bool is_unity_name_space(const char* ns)
{
	return strncmp(ns, "UnityEngine", 11) == 0;
}
bool is_wrapper_name_space(const char* ns)
{
	return strncmp(ns, "PureScriptWrapper", 17) == 0;
}


bool is_wrapper_class(Il2CppClass* klass)
{
	//return il2cpp_check_flag(klass, CLASS_MASK_WRAPPER);
	//return klass->initialized & CLASS_MASK_WRAPPER;
	if (klass == NULL)
	{
		return false;
	}
	const char* ns = il2cpp_class_get_namespace(klass);
	return is_wrapper_name_space(ns);
}

/*
bool is_unity_native(MonoClass* klass)
{
	//return mono_check_flag(klass, CLASS_MASK_UNITY_NATIVE);
	//return  klass->inited & CLASS_MASK_UNITY_NATIVE;
}*/


#pragma region ObjectBind

typedef struct  BindInfo
{
	uint32_t mono_handle;
	uint32_t i2_handle;
} BindInfo;

static MonoReferenceQueue* gc_queue;
typedef std::map<uint64_t, BindInfo> Il2cppObjMap;
static Il2cppObjMap s_il2cppMap;

void on_mono_object_gc(void* user_data)
{
	if (user_data == NULL)
		return;

	uint64_t il2cppHandle = (uint64_t)user_data;
	Il2cppObjMap::iterator res = s_il2cppMap.find(il2cppHandle);
	if (res != s_il2cppMap.end())
	{
		il2cpp_gchandle_free(res->second.i2_handle);
		mono_gchandle_free(res->second.mono_handle);
		s_il2cppMap.erase(res);
	}
}

void bind_mono_il2cpp_object(MonoObject* mono, Il2CppObject* il2cpp)
{
	uint32_t i2Handle = il2cpp_gchandle_new(il2cpp, FALSE);
	uint32_t monoHandle = mono_gchandle_new_weakref(mono, FALSE);

	BindInfo info;
	info.mono_handle = monoHandle;
	info.i2_handle = i2Handle;
	s_il2cppMap[(uint64_t)il2cpp] = info;

	WObjectHead* monoHead = (WObjectHead*)(mono);
	if (monoHead->objectPtr == NULL)
		monoHead->objectPtr = il2cpp; // non-compacting gc

	if (gc_queue == NULL)
		gc_queue = mono_gc_reference_queue_new(on_mono_object_gc);

	mono_gc_reference_queue_add(gc_queue, mono, il2cpp);
}

MonoObject* get_mono_object(Il2CppObject* il2cpp, MonoClass* m_class) {
    return get_mono_object_impl(il2cpp, m_class, FALSE);
}
MonoObject* get_mono_object_impl(Il2CppObject* il2cpp, MonoClass* m_class, bool decide_class)
{
	if (il2cpp == NULL)
		return NULL;

	bool isWrapper = is_wrapper_class(il2cpp_object_get_class(il2cpp));
	if(isWrapper)
		return get_mono_wrapper_object(il2cpp, m_class);

	uint32_t monoHandle = 0;
	MonoObject* monoObj = NULL;
	
	uint64_t il2cppHandle = (uint64_t)il2cpp;
	Il2cppObjMap::iterator res = s_il2cppMap.find(il2cppHandle);
	if (res != s_il2cppMap.end())
		monoHandle = res->second.mono_handle;

	if (monoHandle != 0)
	{
		monoObj = mono_gchandle_get_target(monoHandle);
		if (monoObj == NULL)
			mono_gchandle_free(monoHandle);
	}
	if (monoObj == NULL)
	{
		Il2CppClass* i2class = il2cpp_object_get_class(il2cpp);
		if (m_class != NULL)
		{
			const char* i2cname = il2cpp_class_get_name(i2class);
			const char* monocname = mono_class_get_name(m_class);
			if (strcmp(i2cname, monocname) != 0)
			{
				decide_class = true;
				m_class = NULL;
			}
		}

		if(m_class == NULL && decide_class)
			m_class = get_mono_class(i2class);

		if (m_class != NULL)
		{
			monoObj = mono_object_new(g_domain, m_class);
			bind_mono_il2cpp_object(monoObj, il2cpp);
		}
	}
	return monoObj;
}
void copy_il2cpp_struct_to_mono(Il2CppObject* il2cppObj, MonoObject* monoObj)
{
	if (il2cppObj == NULL)
	{
		MonoType* type = mono_class_get_type(mono_object_get_class(monoObj));
		MonoClass* klass = mono_class_from_mono_type(type);
		platform_log("il2cpp obj is null when copying struct %d", mono_class_get_name(klass));
		return;
	}
	void* raw_data = (char*)il2cppObj + sizeof(Il2CppObject);
	copy_il2cpp_struct_to_mono_raw(raw_data, monoObj);
}

void copy_il2cpp_struct_to_mono_raw(void* il2cppData, MonoObject* monoObj)
{
	
	//note: array element in Il2CppArray is not neccesarily Il2CppObject*, it may be a flat struct type
	MonoClass* klass = mono_object_get_class(monoObj);
	MonoType* type = mono_class_get_type(klass);
	if (il2cppData == NULL)
	{
		platform_log("il2cpp struct is null when copying struct %d", mono_class_get_name(klass));
		return;
	}
	gpointer iter = NULL;
	MonoClassField* field = NULL;
	int align = 0;
	int size = 0;
	while ((field = mono_class_get_fields(klass, &iter))) {
		MonoType* field_type = mono_field_get_type(field);
		uint32_t offset = mono_field_get_offset(field);
		if (offset < sizeof(MonoObject))
		{
			platform_log("copy struct fail, field %s 's offset is %d", mono_class_get_name(mono_class_from_mono_type(field_type)), offset);
			return;
		}
		else
		{
			offset -= sizeof(MonoObject);
		}
		if (field_type->type == MONO_TYPE_CLASS) // is_primitive(field_type)) //do a shallow copy
		{
			//size = mono_type_size(field_type, &align);
			Il2CppObject* i2obj = (Il2CppObject*)(void*)((char*)il2cppData + offset);
			MonoObject* monoobj = get_mono_object(i2obj, mono_class_from_mono_type(field_type));
			//mono_field_set_value(monoObj, field, monoobj);
			mono_gc_wbarrier_set_field(monoObj, field, monoobj);
		}
		else if(is_struct_type(field_type))
		{
			MonoObject** monoobj = NULL;
			get_mono_struct((Il2CppObject*)((char*)il2cppData + offset), monoobj, get_il2cpp_reflection_type(mono_type_get_object(g_domain, type)), mono_class_value_size(klass, NULL));
			if (monoobj != NULL)
			{
				mono_gc_wbarrier_set_field(monoObj, field, *monoobj);
			}
		}
		else
		{
			mono_field_set_value(monoObj, field, (void*)((char*)il2cppData + offset));
		}
	}
}

void copy_mono_struct_to_il2cpp(MonoObject* monoObj, Il2CppObject* il2cppObj)
{
	if (monoObj == NULL)
	{
		MonoType* type = mono_class_get_type(mono_object_get_class(monoObj));
		MonoClass* klass = mono_class_from_mono_type(type);
		platform_log("mono obj is null when copying struct %d", mono_class_get_name(klass));
		return;
	}
	void* raw_data = (char*)monoObj + sizeof(MonoObject);
	copy_mono_struct_to_il2cpp_raw(raw_data, il2cppObj);
}

void copy_mono_struct_to_il2cpp_raw(void* monoData, Il2CppObject* il2cppObj)
{
	//note: array element in Il2CppArray is not neccesarily an Il2CppObject*, it may be a flat struct type
	Il2CppClass* i2class = il2cpp_object_get_class(il2cppObj);
	const Il2CppType* type = il2cpp_class_get_type(i2class);
	if (monoData == NULL)
	{
		platform_log("mono struct is null when copying struct %d", il2cpp_class_get_name(i2class));
		return;
	}
	void* iter = NULL;
	FieldInfo* field = NULL;
	int align = 0;
	int size = 0;
	while ((field = il2cpp_class_get_fields(i2class, &iter))) {
		const Il2CppType* ftype = il2cpp_field_get_type(field);
		uint32_t offset = il2cpp_field_get_offset(field);
		if (offset < sizeof(Il2CppObject))
		{
			platform_log("copy struct fail, field %s 's offset is %d", il2cpp_class_get_name(il2cpp_class_from_il2cpp_type(ftype)), offset);
			return;
		}
		else
		{
			offset -= sizeof(Il2CppObject);
		}
		if (ftype->type == IL2CPP_TYPE_CLASS) // is_primitive(field_type)) //do a shallow copy
		{
			//size = mono_type_size(field_type, &align);
			MonoObject* monoobj = (MonoObject*)(void*)((char*)monoData + offset);
			Il2CppObject* i2obj = get_il2cpp_object(monoobj, il2cpp_class_from_il2cpp_type(ftype));
			//mono_field_set_value(monoObj, field, monoobj);
			void* fieldaddr = (char*)il2cppObj + offset;
			il2cpp_gc_wbarrier_set_field(il2cppObj, &fieldaddr, i2obj);
		}
		else if (is_struct_type_il2cpp(ftype))
		{
			Il2CppObject** i2obj = NULL;
			get_il2cpp_struct((MonoObject*)((char*)monoData + offset), i2obj, ftype, il2cpp_class_value_size(i2class, NULL)); //get_mono_reflection_type(il2cpp_type_get_object(type))
			if (i2obj != NULL)
			{
				void* fieldaddr = (char*)il2cppObj + offset;
				il2cpp_gc_wbarrier_set_field(il2cppObj, &fieldaddr, *i2obj);
			}
		}
		else
		{
			void* fieldaddr = (char*)il2cppObj + offset;
			il2cpp_gc_wbarrier_set_field(il2cppObj, &fieldaddr, (void*)((char*)monoData + offset));
		}
	}
}

Il2CppObject* get_il2cpp_object(MonoObject* mono, Il2CppClass* m_class)
{
	if (mono == NULL)
		return NULL;

	Il2CppObject* il2cpp = NULL;

	WObjectHead* monoHead = (WObjectHead*)(mono);
	if (monoHead->objectPtr == NULL)
	{
		il2cpp = il2cpp_object_new(m_class);
		bind_mono_il2cpp_object(mono, il2cpp);
		return il2cpp;
		//return NULL;
	}

	return get_il2cpp_object_with_ptr(monoHead->objectPtr);
}

Il2CppObject* get_il2cpp_object_with_ptr(void* objPtr)
{
	if (objPtr == NULL)
		return NULL;

	return (Il2CppObject*)objPtr; // non-compacting gc

	//uint32_t handle = (uint32_t)objPtr;
	//return il2cpp_gchandle_get_target(handle);
}

void* get_il2cpp_internal_ptr(Il2CppObject* obj)
{
	WObjectHead* head = (WObjectHead*)(obj);
	return head->objectPtr;
}
#pragma endregion



MonoString* get_mono_string(Il2CppString* str)
{
    if(str == NULL)
        return NULL;
	/*char* ptr = (char*)str;
	int32_t* lenPtr = (int32_t*)(ptr + sizeof(void *) * 2);
	int32_t len = *lenPtr;
	char* chars = (char*)(ptr + sizeof(void *) * 2 + sizeof(int32_t));*/

	int32_t len = il2cpp_string_length(str);
	Il2CppChar* chars = il2cpp_string_chars(str);

	return mono_string_new_utf16(g_domain, (mono_unichar2*)chars, len);
}
Il2CppString* get_il2cpp_string(MonoString* str)
{
    if(str == NULL)
        return NULL;
    
    int32_t len = mono_string_length(str);
    Il2CppChar* chars = (Il2CppChar* )mono_string_to_utf16(str);

    return  il2cpp_string_new_utf16(chars, len);

}

MonoArray* get_mono_array(Il2CppArray * array)
{
	MonoArray* monoArray = NULL;
	if (array == NULL)
		return monoArray;

	uint32_t len = il2cpp_array_length(array);
	//if (len == 0) //check the array length first
	//	return monoArray;

	Il2CppClass* aklass = il2cpp_object_get_class((Il2CppObject*)array);
	Il2CppClass* eklass = il2cpp_class_get_element_class(aklass);

	if (eklass == NULL)
	{
		platform_log("array class element is not Il2CppObject: %s", il2cpp_class_get_name(aklass));
	}
	
	MonoClass* monoklass = get_mono_class(eklass);
    if(monoklass == NULL)
    {
		platform_log("no match mono class with Il2CppObject: %s[], len: %d", il2cpp_class_get_name(eklass), len);
		if (len > 0) {
			Il2CppObject* il2cppObj = il2cpp_array_get(array, Il2CppObject*, 0);
			MonoObject* monoObj = get_mono_object(il2cppObj, NULL);
			if (monoObj != NULL)
				monoklass = mono_object_get_class(monoObj);
		}
		else
		{
			return monoArray;
		}
    }
		
	monoArray = mono_array_new(g_domain, monoklass, len);
	if (len == 0)
	{
		return monoArray;
	}

	MonoType* monoType = mono_class_get_type(monoklass);
	if (is_primitive(monoType))
	{
		char* _p = il2cpp_array_addr_with_size(array, il2cpp_class_array_element_size(eklass), 0);
		//void** __p = (void**)mono_array_addr((dest), void*, (destidx));
		char* _s = mono_array_addr_with_size((monoArray), mono_class_array_element_size(monoklass), 0);
		mono_gc_wbarrier_value_copy(_s, _p, len, monoklass);
	}
	else if (monoType->type == MONO_TYPE_STRING)
	{
		for (int i = 0; i < len; i++)
		{
			Il2CppString* i2str = il2cpp_array_get(array, Il2CppString*, i);
			MonoString* str = get_mono_string(i2str);
			mono_array_setref(monoArray, i, str);
		}
	}
	else if (is_struct_type(monoType))
	{
		int i2size = il2cpp_class_array_element_size(eklass);
		int32_t monosize = mono_class_array_element_size(monoklass);
		//if (i2size != monosize)
		{
			platform_log("copy struct: %s, monosize-%d, il2size-%d", mono_class_get_name(monoklass), monosize, i2size);
		}
		if (is_full_value_struct_type(monoType))
		{
			//copy sturct from
			
			char* _p = il2cpp_array_addr_with_size(array, il2cpp_class_array_element_size(eklass), 0);
			//void** __p = (void**)mono_array_addr((dest), void*, (destidx));
			char* _s = mono_array_addr_with_size((monoArray), mono_class_array_element_size(monoklass), 0);
			mono_gc_wbarrier_value_copy(_s, _p, len, monoklass);
		}
		else
		{
			//TODO: this is not gc safe, use marshal
			for (int i = 0; i < len; i++)
			{
				//array's struct element is plain data
				char* il2cppObj = il2cpp_array_addr_with_size(array, i2size, i);
				MonoObject* monoObj = mono_object_new(g_domain, monoklass);// get_mono_object(il2cppObj, monoklass);
				copy_il2cpp_struct_to_mono_raw((void*)il2cppObj, monoObj);
				mono_array_setref(monoArray, i, monoObj);
			}
		}
	}
	else
	{
		if (mono_class_is_subclass_of(monoklass, get_wobject_class(), false))
		{
			for (int i = 0; i < len; i++)
			{
				Il2CppObject* il2cppObj = il2cpp_array_get(array, Il2CppObject*, i);
				MonoObject* monoObj = get_mono_object(il2cppObj, monoklass);
				mono_array_setref(monoArray, i, monoObj);
			}
		}
		else
		{
			platform_log("(il2cpp to mono)mono array element class must be subclass of WObject:", mono_class_get_name(monoklass));
		}
	}
	
	return monoArray;
}

Il2CppArray* get_il2cpp_array(MonoArray* array)
{
	Il2CppArray* i2Array = NULL;
	if (array == NULL)
		return i2Array;

	MonoClass *klass = mono_object_get_class((MonoObject*)array);
	MonoClass* eklass = mono_class_get_element_class(klass);
	MonoType *monoType = mono_class_get_type(eklass);
	Il2CppClass* i2klass = get_il2cpp_class(eklass);
	int32_t len = mono_array_length(array);
	i2Array = il2cpp_array_new(i2klass, len);
	if (len == 0)
		return i2Array;

	if (is_primitive(monoType))
	{
		char* _p = il2cpp_array_addr_with_size(i2Array, il2cpp_class_array_element_size(i2klass), 0);
		//void** __p = (void**)mono_array_addr((dest), void*, (destidx));
		char* _s = mono_array_addr_with_size((array), mono_class_array_element_size(klass), 0);
		mono_gc_wbarrier_value_copy(_p, _s, len, eklass); //copy from mono to il2cpp
	}
	else if (monoType->type == MONO_TYPE_STRING) 
	{
		for (int i = 0; i < len; i++)
		{
			MonoString* monoStr = mono_array_get(array, MonoString*, i);
			Il2CppString* str = get_il2cpp_string(monoStr);
			il2cpp_array_setref(i2Array, i, str);
		}
	}
	else if (is_struct_type(monoType))
	{
		int i2size = il2cpp_class_array_element_size(i2klass);
		int32_t monosize = mono_class_array_element_size(eklass);
		//if (i2size != monosize)
		{
			platform_log("copy struct: %s, monosize-%d, il2size-%d", mono_class_get_name(klass), monosize, i2size);
		}
		if (is_full_value_struct_type(monoType))
		{
			//copy sturct from

			char* _p = il2cpp_array_addr_with_size(i2Array, il2cpp_class_array_element_size(i2klass), 0);
			//void** __p = (void**)mono_array_addr((dest), void*, (destidx));
			char* _s = mono_array_addr_with_size((array), mono_class_array_element_size(eklass), 0);
			mono_gc_wbarrier_value_copy(_s, _p, len, eklass);
		}
		else
		{
			
			//TODO: this is not gc safe, use marshal
			for (int i = 0; i < len; i++)
			{
				//array's struct element is plain data
				char* monoObj = mono_array_addr_with_size(array, monosize, i);
				Il2CppObject* il2cppObj = il2cpp_object_new(i2klass);// get_mono_object(il2cppObj, monoklass);
				copy_mono_struct_to_il2cpp_raw((void*)monoObj, il2cppObj);
				il2cpp_array_setref(i2Array, i, monoObj);
			}
		}
	}
	else
	{
		if (mono_class_is_subclass_of(eklass, get_wobject_class(), false))
		{
			for (int i = 0; i < len; i++)
			{
				MonoObject* monoObj = mono_array_get(array, MonoObject*, i);
				Il2CppObject* i2Obj = get_il2cpp_object(monoObj, NULL);
				il2cpp_array_setref(i2Array, i, i2Obj);
			}
		}
		else
		{
			platform_log("(mono to il2cpp)array element class must be subclass of WObject:", mono_class_get_name(eklass));
		}
	}
	
	return i2Array;
}

void copy_array_i2_mono(Il2CppArray* i2_array, MonoArray* mono_array)
{
	int32_t len0 = il2cpp_array_length(i2_array);
	int32_t len1 = mono_array_length(mono_array);

	MonoClass *klass = mono_object_get_class((MonoObject*)mono_array);
	MonoClass *eklass = mono_class_get_element_class(klass);

	for (int i = 0; i < len0 && i< len1; i++)
	{
		Il2CppObject* il2cppObj = il2cpp_array_get(i2_array, Il2CppObject*, i);
		MonoObject* monoObj = get_mono_object(il2cppObj, eklass);
		mono_array_setref(mono_array, i, monoObj);
	}
}
void get_mono_struct(Il2CppObject* i2struct, MonoObject** monoStruct, Il2CppReflectionType* i2type, int32_t i2size)
{
	void* raw_data = (char*)i2struct + sizeof(Il2CppObject);
	get_mono_struct_raw(raw_data, monoStruct, i2type, i2size);
}

void get_mono_struct_raw(void* i2struct, MonoObject** monoStruct, Il2CppReflectionType* i2type, int32_t i2size)
{
	Il2CppClass* i2class = il2cpp_type_get_class_or_element_class(i2type->type);
	if (i2class == NULL)
	{
		char* tname = il2cpp_type_get_name(i2type->type);
		platform_log("the type doesn't exists %s", tname);
		il2cpp_free(tname);
		return;
	}
	MonoClass* klass = get_mono_class(i2class);
	if (klass == NULL || !is_struct(klass))
	{
		platform_log("the return value is not a struct: %s", il2cpp_class_get_name(i2class));
		return;
	}
	int32_t size = mono_class_value_size(klass, NULL);
	if (size != i2size)
	{
		platform_log("the mono and il2cpp struct has differnet length: m-%d, i-%d", size, i2size);
		return;
	}
	if (is_full_value_struct(klass))
	{
		MonoObject* tmp = mono_object_new(g_domain, klass);
		*monoStruct = tmp;
		if (monoStruct != NULL)
		{
			//platform_log("mono full value struct copy: %s, addr:%d, size:%d", mono_class_get_name(klass), i2struct, size);
			mono_gc_wbarrier_value_copy((char*)tmp + sizeof(MonoObject), i2struct, 1, klass);
		}
		else
		{
			platform_log("mono struct new failed: %s", mono_class_get_name(klass));
		}
	}
	else
	{
		MonoObject* tmp = mono_object_new(g_domain, klass);
		*monoStruct = tmp;
		copy_il2cpp_struct_to_mono_raw(i2struct, tmp);
		return;
	}
}

void get_il2cpp_struct(MonoObject* monoStruct, Il2CppObject** i2struct, const Il2CppType* i2type, int32_t msize)
{
	void* raw_data = (char*)monoStruct + sizeof(MonoObject);
	get_il2cpp_struct_raw(raw_data, i2struct, i2type, msize);
}

void get_il2cpp_struct_raw(void* monoStruct, Il2CppObject** i2struct, const Il2CppType* i2type, int32_t msize)
{
	Il2CppClass* i2class = il2cpp_type_get_class_or_element_class(i2type);
	MonoClass* klass = get_mono_class(i2class);
	if (klass == NULL)
	{
		platform_log("the type doesn't exists %s", il2cpp_class_get_name(i2class));
		return;
	}
	//Il2CppClass* i2class = get_il2cpp_class(klass);
	if (klass == NULL || !is_struct(klass))
	{
		platform_log("the return value is not a struct: %s", mono_class_get_name(klass));
		return;
	}
	int32_t size = il2cpp_class_value_size(i2class, NULL);
	if (size != msize)
	{
		platform_log("the mono and il2cpp struct has differnet length: m-%d, i-%d", size, msize);
		return;
	}
	if (is_full_value_struct(klass))
	{
		Il2CppObject* tmp = il2cpp_object_new(i2class);
		*i2struct = tmp;
		if (monoStruct != NULL)
		{
			//platform_log("mono full value struct copy: %s, addr:%d, size:%d", mono_class_get_name(klass), i2struct, size);
			//TODO: to implement
			//mono_gc_wbarrier_value_copy((char*)tmp + sizeof(MonoObject), i2struct, 1, klass);
		}
		else
		{
			platform_log("mono struct new failed: %s", mono_class_get_name(klass));
		}
	}
	else
	{
		Il2CppObject* tmp = il2cpp_object_new(i2class);
		*i2struct = tmp;
		//TODO: to implement
		//copy_il2cpp_struct_to_mono_raw(i2struct, tmp);
		return;
	}
}



bool inline is_struct(MonoClass* klass)
{
	MonoType* type = mono_class_get_type(klass);
	return is_struct_type(type);
}


bool inline is_full_value_struct(MonoClass* klass)
{
	MonoType* type = mono_class_get_type(klass);
	return is_full_value_struct_type(type);
}

bool inline is_full_value_struct_type(MonoType* type)
{
	if (!is_struct_type(type)) {
		return false;
	}
	MonoClass* klass = mono_class_from_mono_type(type);
	gpointer iter = NULL;
	MonoClassField* field = NULL;
	
	while ((field = mono_class_get_fields(klass, &iter))) {
		MonoType* ftype = mono_field_get_type(field);
		MonoClass* fklass = mono_class_from_mono_type(ftype);
#if DEBUG
		//platform_log("check type:%s is full value struct, field:%s, type:%d, name: %s", mono_class_get_name(klass), mono_class_get_name(fklass), ftype->type, mono_field_get_name(field));
#endif
		if (ftype == type)
		{
			continue;
		}

		//enum type has a enum type field in it, this will cause a dead circle
		if (!(is_primitive(ftype) || mono_class_is_enum(fklass) || is_full_value_struct_type(ftype)))
		{
#if DEBUG
			//platform_log("type:%s is not full value struct, field:%s, type:%d", mono_class_get_name(klass), mono_class_get_name(fklass), ftype->type);
#endif
			return false;
		}
	}
	return true;
}

Il2CppClass* get_il2cpp_class(MonoClass* mclass)
{
	const char* ns = mono_class_get_namespace(mclass);
	const char* cname = mono_class_get_name(mclass);
	MonoImage* mimage = mono_class_get_image(mclass);
	const char* asmName = mono_image_get_name(mimage);

	Il2CppClass* il2cppClass = il2cpp_search_class(asmName, ns, cname);
	return il2cppClass;
}

MonoClass* get_mono_class(Il2CppClass* mclass) 
{
	const char* cname = il2cpp_class_get_name(mclass);

	Il2CppClass* dc = il2cpp_class_get_declaring_type(mclass);

	static std::stringstream ss;
	if (dc != NULL)
	{
		ss.str("");
		const char* dtname = il2cpp_class_get_name(dc);
		ss << dtname << '/' << cname;
		mclass = dc;
	}

	const char* ns = il2cpp_class_get_namespace(mclass);
    if(is_wrapper_name_space(ns))
        return NULL;
	
	const Il2CppImage* mimage = il2cpp_class_get_image(mclass);
	const char* asmName = il2cpp_image_get_name(mimage);

	MonoClass* monoClass = NULL;
	
	if (dc != NULL)
	{
		const std::string& tmp = ss.str();
		monoClass = mono_search_class(asmName, ns, tmp.c_str());
	}
	else
	{
		monoClass = mono_search_class(asmName, ns,cname);
	}
	
	return monoClass;
}

Il2CppReflectionType* get_il2cpp_reflection_type(MonoReflectionType * type)
{
	MonoType* monoType = mono_reflection_type_get_type(type);
	MonoClass * mclass = mono_class_from_mono_type(monoType);

	const char* ns = mono_class_get_namespace(mclass);
	const char* cname = mono_class_get_name(mclass);
	MonoImage* mimage = mono_class_get_image(mclass);
	const char* asmName = mono_image_get_name(mimage);

	if (need_monobehaviour_wrap(asmName,mclass))
		return get_monobehaviour_wrapper_rtype();//

	
	//const char* asmName = "Assembly-CSharp.dll";//TODO:the asmName must be same in mono and il2cpp

	Il2CppClass* il2cppClass = il2cpp_search_class(asmName, ns, cname);

	const Il2CppType* ktype = il2cpp_class_get_type(il2cppClass);
	//Il2CppReflectionType* rtype = il2cpp::vm::Reflection::GetTypeObject(ktype);
	Il2CppReflectionType* rtype = (Il2CppReflectionType*)il2cpp_type_get_object(ktype);
	return rtype;
}



MonoReflectionType* get_mono_reflection_type(Il2CppReflectionType * type) 
{
	//TODO: get_mono_reflection_type
	return NULL;
}


MonoImage* mono_get_image(const char* assembly)
{
	MonoAssembly* mono_assembly = load_assembly(assembly, NULL);
	return mono_assembly_get_image(mono_assembly);
}

MonoClass* mono_get_class(MonoImage* image, const char* _namespace, const char* name)
{
	return mono_class_from_name(image, _namespace, name);
}

MonoClass* mono_search_class(const char* assembly, const char* _namespace,
	const char* name)
{
/*
	MonoAssembly* mono_assembly = load_assembly(assembly, NULL);

	//MonoAssemblyName* asm_name = mono_assembly_name_new(assembly);
	//MonoAssembly* mono_assembly = mono_assembly_loaded(asm_name);
	//mono_assembly_name_free(asm_name);

	if (mono_assembly == 0)
	{
		int c = 0;
		//TODO: exception..
	}*/

	MonoImage* image = mono_get_image(assembly);
	MonoClass* klass = mono_get_class(image, _namespace, name);

	if (klass == NULL)
	{
		platform_log("fail to search class %s.%s", _namespace, name);
	}

	return klass;
}


MonoMethod* mono_lookup_method(const char* method_name, MonoClass *kclass, int param_count)
{

	MonoMethod *method = NULL;
	MonoClass *clazz = kclass;
	while (clazz != NULL && method == NULL) {
		method = mono_class_get_method_from_name(clazz, method_name, param_count);
		if (method == NULL)
			clazz = mono_class_get_parent(clazz);
	}


	/*MonoMethodDesc* desc = mono_method_desc_new(method_name, / *include_namespace=* /FALSE);
	if (desc == NULL)
		return NULL;

	MonoMethod* method = mono_method_desc_search_in_class(desc, kclass);
	mono_method_desc_free(desc);*/

	if (!method)
	{
		int c = 0;
		//TODO: exception..
	}

	return method;
}

//Exception:
MonoException* get_mono_exception(Il2CppException* il2cpp)
{
	Il2CppString* trace = (Il2CppString*)il2cpp_exception_property((Il2CppObject*)il2cpp, "get_StackTrace", 1);
	Il2CppString* message = (Il2CppString*)il2cpp_exception_property((Il2CppObject*)il2cpp, "get_Message", 1);

	MonoString* _message = get_mono_string(message);
	MonoString* _stack = get_mono_string(trace);
	platform_log("%s\n%s", _message != NULL ? mono_string_to_utf8(_message) : "", _stack != NULL ? mono_string_to_utf8(_stack) : "");
	//mono will crash when _message or _stack is NULL 
	static MonoString* emptyMsg = mono_string_new_len(g_domain, "empty message", 14);
	//static MonoString* emptyStack = mono_string_new_len(g_domain, "empty stack", 12);

	//mono_exception_from_name_two_strings receive two string as parameters to constructor
	return mono_exception_from_name_two_strings(mono_get_corlib(), "System", "Exception", _message == NULL ? emptyMsg : _message, NULL);

	//MonoString* msg = get_mono_string(trace);
	//Il2CppChar* _message = il2cpp_string_chars(message);
	//Il2CppChar* _trace = il2cpp_string_chars(trace);
	//mono_free(_message);
	//mono_free(_trace);
	//MonoException* exc = mono_exception_from_name_two_strings(mono_get_corlib(), "System", "Exception", msg, NULL);
	//mono_free(msg);
	//return exc;
}
Il2CppException* get_il2cpp_exception(MonoException* mono)
{
	MonoString* trace = (MonoString*)mono_exception_property((MonoObject*)mono, "get_StackTrace", 1);
	MonoString* message = (MonoString*)mono_exception_property((MonoObject*)mono, "get_Message", 1);
	char *traceStr = mono_string_to_utf8(trace);
	char *msgStr = mono_string_to_utf8(message);
	std::string outputMsg = std::string(msgStr);
	if(traceStr != NULL)
		outputMsg += "\n"+ std::string(traceStr);
	Il2CppException* exc = il2cpp_exception_from_name_msg(il2cpp_get_corlib(), "System", "Exception", outputMsg.c_str());

	if (traceStr != NULL)
		mono_free(traceStr);
	mono_free(msgStr);
	return	exc;
}

void check_il2cpp_exception(Il2CppException* il2cpp)
{
	if (il2cpp != NULL)
	{
		MonoException* mono = get_mono_exception(il2cpp);
		mono_raise_exception(mono);
	}
}

void check_mono_exception(MonoException* mono)
{
	if (mono != NULL)
	{
		Il2CppException* il2cpp = get_il2cpp_exception(mono);
		il2cpp_raise_exception(il2cpp);
	}
}

static const char* emptyMsg = "empty message";
void raise_mono_exception_runtime(const char* msg)
{
	MonoException* exc = mono_exception_from_name_msg(mono_get_corlib(), "System", "Exception", msg == NULL ? emptyMsg : msg);
	mono_raise_exception(exc);
	//mono_reraise_exception(exc);
}

void raise_il2cpp_exception_runtime(const char* msg)
{
	Il2CppException* exc = il2cpp_exception_from_name_msg(il2cpp_get_corlib(), "System", "Exception", msg == NULL ? emptyMsg : msg);
	il2cpp_raise_exception(exc);
}

#pragma region WrapperBind


void call_wrapper_init(Il2CppObject* il2cpp, MonoObject* mono)
{
    Il2CppClass* klass = il2cpp_object_get_class(il2cpp);
    
    /*if (!is_wrapper_class(klass))
     return;*/
    
    WrapperHead* il2cppHead = (WrapperHead*)(il2cpp);
    if(il2cppHead->handle != 0)
        mono_gchandle_free(il2cppHead->handle);
    il2cppHead->handle = mono_gchandle_new(mono, FALSE);
    
    if (klass == get_monobehaviour_wrapper_class())
    {
        WObjectHead* monoHead = (WObjectHead*)(mono);
        monoHead->objectPtr = il2cpp;
    }
    
    const MethodInfo* method = il2cpp_class_get_method_from_name(klass, "Init", 0);
    
    //void* args[1] = { il2cpp_value_box(handle) };
    Il2CppException* exc = NULL;
    il2cpp_runtime_invoke(method, il2cpp, NULL, &exc);
    check_il2cpp_exception(exc);
}

//more efficient "get_mono_object" for wrapper
MonoObject* get_mono_wrapper_object(Il2CppObject* il2cpp, MonoClass* m_class)
{
    if (il2cpp == NULL)
        return NULL;
    WrapperHead* il2cppHead = (WrapperHead*)(il2cpp);
    MonoObject* mono = NULL;
    
    int32_t curHandle = il2cppHead->handle;
    
    if (curHandle != 0)
        mono = mono_gchandle_get_target(curHandle);
    
    if (mono == NULL && m_class != NULL)
    {
        mono = mono_object_new(g_domain, m_class);
        mono_runtime_object_init (mono);
        call_wrapper_init(il2cpp, mono);
    }
    return mono;
}

Il2CppClass* get_monobehaviour_wrapper_class()
{
    static Il2CppClass* monobehaviour_wrapper_class;
    if (monobehaviour_wrapper_class == NULL)
    {
        monobehaviour_wrapper_class = il2cpp_search_class("PureScript.dll", "PureScriptWrapper", "MonoBehaviourWrapper");
        //il2cpp_add_flag(monobehaviour_wrapper_class, CLASS_MASK_WRAPPER);
    }
    return monobehaviour_wrapper_class;
}

Il2CppReflectionType* get_monobehaviour_wrapper_rtype()
{
    static Il2CppReflectionType* monobehaviour_wrapper_rtype;
    if (monobehaviour_wrapper_rtype == NULL)
    {
        Il2CppClass* kclass = get_monobehaviour_wrapper_class();
        const Il2CppType* ktype = il2cpp_class_get_type(kclass);
        monobehaviour_wrapper_rtype = (Il2CppReflectionType*)il2cpp_type_get_object(ktype);
    }
    
    return monobehaviour_wrapper_rtype;
}

bool need_monobehaviour_wrap(const char* asm_name, MonoClass* m_class)
{
	static MonoClass* monobehaviour = mono_search_class("UnityEngine.CoreModule.dll", "UnityEngine", "MonoBehaviour");
	if (is_reloadable(asm_name))
	{
		return mono_class_is_subclass_of(m_class, monobehaviour, FALSE);
	}

	return FALSE;
}

#pragma endregion

#pragma region assembly map

static std::map<std::string , const char* > assembly_map;
static std::map<std::string, const char* > reloadable_map;

void insert_assembly_map(const char* src, const char* tar) 
{
	assembly_map[std::string(src)] = tar;
}
void insert_reloadable(const char* assembly, const char* info)
{
	reloadable_map[std::string(assembly)] = info;
}
bool is_reloadable(const char* assembly) 
{
	std::map<std::string, const char*>::iterator res = reloadable_map.find(std::string(assembly));
	if (res != reloadable_map.end())
		return TRUE;

	return FALSE;
}

extern "C" const char* resolve_assembly(const char* request)
{
	std::map<std::string, const char*>::iterator res = assembly_map.find(std::string(request));
	if (res != assembly_map.end())
		return res->second;

	return request;
}

#pragma endregion

#if ENABLE_DEBUG
const char* debug_mono_obj(MonoObject* obj)
{
	if (obj == NULL)
		return NULL;

	int res_size = mono_object_get_size(obj);
	MonoClass *type = mono_object_get_class(obj);
	const char* type_name = mono_class_get_name(type);
	return type_name;
}

const char* debug_mono_method(MonoMethod* method)
{
	if (method == NULL)
		return NULL;

	const char* name = mono_method_get_name(method);
	char* fullname = mono_method_full_name(method,true);
	return fullname;
}

const char* debug_il2cpp_obj(Il2CppObject* obj)
{
	if (obj == NULL)
		return NULL;

	Il2CppClass *type = il2cpp_object_get_class(obj);
	const char* type_name = il2cpp_class_get_name(type);
	return type_name;
}
#endif

