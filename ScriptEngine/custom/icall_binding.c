#include "engine_include.h"
#include "wrapper.h"
#include "mono/metadata/exception.h"

MonoObject* MonoGetObject(void* ptr)
{
	Il2CppObject * i2Obj = (Il2CppObject *)ptr;
	 return get_mono_object_impl(i2Obj, NULL,TRUE);
}

void* MonoStoreObject(MonoObject* obj, void* ptr)
{
	if (ptr == NULL)
	{
		Il2CppClass* i2Class = get_il2cpp_class(mono_object_get_class(obj));
		ptr = get_il2cpp_object(obj, i2Class);
		if (ptr == NULL)
			return NULL;
	}

	bind_mono_il2cpp_object(obj, (Il2CppObject*)ptr);
	return ptr;
}

Il2CppObject* Il2cppGetObject(void* ptr)
{
#if DEBUG
	if (ptr == NULL)
	{
		platform_log("il2cpp object is null");
	}
#endif
	return (Il2CppObject *)ptr;
}
void* Il2cppGetObjectPtr(Il2CppObject * obj)
{
#if DEBUG
	if (obj == NULL)
	{
		platform_log("il2cpp object is null when convert to IntPtr");
	}
#endif
	return obj;
}

void GetReturnArrayToMono(Il2CppArray* ilArray, MonoArray** monoArray)
{
	*monoArray = get_mono_array(ilArray);
#if DEBUG
	platform_log("array length: mono-%d, il2cpp-%d", mono_array_length(*monoArray), il2cpp_array_length(ilArray));
#endif
}

void GetReturnStructToMono(void* i2struct, MonoObject** monoStruct, Il2CppReflectionType* i2type, int32_t i2size)
{
#if DEBUG
	//注意此接口会有内存分配
	
	//char* typename = il2cpp_type_get_name(i2type->type);
	//platform_log("get return struct, addr: %d, name: %s", i2struct, typename);
	//il2cpp_free(typename);
	//platform_log("get return struct, addr: %d, name1: %s", i2struct, il2cpp_class_get_name(il2cpp_object_get_class(i2struct)));
#endif
	get_mono_struct_raw(i2struct, monoStruct, i2type, i2size);
}

Il2CppObject* GetMonoObjectByPtr(void* ptr)
{
	return (MonoObject*)ptr;
}

Il2CppObject* ConvertObjectMonoToIL2Cpp(MonoObject* monoObj)
{
	if (monoObj == NULL)
	{
		return NULL;
	}
	MonoClass* klass = mono_object_get_class(monoObj);
	MonoType* type = mono_class_get_type(klass);
	if (is_primitive(type) || type->type == MONO_TYPE_ENUM)
	{
		Il2CppClass* i2class = get_il2cpp_class(klass);
#if DEBUG
		platform_log("primitive type %s size: mono-%d, il2cpp-%d", mono_class_get_name(klass), mono_class_instance_size(klass), i2class != NULL ? il2cpp_class_instance_size(i2class) : -1);
#endif
		if (i2class == NULL)
		{
			return NULL;
		}
		Il2CppObject* i2obj = il2cpp_object_new(i2class);
		//il2cpp_gc_wbarrier_set_field(i2obj, *((char*)i2obj + sizeof(Il2CppObject)), (char*)monoObj + sizeof(MonoObject));
		memcpy((char*)i2obj + sizeof(Il2CppObject), (char*)monoObj + sizeof(MonoObject), il2cpp_class_instance_size(i2class) - sizeof(Il2CppObject));
		return i2obj;
	}
	else if (type->type == MONO_TYPE_STRING) //string类型
	{
		Il2CppString* str = get_il2cpp_string((MonoString*)monoObj);
		return (Il2CppObject*)str;
	}
	else if (is_struct_type(type))
	{
		Il2CppObject** i2obj = NULL;
		get_il2cpp_struct(monoObj, i2obj, mono_type_get_object(g_domain, type), mono_class_value_size(klass, NULL));
		return i2obj; //struct是by value形式传递，所以不用bind
	}
	else if (type->type == MONO_TYPE_SZARRAY) //
	{
		//TODO: to implement
		MonoClass* eklass = mono_class_get_element_class(klass);
		Il2CppArray* i2Array = get_il2cpp_array((MonoArray*)monoObj);
		//array对象本身不用bind，因为bind element对象就足够了
		/*if (i2Array != NULL)
		{
			bind_mono_il2cpp_object(monoObj, (Il2CppObject*)i2Array);
		}*/
		return (Il2CppObject*)i2Array;
	}
	else if(type->type == MONO_TYPE_CLASS)
	{
		if (mono_class_is_subclass_of(klass, get_wobject_class(), 0))
		{
			Il2CppClass* i2class = get_il2cpp_class(klass);
			WObjectHead* monoHead = (WObjectHead*)(monoObj);
			if (monoHead->objectPtr == NULL)
			{
				platform_log("get il2cpp object from mono fail, type:%s", mono_class_get_name(klass));
				return NULL;
				//return NULL;
			}
			return get_il2cpp_object_with_ptr(monoHead->objectPtr);
		}
		else
		{
			platform_log("array element class must be subclass of WObject: %s", mono_class_get_name(klass));
			return NULL;
		}
	}
	else
	{
		platform_log("convert object mono to il2cpp fail, type not support: %s", mono_class_get_name(klass));
		return NULL;
	}
	
}

static char il2cpp_exception[1024];
static bool caught_il2cpp = 0;
static char mono_exception[1024];
static bool caught_mono = 0;

//note: this function is neccessary, the function stack is in il2cpp at this time
//      should raise mono exception when back to mono
void CatchIL2CppException(Il2CppException* exception)
{
	if (exception == NULL)
	{
		platform_log("il2cpp exception is null");
		return;
	}

	Il2CppString* message = (Il2CppString*)il2cpp_exception_property((Il2CppObject*)exception, "get_Message", 1);
	Il2CppString* trace = (Il2CppString*)il2cpp_exception_property((Il2CppObject*)exception, "get_StackTrace", 1);

	caught_il2cpp = 1;
	MonoString* _message = get_mono_string(message);
	char* _msg = mono_string_to_utf8(_message);
	sprintf_s(il2cpp_exception, sizeof(il2cpp_exception), "%s", _msg);

	mono_free(_msg);
	if (trace != NULL)
	{
		MonoString* _stack = get_mono_string(trace);
		char* _stk = mono_string_to_utf8(_stack);
#if DEBUG
		platform_log("il2cpp exception stack: %s", _stk);
#endif
		mono_free(_stk);
	}
	//MonoString* _stack = get_mono_string(trace);
}


void RaiseMonoExceptionFromIL2Cpp()
{
	if (caught_il2cpp)
	{
		MonoException* exc = mono_exception_from_name_msg(mono_get_corlib(), "System", "Exception", il2cpp_exception);
		caught_il2cpp = 0;
		if (exc != NULL)
		{
			mono_raise_exception(exc);
		}
		else
		{
			platform_log("raise mono exception failed: %s", il2cpp_exception);
		}
	}
}

void CatchMonoException(MonoException* exception)
{
	//raise_mono_exception_runtime(msg);
	if (exception == NULL)
	{
		platform_log("mono exception is null");
		return;
	}
	//mono_exception_property(exception, "");
	MonoString* message = (MonoString*)mono_exception_property((MonoObject*)exception, "get_Message", 1);
	MonoString* trace = (MonoString*)mono_exception_property((MonoObject*)exception, "get_StackTrace", 1);

	caught_mono = 1;
	char* msgStr = mono_string_to_utf8(message);
	char* traceStr = mono_string_to_utf8(trace);
	sprintf_s(mono_exception, sizeof(mono_exception), "%s", msgStr);

	mono_free(msgStr);
#if DEBUG
	platform_log("mono exception: %s", mono_exception);
#endif
	if (traceStr != NULL)
	{
#if DEBUG
		platform_log("il2cpp exception stack: %s", traceStr);
#endif
		mono_free(traceStr);
	}

}

void RaiseIL2CppExceptionFromMono()
{
	if (caught_mono)
	{
		Il2CppException* exc = il2cpp_exception_from_name_msg(il2cpp_get_corlib(), "System", "Exception", mono_exception);
		caught_mono = 0;
		il2cpp_raise_exception(exc);
	}
}

#if __ANDROID__
#include <android/asset_manager.h>
#include <jni.h>
#endif
MonoArray* GetFileBinaryData(MonoObject* this, MonoString* path, void* handle)
{
	int size = 0;
	
#if __ANDROID__
	//JavaVM* vm = GetJavaVm();
	//Assert(vm);
	//JNIEnv* env;
	//int ret = vm->AttachCurrentThread(&env, 0);
	//if (ret == 0)
	//{
	//	//env
	//}
#endif
	MonoArray* data = mono_array_new(g_domain, mono_get_byte_class(), size);
}

/*
MonoObject* NewObject(MonoReflectionType* type)
{
	MonoType* monoType = mono_reflection_type_get_type(type);
	MonoClass * mclass = mono_class_from_mono_type(monoType);
	MonoObject* monoObj = mono_object_new(mono_domain_get(), mclass);
	return monoObj;
}*/

/*
MonoObject* UnityEngine_GameObject_CreatePrimitive(int32_t type)
{

	typedef Il2CppObject * (*ICallMethod) (int32_t);
	static ICallMethod icall;
	if (!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.GameObject::CreatePrimitive");
	Il2CppObject* il2cppObj = icall(type);
	
	MonoClass* m_class = mono_search_class("UnityEngine.CoreModule.dll", "UnityEngine", "GameObject");

	MonoObject* monoObj = get_mono_object(il2cppObj, m_class);
	return monoObj;
}*/

/*
void UnityEngine_DebugLogHandler_Internal_Log(int32_t logType, MonoString* str, MonoObject* obj)
{
	typedef void (*ICallMethod) (int32_t, Il2CppString*, Il2CppObject *);
	static ICallMethod icall;
	if (!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.DebugLogHandler::Internal_Log(UnityEngine.LogType,System.String,UnityEngine.Object)");
	icall(logType, get_il2cpp_string(str),obj);
	return ;
}*/

/*
MonoObject* UnityEngine_GameObject_get_transform(MonoObject* monoObj)
{
	typedef Il2CppObject * (*GameObject_get_transform) (Il2CppObject *);
	static GameObject_get_transform icall;
	if(!icall)
		icall = (GameObject_get_transform)il2cpp_resolve_icall("UnityEngine.GameObject::get_transform()");

	Il2CppObject * il2cppObj = get_il2cpp_object(monoObj);
	Il2CppObject * newObj = icall(il2cppObj);

	MonoClass* m_class = mono_search_class("UnityEngine.CoreModule.dll", "UnityEngine", "Transform");
	MonoObject* newMonoObj = get_mono_object(newObj, m_class);
	return newMonoObj;
}*/
/*
MonoObject* UnityEngine_Component_get_transform(MonoObject* monoObj)
{
	typedef Il2CppObject * (*Component_get_transform) (Il2CppObject *);
	static Component_get_transform icall;
	if (!icall)
		icall = (Component_get_transform)il2cpp_resolve_icall("UnityEngine.Component::get_transform()");

	Il2CppObject * il2cppObj = get_il2cpp_object(monoObj);
	Il2CppObject * newObj = icall(il2cppObj);

	MonoClass* m_class = mono_search_class("UnityEngine.CoreModule.dll", "UnityEngine", "Transform");
	MonoObject* newMonoObj = get_mono_object(newObj, m_class);
	return newMonoObj;
}*/

/*
MonoObject* UnityEngine_Component_get_gameobject(MonoObject* monoObj)
{
	typedef Il2CppObject * (*Component_get_transform) (Il2CppObject *);
	static Component_get_transform icall;
	if (!icall)
		icall = (Component_get_transform)il2cpp_resolve_icall("UnityEngine.Component::get_gameObject");

	Il2CppObject * il2cppObj = get_il2cpp_object(monoObj);
	Il2CppObject * newObj = icall(il2cppObj);

	MonoClass* m_class = mono_search_class("UnityEngine.CoreModule.dll", "UnityEngine", "GameObject");
	MonoObject* newMonoObj = get_mono_object(newObj, m_class);
	return newMonoObj;
}*/

/*
void UnityEngine_Transform_set_position_Injected(MonoObject* _thiz ,void* pos)
{
	typedef void (*Transform_set_position) (Il2CppObject*, void*);
	static Transform_set_position icall;
	if (!icall)
		icall = (Transform_set_position)il2cpp_resolve_icall("UnityEngine.Transform::set_position_Injected(UnityEngine.Vector3&)");

	Il2CppObject* il2cppObj = get_il2cpp_object(_thiz);

	icall(il2cppObj, pos);
	return;
}*/

/*
void UnityEngine_Transform_get_position_Injected(MonoObject* _thiz, void* pos)
{
	typedef void(*Transform_get_position) (Il2CppObject*, void*);
	static Transform_get_position icall;
	if (!icall)
		icall = (Transform_get_position)il2cpp_resolve_icall("UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)");

	Il2CppObject* il2cppObj = get_il2cpp_object(_thiz);

	icall(il2cppObj, pos);
	return;
}*/

/*
MonoString* UnityEngine_Object_GetName(MonoObject* obj)
{
	typedef Il2CppString* (*Transform_set_position) (Il2CppObject*);
	static Transform_set_position icall;
	if (!icall)
		icall = (Transform_set_position)il2cpp_resolve_icall("UnityEngine.Object::GetName(UnityEngine.Object)");

	Il2CppObject* il2cppObj = get_il2cpp_object(obj);
	Il2CppString* res = icall(il2cppObj);
	MonoString* monoStr = get_mono_string(res);
	return monoStr;
}*/

/*
float UnityEngine_Time_Get_deltaTime()
{
	typedef float (*Time_Get_deltaTime) ();
	static Time_Get_deltaTime icall;
	if (!icall)
		icall = (Time_Get_deltaTime)il2cpp_resolve_icall("UnityEngine.Time::get_deltaTime()");

	float res = icall();
	return res;
}*/
/*
float UnityEngine_Time_GetTime()
{
	typedef float(*Time_Get_deltaTime) ();
	static Time_Get_deltaTime icall;
	if (!icall)
		icall = (Time_Get_deltaTime)il2cpp_resolve_icall("UnityEngine.Time::get_time()");

	float res = icall();
	return res;
}*/

MonoObject* UnityEngine_GameObject_Internal_AddComponentWithType(MonoObject* obj, MonoReflectionType* type)
{
	typedef Il2CppObject* (*AddComponentWithType) (Il2CppObject*, Il2CppReflectionType*);
	static AddComponentWithType icall;
	if (!icall)
		icall = (AddComponentWithType)il2cpp_resolve_icall("UnityEngine.GameObject::Internal_AddComponentWithType");

	Il2CppObject* il2cppObj = get_il2cpp_object(obj,NULL);
	
	MonoType* monoType = mono_reflection_type_get_type(type);
	MonoClass * mclass = mono_class_from_mono_type(monoType);

	Il2CppReflectionType* il2cppType = get_il2cpp_reflection_type(type);

	Il2CppObject* res = icall(il2cppObj, il2cppType);

	MonoObject* monoObj = get_mono_object(res, mclass);

	return monoObj;
}

MonoArray* UnityEngine_GameObject_GetComponentsInternal(MonoObject* obj, MonoReflectionType* type, bool useSearchTypeAsArrayReturnType, bool recursive, bool includeInactive, bool reverse, MonoObject* resultList)
{
	typedef Il2CppArray* (*GetComponentsInternal) (Il2CppObject*, Il2CppReflectionType*, bool , bool , bool , bool , Il2CppObject* );
	static GetComponentsInternal icall;
	if (!icall)
		icall = (GetComponentsInternal)il2cpp_resolve_icall("UnityEngine.GameObject::GetComponentsInternal");

	Il2CppObject* il2cppObj = get_il2cpp_object(obj, NULL);
	Il2CppReflectionType* il2cppType = get_il2cpp_reflection_type(type);
	
	if (il2cppObj == NULL || il2cppType == NULL)
	{
		platform_log("type not found: %s", mono_class_get_name(mono_class_from_mono_type(mono_reflection_type_get_type(type))));
	}
	Il2CppArray* res = icall(il2cppObj, il2cppType, useSearchTypeAsArrayReturnType, recursive, includeInactive, reverse, NULL);//resultList

	MonoArray* monoRes = get_mono_array(res);
	return monoRes;
}

void UnityEngine_GameObject_GetComponentFastPath(MonoObject* obj, MonoReflectionType* type, intptr_t ptr)
{
	MonoType* monoType = mono_reflection_type_get_type(type);
	MonoClass * mclass = mono_class_from_mono_type(monoType);
	//ptr = *ptr;
	void* objPtr = (char*)ptr - sizeof(void*);
	//objPtr = NULL;

	MonoArray* objs = UnityEngine_GameObject_GetComponentsInternal(obj, type, TRUE, FALSE, TRUE, FALSE, NULL);

	if (objs != NULL)
	{
		size_t len = mono_array_length(objs);

		for (int i = 0; i < len; i++)
		{
			MonoObject* monoObj = mono_array_get(objs, MonoObject*, i);
			if (monoObj == NULL)
				continue;
			MonoClass * tclass = mono_object_get_class(monoObj);
			if (mono_object_isinst(monoObj, mclass))
			{
				mono_gc_wbarrier_generic_store(objPtr, monoObj);
				break;
			}
		}
	}
}

MonoObject* UnityEngine_Component_get_gameObject(MonoObject* thiz);

void UnityEngine_Component_GetComponentFastPath(MonoObject* obj, MonoReflectionType* type, intptr_t ptr)
{
	MonoObject* gameObj = UnityEngine_Component_get_gameObject(obj);
	UnityEngine_GameObject_GetComponentFastPath(gameObj, type, ptr);
}

/*
bool UnityEngine_MonoBehaviour_IsObjectMonoBehaviour(MonoObject* obj)
{
	Il2CppObject* il2cpp = get_il2cpp_object(obj);

	typedef bool(*IsObjectMonoBehaviour) (Il2CppObject*);
	static IsObjectMonoBehaviour icall;
	if (!icall)
		icall = (IsObjectMonoBehaviour)il2cpp_resolve_icall("UnityEngine.MonoBehaviour::IsObjectMonoBehaviour");

	bool res = icall(il2cpp);
	return res;
}*/

MonoObject* UnityEngine_MonoBehaviour_StartCoroutineManaged2(MonoObject* obj,MonoObject* enumerator)
{
	Il2CppObject* il2cpp = get_il2cpp_object(obj, NULL);

	typedef Il2CppObject*(*StartCoroutineManaged2) (Il2CppObject*, Il2CppObject*);
	static StartCoroutineManaged2 icall;
	if (!icall)
		icall = (StartCoroutineManaged2)il2cpp_resolve_icall("UnityEngine.MonoBehaviour::StartCoroutineManaged2");

	Il2CppObject* il2cppEnum = create_il2cpp_enumerator_wrapper(enumerator);

	Il2CppObject* res = icall(il2cpp, il2cppEnum);

	MonoClass* m_class = get_coroutine_class();
	MonoObject* newMonoObj = get_mono_object(res, m_class);
	
	return newMonoObj;
}

void UnityEngine_Coroutine_ReleaseCoroutine(void* ptr)
{
	typedef void(*ReleaseCoroutine) (void*);
	static ReleaseCoroutine icall;
	if (!icall)
		icall = (ReleaseCoroutine)il2cpp_resolve_icall("UnityEngine.Coroutine::ReleaseCoroutine");

	/*Il2CppObject* il2cppObj = get_il2cpp_object_with_ptr(ptr);
	void* internal_ptr = get_il2cpp_internal_ptr(il2cppObj);*/

	icall(ptr);
	return;
}

/*
void UnityEngine_Application_SetLogCallbackDefined(bool defined)
{

	typedef void(*SetLogCallbackDefined) (bool);
	static SetLogCallbackDefined icall;
	if (!icall)
		icall = (SetLogCallbackDefined)il2cpp_resolve_icall("UnityEngine.Application::SetLogCallbackDefined");

	icall(defined);
}*/
/*
MonoString* UnityEngine_Application_get_persistentDataPath()
{

	typedef Il2CppString* (*get_persistentDataPath) ();
	static get_persistentDataPath icall;
	if (!icall)
		icall = (get_persistentDataPath)il2cpp_resolve_icall("UnityEngine.Application::get_persistentDataPath");

	Il2CppString* res = icall();
	MonoString* monoRes = get_mono_string(res);
	return monoRes;
}*/

void init_event();
void regist_icall_gen();
void mono_register_icall(void)
{
	init_il2cpp();
	init_wrapper();
	init_event();

	regist_icall_gen();
	

	il2cpp_add_internal_call("ObjectStore::GetObject", (Il2CppMethodPointer)Il2cppGetObject);
	il2cpp_add_internal_call("ObjectStore::GetObjectPtr", (Il2CppMethodPointer)Il2cppGetObjectPtr);

	il2cpp_add_internal_call("ObjectStore::GetReturnArrayToMono", (Il2CppMethodPointer)GetReturnArrayToMono);
	il2cpp_add_internal_call("ObjectStore::GetReturnStructToMono", (Il2CppMethodPointer)GetReturnStructToMono);

	il2cpp_add_internal_call("PureScript.ScriptEngine::OnException", (Il2CppMethodPointer)CatchIL2CppException);
	il2cpp_add_internal_call("PureScript.ScriptEngine::CheckException", (Il2CppMethodPointer)RaiseIL2CppExceptionFromMono);

	mono_add_internal_call("ObjectStore::GetObject", MonoGetObject);
	mono_add_internal_call("ObjectStore::StoreObject", MonoStoreObject);
	mono_add_internal_call("ObjectStore::GetMonoObjectByPtr", GetMonoObjectByPtr);

	mono_add_internal_call("ObjectStore::ConvertObjectMonoToIL2Cpp", ConvertObjectMonoToIL2Cpp);

	mono_add_internal_call("PureScript.Mono.ScriptEngine::OnException", CatchMonoException);
	mono_add_internal_call("PureScript.Mono.ScriptEngine::CheckException", RaiseMonoExceptionFromIL2Cpp);


	//Aono_add_internal_call("UnityEngine.GameObject::CreatePrimitive", (void*)UnityEngine_GameObject_CreatePrimitive);
	//Aono_add_internal_call("UnityEngine.DebugLogHandler::Internal_Log", (void*)UnityEngine_DebugLogHandler_Internal_Log);
	//Aono_add_internal_call("UnityEngine.GameObject::get_transform", (void*)UnityEngine_GameObject_get_transform);
	//Aono_add_internal_call("UnityEngine.Component::get_transform", (void*)UnityEngine_Component_get_transform);
	//Aono_add_internal_call("UnityEngine.Component::get_gameObject", (void*)UnityEngine_Component_get_gameobject);

	//Aono_add_internal_call("UnityEngine.Transform::set_position_Injected", (void*)UnityEngine_Transform_set_position_Injected);
	//Aono_add_internal_call("UnityEngine.Transform::get_position_Injected", (void*)UnityEngine_Transform_get_position_Injected);

	//Aono_add_internal_call("UnityEngine.Object::GetName", (void*)UnityEngine_Object_GetName);
	//Aono_add_internal_call("UnityEngine.Time::get_deltaTime", (void*)UnityEngine_Time_Get_deltaTime);
	//Aono_add_internal_call("UnityEngine.Time::get_time", (void*)UnityEngine_Time_GetTime);
	
	
	mono_add_internal_call("UnityEngine.GameObject::Internal_AddComponentWithType", (void*)UnityEngine_GameObject_Internal_AddComponentWithType);
	mono_add_internal_call("UnityEngine.GameObject::GetComponentFastPath", (void*)UnityEngine_GameObject_GetComponentFastPath);
	mono_add_internal_call("UnityEngine.Component::GetComponentFastPath", (void*)UnityEngine_Component_GetComponentFastPath);
	mono_add_internal_call("UnityEngine.GameObject::GetComponentsInternal", (void*)UnityEngine_GameObject_GetComponentsInternal);

	//Aono_add_internal_call("UnityEngine.MonoBehaviour::IsObjectMonoBehaviour", (void*)UnityEngine_MonoBehaviour_IsObjectMonoBehaviour);
	mono_add_internal_call("UnityEngine.MonoBehaviour::StartCoroutineManaged2", (void*)UnityEngine_MonoBehaviour_StartCoroutineManaged2);
	mono_add_internal_call("UnityEngine.Coroutine::ReleaseCoroutine", (void*)UnityEngine_Coroutine_ReleaseCoroutine);
	
	//Aono_add_internal_call("UnityEngine.Application::SetLogCallbackDefined", (void*)UnityEngine_Application_SetLogCallbackDefined);
	//Aono_add_internal_call("UnityEngine.Application::get_persistentDataPath", (void*)UnityEngine_Application_get_persistentDataPath);
	

}
