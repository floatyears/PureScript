
#include "engine_include.h"
#include "class_cache_gen.h"
void register_assembly_map()
{
	insert_reloadable("Scripts", NULL);
}
int32_t UnityEngine_AI_NavMeshAgent_get_pathStatus(MonoObject* thiz)
{
	typedef int32_t (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AI.NavMeshAgent::get_pathStatus");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_AI_NavMeshAgent());
	int32_t i2res = icall(i2thiz);
	return i2res;
}
void UnityEngine_AI_NavMeshAgent_set_isStopped(MonoObject* thiz, bool value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, bool value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AI.NavMeshAgent::set_isStopped");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_AI_NavMeshAgent());
	icall(i2thiz,value);
}
void UnityEngine_AI_NavMeshAgent_set_speed(MonoObject* thiz, float value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, float value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AI.NavMeshAgent::set_speed");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_AI_NavMeshAgent());
	icall(i2thiz,value);
}
void UnityEngine_AI_NavMeshAgent_set_angularSpeed(MonoObject* thiz, float value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, float value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AI.NavMeshAgent::set_angularSpeed");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_AI_NavMeshAgent());
	icall(i2thiz,value);
}
void UnityEngine_AI_NavMeshAgent_set_acceleration(MonoObject* thiz, float value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, float value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AI.NavMeshAgent::set_acceleration");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_AI_NavMeshAgent());
	icall(i2thiz,value);
}
void UnityEngine_AI_NavMeshAgent_set_updatePosition(MonoObject* thiz, bool value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, bool value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AI.NavMeshAgent::set_updatePosition");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_AI_NavMeshAgent());
	icall(i2thiz,value);
}
void UnityEngine_AI_NavMeshAgent_set_updateRotation(MonoObject* thiz, bool value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, bool value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AI.NavMeshAgent::set_updateRotation");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_AI_NavMeshAgent());
	icall(i2thiz,value);
}
void UnityEngine_AI_NavMeshAgent_set_radius(MonoObject* thiz, float value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, float value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AI.NavMeshAgent::set_radius");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_AI_NavMeshAgent());
	icall(i2thiz,value);
}
bool UnityEngine_AI_NavMeshAgent_SetDestination_Injected(MonoObject* thiz, void * target)
{
	typedef bool (* ICallMethod) (Il2CppObject* thiz, void * target);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AI.NavMeshAgent::SetDestination_Injected");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_AI_NavMeshAgent());
	bool i2res = icall(i2thiz,target);
	return i2res;
}
bool UnityEngine_AI_NavMeshAgent_Warp_Injected(MonoObject* thiz, void * newPosition)
{
	typedef bool (* ICallMethod) (Il2CppObject* thiz, void * newPosition);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AI.NavMeshAgent::Warp_Injected");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_AI_NavMeshAgent());
	bool i2res = icall(i2thiz,newPosition);
	return i2res;
}
bool UnityEngine_AI_NavMesh_SamplePosition_Injected(void * sourcePosition, void * hit, float maxDistance, int32_t areaMask)
{
	typedef bool (* ICallMethod) (void * sourcePosition, void * hit, float maxDistance, int32_t areaMask);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AI.NavMesh::SamplePosition_Injected");
	bool i2res = icall(sourcePosition,hit,maxDistance,areaMask);
	return i2res;
}
bool UnityEngine_AndroidJNIHelper_get_debug()
{
	typedef bool (* ICallMethod) ();
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNIHelper::get_debug");
	bool i2res = icall();
	return i2res;
}
void UnityEngine_AndroidJNIHelper_set_debug(bool value)
{
	typedef void (* ICallMethod) (bool value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNIHelper::set_debug");
	icall(value);
}
int32_t UnityEngine_AndroidJNI_AttachCurrentThread()
{
	typedef int32_t (* ICallMethod) ();
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::AttachCurrentThread");
	int32_t i2res = icall();
	return i2res;
}
int32_t UnityEngine_AndroidJNI_DetachCurrentThread()
{
	typedef int32_t (* ICallMethod) ();
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::DetachCurrentThread");
	int32_t i2res = icall();
	return i2res;
}
int32_t UnityEngine_AndroidJNI_GetVersion()
{
	typedef int32_t (* ICallMethod) ();
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::GetVersion");
	int32_t i2res = icall();
	return i2res;
}
void * UnityEngine_AndroidJNI_FindClass(MonoString* name)
{
	typedef void * (* ICallMethod) (Il2CppString* name);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::FindClass");
	Il2CppString* i2name = get_il2cpp_string(name);
	void * i2res = icall(i2name);
	if(i2res != NULL && i2res == NULL)
	{
		platform_log("UnityEngine.AndroidJNI::FindClass fail to convert il2cpp obj to mono");
	}
	return i2res;
}
void * UnityEngine_AndroidJNI_FromReflectedMethod(void * refMethod)
{
	typedef void * (* ICallMethod) (void * refMethod);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::FromReflectedMethod");
	void * i2res = icall(refMethod);
	if(i2res != NULL && i2res == NULL)
	{
		platform_log("UnityEngine.AndroidJNI::FromReflectedMethod fail to convert il2cpp obj to mono");
	}
	return i2res;
}
void * UnityEngine_AndroidJNI_FromReflectedField(void * refField)
{
	typedef void * (* ICallMethod) (void * refField);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::FromReflectedField");
	void * i2res = icall(refField);
	if(i2res != NULL && i2res == NULL)
	{
		platform_log("UnityEngine.AndroidJNI::FromReflectedField fail to convert il2cpp obj to mono");
	}
	return i2res;
}
void * UnityEngine_AndroidJNI_ToReflectedMethod(void * clazz, void * methodID, bool isStatic)
{
	typedef void * (* ICallMethod) (void * clazz, void * methodID, bool isStatic);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::ToReflectedMethod");
	void * i2res = icall(clazz,methodID,isStatic);
	if(i2res != NULL && i2res == NULL)
	{
		platform_log("UnityEngine.AndroidJNI::ToReflectedMethod fail to convert il2cpp obj to mono");
	}
	return i2res;
}
void * UnityEngine_AndroidJNI_ToReflectedField(void * clazz, void * fieldID, bool isStatic)
{
	typedef void * (* ICallMethod) (void * clazz, void * fieldID, bool isStatic);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::ToReflectedField");
	void * i2res = icall(clazz,fieldID,isStatic);
	if(i2res != NULL && i2res == NULL)
	{
		platform_log("UnityEngine.AndroidJNI::ToReflectedField fail to convert il2cpp obj to mono");
	}
	return i2res;
}
void * UnityEngine_AndroidJNI_GetSuperclass(void * clazz)
{
	typedef void * (* ICallMethod) (void * clazz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::GetSuperclass");
	void * i2res = icall(clazz);
	if(i2res != NULL && i2res == NULL)
	{
		platform_log("UnityEngine.AndroidJNI::GetSuperclass fail to convert il2cpp obj to mono");
	}
	return i2res;
}
bool UnityEngine_AndroidJNI_IsAssignableFrom(void * clazz1, void * clazz2)
{
	typedef bool (* ICallMethod) (void * clazz1, void * clazz2);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::IsAssignableFrom");
	bool i2res = icall(clazz1,clazz2);
	return i2res;
}
int32_t UnityEngine_AndroidJNI_Throw(void * obj)
{
	typedef int32_t (* ICallMethod) (void * obj);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::Throw");
	int32_t i2res = icall(obj);
	return i2res;
}
int32_t UnityEngine_AndroidJNI_ThrowNew(void * clazz, MonoString* message)
{
	typedef int32_t (* ICallMethod) (void * clazz, Il2CppString* message);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::ThrowNew");
	Il2CppString* i2message = get_il2cpp_string(message);
	int32_t i2res = icall(clazz,i2message);
	return i2res;
}
void * UnityEngine_AndroidJNI_ExceptionOccurred()
{
	typedef void * (* ICallMethod) ();
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::ExceptionOccurred");
	void * i2res = icall();
	if(i2res != NULL && i2res == NULL)
	{
		platform_log("UnityEngine.AndroidJNI::ExceptionOccurred fail to convert il2cpp obj to mono");
	}
	return i2res;
}
void UnityEngine_AndroidJNI_ExceptionDescribe()
{
	typedef void (* ICallMethod) ();
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::ExceptionDescribe");
	icall();
}
void UnityEngine_AndroidJNI_ExceptionClear()
{
	typedef void (* ICallMethod) ();
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::ExceptionClear");
	icall();
}
void UnityEngine_AndroidJNI_FatalError(MonoString* message)
{
	typedef void (* ICallMethod) (Il2CppString* message);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::FatalError");
	Il2CppString* i2message = get_il2cpp_string(message);
	icall(i2message);
}
int32_t UnityEngine_AndroidJNI_PushLocalFrame(int32_t capacity)
{
	typedef int32_t (* ICallMethod) (int32_t capacity);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::PushLocalFrame");
	int32_t i2res = icall(capacity);
	return i2res;
}
void * UnityEngine_AndroidJNI_PopLocalFrame(void * ptr)
{
	typedef void * (* ICallMethod) (void * ptr);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::PopLocalFrame");
	void * i2res = icall(ptr);
	if(i2res != NULL && i2res == NULL)
	{
		platform_log("UnityEngine.AndroidJNI::PopLocalFrame fail to convert il2cpp obj to mono");
	}
	return i2res;
}
void * UnityEngine_AndroidJNI_NewGlobalRef(void * obj)
{
	typedef void * (* ICallMethod) (void * obj);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::NewGlobalRef");
	void * i2res = icall(obj);
	if(i2res != NULL && i2res == NULL)
	{
		platform_log("UnityEngine.AndroidJNI::NewGlobalRef fail to convert il2cpp obj to mono");
	}
	return i2res;
}
void UnityEngine_AndroidJNI_DeleteGlobalRef(void * obj)
{
	typedef void (* ICallMethod) (void * obj);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::DeleteGlobalRef");
	icall(obj);
}
void * UnityEngine_AndroidJNI_NewWeakGlobalRef(void * obj)
{
	typedef void * (* ICallMethod) (void * obj);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::NewWeakGlobalRef");
	void * i2res = icall(obj);
	if(i2res != NULL && i2res == NULL)
	{
		platform_log("UnityEngine.AndroidJNI::NewWeakGlobalRef fail to convert il2cpp obj to mono");
	}
	return i2res;
}
void UnityEngine_AndroidJNI_DeleteWeakGlobalRef(void * obj)
{
	typedef void (* ICallMethod) (void * obj);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::DeleteWeakGlobalRef");
	icall(obj);
}
void * UnityEngine_AndroidJNI_NewLocalRef(void * obj)
{
	typedef void * (* ICallMethod) (void * obj);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::NewLocalRef");
	void * i2res = icall(obj);
	if(i2res != NULL && i2res == NULL)
	{
		platform_log("UnityEngine.AndroidJNI::NewLocalRef fail to convert il2cpp obj to mono");
	}
	return i2res;
}
void UnityEngine_AndroidJNI_DeleteLocalRef(void * obj)
{
	typedef void (* ICallMethod) (void * obj);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::DeleteLocalRef");
	icall(obj);
}
bool UnityEngine_AndroidJNI_IsSameObject(void * obj1, void * obj2)
{
	typedef bool (* ICallMethod) (void * obj1, void * obj2);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::IsSameObject");
	bool i2res = icall(obj1,obj2);
	return i2res;
}
int32_t UnityEngine_AndroidJNI_EnsureLocalCapacity(int32_t capacity)
{
	typedef int32_t (* ICallMethod) (int32_t capacity);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::EnsureLocalCapacity");
	int32_t i2res = icall(capacity);
	return i2res;
}
void * UnityEngine_AndroidJNI_AllocObject(void * clazz)
{
	typedef void * (* ICallMethod) (void * clazz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::AllocObject");
	void * i2res = icall(clazz);
	if(i2res != NULL && i2res == NULL)
	{
		platform_log("UnityEngine.AndroidJNI::AllocObject fail to convert il2cpp obj to mono");
	}
	return i2res;
}
void * UnityEngine_AndroidJNI_NewObject(void * clazz, void * methodID, void* args)
{
	typedef void * (* ICallMethod) (void * clazz, void * methodID, void* args);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::NewObject");
	void * i2res = icall(clazz,methodID,args);
	if(i2res != NULL && i2res == NULL)
	{
		platform_log("UnityEngine.AndroidJNI::NewObject fail to convert il2cpp obj to mono");
	}
	return i2res;
}
void * UnityEngine_AndroidJNI_GetObjectClass(void * obj)
{
	typedef void * (* ICallMethod) (void * obj);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::GetObjectClass");
	void * i2res = icall(obj);
	if(i2res != NULL && i2res == NULL)
	{
		platform_log("UnityEngine.AndroidJNI::GetObjectClass fail to convert il2cpp obj to mono");
	}
	return i2res;
}
bool UnityEngine_AndroidJNI_IsInstanceOf(void * obj, void * clazz)
{
	typedef bool (* ICallMethod) (void * obj, void * clazz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::IsInstanceOf");
	bool i2res = icall(obj,clazz);
	return i2res;
}
void * UnityEngine_AndroidJNI_GetMethodID(void * clazz, MonoString* name, MonoString* sig)
{
	typedef void * (* ICallMethod) (void * clazz, Il2CppString* name, Il2CppString* sig);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::GetMethodID");
	Il2CppString* i2name = get_il2cpp_string(name);
	Il2CppString* i2sig = get_il2cpp_string(sig);
	void * i2res = icall(clazz,i2name,i2sig);
	if(i2res != NULL && i2res == NULL)
	{
		platform_log("UnityEngine.AndroidJNI::GetMethodID fail to convert il2cpp obj to mono");
	}
	return i2res;
}
void * UnityEngine_AndroidJNI_GetFieldID(void * clazz, MonoString* name, MonoString* sig)
{
	typedef void * (* ICallMethod) (void * clazz, Il2CppString* name, Il2CppString* sig);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::GetFieldID");
	Il2CppString* i2name = get_il2cpp_string(name);
	Il2CppString* i2sig = get_il2cpp_string(sig);
	void * i2res = icall(clazz,i2name,i2sig);
	if(i2res != NULL && i2res == NULL)
	{
		platform_log("UnityEngine.AndroidJNI::GetFieldID fail to convert il2cpp obj to mono");
	}
	return i2res;
}
void * UnityEngine_AndroidJNI_GetStaticMethodID(void * clazz, MonoString* name, MonoString* sig)
{
	typedef void * (* ICallMethod) (void * clazz, Il2CppString* name, Il2CppString* sig);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::GetStaticMethodID");
	Il2CppString* i2name = get_il2cpp_string(name);
	Il2CppString* i2sig = get_il2cpp_string(sig);
	void * i2res = icall(clazz,i2name,i2sig);
	if(i2res != NULL && i2res == NULL)
	{
		platform_log("UnityEngine.AndroidJNI::GetStaticMethodID fail to convert il2cpp obj to mono");
	}
	return i2res;
}
void * UnityEngine_AndroidJNI_GetStaticFieldID(void * clazz, MonoString* name, MonoString* sig)
{
	typedef void * (* ICallMethod) (void * clazz, Il2CppString* name, Il2CppString* sig);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::GetStaticFieldID");
	Il2CppString* i2name = get_il2cpp_string(name);
	Il2CppString* i2sig = get_il2cpp_string(sig);
	void * i2res = icall(clazz,i2name,i2sig);
	if(i2res != NULL && i2res == NULL)
	{
		platform_log("UnityEngine.AndroidJNI::GetStaticFieldID fail to convert il2cpp obj to mono");
	}
	return i2res;
}
void * UnityEngine_AndroidJNI_NewStringFromStr(MonoString* chars)
{
	typedef void * (* ICallMethod) (Il2CppString* chars);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::NewStringFromStr");
	Il2CppString* i2chars = get_il2cpp_string(chars);
	void * i2res = icall(i2chars);
	if(i2res != NULL && i2res == NULL)
	{
		platform_log("UnityEngine.AndroidJNI::NewStringFromStr fail to convert il2cpp obj to mono");
	}
	return i2res;
}
void * UnityEngine_AndroidJNI_NewString(MonoArray* chars)
{
	typedef void * (* ICallMethod) (Il2CppArray* chars);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::NewString");
	Il2CppArray* i2chars = get_il2cpp_array(chars);
	void * i2res = icall(i2chars);
	if(i2res != NULL && i2res == NULL)
	{
		platform_log("UnityEngine.AndroidJNI::NewString fail to convert il2cpp obj to mono");
	}
	return i2res;
}
void * UnityEngine_AndroidJNI_NewStringUTF(MonoString* bytes)
{
	typedef void * (* ICallMethod) (Il2CppString* bytes);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::NewStringUTF");
	Il2CppString* i2bytes = get_il2cpp_string(bytes);
	void * i2res = icall(i2bytes);
	if(i2res != NULL && i2res == NULL)
	{
		platform_log("UnityEngine.AndroidJNI::NewStringUTF fail to convert il2cpp obj to mono");
	}
	return i2res;
}
MonoString* UnityEngine_AndroidJNI_GetStringChars(void * str)
{
	typedef Il2CppString* (* ICallMethod) (void * str);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::GetStringChars");
	Il2CppString* i2res = icall(str);
	MonoString* monoi2res = get_mono_string(i2res);
	if(i2res != NULL && monoi2res == NULL)
	{
		platform_log("UnityEngine.AndroidJNI::GetStringChars fail to convert il2cpp obj to mono");
	}
	return monoi2res;
}
int32_t UnityEngine_AndroidJNI_GetStringLength(void * str)
{
	typedef int32_t (* ICallMethod) (void * str);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::GetStringLength");
	int32_t i2res = icall(str);
	return i2res;
}
int32_t UnityEngine_AndroidJNI_GetStringUTFLength(void * str)
{
	typedef int32_t (* ICallMethod) (void * str);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::GetStringUTFLength");
	int32_t i2res = icall(str);
	return i2res;
}
MonoString* UnityEngine_AndroidJNI_GetStringUTFChars(void * str)
{
	typedef Il2CppString* (* ICallMethod) (void * str);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::GetStringUTFChars");
	Il2CppString* i2res = icall(str);
	MonoString* monoi2res = get_mono_string(i2res);
	if(i2res != NULL && monoi2res == NULL)
	{
		platform_log("UnityEngine.AndroidJNI::GetStringUTFChars fail to convert il2cpp obj to mono");
	}
	return monoi2res;
}
MonoString* UnityEngine_AndroidJNI_CallStringMethod(void * obj, void * methodID, void* args)
{
	typedef Il2CppString* (* ICallMethod) (void * obj, void * methodID, void* args);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::CallStringMethod");
	Il2CppString* i2res = icall(obj,methodID,args);
	MonoString* monoi2res = get_mono_string(i2res);
	if(i2res != NULL && monoi2res == NULL)
	{
		platform_log("UnityEngine.AndroidJNI::CallStringMethod fail to convert il2cpp obj to mono");
	}
	return monoi2res;
}
void * UnityEngine_AndroidJNI_CallObjectMethod(void * obj, void * methodID, void* args)
{
	typedef void * (* ICallMethod) (void * obj, void * methodID, void* args);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::CallObjectMethod");
	void * i2res = icall(obj,methodID,args);
	if(i2res != NULL && i2res == NULL)
	{
		platform_log("UnityEngine.AndroidJNI::CallObjectMethod fail to convert il2cpp obj to mono");
	}
	return i2res;
}
int32_t UnityEngine_AndroidJNI_CallIntMethod(void * obj, void * methodID, void* args)
{
	typedef int32_t (* ICallMethod) (void * obj, void * methodID, void* args);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::CallIntMethod");
	int32_t i2res = icall(obj,methodID,args);
	return i2res;
}
bool UnityEngine_AndroidJNI_CallBooleanMethod(void * obj, void * methodID, void* args)
{
	typedef bool (* ICallMethod) (void * obj, void * methodID, void* args);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::CallBooleanMethod");
	bool i2res = icall(obj,methodID,args);
	return i2res;
}
int16_t UnityEngine_AndroidJNI_CallShortMethod(void * obj, void * methodID, void* args)
{
	typedef int16_t (* ICallMethod) (void * obj, void * methodID, void* args);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::CallShortMethod");
	int16_t i2res = icall(obj,methodID,args);
	return i2res;
}
int8_t UnityEngine_AndroidJNI_CallSByteMethod(void * obj, void * methodID, void* args)
{
	typedef int8_t (* ICallMethod) (void * obj, void * methodID, void* args);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::CallSByteMethod");
	int8_t i2res = icall(obj,methodID,args);
	return i2res;
}
char UnityEngine_AndroidJNI_CallCharMethod(void * obj, void * methodID, void* args)
{
	typedef char (* ICallMethod) (void * obj, void * methodID, void* args);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::CallCharMethod");
	char i2res = icall(obj,methodID,args);
	return i2res;
}
float UnityEngine_AndroidJNI_CallFloatMethod(void * obj, void * methodID, void* args)
{
	typedef float (* ICallMethod) (void * obj, void * methodID, void* args);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::CallFloatMethod");
	float i2res = icall(obj,methodID,args);
	return i2res;
}
double UnityEngine_AndroidJNI_CallDoubleMethod(void * obj, void * methodID, void* args)
{
	typedef double (* ICallMethod) (void * obj, void * methodID, void* args);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::CallDoubleMethod");
	double i2res = icall(obj,methodID,args);
	return i2res;
}
int64_t UnityEngine_AndroidJNI_CallLongMethod(void * obj, void * methodID, void* args)
{
	typedef int64_t (* ICallMethod) (void * obj, void * methodID, void* args);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::CallLongMethod");
	int64_t i2res = icall(obj,methodID,args);
	return i2res;
}
void UnityEngine_AndroidJNI_CallVoidMethod(void * obj, void * methodID, void* args)
{
	typedef void (* ICallMethod) (void * obj, void * methodID, void* args);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::CallVoidMethod");
	icall(obj,methodID,args);
}
MonoString* UnityEngine_AndroidJNI_GetStringField(void * obj, void * fieldID)
{
	typedef Il2CppString* (* ICallMethod) (void * obj, void * fieldID);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::GetStringField");
	Il2CppString* i2res = icall(obj,fieldID);
	MonoString* monoi2res = get_mono_string(i2res);
	if(i2res != NULL && monoi2res == NULL)
	{
		platform_log("UnityEngine.AndroidJNI::GetStringField fail to convert il2cpp obj to mono");
	}
	return monoi2res;
}
void * UnityEngine_AndroidJNI_GetObjectField(void * obj, void * fieldID)
{
	typedef void * (* ICallMethod) (void * obj, void * fieldID);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::GetObjectField");
	void * i2res = icall(obj,fieldID);
	if(i2res != NULL && i2res == NULL)
	{
		platform_log("UnityEngine.AndroidJNI::GetObjectField fail to convert il2cpp obj to mono");
	}
	return i2res;
}
bool UnityEngine_AndroidJNI_GetBooleanField(void * obj, void * fieldID)
{
	typedef bool (* ICallMethod) (void * obj, void * fieldID);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::GetBooleanField");
	bool i2res = icall(obj,fieldID);
	return i2res;
}
int8_t UnityEngine_AndroidJNI_GetSByteField(void * obj, void * fieldID)
{
	typedef int8_t (* ICallMethod) (void * obj, void * fieldID);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::GetSByteField");
	int8_t i2res = icall(obj,fieldID);
	return i2res;
}
char UnityEngine_AndroidJNI_GetCharField(void * obj, void * fieldID)
{
	typedef char (* ICallMethod) (void * obj, void * fieldID);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::GetCharField");
	char i2res = icall(obj,fieldID);
	return i2res;
}
int16_t UnityEngine_AndroidJNI_GetShortField(void * obj, void * fieldID)
{
	typedef int16_t (* ICallMethod) (void * obj, void * fieldID);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::GetShortField");
	int16_t i2res = icall(obj,fieldID);
	return i2res;
}
int32_t UnityEngine_AndroidJNI_GetIntField(void * obj, void * fieldID)
{
	typedef int32_t (* ICallMethod) (void * obj, void * fieldID);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::GetIntField");
	int32_t i2res = icall(obj,fieldID);
	return i2res;
}
int64_t UnityEngine_AndroidJNI_GetLongField(void * obj, void * fieldID)
{
	typedef int64_t (* ICallMethod) (void * obj, void * fieldID);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::GetLongField");
	int64_t i2res = icall(obj,fieldID);
	return i2res;
}
float UnityEngine_AndroidJNI_GetFloatField(void * obj, void * fieldID)
{
	typedef float (* ICallMethod) (void * obj, void * fieldID);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::GetFloatField");
	float i2res = icall(obj,fieldID);
	return i2res;
}
double UnityEngine_AndroidJNI_GetDoubleField(void * obj, void * fieldID)
{
	typedef double (* ICallMethod) (void * obj, void * fieldID);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::GetDoubleField");
	double i2res = icall(obj,fieldID);
	return i2res;
}
void UnityEngine_AndroidJNI_SetStringField(void * obj, void * fieldID, MonoString* val)
{
	typedef void (* ICallMethod) (void * obj, void * fieldID, Il2CppString* val);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::SetStringField");
	Il2CppString* i2val = get_il2cpp_string(val);
	icall(obj,fieldID,i2val);
}
void UnityEngine_AndroidJNI_SetObjectField(void * obj, void * fieldID, void * val)
{
	typedef void (* ICallMethod) (void * obj, void * fieldID, void * val);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::SetObjectField");
	icall(obj,fieldID,val);
}
void UnityEngine_AndroidJNI_SetBooleanField(void * obj, void * fieldID, bool val)
{
	typedef void (* ICallMethod) (void * obj, void * fieldID, bool val);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::SetBooleanField");
	icall(obj,fieldID,val);
}
void UnityEngine_AndroidJNI_SetSByteField(void * obj, void * fieldID, int8_t val)
{
	typedef void (* ICallMethod) (void * obj, void * fieldID, int8_t val);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::SetSByteField");
	icall(obj,fieldID,val);
}
void UnityEngine_AndroidJNI_SetCharField(void * obj, void * fieldID, char val)
{
	typedef void (* ICallMethod) (void * obj, void * fieldID, char val);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::SetCharField");
	icall(obj,fieldID,val);
}
void UnityEngine_AndroidJNI_SetShortField(void * obj, void * fieldID, int16_t val)
{
	typedef void (* ICallMethod) (void * obj, void * fieldID, int16_t val);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::SetShortField");
	icall(obj,fieldID,val);
}
void UnityEngine_AndroidJNI_SetIntField(void * obj, void * fieldID, int32_t val)
{
	typedef void (* ICallMethod) (void * obj, void * fieldID, int32_t val);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::SetIntField");
	icall(obj,fieldID,val);
}
void UnityEngine_AndroidJNI_SetLongField(void * obj, void * fieldID, int64_t val)
{
	typedef void (* ICallMethod) (void * obj, void * fieldID, int64_t val);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::SetLongField");
	icall(obj,fieldID,val);
}
void UnityEngine_AndroidJNI_SetFloatField(void * obj, void * fieldID, float val)
{
	typedef void (* ICallMethod) (void * obj, void * fieldID, float val);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::SetFloatField");
	icall(obj,fieldID,val);
}
void UnityEngine_AndroidJNI_SetDoubleField(void * obj, void * fieldID, double val)
{
	typedef void (* ICallMethod) (void * obj, void * fieldID, double val);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::SetDoubleField");
	icall(obj,fieldID,val);
}
MonoString* UnityEngine_AndroidJNI_CallStaticStringMethod(void * clazz, void * methodID, void* args)
{
	typedef Il2CppString* (* ICallMethod) (void * clazz, void * methodID, void* args);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::CallStaticStringMethod");
	Il2CppString* i2res = icall(clazz,methodID,args);
	MonoString* monoi2res = get_mono_string(i2res);
	if(i2res != NULL && monoi2res == NULL)
	{
		platform_log("UnityEngine.AndroidJNI::CallStaticStringMethod fail to convert il2cpp obj to mono");
	}
	return monoi2res;
}
void * UnityEngine_AndroidJNI_CallStaticObjectMethod(void * clazz, void * methodID, void* args)
{
	typedef void * (* ICallMethod) (void * clazz, void * methodID, void* args);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::CallStaticObjectMethod");
	void * i2res = icall(clazz,methodID,args);
	if(i2res != NULL && i2res == NULL)
	{
		platform_log("UnityEngine.AndroidJNI::CallStaticObjectMethod fail to convert il2cpp obj to mono");
	}
	return i2res;
}
int32_t UnityEngine_AndroidJNI_CallStaticIntMethod(void * clazz, void * methodID, void* args)
{
	typedef int32_t (* ICallMethod) (void * clazz, void * methodID, void* args);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::CallStaticIntMethod");
	int32_t i2res = icall(clazz,methodID,args);
	return i2res;
}
bool UnityEngine_AndroidJNI_CallStaticBooleanMethod(void * clazz, void * methodID, void* args)
{
	typedef bool (* ICallMethod) (void * clazz, void * methodID, void* args);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::CallStaticBooleanMethod");
	bool i2res = icall(clazz,methodID,args);
	return i2res;
}
int16_t UnityEngine_AndroidJNI_CallStaticShortMethod(void * clazz, void * methodID, void* args)
{
	typedef int16_t (* ICallMethod) (void * clazz, void * methodID, void* args);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::CallStaticShortMethod");
	int16_t i2res = icall(clazz,methodID,args);
	return i2res;
}
int8_t UnityEngine_AndroidJNI_CallStaticSByteMethod(void * clazz, void * methodID, void* args)
{
	typedef int8_t (* ICallMethod) (void * clazz, void * methodID, void* args);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::CallStaticSByteMethod");
	int8_t i2res = icall(clazz,methodID,args);
	return i2res;
}
char UnityEngine_AndroidJNI_CallStaticCharMethod(void * clazz, void * methodID, void* args)
{
	typedef char (* ICallMethod) (void * clazz, void * methodID, void* args);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::CallStaticCharMethod");
	char i2res = icall(clazz,methodID,args);
	return i2res;
}
float UnityEngine_AndroidJNI_CallStaticFloatMethod(void * clazz, void * methodID, void* args)
{
	typedef float (* ICallMethod) (void * clazz, void * methodID, void* args);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::CallStaticFloatMethod");
	float i2res = icall(clazz,methodID,args);
	return i2res;
}
double UnityEngine_AndroidJNI_CallStaticDoubleMethod(void * clazz, void * methodID, void* args)
{
	typedef double (* ICallMethod) (void * clazz, void * methodID, void* args);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::CallStaticDoubleMethod");
	double i2res = icall(clazz,methodID,args);
	return i2res;
}
int64_t UnityEngine_AndroidJNI_CallStaticLongMethod(void * clazz, void * methodID, void* args)
{
	typedef int64_t (* ICallMethod) (void * clazz, void * methodID, void* args);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::CallStaticLongMethod");
	int64_t i2res = icall(clazz,methodID,args);
	return i2res;
}
void UnityEngine_AndroidJNI_CallStaticVoidMethod(void * clazz, void * methodID, void* args)
{
	typedef void (* ICallMethod) (void * clazz, void * methodID, void* args);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::CallStaticVoidMethod");
	icall(clazz,methodID,args);
}
MonoString* UnityEngine_AndroidJNI_GetStaticStringField(void * clazz, void * fieldID)
{
	typedef Il2CppString* (* ICallMethod) (void * clazz, void * fieldID);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::GetStaticStringField");
	Il2CppString* i2res = icall(clazz,fieldID);
	MonoString* monoi2res = get_mono_string(i2res);
	if(i2res != NULL && monoi2res == NULL)
	{
		platform_log("UnityEngine.AndroidJNI::GetStaticStringField fail to convert il2cpp obj to mono");
	}
	return monoi2res;
}
void * UnityEngine_AndroidJNI_GetStaticObjectField(void * clazz, void * fieldID)
{
	typedef void * (* ICallMethod) (void * clazz, void * fieldID);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::GetStaticObjectField");
	void * i2res = icall(clazz,fieldID);
	if(i2res != NULL && i2res == NULL)
	{
		platform_log("UnityEngine.AndroidJNI::GetStaticObjectField fail to convert il2cpp obj to mono");
	}
	return i2res;
}
bool UnityEngine_AndroidJNI_GetStaticBooleanField(void * clazz, void * fieldID)
{
	typedef bool (* ICallMethod) (void * clazz, void * fieldID);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::GetStaticBooleanField");
	bool i2res = icall(clazz,fieldID);
	return i2res;
}
int8_t UnityEngine_AndroidJNI_GetStaticSByteField(void * clazz, void * fieldID)
{
	typedef int8_t (* ICallMethod) (void * clazz, void * fieldID);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::GetStaticSByteField");
	int8_t i2res = icall(clazz,fieldID);
	return i2res;
}
char UnityEngine_AndroidJNI_GetStaticCharField(void * clazz, void * fieldID)
{
	typedef char (* ICallMethod) (void * clazz, void * fieldID);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::GetStaticCharField");
	char i2res = icall(clazz,fieldID);
	return i2res;
}
int16_t UnityEngine_AndroidJNI_GetStaticShortField(void * clazz, void * fieldID)
{
	typedef int16_t (* ICallMethod) (void * clazz, void * fieldID);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::GetStaticShortField");
	int16_t i2res = icall(clazz,fieldID);
	return i2res;
}
int32_t UnityEngine_AndroidJNI_GetStaticIntField(void * clazz, void * fieldID)
{
	typedef int32_t (* ICallMethod) (void * clazz, void * fieldID);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::GetStaticIntField");
	int32_t i2res = icall(clazz,fieldID);
	return i2res;
}
int64_t UnityEngine_AndroidJNI_GetStaticLongField(void * clazz, void * fieldID)
{
	typedef int64_t (* ICallMethod) (void * clazz, void * fieldID);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::GetStaticLongField");
	int64_t i2res = icall(clazz,fieldID);
	return i2res;
}
float UnityEngine_AndroidJNI_GetStaticFloatField(void * clazz, void * fieldID)
{
	typedef float (* ICallMethod) (void * clazz, void * fieldID);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::GetStaticFloatField");
	float i2res = icall(clazz,fieldID);
	return i2res;
}
double UnityEngine_AndroidJNI_GetStaticDoubleField(void * clazz, void * fieldID)
{
	typedef double (* ICallMethod) (void * clazz, void * fieldID);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::GetStaticDoubleField");
	double i2res = icall(clazz,fieldID);
	return i2res;
}
void UnityEngine_AndroidJNI_SetStaticStringField(void * clazz, void * fieldID, MonoString* val)
{
	typedef void (* ICallMethod) (void * clazz, void * fieldID, Il2CppString* val);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::SetStaticStringField");
	Il2CppString* i2val = get_il2cpp_string(val);
	icall(clazz,fieldID,i2val);
}
void UnityEngine_AndroidJNI_SetStaticObjectField(void * clazz, void * fieldID, void * val)
{
	typedef void (* ICallMethod) (void * clazz, void * fieldID, void * val);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::SetStaticObjectField");
	icall(clazz,fieldID,val);
}
void UnityEngine_AndroidJNI_SetStaticBooleanField(void * clazz, void * fieldID, bool val)
{
	typedef void (* ICallMethod) (void * clazz, void * fieldID, bool val);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::SetStaticBooleanField");
	icall(clazz,fieldID,val);
}
void UnityEngine_AndroidJNI_SetStaticSByteField(void * clazz, void * fieldID, int8_t val)
{
	typedef void (* ICallMethod) (void * clazz, void * fieldID, int8_t val);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::SetStaticSByteField");
	icall(clazz,fieldID,val);
}
void UnityEngine_AndroidJNI_SetStaticCharField(void * clazz, void * fieldID, char val)
{
	typedef void (* ICallMethod) (void * clazz, void * fieldID, char val);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::SetStaticCharField");
	icall(clazz,fieldID,val);
}
void UnityEngine_AndroidJNI_SetStaticShortField(void * clazz, void * fieldID, int16_t val)
{
	typedef void (* ICallMethod) (void * clazz, void * fieldID, int16_t val);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::SetStaticShortField");
	icall(clazz,fieldID,val);
}
void UnityEngine_AndroidJNI_SetStaticIntField(void * clazz, void * fieldID, int32_t val)
{
	typedef void (* ICallMethod) (void * clazz, void * fieldID, int32_t val);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::SetStaticIntField");
	icall(clazz,fieldID,val);
}
void UnityEngine_AndroidJNI_SetStaticLongField(void * clazz, void * fieldID, int64_t val)
{
	typedef void (* ICallMethod) (void * clazz, void * fieldID, int64_t val);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::SetStaticLongField");
	icall(clazz,fieldID,val);
}
void UnityEngine_AndroidJNI_SetStaticFloatField(void * clazz, void * fieldID, float val)
{
	typedef void (* ICallMethod) (void * clazz, void * fieldID, float val);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::SetStaticFloatField");
	icall(clazz,fieldID,val);
}
void UnityEngine_AndroidJNI_SetStaticDoubleField(void * clazz, void * fieldID, double val)
{
	typedef void (* ICallMethod) (void * clazz, void * fieldID, double val);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::SetStaticDoubleField");
	icall(clazz,fieldID,val);
}
void * UnityEngine_AndroidJNI_ToBooleanArray(MonoArray* array)
{
	typedef void * (* ICallMethod) (Il2CppArray* array);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::ToBooleanArray");
	Il2CppArray* i2array = get_il2cpp_array(array);
	void * i2res = icall(i2array);
	if(i2res != NULL && i2res == NULL)
	{
		platform_log("UnityEngine.AndroidJNI::ToBooleanArray fail to convert il2cpp obj to mono");
	}
	return i2res;
}
void * UnityEngine_AndroidJNI_ToByteArray(MonoArray* array)
{
	typedef void * (* ICallMethod) (Il2CppArray* array);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::ToByteArray");
	Il2CppArray* i2array = get_il2cpp_array(array);
	void * i2res = icall(i2array);
	if(i2res != NULL && i2res == NULL)
	{
		platform_log("UnityEngine.AndroidJNI::ToByteArray fail to convert il2cpp obj to mono");
	}
	return i2res;
}
void * UnityEngine_AndroidJNI_ToSByteArray(MonoArray* array)
{
	typedef void * (* ICallMethod) (Il2CppArray* array);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::ToSByteArray");
	Il2CppArray* i2array = get_il2cpp_array(array);
	void * i2res = icall(i2array);
	if(i2res != NULL && i2res == NULL)
	{
		platform_log("UnityEngine.AndroidJNI::ToSByteArray fail to convert il2cpp obj to mono");
	}
	return i2res;
}
void * UnityEngine_AndroidJNI_ToCharArray(MonoArray* array)
{
	typedef void * (* ICallMethod) (Il2CppArray* array);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::ToCharArray");
	Il2CppArray* i2array = get_il2cpp_array(array);
	void * i2res = icall(i2array);
	if(i2res != NULL && i2res == NULL)
	{
		platform_log("UnityEngine.AndroidJNI::ToCharArray fail to convert il2cpp obj to mono");
	}
	return i2res;
}
void * UnityEngine_AndroidJNI_ToShortArray(MonoArray* array)
{
	typedef void * (* ICallMethod) (Il2CppArray* array);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::ToShortArray");
	Il2CppArray* i2array = get_il2cpp_array(array);
	void * i2res = icall(i2array);
	if(i2res != NULL && i2res == NULL)
	{
		platform_log("UnityEngine.AndroidJNI::ToShortArray fail to convert il2cpp obj to mono");
	}
	return i2res;
}
void * UnityEngine_AndroidJNI_ToIntArray(MonoArray* array)
{
	typedef void * (* ICallMethod) (Il2CppArray* array);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::ToIntArray");
	Il2CppArray* i2array = get_il2cpp_array(array);
	void * i2res = icall(i2array);
	if(i2res != NULL && i2res == NULL)
	{
		platform_log("UnityEngine.AndroidJNI::ToIntArray fail to convert il2cpp obj to mono");
	}
	return i2res;
}
void * UnityEngine_AndroidJNI_ToLongArray(MonoArray* array)
{
	typedef void * (* ICallMethod) (Il2CppArray* array);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::ToLongArray");
	Il2CppArray* i2array = get_il2cpp_array(array);
	void * i2res = icall(i2array);
	if(i2res != NULL && i2res == NULL)
	{
		platform_log("UnityEngine.AndroidJNI::ToLongArray fail to convert il2cpp obj to mono");
	}
	return i2res;
}
void * UnityEngine_AndroidJNI_ToFloatArray(MonoArray* array)
{
	typedef void * (* ICallMethod) (Il2CppArray* array);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::ToFloatArray");
	Il2CppArray* i2array = get_il2cpp_array(array);
	void * i2res = icall(i2array);
	if(i2res != NULL && i2res == NULL)
	{
		platform_log("UnityEngine.AndroidJNI::ToFloatArray fail to convert il2cpp obj to mono");
	}
	return i2res;
}
void * UnityEngine_AndroidJNI_ToDoubleArray(MonoArray* array)
{
	typedef void * (* ICallMethod) (Il2CppArray* array);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::ToDoubleArray");
	Il2CppArray* i2array = get_il2cpp_array(array);
	void * i2res = icall(i2array);
	if(i2res != NULL && i2res == NULL)
	{
		platform_log("UnityEngine.AndroidJNI::ToDoubleArray fail to convert il2cpp obj to mono");
	}
	return i2res;
}
void * UnityEngine_AndroidJNI_ToObjectArray(MonoArray* array, void * arrayClass)
{
	typedef void * (* ICallMethod) (Il2CppArray* array, void * arrayClass);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::ToObjectArray");
	Il2CppArray* i2array = get_il2cpp_array(array);
	void * i2res = icall(i2array,arrayClass);
	if(i2res != NULL && i2res == NULL)
	{
		platform_log("UnityEngine.AndroidJNI::ToObjectArray fail to convert il2cpp obj to mono");
	}
	return i2res;
}
MonoArray* UnityEngine_AndroidJNI_FromBooleanArray(void * array)
{
	typedef Il2CppArray* (* ICallMethod) (void * array);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::FromBooleanArray");
	Il2CppArray* i2res = icall(array);
	MonoArray* monoi2res = get_mono_array(i2res);
	if(i2res != NULL && monoi2res == NULL)
	{
		platform_log("UnityEngine.AndroidJNI::FromBooleanArray fail to convert il2cpp obj to mono");
	}
	return monoi2res;
}
MonoArray* UnityEngine_AndroidJNI_FromByteArray(void * array)
{
	typedef Il2CppArray* (* ICallMethod) (void * array);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::FromByteArray");
	Il2CppArray* i2res = icall(array);
	MonoArray* monoi2res = get_mono_array(i2res);
	if(i2res != NULL && monoi2res == NULL)
	{
		platform_log("UnityEngine.AndroidJNI::FromByteArray fail to convert il2cpp obj to mono");
	}
	return monoi2res;
}
MonoArray* UnityEngine_AndroidJNI_FromSByteArray(void * array)
{
	typedef Il2CppArray* (* ICallMethod) (void * array);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::FromSByteArray");
	Il2CppArray* i2res = icall(array);
	MonoArray* monoi2res = get_mono_array(i2res);
	if(i2res != NULL && monoi2res == NULL)
	{
		platform_log("UnityEngine.AndroidJNI::FromSByteArray fail to convert il2cpp obj to mono");
	}
	return monoi2res;
}
MonoArray* UnityEngine_AndroidJNI_FromCharArray(void * array)
{
	typedef Il2CppArray* (* ICallMethod) (void * array);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::FromCharArray");
	Il2CppArray* i2res = icall(array);
	MonoArray* monoi2res = get_mono_array(i2res);
	if(i2res != NULL && monoi2res == NULL)
	{
		platform_log("UnityEngine.AndroidJNI::FromCharArray fail to convert il2cpp obj to mono");
	}
	return monoi2res;
}
MonoArray* UnityEngine_AndroidJNI_FromShortArray(void * array)
{
	typedef Il2CppArray* (* ICallMethod) (void * array);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::FromShortArray");
	Il2CppArray* i2res = icall(array);
	MonoArray* monoi2res = get_mono_array(i2res);
	if(i2res != NULL && monoi2res == NULL)
	{
		platform_log("UnityEngine.AndroidJNI::FromShortArray fail to convert il2cpp obj to mono");
	}
	return monoi2res;
}
MonoArray* UnityEngine_AndroidJNI_FromIntArray(void * array)
{
	typedef Il2CppArray* (* ICallMethod) (void * array);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::FromIntArray");
	Il2CppArray* i2res = icall(array);
	MonoArray* monoi2res = get_mono_array(i2res);
	if(i2res != NULL && monoi2res == NULL)
	{
		platform_log("UnityEngine.AndroidJNI::FromIntArray fail to convert il2cpp obj to mono");
	}
	return monoi2res;
}
MonoArray* UnityEngine_AndroidJNI_FromLongArray(void * array)
{
	typedef Il2CppArray* (* ICallMethod) (void * array);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::FromLongArray");
	Il2CppArray* i2res = icall(array);
	MonoArray* monoi2res = get_mono_array(i2res);
	if(i2res != NULL && monoi2res == NULL)
	{
		platform_log("UnityEngine.AndroidJNI::FromLongArray fail to convert il2cpp obj to mono");
	}
	return monoi2res;
}
MonoArray* UnityEngine_AndroidJNI_FromFloatArray(void * array)
{
	typedef Il2CppArray* (* ICallMethod) (void * array);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::FromFloatArray");
	Il2CppArray* i2res = icall(array);
	MonoArray* monoi2res = get_mono_array(i2res);
	if(i2res != NULL && monoi2res == NULL)
	{
		platform_log("UnityEngine.AndroidJNI::FromFloatArray fail to convert il2cpp obj to mono");
	}
	return monoi2res;
}
MonoArray* UnityEngine_AndroidJNI_FromDoubleArray(void * array)
{
	typedef Il2CppArray* (* ICallMethod) (void * array);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::FromDoubleArray");
	Il2CppArray* i2res = icall(array);
	MonoArray* monoi2res = get_mono_array(i2res);
	if(i2res != NULL && monoi2res == NULL)
	{
		platform_log("UnityEngine.AndroidJNI::FromDoubleArray fail to convert il2cpp obj to mono");
	}
	return monoi2res;
}
MonoArray* UnityEngine_AndroidJNI_FromObjectArray(void * array)
{
	typedef Il2CppArray* (* ICallMethod) (void * array);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::FromObjectArray");
	Il2CppArray* i2res = icall(array);
	MonoArray* monoi2res = get_mono_array(i2res);
	if(i2res != NULL && monoi2res == NULL)
	{
		platform_log("UnityEngine.AndroidJNI::FromObjectArray fail to convert il2cpp obj to mono");
	}
	return monoi2res;
}
int32_t UnityEngine_AndroidJNI_GetArrayLength(void * array)
{
	typedef int32_t (* ICallMethod) (void * array);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::GetArrayLength");
	int32_t i2res = icall(array);
	return i2res;
}
void * UnityEngine_AndroidJNI_NewBooleanArray(int32_t size)
{
	typedef void * (* ICallMethod) (int32_t size);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::NewBooleanArray");
	void * i2res = icall(size);
	if(i2res != NULL && i2res == NULL)
	{
		platform_log("UnityEngine.AndroidJNI::NewBooleanArray fail to convert il2cpp obj to mono");
	}
	return i2res;
}
void * UnityEngine_AndroidJNI_NewSByteArray(int32_t size)
{
	typedef void * (* ICallMethod) (int32_t size);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::NewSByteArray");
	void * i2res = icall(size);
	if(i2res != NULL && i2res == NULL)
	{
		platform_log("UnityEngine.AndroidJNI::NewSByteArray fail to convert il2cpp obj to mono");
	}
	return i2res;
}
void * UnityEngine_AndroidJNI_NewCharArray(int32_t size)
{
	typedef void * (* ICallMethod) (int32_t size);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::NewCharArray");
	void * i2res = icall(size);
	if(i2res != NULL && i2res == NULL)
	{
		platform_log("UnityEngine.AndroidJNI::NewCharArray fail to convert il2cpp obj to mono");
	}
	return i2res;
}
void * UnityEngine_AndroidJNI_NewShortArray(int32_t size)
{
	typedef void * (* ICallMethod) (int32_t size);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::NewShortArray");
	void * i2res = icall(size);
	if(i2res != NULL && i2res == NULL)
	{
		platform_log("UnityEngine.AndroidJNI::NewShortArray fail to convert il2cpp obj to mono");
	}
	return i2res;
}
void * UnityEngine_AndroidJNI_NewIntArray(int32_t size)
{
	typedef void * (* ICallMethod) (int32_t size);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::NewIntArray");
	void * i2res = icall(size);
	if(i2res != NULL && i2res == NULL)
	{
		platform_log("UnityEngine.AndroidJNI::NewIntArray fail to convert il2cpp obj to mono");
	}
	return i2res;
}
void * UnityEngine_AndroidJNI_NewLongArray(int32_t size)
{
	typedef void * (* ICallMethod) (int32_t size);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::NewLongArray");
	void * i2res = icall(size);
	if(i2res != NULL && i2res == NULL)
	{
		platform_log("UnityEngine.AndroidJNI::NewLongArray fail to convert il2cpp obj to mono");
	}
	return i2res;
}
void * UnityEngine_AndroidJNI_NewFloatArray(int32_t size)
{
	typedef void * (* ICallMethod) (int32_t size);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::NewFloatArray");
	void * i2res = icall(size);
	if(i2res != NULL && i2res == NULL)
	{
		platform_log("UnityEngine.AndroidJNI::NewFloatArray fail to convert il2cpp obj to mono");
	}
	return i2res;
}
void * UnityEngine_AndroidJNI_NewDoubleArray(int32_t size)
{
	typedef void * (* ICallMethod) (int32_t size);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::NewDoubleArray");
	void * i2res = icall(size);
	if(i2res != NULL && i2res == NULL)
	{
		platform_log("UnityEngine.AndroidJNI::NewDoubleArray fail to convert il2cpp obj to mono");
	}
	return i2res;
}
void * UnityEngine_AndroidJNI_NewObjectArray(int32_t size, void * clazz, void * obj)
{
	typedef void * (* ICallMethod) (int32_t size, void * clazz, void * obj);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::NewObjectArray");
	void * i2res = icall(size,clazz,obj);
	if(i2res != NULL && i2res == NULL)
	{
		platform_log("UnityEngine.AndroidJNI::NewObjectArray fail to convert il2cpp obj to mono");
	}
	return i2res;
}
bool UnityEngine_AndroidJNI_GetBooleanArrayElement(void * array, int32_t index)
{
	typedef bool (* ICallMethod) (void * array, int32_t index);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::GetBooleanArrayElement");
	bool i2res = icall(array,index);
	return i2res;
}
int8_t UnityEngine_AndroidJNI_GetSByteArrayElement(void * array, int32_t index)
{
	typedef int8_t (* ICallMethod) (void * array, int32_t index);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::GetSByteArrayElement");
	int8_t i2res = icall(array,index);
	return i2res;
}
char UnityEngine_AndroidJNI_GetCharArrayElement(void * array, int32_t index)
{
	typedef char (* ICallMethod) (void * array, int32_t index);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::GetCharArrayElement");
	char i2res = icall(array,index);
	return i2res;
}
int16_t UnityEngine_AndroidJNI_GetShortArrayElement(void * array, int32_t index)
{
	typedef int16_t (* ICallMethod) (void * array, int32_t index);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::GetShortArrayElement");
	int16_t i2res = icall(array,index);
	return i2res;
}
int32_t UnityEngine_AndroidJNI_GetIntArrayElement(void * array, int32_t index)
{
	typedef int32_t (* ICallMethod) (void * array, int32_t index);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::GetIntArrayElement");
	int32_t i2res = icall(array,index);
	return i2res;
}
int64_t UnityEngine_AndroidJNI_GetLongArrayElement(void * array, int32_t index)
{
	typedef int64_t (* ICallMethod) (void * array, int32_t index);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::GetLongArrayElement");
	int64_t i2res = icall(array,index);
	return i2res;
}
float UnityEngine_AndroidJNI_GetFloatArrayElement(void * array, int32_t index)
{
	typedef float (* ICallMethod) (void * array, int32_t index);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::GetFloatArrayElement");
	float i2res = icall(array,index);
	return i2res;
}
double UnityEngine_AndroidJNI_GetDoubleArrayElement(void * array, int32_t index)
{
	typedef double (* ICallMethod) (void * array, int32_t index);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::GetDoubleArrayElement");
	double i2res = icall(array,index);
	return i2res;
}
void * UnityEngine_AndroidJNI_GetObjectArrayElement(void * array, int32_t index)
{
	typedef void * (* ICallMethod) (void * array, int32_t index);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::GetObjectArrayElement");
	void * i2res = icall(array,index);
	if(i2res != NULL && i2res == NULL)
	{
		platform_log("UnityEngine.AndroidJNI::GetObjectArrayElement fail to convert il2cpp obj to mono");
	}
	return i2res;
}
void UnityEngine_AndroidJNI_SetBooleanArrayElement(void * array, int32_t index, bool val)
{
	typedef void (* ICallMethod) (void * array, int32_t index, bool val);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::SetBooleanArrayElement");
	icall(array,index,val);
}
void UnityEngine_AndroidJNI_SetSByteArrayElement(void * array, int32_t index, int8_t val)
{
	typedef void (* ICallMethod) (void * array, int32_t index, int8_t val);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::SetSByteArrayElement");
	icall(array,index,val);
}
void UnityEngine_AndroidJNI_SetCharArrayElement(void * array, int32_t index, char val)
{
	typedef void (* ICallMethod) (void * array, int32_t index, char val);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::SetCharArrayElement");
	icall(array,index,val);
}
void UnityEngine_AndroidJNI_SetShortArrayElement(void * array, int32_t index, int16_t val)
{
	typedef void (* ICallMethod) (void * array, int32_t index, int16_t val);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::SetShortArrayElement");
	icall(array,index,val);
}
void UnityEngine_AndroidJNI_SetIntArrayElement(void * array, int32_t index, int32_t val)
{
	typedef void (* ICallMethod) (void * array, int32_t index, int32_t val);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::SetIntArrayElement");
	icall(array,index,val);
}
void UnityEngine_AndroidJNI_SetLongArrayElement(void * array, int32_t index, int64_t val)
{
	typedef void (* ICallMethod) (void * array, int32_t index, int64_t val);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::SetLongArrayElement");
	icall(array,index,val);
}
void UnityEngine_AndroidJNI_SetFloatArrayElement(void * array, int32_t index, float val)
{
	typedef void (* ICallMethod) (void * array, int32_t index, float val);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::SetFloatArrayElement");
	icall(array,index,val);
}
void UnityEngine_AndroidJNI_SetDoubleArrayElement(void * array, int32_t index, double val)
{
	typedef void (* ICallMethod) (void * array, int32_t index, double val);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::SetDoubleArrayElement");
	icall(array,index,val);
}
void UnityEngine_AndroidJNI_SetObjectArrayElement(void * array, int32_t index, void * obj)
{
	typedef void (* ICallMethod) (void * array, int32_t index, void * obj);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AndroidJNI::SetObjectArrayElement");
	icall(array,index,obj);
}
bool UnityEngine_Animator_get_isHuman(MonoObject* thiz)
{
	typedef bool (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Animator::get_isHuman");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Animator());
	bool i2res = icall(i2thiz);
	return i2res;
}
bool UnityEngine_Animator_get_hasRootMotion(MonoObject* thiz)
{
	typedef bool (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Animator::get_hasRootMotion");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Animator());
	bool i2res = icall(i2thiz);
	return i2res;
}
void UnityEngine_Animator_set_updateMode(MonoObject* thiz, int32_t value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, int32_t value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Animator::set_updateMode");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Animator());
	icall(i2thiz,value);
}
int32_t UnityEngine_Animator_get_layerCount(MonoObject* thiz)
{
	typedef int32_t (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Animator::get_layerCount");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Animator());
	int32_t i2res = icall(i2thiz);
	return i2res;
}
void UnityEngine_Animator_set_speed_1(MonoObject* thiz, float value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, float value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Animator::set_speed");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Animator());
	icall(i2thiz,value);
}
MonoObject* UnityEngine_Animator_get_runtimeAnimatorController(MonoObject* thiz)
{
	typedef Il2CppObject* (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Animator::get_runtimeAnimatorController");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Animator());
	Il2CppObject* i2res = icall(i2thiz);
	MonoObject* monoi2res = get_mono_object(i2res,mono_get_class_UnityEngine_RuntimeAnimatorController());
	if(i2res != NULL && monoi2res == NULL)
	{
		platform_log("UnityEngine.Animator::get_runtimeAnimatorController fail to convert il2cpp obj to mono");
	}
	return monoi2res;
}
bool UnityEngine_Animator_get_hasBoundPlayables(MonoObject* thiz)
{
	typedef bool (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Animator::get_hasBoundPlayables");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Animator());
	bool i2res = icall(i2thiz);
	return i2res;
}
MonoObject* UnityEngine_Animator_get_avatar(MonoObject* thiz)
{
	typedef Il2CppObject* (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Animator::get_avatar");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Animator());
	Il2CppObject* i2res = icall(i2thiz);
	MonoObject* monoi2res = get_mono_object(i2res,mono_get_class_UnityEngine_Avatar());
	if(i2res != NULL && monoi2res == NULL)
	{
		platform_log("UnityEngine.Animator::get_avatar fail to convert il2cpp obj to mono");
	}
	return monoi2res;
}
void UnityEngine_Animator_SetBoolString(MonoObject* thiz, MonoString* name, bool value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, Il2CppString* name, bool value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Animator::SetBoolString");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Animator());
	Il2CppString* i2name = get_il2cpp_string(name);
	icall(i2thiz,i2name,value);
}
void UnityEngine_Animator_SetIntegerString(MonoObject* thiz, MonoString* name, int32_t value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, Il2CppString* name, int32_t value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Animator::SetIntegerString");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Animator());
	Il2CppString* i2name = get_il2cpp_string(name);
	icall(i2thiz,i2name,value);
}
void UnityEngine_Animator_SetTriggerString(MonoObject* thiz, MonoString* name)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, Il2CppString* name);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Animator::SetTriggerString");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Animator());
	Il2CppString* i2name = get_il2cpp_string(name);
	icall(i2thiz,i2name);
}
void UnityEngine_Animator_ResetTriggerString(MonoObject* thiz, MonoString* name)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, Il2CppString* name);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Animator::ResetTriggerString");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Animator());
	Il2CppString* i2name = get_il2cpp_string(name);
	icall(i2thiz,i2name);
}
float UnityEngine_Animator_GetLayerWeight(MonoObject* thiz, int32_t layerIndex)
{
	typedef float (* ICallMethod) (Il2CppObject* thiz, int32_t layerIndex);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Animator::GetLayerWeight");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Animator());
	float i2res = icall(i2thiz,layerIndex);
	return i2res;
}
void UnityEngine_Animator_GetAnimatorStateInfo(MonoObject* thiz, int32_t layerIndex, int32_t stateInfoIndex, void * info)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, int32_t layerIndex, int32_t stateInfoIndex, void * info);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Animator::GetAnimatorStateInfo");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Animator());
	icall(i2thiz,layerIndex,stateInfoIndex,info);
}
int32_t UnityEngine_Animator_GetAnimatorClipInfoCount(MonoObject* thiz, int32_t layerIndex, bool current)
{
	typedef int32_t (* ICallMethod) (Il2CppObject* thiz, int32_t layerIndex, bool current);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Animator::GetAnimatorClipInfoCount");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Animator());
	int32_t i2res = icall(i2thiz,layerIndex,current);
	return i2res;
}
void* UnityEngine_Animator_GetCurrentAnimatorClipInfo(MonoObject* thiz, int32_t layerIndex)
{
	typedef void* (* ICallMethod) (Il2CppObject* thiz, int32_t layerIndex);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Animator::GetCurrentAnimatorClipInfo");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Animator());
	void* i2res = icall(i2thiz,layerIndex);
	if(i2res != NULL && i2res == NULL)
	{
		platform_log("UnityEngine.Animator::GetCurrentAnimatorClipInfo fail to convert il2cpp obj to mono");
	}
	return i2res;
}
bool UnityEngine_Animator_IsInTransition(MonoObject* thiz, int32_t layerIndex)
{
	typedef bool (* ICallMethod) (Il2CppObject* thiz, int32_t layerIndex);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Animator::IsInTransition");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Animator());
	bool i2res = icall(i2thiz,layerIndex);
	return i2res;
}
int32_t UnityEngine_Animator_StringToHash(MonoString* name)
{
	typedef int32_t (* ICallMethod) (Il2CppString* name);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Animator::StringToHash");
	Il2CppString* i2name = get_il2cpp_string(name);
	int32_t i2res = icall(i2name);
	return i2res;
}
void UnityEngine_Animator_CrossFadeInFixedTime(MonoObject* thiz, int32_t stateHashName, float fixedTransitionDuration, int32_t layer, float fixedTimeOffset, float normalizedTransitionTime)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, int32_t stateHashName, float fixedTransitionDuration, int32_t layer, float fixedTimeOffset, float normalizedTransitionTime);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Animator::CrossFadeInFixedTime");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Animator());
	icall(i2thiz,stateHashName,fixedTransitionDuration,layer,fixedTimeOffset,normalizedTransitionTime);
}
void UnityEngine_Animator_Play(MonoObject* thiz, int32_t stateNameHash, int32_t layer, float normalizedTime)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, int32_t stateNameHash, int32_t layer, float normalizedTime);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Animator::Play");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Animator());
	icall(i2thiz,stateNameHash,layer,normalizedTime);
}
bool UnityEngine_Animator_HasState(MonoObject* thiz, int32_t layerIndex, int32_t stateID)
{
	typedef bool (* ICallMethod) (Il2CppObject* thiz, int32_t layerIndex, int32_t stateID);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Animator::HasState");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Animator());
	bool i2res = icall(i2thiz,layerIndex,stateID);
	return i2res;
}
void UnityEngine_Animator_Update(MonoObject* thiz, float deltaTime)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, float deltaTime);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Animator::Update");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Animator());
	icall(i2thiz,deltaTime);
}
MonoObject* UnityEngine_AnimatorClipInfo_InstanceIDToAnimationClipPPtr(int32_t instanceID)
{
	typedef Il2CppObject* (* ICallMethod) (int32_t instanceID);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AnimatorClipInfo::InstanceIDToAnimationClipPPtr");
	Il2CppObject* i2res = icall(instanceID);
	MonoObject* monoi2res = get_mono_object(i2res,mono_get_class_UnityEngine_AnimationClip());
	if(i2res != NULL && monoi2res == NULL)
	{
		platform_log("UnityEngine.AnimatorClipInfo::InstanceIDToAnimationClipPPtr fail to convert il2cpp obj to mono");
	}
	return monoi2res;
}
MonoObject* UnityEngine_Animation_get_clip(MonoObject* thiz)
{
	typedef Il2CppObject* (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Animation::get_clip");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Animation());
	Il2CppObject* i2res = icall(i2thiz);
	MonoObject* monoi2res = get_mono_object(i2res,mono_get_class_UnityEngine_AnimationClip());
	if(i2res != NULL && monoi2res == NULL)
	{
		platform_log("UnityEngine.Animation::get_clip fail to convert il2cpp obj to mono");
	}
	return monoi2res;
}
void UnityEngine_Animation_set_wrapMode(MonoObject* thiz, int32_t value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, int32_t value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Animation::set_wrapMode");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Animation());
	icall(i2thiz,value);
}
bool UnityEngine_Animation_get_isPlaying(MonoObject* thiz)
{
	typedef bool (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Animation::get_isPlaying");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Animation());
	bool i2res = icall(i2thiz);
	return i2res;
}
void UnityEngine_Animation_Sample(MonoObject* thiz)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Animation::Sample");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Animation());
	icall(i2thiz);
}
bool UnityEngine_Animation_IsPlaying(MonoObject* thiz, MonoString* name)
{
	typedef bool (* ICallMethod) (Il2CppObject* thiz, Il2CppString* name);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Animation::IsPlaying");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Animation());
	Il2CppString* i2name = get_il2cpp_string(name);
	bool i2res = icall(i2thiz,i2name);
	return i2res;
}
bool UnityEngine_Animation_PlayDefaultAnimation(MonoObject* thiz, int32_t mode)
{
	typedef bool (* ICallMethod) (Il2CppObject* thiz, int32_t mode);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Animation::PlayDefaultAnimation");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Animation());
	bool i2res = icall(i2thiz,mode);
	return i2res;
}
bool UnityEngine_Animation_Play_1(MonoObject* thiz, MonoString* animation, int32_t mode)
{
	typedef bool (* ICallMethod) (Il2CppObject* thiz, Il2CppString* animation, int32_t mode);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Animation::Play");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Animation());
	Il2CppString* i2animation = get_il2cpp_string(animation);
	bool i2res = icall(i2thiz,i2animation,mode);
	return i2res;
}
float UnityEngine_AnimationClip_get_length(MonoObject* thiz)
{
	typedef float (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AnimationClip::get_length");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_AnimationClip());
	float i2res = icall(i2thiz);
	return i2res;
}
float UnityEngine_AnimationClip_get_frameRate(MonoObject* thiz)
{
	typedef float (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AnimationClip::get_frameRate");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_AnimationClip());
	float i2res = icall(i2thiz);
	return i2res;
}
void UnityEngine_AnimationClip_set_frameRate(MonoObject* thiz, float value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, float value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AnimationClip::set_frameRate");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_AnimationClip());
	icall(i2thiz,value);
}
void UnityEngine_AnimationClip_set_wrapMode_1(MonoObject* thiz, int32_t value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, int32_t value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AnimationClip::set_wrapMode");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_AnimationClip());
	icall(i2thiz,value);
}
bool UnityEngine_AnimationClip_get_legacy(MonoObject* thiz)
{
	typedef bool (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AnimationClip::get_legacy");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_AnimationClip());
	bool i2res = icall(i2thiz);
	return i2res;
}
void UnityEngine_AnimationClip_set_legacy(MonoObject* thiz, bool value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, bool value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AnimationClip::set_legacy");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_AnimationClip());
	icall(i2thiz,value);
}
bool UnityEngine_AnimationClip_get_empty(MonoObject* thiz)
{
	typedef bool (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AnimationClip::get_empty");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_AnimationClip());
	bool i2res = icall(i2thiz);
	return i2res;
}
bool UnityEngine_AnimationClip_get_hasGenericRootTransform(MonoObject* thiz)
{
	typedef bool (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AnimationClip::get_hasGenericRootTransform");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_AnimationClip());
	bool i2res = icall(i2thiz);
	return i2res;
}
bool UnityEngine_AnimationClip_get_hasMotionCurves(MonoObject* thiz)
{
	typedef bool (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AnimationClip::get_hasMotionCurves");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_AnimationClip());
	bool i2res = icall(i2thiz);
	return i2res;
}
bool UnityEngine_AnimationClip_get_hasRootCurves(MonoObject* thiz)
{
	typedef bool (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AnimationClip::get_hasRootCurves");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_AnimationClip());
	bool i2res = icall(i2thiz);
	return i2res;
}
void UnityEngine_AnimationClip_Internal_CreateAnimationClip(MonoObject* self)
{
	typedef void (* ICallMethod) (Il2CppObject* self);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AnimationClip::Internal_CreateAnimationClip");
	Il2CppObject* i2self = get_il2cpp_object(self,il2cpp_get_class_UnityEngine_AnimationClip());
	icall(i2self);
}
bool UnityEngine_Motion_get_isLooping(MonoObject* thiz)
{
	typedef bool (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Motion::get_isLooping");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Motion());
	bool i2res = icall(i2thiz);
	return i2res;
}
float UnityEngine_AnimationState_get_time(MonoObject* thiz)
{
	typedef float (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AnimationState::get_time");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_AnimationState());
	float i2res = icall(i2thiz);
	return i2res;
}
void UnityEngine_AnimationState_set_time(MonoObject* thiz, float value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, float value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AnimationState::set_time");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_AnimationState());
	icall(i2thiz,value);
}
float UnityEngine_AnimationState_get_speed(MonoObject* thiz)
{
	typedef float (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AnimationState::get_speed");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_AnimationState());
	float i2res = icall(i2thiz);
	return i2res;
}
void UnityEngine_AnimationState_set_speed_2(MonoObject* thiz, float value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, float value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AnimationState::set_speed");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_AnimationState());
	icall(i2thiz,value);
}
float UnityEngine_AnimationState_get_length_1(MonoObject* thiz)
{
	typedef float (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AnimationState::get_length");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_AnimationState());
	float i2res = icall(i2thiz);
	return i2res;
}
MonoString* UnityEngine_AnimationState_get_name(MonoObject* thiz)
{
	typedef Il2CppString* (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AnimationState::get_name");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_AnimationState());
	Il2CppString* i2res = icall(i2thiz);
	MonoString* monoi2res = get_mono_string(i2res);
	if(i2res != NULL && monoi2res == NULL)
	{
		platform_log("UnityEngine.AnimationState::get_name fail to convert il2cpp obj to mono");
	}
	return monoi2res;
}
int32_t UnityEngine_AvatarMask_get_transformCount(MonoObject* thiz)
{
	typedef int32_t (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AvatarMask::get_transformCount");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_AvatarMask());
	int32_t i2res = icall(i2thiz);
	return i2res;
}
bool UnityEngine_AvatarMask_GetHumanoidBodyPartActive(MonoObject* thiz, int32_t index)
{
	typedef bool (* ICallMethod) (Il2CppObject* thiz, int32_t index);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AvatarMask::GetHumanoidBodyPartActive");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_AvatarMask());
	bool i2res = icall(i2thiz,index);
	return i2res;
}
MonoString* UnityEngine_AvatarMask_GetTransformPath(MonoObject* thiz, int32_t index)
{
	typedef Il2CppString* (* ICallMethod) (Il2CppObject* thiz, int32_t index);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AvatarMask::GetTransformPath");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_AvatarMask());
	Il2CppString* i2res = icall(i2thiz,index);
	MonoString* monoi2res = get_mono_string(i2res);
	if(i2res != NULL && monoi2res == NULL)
	{
		platform_log("UnityEngine.AvatarMask::GetTransformPath fail to convert il2cpp obj to mono");
	}
	return monoi2res;
}
float UnityEngine_AvatarMask_GetTransformWeight(MonoObject* thiz, int32_t index)
{
	typedef float (* ICallMethod) (Il2CppObject* thiz, int32_t index);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AvatarMask::GetTransformWeight");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_AvatarMask());
	float i2res = icall(i2thiz,index);
	return i2res;
}
void UnityEngine_Animations_AnimationClipPlayable_SetApplyFootIKInternal(void * handle, bool value)
{
	typedef void (* ICallMethod) (void * handle, bool value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Animations.AnimationClipPlayable::SetApplyFootIKInternal");
	icall(handle,value);
}
void UnityEngine_Animations_AnimationClipPlayable_SetRemoveStartOffsetInternal(void * handle, bool value)
{
	typedef void (* ICallMethod) (void * handle, bool value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Animations.AnimationClipPlayable::SetRemoveStartOffsetInternal");
	icall(handle,value);
}
void UnityEngine_Animations_AnimationClipPlayable_SetOverrideLoopTimeInternal(void * handle, bool value)
{
	typedef void (* ICallMethod) (void * handle, bool value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Animations.AnimationClipPlayable::SetOverrideLoopTimeInternal");
	icall(handle,value);
}
void UnityEngine_Animations_AnimationClipPlayable_SetLoopTimeInternal(void * handle, bool value)
{
	typedef void (* ICallMethod) (void * handle, bool value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Animations.AnimationClipPlayable::SetLoopTimeInternal");
	icall(handle,value);
}
bool UnityEngine_Animations_AnimationClipPlayable_CreateHandleInternal_Injected(void * graph, MonoObject* clip, void * handle)
{
	typedef bool (* ICallMethod) (void * graph, Il2CppObject* clip, void * handle);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Animations.AnimationClipPlayable::CreateHandleInternal_Injected");
	Il2CppObject* i2clip = get_il2cpp_object(clip,il2cpp_get_class_UnityEngine_AnimationClip());
	bool i2res = icall(graph,i2clip,handle);
	return i2res;
}
void UnityEngine_Animations_AnimationLayerMixerPlayable_SetLayerMaskFromAvatarMaskInternal(void * handle, uint32_t layerIndex, MonoObject* mask)
{
	typedef void (* ICallMethod) (void * handle, uint32_t layerIndex, Il2CppObject* mask);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Animations.AnimationLayerMixerPlayable::SetLayerMaskFromAvatarMaskInternal");
	Il2CppObject* i2mask = get_il2cpp_object(mask,il2cpp_get_class_UnityEngine_AvatarMask());
	icall(handle,layerIndex,i2mask);
}
bool UnityEngine_Animations_AnimationLayerMixerPlayable_CreateHandleInternal_Injected_1(void * graph, void * handle)
{
	typedef bool (* ICallMethod) (void * graph, void * handle);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Animations.AnimationLayerMixerPlayable::CreateHandleInternal_Injected");
	bool i2res = icall(graph,handle);
	return i2res;
}
bool UnityEngine_Animations_AnimationMixerPlayable_CreateHandleInternal_Injected_2(void * graph, bool normalizeWeights, void * handle)
{
	typedef bool (* ICallMethod) (void * graph, bool normalizeWeights, void * handle);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Animations.AnimationMixerPlayable::CreateHandleInternal_Injected");
	bool i2res = icall(graph,normalizeWeights,handle);
	return i2res;
}
void UnityEngine_Animations_AnimationPlayableExtensions_SetAnimatedPropertiesInternal(void * playable, MonoObject* animatedProperties)
{
	typedef void (* ICallMethod) (void * playable, Il2CppObject* animatedProperties);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Animations.AnimationPlayableExtensions::SetAnimatedPropertiesInternal");
	Il2CppObject* i2animatedProperties = get_il2cpp_object(animatedProperties,il2cpp_get_class_UnityEngine_AnimationClip());
	icall(playable,i2animatedProperties);
}
bool UnityEngine_Animations_AnimationPlayableGraphExtensions_InternalCreateAnimationOutput(void * graph, MonoString* name, void * handle)
{
	typedef bool (* ICallMethod) (void * graph, Il2CppString* name, void * handle);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Animations.AnimationPlayableGraphExtensions::InternalCreateAnimationOutput");
	Il2CppString* i2name = get_il2cpp_string(name);
	bool i2res = icall(graph,i2name,handle);
	return i2res;
}
void UnityEngine_Animations_AnimationPlayableOutput_InternalSetTarget(void * handle, MonoObject* target)
{
	typedef void (* ICallMethod) (void * handle, Il2CppObject* target);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Animations.AnimationPlayableOutput::InternalSetTarget");
	Il2CppObject* i2target = get_il2cpp_object(target,il2cpp_get_class_UnityEngine_Animator());
	icall(handle,i2target);
}
bool UnityEngine_AssetBundle_get_isStreamedSceneAssetBundle(MonoObject* thiz)
{
	typedef bool (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AssetBundle::get_isStreamedSceneAssetBundle");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_AssetBundle());
	bool i2res = icall(i2thiz);
	return i2res;
}
MonoObject* UnityEngine_AssetBundle_returnMainAsset(MonoObject* bundle)
{
	typedef Il2CppObject* (* ICallMethod) (Il2CppObject* bundle);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AssetBundle::returnMainAsset");
	Il2CppObject* i2bundle = get_il2cpp_object(bundle,il2cpp_get_class_UnityEngine_AssetBundle());
	Il2CppObject* i2res = icall(i2bundle);
	MonoObject* monoi2res = get_mono_object(i2res,get_mono_class(il2cpp_object_get_class(i2res)));
	if(i2res != NULL && monoi2res == NULL)
	{
		platform_log("UnityEngine.AssetBundle::returnMainAsset fail to convert il2cpp obj to mono");
	}
	return monoi2res;
}
void UnityEngine_AssetBundle_UnloadAllAssetBundles(bool unloadAllObjects)
{
	typedef void (* ICallMethod) (bool unloadAllObjects);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AssetBundle::UnloadAllAssetBundles");
	icall(unloadAllObjects);
}
MonoArray* UnityEngine_AssetBundle_GetAllLoadedAssetBundles_Native()
{
	typedef Il2CppArray* (* ICallMethod) ();
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AssetBundle::GetAllLoadedAssetBundles_Native");
	Il2CppArray* i2res = icall();
	MonoArray* monoi2res = get_mono_array(i2res);
	if(i2res != NULL && monoi2res == NULL)
	{
		platform_log("UnityEngine.AssetBundle::GetAllLoadedAssetBundles_Native fail to convert il2cpp obj to mono");
	}
	return monoi2res;
}
MonoObject* UnityEngine_AssetBundle_LoadFromFileAsync_Internal(MonoString* path, uint32_t crc, uint64_t offset)
{
	typedef Il2CppObject* (* ICallMethod) (Il2CppString* path, uint32_t crc, uint64_t offset);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AssetBundle::LoadFromFileAsync_Internal");
	Il2CppString* i2path = get_il2cpp_string(path);
	Il2CppObject* i2res = icall(i2path,crc,offset);
	MonoObject* monoi2res = get_mono_object(i2res,mono_get_class_UnityEngine_AssetBundleCreateRequest());
	if(i2res != NULL && monoi2res == NULL)
	{
		platform_log("UnityEngine.AssetBundle::LoadFromFileAsync_Internal fail to convert il2cpp obj to mono");
	}
	return monoi2res;
}
MonoObject* UnityEngine_AssetBundle_LoadFromFile_Internal(MonoString* path, uint32_t crc, uint64_t offset)
{
	typedef Il2CppObject* (* ICallMethod) (Il2CppString* path, uint32_t crc, uint64_t offset);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AssetBundle::LoadFromFile_Internal");
	Il2CppString* i2path = get_il2cpp_string(path);
	Il2CppObject* i2res = icall(i2path,crc,offset);
	MonoObject* monoi2res = get_mono_object(i2res,mono_get_class_UnityEngine_AssetBundle());
	if(i2res != NULL && monoi2res == NULL)
	{
		platform_log("UnityEngine.AssetBundle::LoadFromFile_Internal fail to convert il2cpp obj to mono");
	}
	return monoi2res;
}
MonoObject* UnityEngine_AssetBundle_LoadFromMemoryAsync_Internal(MonoArray* binary, uint32_t crc)
{
	typedef Il2CppObject* (* ICallMethod) (Il2CppArray* binary, uint32_t crc);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AssetBundle::LoadFromMemoryAsync_Internal");
	Il2CppArray* i2binary = get_il2cpp_array(binary);
	Il2CppObject* i2res = icall(i2binary,crc);
	MonoObject* monoi2res = get_mono_object(i2res,mono_get_class_UnityEngine_AssetBundleCreateRequest());
	if(i2res != NULL && monoi2res == NULL)
	{
		platform_log("UnityEngine.AssetBundle::LoadFromMemoryAsync_Internal fail to convert il2cpp obj to mono");
	}
	return monoi2res;
}
MonoObject* UnityEngine_AssetBundle_LoadFromMemory_Internal(MonoArray* binary, uint32_t crc)
{
	typedef Il2CppObject* (* ICallMethod) (Il2CppArray* binary, uint32_t crc);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AssetBundle::LoadFromMemory_Internal");
	Il2CppArray* i2binary = get_il2cpp_array(binary);
	Il2CppObject* i2res = icall(i2binary,crc);
	MonoObject* monoi2res = get_mono_object(i2res,mono_get_class_UnityEngine_AssetBundle());
	if(i2res != NULL && monoi2res == NULL)
	{
		platform_log("UnityEngine.AssetBundle::LoadFromMemory_Internal fail to convert il2cpp obj to mono");
	}
	return monoi2res;
}
MonoObject* UnityEngine_AssetBundle_LoadFromStreamAsyncInternal(MonoObject* stream, uint32_t crc, uint32_t managedReadBufferSize)
{
	typedef Il2CppObject* (* ICallMethod) (Il2CppObject* stream, uint32_t crc, uint32_t managedReadBufferSize);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AssetBundle::LoadFromStreamAsyncInternal");
	Il2CppObject* i2stream = get_il2cpp_object(stream,NULL);
	Il2CppObject* i2res = icall(i2stream,crc,managedReadBufferSize);
	MonoObject* monoi2res = get_mono_object(i2res,mono_get_class_UnityEngine_AssetBundleCreateRequest());
	if(i2res != NULL && monoi2res == NULL)
	{
		platform_log("UnityEngine.AssetBundle::LoadFromStreamAsyncInternal fail to convert il2cpp obj to mono");
	}
	return monoi2res;
}
MonoObject* UnityEngine_AssetBundle_LoadFromStreamInternal(MonoObject* stream, uint32_t crc, uint32_t managedReadBufferSize)
{
	typedef Il2CppObject* (* ICallMethod) (Il2CppObject* stream, uint32_t crc, uint32_t managedReadBufferSize);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AssetBundle::LoadFromStreamInternal");
	Il2CppObject* i2stream = get_il2cpp_object(stream,NULL);
	Il2CppObject* i2res = icall(i2stream,crc,managedReadBufferSize);
	MonoObject* monoi2res = get_mono_object(i2res,mono_get_class_UnityEngine_AssetBundle());
	if(i2res != NULL && monoi2res == NULL)
	{
		platform_log("UnityEngine.AssetBundle::LoadFromStreamInternal fail to convert il2cpp obj to mono");
	}
	return monoi2res;
}
bool UnityEngine_AssetBundle_Contains(MonoObject* thiz, MonoString* name)
{
	typedef bool (* ICallMethod) (Il2CppObject* thiz, Il2CppString* name);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AssetBundle::Contains");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_AssetBundle());
	Il2CppString* i2name = get_il2cpp_string(name);
	bool i2res = icall(i2thiz,i2name);
	return i2res;
}
MonoObject* UnityEngine_AssetBundle_LoadAsset_Internal(MonoObject* thiz, MonoString* name, MonoReflectionType* type)
{
	typedef Il2CppObject* (* ICallMethod) (Il2CppObject* thiz, Il2CppString* name, Il2CppReflectionType* type);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AssetBundle::LoadAsset_Internal");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_AssetBundle());
	Il2CppString* i2name = get_il2cpp_string(name);
	Il2CppReflectionType* i2type = get_il2cpp_reflection_type(type);
	Il2CppObject* i2res = icall(i2thiz,i2name,i2type);
	MonoObject* monoi2res = get_mono_object(i2res,get_mono_class(il2cpp_object_get_class(i2res)));
	if(i2res != NULL && monoi2res == NULL)
	{
		platform_log("UnityEngine.AssetBundle::LoadAsset_Internal fail to convert il2cpp obj to mono");
	}
	return monoi2res;
}
MonoObject* UnityEngine_AssetBundle_LoadAssetAsync_Internal(MonoObject* thiz, MonoString* name, MonoReflectionType* type)
{
	typedef Il2CppObject* (* ICallMethod) (Il2CppObject* thiz, Il2CppString* name, Il2CppReflectionType* type);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AssetBundle::LoadAssetAsync_Internal");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_AssetBundle());
	Il2CppString* i2name = get_il2cpp_string(name);
	Il2CppReflectionType* i2type = get_il2cpp_reflection_type(type);
	Il2CppObject* i2res = icall(i2thiz,i2name,i2type);
	MonoObject* monoi2res = get_mono_object(i2res,mono_get_class_UnityEngine_AssetBundleRequest());
	if(i2res != NULL && monoi2res == NULL)
	{
		platform_log("UnityEngine.AssetBundle::LoadAssetAsync_Internal fail to convert il2cpp obj to mono");
	}
	return monoi2res;
}
void UnityEngine_AssetBundle_Unload(MonoObject* thiz, bool unloadAllLoadedObjects)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, bool unloadAllLoadedObjects);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AssetBundle::Unload");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_AssetBundle());
	icall(i2thiz,unloadAllLoadedObjects);
}
MonoObject* UnityEngine_AssetBundle_UnloadAsync(MonoObject* thiz, bool unloadAllLoadedObjects)
{
	typedef Il2CppObject* (* ICallMethod) (Il2CppObject* thiz, bool unloadAllLoadedObjects);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AssetBundle::UnloadAsync");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_AssetBundle());
	Il2CppObject* i2res = icall(i2thiz,unloadAllLoadedObjects);
	MonoObject* monoi2res = get_mono_object(i2res,mono_get_class_UnityEngine_AsyncOperation());
	if(i2res != NULL && monoi2res == NULL)
	{
		platform_log("UnityEngine.AssetBundle::UnloadAsync fail to convert il2cpp obj to mono");
	}
	return monoi2res;
}
MonoArray* UnityEngine_AssetBundle_GetAllAssetNames(MonoObject* thiz)
{
	typedef Il2CppArray* (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AssetBundle::GetAllAssetNames");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_AssetBundle());
	Il2CppArray* i2res = icall(i2thiz);
	MonoArray* monoi2res = get_mono_array(i2res);
	if(i2res != NULL && monoi2res == NULL)
	{
		platform_log("UnityEngine.AssetBundle::GetAllAssetNames fail to convert il2cpp obj to mono");
	}
	return monoi2res;
}
MonoArray* UnityEngine_AssetBundle_GetAllScenePaths(MonoObject* thiz)
{
	typedef Il2CppArray* (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AssetBundle::GetAllScenePaths");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_AssetBundle());
	Il2CppArray* i2res = icall(i2thiz);
	MonoArray* monoi2res = get_mono_array(i2res);
	if(i2res != NULL && monoi2res == NULL)
	{
		platform_log("UnityEngine.AssetBundle::GetAllScenePaths fail to convert il2cpp obj to mono");
	}
	return monoi2res;
}
MonoArray* UnityEngine_AssetBundle_LoadAssetWithSubAssets_Internal(MonoObject* thiz, MonoString* name, MonoReflectionType* type)
{
	typedef Il2CppArray* (* ICallMethod) (Il2CppObject* thiz, Il2CppString* name, Il2CppReflectionType* type);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AssetBundle::LoadAssetWithSubAssets_Internal");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_AssetBundle());
	Il2CppString* i2name = get_il2cpp_string(name);
	Il2CppReflectionType* i2type = get_il2cpp_reflection_type(type);
	Il2CppArray* i2res = icall(i2thiz,i2name,i2type);
	MonoArray* monoi2res = get_mono_array(i2res);
	if(i2res != NULL && monoi2res == NULL)
	{
		platform_log("UnityEngine.AssetBundle::LoadAssetWithSubAssets_Internal fail to convert il2cpp obj to mono");
	}
	return monoi2res;
}
MonoObject* UnityEngine_AssetBundle_LoadAssetWithSubAssetsAsync_Internal(MonoObject* thiz, MonoString* name, MonoReflectionType* type)
{
	typedef Il2CppObject* (* ICallMethod) (Il2CppObject* thiz, Il2CppString* name, Il2CppReflectionType* type);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AssetBundle::LoadAssetWithSubAssetsAsync_Internal");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_AssetBundle());
	Il2CppString* i2name = get_il2cpp_string(name);
	Il2CppReflectionType* i2type = get_il2cpp_reflection_type(type);
	Il2CppObject* i2res = icall(i2thiz,i2name,i2type);
	MonoObject* monoi2res = get_mono_object(i2res,mono_get_class_UnityEngine_AssetBundleRequest());
	if(i2res != NULL && monoi2res == NULL)
	{
		platform_log("UnityEngine.AssetBundle::LoadAssetWithSubAssetsAsync_Internal fail to convert il2cpp obj to mono");
	}
	return monoi2res;
}
MonoObject* UnityEngine_AssetBundle_RecompressAssetBundleAsync_Internal_Injected(MonoString* inputPath, MonoString* outputPath, void * method, uint32_t expectedCRC, int32_t priority)
{
	typedef Il2CppObject* (* ICallMethod) (Il2CppString* inputPath, Il2CppString* outputPath, void * method, uint32_t expectedCRC, int32_t priority);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AssetBundle::RecompressAssetBundleAsync_Internal_Injected");
	Il2CppString* i2inputPath = get_il2cpp_string(inputPath);
	Il2CppString* i2outputPath = get_il2cpp_string(outputPath);
	Il2CppObject* i2res = icall(i2inputPath,i2outputPath,method,expectedCRC,priority);
	MonoObject* monoi2res = get_mono_object(i2res,mono_get_class_UnityEngine_AssetBundleRecompressOperation());
	if(i2res != NULL && monoi2res == NULL)
	{
		platform_log("UnityEngine.AssetBundle::RecompressAssetBundleAsync_Internal_Injected fail to convert il2cpp obj to mono");
	}
	return monoi2res;
}
uint32_t UnityEngine_AssetBundleLoadingCache_get_maxBlocksPerFile()
{
	typedef uint32_t (* ICallMethod) ();
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AssetBundleLoadingCache::get_maxBlocksPerFile");
	uint32_t i2res = icall();
	return i2res;
}
void UnityEngine_AssetBundleLoadingCache_set_maxBlocksPerFile(uint32_t value)
{
	typedef void (* ICallMethod) (uint32_t value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AssetBundleLoadingCache::set_maxBlocksPerFile");
	icall(value);
}
uint32_t UnityEngine_AssetBundleLoadingCache_get_blockCount()
{
	typedef uint32_t (* ICallMethod) ();
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AssetBundleLoadingCache::get_blockCount");
	uint32_t i2res = icall();
	return i2res;
}
void UnityEngine_AssetBundleLoadingCache_set_blockCount(uint32_t value)
{
	typedef void (* ICallMethod) (uint32_t value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AssetBundleLoadingCache::set_blockCount");
	icall(value);
}
uint32_t UnityEngine_AssetBundleLoadingCache_get_blockSize()
{
	typedef uint32_t (* ICallMethod) ();
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AssetBundleLoadingCache::get_blockSize");
	uint32_t i2res = icall();
	return i2res;
}
bool UnityEngine_AudioSettings_StartAudioOutput()
{
	typedef bool (* ICallMethod) ();
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AudioSettings::StartAudioOutput");
	bool i2res = icall();
	return i2res;
}
bool UnityEngine_AudioSettings_StopAudioOutput()
{
	typedef bool (* ICallMethod) ();
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AudioSettings::StopAudioOutput");
	bool i2res = icall();
	return i2res;
}
float UnityEngine_AudioClip_get_length_2(MonoObject* thiz)
{
	typedef float (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AudioClip::get_length");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_AudioClip());
	float i2res = icall(i2thiz);
	return i2res;
}
int32_t UnityEngine_AudioClip_get_samples(MonoObject* thiz)
{
	typedef int32_t (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AudioClip::get_samples");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_AudioClip());
	int32_t i2res = icall(i2thiz);
	return i2res;
}
int32_t UnityEngine_AudioClip_get_channels(MonoObject* thiz)
{
	typedef int32_t (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AudioClip::get_channels");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_AudioClip());
	int32_t i2res = icall(i2thiz);
	return i2res;
}
float UnityEngine_AudioSource_get_volume(MonoObject* thiz)
{
	typedef float (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AudioSource::get_volume");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_AudioSource());
	float i2res = icall(i2thiz);
	return i2res;
}
void UnityEngine_AudioSource_set_volume(MonoObject* thiz, float value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, float value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AudioSource::set_volume");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_AudioSource());
	icall(i2thiz,value);
}
MonoObject* UnityEngine_AudioSource_get_clip_1(MonoObject* thiz)
{
	typedef Il2CppObject* (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AudioSource::get_clip");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_AudioSource());
	Il2CppObject* i2res = icall(i2thiz);
	MonoObject* monoi2res = get_mono_object(i2res,mono_get_class_UnityEngine_AudioClip());
	if(i2res != NULL && monoi2res == NULL)
	{
		platform_log("UnityEngine.AudioSource::get_clip fail to convert il2cpp obj to mono");
	}
	return monoi2res;
}
void UnityEngine_AudioSource_set_clip(MonoObject* thiz, MonoObject* value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, Il2CppObject* value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AudioSource::set_clip");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_AudioSource());
	Il2CppObject* i2value = get_il2cpp_object(value,il2cpp_get_class_UnityEngine_AudioClip());
	icall(i2thiz,i2value);
}
bool UnityEngine_AudioSource_get_isPlaying_1(MonoObject* thiz)
{
	typedef bool (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AudioSource::get_isPlaying");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_AudioSource());
	bool i2res = icall(i2thiz);
	return i2res;
}
void UnityEngine_AudioSource_set_loop(MonoObject* thiz, bool value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, bool value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AudioSource::set_loop");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_AudioSource());
	icall(i2thiz,value);
}
void UnityEngine_AudioSource_set_playOnAwake(MonoObject* thiz, bool value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, bool value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AudioSource::set_playOnAwake");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_AudioSource());
	icall(i2thiz,value);
}
void UnityEngine_AudioSource_set_priority(MonoObject* thiz, int32_t value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, int32_t value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AudioSource::set_priority");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_AudioSource());
	icall(i2thiz,value);
}
void UnityEngine_AudioSource_PlayHelper(MonoObject* source, uint64_t delay)
{
	typedef void (* ICallMethod) (Il2CppObject* source, uint64_t delay);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AudioSource::PlayHelper");
	Il2CppObject* i2source = get_il2cpp_object(source,il2cpp_get_class_UnityEngine_AudioSource());
	icall(i2source,delay);
}
void UnityEngine_AudioSource_Play_2(MonoObject* thiz, double delay)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, double delay);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AudioSource::Play");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_AudioSource());
	icall(i2thiz,delay);
}
void UnityEngine_AudioSource_Stop(MonoObject* thiz, bool stopOneShots)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, bool stopOneShots);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AudioSource::Stop");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_AudioSource());
	icall(i2thiz,stopOneShots);
}
void UnityEngine_AudioSource_Pause(MonoObject* thiz)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AudioSource::Pause");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_AudioSource());
	icall(i2thiz);
}
MonoArray* UnityEngine_Microphone_get_devices()
{
	typedef Il2CppArray* (* ICallMethod) ();
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Microphone::get_devices");
	Il2CppArray* i2res = icall();
	MonoArray* monoi2res = get_mono_array(i2res);
	if(i2res != NULL && monoi2res == NULL)
	{
		platform_log("UnityEngine.Microphone::get_devices fail to convert il2cpp obj to mono");
	}
	return monoi2res;
}
int32_t UnityEngine_Microphone_GetMicrophoneDeviceIDFromName(MonoString* name)
{
	typedef int32_t (* ICallMethod) (Il2CppString* name);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Microphone::GetMicrophoneDeviceIDFromName");
	Il2CppString* i2name = get_il2cpp_string(name);
	int32_t i2res = icall(i2name);
	return i2res;
}
void UnityEngine_Microphone_EndRecord(int32_t deviceID)
{
	typedef void (* ICallMethod) (int32_t deviceID);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Microphone::EndRecord");
	icall(deviceID);
}
bool UnityEngine_Microphone_IsRecording(int32_t deviceID)
{
	typedef bool (* ICallMethod) (int32_t deviceID);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Microphone::IsRecording");
	bool i2res = icall(deviceID);
	return i2res;
}
void UnityEngine_Audio_AudioPlayableOutput_InternalSetEvaluateOnSeek(void * output, bool value)
{
	typedef void (* ICallMethod) (void * output, bool value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Audio.AudioPlayableOutput::InternalSetEvaluateOnSeek");
	icall(output,value);
}
int32_t UnityEngine_SortingLayer_GetLayerValueFromID(int32_t id)
{
	typedef int32_t (* ICallMethod) (int32_t id);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.SortingLayer::GetLayerValueFromID");
	int32_t i2res = icall(id);
	return i2res;
}
int32_t UnityEngine_AnimationCurve_get_length_3(MonoObject* thiz)
{
	typedef int32_t (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AnimationCurve::get_length");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_AnimationCurve());
	int32_t i2res = icall(i2thiz);
	return i2res;
}
float UnityEngine_AnimationCurve_Evaluate(MonoObject* thiz, float time)
{
	typedef float (* ICallMethod) (Il2CppObject* thiz, float time);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AnimationCurve::Evaluate");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_AnimationCurve());
	float i2res = icall(i2thiz,time);
	return i2res;
}
bool UnityEngine_Application_get_isPlaying_2()
{
	typedef bool (* ICallMethod) ();
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Application::get_isPlaying");
	bool i2res = icall();
	return i2res;
}
bool UnityEngine_Application_get_isBatchMode()
{
	typedef bool (* ICallMethod) ();
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Application::get_isBatchMode");
	bool i2res = icall();
	return i2res;
}
MonoString* UnityEngine_Application_get_dataPath()
{
	typedef Il2CppString* (* ICallMethod) ();
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Application::get_dataPath");
	Il2CppString* i2res = icall();
	MonoString* monoi2res = get_mono_string(i2res);
	if(i2res != NULL && monoi2res == NULL)
	{
		platform_log("UnityEngine.Application::get_dataPath fail to convert il2cpp obj to mono");
	}
	return monoi2res;
}
MonoString* UnityEngine_Application_get_streamingAssetsPath()
{
	typedef Il2CppString* (* ICallMethod) ();
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Application::get_streamingAssetsPath");
	Il2CppString* i2res = icall();
	MonoString* monoi2res = get_mono_string(i2res);
	if(i2res != NULL && monoi2res == NULL)
	{
		platform_log("UnityEngine.Application::get_streamingAssetsPath fail to convert il2cpp obj to mono");
	}
	return monoi2res;
}
MonoString* UnityEngine_Application_get_persistentDataPath()
{
	typedef Il2CppString* (* ICallMethod) ();
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Application::get_persistentDataPath");
	Il2CppString* i2res = icall();
	MonoString* monoi2res = get_mono_string(i2res);
	if(i2res != NULL && monoi2res == NULL)
	{
		platform_log("UnityEngine.Application::get_persistentDataPath fail to convert il2cpp obj to mono");
	}
	return monoi2res;
}
MonoString* UnityEngine_Application_get_unityVersion()
{
	typedef Il2CppString* (* ICallMethod) ();
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Application::get_unityVersion");
	Il2CppString* i2res = icall();
	MonoString* monoi2res = get_mono_string(i2res);
	if(i2res != NULL && monoi2res == NULL)
	{
		platform_log("UnityEngine.Application::get_unityVersion fail to convert il2cpp obj to mono");
	}
	return monoi2res;
}
MonoString* UnityEngine_Application_get_identifier()
{
	typedef Il2CppString* (* ICallMethod) ();
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Application::get_identifier");
	Il2CppString* i2res = icall();
	MonoString* monoi2res = get_mono_string(i2res);
	if(i2res != NULL && monoi2res == NULL)
	{
		platform_log("UnityEngine.Application::get_identifier fail to convert il2cpp obj to mono");
	}
	return monoi2res;
}
int32_t UnityEngine_Application_get_targetFrameRate()
{
	typedef int32_t (* ICallMethod) ();
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Application::get_targetFrameRate");
	int32_t i2res = icall();
	return i2res;
}
void UnityEngine_Application_set_targetFrameRate(int32_t value)
{
	typedef void (* ICallMethod) (int32_t value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Application::set_targetFrameRate");
	icall(value);
}
int32_t UnityEngine_Application_get_platform()
{
	typedef int32_t (* ICallMethod) ();
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Application::get_platform");
	int32_t i2res = icall();
	return i2res;
}
int32_t UnityEngine_Application_get_internetReachability()
{
	typedef int32_t (* ICallMethod) ();
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Application::get_internetReachability");
	int32_t i2res = icall();
	return i2res;
}
void UnityEngine_Application_OpenURL(MonoString* url)
{
	typedef void (* ICallMethod) (Il2CppString* url);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Application::OpenURL");
	Il2CppString* i2url = get_il2cpp_string(url);
	icall(i2url);
}
bool UnityEngine_Caching_ClearCache()
{
	typedef bool (* ICallMethod) ();
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Caching::ClearCache");
	bool i2res = icall();
	return i2res;
}
float UnityEngine_Camera_get_nearClipPlane(MonoObject* thiz)
{
	typedef float (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Camera::get_nearClipPlane");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Camera());
	float i2res = icall(i2thiz);
	return i2res;
}
void UnityEngine_Camera_set_nearClipPlane(MonoObject* thiz, float value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, float value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Camera::set_nearClipPlane");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Camera());
	icall(i2thiz,value);
}
float UnityEngine_Camera_get_farClipPlane(MonoObject* thiz)
{
	typedef float (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Camera::get_farClipPlane");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Camera());
	float i2res = icall(i2thiz);
	return i2res;
}
void UnityEngine_Camera_set_farClipPlane(MonoObject* thiz, float value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, float value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Camera::set_farClipPlane");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Camera());
	icall(i2thiz,value);
}
float UnityEngine_Camera_get_fieldOfView(MonoObject* thiz)
{
	typedef float (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Camera::get_fieldOfView");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Camera());
	float i2res = icall(i2thiz);
	return i2res;
}
void UnityEngine_Camera_set_fieldOfView(MonoObject* thiz, float value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, float value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Camera::set_fieldOfView");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Camera());
	icall(i2thiz,value);
}
void UnityEngine_Camera_set_renderingPath(MonoObject* thiz, int32_t value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, int32_t value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Camera::set_renderingPath");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Camera());
	icall(i2thiz,value);
}
void UnityEngine_Camera_set_allowHDR(MonoObject* thiz, bool value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, bool value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Camera::set_allowHDR");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Camera());
	icall(i2thiz,value);
}
float UnityEngine_Camera_get_orthographicSize(MonoObject* thiz)
{
	typedef float (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Camera::get_orthographicSize");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Camera());
	float i2res = icall(i2thiz);
	return i2res;
}
void UnityEngine_Camera_set_orthographicSize(MonoObject* thiz, float value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, float value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Camera::set_orthographicSize");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Camera());
	icall(i2thiz,value);
}
bool UnityEngine_Camera_get_orthographic(MonoObject* thiz)
{
	typedef bool (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Camera::get_orthographic");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Camera());
	bool i2res = icall(i2thiz);
	return i2res;
}
void UnityEngine_Camera_set_orthographic(MonoObject* thiz, bool value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, bool value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Camera::set_orthographic");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Camera());
	icall(i2thiz,value);
}
int32_t UnityEngine_Camera_get_transparencySortMode(MonoObject* thiz)
{
	typedef int32_t (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Camera::get_transparencySortMode");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Camera());
	int32_t i2res = icall(i2thiz);
	return i2res;
}
void UnityEngine_Camera_set_transparencySortMode(MonoObject* thiz, int32_t value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, int32_t value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Camera::set_transparencySortMode");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Camera());
	icall(i2thiz,value);
}
float UnityEngine_Camera_get_depth(MonoObject* thiz)
{
	typedef float (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Camera::get_depth");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Camera());
	float i2res = icall(i2thiz);
	return i2res;
}
void UnityEngine_Camera_set_depth(MonoObject* thiz, float value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, float value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Camera::set_depth");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Camera());
	icall(i2thiz,value);
}
float UnityEngine_Camera_get_aspect(MonoObject* thiz)
{
	typedef float (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Camera::get_aspect");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Camera());
	float i2res = icall(i2thiz);
	return i2res;
}
int32_t UnityEngine_Camera_get_cullingMask(MonoObject* thiz)
{
	typedef int32_t (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Camera::get_cullingMask");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Camera());
	int32_t i2res = icall(i2thiz);
	return i2res;
}
void UnityEngine_Camera_set_cullingMask(MonoObject* thiz, int32_t value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, int32_t value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Camera::set_cullingMask");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Camera());
	icall(i2thiz,value);
}
int32_t UnityEngine_Camera_get_eventMask(MonoObject* thiz)
{
	typedef int32_t (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Camera::get_eventMask");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Camera());
	int32_t i2res = icall(i2thiz);
	return i2res;
}
void UnityEngine_Camera_set_eventMask(MonoObject* thiz, int32_t value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, int32_t value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Camera::set_eventMask");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Camera());
	icall(i2thiz,value);
}
void UnityEngine_Camera_set_useOcclusionCulling(MonoObject* thiz, bool value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, bool value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Camera::set_useOcclusionCulling");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Camera());
	icall(i2thiz,value);
}
int32_t UnityEngine_Camera_get_clearFlags(MonoObject* thiz)
{
	typedef int32_t (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Camera::get_clearFlags");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Camera());
	int32_t i2res = icall(i2thiz);
	return i2res;
}
void UnityEngine_Camera_set_clearFlags(MonoObject* thiz, int32_t value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, int32_t value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Camera::set_clearFlags");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Camera());
	icall(i2thiz,value);
}
int32_t UnityEngine_Camera_get_depthTextureMode(MonoObject* thiz)
{
	typedef int32_t (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Camera::get_depthTextureMode");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Camera());
	int32_t i2res = icall(i2thiz);
	return i2res;
}
void UnityEngine_Camera_set_depthTextureMode(MonoObject* thiz, int32_t value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, int32_t value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Camera::set_depthTextureMode");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Camera());
	icall(i2thiz,value);
}
int32_t UnityEngine_Camera_get_pixelWidth(MonoObject* thiz)
{
	typedef int32_t (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Camera::get_pixelWidth");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Camera());
	int32_t i2res = icall(i2thiz);
	return i2res;
}
int32_t UnityEngine_Camera_get_pixelHeight(MonoObject* thiz)
{
	typedef int32_t (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Camera::get_pixelHeight");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Camera());
	int32_t i2res = icall(i2thiz);
	return i2res;
}
MonoObject* UnityEngine_Camera_get_targetTexture(MonoObject* thiz)
{
	typedef Il2CppObject* (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Camera::get_targetTexture");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Camera());
	Il2CppObject* i2res = icall(i2thiz);
	MonoObject* monoi2res = get_mono_object(i2res,mono_get_class_UnityEngine_RenderTexture());
	if(i2res != NULL && monoi2res == NULL)
	{
		platform_log("UnityEngine.Camera::get_targetTexture fail to convert il2cpp obj to mono");
	}
	return monoi2res;
}
void UnityEngine_Camera_set_targetTexture(MonoObject* thiz, MonoObject* value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, Il2CppObject* value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Camera::set_targetTexture");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Camera());
	Il2CppObject* i2value = get_il2cpp_object(value,il2cpp_get_class_UnityEngine_RenderTexture());
	icall(i2thiz,i2value);
}
int32_t UnityEngine_Camera_get_targetDisplay(MonoObject* thiz)
{
	typedef int32_t (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Camera::get_targetDisplay");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Camera());
	int32_t i2res = icall(i2thiz);
	return i2res;
}
MonoObject* UnityEngine_Camera_get_main()
{
	typedef Il2CppObject* (* ICallMethod) ();
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Camera::get_main");
	Il2CppObject* i2res = icall();
	MonoObject* monoi2res = get_mono_object(i2res,mono_get_class_UnityEngine_Camera());
	if(i2res != NULL && monoi2res == NULL)
	{
		platform_log("UnityEngine.Camera::get_main fail to convert il2cpp obj to mono");
	}
	return monoi2res;
}
void UnityEngine_Camera_WorldToScreenPoint_Injected(MonoObject* thiz, void * position, int32_t eye, void * ret)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, void * position, int32_t eye, void * ret);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Camera::WorldToScreenPoint_Injected");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Camera());
	icall(i2thiz,position,eye,ret);
}
void UnityEngine_Camera_WorldToViewportPoint_Injected(MonoObject* thiz, void * position, int32_t eye, void * ret)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, void * position, int32_t eye, void * ret);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Camera::WorldToViewportPoint_Injected");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Camera());
	icall(i2thiz,position,eye,ret);
}
void UnityEngine_Camera_ViewportToWorldPoint_Injected(MonoObject* thiz, void * position, int32_t eye, void * ret)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, void * position, int32_t eye, void * ret);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Camera::ViewportToWorldPoint_Injected");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Camera());
	icall(i2thiz,position,eye,ret);
}
void UnityEngine_Camera_ScreenToWorldPoint_Injected(MonoObject* thiz, void * position, int32_t eye, void * ret)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, void * position, int32_t eye, void * ret);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Camera::ScreenToWorldPoint_Injected");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Camera());
	icall(i2thiz,position,eye,ret);
}
void UnityEngine_Camera_ScreenToViewportPoint_Injected(MonoObject* thiz, void * position, void * ret)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, void * position, void * ret);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Camera::ScreenToViewportPoint_Injected");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Camera());
	icall(i2thiz,position,ret);
}
void UnityEngine_Camera_Render(MonoObject* thiz)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Camera::Render");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Camera());
	icall(i2thiz);
}
void UnityEngine_Camera_CopyFrom(MonoObject* thiz, MonoObject* other)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, Il2CppObject* other);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Camera::CopyFrom");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Camera());
	Il2CppObject* i2other = get_il2cpp_object(other,il2cpp_get_class_UnityEngine_Camera());
	icall(i2thiz,i2other);
}
float UnityEngine_Mathf_GammaToLinearSpace(float value)
{
	typedef float (* ICallMethod) (float value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Mathf::GammaToLinearSpace");
	float i2res = icall(value);
	return i2res;
}
float UnityEngine_Mathf_PerlinNoise(float x, float y)
{
	typedef float (* ICallMethod) (float x, float y);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Mathf::PerlinNoise");
	float i2res = icall(x,y);
	return i2res;
}
int32_t UnityEngine_RenderTexture_get_width(MonoObject* thiz)
{
	typedef int32_t (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.RenderTexture::get_width");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_RenderTexture());
	int32_t i2res = icall(i2thiz);
	return i2res;
}
void UnityEngine_RenderTexture_set_width(MonoObject* thiz, int32_t value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, int32_t value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.RenderTexture::set_width");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_RenderTexture());
	icall(i2thiz,value);
}
int32_t UnityEngine_RenderTexture_get_height(MonoObject* thiz)
{
	typedef int32_t (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.RenderTexture::get_height");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_RenderTexture());
	int32_t i2res = icall(i2thiz);
	return i2res;
}
void UnityEngine_RenderTexture_set_height(MonoObject* thiz, int32_t value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, int32_t value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.RenderTexture::set_height");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_RenderTexture());
	icall(i2thiz,value);
}
void UnityEngine_RenderTexture_set_graphicsFormat(MonoObject* thiz, int32_t value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, int32_t value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.RenderTexture::set_graphicsFormat");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_RenderTexture());
	icall(i2thiz,value);
}
void UnityEngine_RenderTexture_set_depth_1(MonoObject* thiz, int32_t value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, int32_t value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.RenderTexture::set_depth");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_RenderTexture());
	icall(i2thiz,value);
}
void UnityEngine_RenderTexture_ReleaseTemporary(MonoObject* temp)
{
	typedef void (* ICallMethod) (Il2CppObject* temp);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.RenderTexture::ReleaseTemporary");
	Il2CppObject* i2temp = get_il2cpp_object(temp,il2cpp_get_class_UnityEngine_RenderTexture());
	icall(i2temp);
}
void UnityEngine_QualitySettings_set_shadows(int32_t value)
{
	typedef void (* ICallMethod) (int32_t value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.QualitySettings::set_shadows");
	icall(value);
}
void UnityEngine_QualitySettings_set_vSyncCount(int32_t value)
{
	typedef void (* ICallMethod) (int32_t value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.QualitySettings::set_vSyncCount");
	icall(value);
}
int32_t UnityEngine_QualitySettings_get_activeColorSpace()
{
	typedef int32_t (* ICallMethod) ();
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.QualitySettings::get_activeColorSpace");
	int32_t i2res = icall();
	return i2res;
}
void UnityEngine_QualitySettings_SetQualityLevel(int32_t index, bool applyExpensiveChanges)
{
	typedef void (* ICallMethod) (int32_t index, bool applyExpensiveChanges);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.QualitySettings::SetQualityLevel");
	icall(index,applyExpensiveChanges);
}
bool UnityEngine_SystemInfo_IsFormatSupported(int32_t format, int32_t usage)
{
	typedef bool (* ICallMethod) (int32_t format, int32_t usage);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.SystemInfo::IsFormatSupported");
	bool i2res = icall(format,usage);
	return i2res;
}
int32_t UnityEngine_SystemInfo_GetCompatibleFormat(int32_t format, int32_t usage)
{
	typedef int32_t (* ICallMethod) (int32_t format, int32_t usage);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.SystemInfo::GetCompatibleFormat");
	int32_t i2res = icall(format,usage);
	return i2res;
}
int32_t UnityEngine_SystemInfo_GetGraphicsFormat(int32_t format)
{
	typedef int32_t (* ICallMethod) (int32_t format);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.SystemInfo::GetGraphicsFormat");
	int32_t i2res = icall(format);
	return i2res;
}
void UnityEngine_Matrix4x4_TRS_Injected(void * pos, void * q, void * s, void * ret)
{
	typedef void (* ICallMethod) (void * pos, void * q, void * s, void * ret);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Matrix4x4::TRS_Injected");
	icall(pos,q,s,ret);
}
bool UnityEngine_Matrix4x4_Inverse3DAffine_Injected(void * input, void * result)
{
	typedef bool (* ICallMethod) (void * input, void * result);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Matrix4x4::Inverse3DAffine_Injected");
	bool i2res = icall(input,result);
	return i2res;
}
void UnityEngine_Matrix4x4_Inverse_Injected(void * m, void * ret)
{
	typedef void (* ICallMethod) (void * m, void * ret);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Matrix4x4::Inverse_Injected");
	icall(m,ret);
}
void UnityEngine_Matrix4x4_Perspective_Injected(float fov, float aspect, float zNear, float zFar, void * ret)
{
	typedef void (* ICallMethod) (float fov, float aspect, float zNear, float zFar, void * ret);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Matrix4x4::Perspective_Injected");
	icall(fov,aspect,zNear,zFar,ret);
}
void UnityEngine_Vector3_Slerp_Injected(void * a, void * b, float t, void * ret)
{
	typedef void (* ICallMethod) (void * a, void * b, float t, void * ret);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Vector3::Slerp_Injected");
	icall(a,b,t,ret);
}
void UnityEngine_Quaternion_FromToRotation_Injected(void * fromDirection, void * toDirection, void * ret)
{
	typedef void (* ICallMethod) (void * fromDirection, void * toDirection, void * ret);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Quaternion::FromToRotation_Injected");
	icall(fromDirection,toDirection,ret);
}
void UnityEngine_Quaternion_Inverse_Injected_1(void * rotation, void * ret)
{
	typedef void (* ICallMethod) (void * rotation, void * ret);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Quaternion::Inverse_Injected");
	icall(rotation,ret);
}
void UnityEngine_Quaternion_Slerp_Injected_1(void * a, void * b, float t, void * ret)
{
	typedef void (* ICallMethod) (void * a, void * b, float t, void * ret);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Quaternion::Slerp_Injected");
	icall(a,b,t,ret);
}
void UnityEngine_Quaternion_Lerp_Injected(void * a, void * b, float t, void * ret)
{
	typedef void (* ICallMethod) (void * a, void * b, float t, void * ret);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Quaternion::Lerp_Injected");
	icall(a,b,t,ret);
}
void UnityEngine_Quaternion_Internal_FromEulerRad_Injected(void * euler, void * ret)
{
	typedef void (* ICallMethod) (void * euler, void * ret);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Quaternion::Internal_FromEulerRad_Injected");
	icall(euler,ret);
}
void UnityEngine_Quaternion_Internal_ToEulerRad_Injected(void * rotation, void * ret)
{
	typedef void (* ICallMethod) (void * rotation, void * ret);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Quaternion::Internal_ToEulerRad_Injected");
	icall(rotation,ret);
}
void UnityEngine_Quaternion_AngleAxis_Injected(float angle, void * axis, void * ret)
{
	typedef void (* ICallMethod) (float angle, void * axis, void * ret);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Quaternion::AngleAxis_Injected");
	icall(angle,axis,ret);
}
void UnityEngine_Quaternion_LookRotation_Injected(void * forward, void * upwards, void * ret)
{
	typedef void (* ICallMethod) (void * forward, void * upwards, void * ret);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Quaternion::LookRotation_Injected");
	icall(forward,upwards,ret);
}
int32_t UnityEngine_Object_get_hideFlags(MonoObject* thiz)
{
	typedef int32_t (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Object::get_hideFlags");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Object());
	int32_t i2res = icall(i2thiz);
	return i2res;
}
void UnityEngine_Object_set_hideFlags(MonoObject* thiz, int32_t value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, int32_t value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Object::set_hideFlags");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Object());
	icall(i2thiz,value);
}
MonoObject* UnityEngine_Object_Internal_CloneSingle(MonoObject* data)
{
	typedef Il2CppObject* (* ICallMethod) (Il2CppObject* data);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Object::Internal_CloneSingle");
	Il2CppObject* i2data = get_il2cpp_object(data,il2cpp_get_class_UnityEngine_Object());
	Il2CppObject* i2res = icall(i2data);
	MonoObject* monoi2res = get_mono_object(i2res,get_mono_class(il2cpp_object_get_class(i2res)));
	if(i2res != NULL && monoi2res == NULL)
	{
		platform_log("UnityEngine.Object::Internal_CloneSingle fail to convert il2cpp obj to mono");
	}
	return monoi2res;
}
MonoString* UnityEngine_Object_ToString(MonoObject* obj)
{
	typedef Il2CppString* (* ICallMethod) (Il2CppObject* obj);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Object::ToString");
	Il2CppObject* i2obj = get_il2cpp_object(obj,il2cpp_get_class_UnityEngine_Object());
	Il2CppString* i2res = icall(i2obj);
	MonoString* monoi2res = get_mono_string(i2res);
	if(i2res != NULL && monoi2res == NULL)
	{
		platform_log("UnityEngine.Object::ToString fail to convert il2cpp obj to mono");
	}
	return monoi2res;
}
MonoObject* UnityEngine_Object_FindObjectFromInstanceID(int32_t instanceID)
{
	typedef Il2CppObject* (* ICallMethod) (int32_t instanceID);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Object::FindObjectFromInstanceID");
	Il2CppObject* i2res = icall(instanceID);
	MonoObject* monoi2res = get_mono_object(i2res,get_mono_class(il2cpp_object_get_class(i2res)));
	if(i2res != NULL && monoi2res == NULL)
	{
		platform_log("UnityEngine.Object::FindObjectFromInstanceID fail to convert il2cpp obj to mono");
	}
	return monoi2res;
}
void UnityEngine_Object_Destroy(MonoObject* obj, float t)
{
	typedef void (* ICallMethod) (Il2CppObject* obj, float t);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Object::Destroy");
	Il2CppObject* i2obj = get_il2cpp_object(obj,il2cpp_get_class_UnityEngine_Object());
	icall(i2obj,t);
}
void UnityEngine_Object_DestroyImmediate(MonoObject* obj, bool allowDestroyingAssets)
{
	typedef void (* ICallMethod) (Il2CppObject* obj, bool allowDestroyingAssets);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Object::DestroyImmediate");
	Il2CppObject* i2obj = get_il2cpp_object(obj,il2cpp_get_class_UnityEngine_Object());
	icall(i2obj,allowDestroyingAssets);
}
MonoArray* UnityEngine_Object_FindObjectsOfType(MonoReflectionType* type, bool includeInactive)
{
	typedef Il2CppArray* (* ICallMethod) (Il2CppReflectionType* type, bool includeInactive);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Object::FindObjectsOfType");
	Il2CppReflectionType* i2type = get_il2cpp_reflection_type(type);
	Il2CppArray* i2res = icall(i2type,includeInactive);
	MonoArray* monoi2res = get_mono_array(i2res);
	if(i2res != NULL && monoi2res == NULL)
	{
		platform_log("UnityEngine.Object::FindObjectsOfType fail to convert il2cpp obj to mono");
	}
	return monoi2res;
}
void UnityEngine_Object_DontDestroyOnLoad(MonoObject* target)
{
	typedef void (* ICallMethod) (Il2CppObject* target);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Object::DontDestroyOnLoad");
	Il2CppObject* i2target = get_il2cpp_object(target,il2cpp_get_class_UnityEngine_Object());
	icall(i2target);
}
int32_t UnityEngine_Transform_get_childCount(MonoObject* thiz)
{
	typedef int32_t (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Transform::get_childCount");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Transform());
	int32_t i2res = icall(i2thiz);
	return i2res;
}
bool UnityEngine_Transform_get_hasChanged(MonoObject* thiz)
{
	typedef bool (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Transform::get_hasChanged");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Transform());
	bool i2res = icall(i2thiz);
	return i2res;
}
void UnityEngine_Transform_set_hasChanged(MonoObject* thiz, bool value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, bool value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Transform::set_hasChanged");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Transform());
	icall(i2thiz,value);
}
MonoObject* UnityEngine_Transform_GetParent(MonoObject* thiz)
{
	typedef Il2CppObject* (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Transform::GetParent");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Transform());
	Il2CppObject* i2res = icall(i2thiz);
	MonoObject* monoi2res = get_mono_object(i2res,mono_get_class_UnityEngine_Transform());
	if(i2res != NULL && monoi2res == NULL)
	{
		platform_log("UnityEngine.Transform::GetParent fail to convert il2cpp obj to mono");
	}
	return monoi2res;
}
void UnityEngine_Transform_SetParent(MonoObject* thiz, MonoObject* parent, bool worldPositionStays)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, Il2CppObject* parent, bool worldPositionStays);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Transform::SetParent");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Transform());
	Il2CppObject* i2parent = get_il2cpp_object(parent,il2cpp_get_class_UnityEngine_Transform());
	icall(i2thiz,i2parent,worldPositionStays);
}
MonoObject* UnityEngine_Transform_GetRoot(MonoObject* thiz)
{
	typedef Il2CppObject* (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Transform::GetRoot");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Transform());
	Il2CppObject* i2res = icall(i2thiz);
	MonoObject* monoi2res = get_mono_object(i2res,mono_get_class_UnityEngine_Transform());
	if(i2res != NULL && monoi2res == NULL)
	{
		platform_log("UnityEngine.Transform::GetRoot fail to convert il2cpp obj to mono");
	}
	return monoi2res;
}
void UnityEngine_Transform_SetAsFirstSibling(MonoObject* thiz)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Transform::SetAsFirstSibling");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Transform());
	icall(i2thiz);
}
MonoObject* UnityEngine_Transform_FindRelativeTransformWithPath(MonoObject* transform, MonoString* path, bool isActiveOnly)
{
	typedef Il2CppObject* (* ICallMethod) (Il2CppObject* transform, Il2CppString* path, bool isActiveOnly);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Transform::FindRelativeTransformWithPath");
	Il2CppObject* i2transform = get_il2cpp_object(transform,il2cpp_get_class_UnityEngine_Transform());
	Il2CppString* i2path = get_il2cpp_string(path);
	Il2CppObject* i2res = icall(i2transform,i2path,isActiveOnly);
	MonoObject* monoi2res = get_mono_object(i2res,mono_get_class_UnityEngine_Transform());
	if(i2res != NULL && monoi2res == NULL)
	{
		platform_log("UnityEngine.Transform::FindRelativeTransformWithPath fail to convert il2cpp obj to mono");
	}
	return monoi2res;
}
bool UnityEngine_Transform_IsChildOf(MonoObject* thiz, MonoObject* parent)
{
	typedef bool (* ICallMethod) (Il2CppObject* thiz, Il2CppObject* parent);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Transform::IsChildOf");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Transform());
	Il2CppObject* i2parent = get_il2cpp_object(parent,il2cpp_get_class_UnityEngine_Transform());
	bool i2res = icall(i2thiz,i2parent);
	return i2res;
}
MonoObject* UnityEngine_Transform_GetChild(MonoObject* thiz, int32_t index)
{
	typedef Il2CppObject* (* ICallMethod) (Il2CppObject* thiz, int32_t index);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Transform::GetChild");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Transform());
	Il2CppObject* i2res = icall(i2thiz,index);
	MonoObject* monoi2res = get_mono_object(i2res,mono_get_class_UnityEngine_Transform());
	if(i2res != NULL && monoi2res == NULL)
	{
		platform_log("UnityEngine.Transform::GetChild fail to convert il2cpp obj to mono");
	}
	return monoi2res;
}
void UnityEngine_Transform_get_position_Injected(MonoObject* thiz, void * ret)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, void * ret);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Transform::get_position_Injected");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Transform());
	icall(i2thiz,ret);
}
void UnityEngine_Transform_set_position_Injected(MonoObject* thiz, void * value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, void * value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Transform::set_position_Injected");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Transform());
	icall(i2thiz,value);
}
void UnityEngine_Transform_get_localPosition_Injected(MonoObject* thiz, void * ret)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, void * ret);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Transform::get_localPosition_Injected");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Transform());
	icall(i2thiz,ret);
}
void UnityEngine_Transform_set_localPosition_Injected(MonoObject* thiz, void * value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, void * value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Transform::set_localPosition_Injected");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Transform());
	icall(i2thiz,value);
}
void UnityEngine_Transform_get_rotation_Injected(MonoObject* thiz, void * ret)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, void * ret);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Transform::get_rotation_Injected");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Transform());
	icall(i2thiz,ret);
}
void UnityEngine_Transform_set_rotation_Injected(MonoObject* thiz, void * value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, void * value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Transform::set_rotation_Injected");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Transform());
	icall(i2thiz,value);
}
void UnityEngine_Transform_get_localRotation_Injected(MonoObject* thiz, void * ret)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, void * ret);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Transform::get_localRotation_Injected");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Transform());
	icall(i2thiz,ret);
}
void UnityEngine_Transform_set_localRotation_Injected(MonoObject* thiz, void * value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, void * value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Transform::set_localRotation_Injected");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Transform());
	icall(i2thiz,value);
}
void UnityEngine_Transform_get_localScale_Injected(MonoObject* thiz, void * ret)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, void * ret);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Transform::get_localScale_Injected");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Transform());
	icall(i2thiz,ret);
}
void UnityEngine_Transform_set_localScale_Injected(MonoObject* thiz, void * value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, void * value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Transform::set_localScale_Injected");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Transform());
	icall(i2thiz,value);
}
void UnityEngine_Transform_get_worldToLocalMatrix_Injected(MonoObject* thiz, void * ret)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, void * ret);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Transform::get_worldToLocalMatrix_Injected");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Transform());
	icall(i2thiz,ret);
}
void UnityEngine_Transform_get_localToWorldMatrix_Injected(MonoObject* thiz, void * ret)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, void * ret);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Transform::get_localToWorldMatrix_Injected");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Transform());
	icall(i2thiz,ret);
}
void UnityEngine_Transform_SetPositionAndRotation_Injected(MonoObject* thiz, void * position, void * rotation)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, void * position, void * rotation);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Transform::SetPositionAndRotation_Injected");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Transform());
	icall(i2thiz,position,rotation);
}
void UnityEngine_Transform_Internal_LookAt_Injected(MonoObject* thiz, void * worldPosition, void * worldUp)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, void * worldPosition, void * worldUp);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Transform::Internal_LookAt_Injected");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Transform());
	icall(i2thiz,worldPosition,worldUp);
}
void UnityEngine_Transform_TransformDirection_Injected(MonoObject* thiz, void * direction, void * ret)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, void * direction, void * ret);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Transform::TransformDirection_Injected");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Transform());
	icall(i2thiz,direction,ret);
}
void UnityEngine_Transform_InverseTransformDirection_Injected(MonoObject* thiz, void * direction, void * ret)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, void * direction, void * ret);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Transform::InverseTransformDirection_Injected");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Transform());
	icall(i2thiz,direction,ret);
}
void UnityEngine_Transform_TransformPoint_Injected(MonoObject* thiz, void * position, void * ret)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, void * position, void * ret);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Transform::TransformPoint_Injected");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Transform());
	icall(i2thiz,position,ret);
}
void UnityEngine_Transform_InverseTransformPoint_Injected(MonoObject* thiz, void * position, void * ret)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, void * position, void * ret);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Transform::InverseTransformPoint_Injected");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Transform());
	icall(i2thiz,position,ret);
}
void UnityEngine_Transform_get_lossyScale_Injected(MonoObject* thiz, void * ret)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, void * ret);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Transform::get_lossyScale_Injected");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Transform());
	icall(i2thiz,ret);
}
MonoObject* UnityEngine_Component_get_transform(MonoObject* thiz)
{
	typedef Il2CppObject* (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Component::get_transform");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Component());
	Il2CppObject* i2res = icall(i2thiz);
	MonoObject* monoi2res = get_mono_object(i2res,mono_get_class_UnityEngine_Transform());
	if(i2res != NULL && monoi2res == NULL)
	{
		platform_log("UnityEngine.Component::get_transform fail to convert il2cpp obj to mono");
	}
	return monoi2res;
}
MonoObject* UnityEngine_Component_get_gameObject(MonoObject* thiz)
{
	typedef Il2CppObject* (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Component::get_gameObject");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Component());
	Il2CppObject* i2res = icall(i2thiz);
	MonoObject* monoi2res = get_mono_object(i2res,mono_get_class_UnityEngine_GameObject());
	if(i2res != NULL && monoi2res == NULL)
	{
		platform_log("UnityEngine.Component::get_gameObject fail to convert il2cpp obj to mono");
	}
	return monoi2res;
}
void UnityEngine_Component_GetComponentsForListInternal(MonoObject* thiz, MonoReflectionType* searchType, MonoObject* resultList)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, Il2CppReflectionType* searchType, Il2CppObject* resultList);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Component::GetComponentsForListInternal");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Component());
	Il2CppReflectionType* i2searchType = get_il2cpp_reflection_type(searchType);
	Il2CppObject* i2resultList = get_il2cpp_object(resultList,NULL);
	icall(i2thiz,i2searchType,i2resultList);
}
void UnityEngine_Component_SendMessage(MonoObject* thiz, MonoString* methodName, MonoObject* value, int32_t options)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, Il2CppString* methodName, Il2CppObject* value, int32_t options);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Component::SendMessage");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Component());
	Il2CppString* i2methodName = get_il2cpp_string(methodName);
	Il2CppObject* i2value = get_il2cpp_object(value,NULL);
	icall(i2thiz,i2methodName,i2value,options);
}
void UnityEngine_Component_BroadcastMessage(MonoObject* thiz, MonoString* methodName, MonoObject* parameter, int32_t options)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, Il2CppString* methodName, Il2CppObject* parameter, int32_t options);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Component::BroadcastMessage");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Component());
	Il2CppString* i2methodName = get_il2cpp_string(methodName);
	Il2CppObject* i2parameter = get_il2cpp_object(parameter,NULL);
	icall(i2thiz,i2methodName,i2parameter,options);
}
MonoObject* UnityEngine_GameObject_get_transform_1(MonoObject* thiz)
{
	typedef Il2CppObject* (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.GameObject::get_transform");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_GameObject());
	Il2CppObject* i2res = icall(i2thiz);
	MonoObject* monoi2res = get_mono_object(i2res,mono_get_class_UnityEngine_Transform());
	if(i2res != NULL && monoi2res == NULL)
	{
		platform_log("UnityEngine.GameObject::get_transform fail to convert il2cpp obj to mono");
	}
	return monoi2res;
}
int32_t UnityEngine_GameObject_get_layer(MonoObject* thiz)
{
	typedef int32_t (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.GameObject::get_layer");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_GameObject());
	int32_t i2res = icall(i2thiz);
	return i2res;
}
void UnityEngine_GameObject_set_layer(MonoObject* thiz, int32_t value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, int32_t value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.GameObject::set_layer");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_GameObject());
	icall(i2thiz,value);
}
bool UnityEngine_GameObject_get_active(MonoObject* thiz)
{
	typedef bool (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.GameObject::get_active");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_GameObject());
	bool i2res = icall(i2thiz);
	return i2res;
}
bool UnityEngine_GameObject_get_activeSelf(MonoObject* thiz)
{
	typedef bool (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.GameObject::get_activeSelf");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_GameObject());
	bool i2res = icall(i2thiz);
	return i2res;
}
bool UnityEngine_GameObject_get_activeInHierarchy(MonoObject* thiz)
{
	typedef bool (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.GameObject::get_activeInHierarchy");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_GameObject());
	bool i2res = icall(i2thiz);
	return i2res;
}
MonoString* UnityEngine_GameObject_get_tag(MonoObject* thiz)
{
	typedef Il2CppString* (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.GameObject::get_tag");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_GameObject());
	Il2CppString* i2res = icall(i2thiz);
	MonoString* monoi2res = get_mono_string(i2res);
	if(i2res != NULL && monoi2res == NULL)
	{
		platform_log("UnityEngine.GameObject::get_tag fail to convert il2cpp obj to mono");
	}
	return monoi2res;
}
void UnityEngine_GameObject_set_tag(MonoObject* thiz, MonoString* value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, Il2CppString* value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.GameObject::set_tag");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_GameObject());
	Il2CppString* i2value = get_il2cpp_string(value);
	icall(i2thiz,i2value);
}
MonoObject* UnityEngine_GameObject_GetComponent(MonoObject* thiz, MonoReflectionType* type)
{
	typedef Il2CppObject* (* ICallMethod) (Il2CppObject* thiz, Il2CppReflectionType* type);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.GameObject::GetComponent");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_GameObject());
	Il2CppReflectionType* i2type = get_il2cpp_reflection_type(type);
	Il2CppObject* i2res = icall(i2thiz,i2type);
	MonoObject* monoi2res = get_mono_object(i2res,mono_get_class_UnityEngine_Component());
	if(i2res != NULL && monoi2res == NULL)
	{
		platform_log("UnityEngine.GameObject::GetComponent fail to convert il2cpp obj to mono");
	}
	return monoi2res;
}
MonoObject* UnityEngine_GameObject_GetComponentInChildren(MonoObject* thiz, MonoReflectionType* type, bool includeInactive)
{
	typedef Il2CppObject* (* ICallMethod) (Il2CppObject* thiz, Il2CppReflectionType* type, bool includeInactive);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.GameObject::GetComponentInChildren");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_GameObject());
	Il2CppReflectionType* i2type = get_il2cpp_reflection_type(type);
	Il2CppObject* i2res = icall(i2thiz,i2type,includeInactive);
	MonoObject* monoi2res = get_mono_object(i2res,mono_get_class_UnityEngine_Component());
	if(i2res != NULL && monoi2res == NULL)
	{
		platform_log("UnityEngine.GameObject::GetComponentInChildren fail to convert il2cpp obj to mono");
	}
	return monoi2res;
}
MonoObject* UnityEngine_GameObject_GetComponentInParent(MonoObject* thiz, MonoReflectionType* type, bool includeInactive)
{
	typedef Il2CppObject* (* ICallMethod) (Il2CppObject* thiz, Il2CppReflectionType* type, bool includeInactive);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.GameObject::GetComponentInParent");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_GameObject());
	Il2CppReflectionType* i2type = get_il2cpp_reflection_type(type);
	Il2CppObject* i2res = icall(i2thiz,i2type,includeInactive);
	MonoObject* monoi2res = get_mono_object(i2res,mono_get_class_UnityEngine_Component());
	if(i2res != NULL && monoi2res == NULL)
	{
		platform_log("UnityEngine.GameObject::GetComponentInParent fail to convert il2cpp obj to mono");
	}
	return monoi2res;
}
void UnityEngine_GameObject_TryGetComponentFastPath(MonoObject* thiz, MonoReflectionType* type, void * oneFurtherThanResultValue)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, Il2CppReflectionType* type, void * oneFurtherThanResultValue);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.GameObject::TryGetComponentFastPath");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_GameObject());
	Il2CppReflectionType* i2type = get_il2cpp_reflection_type(type);
	icall(i2thiz,i2type,oneFurtherThanResultValue);
}
void UnityEngine_GameObject_SetActive(MonoObject* thiz, bool value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, bool value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.GameObject::SetActive");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_GameObject());
	icall(i2thiz,value);
}
bool UnityEngine_GameObject_CompareTag(MonoObject* thiz, MonoString* tag)
{
	typedef bool (* ICallMethod) (Il2CppObject* thiz, Il2CppString* tag);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.GameObject::CompareTag");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_GameObject());
	Il2CppString* i2tag = get_il2cpp_string(tag);
	bool i2res = icall(i2thiz,i2tag);
	return i2res;
}
void UnityEngine_GameObject_SendMessage_1(MonoObject* thiz, MonoString* methodName, MonoObject* value, int32_t options)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, Il2CppString* methodName, Il2CppObject* value, int32_t options);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.GameObject::SendMessage");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_GameObject());
	Il2CppString* i2methodName = get_il2cpp_string(methodName);
	Il2CppObject* i2value = get_il2cpp_object(value,NULL);
	icall(i2thiz,i2methodName,i2value,options);
}
void UnityEngine_GameObject_BroadcastMessage_1(MonoObject* thiz, MonoString* methodName, MonoObject* parameter, int32_t options)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, Il2CppString* methodName, Il2CppObject* parameter, int32_t options);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.GameObject::BroadcastMessage");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_GameObject());
	Il2CppString* i2methodName = get_il2cpp_string(methodName);
	Il2CppObject* i2parameter = get_il2cpp_object(parameter,NULL);
	icall(i2thiz,i2methodName,i2parameter,options);
}
void UnityEngine_GameObject_Internal_CreateGameObject(MonoObject* self, MonoString* name)
{
	typedef void (* ICallMethod) (Il2CppObject* self, Il2CppString* name);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.GameObject::Internal_CreateGameObject");
	Il2CppObject* i2self = get_il2cpp_object(self,il2cpp_get_class_UnityEngine_GameObject());
	Il2CppString* i2name = get_il2cpp_string(name);
	icall(i2self,i2name);
}
MonoObject* UnityEngine_GameObject_Find(MonoString* name)
{
	typedef Il2CppObject* (* ICallMethod) (Il2CppString* name);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.GameObject::Find");
	Il2CppString* i2name = get_il2cpp_string(name);
	Il2CppObject* i2res = icall(i2name);
	MonoObject* monoi2res = get_mono_object(i2res,mono_get_class_UnityEngine_GameObject());
	if(i2res != NULL && monoi2res == NULL)
	{
		platform_log("UnityEngine.GameObject::Find fail to convert il2cpp obj to mono");
	}
	return monoi2res;
}
bool UnityEngine_Behaviour_get_enabled(MonoObject* thiz)
{
	typedef bool (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Behaviour::get_enabled");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Behaviour());
	bool i2res = icall(i2thiz);
	return i2res;
}
void UnityEngine_Behaviour_set_enabled(MonoObject* thiz, bool value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, bool value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Behaviour::set_enabled");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Behaviour());
	icall(i2thiz,value);
}
bool UnityEngine_Behaviour_get_isActiveAndEnabled(MonoObject* thiz)
{
	typedef bool (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Behaviour::get_isActiveAndEnabled");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Behaviour());
	bool i2res = icall(i2thiz);
	return i2res;
}
void UnityEngine_DebugLogHandler_Internal_Log(int32_t level, int32_t options, MonoString* msg, MonoObject* obj)
{
	typedef void (* ICallMethod) (int32_t level, int32_t options, Il2CppString* msg, Il2CppObject* obj);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.DebugLogHandler::Internal_Log");
	Il2CppString* i2msg = get_il2cpp_string(msg);
	Il2CppObject* i2obj = get_il2cpp_object(obj,il2cpp_get_class_UnityEngine_Object());
	icall(level,options,i2msg,i2obj);
}
void UnityEngine_DebugLogHandler_Internal_LogException(MonoObject* ex, MonoObject* obj)
{
	typedef void (* ICallMethod) (Il2CppObject* ex, Il2CppObject* obj);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.DebugLogHandler::Internal_LogException");
	Il2CppObject* i2ex = get_il2cpp_object(ex,NULL);
	Il2CppObject* i2obj = get_il2cpp_object(obj,il2cpp_get_class_UnityEngine_Object());
	icall(i2ex,i2obj);
}
bool UnityEngine_Debug_get_isDebugBuild()
{
	typedef bool (* ICallMethod) ();
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Debug::get_isDebugBuild");
	bool i2res = icall();
	return i2res;
}
int32_t UnityEngine_Debug_ExtractStackTraceNoAlloc(void * buffer, int32_t bufferMax, MonoString* projectFolder)
{
	typedef int32_t (* ICallMethod) (void * buffer, int32_t bufferMax, Il2CppString* projectFolder);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Debug::ExtractStackTraceNoAlloc");
	Il2CppString* i2projectFolder = get_il2cpp_string(projectFolder);
	int32_t i2res = icall(buffer,bufferMax,i2projectFolder);
	return i2res;
}
void UnityEngine_Debug_DrawLine_Injected(void * start, void * end, void * color, float duration, bool depthTest)
{
	typedef void (* ICallMethod) (void * start, void * end, void * color, float duration, bool depthTest);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Debug::DrawLine_Injected");
	icall(start,end,color,duration,depthTest);
}
int32_t UnityEngine_RectOffset_get_left(MonoObject* thiz)
{
	typedef int32_t (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.RectOffset::get_left");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_RectOffset());
	int32_t i2res = icall(i2thiz);
	return i2res;
}
int32_t UnityEngine_RectOffset_get_right(MonoObject* thiz)
{
	typedef int32_t (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.RectOffset::get_right");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_RectOffset());
	int32_t i2res = icall(i2thiz);
	return i2res;
}
int32_t UnityEngine_RectOffset_get_top(MonoObject* thiz)
{
	typedef int32_t (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.RectOffset::get_top");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_RectOffset());
	int32_t i2res = icall(i2thiz);
	return i2res;
}
int32_t UnityEngine_RectOffset_get_bottom(MonoObject* thiz)
{
	typedef int32_t (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.RectOffset::get_bottom");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_RectOffset());
	int32_t i2res = icall(i2thiz);
	return i2res;
}
int32_t UnityEngine_RectOffset_get_horizontal(MonoObject* thiz)
{
	typedef int32_t (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.RectOffset::get_horizontal");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_RectOffset());
	int32_t i2res = icall(i2thiz);
	return i2res;
}
int32_t UnityEngine_RectOffset_get_vertical(MonoObject* thiz)
{
	typedef int32_t (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.RectOffset::get_vertical");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_RectOffset());
	int32_t i2res = icall(i2thiz);
	return i2res;
}
void UnityEngine_Gizmos_DrawLine_Injected_1(void * from, void * to)
{
	typedef void (* ICallMethod) (void * from, void * to);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Gizmos::DrawLine_Injected");
	icall(from,to);
}
void UnityEngine_Gizmos_DrawWireSphere_Injected(void * center, float radius)
{
	typedef void (* ICallMethod) (void * center, float radius);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Gizmos::DrawWireSphere_Injected");
	icall(center,radius);
}
void UnityEngine_Gizmos_DrawWireCube_Injected(void * center, void * size)
{
	typedef void (* ICallMethod) (void * center, void * size);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Gizmos::DrawWireCube_Injected");
	icall(center,size);
}
int32_t UnityEngine_Screen_get_width_1()
{
	typedef int32_t (* ICallMethod) ();
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Screen::get_width");
	int32_t i2res = icall();
	return i2res;
}
int32_t UnityEngine_Screen_get_height_1()
{
	typedef int32_t (* ICallMethod) ();
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Screen::get_height");
	int32_t i2res = icall();
	return i2res;
}
float UnityEngine_Screen_get_dpi()
{
	typedef float (* ICallMethod) ();
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Screen::get_dpi");
	float i2res = icall();
	return i2res;
}
int32_t UnityEngine_Screen_get_sleepTimeout()
{
	typedef int32_t (* ICallMethod) ();
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Screen::get_sleepTimeout");
	int32_t i2res = icall();
	return i2res;
}
void UnityEngine_Screen_set_sleepTimeout(int32_t value)
{
	typedef void (* ICallMethod) (int32_t value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Screen::set_sleepTimeout");
	icall(value);
}
bool UnityEngine_Screen_get_fullScreen()
{
	typedef bool (* ICallMethod) ();
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Screen::get_fullScreen");
	bool i2res = icall();
	return i2res;
}
void UnityEngine_Screen_set_fullScreen(bool value)
{
	typedef void (* ICallMethod) (bool value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Screen::set_fullScreen");
	icall(value);
}
int32_t UnityEngine_Screen_get_fullScreenMode()
{
	typedef int32_t (* ICallMethod) ();
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Screen::get_fullScreenMode");
	int32_t i2res = icall();
	return i2res;
}
void UnityEngine_Screen_set_fullScreenMode(int32_t value)
{
	typedef void (* ICallMethod) (int32_t value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Screen::set_fullScreenMode");
	icall(value);
}
void* UnityEngine_Screen_get_cutouts()
{
	typedef void* (* ICallMethod) ();
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Screen::get_cutouts");
	void* i2res = icall();
	if(i2res != NULL && i2res == NULL)
	{
		platform_log("UnityEngine.Screen::get_cutouts fail to convert il2cpp obj to mono");
	}
	return i2res;
}
void* UnityEngine_Screen_get_resolutions()
{
	typedef void* (* ICallMethod) ();
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Screen::get_resolutions");
	void* i2res = icall();
	if(i2res != NULL && i2res == NULL)
	{
		platform_log("UnityEngine.Screen::get_resolutions fail to convert il2cpp obj to mono");
	}
	return i2res;
}
float UnityEngine_Screen_get_brightness()
{
	typedef float (* ICallMethod) ();
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Screen::get_brightness");
	float i2res = icall();
	return i2res;
}
void UnityEngine_Screen_set_brightness(float value)
{
	typedef void (* ICallMethod) (float value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Screen::set_brightness");
	icall(value);
}
void UnityEngine_Screen_SetResolution(int32_t width, int32_t height, int32_t fullscreenMode, int32_t preferredRefreshRate)
{
	typedef void (* ICallMethod) (int32_t width, int32_t height, int32_t fullscreenMode, int32_t preferredRefreshRate);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Screen::SetResolution");
	icall(width,height,fullscreenMode,preferredRefreshRate);
}
void UnityEngine_Graphics_Blit2(MonoObject* source, MonoObject* dest)
{
	typedef void (* ICallMethod) (Il2CppObject* source, Il2CppObject* dest);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Graphics::Blit2");
	Il2CppObject* i2source = get_il2cpp_object(source,il2cpp_get_class_UnityEngine_Texture());
	Il2CppObject* i2dest = get_il2cpp_object(dest,il2cpp_get_class_UnityEngine_RenderTexture());
	icall(i2source,i2dest);
}
void UnityEngine_Graphics_Internal_BlitMaterial5(MonoObject* source, MonoObject* dest, MonoObject* mat, int32_t pass, bool setRT)
{
	typedef void (* ICallMethod) (Il2CppObject* source, Il2CppObject* dest, Il2CppObject* mat, int32_t pass, bool setRT);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Graphics::Internal_BlitMaterial5");
	Il2CppObject* i2source = get_il2cpp_object(source,il2cpp_get_class_UnityEngine_Texture());
	Il2CppObject* i2dest = get_il2cpp_object(dest,il2cpp_get_class_UnityEngine_RenderTexture());
	Il2CppObject* i2mat = get_il2cpp_object(mat,il2cpp_get_class_UnityEngine_Material());
	icall(i2source,i2dest,i2mat,pass,setRT);
}
int32_t UnityEngine_Mesh_get_vertexCount(MonoObject* thiz)
{
	typedef int32_t (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Mesh::get_vertexCount");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Mesh());
	int32_t i2res = icall(i2thiz);
	return i2res;
}
int32_t UnityEngine_Mesh_get_subMeshCount(MonoObject* thiz)
{
	typedef int32_t (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Mesh::get_subMeshCount");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Mesh());
	int32_t i2res = icall(i2thiz);
	return i2res;
}
void UnityEngine_Mesh_set_subMeshCount(MonoObject* thiz, int32_t value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, int32_t value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Mesh::set_subMeshCount");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Mesh());
	icall(i2thiz,value);
}
bool UnityEngine_Mesh_get_canAccess(MonoObject* thiz)
{
	typedef bool (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Mesh::get_canAccess");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Mesh());
	bool i2res = icall(i2thiz);
	return i2res;
}
void UnityEngine_Mesh_Internal_Create(MonoObject* mono)
{
	typedef void (* ICallMethod) (Il2CppObject* mono);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Mesh::Internal_Create");
	Il2CppObject* i2mono = get_il2cpp_object(mono,il2cpp_get_class_UnityEngine_Mesh());
	icall(i2mono);
}
void UnityEngine_Mesh_ClearImpl(MonoObject* thiz, bool keepVertexLayout)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, bool keepVertexLayout);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Mesh::ClearImpl");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Mesh());
	icall(i2thiz,keepVertexLayout);
}
void UnityEngine_Mesh_MarkDynamicImpl(MonoObject* thiz)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Mesh::MarkDynamicImpl");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Mesh());
	icall(i2thiz);
}
bool UnityEngine_Mesh_HasVertexAttribute(MonoObject* thiz, int32_t attr)
{
	typedef bool (* ICallMethod) (Il2CppObject* thiz, int32_t attr);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Mesh::HasVertexAttribute");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Mesh());
	bool i2res = icall(i2thiz,attr);
	return i2res;
}
MonoObject* UnityEngine_Material_get_shader(MonoObject* thiz)
{
	typedef Il2CppObject* (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Material::get_shader");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Material());
	Il2CppObject* i2res = icall(i2thiz);
	MonoObject* monoi2res = get_mono_object(i2res,mono_get_class_UnityEngine_Shader());
	if(i2res != NULL && monoi2res == NULL)
	{
		platform_log("UnityEngine.Material::get_shader fail to convert il2cpp obj to mono");
	}
	return monoi2res;
}
void UnityEngine_Material_set_shader(MonoObject* thiz, MonoObject* value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, Il2CppObject* value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Material::set_shader");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Material());
	Il2CppObject* i2value = get_il2cpp_object(value,il2cpp_get_class_UnityEngine_Shader());
	icall(i2thiz,i2value);
}
int32_t UnityEngine_Material_get_renderQueue(MonoObject* thiz)
{
	typedef int32_t (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Material::get_renderQueue");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Material());
	int32_t i2res = icall(i2thiz);
	return i2res;
}
void UnityEngine_Material_set_renderQueue(MonoObject* thiz, int32_t value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, int32_t value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Material::set_renderQueue");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Material());
	icall(i2thiz,value);
}
void UnityEngine_Material_CreateWithShader(MonoObject* self, MonoObject* shader)
{
	typedef void (* ICallMethod) (Il2CppObject* self, Il2CppObject* shader);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Material::CreateWithShader");
	Il2CppObject* i2self = get_il2cpp_object(self,il2cpp_get_class_UnityEngine_Material());
	Il2CppObject* i2shader = get_il2cpp_object(shader,il2cpp_get_class_UnityEngine_Shader());
	icall(i2self,i2shader);
}
void UnityEngine_Material_CreateWithMaterial(MonoObject* self, MonoObject* source)
{
	typedef void (* ICallMethod) (Il2CppObject* self, Il2CppObject* source);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Material::CreateWithMaterial");
	Il2CppObject* i2self = get_il2cpp_object(self,il2cpp_get_class_UnityEngine_Material());
	Il2CppObject* i2source = get_il2cpp_object(source,il2cpp_get_class_UnityEngine_Material());
	icall(i2self,i2source);
}
void UnityEngine_Material_CreateWithString(MonoObject* self)
{
	typedef void (* ICallMethod) (Il2CppObject* self);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Material::CreateWithString");
	Il2CppObject* i2self = get_il2cpp_object(self,il2cpp_get_class_UnityEngine_Material());
	icall(i2self);
}
MonoString* UnityEngine_Material_GetTagImpl(MonoObject* thiz, MonoString* tag, bool currentSubShaderOnly, MonoString* defaultValue)
{
	typedef Il2CppString* (* ICallMethod) (Il2CppObject* thiz, Il2CppString* tag, bool currentSubShaderOnly, Il2CppString* defaultValue);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Material::GetTagImpl");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Material());
	Il2CppString* i2tag = get_il2cpp_string(tag);
	Il2CppString* i2defaultValue = get_il2cpp_string(defaultValue);
	Il2CppString* i2res = icall(i2thiz,i2tag,currentSubShaderOnly,i2defaultValue);
	MonoString* monoi2res = get_mono_string(i2res);
	if(i2res != NULL && monoi2res == NULL)
	{
		platform_log("UnityEngine.Material::GetTagImpl fail to convert il2cpp obj to mono");
	}
	return monoi2res;
}
void UnityEngine_Material_SetFloatImpl(MonoObject* thiz, int32_t name, float value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, int32_t name, float value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Material::SetFloatImpl");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Material());
	icall(i2thiz,name,value);
}
void UnityEngine_Material_SetColorImpl_Injected(MonoObject* thiz, int32_t name, void * value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, int32_t name, void * value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Material::SetColorImpl_Injected");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Material());
	icall(i2thiz,name,value);
}
void UnityEngine_Material_SetMatrixImpl_Injected(MonoObject* thiz, int32_t name, void * value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, int32_t name, void * value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Material::SetMatrixImpl_Injected");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Material());
	icall(i2thiz,name,value);
}
void UnityEngine_Material_SetTextureImpl(MonoObject* thiz, int32_t name, MonoObject* value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, int32_t name, Il2CppObject* value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Material::SetTextureImpl");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Material());
	Il2CppObject* i2value = get_il2cpp_object(value,il2cpp_get_class_UnityEngine_Texture());
	icall(i2thiz,name,i2value);
}
float UnityEngine_Material_GetFloatImpl(MonoObject* thiz, int32_t name)
{
	typedef float (* ICallMethod) (Il2CppObject* thiz, int32_t name);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Material::GetFloatImpl");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Material());
	float i2res = icall(i2thiz,name);
	return i2res;
}
void UnityEngine_Material_GetColorImpl_Injected(MonoObject* thiz, int32_t name, void * ret)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, int32_t name, void * ret);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Material::GetColorImpl_Injected");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Material());
	icall(i2thiz,name,ret);
}
MonoObject* UnityEngine_Material_GetTextureImpl(MonoObject* thiz, int32_t name)
{
	typedef Il2CppObject* (* ICallMethod) (Il2CppObject* thiz, int32_t name);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Material::GetTextureImpl");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Material());
	Il2CppObject* i2res = icall(i2thiz,name);
	MonoObject* monoi2res = get_mono_object(i2res,mono_get_class_UnityEngine_Texture());
	if(i2res != NULL && monoi2res == NULL)
	{
		platform_log("UnityEngine.Material::GetTextureImpl fail to convert il2cpp obj to mono");
	}
	return monoi2res;
}
void UnityEngine_Material_SetTextureOffsetImpl_Injected(MonoObject* thiz, int32_t name, void * offset)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, int32_t name, void * offset);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Material::SetTextureOffsetImpl_Injected");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Material());
	icall(i2thiz,name,offset);
}
void UnityEngine_Material_SetTextureScaleImpl_Injected(MonoObject* thiz, int32_t name, void * scale)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, int32_t name, void * scale);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Material::SetTextureScaleImpl_Injected");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Material());
	icall(i2thiz,name,scale);
}
bool UnityEngine_Material_HasProperty(MonoObject* thiz, int32_t nameID)
{
	typedef bool (* ICallMethod) (Il2CppObject* thiz, int32_t nameID);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Material::HasProperty");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Material());
	bool i2res = icall(i2thiz,nameID);
	return i2res;
}
void UnityEngine_Material_EnableKeyword(MonoObject* thiz, MonoString* keyword)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, Il2CppString* keyword);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Material::EnableKeyword");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Material());
	Il2CppString* i2keyword = get_il2cpp_string(keyword);
	icall(i2thiz,i2keyword);
}
void UnityEngine_Material_DisableKeyword(MonoObject* thiz, MonoString* keyword)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, Il2CppString* keyword);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Material::DisableKeyword");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Material());
	Il2CppString* i2keyword = get_il2cpp_string(keyword);
	icall(i2thiz,i2keyword);
}
bool UnityEngine_Material_SetPass(MonoObject* thiz, int32_t pass)
{
	typedef bool (* ICallMethod) (Il2CppObject* thiz, int32_t pass);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Material::SetPass");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Material());
	bool i2res = icall(i2thiz,pass);
	return i2res;
}
void UnityEngine_Material_CopyPropertiesFromMaterial(MonoObject* thiz, MonoObject* mat)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, Il2CppObject* mat);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Material::CopyPropertiesFromMaterial");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Material());
	Il2CppObject* i2mat = get_il2cpp_object(mat,il2cpp_get_class_UnityEngine_Material());
	icall(i2thiz,i2mat);
}
bool UnityEngine_Shader_get_isSupported(MonoObject* thiz)
{
	typedef bool (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Shader::get_isSupported");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Shader());
	bool i2res = icall(i2thiz);
	return i2res;
}
void UnityEngine_Shader_SetGlobalFloatImpl(int32_t name, float value)
{
	typedef void (* ICallMethod) (int32_t name, float value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Shader::SetGlobalFloatImpl");
	icall(name,value);
}
void UnityEngine_Shader_SetGlobalMatrixImpl_Injected(int32_t name, void * value)
{
	typedef void (* ICallMethod) (int32_t name, void * value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Shader::SetGlobalMatrixImpl_Injected");
	icall(name,value);
}
int32_t UnityEngine_Shader_TagToID(MonoString* name)
{
	typedef int32_t (* ICallMethod) (Il2CppString* name);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Shader::TagToID");
	Il2CppString* i2name = get_il2cpp_string(name);
	int32_t i2res = icall(i2name);
	return i2res;
}
void UnityEngine_Shader_EnableKeyword_1(MonoString* keyword)
{
	typedef void (* ICallMethod) (Il2CppString* keyword);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Shader::EnableKeyword");
	Il2CppString* i2keyword = get_il2cpp_string(keyword);
	icall(i2keyword);
}
void UnityEngine_Shader_DisableKeyword_1(MonoString* keyword)
{
	typedef void (* ICallMethod) (Il2CppString* keyword);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Shader::DisableKeyword");
	Il2CppString* i2keyword = get_il2cpp_string(keyword);
	icall(i2keyword);
}
void UnityEngine_Shader_WarmupAllShaders()
{
	typedef void (* ICallMethod) ();
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Shader::WarmupAllShaders");
	icall();
}
int32_t UnityEngine_Shader_PropertyToID(MonoString* name)
{
	typedef int32_t (* ICallMethod) (Il2CppString* name);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Shader::PropertyToID");
	Il2CppString* i2name = get_il2cpp_string(name);
	int32_t i2res = icall(i2name);
	return i2res;
}
int32_t UnityEngine_Shader_GetPropertyCount(MonoObject* thiz)
{
	typedef int32_t (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Shader::GetPropertyCount");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Shader());
	int32_t i2res = icall(i2thiz);
	return i2res;
}
bool UnityEngine_Texture_get_isReadable(MonoObject* thiz)
{
	typedef bool (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Texture::get_isReadable");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Texture());
	bool i2res = icall(i2thiz);
	return i2res;
}
int32_t UnityEngine_Texture_get_wrapMode(MonoObject* thiz)
{
	typedef int32_t (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Texture::get_wrapMode");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Texture());
	int32_t i2res = icall(i2thiz);
	return i2res;
}
void UnityEngine_Texture_set_wrapMode_2(MonoObject* thiz, int32_t value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, int32_t value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Texture::set_wrapMode");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Texture());
	icall(i2thiz,value);
}
void UnityEngine_Texture_set_filterMode(MonoObject* thiz, int32_t value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, int32_t value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Texture::set_filterMode");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Texture());
	icall(i2thiz,value);
}
int32_t UnityEngine_Texture_get_anisoLevel(MonoObject* thiz)
{
	typedef int32_t (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Texture::get_anisoLevel");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Texture());
	int32_t i2res = icall(i2thiz);
	return i2res;
}
void UnityEngine_Texture_set_anisoLevel(MonoObject* thiz, int32_t value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, int32_t value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Texture::set_anisoLevel");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Texture());
	icall(i2thiz,value);
}
void UnityEngine_Texture_set_mipMapBias(MonoObject* thiz, float value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, float value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Texture::set_mipMapBias");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Texture());
	icall(i2thiz,value);
}
int32_t UnityEngine_Texture_GetDataWidth(MonoObject* thiz)
{
	typedef int32_t (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Texture::GetDataWidth");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Texture());
	int32_t i2res = icall(i2thiz);
	return i2res;
}
int32_t UnityEngine_Texture_GetDataHeight(MonoObject* thiz)
{
	typedef int32_t (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Texture::GetDataHeight");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Texture());
	int32_t i2res = icall(i2thiz);
	return i2res;
}
void UnityEngine_MaterialPropertyBlock_SetFloatImpl_1(MonoObject* thiz, int32_t name, float value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, int32_t name, float value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.MaterialPropertyBlock::SetFloatImpl");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_MaterialPropertyBlock());
	icall(i2thiz,name,value);
}
void UnityEngine_GL_Vertex3(float x, float y, float z)
{
	typedef void (* ICallMethod) (float x, float y, float z);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.GL::Vertex3");
	icall(x,y,z);
}
void UnityEngine_GL_MultiTexCoord3(int32_t unit, float x, float y, float z)
{
	typedef void (* ICallMethod) (int32_t unit, float x, float y, float z);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.GL::MultiTexCoord3");
	icall(unit,x,y,z);
}
void UnityEngine_GL_PushMatrix()
{
	typedef void (* ICallMethod) ();
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.GL::PushMatrix");
	icall();
}
void UnityEngine_GL_PopMatrix()
{
	typedef void (* ICallMethod) ();
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.GL::PopMatrix");
	icall();
}
void UnityEngine_GL_LoadOrtho()
{
	typedef void (* ICallMethod) ();
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.GL::LoadOrtho");
	icall();
}
void UnityEngine_GL_Begin(int32_t mode)
{
	typedef void (* ICallMethod) (int32_t mode);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.GL::Begin");
	icall(mode);
}
void UnityEngine_GL_End()
{
	typedef void (* ICallMethod) ();
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.GL::End");
	icall();
}
float UnityEngine_TrailRenderer_get_time_1(MonoObject* thiz)
{
	typedef float (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.TrailRenderer::get_time");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_TrailRenderer());
	float i2res = icall(i2thiz);
	return i2res;
}
void UnityEngine_TrailRenderer_set_time_1(MonoObject* thiz, float value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, float value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.TrailRenderer::set_time");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_TrailRenderer());
	icall(i2thiz,value);
}
void UnityEngine_LineRenderer_set_widthMultiplier(MonoObject* thiz, float value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, float value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.LineRenderer::set_widthMultiplier");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_LineRenderer());
	icall(i2thiz,value);
}
void UnityEngine_LineRenderer_set_positionCount(MonoObject* thiz, int32_t value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, int32_t value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.LineRenderer::set_positionCount");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_LineRenderer());
	icall(i2thiz,value);
}
void UnityEngine_LineRenderer_SetPosition_Injected(MonoObject* thiz, int32_t index, void * position)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, int32_t index, void * position);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.LineRenderer::SetPosition_Injected");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_LineRenderer());
	icall(i2thiz,index,position);
}
bool UnityEngine_Renderer_get_enabled_1(MonoObject* thiz)
{
	typedef bool (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Renderer::get_enabled");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Renderer());
	bool i2res = icall(i2thiz);
	return i2res;
}
void UnityEngine_Renderer_set_enabled_1(MonoObject* thiz, bool value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, bool value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Renderer::set_enabled");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Renderer());
	icall(i2thiz,value);
}
int32_t UnityEngine_Renderer_get_shadowCastingMode(MonoObject* thiz)
{
	typedef int32_t (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Renderer::get_shadowCastingMode");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Renderer());
	int32_t i2res = icall(i2thiz);
	return i2res;
}
void UnityEngine_Renderer_set_shadowCastingMode(MonoObject* thiz, int32_t value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, int32_t value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Renderer::set_shadowCastingMode");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Renderer());
	icall(i2thiz,value);
}
bool UnityEngine_Renderer_get_receiveShadows(MonoObject* thiz)
{
	typedef bool (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Renderer::get_receiveShadows");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Renderer());
	bool i2res = icall(i2thiz);
	return i2res;
}
void UnityEngine_Renderer_set_receiveShadows(MonoObject* thiz, bool value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, bool value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Renderer::set_receiveShadows");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Renderer());
	icall(i2thiz,value);
}
int32_t UnityEngine_Renderer_get_motionVectorGenerationMode(MonoObject* thiz)
{
	typedef int32_t (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Renderer::get_motionVectorGenerationMode");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Renderer());
	int32_t i2res = icall(i2thiz);
	return i2res;
}
void UnityEngine_Renderer_set_motionVectorGenerationMode(MonoObject* thiz, int32_t value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, int32_t value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Renderer::set_motionVectorGenerationMode");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Renderer());
	icall(i2thiz,value);
}
int32_t UnityEngine_Renderer_get_lightProbeUsage(MonoObject* thiz)
{
	typedef int32_t (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Renderer::get_lightProbeUsage");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Renderer());
	int32_t i2res = icall(i2thiz);
	return i2res;
}
void UnityEngine_Renderer_set_lightProbeUsage(MonoObject* thiz, int32_t value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, int32_t value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Renderer::set_lightProbeUsage");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Renderer());
	icall(i2thiz,value);
}
int32_t UnityEngine_Renderer_get_reflectionProbeUsage(MonoObject* thiz)
{
	typedef int32_t (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Renderer::get_reflectionProbeUsage");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Renderer());
	int32_t i2res = icall(i2thiz);
	return i2res;
}
void UnityEngine_Renderer_set_reflectionProbeUsage(MonoObject* thiz, int32_t value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, int32_t value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Renderer::set_reflectionProbeUsage");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Renderer());
	icall(i2thiz,value);
}
int32_t UnityEngine_Renderer_get_sortingLayerID(MonoObject* thiz)
{
	typedef int32_t (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Renderer::get_sortingLayerID");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Renderer());
	int32_t i2res = icall(i2thiz);
	return i2res;
}
void UnityEngine_Renderer_set_sortingLayerID(MonoObject* thiz, int32_t value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, int32_t value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Renderer::set_sortingLayerID");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Renderer());
	icall(i2thiz,value);
}
int32_t UnityEngine_Renderer_get_sortingOrder(MonoObject* thiz)
{
	typedef int32_t (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Renderer::get_sortingOrder");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Renderer());
	int32_t i2res = icall(i2thiz);
	return i2res;
}
void UnityEngine_Renderer_set_sortingOrder(MonoObject* thiz, int32_t value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, int32_t value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Renderer::set_sortingOrder");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Renderer());
	icall(i2thiz,value);
}
MonoObject* UnityEngine_Renderer_get_probeAnchor(MonoObject* thiz)
{
	typedef Il2CppObject* (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Renderer::get_probeAnchor");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Renderer());
	Il2CppObject* i2res = icall(i2thiz);
	MonoObject* monoi2res = get_mono_object(i2res,mono_get_class_UnityEngine_Transform());
	if(i2res != NULL && monoi2res == NULL)
	{
		platform_log("UnityEngine.Renderer::get_probeAnchor fail to convert il2cpp obj to mono");
	}
	return monoi2res;
}
void UnityEngine_Renderer_set_probeAnchor(MonoObject* thiz, MonoObject* value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, Il2CppObject* value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Renderer::set_probeAnchor");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Renderer());
	Il2CppObject* i2value = get_il2cpp_object(value,il2cpp_get_class_UnityEngine_Transform());
	icall(i2thiz,i2value);
}
void UnityEngine_Renderer_Internal_SetPropertyBlock(MonoObject* thiz, MonoObject* properties)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, Il2CppObject* properties);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Renderer::Internal_SetPropertyBlock");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Renderer());
	Il2CppObject* i2properties = get_il2cpp_object(properties,il2cpp_get_class_UnityEngine_MaterialPropertyBlock());
	icall(i2thiz,i2properties);
}
void UnityEngine_Renderer_Internal_GetPropertyBlock(MonoObject* thiz, MonoObject* dest)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, Il2CppObject* dest);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Renderer::Internal_GetPropertyBlock");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Renderer());
	Il2CppObject* i2dest = get_il2cpp_object(dest,il2cpp_get_class_UnityEngine_MaterialPropertyBlock());
	icall(i2thiz,i2dest);
}
void UnityEngine_Projector_set_orthographic_1(MonoObject* thiz, bool value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, bool value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Projector::set_orthographic");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Projector());
	icall(i2thiz,value);
}
void UnityEngine_Projector_set_orthographicSize_1(MonoObject* thiz, float value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, float value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Projector::set_orthographicSize");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Projector());
	icall(i2thiz,value);
}
void UnityEngine_Projector_set_ignoreLayers(MonoObject* thiz, int32_t value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, int32_t value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Projector::set_ignoreLayers");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Projector());
	icall(i2thiz,value);
}
MonoObject* UnityEngine_Projector_get_material(MonoObject* thiz)
{
	typedef Il2CppObject* (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Projector::get_material");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Projector());
	Il2CppObject* i2res = icall(i2thiz);
	MonoObject* monoi2res = get_mono_object(i2res,mono_get_class_UnityEngine_Material());
	if(i2res != NULL && monoi2res == NULL)
	{
		platform_log("UnityEngine.Projector::get_material fail to convert il2cpp obj to mono");
	}
	return monoi2res;
}
void UnityEngine_Projector_set_material(MonoObject* thiz, MonoObject* value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, Il2CppObject* value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Projector::set_material");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Projector());
	Il2CppObject* i2value = get_il2cpp_object(value,il2cpp_get_class_UnityEngine_Material());
	icall(i2thiz,i2value);
}
int32_t UnityEngine_Light_get_type(MonoObject* thiz)
{
	typedef int32_t (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Light::get_type");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Light());
	int32_t i2res = icall(i2thiz);
	return i2res;
}
float UnityEngine_Light_get_spotAngle(MonoObject* thiz)
{
	typedef float (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Light::get_spotAngle");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Light());
	float i2res = icall(i2thiz);
	return i2res;
}
float UnityEngine_Light_get_intensity(MonoObject* thiz)
{
	typedef float (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Light::get_intensity");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Light());
	float i2res = icall(i2thiz);
	return i2res;
}
float UnityEngine_Light_get_bounceIntensity(MonoObject* thiz)
{
	typedef float (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Light::get_bounceIntensity");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Light());
	float i2res = icall(i2thiz);
	return i2res;
}
float UnityEngine_Light_get_range(MonoObject* thiz)
{
	typedef float (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Light::get_range");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Light());
	float i2res = icall(i2thiz);
	return i2res;
}
int32_t UnityEngine_Light_get_shadows(MonoObject* thiz)
{
	typedef int32_t (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Light::get_shadows");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Light());
	int32_t i2res = icall(i2thiz);
	return i2res;
}
float UnityEngine_Light_get_cookieSize(MonoObject* thiz)
{
	typedef float (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Light::get_cookieSize");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Light());
	float i2res = icall(i2thiz);
	return i2res;
}
MonoObject* UnityEngine_Light_get_cookie(MonoObject* thiz)
{
	typedef Il2CppObject* (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Light::get_cookie");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Light());
	Il2CppObject* i2res = icall(i2thiz);
	MonoObject* monoi2res = get_mono_object(i2res,mono_get_class_UnityEngine_Texture());
	if(i2res != NULL && monoi2res == NULL)
	{
		platform_log("UnityEngine.Light::get_cookie fail to convert il2cpp obj to mono");
	}
	return monoi2res;
}
MonoObject* UnityEngine_MeshFilter_get_sharedMesh(MonoObject* thiz)
{
	typedef Il2CppObject* (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.MeshFilter::get_sharedMesh");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_MeshFilter());
	Il2CppObject* i2res = icall(i2thiz);
	MonoObject* monoi2res = get_mono_object(i2res,mono_get_class_UnityEngine_Mesh());
	if(i2res != NULL && monoi2res == NULL)
	{
		platform_log("UnityEngine.MeshFilter::get_sharedMesh fail to convert il2cpp obj to mono");
	}
	return monoi2res;
}
void UnityEngine_MeshFilter_set_sharedMesh(MonoObject* thiz, MonoObject* value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, Il2CppObject* value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.MeshFilter::set_sharedMesh");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_MeshFilter());
	Il2CppObject* i2value = get_il2cpp_object(value,il2cpp_get_class_UnityEngine_Mesh());
	icall(i2thiz,i2value);
}
MonoObject* UnityEngine_MeshFilter_get_mesh(MonoObject* thiz)
{
	typedef Il2CppObject* (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.MeshFilter::get_mesh");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_MeshFilter());
	Il2CppObject* i2res = icall(i2thiz);
	MonoObject* monoi2res = get_mono_object(i2res,mono_get_class_UnityEngine_Mesh());
	if(i2res != NULL && monoi2res == NULL)
	{
		platform_log("UnityEngine.MeshFilter::get_mesh fail to convert il2cpp obj to mono");
	}
	return monoi2res;
}
void UnityEngine_MeshFilter_set_mesh(MonoObject* thiz, MonoObject* value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, Il2CppObject* value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.MeshFilter::set_mesh");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_MeshFilter());
	Il2CppObject* i2value = get_il2cpp_object(value,il2cpp_get_class_UnityEngine_Mesh());
	icall(i2thiz,i2value);
}
void UnityEngine_SkinnedMeshRenderer_BakeMesh(MonoObject* thiz, MonoObject* mesh, bool useScale)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, Il2CppObject* mesh, bool useScale);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.SkinnedMeshRenderer::BakeMesh");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_SkinnedMeshRenderer());
	Il2CppObject* i2mesh = get_il2cpp_object(mesh,il2cpp_get_class_UnityEngine_Mesh());
	icall(i2thiz,i2mesh,useScale);
}
MonoObject* UnityEngine_Texture2D_get_whiteTexture()
{
	typedef Il2CppObject* (* ICallMethod) ();
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Texture2D::get_whiteTexture");
	Il2CppObject* i2res = icall();
	MonoObject* monoi2res = get_mono_object(i2res,mono_get_class_UnityEngine_Texture2D());
	if(i2res != NULL && monoi2res == NULL)
	{
		platform_log("UnityEngine.Texture2D::get_whiteTexture fail to convert il2cpp obj to mono");
	}
	return monoi2res;
}
bool UnityEngine_Texture2D_get_isReadable_1(MonoObject* thiz)
{
	typedef bool (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Texture2D::get_isReadable");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Texture2D());
	bool i2res = icall(i2thiz);
	return i2res;
}
void* UnityEngine_Texture2D_GetPixels(MonoObject* thiz, int32_t x, int32_t y, int32_t blockWidth, int32_t blockHeight, int32_t miplevel)
{
	typedef void* (* ICallMethod) (Il2CppObject* thiz, int32_t x, int32_t y, int32_t blockWidth, int32_t blockHeight, int32_t miplevel);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Texture2D::GetPixels");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Texture2D());
	void* i2res = icall(i2thiz,x,y,blockWidth,blockHeight,miplevel);
	if(i2res != NULL && i2res == NULL)
	{
		platform_log("UnityEngine.Texture2D::GetPixels fail to convert il2cpp obj to mono");
	}
	return i2res;
}
void* UnityEngine_Texture2D_PackTextures(MonoObject* thiz, MonoArray* textures, int32_t padding, int32_t maximumAtlasSize, bool makeNoLongerReadable)
{
	typedef void* (* ICallMethod) (Il2CppObject* thiz, Il2CppArray* textures, int32_t padding, int32_t maximumAtlasSize, bool makeNoLongerReadable);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Texture2D::PackTextures");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Texture2D());
	Il2CppArray* i2textures = get_il2cpp_array(textures);
	void* i2res = icall(i2thiz,i2textures,padding,maximumAtlasSize,makeNoLongerReadable);
	if(i2res != NULL && i2res == NULL)
	{
		platform_log("UnityEngine.Texture2D::PackTextures fail to convert il2cpp obj to mono");
	}
	return i2res;
}
bool UnityEngine_Cubemap_get_isReadable_2(MonoObject* thiz)
{
	typedef bool (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Cubemap::get_isReadable");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Cubemap());
	bool i2res = icall(i2thiz);
	return i2res;
}
bool UnityEngine_Texture3D_get_isReadable_3(MonoObject* thiz)
{
	typedef bool (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Texture3D::get_isReadable");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Texture3D());
	bool i2res = icall(i2thiz);
	return i2res;
}
bool UnityEngine_Texture2DArray_get_isReadable_4(MonoObject* thiz)
{
	typedef bool (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Texture2DArray::get_isReadable");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Texture2DArray());
	bool i2res = icall(i2thiz);
	return i2res;
}
bool UnityEngine_CubemapArray_get_isReadable_5(MonoObject* thiz)
{
	typedef bool (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.CubemapArray::get_isReadable");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_CubemapArray());
	bool i2res = icall(i2thiz);
	return i2res;
}
void UnityEngine_Cursor_set_visible(bool value)
{
	typedef void (* ICallMethod) (bool value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Cursor::set_visible");
	icall(value);
}
int32_t UnityEngine_Cursor_get_lockState()
{
	typedef int32_t (* ICallMethod) ();
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Cursor::get_lockState");
	int32_t i2res = icall();
	return i2res;
}
void UnityEngine_Cursor_set_lockState(int32_t value)
{
	typedef void (* ICallMethod) (int32_t value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Cursor::set_lockState");
	icall(value);
}
int32_t UnityEngine_PlayerPrefs_GetInt(MonoString* key, int32_t defaultValue)
{
	typedef int32_t (* ICallMethod) (Il2CppString* key, int32_t defaultValue);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.PlayerPrefs::GetInt");
	Il2CppString* i2key = get_il2cpp_string(key);
	int32_t i2res = icall(i2key,defaultValue);
	return i2res;
}
float UnityEngine_PlayerPrefs_GetFloat(MonoString* key, float defaultValue)
{
	typedef float (* ICallMethod) (Il2CppString* key, float defaultValue);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.PlayerPrefs::GetFloat");
	Il2CppString* i2key = get_il2cpp_string(key);
	float i2res = icall(i2key,defaultValue);
	return i2res;
}
MonoString* UnityEngine_PlayerPrefs_GetString(MonoString* key, MonoString* defaultValue)
{
	typedef Il2CppString* (* ICallMethod) (Il2CppString* key, Il2CppString* defaultValue);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.PlayerPrefs::GetString");
	Il2CppString* i2key = get_il2cpp_string(key);
	Il2CppString* i2defaultValue = get_il2cpp_string(defaultValue);
	Il2CppString* i2res = icall(i2key,i2defaultValue);
	MonoString* monoi2res = get_mono_string(i2res);
	if(i2res != NULL && monoi2res == NULL)
	{
		platform_log("UnityEngine.PlayerPrefs::GetString fail to convert il2cpp obj to mono");
	}
	return monoi2res;
}
bool UnityEngine_PlayerPrefs_HasKey(MonoString* key)
{
	typedef bool (* ICallMethod) (Il2CppString* key);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.PlayerPrefs::HasKey");
	Il2CppString* i2key = get_il2cpp_string(key);
	bool i2res = icall(i2key);
	return i2res;
}
void UnityEngine_PlayerPrefs_DeleteKey(MonoString* key)
{
	typedef void (* ICallMethod) (Il2CppString* key);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.PlayerPrefs::DeleteKey");
	Il2CppString* i2key = get_il2cpp_string(key);
	icall(i2key);
}
void UnityEngine_PlayerPrefs_Save()
{
	typedef void (* ICallMethod) ();
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.PlayerPrefs::Save");
	icall();
}
void UnityEngine_PropertyNameUtils_PropertyNameFromString_Injected(MonoString* name, void * ret)
{
	typedef void (* ICallMethod) (Il2CppString* name, void * ret);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.PropertyNameUtils::PropertyNameFromString_Injected");
	Il2CppString* i2name = get_il2cpp_string(name);
	icall(i2name,ret);
}
int32_t UnityEngine_Random_RandomRangeInt(int32_t minInclusive, int32_t maxExclusive)
{
	typedef int32_t (* ICallMethod) (int32_t minInclusive, int32_t maxExclusive);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Random::RandomRangeInt");
	int32_t i2res = icall(minInclusive,maxExclusive);
	return i2res;
}
void UnityEngine_Random_InitState(int32_t seed)
{
	typedef void (* ICallMethod) (int32_t seed);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Random::InitState");
	icall(seed);
}
float UnityEngine_Random_Range(float minInclusive, float maxInclusive)
{
	typedef float (* ICallMethod) (float minInclusive, float maxInclusive);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Random::Range");
	float i2res = icall(minInclusive,maxInclusive);
	return i2res;
}
MonoArray* UnityEngine_ResourcesAPIInternal_FindObjectsOfTypeAll(MonoReflectionType* type)
{
	typedef Il2CppArray* (* ICallMethod) (Il2CppReflectionType* type);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.ResourcesAPIInternal::FindObjectsOfTypeAll");
	Il2CppReflectionType* i2type = get_il2cpp_reflection_type(type);
	Il2CppArray* i2res = icall(i2type);
	MonoArray* monoi2res = get_mono_array(i2res);
	if(i2res != NULL && monoi2res == NULL)
	{
		platform_log("UnityEngine.ResourcesAPIInternal::FindObjectsOfTypeAll fail to convert il2cpp obj to mono");
	}
	return monoi2res;
}
MonoObject* UnityEngine_ResourcesAPIInternal_FindShaderByName(MonoString* name)
{
	typedef Il2CppObject* (* ICallMethod) (Il2CppString* name);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.ResourcesAPIInternal::FindShaderByName");
	Il2CppString* i2name = get_il2cpp_string(name);
	Il2CppObject* i2res = icall(i2name);
	MonoObject* monoi2res = get_mono_object(i2res,mono_get_class_UnityEngine_Shader());
	if(i2res != NULL && monoi2res == NULL)
	{
		platform_log("UnityEngine.ResourcesAPIInternal::FindShaderByName fail to convert il2cpp obj to mono");
	}
	return monoi2res;
}
MonoObject* UnityEngine_ResourcesAPIInternal_Load(MonoString* path, MonoReflectionType* systemTypeInstance)
{
	typedef Il2CppObject* (* ICallMethod) (Il2CppString* path, Il2CppReflectionType* systemTypeInstance);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.ResourcesAPIInternal::Load");
	Il2CppString* i2path = get_il2cpp_string(path);
	Il2CppReflectionType* i2systemTypeInstance = get_il2cpp_reflection_type(systemTypeInstance);
	Il2CppObject* i2res = icall(i2path,i2systemTypeInstance);
	MonoObject* monoi2res = get_mono_object(i2res,get_mono_class(il2cpp_object_get_class(i2res)));
	if(i2res != NULL && monoi2res == NULL)
	{
		platform_log("UnityEngine.ResourcesAPIInternal::Load fail to convert il2cpp obj to mono");
	}
	return monoi2res;
}
MonoObject* UnityEngine_Resources_GetBuiltinResource(MonoReflectionType* type, MonoString* path)
{
	typedef Il2CppObject* (* ICallMethod) (Il2CppReflectionType* type, Il2CppString* path);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Resources::GetBuiltinResource");
	Il2CppReflectionType* i2type = get_il2cpp_reflection_type(type);
	Il2CppString* i2path = get_il2cpp_string(path);
	Il2CppObject* i2res = icall(i2type,i2path);
	MonoObject* monoi2res = get_mono_object(i2res,get_mono_class(il2cpp_object_get_class(i2res)));
	if(i2res != NULL && monoi2res == NULL)
	{
		platform_log("UnityEngine.Resources::GetBuiltinResource fail to convert il2cpp obj to mono");
	}
	return monoi2res;
}
MonoObject* UnityEngine_Resources_UnloadUnusedAssets()
{
	typedef Il2CppObject* (* ICallMethod) ();
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Resources::UnloadUnusedAssets");
	Il2CppObject* i2res = icall();
	MonoObject* monoi2res = get_mono_object(i2res,mono_get_class_UnityEngine_AsyncOperation());
	if(i2res != NULL && monoi2res == NULL)
	{
		platform_log("UnityEngine.Resources::UnloadUnusedAssets fail to convert il2cpp obj to mono");
	}
	return monoi2res;
}
bool UnityEngine_AsyncOperation_get_isDone(MonoObject* thiz)
{
	typedef bool (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.AsyncOperation::get_isDone");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_AsyncOperation());
	bool i2res = icall(i2thiz);
	return i2res;
}
int32_t UnityEngine_LayerMask_NameToLayer(MonoString* layerName)
{
	typedef int32_t (* ICallMethod) (Il2CppString* layerName);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.LayerMask::NameToLayer");
	Il2CppString* i2layerName = get_il2cpp_string(layerName);
	int32_t i2res = icall(i2layerName);
	return i2res;
}
bool UnityEngine_MonoBehaviour_get_useGUILayout(MonoObject* thiz)
{
	typedef bool (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.MonoBehaviour::get_useGUILayout");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_MonoBehaviour());
	bool i2res = icall(i2thiz);
	return i2res;
}
void UnityEngine_MonoBehaviour_set_useGUILayout(MonoObject* thiz, bool value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, bool value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.MonoBehaviour::set_useGUILayout");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_MonoBehaviour());
	icall(i2thiz,value);
}
void UnityEngine_MonoBehaviour_StopCoroutine(MonoObject* thiz, MonoString* methodName)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, Il2CppString* methodName);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.MonoBehaviour::StopCoroutine");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_MonoBehaviour());
	Il2CppString* i2methodName = get_il2cpp_string(methodName);
	icall(i2thiz,i2methodName);
}
void UnityEngine_MonoBehaviour_StopAllCoroutines(MonoObject* thiz)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.MonoBehaviour::StopAllCoroutines");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_MonoBehaviour());
	icall(i2thiz);
}
void UnityEngine_MonoBehaviour_Internal_CancelInvokeAll(MonoObject* self)
{
	typedef void (* ICallMethod) (Il2CppObject* self);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.MonoBehaviour::Internal_CancelInvokeAll");
	Il2CppObject* i2self = get_il2cpp_object(self,il2cpp_get_class_UnityEngine_MonoBehaviour());
	icall(i2self);
}
bool UnityEngine_MonoBehaviour_Internal_IsInvokingAll(MonoObject* self)
{
	typedef bool (* ICallMethod) (Il2CppObject* self);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.MonoBehaviour::Internal_IsInvokingAll");
	Il2CppObject* i2self = get_il2cpp_object(self,il2cpp_get_class_UnityEngine_MonoBehaviour());
	bool i2res = icall(i2self);
	return i2res;
}
void UnityEngine_MonoBehaviour_InvokeDelayed(MonoObject* self, MonoString* methodName, float time, float repeatRate)
{
	typedef void (* ICallMethod) (Il2CppObject* self, Il2CppString* methodName, float time, float repeatRate);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.MonoBehaviour::InvokeDelayed");
	Il2CppObject* i2self = get_il2cpp_object(self,il2cpp_get_class_UnityEngine_MonoBehaviour());
	Il2CppString* i2methodName = get_il2cpp_string(methodName);
	icall(i2self,i2methodName,time,repeatRate);
}
void UnityEngine_MonoBehaviour_CancelInvoke(MonoObject* self, MonoString* methodName)
{
	typedef void (* ICallMethod) (Il2CppObject* self, Il2CppString* methodName);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.MonoBehaviour::CancelInvoke");
	Il2CppObject* i2self = get_il2cpp_object(self,il2cpp_get_class_UnityEngine_MonoBehaviour());
	Il2CppString* i2methodName = get_il2cpp_string(methodName);
	icall(i2self,i2methodName);
}
bool UnityEngine_MonoBehaviour_IsInvoking(MonoObject* self, MonoString* methodName)
{
	typedef bool (* ICallMethod) (Il2CppObject* self, Il2CppString* methodName);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.MonoBehaviour::IsInvoking");
	Il2CppObject* i2self = get_il2cpp_object(self,il2cpp_get_class_UnityEngine_MonoBehaviour());
	Il2CppString* i2methodName = get_il2cpp_string(methodName);
	bool i2res = icall(i2self,i2methodName);
	return i2res;
}
bool UnityEngine_MonoBehaviour_IsObjectMonoBehaviour(MonoObject* obj)
{
	typedef bool (* ICallMethod) (Il2CppObject* obj);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.MonoBehaviour::IsObjectMonoBehaviour");
	Il2CppObject* i2obj = get_il2cpp_object(obj,il2cpp_get_class_UnityEngine_Object());
	bool i2res = icall(i2obj);
	return i2res;
}
MonoObject* UnityEngine_MonoBehaviour_StartCoroutineManaged(MonoObject* thiz, MonoString* methodName, MonoObject* value)
{
	typedef Il2CppObject* (* ICallMethod) (Il2CppObject* thiz, Il2CppString* methodName, Il2CppObject* value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.MonoBehaviour::StartCoroutineManaged");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_MonoBehaviour());
	Il2CppString* i2methodName = get_il2cpp_string(methodName);
	Il2CppObject* i2value = get_il2cpp_object(value,NULL);
	Il2CppObject* i2res = icall(i2thiz,i2methodName,i2value);
	MonoObject* monoi2res = get_mono_object(i2res,mono_get_class_UnityEngine_Coroutine());
	if(i2res != NULL && monoi2res == NULL)
	{
		platform_log("UnityEngine.MonoBehaviour::StartCoroutineManaged fail to convert il2cpp obj to mono");
	}
	return monoi2res;
}
void UnityEngine_MonoBehaviour_StopCoroutineManaged(MonoObject* thiz, MonoObject* routine)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, Il2CppObject* routine);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.MonoBehaviour::StopCoroutineManaged");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_MonoBehaviour());
	Il2CppObject* i2routine = get_il2cpp_object(routine,il2cpp_get_class_UnityEngine_Coroutine());
	icall(i2thiz,i2routine);
}
void UnityEngine_MonoBehaviour_StopCoroutineFromEnumeratorManaged(MonoObject* thiz, MonoObject* routine)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, Il2CppObject* routine);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.MonoBehaviour::StopCoroutineFromEnumeratorManaged");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_MonoBehaviour());
	Il2CppObject* i2routine = get_il2cpp_object(routine,NULL);
	icall(i2thiz,i2routine);
}
MonoString* UnityEngine_MonoBehaviour_GetScriptClassName(MonoObject* thiz)
{
	typedef Il2CppString* (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.MonoBehaviour::GetScriptClassName");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_MonoBehaviour());
	Il2CppString* i2res = icall(i2thiz);
	MonoString* monoi2res = get_mono_string(i2res);
	if(i2res != NULL && monoi2res == NULL)
	{
		platform_log("UnityEngine.MonoBehaviour::GetScriptClassName fail to convert il2cpp obj to mono");
	}
	return monoi2res;
}
void UnityEngine_ScriptableObject_CreateScriptableObject(MonoObject* self)
{
	typedef void (* ICallMethod) (Il2CppObject* self);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.ScriptableObject::CreateScriptableObject");
	Il2CppObject* i2self = get_il2cpp_object(self,il2cpp_get_class_UnityEngine_ScriptableObject());
	icall(i2self);
}
MonoObject* UnityEngine_ScriptableObject_CreateScriptableObjectInstanceFromType(MonoReflectionType* type, bool applyDefaultsAndReset)
{
	typedef Il2CppObject* (* ICallMethod) (Il2CppReflectionType* type, bool applyDefaultsAndReset);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.ScriptableObject::CreateScriptableObjectInstanceFromType");
	Il2CppReflectionType* i2type = get_il2cpp_reflection_type(type);
	Il2CppObject* i2res = icall(i2type,applyDefaultsAndReset);
	MonoObject* monoi2res = get_mono_object(i2res,mono_get_class_UnityEngine_ScriptableObject());
	if(i2res != NULL && monoi2res == NULL)
	{
		platform_log("UnityEngine.ScriptableObject::CreateScriptableObjectInstanceFromType fail to convert il2cpp obj to mono");
	}
	return monoi2res;
}
MonoArray* UnityEngine_TextAsset_get_bytes(MonoObject* thiz)
{
	typedef Il2CppArray* (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.TextAsset::get_bytes");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_TextAsset());
	Il2CppArray* i2res = icall(i2thiz);
	MonoArray* monoi2res = get_mono_array(i2res);
	if(i2res != NULL && monoi2res == NULL)
	{
		platform_log("UnityEngine.TextAsset::get_bytes fail to convert il2cpp obj to mono");
	}
	return monoi2res;
}
int32_t UnityEngine_ComputeShader_FindKernel(MonoObject* thiz, MonoString* name)
{
	typedef int32_t (* ICallMethod) (Il2CppObject* thiz, Il2CppString* name);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.ComputeShader::FindKernel");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_ComputeShader());
	Il2CppString* i2name = get_il2cpp_string(name);
	int32_t i2res = icall(i2thiz,i2name);
	return i2res;
}
void UnityEngine_ShaderVariantCollection_WarmUp(MonoObject* thiz)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.ShaderVariantCollection::WarmUp");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_ShaderVariantCollection());
	icall(i2thiz);
}
float UnityEngine_Time_get_time_2()
{
	typedef float (* ICallMethod) ();
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Time::get_time");
	float i2res = icall();
	return i2res;
}
float UnityEngine_Time_get_deltaTime()
{
	typedef float (* ICallMethod) ();
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Time::get_deltaTime");
	float i2res = icall();
	return i2res;
}
float UnityEngine_Time_get_unscaledTime()
{
	typedef float (* ICallMethod) ();
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Time::get_unscaledTime");
	float i2res = icall();
	return i2res;
}
float UnityEngine_Time_get_unscaledDeltaTime()
{
	typedef float (* ICallMethod) ();
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Time::get_unscaledDeltaTime");
	float i2res = icall();
	return i2res;
}
float UnityEngine_Time_get_fixedDeltaTime()
{
	typedef float (* ICallMethod) ();
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Time::get_fixedDeltaTime");
	float i2res = icall();
	return i2res;
}
float UnityEngine_Time_get_maximumDeltaTime()
{
	typedef float (* ICallMethod) ();
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Time::get_maximumDeltaTime");
	float i2res = icall();
	return i2res;
}
float UnityEngine_Time_get_timeScale()
{
	typedef float (* ICallMethod) ();
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Time::get_timeScale");
	float i2res = icall();
	return i2res;
}
void UnityEngine_Time_set_timeScale(float value)
{
	typedef void (* ICallMethod) (float value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Time::set_timeScale");
	icall(value);
}
int32_t UnityEngine_Time_get_frameCount()
{
	typedef int32_t (* ICallMethod) ();
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Time::get_frameCount");
	int32_t i2res = icall();
	return i2res;
}
float UnityEngine_Time_get_realtimeSinceStartup()
{
	typedef float (* ICallMethod) ();
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Time::get_realtimeSinceStartup");
	float i2res = icall();
	return i2res;
}
void UnityEngine_Time_set_captureDeltaTime(float value)
{
	typedef void (* ICallMethod) (float value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Time::set_captureDeltaTime");
	icall(value);
}
MonoString* UnityEngine_TouchScreenKeyboard_get_text(MonoObject* thiz)
{
	typedef Il2CppString* (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.TouchScreenKeyboard::get_text");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_TouchScreenKeyboard());
	Il2CppString* i2res = icall(i2thiz);
	MonoString* monoi2res = get_mono_string(i2res);
	if(i2res != NULL && monoi2res == NULL)
	{
		platform_log("UnityEngine.TouchScreenKeyboard::get_text fail to convert il2cpp obj to mono");
	}
	return monoi2res;
}
void UnityEngine_TouchScreenKeyboard_set_text(MonoObject* thiz, MonoString* value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, Il2CppString* value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.TouchScreenKeyboard::set_text");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_TouchScreenKeyboard());
	Il2CppString* i2value = get_il2cpp_string(value);
	icall(i2thiz,i2value);
}
void UnityEngine_TouchScreenKeyboard_set_hideInput(bool value)
{
	typedef void (* ICallMethod) (bool value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.TouchScreenKeyboard::set_hideInput");
	icall(value);
}
bool UnityEngine_TouchScreenKeyboard_get_active_1(MonoObject* thiz)
{
	typedef bool (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.TouchScreenKeyboard::get_active");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_TouchScreenKeyboard());
	bool i2res = icall(i2thiz);
	return i2res;
}
void UnityEngine_TouchScreenKeyboard_set_active(MonoObject* thiz, bool value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, bool value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.TouchScreenKeyboard::set_active");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_TouchScreenKeyboard());
	icall(i2thiz,value);
}
int32_t UnityEngine_TouchScreenKeyboard_get_status(MonoObject* thiz)
{
	typedef int32_t (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.TouchScreenKeyboard::get_status");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_TouchScreenKeyboard());
	int32_t i2res = icall(i2thiz);
	return i2res;
}
void UnityEngine_TouchScreenKeyboard_set_characterLimit(MonoObject* thiz, int32_t value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, int32_t value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.TouchScreenKeyboard::set_characterLimit");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_TouchScreenKeyboard());
	icall(i2thiz,value);
}
bool UnityEngine_TouchScreenKeyboard_get_canGetSelection(MonoObject* thiz)
{
	typedef bool (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.TouchScreenKeyboard::get_canGetSelection");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_TouchScreenKeyboard());
	bool i2res = icall(i2thiz);
	return i2res;
}
bool UnityEngine_TouchScreenKeyboard_get_canSetSelection(MonoObject* thiz)
{
	typedef bool (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.TouchScreenKeyboard::get_canSetSelection");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_TouchScreenKeyboard());
	bool i2res = icall(i2thiz);
	return i2res;
}
void UnityEngine_SpriteRenderer_set_sprite(MonoObject* thiz, MonoObject* value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, Il2CppObject* value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.SpriteRenderer::set_sprite");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_SpriteRenderer());
	Il2CppObject* i2value = get_il2cpp_object(value,il2cpp_get_class_UnityEngine_Sprite());
	icall(i2thiz,i2value);
}
MonoObject* UnityEngine_Sprite_get_texture(MonoObject* thiz)
{
	typedef Il2CppObject* (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Sprite::get_texture");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Sprite());
	Il2CppObject* i2res = icall(i2thiz);
	MonoObject* monoi2res = get_mono_object(i2res,mono_get_class_UnityEngine_Texture2D());
	if(i2res != NULL && monoi2res == NULL)
	{
		platform_log("UnityEngine.Sprite::get_texture fail to convert il2cpp obj to mono");
	}
	return monoi2res;
}
float UnityEngine_Sprite_get_pixelsPerUnit(MonoObject* thiz)
{
	typedef float (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Sprite::get_pixelsPerUnit");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Sprite());
	float i2res = icall(i2thiz);
	return i2res;
}
MonoObject* UnityEngine_Sprite_get_associatedAlphaSplitTexture(MonoObject* thiz)
{
	typedef Il2CppObject* (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Sprite::get_associatedAlphaSplitTexture");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Sprite());
	Il2CppObject* i2res = icall(i2thiz);
	MonoObject* monoi2res = get_mono_object(i2res,mono_get_class_UnityEngine_Texture2D());
	if(i2res != NULL && monoi2res == NULL)
	{
		platform_log("UnityEngine.Sprite::get_associatedAlphaSplitTexture fail to convert il2cpp obj to mono");
	}
	return monoi2res;
}
void* UnityEngine_Sprite_get_vertices(MonoObject* thiz)
{
	typedef void* (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Sprite::get_vertices");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Sprite());
	void* i2res = icall(i2thiz);
	if(i2res != NULL && i2res == NULL)
	{
		platform_log("UnityEngine.Sprite::get_vertices fail to convert il2cpp obj to mono");
	}
	return i2res;
}
MonoArray* UnityEngine_Sprite_get_triangles(MonoObject* thiz)
{
	typedef Il2CppArray* (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Sprite::get_triangles");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Sprite());
	Il2CppArray* i2res = icall(i2thiz);
	MonoArray* monoi2res = get_mono_array(i2res);
	if(i2res != NULL && monoi2res == NULL)
	{
		platform_log("UnityEngine.Sprite::get_triangles fail to convert il2cpp obj to mono");
	}
	return monoi2res;
}
void* UnityEngine_Sprite_get_uv(MonoObject* thiz)
{
	typedef void* (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Sprite::get_uv");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Sprite());
	void* i2res = icall(i2thiz);
	if(i2res != NULL && i2res == NULL)
	{
		platform_log("UnityEngine.Sprite::get_uv fail to convert il2cpp obj to mono");
	}
	return i2res;
}
void UnityEngine_Sprite_GetInnerUVs_Injected(MonoObject* thiz, void * ret)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, void * ret);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Sprite::GetInnerUVs_Injected");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Sprite());
	icall(i2thiz,ret);
}
void UnityEngine_Sprite_GetOuterUVs_Injected(MonoObject* thiz, void * ret)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, void * ret);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Sprite::GetOuterUVs_Injected");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Sprite());
	icall(i2thiz,ret);
}
void UnityEngine_Sprite_GetPadding_Injected(MonoObject* thiz, void * ret)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, void * ret);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Sprite::GetPadding_Injected");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Sprite());
	icall(i2thiz,ret);
}
bool UnityEngine_Playables_PlayableGraph_IsValid_Injected(void * _unity_self)
{
	typedef bool (* ICallMethod) (void * _unity_self);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Playables.PlayableGraph::IsValid_Injected");
	bool i2res = icall(_unity_self);
	return i2res;
}
void UnityEngine_Playables_PlayableGraph_Stop_Injected(void * _unity_self)
{
	typedef void (* ICallMethod) (void * _unity_self);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Playables.PlayableGraph::Stop_Injected");
	icall(_unity_self);
}
int32_t UnityEngine_Playables_PlayableGraph_GetPlayableCount_Injected(void * _unity_self)
{
	typedef int32_t (* ICallMethod) (void * _unity_self);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Playables.PlayableGraph::GetPlayableCount_Injected");
	int32_t i2res = icall(_unity_self);
	return i2res;
}
void UnityEngine_Playables_PlayableGraph_CreatePlayableHandle_Injected(void * _unity_self, void * ret)
{
	typedef void (* ICallMethod) (void * _unity_self, void * ret);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Playables.PlayableGraph::CreatePlayableHandle_Injected");
	icall(_unity_self,ret);
}
bool UnityEngine_Playables_PlayableGraph_CreateScriptOutputInternal_Injected(void * _unity_self, MonoString* name, void * handle)
{
	typedef bool (* ICallMethod) (void * _unity_self, Il2CppString* name, void * handle);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Playables.PlayableGraph::CreateScriptOutputInternal_Injected");
	Il2CppString* i2name = get_il2cpp_string(name);
	bool i2res = icall(_unity_self,i2name,handle);
	return i2res;
}
void UnityEngine_Playables_PlayableGraph_GetRootPlayableInternal_Injected(void * _unity_self, int32_t index, void * ret)
{
	typedef void (* ICallMethod) (void * _unity_self, int32_t index, void * ret);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Playables.PlayableGraph::GetRootPlayableInternal_Injected");
	icall(_unity_self,index,ret);
}
bool UnityEngine_Playables_PlayableGraph_ConnectInternal_Injected(void * _unity_self, void * source, int32_t sourceOutputPort, void * destination, int32_t destinationInputPort)
{
	typedef bool (* ICallMethod) (void * _unity_self, void * source, int32_t sourceOutputPort, void * destination, int32_t destinationInputPort);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Playables.PlayableGraph::ConnectInternal_Injected");
	bool i2res = icall(_unity_self,source,sourceOutputPort,destination,destinationInputPort);
	return i2res;
}
void UnityEngine_Playables_PlayableGraph_DestroyPlayableInternal_Injected(void * _unity_self, void * playable)
{
	typedef void (* ICallMethod) (void * _unity_self, void * playable);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Playables.PlayableGraph::DestroyPlayableInternal_Injected");
	icall(_unity_self,playable);
}
bool UnityEngine_Playables_PlayableHandle_IsNull_Injected(void * _unity_self)
{
	typedef bool (* ICallMethod) (void * _unity_self);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Playables.PlayableHandle::IsNull_Injected");
	bool i2res = icall(_unity_self);
	return i2res;
}
bool UnityEngine_Playables_PlayableHandle_IsValid_Injected_1(void * _unity_self)
{
	typedef bool (* ICallMethod) (void * _unity_self);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Playables.PlayableHandle::IsValid_Injected");
	bool i2res = icall(_unity_self);
	return i2res;
}
MonoReflectionType* UnityEngine_Playables_PlayableHandle_GetPlayableType_Injected(void * _unity_self)
{
	typedef Il2CppReflectionType* (* ICallMethod) (void * _unity_self);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Playables.PlayableHandle::GetPlayableType_Injected");
	Il2CppReflectionType* i2res = icall(_unity_self);
	MonoReflectionType* monoi2res = get_mono_reflection_type(i2res);
	if(i2res != NULL && monoi2res == NULL)
	{
		platform_log("UnityEngine.Playables.PlayableHandle::GetPlayableType_Injected fail to convert il2cpp obj to mono");
	}
	return monoi2res;
}
MonoReflectionType* UnityEngine_Playables_PlayableHandle_GetJobType_Injected(void * _unity_self)
{
	typedef Il2CppReflectionType* (* ICallMethod) (void * _unity_self);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Playables.PlayableHandle::GetJobType_Injected");
	Il2CppReflectionType* i2res = icall(_unity_self);
	MonoReflectionType* monoi2res = get_mono_reflection_type(i2res);
	if(i2res != NULL && monoi2res == NULL)
	{
		platform_log("UnityEngine.Playables.PlayableHandle::GetJobType_Injected fail to convert il2cpp obj to mono");
	}
	return monoi2res;
}
void UnityEngine_Playables_PlayableHandle_SetScriptInstance_Injected(void * _unity_self, MonoObject* scriptInstance)
{
	typedef void (* ICallMethod) (void * _unity_self, Il2CppObject* scriptInstance);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Playables.PlayableHandle::SetScriptInstance_Injected");
	Il2CppObject* i2scriptInstance = get_il2cpp_object(scriptInstance,NULL);
	icall(_unity_self,i2scriptInstance);
}
bool UnityEngine_Playables_PlayableHandle_CanChangeInputs_Injected(void * _unity_self)
{
	typedef bool (* ICallMethod) (void * _unity_self);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Playables.PlayableHandle::CanChangeInputs_Injected");
	bool i2res = icall(_unity_self);
	return i2res;
}
bool UnityEngine_Playables_PlayableHandle_CanSetWeights_Injected(void * _unity_self)
{
	typedef bool (* ICallMethod) (void * _unity_self);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Playables.PlayableHandle::CanSetWeights_Injected");
	bool i2res = icall(_unity_self);
	return i2res;
}
bool UnityEngine_Playables_PlayableHandle_CanDestroy_Injected(void * _unity_self)
{
	typedef bool (* ICallMethod) (void * _unity_self);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Playables.PlayableHandle::CanDestroy_Injected");
	bool i2res = icall(_unity_self);
	return i2res;
}
int32_t UnityEngine_Playables_PlayableHandle_GetPlayState_Injected(void * _unity_self)
{
	typedef int32_t (* ICallMethod) (void * _unity_self);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Playables.PlayableHandle::GetPlayState_Injected");
	int32_t i2res = icall(_unity_self);
	return i2res;
}
void UnityEngine_Playables_PlayableHandle_Play_Injected(void * _unity_self)
{
	typedef void (* ICallMethod) (void * _unity_self);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Playables.PlayableHandle::Play_Injected");
	icall(_unity_self);
}
void UnityEngine_Playables_PlayableHandle_Pause_Injected(void * _unity_self)
{
	typedef void (* ICallMethod) (void * _unity_self);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Playables.PlayableHandle::Pause_Injected");
	icall(_unity_self);
}
double UnityEngine_Playables_PlayableHandle_GetSpeed_Injected(void * _unity_self)
{
	typedef double (* ICallMethod) (void * _unity_self);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Playables.PlayableHandle::GetSpeed_Injected");
	double i2res = icall(_unity_self);
	return i2res;
}
void UnityEngine_Playables_PlayableHandle_SetSpeed_Injected(void * _unity_self, double value)
{
	typedef void (* ICallMethod) (void * _unity_self, double value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Playables.PlayableHandle::SetSpeed_Injected");
	icall(_unity_self,value);
}
double UnityEngine_Playables_PlayableHandle_GetTime_Injected(void * _unity_self)
{
	typedef double (* ICallMethod) (void * _unity_self);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Playables.PlayableHandle::GetTime_Injected");
	double i2res = icall(_unity_self);
	return i2res;
}
void UnityEngine_Playables_PlayableHandle_SetTime_Injected(void * _unity_self, double value)
{
	typedef void (* ICallMethod) (void * _unity_self, double value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Playables.PlayableHandle::SetTime_Injected");
	icall(_unity_self,value);
}
bool UnityEngine_Playables_PlayableHandle_IsDone_Injected(void * _unity_self)
{
	typedef bool (* ICallMethod) (void * _unity_self);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Playables.PlayableHandle::IsDone_Injected");
	bool i2res = icall(_unity_self);
	return i2res;
}
void UnityEngine_Playables_PlayableHandle_SetDone_Injected(void * _unity_self, bool value)
{
	typedef void (* ICallMethod) (void * _unity_self, bool value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Playables.PlayableHandle::SetDone_Injected");
	icall(_unity_self,value);
}
double UnityEngine_Playables_PlayableHandle_GetDuration_Injected(void * _unity_self)
{
	typedef double (* ICallMethod) (void * _unity_self);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Playables.PlayableHandle::GetDuration_Injected");
	double i2res = icall(_unity_self);
	return i2res;
}
void UnityEngine_Playables_PlayableHandle_SetDuration_Injected(void * _unity_self, double value)
{
	typedef void (* ICallMethod) (void * _unity_self, double value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Playables.PlayableHandle::SetDuration_Injected");
	icall(_unity_self,value);
}
bool UnityEngine_Playables_PlayableHandle_GetPropagateSetTime_Injected(void * _unity_self)
{
	typedef bool (* ICallMethod) (void * _unity_self);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Playables.PlayableHandle::GetPropagateSetTime_Injected");
	bool i2res = icall(_unity_self);
	return i2res;
}
void UnityEngine_Playables_PlayableHandle_SetPropagateSetTime_Injected(void * _unity_self, bool value)
{
	typedef void (* ICallMethod) (void * _unity_self, bool value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Playables.PlayableHandle::SetPropagateSetTime_Injected");
	icall(_unity_self,value);
}
void UnityEngine_Playables_PlayableHandle_GetGraph_Injected(void * _unity_self, void * ret)
{
	typedef void (* ICallMethod) (void * _unity_self, void * ret);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Playables.PlayableHandle::GetGraph_Injected");
	icall(_unity_self,ret);
}
int32_t UnityEngine_Playables_PlayableHandle_GetInputCount_Injected(void * _unity_self)
{
	typedef int32_t (* ICallMethod) (void * _unity_self);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Playables.PlayableHandle::GetInputCount_Injected");
	int32_t i2res = icall(_unity_self);
	return i2res;
}
void UnityEngine_Playables_PlayableHandle_SetInputCount_Injected(void * _unity_self, int32_t value)
{
	typedef void (* ICallMethod) (void * _unity_self, int32_t value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Playables.PlayableHandle::SetInputCount_Injected");
	icall(_unity_self,value);
}
int32_t UnityEngine_Playables_PlayableHandle_GetOutputCount_Injected(void * _unity_self)
{
	typedef int32_t (* ICallMethod) (void * _unity_self);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Playables.PlayableHandle::GetOutputCount_Injected");
	int32_t i2res = icall(_unity_self);
	return i2res;
}
void UnityEngine_Playables_PlayableHandle_SetOutputCount_Injected(void * _unity_self, int32_t value)
{
	typedef void (* ICallMethod) (void * _unity_self, int32_t value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Playables.PlayableHandle::SetOutputCount_Injected");
	icall(_unity_self,value);
}
void UnityEngine_Playables_PlayableHandle_SetInputWeight_Injected(void * _unity_self, void * input, float weight)
{
	typedef void (* ICallMethod) (void * _unity_self, void * input, float weight);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Playables.PlayableHandle::SetInputWeight_Injected");
	icall(_unity_self,input,weight);
}
void UnityEngine_Playables_PlayableHandle_SetDelay_Injected(void * _unity_self, double delay)
{
	typedef void (* ICallMethod) (void * _unity_self, double delay);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Playables.PlayableHandle::SetDelay_Injected");
	icall(_unity_self,delay);
}
double UnityEngine_Playables_PlayableHandle_GetDelay_Injected(void * _unity_self)
{
	typedef double (* ICallMethod) (void * _unity_self);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Playables.PlayableHandle::GetDelay_Injected");
	double i2res = icall(_unity_self);
	return i2res;
}
bool UnityEngine_Playables_PlayableHandle_IsDelayed_Injected(void * _unity_self)
{
	typedef bool (* ICallMethod) (void * _unity_self);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Playables.PlayableHandle::IsDelayed_Injected");
	bool i2res = icall(_unity_self);
	return i2res;
}
double UnityEngine_Playables_PlayableHandle_GetPreviousTime_Injected(void * _unity_self)
{
	typedef double (* ICallMethod) (void * _unity_self);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Playables.PlayableHandle::GetPreviousTime_Injected");
	double i2res = icall(_unity_self);
	return i2res;
}
void UnityEngine_Playables_PlayableHandle_SetLeadTime_Injected(void * _unity_self, float value)
{
	typedef void (* ICallMethod) (void * _unity_self, float value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Playables.PlayableHandle::SetLeadTime_Injected");
	icall(_unity_self,value);
}
float UnityEngine_Playables_PlayableHandle_GetLeadTime_Injected(void * _unity_self)
{
	typedef float (* ICallMethod) (void * _unity_self);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Playables.PlayableHandle::GetLeadTime_Injected");
	float i2res = icall(_unity_self);
	return i2res;
}
int32_t UnityEngine_Playables_PlayableHandle_GetTraversalMode_Injected(void * _unity_self)
{
	typedef int32_t (* ICallMethod) (void * _unity_self);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Playables.PlayableHandle::GetTraversalMode_Injected");
	int32_t i2res = icall(_unity_self);
	return i2res;
}
void UnityEngine_Playables_PlayableHandle_SetTraversalMode_Injected(void * _unity_self, int32_t mode)
{
	typedef void (* ICallMethod) (void * _unity_self, int32_t mode);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Playables.PlayableHandle::SetTraversalMode_Injected");
	icall(_unity_self,mode);
}
void * UnityEngine_Playables_PlayableHandle_GetJobData_Injected(void * _unity_self)
{
	typedef void * (* ICallMethod) (void * _unity_self);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Playables.PlayableHandle::GetJobData_Injected");
	void * i2res = icall(_unity_self);
	if(i2res != NULL && i2res == NULL)
	{
		platform_log("UnityEngine.Playables.PlayableHandle::GetJobData_Injected fail to convert il2cpp obj to mono");
	}
	return i2res;
}
int32_t UnityEngine_Playables_PlayableHandle_GetTimeWrapMode_Injected(void * _unity_self)
{
	typedef int32_t (* ICallMethod) (void * _unity_self);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Playables.PlayableHandle::GetTimeWrapMode_Injected");
	int32_t i2res = icall(_unity_self);
	return i2res;
}
void UnityEngine_Playables_PlayableHandle_SetTimeWrapMode_Injected(void * _unity_self, int32_t mode)
{
	typedef void (* ICallMethod) (void * _unity_self, int32_t mode);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Playables.PlayableHandle::SetTimeWrapMode_Injected");
	icall(_unity_self,mode);
}
MonoObject* UnityEngine_Playables_PlayableHandle_GetScriptInstance_Injected(void * _unity_self)
{
	typedef Il2CppObject* (* ICallMethod) (void * _unity_self);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Playables.PlayableHandle::GetScriptInstance_Injected");
	Il2CppObject* i2res = icall(_unity_self);
	MonoObject* monoi2res = get_mono_object(i2res,get_mono_class(il2cpp_object_get_class(i2res)));
	if(i2res != NULL && monoi2res == NULL)
	{
		platform_log("UnityEngine.Playables.PlayableHandle::GetScriptInstance_Injected fail to convert il2cpp obj to mono");
	}
	return monoi2res;
}
void UnityEngine_Playables_PlayableHandle_GetInputHandle_Injected(void * _unity_self, int32_t index, void * ret)
{
	typedef void (* ICallMethod) (void * _unity_self, int32_t index, void * ret);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Playables.PlayableHandle::GetInputHandle_Injected");
	icall(_unity_self,index,ret);
}
void UnityEngine_Playables_PlayableHandle_GetOutputHandle_Injected(void * _unity_self, int32_t index, void * ret)
{
	typedef void (* ICallMethod) (void * _unity_self, int32_t index, void * ret);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Playables.PlayableHandle::GetOutputHandle_Injected");
	icall(_unity_self,index,ret);
}
void UnityEngine_Playables_PlayableHandle_SetInputWeightFromIndex_Injected(void * _unity_self, int32_t index, float weight)
{
	typedef void (* ICallMethod) (void * _unity_self, int32_t index, float weight);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Playables.PlayableHandle::SetInputWeightFromIndex_Injected");
	icall(_unity_self,index,weight);
}
float UnityEngine_Playables_PlayableHandle_GetInputWeightFromIndex_Injected(void * _unity_self, int32_t index)
{
	typedef float (* ICallMethod) (void * _unity_self, int32_t index);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Playables.PlayableHandle::GetInputWeightFromIndex_Injected");
	float i2res = icall(_unity_self,index);
	return i2res;
}
bool UnityEngine_Playables_PlayableOutputHandle_IsNull_Injected_1(void * _unity_self)
{
	typedef bool (* ICallMethod) (void * _unity_self);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Playables.PlayableOutputHandle::IsNull_Injected");
	bool i2res = icall(_unity_self);
	return i2res;
}
bool UnityEngine_Playables_PlayableOutputHandle_IsValid_Injected_2(void * _unity_self)
{
	typedef bool (* ICallMethod) (void * _unity_self);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Playables.PlayableOutputHandle::IsValid_Injected");
	bool i2res = icall(_unity_self);
	return i2res;
}
MonoReflectionType* UnityEngine_Playables_PlayableOutputHandle_GetPlayableOutputType_Injected(void * _unity_self)
{
	typedef Il2CppReflectionType* (* ICallMethod) (void * _unity_self);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Playables.PlayableOutputHandle::GetPlayableOutputType_Injected");
	Il2CppReflectionType* i2res = icall(_unity_self);
	MonoReflectionType* monoi2res = get_mono_reflection_type(i2res);
	if(i2res != NULL && monoi2res == NULL)
	{
		platform_log("UnityEngine.Playables.PlayableOutputHandle::GetPlayableOutputType_Injected fail to convert il2cpp obj to mono");
	}
	return monoi2res;
}
MonoObject* UnityEngine_Playables_PlayableOutputHandle_GetReferenceObject_Injected(void * _unity_self)
{
	typedef Il2CppObject* (* ICallMethod) (void * _unity_self);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Playables.PlayableOutputHandle::GetReferenceObject_Injected");
	Il2CppObject* i2res = icall(_unity_self);
	MonoObject* monoi2res = get_mono_object(i2res,get_mono_class(il2cpp_object_get_class(i2res)));
	if(i2res != NULL && monoi2res == NULL)
	{
		platform_log("UnityEngine.Playables.PlayableOutputHandle::GetReferenceObject_Injected fail to convert il2cpp obj to mono");
	}
	return monoi2res;
}
void UnityEngine_Playables_PlayableOutputHandle_SetReferenceObject_Injected(void * _unity_self, MonoObject* target)
{
	typedef void (* ICallMethod) (void * _unity_self, Il2CppObject* target);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Playables.PlayableOutputHandle::SetReferenceObject_Injected");
	Il2CppObject* i2target = get_il2cpp_object(target,il2cpp_get_class_UnityEngine_Object());
	icall(_unity_self,i2target);
}
MonoObject* UnityEngine_Playables_PlayableOutputHandle_GetUserData_Injected(void * _unity_self)
{
	typedef Il2CppObject* (* ICallMethod) (void * _unity_self);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Playables.PlayableOutputHandle::GetUserData_Injected");
	Il2CppObject* i2res = icall(_unity_self);
	MonoObject* monoi2res = get_mono_object(i2res,get_mono_class(il2cpp_object_get_class(i2res)));
	if(i2res != NULL && monoi2res == NULL)
	{
		platform_log("UnityEngine.Playables.PlayableOutputHandle::GetUserData_Injected fail to convert il2cpp obj to mono");
	}
	return monoi2res;
}
void UnityEngine_Playables_PlayableOutputHandle_SetUserData_Injected(void * _unity_self, MonoObject* target)
{
	typedef void (* ICallMethod) (void * _unity_self, Il2CppObject* target);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Playables.PlayableOutputHandle::SetUserData_Injected");
	Il2CppObject* i2target = get_il2cpp_object(target,il2cpp_get_class_UnityEngine_Object());
	icall(_unity_self,i2target);
}
void UnityEngine_Playables_PlayableOutputHandle_GetSourcePlayable_Injected(void * _unity_self, void * ret)
{
	typedef void (* ICallMethod) (void * _unity_self, void * ret);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Playables.PlayableOutputHandle::GetSourcePlayable_Injected");
	icall(_unity_self,ret);
}
void UnityEngine_Playables_PlayableOutputHandle_SetSourcePlayable_Injected(void * _unity_self, void * target, int32_t port)
{
	typedef void (* ICallMethod) (void * _unity_self, void * target, int32_t port);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Playables.PlayableOutputHandle::SetSourcePlayable_Injected");
	icall(_unity_self,target,port);
}
int32_t UnityEngine_Playables_PlayableOutputHandle_GetSourceOutputPort_Injected(void * _unity_self)
{
	typedef int32_t (* ICallMethod) (void * _unity_self);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Playables.PlayableOutputHandle::GetSourceOutputPort_Injected");
	int32_t i2res = icall(_unity_self);
	return i2res;
}
float UnityEngine_Playables_PlayableOutputHandle_GetWeight_Injected(void * _unity_self)
{
	typedef float (* ICallMethod) (void * _unity_self);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Playables.PlayableOutputHandle::GetWeight_Injected");
	float i2res = icall(_unity_self);
	return i2res;
}
void UnityEngine_Playables_PlayableOutputHandle_SetWeight_Injected(void * _unity_self, float weight)
{
	typedef void (* ICallMethod) (void * _unity_self, float weight);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Playables.PlayableOutputHandle::SetWeight_Injected");
	icall(_unity_self,weight);
}
void UnityEngine_Playables_PlayableOutputHandle_PushNotification_Injected(void * _unity_self, void * origin, MonoObject* notification, MonoObject* context)
{
	typedef void (* ICallMethod) (void * _unity_self, void * origin, Il2CppObject* notification, Il2CppObject* context);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Playables.PlayableOutputHandle::PushNotification_Injected");
	Il2CppObject* i2notification = get_il2cpp_object(notification,il2cpp_get_class_UnityEngine_Playables_INotification());
	Il2CppObject* i2context = get_il2cpp_object(context,NULL);
	icall(_unity_self,origin,i2notification,i2context);
}
MonoArray* UnityEngine_Playables_PlayableOutputHandle_GetNotificationReceivers_Injected(void * _unity_self)
{
	typedef Il2CppArray* (* ICallMethod) (void * _unity_self);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Playables.PlayableOutputHandle::GetNotificationReceivers_Injected");
	Il2CppArray* i2res = icall(_unity_self);
	MonoArray* monoi2res = get_mono_array(i2res);
	if(i2res != NULL && monoi2res == NULL)
	{
		platform_log("UnityEngine.Playables.PlayableOutputHandle::GetNotificationReceivers_Injected fail to convert il2cpp obj to mono");
	}
	return monoi2res;
}
void UnityEngine_Playables_PlayableOutputHandle_AddNotificationReceiver_Injected(void * _unity_self, MonoObject* receiver)
{
	typedef void (* ICallMethod) (void * _unity_self, Il2CppObject* receiver);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Playables.PlayableOutputHandle::AddNotificationReceiver_Injected");
	Il2CppObject* i2receiver = get_il2cpp_object(receiver,il2cpp_get_class_UnityEngine_Playables_INotificationReceiver());
	icall(_unity_self,i2receiver);
}
void UnityEngine_Playables_PlayableOutputHandle_RemoveNotificationReceiver_Injected(void * _unity_self, MonoObject* receiver)
{
	typedef void (* ICallMethod) (void * _unity_self, Il2CppObject* receiver);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Playables.PlayableOutputHandle::RemoveNotificationReceiver_Injected");
	Il2CppObject* i2receiver = get_il2cpp_object(receiver,il2cpp_get_class_UnityEngine_Playables_INotificationReceiver());
	icall(_unity_self,i2receiver);
}
bool UnityEngine_SceneManagement_Scene_IsValidInternal(int32_t sceneHandle)
{
	typedef bool (* ICallMethod) (int32_t sceneHandle);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.SceneManagement.Scene::IsValidInternal");
	bool i2res = icall(sceneHandle);
	return i2res;
}
bool UnityEngine_SceneManagement_Scene_GetIsLoadedInternal(int32_t sceneHandle)
{
	typedef bool (* ICallMethod) (int32_t sceneHandle);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.SceneManagement.Scene::GetIsLoadedInternal");
	bool i2res = icall(sceneHandle);
	return i2res;
}
int32_t UnityEngine_SceneManagement_Scene_GetRootCountInternal(int32_t sceneHandle)
{
	typedef int32_t (* ICallMethod) (int32_t sceneHandle);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.SceneManagement.Scene::GetRootCountInternal");
	int32_t i2res = icall(sceneHandle);
	return i2res;
}
void UnityEngine_SceneManagement_Scene_GetRootGameObjectsInternal(int32_t sceneHandle, MonoObject* resultRootList)
{
	typedef void (* ICallMethod) (int32_t sceneHandle, Il2CppObject* resultRootList);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.SceneManagement.Scene::GetRootGameObjectsInternal");
	Il2CppObject* i2resultRootList = get_il2cpp_object(resultRootList,NULL);
	icall(sceneHandle,i2resultRootList);
}
int32_t UnityEngine_SceneManagement_SceneManager_get_sceneCount()
{
	typedef int32_t (* ICallMethod) ();
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.SceneManagement.SceneManager::get_sceneCount");
	int32_t i2res = icall();
	return i2res;
}
void UnityEngine_SceneManagement_SceneManager_GetActiveScene_Injected(void * ret)
{
	typedef void (* ICallMethod) (void * ret);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.SceneManagement.SceneManager::GetActiveScene_Injected");
	icall(ret);
}
void UnityEngine_SceneManagement_SceneManager_GetSceneByName_Injected(MonoString* name, void * ret)
{
	typedef void (* ICallMethod) (Il2CppString* name, void * ret);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.SceneManagement.SceneManager::GetSceneByName_Injected");
	Il2CppString* i2name = get_il2cpp_string(name);
	icall(i2name,ret);
}
void UnityEngine_SceneManagement_SceneManager_GetSceneAt_Injected(int32_t index, void * ret)
{
	typedef void (* ICallMethod) (int32_t index, void * ret);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.SceneManagement.SceneManager::GetSceneAt_Injected");
	icall(index,ret);
}
bool UnityEngine_Scripting_GarbageCollector_get_isIncremental()
{
	typedef bool (* ICallMethod) ();
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Scripting.GarbageCollector::get_isIncremental");
	bool i2res = icall();
	return i2res;
}
uint64_t UnityEngine_Scripting_GarbageCollector_get_incrementalTimeSliceNanoseconds()
{
	typedef uint64_t (* ICallMethod) ();
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Scripting.GarbageCollector::get_incrementalTimeSliceNanoseconds");
	uint64_t i2res = icall();
	return i2res;
}
void UnityEngine_Scripting_GarbageCollector_set_incrementalTimeSliceNanoseconds(uint64_t value)
{
	typedef void (* ICallMethod) (uint64_t value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Scripting.GarbageCollector::set_incrementalTimeSliceNanoseconds");
	icall(value);
}
bool UnityEngine_Scripting_GarbageCollector_CollectIncremental(uint64_t nanoseconds)
{
	typedef bool (* ICallMethod) (uint64_t nanoseconds);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Scripting.GarbageCollector::CollectIncremental");
	bool i2res = icall(nanoseconds);
	return i2res;
}
bool UnityEngine_U2D_SpriteAtlas_CanBindTo(MonoObject* thiz, MonoObject* sprite)
{
	typedef bool (* ICallMethod) (Il2CppObject* thiz, Il2CppObject* sprite);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.U2D.SpriteAtlas::CanBindTo");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_U2D_SpriteAtlas());
	Il2CppObject* i2sprite = get_il2cpp_object(sprite,il2cpp_get_class_UnityEngine_Sprite());
	bool i2res = icall(i2thiz,i2sprite);
	return i2res;
}
bool UnityEngine_Rendering_GraphicsSettings_get_lightsUseLinearIntensity()
{
	typedef bool (* ICallMethod) ();
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Rendering.GraphicsSettings::get_lightsUseLinearIntensity");
	bool i2res = icall();
	return i2res;
}
void UnityEngine_Rendering_ScriptableRenderContext_GetCameras_Internal_Injected(void * _unity_self, MonoReflectionType* listType, MonoObject* resultList)
{
	typedef void (* ICallMethod) (void * _unity_self, Il2CppReflectionType* listType, Il2CppObject* resultList);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Rendering.ScriptableRenderContext::GetCameras_Internal_Injected");
	Il2CppReflectionType* i2listType = get_il2cpp_reflection_type(listType);
	Il2CppObject* i2resultList = get_il2cpp_object(resultList,NULL);
	icall(_unity_self,i2listType,i2resultList);
}
int32_t UnityEngine_Experimental_Rendering_GraphicsFormatUtility_GetGraphicsFormat_Native_TextureFormat(int32_t format, bool isSRGB)
{
	typedef int32_t (* ICallMethod) (int32_t format, bool isSRGB);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Experimental.Rendering.GraphicsFormatUtility::GetGraphicsFormat_Native_TextureFormat");
	int32_t i2res = icall(format,isSRGB);
	return i2res;
}
int32_t UnityEngine_Experimental_Rendering_GraphicsFormatUtility_GetGraphicsFormat_Native_RenderTextureFormat(int32_t format, bool isSRGB)
{
	typedef int32_t (* ICallMethod) (int32_t format, bool isSRGB);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Experimental.Rendering.GraphicsFormatUtility::GetGraphicsFormat_Native_RenderTextureFormat");
	int32_t i2res = icall(format,isSRGB);
	return i2res;
}
bool UnityEngine_Experimental_Rendering_GraphicsFormatUtility_IsSRGBFormat(int32_t format)
{
	typedef bool (* ICallMethod) (int32_t format);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Experimental.Rendering.GraphicsFormatUtility::IsSRGBFormat");
	bool i2res = icall(format);
	return i2res;
}
int32_t UnityEngine_Experimental_Rendering_GraphicsFormatUtility_GetRenderTextureFormat(int32_t format)
{
	typedef int32_t (* ICallMethod) (int32_t format);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Experimental.Rendering.GraphicsFormatUtility::GetRenderTextureFormat");
	int32_t i2res = icall(format);
	return i2res;
}
void Unity_Jobs_JobHandle_ScheduleBatchedJobs()
{
	typedef void (* ICallMethod) ();
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("Unity.Jobs.JobHandle::ScheduleBatchedJobs");
	icall();
}
void UnityEngine_Playables_PlayableDirector_set_time_2(MonoObject* thiz, double value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, double value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Playables.PlayableDirector::set_time");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Playables_PlayableDirector());
	icall(i2thiz,value);
}
void UnityEngine_Playables_PlayableDirector_Evaluate_1(MonoObject* thiz)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Playables.PlayableDirector::Evaluate");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Playables_PlayableDirector());
	icall(i2thiz);
}
void UnityEngine_Playables_PlayableDirector_Play_3(MonoObject* thiz)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Playables.PlayableDirector::Play");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Playables_PlayableDirector());
	icall(i2thiz);
}
void UnityEngine_Playables_PlayableDirector_Stop_1(MonoObject* thiz)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Playables.PlayableDirector::Stop");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Playables_PlayableDirector());
	icall(i2thiz);
}
void UnityEngine_Playables_PlayableDirector_Pause_1(MonoObject* thiz)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Playables.PlayableDirector::Pause");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Playables_PlayableDirector());
	icall(i2thiz);
}
void UnityEngine_Playables_PlayableDirector_Resume(MonoObject* thiz)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Playables.PlayableDirector::Resume");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Playables_PlayableDirector());
	icall(i2thiz);
}
MonoObject* UnityEngine_Playables_PlayableDirector_GetGenericBinding(MonoObject* thiz, MonoObject* key)
{
	typedef Il2CppObject* (* ICallMethod) (Il2CppObject* thiz, Il2CppObject* key);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Playables.PlayableDirector::GetGenericBinding");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Playables_PlayableDirector());
	Il2CppObject* i2key = get_il2cpp_object(key,il2cpp_get_class_UnityEngine_Object());
	Il2CppObject* i2res = icall(i2thiz,i2key);
	MonoObject* monoi2res = get_mono_object(i2res,get_mono_class(il2cpp_object_get_class(i2res)));
	if(i2res != NULL && monoi2res == NULL)
	{
		platform_log("UnityEngine.Playables.PlayableDirector::GetGenericBinding fail to convert il2cpp obj to mono");
	}
	return monoi2res;
}
MonoArray* UnityEngine_ImageConversion_EncodeToPNG(MonoObject* tex)
{
	typedef Il2CppArray* (* ICallMethod) (Il2CppObject* tex);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.ImageConversion::EncodeToPNG");
	Il2CppObject* i2tex = get_il2cpp_object(tex,il2cpp_get_class_UnityEngine_Texture2D());
	Il2CppArray* i2res = icall(i2tex);
	MonoArray* monoi2res = get_mono_array(i2res);
	if(i2res != NULL && monoi2res == NULL)
	{
		platform_log("UnityEngine.ImageConversion::EncodeToPNG fail to convert il2cpp obj to mono");
	}
	return monoi2res;
}
MonoArray* UnityEngine_ImageConversion_EncodeToJPG(MonoObject* tex, int32_t quality)
{
	typedef Il2CppArray* (* ICallMethod) (Il2CppObject* tex, int32_t quality);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.ImageConversion::EncodeToJPG");
	Il2CppObject* i2tex = get_il2cpp_object(tex,il2cpp_get_class_UnityEngine_Texture2D());
	Il2CppArray* i2res = icall(i2tex,quality);
	MonoArray* monoi2res = get_mono_array(i2res);
	if(i2res != NULL && monoi2res == NULL)
	{
		platform_log("UnityEngine.ImageConversion::EncodeToJPG fail to convert il2cpp obj to mono");
	}
	return monoi2res;
}
bool UnityEngine_ImageConversion_LoadImage(MonoObject* tex, MonoArray* data, bool markNonReadable)
{
	typedef bool (* ICallMethod) (Il2CppObject* tex, Il2CppArray* data, bool markNonReadable);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.ImageConversion::LoadImage");
	Il2CppObject* i2tex = get_il2cpp_object(tex,il2cpp_get_class_UnityEngine_Texture2D());
	Il2CppArray* i2data = get_il2cpp_array(data);
	bool i2res = icall(i2tex,i2data,markNonReadable);
	return i2res;
}
int32_t UnityEngine_Event_get_rawType(MonoObject* thiz)
{
	typedef int32_t (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Event::get_rawType");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Event());
	int32_t i2res = icall(i2thiz);
	return i2res;
}
int32_t UnityEngine_Event_get_pointerType(MonoObject* thiz)
{
	typedef int32_t (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Event::get_pointerType");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Event());
	int32_t i2res = icall(i2thiz);
	return i2res;
}
int32_t UnityEngine_Event_get_button(MonoObject* thiz)
{
	typedef int32_t (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Event::get_button");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Event());
	int32_t i2res = icall(i2thiz);
	return i2res;
}
int32_t UnityEngine_Event_get_modifiers(MonoObject* thiz)
{
	typedef int32_t (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Event::get_modifiers");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Event());
	int32_t i2res = icall(i2thiz);
	return i2res;
}
float UnityEngine_Event_get_pressure(MonoObject* thiz)
{
	typedef float (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Event::get_pressure");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Event());
	float i2res = icall(i2thiz);
	return i2res;
}
int32_t UnityEngine_Event_get_clickCount(MonoObject* thiz)
{
	typedef int32_t (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Event::get_clickCount");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Event());
	int32_t i2res = icall(i2thiz);
	return i2res;
}
char UnityEngine_Event_get_character(MonoObject* thiz)
{
	typedef char (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Event::get_character");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Event());
	char i2res = icall(i2thiz);
	return i2res;
}
int32_t UnityEngine_Event_get_keyCode(MonoObject* thiz)
{
	typedef int32_t (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Event::get_keyCode");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Event());
	int32_t i2res = icall(i2thiz);
	return i2res;
}
int32_t UnityEngine_Event_get_displayIndex(MonoObject* thiz)
{
	typedef int32_t (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Event::get_displayIndex");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Event());
	int32_t i2res = icall(i2thiz);
	return i2res;
}
void UnityEngine_Event_set_displayIndex(MonoObject* thiz, int32_t value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, int32_t value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Event::set_displayIndex");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Event());
	icall(i2thiz,value);
}
int32_t UnityEngine_Event_get_type_1(MonoObject* thiz)
{
	typedef int32_t (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Event::get_type");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Event());
	int32_t i2res = icall(i2thiz);
	return i2res;
}
void UnityEngine_Event_set_type(MonoObject* thiz, int32_t value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, int32_t value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Event::set_type");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Event());
	icall(i2thiz,value);
}
MonoString* UnityEngine_Event_get_commandName(MonoObject* thiz)
{
	typedef Il2CppString* (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Event::get_commandName");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Event());
	Il2CppString* i2res = icall(i2thiz);
	MonoString* monoi2res = get_mono_string(i2res);
	if(i2res != NULL && monoi2res == NULL)
	{
		platform_log("UnityEngine.Event::get_commandName fail to convert il2cpp obj to mono");
	}
	return monoi2res;
}
void UnityEngine_Event_set_commandName(MonoObject* thiz, MonoString* value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, Il2CppString* value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Event::set_commandName");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Event());
	Il2CppString* i2value = get_il2cpp_string(value);
	icall(i2thiz,i2value);
}
void UnityEngine_Event_CopyFromPtr(MonoObject* thiz, void * ptr)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, void * ptr);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Event::CopyFromPtr");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Event());
	icall(i2thiz,ptr);
}
bool UnityEngine_Event_PopEvent(MonoObject* outEvent)
{
	typedef bool (* ICallMethod) (Il2CppObject* outEvent);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Event::PopEvent");
	Il2CppObject* i2outEvent = get_il2cpp_object(outEvent,il2cpp_get_class_UnityEngine_Event());
	bool i2res = icall(i2outEvent);
	return i2res;
}
void UnityEngine_Event_get_mousePosition_Injected(MonoObject* thiz, void * ret)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, void * ret);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Event::get_mousePosition_Injected");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Event());
	icall(i2thiz,ret);
}
bool UnityEngine_GUI_get_changed()
{
	typedef bool (* ICallMethod) ();
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.GUI::get_changed");
	bool i2res = icall();
	return i2res;
}
void UnityEngine_GUI_set_changed(bool value)
{
	typedef void (* ICallMethod) (bool value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.GUI::set_changed");
	icall(value);
}
bool UnityEngine_GUI_get_enabled_2()
{
	typedef bool (* ICallMethod) ();
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.GUI::get_enabled");
	bool i2res = icall();
	return i2res;
}
void UnityEngine_GUI_set_enabled_2(bool value)
{
	typedef void (* ICallMethod) (bool value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.GUI::set_enabled");
	icall(value);
}
void UnityEngine_GUIStyle_set_alignment(MonoObject* thiz, int32_t value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, int32_t value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.GUIStyle::set_alignment");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_GUIStyle());
	icall(i2thiz,value);
}
float UnityEngine_GUIStyle_get_fixedWidth(MonoObject* thiz)
{
	typedef float (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.GUIStyle::get_fixedWidth");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_GUIStyle());
	float i2res = icall(i2thiz);
	return i2res;
}
float UnityEngine_GUIStyle_get_fixedHeight(MonoObject* thiz)
{
	typedef float (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.GUIStyle::get_fixedHeight");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_GUIStyle());
	float i2res = icall(i2thiz);
	return i2res;
}
bool UnityEngine_GUIStyle_get_stretchWidth(MonoObject* thiz)
{
	typedef bool (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.GUIStyle::get_stretchWidth");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_GUIStyle());
	bool i2res = icall(i2thiz);
	return i2res;
}
bool UnityEngine_GUIStyle_get_stretchHeight(MonoObject* thiz)
{
	typedef bool (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.GUIStyle::get_stretchHeight");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_GUIStyle());
	bool i2res = icall(i2thiz);
	return i2res;
}
void UnityEngine_GUIStyle_set_stretchHeight(MonoObject* thiz, bool value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, bool value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.GUIStyle::set_stretchHeight");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_GUIStyle());
	icall(i2thiz,value);
}
void UnityEngine_GUIStyle_Internal_Draw_Injected(MonoObject* thiz, void * screenRect, MonoObject* content, bool isHover, bool isActive, bool on, bool hasKeyboardFocus)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, void * screenRect, Il2CppObject* content, bool isHover, bool isActive, bool on, bool hasKeyboardFocus);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.GUIStyle::Internal_Draw_Injected");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_GUIStyle());
	Il2CppObject* i2content = get_il2cpp_object(content,il2cpp_get_class_UnityEngine_GUIContent());
	icall(i2thiz,screenRect,i2content,isHover,isActive,on,hasKeyboardFocus);
}
void UnityEngine_GUIStyle_Internal_Draw2_Injected(MonoObject* thiz, void * position, MonoObject* content, int32_t controlID, bool on)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, void * position, Il2CppObject* content, int32_t controlID, bool on);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.GUIStyle::Internal_Draw2_Injected");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_GUIStyle());
	Il2CppObject* i2content = get_il2cpp_object(content,il2cpp_get_class_UnityEngine_GUIContent());
	icall(i2thiz,position,i2content,controlID,on);
}
void UnityEngine_GUIStyle_Internal_CalcSize_Injected(MonoObject* thiz, MonoObject* content, void * ret)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, Il2CppObject* content, void * ret);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.GUIStyle::Internal_CalcSize_Injected");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_GUIStyle());
	Il2CppObject* i2content = get_il2cpp_object(content,il2cpp_get_class_UnityEngine_GUIContent());
	icall(i2thiz,i2content,ret);
}
MonoString* UnityEngine_GUIUtility_get_systemCopyBuffer()
{
	typedef Il2CppString* (* ICallMethod) ();
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.GUIUtility::get_systemCopyBuffer");
	Il2CppString* i2res = icall();
	MonoString* monoi2res = get_mono_string(i2res);
	if(i2res != NULL && monoi2res == NULL)
	{
		platform_log("UnityEngine.GUIUtility::get_systemCopyBuffer fail to convert il2cpp obj to mono");
	}
	return monoi2res;
}
void UnityEngine_GUIUtility_set_systemCopyBuffer(MonoString* value)
{
	typedef void (* ICallMethod) (Il2CppString* value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.GUIUtility::set_systemCopyBuffer");
	Il2CppString* i2value = get_il2cpp_string(value);
	icall(i2value);
}
bool UnityEngine_Input_get_anyKeyDown()
{
	typedef bool (* ICallMethod) ();
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Input::get_anyKeyDown");
	bool i2res = icall();
	return i2res;
}
MonoString* UnityEngine_Input_get_inputString()
{
	typedef Il2CppString* (* ICallMethod) ();
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Input::get_inputString");
	Il2CppString* i2res = icall();
	MonoString* monoi2res = get_mono_string(i2res);
	if(i2res != NULL && monoi2res == NULL)
	{
		platform_log("UnityEngine.Input::get_inputString fail to convert il2cpp obj to mono");
	}
	return monoi2res;
}
int32_t UnityEngine_Input_get_imeCompositionMode()
{
	typedef int32_t (* ICallMethod) ();
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Input::get_imeCompositionMode");
	int32_t i2res = icall();
	return i2res;
}
void UnityEngine_Input_set_imeCompositionMode(int32_t value)
{
	typedef void (* ICallMethod) (int32_t value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Input::set_imeCompositionMode");
	icall(value);
}
MonoString* UnityEngine_Input_get_compositionString()
{
	typedef Il2CppString* (* ICallMethod) ();
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Input::get_compositionString");
	Il2CppString* i2res = icall();
	MonoString* monoi2res = get_mono_string(i2res);
	if(i2res != NULL && monoi2res == NULL)
	{
		platform_log("UnityEngine.Input::get_compositionString fail to convert il2cpp obj to mono");
	}
	return monoi2res;
}
bool UnityEngine_Input_get_mousePresent()
{
	typedef bool (* ICallMethod) ();
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Input::get_mousePresent");
	bool i2res = icall();
	return i2res;
}
int32_t UnityEngine_Input_get_touchCount()
{
	typedef int32_t (* ICallMethod) ();
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Input::get_touchCount");
	int32_t i2res = icall();
	return i2res;
}
bool UnityEngine_Input_get_touchSupported()
{
	typedef bool (* ICallMethod) ();
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Input::get_touchSupported");
	bool i2res = icall();
	return i2res;
}
void UnityEngine_Input_set_multiTouchEnabled(bool value)
{
	typedef void (* ICallMethod) (bool value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Input::set_multiTouchEnabled");
	icall(value);
}
float UnityEngine_Input_GetAxis(MonoString* axisName)
{
	typedef float (* ICallMethod) (Il2CppString* axisName);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Input::GetAxis");
	Il2CppString* i2axisName = get_il2cpp_string(axisName);
	float i2res = icall(i2axisName);
	return i2res;
}
float UnityEngine_Input_GetAxisRaw(MonoString* axisName)
{
	typedef float (* ICallMethod) (Il2CppString* axisName);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Input::GetAxisRaw");
	Il2CppString* i2axisName = get_il2cpp_string(axisName);
	float i2res = icall(i2axisName);
	return i2res;
}
bool UnityEngine_Input_GetButtonDown(MonoString* buttonName)
{
	typedef bool (* ICallMethod) (Il2CppString* buttonName);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Input::GetButtonDown");
	Il2CppString* i2buttonName = get_il2cpp_string(buttonName);
	bool i2res = icall(i2buttonName);
	return i2res;
}
bool UnityEngine_Input_GetMouseButton(int32_t button)
{
	typedef bool (* ICallMethod) (int32_t button);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Input::GetMouseButton");
	bool i2res = icall(button);
	return i2res;
}
bool UnityEngine_Input_GetMouseButtonDown(int32_t button)
{
	typedef bool (* ICallMethod) (int32_t button);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Input::GetMouseButtonDown");
	bool i2res = icall(button);
	return i2res;
}
bool UnityEngine_Input_GetMouseButtonUp(int32_t button)
{
	typedef bool (* ICallMethod) (int32_t button);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Input::GetMouseButtonUp");
	bool i2res = icall(button);
	return i2res;
}
void UnityEngine_Input_GetTouch_Injected(int32_t index, void * ret)
{
	typedef void (* ICallMethod) (int32_t index, void * ret);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Input::GetTouch_Injected");
	icall(index,ret);
}
bool UnityEngine_Input_GetKeyInt(int32_t key)
{
	typedef bool (* ICallMethod) (int32_t key);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Input::GetKeyInt");
	bool i2res = icall(key);
	return i2res;
}
bool UnityEngine_Input_GetKeyUpInt(int32_t key)
{
	typedef bool (* ICallMethod) (int32_t key);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Input::GetKeyUpInt");
	bool i2res = icall(key);
	return i2res;
}
bool UnityEngine_Input_GetKeyDownInt(int32_t key)
{
	typedef bool (* ICallMethod) (int32_t key);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Input::GetKeyDownInt");
	bool i2res = icall(key);
	return i2res;
}
int32_t UnityEngine_ParticleSystem_get_particleCount(MonoObject* thiz)
{
	typedef int32_t (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.ParticleSystem::get_particleCount");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_ParticleSystem());
	int32_t i2res = icall(i2thiz);
	return i2res;
}
void UnityEngine_ParticleSystem_set_time_3(MonoObject* thiz, float value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, float value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.ParticleSystem::set_time");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_ParticleSystem());
	icall(i2thiz,value);
}
void UnityEngine_ParticleSystem_EmitOld_Internal(MonoObject* thiz, void * particle)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, void * particle);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.ParticleSystem::EmitOld_Internal");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_ParticleSystem());
	icall(i2thiz,particle);
}
void UnityEngine_ParticleSystem_SetParticles(MonoObject* thiz, void* particles, int32_t size, int32_t offset)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, void* particles, int32_t size, int32_t offset);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.ParticleSystem::SetParticles");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_ParticleSystem());
	icall(i2thiz,particles,size,offset);
}
int32_t UnityEngine_ParticleSystem_GetParticles(MonoObject* thiz, void* particles, int32_t size, int32_t offset)
{
	typedef int32_t (* ICallMethod) (Il2CppObject* thiz, void* particles, int32_t size, int32_t offset);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.ParticleSystem::GetParticles");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_ParticleSystem());
	int32_t i2res = icall(i2thiz,particles,size,offset);
	return i2res;
}
void UnityEngine_ParticleSystem_Simulate(MonoObject* thiz, float t, bool withChildren, bool restart, bool fixedTimeStep)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, float t, bool withChildren, bool restart, bool fixedTimeStep);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.ParticleSystem::Simulate");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_ParticleSystem());
	icall(i2thiz,t,withChildren,restart,fixedTimeStep);
}
void UnityEngine_ParticleSystem_Play_4(MonoObject* thiz, bool withChildren)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, bool withChildren);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.ParticleSystem::Play");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_ParticleSystem());
	icall(i2thiz,withChildren);
}
void UnityEngine_ParticleSystem_Clear(MonoObject* thiz, bool withChildren)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, bool withChildren);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.ParticleSystem::Clear");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_ParticleSystem());
	icall(i2thiz,withChildren);
}
void UnityEngine_ParticleSystem_Emit_Internal(MonoObject* thiz, int32_t count)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, int32_t count);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.ParticleSystem::Emit_Internal");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_ParticleSystem());
	icall(i2thiz,count);
}
void UnityEngine_ParticleSystem_Emit_Injected(MonoObject* thiz, void * emitParams, int32_t count)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, void * emitParams, int32_t count);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.ParticleSystem::Emit_Injected");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_ParticleSystem());
	icall(i2thiz,emitParams,count);
}
int32_t UnityEngine_ParticleSystemRenderer_get_renderMode(MonoObject* thiz)
{
	typedef int32_t (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.ParticleSystemRenderer::get_renderMode");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_ParticleSystemRenderer());
	int32_t i2res = icall(i2thiz);
	return i2res;
}
float UnityEngine_ParticleSystemRenderer_get_lengthScale(MonoObject* thiz)
{
	typedef float (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.ParticleSystemRenderer::get_lengthScale");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_ParticleSystemRenderer());
	float i2res = icall(i2thiz);
	return i2res;
}
void UnityEngine_ParticleSystemRenderer_set_lengthScale(MonoObject* thiz, float value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, float value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.ParticleSystemRenderer::set_lengthScale");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_ParticleSystemRenderer());
	icall(i2thiz,value);
}
float UnityEngine_ParticleSystemRenderer_get_velocityScale(MonoObject* thiz)
{
	typedef float (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.ParticleSystemRenderer::get_velocityScale");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_ParticleSystemRenderer());
	float i2res = icall(i2thiz);
	return i2res;
}
void UnityEngine_ParticleSystemRenderer_set_velocityScale(MonoObject* thiz, float value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, float value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.ParticleSystemRenderer::set_velocityScale");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_ParticleSystemRenderer());
	icall(i2thiz,value);
}
int32_t UnityEngine_ParticleSystemRenderer_GetMeshes(MonoObject* thiz, MonoArray* meshes)
{
	typedef int32_t (* ICallMethod) (Il2CppObject* thiz, Il2CppArray* meshes);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.ParticleSystemRenderer::GetMeshes");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_ParticleSystemRenderer());
	Il2CppArray* i2meshes = get_il2cpp_array(meshes);
	int32_t i2res = icall(i2thiz,i2meshes);
	return i2res;
}
void UnityEngine_PhysicsScene2D_Raycast_Internal_Injected(void * physicsScene, void * origin, void * direction, float distance, void * contactFilter, void * ret)
{
	typedef void (* ICallMethod) (void * physicsScene, void * origin, void * direction, float distance, void * contactFilter, void * ret);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.PhysicsScene2D::Raycast_Internal_Injected");
	icall(physicsScene,origin,direction,distance,contactFilter,ret);
}
int32_t UnityEngine_PhysicsScene2D_RaycastArray_Internal_Injected(void * physicsScene, void * origin, void * direction, float distance, void * contactFilter, void* results)
{
	typedef int32_t (* ICallMethod) (void * physicsScene, void * origin, void * direction, float distance, void * contactFilter, void* results);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.PhysicsScene2D::RaycastArray_Internal_Injected");
	int32_t i2res = icall(physicsScene,origin,direction,distance,contactFilter,results);
	return i2res;
}
int32_t UnityEngine_PhysicsScene2D_RaycastList_Internal_Injected(void * physicsScene, void * origin, void * direction, float distance, void * contactFilter, MonoObject* results)
{
	typedef int32_t (* ICallMethod) (void * physicsScene, void * origin, void * direction, float distance, void * contactFilter, Il2CppObject* results);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.PhysicsScene2D::RaycastList_Internal_Injected");
	Il2CppObject* i2results = get_il2cpp_object(results,NULL);
	int32_t i2res = icall(physicsScene,origin,direction,distance,contactFilter,i2results);
	return i2res;
}
void UnityEngine_PhysicsScene2D_CircleCast_Internal_Injected(void * physicsScene, void * origin, float radius, void * direction, float distance, void * contactFilter, void * ret)
{
	typedef void (* ICallMethod) (void * physicsScene, void * origin, float radius, void * direction, float distance, void * contactFilter, void * ret);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.PhysicsScene2D::CircleCast_Internal_Injected");
	icall(physicsScene,origin,radius,direction,distance,contactFilter,ret);
}
int32_t UnityEngine_PhysicsScene2D_GetRayIntersectionArray_Internal_Injected(void * physicsScene, void * origin, void * direction, float distance, int32_t layerMask, void* results)
{
	typedef int32_t (* ICallMethod) (void * physicsScene, void * origin, void * direction, float distance, int32_t layerMask, void* results);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.PhysicsScene2D::GetRayIntersectionArray_Internal_Injected");
	int32_t i2res = icall(physicsScene,origin,direction,distance,layerMask,results);
	return i2res;
}
MonoObject* UnityEngine_PhysicsScene2D_OverlapPoint_Internal_Injected(void * physicsScene, void * point, void * contactFilter)
{
	typedef Il2CppObject* (* ICallMethod) (void * physicsScene, void * point, void * contactFilter);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.PhysicsScene2D::OverlapPoint_Internal_Injected");
	Il2CppObject* i2res = icall(physicsScene,point,contactFilter);
	MonoObject* monoi2res = get_mono_object(i2res,mono_get_class_UnityEngine_Collider2D());
	if(i2res != NULL && monoi2res == NULL)
	{
		platform_log("UnityEngine.PhysicsScene2D::OverlapPoint_Internal_Injected fail to convert il2cpp obj to mono");
	}
	return monoi2res;
}
bool UnityEngine_Physics2D_get_queriesHitTriggers()
{
	typedef bool (* ICallMethod) ();
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Physics2D::get_queriesHitTriggers");
	bool i2res = icall();
	return i2res;
}
void UnityEngine_Physics2D_IgnoreCollision(MonoObject* collider1, MonoObject* collider2, bool ignore)
{
	typedef void (* ICallMethod) (Il2CppObject* collider1, Il2CppObject* collider2, bool ignore);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Physics2D::IgnoreCollision");
	Il2CppObject* i2collider1 = get_il2cpp_object(collider1,il2cpp_get_class_UnityEngine_Collider2D());
	Il2CppObject* i2collider2 = get_il2cpp_object(collider2,il2cpp_get_class_UnityEngine_Collider2D());
	icall(i2collider1,i2collider2,ignore);
}
void UnityEngine_Collider2D_set_isTrigger(MonoObject* thiz, bool value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, bool value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Collider2D::set_isTrigger");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Collider2D());
	icall(i2thiz,value);
}
bool UnityEngine_Collider2D_OverlapPoint_Injected(MonoObject* thiz, void * point)
{
	typedef bool (* ICallMethod) (Il2CppObject* thiz, void * point);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Collider2D::OverlapPoint_Injected");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Collider2D());
	bool i2res = icall(i2thiz,point);
	return i2res;
}
void UnityEngine_ContactFilter2D_CheckConsistency_Injected(void * _unity_self)
{
	typedef void (* ICallMethod) (void * _unity_self);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.ContactFilter2D::CheckConsistency_Injected");
	icall(_unity_self);
}
float UnityEngine_Rigidbody2D_get_mass(MonoObject* thiz)
{
	typedef float (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Rigidbody2D::get_mass");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Rigidbody2D());
	float i2res = icall(i2thiz);
	return i2res;
}
void UnityEngine_Rigidbody2D_set_mass(MonoObject* thiz, float value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, float value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Rigidbody2D::set_mass");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Rigidbody2D());
	icall(i2thiz,value);
}
void UnityEngine_Rigidbody2D_set_gravityScale(MonoObject* thiz, float value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, float value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Rigidbody2D::set_gravityScale");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Rigidbody2D());
	icall(i2thiz,value);
}
void UnityEngine_Rigidbody2D_set_bodyType(MonoObject* thiz, int32_t value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, int32_t value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Rigidbody2D::set_bodyType");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Rigidbody2D());
	icall(i2thiz,value);
}
void UnityEngine_Rigidbody2D_MovePosition_Injected(MonoObject* thiz, void * position)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, void * position);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Rigidbody2D::MovePosition_Injected");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Rigidbody2D());
	icall(i2thiz,position);
}
void UnityEngine_Rigidbody2D_MoveRotation_Angle(MonoObject* thiz, float angle)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, float angle);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Rigidbody2D::MoveRotation_Angle");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Rigidbody2D());
	icall(i2thiz,angle);
}
void UnityEngine_CircleCollider2D_set_radius_1(MonoObject* thiz, float value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, float value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.CircleCollider2D::set_radius");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_CircleCollider2D());
	icall(i2thiz,value);
}
int32_t UnityEngine_PolygonCollider2D_get_pathCount(MonoObject* thiz)
{
	typedef int32_t (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.PolygonCollider2D::get_pathCount");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_PolygonCollider2D());
	int32_t i2res = icall(i2thiz);
	return i2res;
}
int32_t UnityEngine_CompositeCollider2D_get_pathCount_1(MonoObject* thiz)
{
	typedef int32_t (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.CompositeCollider2D::get_pathCount");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_CompositeCollider2D());
	int32_t i2res = icall(i2thiz);
	return i2res;
}
int32_t UnityEngine_CompositeCollider2D_get_pointCount(MonoObject* thiz)
{
	typedef int32_t (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.CompositeCollider2D::get_pointCount");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_CompositeCollider2D());
	int32_t i2res = icall(i2thiz);
	return i2res;
}
MonoObject* UnityEngine_Joint2D_get_connectedBody(MonoObject* thiz)
{
	typedef Il2CppObject* (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Joint2D::get_connectedBody");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Joint2D());
	Il2CppObject* i2res = icall(i2thiz);
	MonoObject* monoi2res = get_mono_object(i2res,mono_get_class_UnityEngine_Rigidbody2D());
	if(i2res != NULL && monoi2res == NULL)
	{
		platform_log("UnityEngine.Joint2D::get_connectedBody fail to convert il2cpp obj to mono");
	}
	return monoi2res;
}
void UnityEngine_Joint2D_set_connectedBody(MonoObject* thiz, MonoObject* value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, Il2CppObject* value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Joint2D::set_connectedBody");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Joint2D());
	Il2CppObject* i2value = get_il2cpp_object(value,il2cpp_get_class_UnityEngine_Rigidbody2D());
	icall(i2thiz,i2value);
}
void UnityEngine_HingeJoint2D_set_useLimits(MonoObject* thiz, bool value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, bool value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.HingeJoint2D::set_useLimits");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_HingeJoint2D());
	icall(i2thiz,value);
}
float UnityEngine_Rigidbody_get_mass_1(MonoObject* thiz)
{
	typedef float (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Rigidbody::get_mass");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Rigidbody());
	float i2res = icall(i2thiz);
	return i2res;
}
void UnityEngine_Rigidbody_set_mass_1(MonoObject* thiz, float value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, float value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Rigidbody::set_mass");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Rigidbody());
	icall(i2thiz,value);
}
void UnityEngine_Rigidbody_set_useGravity(MonoObject* thiz, bool value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, bool value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Rigidbody::set_useGravity");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Rigidbody());
	icall(i2thiz,value);
}
void UnityEngine_Rigidbody_set_isKinematic(MonoObject* thiz, bool value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, bool value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Rigidbody::set_isKinematic");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Rigidbody());
	icall(i2thiz,value);
}
void UnityEngine_Rigidbody_set_constraints(MonoObject* thiz, int32_t value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, int32_t value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Rigidbody::set_constraints");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Rigidbody());
	icall(i2thiz,value);
}
void UnityEngine_Rigidbody_MovePosition_Injected_1(MonoObject* thiz, void * position)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, void * position);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Rigidbody::MovePosition_Injected");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Rigidbody());
	icall(i2thiz,position);
}
void UnityEngine_Rigidbody_MoveRotation_Injected(MonoObject* thiz, void * rot)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, void * rot);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Rigidbody::MoveRotation_Injected");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Rigidbody());
	icall(i2thiz,rot);
}
bool UnityEngine_Collider_get_enabled_3(MonoObject* thiz)
{
	typedef bool (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Collider::get_enabled");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Collider());
	bool i2res = icall(i2thiz);
	return i2res;
}
void UnityEngine_Collider_set_enabled_3(MonoObject* thiz, bool value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, bool value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Collider::set_enabled");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Collider());
	icall(i2thiz,value);
}
void UnityEngine_Collider_set_isTrigger_1(MonoObject* thiz, bool value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, bool value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Collider::set_isTrigger");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Collider());
	icall(i2thiz,value);
}
void UnityEngine_Collider_ClosestPoint_Injected(MonoObject* thiz, void * position, void * ret)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, void * position, void * ret);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Collider::ClosestPoint_Injected");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Collider());
	icall(i2thiz,position,ret);
}
void UnityEngine_Collider_Raycast_Injected(MonoObject* thiz, void * ray, float maxDistance, void * hasHit, void * ret)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, void * ray, float maxDistance, void * hasHit, void * ret);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Collider::Raycast_Injected");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Collider());
	icall(i2thiz,ray,maxDistance,hasHit,ret);
}
void UnityEngine_SphereCollider_set_radius_2(MonoObject* thiz, float value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, float value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.SphereCollider::set_radius");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_SphereCollider());
	icall(i2thiz,value);
}
MonoObject* UnityEngine_Joint_get_connectedBody_1(MonoObject* thiz)
{
	typedef Il2CppObject* (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Joint::get_connectedBody");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Joint());
	Il2CppObject* i2res = icall(i2thiz);
	MonoObject* monoi2res = get_mono_object(i2res,mono_get_class_UnityEngine_Rigidbody());
	if(i2res != NULL && monoi2res == NULL)
	{
		platform_log("UnityEngine.Joint::get_connectedBody fail to convert il2cpp obj to mono");
	}
	return monoi2res;
}
void UnityEngine_Joint_set_connectedBody_1(MonoObject* thiz, MonoObject* value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, Il2CppObject* value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Joint::set_connectedBody");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Joint());
	Il2CppObject* i2value = get_il2cpp_object(value,il2cpp_get_class_UnityEngine_Rigidbody());
	icall(i2thiz,i2value);
}
void UnityEngine_Joint_set_enableCollision(MonoObject* thiz, bool value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, bool value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Joint::set_enableCollision");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Joint());
	icall(i2thiz,value);
}
void UnityEngine_HingeJoint_set_useLimits_1(MonoObject* thiz, bool value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, bool value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.HingeJoint::set_useLimits");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_HingeJoint());
	icall(i2thiz,value);
}
bool UnityEngine_PhysicsScene_Internal_RaycastTest_Injected(void * physicsScene, void * ray, float maxDistance, int32_t layerMask, int32_t queryTriggerInteraction)
{
	typedef bool (* ICallMethod) (void * physicsScene, void * ray, float maxDistance, int32_t layerMask, int32_t queryTriggerInteraction);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.PhysicsScene::Internal_RaycastTest_Injected");
	bool i2res = icall(physicsScene,ray,maxDistance,layerMask,queryTriggerInteraction);
	return i2res;
}
bool UnityEngine_PhysicsScene_Internal_Raycast_Injected(void * physicsScene, void * ray, float maxDistance, void * hit, int32_t layerMask, int32_t queryTriggerInteraction)
{
	typedef bool (* ICallMethod) (void * physicsScene, void * ray, float maxDistance, void * hit, int32_t layerMask, int32_t queryTriggerInteraction);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.PhysicsScene::Internal_Raycast_Injected");
	bool i2res = icall(physicsScene,ray,maxDistance,hit,layerMask,queryTriggerInteraction);
	return i2res;
}
int32_t UnityEngine_PhysicsScene_Internal_RaycastNonAlloc_Injected(void * physicsScene, void * ray, void* raycastHits, float maxDistance, int32_t mask, int32_t queryTriggerInteraction)
{
	typedef int32_t (* ICallMethod) (void * physicsScene, void * ray, void* raycastHits, float maxDistance, int32_t mask, int32_t queryTriggerInteraction);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.PhysicsScene::Internal_RaycastNonAlloc_Injected");
	int32_t i2res = icall(physicsScene,ray,raycastHits,maxDistance,mask,queryTriggerInteraction);
	return i2res;
}
bool UnityEngine_PhysicsScene_Query_SphereCast_Injected(void * physicsScene, void * origin, float radius, void * direction, float maxDistance, void * hitInfo, int32_t layerMask, int32_t queryTriggerInteraction)
{
	typedef bool (* ICallMethod) (void * physicsScene, void * origin, float radius, void * direction, float maxDistance, void * hitInfo, int32_t layerMask, int32_t queryTriggerInteraction);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.PhysicsScene::Query_SphereCast_Injected");
	bool i2res = icall(physicsScene,origin,radius,direction,maxDistance,hitInfo,layerMask,queryTriggerInteraction);
	return i2res;
}
int32_t UnityEngine_PhysicsScene_Internal_SphereCastNonAlloc_Injected(void * physicsScene, void * origin, float radius, void * direction, void* raycastHits, float maxDistance, int32_t mask, int32_t queryTriggerInteraction)
{
	typedef int32_t (* ICallMethod) (void * physicsScene, void * origin, float radius, void * direction, void* raycastHits, float maxDistance, int32_t mask, int32_t queryTriggerInteraction);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.PhysicsScene::Internal_SphereCastNonAlloc_Injected");
	int32_t i2res = icall(physicsScene,origin,radius,direction,raycastHits,maxDistance,mask,queryTriggerInteraction);
	return i2res;
}
int32_t UnityEngine_PhysicsScene_OverlapSphereNonAlloc_Internal_Injected(void * physicsScene, void * position, float radius, MonoArray* results, int32_t layerMask, int32_t queryTriggerInteraction)
{
	typedef int32_t (* ICallMethod) (void * physicsScene, void * position, float radius, Il2CppArray* results, int32_t layerMask, int32_t queryTriggerInteraction);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.PhysicsScene::OverlapSphereNonAlloc_Internal_Injected");
	Il2CppArray* i2results = get_il2cpp_array(results);
	int32_t i2res = icall(physicsScene,position,radius,i2results,layerMask,queryTriggerInteraction);
	return i2res;
}
void UnityEngine_Physics_IgnoreCollision_1(MonoObject* collider1, MonoObject* collider2, bool ignore)
{
	typedef void (* ICallMethod) (Il2CppObject* collider1, Il2CppObject* collider2, bool ignore);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Physics::IgnoreCollision");
	Il2CppObject* i2collider1 = get_il2cpp_object(collider1,il2cpp_get_class_UnityEngine_Collider());
	Il2CppObject* i2collider2 = get_il2cpp_object(collider2,il2cpp_get_class_UnityEngine_Collider());
	icall(i2collider1,i2collider2,ignore);
}
void UnityEngine_Physics_get_defaultPhysicsScene_Injected(void * ret)
{
	typedef void (* ICallMethod) (void * ret);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Physics::get_defaultPhysicsScene_Injected");
	icall(ret);
}
int32_t UnityEngine_TextGenerator_get_characterCount(MonoObject* thiz)
{
	typedef int32_t (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.TextGenerator::get_characterCount");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_TextGenerator());
	int32_t i2res = icall(i2thiz);
	return i2res;
}
int32_t UnityEngine_TextGenerator_get_lineCount(MonoObject* thiz)
{
	typedef int32_t (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.TextGenerator::get_lineCount");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_TextGenerator());
	int32_t i2res = icall(i2thiz);
	return i2res;
}
void UnityEngine_TextGenerator_GetCharactersInternal(MonoObject* thiz, MonoObject* characters)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, Il2CppObject* characters);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.TextGenerator::GetCharactersInternal");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_TextGenerator());
	Il2CppObject* i2characters = get_il2cpp_object(characters,NULL);
	icall(i2thiz,i2characters);
}
void UnityEngine_TextGenerator_GetLinesInternal(MonoObject* thiz, MonoObject* lines)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, Il2CppObject* lines);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.TextGenerator::GetLinesInternal");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_TextGenerator());
	Il2CppObject* i2lines = get_il2cpp_object(lines,NULL);
	icall(i2thiz,i2lines);
}
void UnityEngine_TextGenerator_GetVerticesInternal(MonoObject* thiz, MonoObject* vertices)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, Il2CppObject* vertices);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.TextGenerator::GetVerticesInternal");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_TextGenerator());
	Il2CppObject* i2vertices = get_il2cpp_object(vertices,NULL);
	icall(i2thiz,i2vertices);
}
MonoObject* UnityEngine_Font_get_material_1(MonoObject* thiz)
{
	typedef Il2CppObject* (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Font::get_material");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Font());
	Il2CppObject* i2res = icall(i2thiz);
	MonoObject* monoi2res = get_mono_object(i2res,mono_get_class_UnityEngine_Material());
	if(i2res != NULL && monoi2res == NULL)
	{
		platform_log("UnityEngine.Font::get_material fail to convert il2cpp obj to mono");
	}
	return monoi2res;
}
MonoArray* UnityEngine_Font_get_fontNames(MonoObject* thiz)
{
	typedef Il2CppArray* (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Font::get_fontNames");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Font());
	Il2CppArray* i2res = icall(i2thiz);
	MonoArray* monoi2res = get_mono_array(i2res);
	if(i2res != NULL && monoi2res == NULL)
	{
		platform_log("UnityEngine.Font::get_fontNames fail to convert il2cpp obj to mono");
	}
	return monoi2res;
}
bool UnityEngine_Font_get_dynamic(MonoObject* thiz)
{
	typedef bool (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Font::get_dynamic");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Font());
	bool i2res = icall(i2thiz);
	return i2res;
}
int32_t UnityEngine_Font_get_fontSize(MonoObject* thiz)
{
	typedef int32_t (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Font::get_fontSize");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Font());
	int32_t i2res = icall(i2thiz);
	return i2res;
}
bool UnityEngine_Font_HasCharacter(MonoObject* thiz, int32_t c)
{
	typedef bool (* ICallMethod) (Il2CppObject* thiz, int32_t c);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Font::HasCharacter");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Font());
	bool i2res = icall(i2thiz,c);
	return i2res;
}
bool UnityEngine_Font_GetCharacterInfo(MonoObject* thiz, char ch, void * info, int32_t size, int32_t style)
{
	typedef bool (* ICallMethod) (Il2CppObject* thiz, char ch, void * info, int32_t size, int32_t style);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Font::GetCharacterInfo");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Font());
	bool i2res = icall(i2thiz,ch,info,size,style);
	return i2res;
}
void UnityEngine_Font_RequestCharactersInTexture(MonoObject* thiz, MonoString* characters, int32_t size, int32_t style)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, Il2CppString* characters, int32_t size, int32_t style);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Font::RequestCharactersInTexture");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Font());
	Il2CppString* i2characters = get_il2cpp_string(characters);
	icall(i2thiz,i2characters,size,style);
}
void UnityEngine_Tilemaps_Tilemap_RefreshTile_Injected(MonoObject* thiz, void * position)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, void * position);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Tilemaps.Tilemap::RefreshTile_Injected");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Tilemaps_Tilemap());
	icall(i2thiz,position);
}
float UnityEngine_CanvasGroup_get_alpha(MonoObject* thiz)
{
	typedef float (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.CanvasGroup::get_alpha");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_CanvasGroup());
	float i2res = icall(i2thiz);
	return i2res;
}
void UnityEngine_CanvasGroup_set_alpha(MonoObject* thiz, float value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, float value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.CanvasGroup::set_alpha");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_CanvasGroup());
	icall(i2thiz,value);
}
bool UnityEngine_CanvasGroup_get_interactable(MonoObject* thiz)
{
	typedef bool (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.CanvasGroup::get_interactable");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_CanvasGroup());
	bool i2res = icall(i2thiz);
	return i2res;
}
bool UnityEngine_CanvasGroup_get_blocksRaycasts(MonoObject* thiz)
{
	typedef bool (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.CanvasGroup::get_blocksRaycasts");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_CanvasGroup());
	bool i2res = icall(i2thiz);
	return i2res;
}
bool UnityEngine_CanvasGroup_get_ignoreParentGroups(MonoObject* thiz)
{
	typedef bool (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.CanvasGroup::get_ignoreParentGroups");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_CanvasGroup());
	bool i2res = icall(i2thiz);
	return i2res;
}
void UnityEngine_CanvasRenderer_set_hasPopInstruction(MonoObject* thiz, bool value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, bool value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.CanvasRenderer::set_hasPopInstruction");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_CanvasRenderer());
	icall(i2thiz,value);
}
int32_t UnityEngine_CanvasRenderer_get_materialCount(MonoObject* thiz)
{
	typedef int32_t (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.CanvasRenderer::get_materialCount");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_CanvasRenderer());
	int32_t i2res = icall(i2thiz);
	return i2res;
}
void UnityEngine_CanvasRenderer_set_materialCount(MonoObject* thiz, int32_t value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, int32_t value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.CanvasRenderer::set_materialCount");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_CanvasRenderer());
	icall(i2thiz,value);
}
void UnityEngine_CanvasRenderer_set_popMaterialCount(MonoObject* thiz, int32_t value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, int32_t value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.CanvasRenderer::set_popMaterialCount");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_CanvasRenderer());
	icall(i2thiz,value);
}
int32_t UnityEngine_CanvasRenderer_get_absoluteDepth(MonoObject* thiz)
{
	typedef int32_t (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.CanvasRenderer::get_absoluteDepth");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_CanvasRenderer());
	int32_t i2res = icall(i2thiz);
	return i2res;
}
bool UnityEngine_CanvasRenderer_get_hasMoved(MonoObject* thiz)
{
	typedef bool (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.CanvasRenderer::get_hasMoved");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_CanvasRenderer());
	bool i2res = icall(i2thiz);
	return i2res;
}
bool UnityEngine_CanvasRenderer_get_cull(MonoObject* thiz)
{
	typedef bool (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.CanvasRenderer::get_cull");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_CanvasRenderer());
	bool i2res = icall(i2thiz);
	return i2res;
}
void UnityEngine_CanvasRenderer_set_cull(MonoObject* thiz, bool value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, bool value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.CanvasRenderer::set_cull");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_CanvasRenderer());
	icall(i2thiz,value);
}
void UnityEngine_CanvasRenderer_SetColor_Injected(MonoObject* thiz, void * color)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, void * color);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.CanvasRenderer::SetColor_Injected");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_CanvasRenderer());
	icall(i2thiz,color);
}
void UnityEngine_CanvasRenderer_GetColor_Injected(MonoObject* thiz, void * ret)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, void * ret);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.CanvasRenderer::GetColor_Injected");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_CanvasRenderer());
	icall(i2thiz,ret);
}
void UnityEngine_CanvasRenderer_EnableRectClipping_Injected(MonoObject* thiz, void * rect)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, void * rect);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.CanvasRenderer::EnableRectClipping_Injected");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_CanvasRenderer());
	icall(i2thiz,rect);
}
void UnityEngine_CanvasRenderer_DisableRectClipping(MonoObject* thiz)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.CanvasRenderer::DisableRectClipping");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_CanvasRenderer());
	icall(i2thiz);
}
void UnityEngine_CanvasRenderer_SetMaterial(MonoObject* thiz, MonoObject* material, int32_t index)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, Il2CppObject* material, int32_t index);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.CanvasRenderer::SetMaterial");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_CanvasRenderer());
	Il2CppObject* i2material = get_il2cpp_object(material,il2cpp_get_class_UnityEngine_Material());
	icall(i2thiz,i2material,index);
}
void UnityEngine_CanvasRenderer_SetPopMaterial(MonoObject* thiz, MonoObject* material, int32_t index)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, Il2CppObject* material, int32_t index);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.CanvasRenderer::SetPopMaterial");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_CanvasRenderer());
	Il2CppObject* i2material = get_il2cpp_object(material,il2cpp_get_class_UnityEngine_Material());
	icall(i2thiz,i2material,index);
}
void UnityEngine_CanvasRenderer_SetTexture(MonoObject* thiz, MonoObject* texture)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, Il2CppObject* texture);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.CanvasRenderer::SetTexture");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_CanvasRenderer());
	Il2CppObject* i2texture = get_il2cpp_object(texture,il2cpp_get_class_UnityEngine_Texture());
	icall(i2thiz,i2texture);
}
void UnityEngine_CanvasRenderer_SetAlphaTexture(MonoObject* thiz, MonoObject* texture)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, Il2CppObject* texture);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.CanvasRenderer::SetAlphaTexture");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_CanvasRenderer());
	Il2CppObject* i2texture = get_il2cpp_object(texture,il2cpp_get_class_UnityEngine_Texture());
	icall(i2thiz,i2texture);
}
void UnityEngine_CanvasRenderer_SetMesh(MonoObject* thiz, MonoObject* mesh)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, Il2CppObject* mesh);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.CanvasRenderer::SetMesh");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_CanvasRenderer());
	Il2CppObject* i2mesh = get_il2cpp_object(mesh,il2cpp_get_class_UnityEngine_Mesh());
	icall(i2thiz,i2mesh);
}
void UnityEngine_CanvasRenderer_Clear_1(MonoObject* thiz)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.CanvasRenderer::Clear");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_CanvasRenderer());
	icall(i2thiz);
}
void UnityEngine_CanvasRenderer_SplitUIVertexStreamsInternal(MonoObject* verts, MonoObject* positions, MonoObject* colors, MonoObject* uv0S, MonoObject* uv1S, MonoObject* uv2S, MonoObject* uv3S, MonoObject* normals, MonoObject* tangents)
{
	typedef void (* ICallMethod) (Il2CppObject* verts, Il2CppObject* positions, Il2CppObject* colors, Il2CppObject* uv0S, Il2CppObject* uv1S, Il2CppObject* uv2S, Il2CppObject* uv3S, Il2CppObject* normals, Il2CppObject* tangents);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.CanvasRenderer::SplitUIVertexStreamsInternal");
	Il2CppObject* i2verts = get_il2cpp_object(verts,NULL);
	Il2CppObject* i2positions = get_il2cpp_object(positions,NULL);
	Il2CppObject* i2colors = get_il2cpp_object(colors,NULL);
	Il2CppObject* i2uv0S = get_il2cpp_object(uv0S,NULL);
	Il2CppObject* i2uv1S = get_il2cpp_object(uv1S,NULL);
	Il2CppObject* i2uv2S = get_il2cpp_object(uv2S,NULL);
	Il2CppObject* i2uv3S = get_il2cpp_object(uv3S,NULL);
	Il2CppObject* i2normals = get_il2cpp_object(normals,NULL);
	Il2CppObject* i2tangents = get_il2cpp_object(tangents,NULL);
	icall(i2verts,i2positions,i2colors,i2uv0S,i2uv1S,i2uv2S,i2uv3S,i2normals,i2tangents);
}
void UnityEngine_CanvasRenderer_SplitIndicesStreamsInternal(MonoObject* verts, MonoObject* indices)
{
	typedef void (* ICallMethod) (Il2CppObject* verts, Il2CppObject* indices);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.CanvasRenderer::SplitIndicesStreamsInternal");
	Il2CppObject* i2verts = get_il2cpp_object(verts,NULL);
	Il2CppObject* i2indices = get_il2cpp_object(indices,NULL);
	icall(i2verts,i2indices);
}
void UnityEngine_CanvasRenderer_CreateUIVertexStreamInternal(MonoObject* verts, MonoObject* positions, MonoObject* colors, MonoObject* uv0S, MonoObject* uv1S, MonoObject* uv2S, MonoObject* uv3S, MonoObject* normals, MonoObject* tangents, MonoObject* indices)
{
	typedef void (* ICallMethod) (Il2CppObject* verts, Il2CppObject* positions, Il2CppObject* colors, Il2CppObject* uv0S, Il2CppObject* uv1S, Il2CppObject* uv2S, Il2CppObject* uv3S, Il2CppObject* normals, Il2CppObject* tangents, Il2CppObject* indices);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.CanvasRenderer::CreateUIVertexStreamInternal");
	Il2CppObject* i2verts = get_il2cpp_object(verts,NULL);
	Il2CppObject* i2positions = get_il2cpp_object(positions,NULL);
	Il2CppObject* i2colors = get_il2cpp_object(colors,NULL);
	Il2CppObject* i2uv0S = get_il2cpp_object(uv0S,NULL);
	Il2CppObject* i2uv1S = get_il2cpp_object(uv1S,NULL);
	Il2CppObject* i2uv2S = get_il2cpp_object(uv2S,NULL);
	Il2CppObject* i2uv3S = get_il2cpp_object(uv3S,NULL);
	Il2CppObject* i2normals = get_il2cpp_object(normals,NULL);
	Il2CppObject* i2tangents = get_il2cpp_object(tangents,NULL);
	Il2CppObject* i2indices = get_il2cpp_object(indices,NULL);
	icall(i2verts,i2positions,i2colors,i2uv0S,i2uv1S,i2uv2S,i2uv3S,i2normals,i2tangents,i2indices);
}
void UnityEngine_RectTransformUtility_PixelAdjustPoint_Injected(void * point, MonoObject* elementTransform, MonoObject* canvas, void * ret)
{
	typedef void (* ICallMethod) (void * point, Il2CppObject* elementTransform, Il2CppObject* canvas, void * ret);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.RectTransformUtility::PixelAdjustPoint_Injected");
	Il2CppObject* i2elementTransform = get_il2cpp_object(elementTransform,il2cpp_get_class_UnityEngine_Transform());
	Il2CppObject* i2canvas = get_il2cpp_object(canvas,il2cpp_get_class_UnityEngine_Canvas());
	icall(point,i2elementTransform,i2canvas,ret);
}
void UnityEngine_RectTransformUtility_PixelAdjustRect_Injected(MonoObject* rectTransform, MonoObject* canvas, void * ret)
{
	typedef void (* ICallMethod) (Il2CppObject* rectTransform, Il2CppObject* canvas, void * ret);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.RectTransformUtility::PixelAdjustRect_Injected");
	Il2CppObject* i2rectTransform = get_il2cpp_object(rectTransform,il2cpp_get_class_UnityEngine_RectTransform());
	Il2CppObject* i2canvas = get_il2cpp_object(canvas,il2cpp_get_class_UnityEngine_Canvas());
	icall(i2rectTransform,i2canvas,ret);
}
bool UnityEngine_RectTransformUtility_PointInRectangle_Injected(void * screenPoint, MonoObject* rect, MonoObject* cam, void * offset)
{
	typedef bool (* ICallMethod) (void * screenPoint, Il2CppObject* rect, Il2CppObject* cam, void * offset);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.RectTransformUtility::PointInRectangle_Injected");
	Il2CppObject* i2rect = get_il2cpp_object(rect,il2cpp_get_class_UnityEngine_RectTransform());
	Il2CppObject* i2cam = get_il2cpp_object(cam,il2cpp_get_class_UnityEngine_Camera());
	bool i2res = icall(screenPoint,i2rect,i2cam,offset);
	return i2res;
}
int32_t UnityEngine_Canvas_get_renderMode_1(MonoObject* thiz)
{
	typedef int32_t (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Canvas::get_renderMode");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Canvas());
	int32_t i2res = icall(i2thiz);
	return i2res;
}
bool UnityEngine_Canvas_get_isRootCanvas(MonoObject* thiz)
{
	typedef bool (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Canvas::get_isRootCanvas");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Canvas());
	bool i2res = icall(i2thiz);
	return i2res;
}
float UnityEngine_Canvas_get_scaleFactor(MonoObject* thiz)
{
	typedef float (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Canvas::get_scaleFactor");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Canvas());
	float i2res = icall(i2thiz);
	return i2res;
}
void UnityEngine_Canvas_set_scaleFactor(MonoObject* thiz, float value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, float value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Canvas::set_scaleFactor");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Canvas());
	icall(i2thiz,value);
}
float UnityEngine_Canvas_get_referencePixelsPerUnit(MonoObject* thiz)
{
	typedef float (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Canvas::get_referencePixelsPerUnit");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Canvas());
	float i2res = icall(i2thiz);
	return i2res;
}
void UnityEngine_Canvas_set_referencePixelsPerUnit(MonoObject* thiz, float value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, float value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Canvas::set_referencePixelsPerUnit");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Canvas());
	icall(i2thiz,value);
}
bool UnityEngine_Canvas_get_pixelPerfect(MonoObject* thiz)
{
	typedef bool (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Canvas::get_pixelPerfect");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Canvas());
	bool i2res = icall(i2thiz);
	return i2res;
}
int32_t UnityEngine_Canvas_get_renderOrder(MonoObject* thiz)
{
	typedef int32_t (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Canvas::get_renderOrder");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Canvas());
	int32_t i2res = icall(i2thiz);
	return i2res;
}
bool UnityEngine_Canvas_get_overrideSorting(MonoObject* thiz)
{
	typedef bool (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Canvas::get_overrideSorting");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Canvas());
	bool i2res = icall(i2thiz);
	return i2res;
}
void UnityEngine_Canvas_set_overrideSorting(MonoObject* thiz, bool value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, bool value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Canvas::set_overrideSorting");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Canvas());
	icall(i2thiz,value);
}
int32_t UnityEngine_Canvas_get_sortingOrder_1(MonoObject* thiz)
{
	typedef int32_t (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Canvas::get_sortingOrder");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Canvas());
	int32_t i2res = icall(i2thiz);
	return i2res;
}
void UnityEngine_Canvas_set_sortingOrder_1(MonoObject* thiz, int32_t value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, int32_t value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Canvas::set_sortingOrder");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Canvas());
	icall(i2thiz,value);
}
int32_t UnityEngine_Canvas_get_targetDisplay_1(MonoObject* thiz)
{
	typedef int32_t (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Canvas::get_targetDisplay");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Canvas());
	int32_t i2res = icall(i2thiz);
	return i2res;
}
int32_t UnityEngine_Canvas_get_sortingLayerID_1(MonoObject* thiz)
{
	typedef int32_t (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Canvas::get_sortingLayerID");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Canvas());
	int32_t i2res = icall(i2thiz);
	return i2res;
}
void UnityEngine_Canvas_set_sortingLayerID_1(MonoObject* thiz, int32_t value)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz, int32_t value);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Canvas::set_sortingLayerID");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Canvas());
	icall(i2thiz,value);
}
MonoObject* UnityEngine_Canvas_get_rootCanvas(MonoObject* thiz)
{
	typedef Il2CppObject* (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Canvas::get_rootCanvas");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Canvas());
	Il2CppObject* i2res = icall(i2thiz);
	MonoObject* monoi2res = get_mono_object(i2res,mono_get_class_UnityEngine_Canvas());
	if(i2res != NULL && monoi2res == NULL)
	{
		platform_log("UnityEngine.Canvas::get_rootCanvas fail to convert il2cpp obj to mono");
	}
	return monoi2res;
}
MonoObject* UnityEngine_Canvas_get_worldCamera(MonoObject* thiz)
{
	typedef Il2CppObject* (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Canvas::get_worldCamera");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Canvas());
	Il2CppObject* i2res = icall(i2thiz);
	MonoObject* monoi2res = get_mono_object(i2res,mono_get_class_UnityEngine_Camera());
	if(i2res != NULL && monoi2res == NULL)
	{
		platform_log("UnityEngine.Canvas::get_worldCamera fail to convert il2cpp obj to mono");
	}
	return monoi2res;
}
MonoObject* UnityEngine_Canvas_GetDefaultCanvasMaterial()
{
	typedef Il2CppObject* (* ICallMethod) ();
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Canvas::GetDefaultCanvasMaterial");
	Il2CppObject* i2res = icall();
	MonoObject* monoi2res = get_mono_object(i2res,mono_get_class_UnityEngine_Material());
	if(i2res != NULL && monoi2res == NULL)
	{
		platform_log("UnityEngine.Canvas::GetDefaultCanvasMaterial fail to convert il2cpp obj to mono");
	}
	return monoi2res;
}
MonoObject* UnityEngine_Canvas_GetETC1SupportedCanvasMaterial()
{
	typedef Il2CppObject* (* ICallMethod) ();
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Canvas::GetETC1SupportedCanvasMaterial");
	Il2CppObject* i2res = icall();
	MonoObject* monoi2res = get_mono_object(i2res,mono_get_class_UnityEngine_Material());
	if(i2res != NULL && monoi2res == NULL)
	{
		platform_log("UnityEngine.Canvas::GetETC1SupportedCanvasMaterial fail to convert il2cpp obj to mono");
	}
	return monoi2res;
}
void UnityEngine_UISystemProfilerApi_BeginSample(int32_t type)
{
	typedef void (* ICallMethod) (int32_t type);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.UISystemProfilerApi::BeginSample");
	icall(type);
}
void UnityEngine_UISystemProfilerApi_EndSample(int32_t type)
{
	typedef void (* ICallMethod) (int32_t type);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.UISystemProfilerApi::EndSample");
	icall(type);
}
void UnityEngine_UISystemProfilerApi_AddMarker(MonoString* name, MonoObject* obj)
{
	typedef void (* ICallMethod) (Il2CppString* name, Il2CppObject* obj);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.UISystemProfilerApi::AddMarker");
	Il2CppString* i2name = get_il2cpp_string(name);
	Il2CppObject* i2obj = get_il2cpp_object(obj,il2cpp_get_class_UnityEngine_Object());
	icall(i2name,i2obj);
}
int64_t UnityEngine_Networking_UnityWebRequest_get_responseCode(MonoObject* thiz)
{
	typedef int64_t (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Networking.UnityWebRequest::get_responseCode");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Networking_UnityWebRequest());
	int64_t i2res = icall(i2thiz);
	return i2res;
}
bool UnityEngine_Networking_UnityWebRequest_get_isModifiable(MonoObject* thiz)
{
	typedef bool (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Networking.UnityWebRequest::get_isModifiable");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Networking_UnityWebRequest());
	bool i2res = icall(i2thiz);
	return i2res;
}
int32_t UnityEngine_Networking_UnityWebRequest_get_result(MonoObject* thiz)
{
	typedef int32_t (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Networking.UnityWebRequest::get_result");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Networking_UnityWebRequest());
	int32_t i2res = icall(i2thiz);
	return i2res;
}
MonoString* UnityEngine_Networking_UnityWebRequest_GetHTTPStatusString(int64_t responseCode)
{
	typedef Il2CppString* (* ICallMethod) (int64_t responseCode);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Networking.UnityWebRequest::GetHTTPStatusString");
	Il2CppString* i2res = icall(responseCode);
	MonoString* monoi2res = get_mono_string(i2res);
	if(i2res != NULL && monoi2res == NULL)
	{
		platform_log("UnityEngine.Networking.UnityWebRequest::GetHTTPStatusString fail to convert il2cpp obj to mono");
	}
	return monoi2res;
}
void UnityEngine_Networking_UnityWebRequest_Abort(MonoObject* thiz)
{
	typedef void (* ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Networking.UnityWebRequest::Abort");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Networking_UnityWebRequest());
	icall(i2thiz);
}
MonoString* UnityEngine_Networking_UnityWebRequest_GetResponseHeader(MonoObject* thiz, MonoString* name)
{
	typedef Il2CppString* (* ICallMethod) (Il2CppObject* thiz, Il2CppString* name);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Networking.UnityWebRequest::GetResponseHeader");
	Il2CppObject* i2thiz = get_il2cpp_object(thiz,il2cpp_get_class_UnityEngine_Networking_UnityWebRequest());
	Il2CppString* i2name = get_il2cpp_string(name);
	Il2CppString* i2res = icall(i2thiz,i2name);
	MonoString* monoi2res = get_mono_string(i2res);
	if(i2res != NULL && monoi2res == NULL)
	{
		platform_log("UnityEngine.Networking.UnityWebRequest::GetResponseHeader fail to convert il2cpp obj to mono");
	}
	return monoi2res;
}
void * UnityEngine_Networking_DownloadHandler_InternalGetByteArray(MonoObject* dh, void * length)
{
	typedef void * (* ICallMethod) (Il2CppObject* dh, void * length);
	static ICallMethod icall;
	if(!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Networking.DownloadHandler::InternalGetByteArray");
	Il2CppObject* i2dh = get_il2cpp_object(dh,il2cpp_get_class_UnityEngine_Networking_DownloadHandler());
	void * i2res = icall(i2dh,length);
	if(i2res != NULL && i2res == NULL)
	{
		platform_log("UnityEngine.Networking.DownloadHandler::InternalGetByteArray fail to convert il2cpp obj to mono");
	}
	return i2res;
}
void regist_icall_gen()
{
	mono_add_internal_call("UnityEngine.AI.NavMeshAgent::get_pathStatus",(void*) UnityEngine_AI_NavMeshAgent_get_pathStatus);
	mono_add_internal_call("UnityEngine.AI.NavMeshAgent::set_isStopped",(void*) UnityEngine_AI_NavMeshAgent_set_isStopped);
	mono_add_internal_call("UnityEngine.AI.NavMeshAgent::set_speed",(void*) UnityEngine_AI_NavMeshAgent_set_speed);
	mono_add_internal_call("UnityEngine.AI.NavMeshAgent::set_angularSpeed",(void*) UnityEngine_AI_NavMeshAgent_set_angularSpeed);
	mono_add_internal_call("UnityEngine.AI.NavMeshAgent::set_acceleration",(void*) UnityEngine_AI_NavMeshAgent_set_acceleration);
	mono_add_internal_call("UnityEngine.AI.NavMeshAgent::set_updatePosition",(void*) UnityEngine_AI_NavMeshAgent_set_updatePosition);
	mono_add_internal_call("UnityEngine.AI.NavMeshAgent::set_updateRotation",(void*) UnityEngine_AI_NavMeshAgent_set_updateRotation);
	mono_add_internal_call("UnityEngine.AI.NavMeshAgent::set_radius",(void*) UnityEngine_AI_NavMeshAgent_set_radius);
	mono_add_internal_call("UnityEngine.AI.NavMeshAgent::SetDestination_Injected",(void*) UnityEngine_AI_NavMeshAgent_SetDestination_Injected);
	mono_add_internal_call("UnityEngine.AI.NavMeshAgent::Warp_Injected",(void*) UnityEngine_AI_NavMeshAgent_Warp_Injected);
	mono_add_internal_call("UnityEngine.AI.NavMesh::SamplePosition_Injected",(void*) UnityEngine_AI_NavMesh_SamplePosition_Injected);
	mono_add_internal_call("UnityEngine.AndroidJNIHelper::get_debug",(void*) UnityEngine_AndroidJNIHelper_get_debug);
	mono_add_internal_call("UnityEngine.AndroidJNIHelper::set_debug",(void*) UnityEngine_AndroidJNIHelper_set_debug);
	mono_add_internal_call("UnityEngine.AndroidJNI::AttachCurrentThread",(void*) UnityEngine_AndroidJNI_AttachCurrentThread);
	mono_add_internal_call("UnityEngine.AndroidJNI::DetachCurrentThread",(void*) UnityEngine_AndroidJNI_DetachCurrentThread);
	mono_add_internal_call("UnityEngine.AndroidJNI::GetVersion",(void*) UnityEngine_AndroidJNI_GetVersion);
	mono_add_internal_call("UnityEngine.AndroidJNI::FindClass",(void*) UnityEngine_AndroidJNI_FindClass);
	mono_add_internal_call("UnityEngine.AndroidJNI::FromReflectedMethod",(void*) UnityEngine_AndroidJNI_FromReflectedMethod);
	mono_add_internal_call("UnityEngine.AndroidJNI::FromReflectedField",(void*) UnityEngine_AndroidJNI_FromReflectedField);
	mono_add_internal_call("UnityEngine.AndroidJNI::ToReflectedMethod",(void*) UnityEngine_AndroidJNI_ToReflectedMethod);
	mono_add_internal_call("UnityEngine.AndroidJNI::ToReflectedField",(void*) UnityEngine_AndroidJNI_ToReflectedField);
	mono_add_internal_call("UnityEngine.AndroidJNI::GetSuperclass",(void*) UnityEngine_AndroidJNI_GetSuperclass);
	mono_add_internal_call("UnityEngine.AndroidJNI::IsAssignableFrom",(void*) UnityEngine_AndroidJNI_IsAssignableFrom);
	mono_add_internal_call("UnityEngine.AndroidJNI::Throw",(void*) UnityEngine_AndroidJNI_Throw);
	mono_add_internal_call("UnityEngine.AndroidJNI::ThrowNew",(void*) UnityEngine_AndroidJNI_ThrowNew);
	mono_add_internal_call("UnityEngine.AndroidJNI::ExceptionOccurred",(void*) UnityEngine_AndroidJNI_ExceptionOccurred);
	mono_add_internal_call("UnityEngine.AndroidJNI::ExceptionDescribe",(void*) UnityEngine_AndroidJNI_ExceptionDescribe);
	mono_add_internal_call("UnityEngine.AndroidJNI::ExceptionClear",(void*) UnityEngine_AndroidJNI_ExceptionClear);
	mono_add_internal_call("UnityEngine.AndroidJNI::FatalError",(void*) UnityEngine_AndroidJNI_FatalError);
	mono_add_internal_call("UnityEngine.AndroidJNI::PushLocalFrame",(void*) UnityEngine_AndroidJNI_PushLocalFrame);
	mono_add_internal_call("UnityEngine.AndroidJNI::PopLocalFrame",(void*) UnityEngine_AndroidJNI_PopLocalFrame);
	mono_add_internal_call("UnityEngine.AndroidJNI::NewGlobalRef",(void*) UnityEngine_AndroidJNI_NewGlobalRef);
	mono_add_internal_call("UnityEngine.AndroidJNI::DeleteGlobalRef",(void*) UnityEngine_AndroidJNI_DeleteGlobalRef);
	mono_add_internal_call("UnityEngine.AndroidJNI::NewWeakGlobalRef",(void*) UnityEngine_AndroidJNI_NewWeakGlobalRef);
	mono_add_internal_call("UnityEngine.AndroidJNI::DeleteWeakGlobalRef",(void*) UnityEngine_AndroidJNI_DeleteWeakGlobalRef);
	mono_add_internal_call("UnityEngine.AndroidJNI::NewLocalRef",(void*) UnityEngine_AndroidJNI_NewLocalRef);
	mono_add_internal_call("UnityEngine.AndroidJNI::DeleteLocalRef",(void*) UnityEngine_AndroidJNI_DeleteLocalRef);
	mono_add_internal_call("UnityEngine.AndroidJNI::IsSameObject",(void*) UnityEngine_AndroidJNI_IsSameObject);
	mono_add_internal_call("UnityEngine.AndroidJNI::EnsureLocalCapacity",(void*) UnityEngine_AndroidJNI_EnsureLocalCapacity);
	mono_add_internal_call("UnityEngine.AndroidJNI::AllocObject",(void*) UnityEngine_AndroidJNI_AllocObject);
	mono_add_internal_call("UnityEngine.AndroidJNI::NewObject",(void*) UnityEngine_AndroidJNI_NewObject);
	mono_add_internal_call("UnityEngine.AndroidJNI::GetObjectClass",(void*) UnityEngine_AndroidJNI_GetObjectClass);
	mono_add_internal_call("UnityEngine.AndroidJNI::IsInstanceOf",(void*) UnityEngine_AndroidJNI_IsInstanceOf);
	mono_add_internal_call("UnityEngine.AndroidJNI::GetMethodID",(void*) UnityEngine_AndroidJNI_GetMethodID);
	mono_add_internal_call("UnityEngine.AndroidJNI::GetFieldID",(void*) UnityEngine_AndroidJNI_GetFieldID);
	mono_add_internal_call("UnityEngine.AndroidJNI::GetStaticMethodID",(void*) UnityEngine_AndroidJNI_GetStaticMethodID);
	mono_add_internal_call("UnityEngine.AndroidJNI::GetStaticFieldID",(void*) UnityEngine_AndroidJNI_GetStaticFieldID);
	mono_add_internal_call("UnityEngine.AndroidJNI::NewStringFromStr",(void*) UnityEngine_AndroidJNI_NewStringFromStr);
	mono_add_internal_call("UnityEngine.AndroidJNI::NewString",(void*) UnityEngine_AndroidJNI_NewString);
	mono_add_internal_call("UnityEngine.AndroidJNI::NewStringUTF",(void*) UnityEngine_AndroidJNI_NewStringUTF);
	mono_add_internal_call("UnityEngine.AndroidJNI::GetStringChars",(void*) UnityEngine_AndroidJNI_GetStringChars);
	mono_add_internal_call("UnityEngine.AndroidJNI::GetStringLength",(void*) UnityEngine_AndroidJNI_GetStringLength);
	mono_add_internal_call("UnityEngine.AndroidJNI::GetStringUTFLength",(void*) UnityEngine_AndroidJNI_GetStringUTFLength);
	mono_add_internal_call("UnityEngine.AndroidJNI::GetStringUTFChars",(void*) UnityEngine_AndroidJNI_GetStringUTFChars);
	mono_add_internal_call("UnityEngine.AndroidJNI::CallStringMethod",(void*) UnityEngine_AndroidJNI_CallStringMethod);
	mono_add_internal_call("UnityEngine.AndroidJNI::CallObjectMethod",(void*) UnityEngine_AndroidJNI_CallObjectMethod);
	mono_add_internal_call("UnityEngine.AndroidJNI::CallIntMethod",(void*) UnityEngine_AndroidJNI_CallIntMethod);
	mono_add_internal_call("UnityEngine.AndroidJNI::CallBooleanMethod",(void*) UnityEngine_AndroidJNI_CallBooleanMethod);
	mono_add_internal_call("UnityEngine.AndroidJNI::CallShortMethod",(void*) UnityEngine_AndroidJNI_CallShortMethod);
	mono_add_internal_call("UnityEngine.AndroidJNI::CallSByteMethod",(void*) UnityEngine_AndroidJNI_CallSByteMethod);
	mono_add_internal_call("UnityEngine.AndroidJNI::CallCharMethod",(void*) UnityEngine_AndroidJNI_CallCharMethod);
	mono_add_internal_call("UnityEngine.AndroidJNI::CallFloatMethod",(void*) UnityEngine_AndroidJNI_CallFloatMethod);
	mono_add_internal_call("UnityEngine.AndroidJNI::CallDoubleMethod",(void*) UnityEngine_AndroidJNI_CallDoubleMethod);
	mono_add_internal_call("UnityEngine.AndroidJNI::CallLongMethod",(void*) UnityEngine_AndroidJNI_CallLongMethod);
	mono_add_internal_call("UnityEngine.AndroidJNI::CallVoidMethod",(void*) UnityEngine_AndroidJNI_CallVoidMethod);
	mono_add_internal_call("UnityEngine.AndroidJNI::GetStringField",(void*) UnityEngine_AndroidJNI_GetStringField);
	mono_add_internal_call("UnityEngine.AndroidJNI::GetObjectField",(void*) UnityEngine_AndroidJNI_GetObjectField);
	mono_add_internal_call("UnityEngine.AndroidJNI::GetBooleanField",(void*) UnityEngine_AndroidJNI_GetBooleanField);
	mono_add_internal_call("UnityEngine.AndroidJNI::GetSByteField",(void*) UnityEngine_AndroidJNI_GetSByteField);
	mono_add_internal_call("UnityEngine.AndroidJNI::GetCharField",(void*) UnityEngine_AndroidJNI_GetCharField);
	mono_add_internal_call("UnityEngine.AndroidJNI::GetShortField",(void*) UnityEngine_AndroidJNI_GetShortField);
	mono_add_internal_call("UnityEngine.AndroidJNI::GetIntField",(void*) UnityEngine_AndroidJNI_GetIntField);
	mono_add_internal_call("UnityEngine.AndroidJNI::GetLongField",(void*) UnityEngine_AndroidJNI_GetLongField);
	mono_add_internal_call("UnityEngine.AndroidJNI::GetFloatField",(void*) UnityEngine_AndroidJNI_GetFloatField);
	mono_add_internal_call("UnityEngine.AndroidJNI::GetDoubleField",(void*) UnityEngine_AndroidJNI_GetDoubleField);
	mono_add_internal_call("UnityEngine.AndroidJNI::SetStringField",(void*) UnityEngine_AndroidJNI_SetStringField);
	mono_add_internal_call("UnityEngine.AndroidJNI::SetObjectField",(void*) UnityEngine_AndroidJNI_SetObjectField);
	mono_add_internal_call("UnityEngine.AndroidJNI::SetBooleanField",(void*) UnityEngine_AndroidJNI_SetBooleanField);
	mono_add_internal_call("UnityEngine.AndroidJNI::SetSByteField",(void*) UnityEngine_AndroidJNI_SetSByteField);
	mono_add_internal_call("UnityEngine.AndroidJNI::SetCharField",(void*) UnityEngine_AndroidJNI_SetCharField);
	mono_add_internal_call("UnityEngine.AndroidJNI::SetShortField",(void*) UnityEngine_AndroidJNI_SetShortField);
	mono_add_internal_call("UnityEngine.AndroidJNI::SetIntField",(void*) UnityEngine_AndroidJNI_SetIntField);
	mono_add_internal_call("UnityEngine.AndroidJNI::SetLongField",(void*) UnityEngine_AndroidJNI_SetLongField);
	mono_add_internal_call("UnityEngine.AndroidJNI::SetFloatField",(void*) UnityEngine_AndroidJNI_SetFloatField);
	mono_add_internal_call("UnityEngine.AndroidJNI::SetDoubleField",(void*) UnityEngine_AndroidJNI_SetDoubleField);
	mono_add_internal_call("UnityEngine.AndroidJNI::CallStaticStringMethod",(void*) UnityEngine_AndroidJNI_CallStaticStringMethod);
	mono_add_internal_call("UnityEngine.AndroidJNI::CallStaticObjectMethod",(void*) UnityEngine_AndroidJNI_CallStaticObjectMethod);
	mono_add_internal_call("UnityEngine.AndroidJNI::CallStaticIntMethod",(void*) UnityEngine_AndroidJNI_CallStaticIntMethod);
	mono_add_internal_call("UnityEngine.AndroidJNI::CallStaticBooleanMethod",(void*) UnityEngine_AndroidJNI_CallStaticBooleanMethod);
	mono_add_internal_call("UnityEngine.AndroidJNI::CallStaticShortMethod",(void*) UnityEngine_AndroidJNI_CallStaticShortMethod);
	mono_add_internal_call("UnityEngine.AndroidJNI::CallStaticSByteMethod",(void*) UnityEngine_AndroidJNI_CallStaticSByteMethod);
	mono_add_internal_call("UnityEngine.AndroidJNI::CallStaticCharMethod",(void*) UnityEngine_AndroidJNI_CallStaticCharMethod);
	mono_add_internal_call("UnityEngine.AndroidJNI::CallStaticFloatMethod",(void*) UnityEngine_AndroidJNI_CallStaticFloatMethod);
	mono_add_internal_call("UnityEngine.AndroidJNI::CallStaticDoubleMethod",(void*) UnityEngine_AndroidJNI_CallStaticDoubleMethod);
	mono_add_internal_call("UnityEngine.AndroidJNI::CallStaticLongMethod",(void*) UnityEngine_AndroidJNI_CallStaticLongMethod);
	mono_add_internal_call("UnityEngine.AndroidJNI::CallStaticVoidMethod",(void*) UnityEngine_AndroidJNI_CallStaticVoidMethod);
	mono_add_internal_call("UnityEngine.AndroidJNI::GetStaticStringField",(void*) UnityEngine_AndroidJNI_GetStaticStringField);
	mono_add_internal_call("UnityEngine.AndroidJNI::GetStaticObjectField",(void*) UnityEngine_AndroidJNI_GetStaticObjectField);
	mono_add_internal_call("UnityEngine.AndroidJNI::GetStaticBooleanField",(void*) UnityEngine_AndroidJNI_GetStaticBooleanField);
	mono_add_internal_call("UnityEngine.AndroidJNI::GetStaticSByteField",(void*) UnityEngine_AndroidJNI_GetStaticSByteField);
	mono_add_internal_call("UnityEngine.AndroidJNI::GetStaticCharField",(void*) UnityEngine_AndroidJNI_GetStaticCharField);
	mono_add_internal_call("UnityEngine.AndroidJNI::GetStaticShortField",(void*) UnityEngine_AndroidJNI_GetStaticShortField);
	mono_add_internal_call("UnityEngine.AndroidJNI::GetStaticIntField",(void*) UnityEngine_AndroidJNI_GetStaticIntField);
	mono_add_internal_call("UnityEngine.AndroidJNI::GetStaticLongField",(void*) UnityEngine_AndroidJNI_GetStaticLongField);
	mono_add_internal_call("UnityEngine.AndroidJNI::GetStaticFloatField",(void*) UnityEngine_AndroidJNI_GetStaticFloatField);
	mono_add_internal_call("UnityEngine.AndroidJNI::GetStaticDoubleField",(void*) UnityEngine_AndroidJNI_GetStaticDoubleField);
	mono_add_internal_call("UnityEngine.AndroidJNI::SetStaticStringField",(void*) UnityEngine_AndroidJNI_SetStaticStringField);
	mono_add_internal_call("UnityEngine.AndroidJNI::SetStaticObjectField",(void*) UnityEngine_AndroidJNI_SetStaticObjectField);
	mono_add_internal_call("UnityEngine.AndroidJNI::SetStaticBooleanField",(void*) UnityEngine_AndroidJNI_SetStaticBooleanField);
	mono_add_internal_call("UnityEngine.AndroidJNI::SetStaticSByteField",(void*) UnityEngine_AndroidJNI_SetStaticSByteField);
	mono_add_internal_call("UnityEngine.AndroidJNI::SetStaticCharField",(void*) UnityEngine_AndroidJNI_SetStaticCharField);
	mono_add_internal_call("UnityEngine.AndroidJNI::SetStaticShortField",(void*) UnityEngine_AndroidJNI_SetStaticShortField);
	mono_add_internal_call("UnityEngine.AndroidJNI::SetStaticIntField",(void*) UnityEngine_AndroidJNI_SetStaticIntField);
	mono_add_internal_call("UnityEngine.AndroidJNI::SetStaticLongField",(void*) UnityEngine_AndroidJNI_SetStaticLongField);
	mono_add_internal_call("UnityEngine.AndroidJNI::SetStaticFloatField",(void*) UnityEngine_AndroidJNI_SetStaticFloatField);
	mono_add_internal_call("UnityEngine.AndroidJNI::SetStaticDoubleField",(void*) UnityEngine_AndroidJNI_SetStaticDoubleField);
	mono_add_internal_call("UnityEngine.AndroidJNI::ToBooleanArray",(void*) UnityEngine_AndroidJNI_ToBooleanArray);
	mono_add_internal_call("UnityEngine.AndroidJNI::ToByteArray",(void*) UnityEngine_AndroidJNI_ToByteArray);
	mono_add_internal_call("UnityEngine.AndroidJNI::ToSByteArray",(void*) UnityEngine_AndroidJNI_ToSByteArray);
	mono_add_internal_call("UnityEngine.AndroidJNI::ToCharArray",(void*) UnityEngine_AndroidJNI_ToCharArray);
	mono_add_internal_call("UnityEngine.AndroidJNI::ToShortArray",(void*) UnityEngine_AndroidJNI_ToShortArray);
	mono_add_internal_call("UnityEngine.AndroidJNI::ToIntArray",(void*) UnityEngine_AndroidJNI_ToIntArray);
	mono_add_internal_call("UnityEngine.AndroidJNI::ToLongArray",(void*) UnityEngine_AndroidJNI_ToLongArray);
	mono_add_internal_call("UnityEngine.AndroidJNI::ToFloatArray",(void*) UnityEngine_AndroidJNI_ToFloatArray);
	mono_add_internal_call("UnityEngine.AndroidJNI::ToDoubleArray",(void*) UnityEngine_AndroidJNI_ToDoubleArray);
	mono_add_internal_call("UnityEngine.AndroidJNI::ToObjectArray",(void*) UnityEngine_AndroidJNI_ToObjectArray);
	mono_add_internal_call("UnityEngine.AndroidJNI::FromBooleanArray",(void*) UnityEngine_AndroidJNI_FromBooleanArray);
	mono_add_internal_call("UnityEngine.AndroidJNI::FromByteArray",(void*) UnityEngine_AndroidJNI_FromByteArray);
	mono_add_internal_call("UnityEngine.AndroidJNI::FromSByteArray",(void*) UnityEngine_AndroidJNI_FromSByteArray);
	mono_add_internal_call("UnityEngine.AndroidJNI::FromCharArray",(void*) UnityEngine_AndroidJNI_FromCharArray);
	mono_add_internal_call("UnityEngine.AndroidJNI::FromShortArray",(void*) UnityEngine_AndroidJNI_FromShortArray);
	mono_add_internal_call("UnityEngine.AndroidJNI::FromIntArray",(void*) UnityEngine_AndroidJNI_FromIntArray);
	mono_add_internal_call("UnityEngine.AndroidJNI::FromLongArray",(void*) UnityEngine_AndroidJNI_FromLongArray);
	mono_add_internal_call("UnityEngine.AndroidJNI::FromFloatArray",(void*) UnityEngine_AndroidJNI_FromFloatArray);
	mono_add_internal_call("UnityEngine.AndroidJNI::FromDoubleArray",(void*) UnityEngine_AndroidJNI_FromDoubleArray);
	mono_add_internal_call("UnityEngine.AndroidJNI::FromObjectArray",(void*) UnityEngine_AndroidJNI_FromObjectArray);
	mono_add_internal_call("UnityEngine.AndroidJNI::GetArrayLength",(void*) UnityEngine_AndroidJNI_GetArrayLength);
	mono_add_internal_call("UnityEngine.AndroidJNI::NewBooleanArray",(void*) UnityEngine_AndroidJNI_NewBooleanArray);
	mono_add_internal_call("UnityEngine.AndroidJNI::NewSByteArray",(void*) UnityEngine_AndroidJNI_NewSByteArray);
	mono_add_internal_call("UnityEngine.AndroidJNI::NewCharArray",(void*) UnityEngine_AndroidJNI_NewCharArray);
	mono_add_internal_call("UnityEngine.AndroidJNI::NewShortArray",(void*) UnityEngine_AndroidJNI_NewShortArray);
	mono_add_internal_call("UnityEngine.AndroidJNI::NewIntArray",(void*) UnityEngine_AndroidJNI_NewIntArray);
	mono_add_internal_call("UnityEngine.AndroidJNI::NewLongArray",(void*) UnityEngine_AndroidJNI_NewLongArray);
	mono_add_internal_call("UnityEngine.AndroidJNI::NewFloatArray",(void*) UnityEngine_AndroidJNI_NewFloatArray);
	mono_add_internal_call("UnityEngine.AndroidJNI::NewDoubleArray",(void*) UnityEngine_AndroidJNI_NewDoubleArray);
	mono_add_internal_call("UnityEngine.AndroidJNI::NewObjectArray",(void*) UnityEngine_AndroidJNI_NewObjectArray);
	mono_add_internal_call("UnityEngine.AndroidJNI::GetBooleanArrayElement",(void*) UnityEngine_AndroidJNI_GetBooleanArrayElement);
	mono_add_internal_call("UnityEngine.AndroidJNI::GetSByteArrayElement",(void*) UnityEngine_AndroidJNI_GetSByteArrayElement);
	mono_add_internal_call("UnityEngine.AndroidJNI::GetCharArrayElement",(void*) UnityEngine_AndroidJNI_GetCharArrayElement);
	mono_add_internal_call("UnityEngine.AndroidJNI::GetShortArrayElement",(void*) UnityEngine_AndroidJNI_GetShortArrayElement);
	mono_add_internal_call("UnityEngine.AndroidJNI::GetIntArrayElement",(void*) UnityEngine_AndroidJNI_GetIntArrayElement);
	mono_add_internal_call("UnityEngine.AndroidJNI::GetLongArrayElement",(void*) UnityEngine_AndroidJNI_GetLongArrayElement);
	mono_add_internal_call("UnityEngine.AndroidJNI::GetFloatArrayElement",(void*) UnityEngine_AndroidJNI_GetFloatArrayElement);
	mono_add_internal_call("UnityEngine.AndroidJNI::GetDoubleArrayElement",(void*) UnityEngine_AndroidJNI_GetDoubleArrayElement);
	mono_add_internal_call("UnityEngine.AndroidJNI::GetObjectArrayElement",(void*) UnityEngine_AndroidJNI_GetObjectArrayElement);
	mono_add_internal_call("UnityEngine.AndroidJNI::SetBooleanArrayElement",(void*) UnityEngine_AndroidJNI_SetBooleanArrayElement);
	mono_add_internal_call("UnityEngine.AndroidJNI::SetSByteArrayElement",(void*) UnityEngine_AndroidJNI_SetSByteArrayElement);
	mono_add_internal_call("UnityEngine.AndroidJNI::SetCharArrayElement",(void*) UnityEngine_AndroidJNI_SetCharArrayElement);
	mono_add_internal_call("UnityEngine.AndroidJNI::SetShortArrayElement",(void*) UnityEngine_AndroidJNI_SetShortArrayElement);
	mono_add_internal_call("UnityEngine.AndroidJNI::SetIntArrayElement",(void*) UnityEngine_AndroidJNI_SetIntArrayElement);
	mono_add_internal_call("UnityEngine.AndroidJNI::SetLongArrayElement",(void*) UnityEngine_AndroidJNI_SetLongArrayElement);
	mono_add_internal_call("UnityEngine.AndroidJNI::SetFloatArrayElement",(void*) UnityEngine_AndroidJNI_SetFloatArrayElement);
	mono_add_internal_call("UnityEngine.AndroidJNI::SetDoubleArrayElement",(void*) UnityEngine_AndroidJNI_SetDoubleArrayElement);
	mono_add_internal_call("UnityEngine.AndroidJNI::SetObjectArrayElement",(void*) UnityEngine_AndroidJNI_SetObjectArrayElement);
	mono_add_internal_call("UnityEngine.Animator::get_isHuman",(void*) UnityEngine_Animator_get_isHuman);
	mono_add_internal_call("UnityEngine.Animator::get_hasRootMotion",(void*) UnityEngine_Animator_get_hasRootMotion);
	mono_add_internal_call("UnityEngine.Animator::set_updateMode",(void*) UnityEngine_Animator_set_updateMode);
	mono_add_internal_call("UnityEngine.Animator::get_layerCount",(void*) UnityEngine_Animator_get_layerCount);
	mono_add_internal_call("UnityEngine.Animator::set_speed",(void*) UnityEngine_Animator_set_speed_1);
	mono_add_internal_call("UnityEngine.Animator::get_runtimeAnimatorController",(void*) UnityEngine_Animator_get_runtimeAnimatorController);
	mono_add_internal_call("UnityEngine.Animator::get_hasBoundPlayables",(void*) UnityEngine_Animator_get_hasBoundPlayables);
	mono_add_internal_call("UnityEngine.Animator::get_avatar",(void*) UnityEngine_Animator_get_avatar);
	mono_add_internal_call("UnityEngine.Animator::SetBoolString",(void*) UnityEngine_Animator_SetBoolString);
	mono_add_internal_call("UnityEngine.Animator::SetIntegerString",(void*) UnityEngine_Animator_SetIntegerString);
	mono_add_internal_call("UnityEngine.Animator::SetTriggerString",(void*) UnityEngine_Animator_SetTriggerString);
	mono_add_internal_call("UnityEngine.Animator::ResetTriggerString",(void*) UnityEngine_Animator_ResetTriggerString);
	mono_add_internal_call("UnityEngine.Animator::GetLayerWeight",(void*) UnityEngine_Animator_GetLayerWeight);
	mono_add_internal_call("UnityEngine.Animator::GetAnimatorStateInfo",(void*) UnityEngine_Animator_GetAnimatorStateInfo);
	mono_add_internal_call("UnityEngine.Animator::GetAnimatorClipInfoCount",(void*) UnityEngine_Animator_GetAnimatorClipInfoCount);
	mono_add_internal_call("UnityEngine.Animator::GetCurrentAnimatorClipInfo",(void*) UnityEngine_Animator_GetCurrentAnimatorClipInfo);
	mono_add_internal_call("UnityEngine.Animator::IsInTransition",(void*) UnityEngine_Animator_IsInTransition);
	mono_add_internal_call("UnityEngine.Animator::StringToHash",(void*) UnityEngine_Animator_StringToHash);
	mono_add_internal_call("UnityEngine.Animator::CrossFadeInFixedTime",(void*) UnityEngine_Animator_CrossFadeInFixedTime);
	mono_add_internal_call("UnityEngine.Animator::Play",(void*) UnityEngine_Animator_Play);
	mono_add_internal_call("UnityEngine.Animator::HasState",(void*) UnityEngine_Animator_HasState);
	mono_add_internal_call("UnityEngine.Animator::Update",(void*) UnityEngine_Animator_Update);
	mono_add_internal_call("UnityEngine.AnimatorClipInfo::InstanceIDToAnimationClipPPtr",(void*) UnityEngine_AnimatorClipInfo_InstanceIDToAnimationClipPPtr);
	mono_add_internal_call("UnityEngine.Animation::get_clip",(void*) UnityEngine_Animation_get_clip);
	mono_add_internal_call("UnityEngine.Animation::set_wrapMode",(void*) UnityEngine_Animation_set_wrapMode);
	mono_add_internal_call("UnityEngine.Animation::get_isPlaying",(void*) UnityEngine_Animation_get_isPlaying);
	mono_add_internal_call("UnityEngine.Animation::Sample",(void*) UnityEngine_Animation_Sample);
	mono_add_internal_call("UnityEngine.Animation::IsPlaying",(void*) UnityEngine_Animation_IsPlaying);
	mono_add_internal_call("UnityEngine.Animation::PlayDefaultAnimation",(void*) UnityEngine_Animation_PlayDefaultAnimation);
	mono_add_internal_call("UnityEngine.Animation::Play",(void*) UnityEngine_Animation_Play_1);
	mono_add_internal_call("UnityEngine.AnimationClip::get_length",(void*) UnityEngine_AnimationClip_get_length);
	mono_add_internal_call("UnityEngine.AnimationClip::get_frameRate",(void*) UnityEngine_AnimationClip_get_frameRate);
	mono_add_internal_call("UnityEngine.AnimationClip::set_frameRate",(void*) UnityEngine_AnimationClip_set_frameRate);
	mono_add_internal_call("UnityEngine.AnimationClip::set_wrapMode",(void*) UnityEngine_AnimationClip_set_wrapMode_1);
	mono_add_internal_call("UnityEngine.AnimationClip::get_legacy",(void*) UnityEngine_AnimationClip_get_legacy);
	mono_add_internal_call("UnityEngine.AnimationClip::set_legacy",(void*) UnityEngine_AnimationClip_set_legacy);
	mono_add_internal_call("UnityEngine.AnimationClip::get_empty",(void*) UnityEngine_AnimationClip_get_empty);
	mono_add_internal_call("UnityEngine.AnimationClip::get_hasGenericRootTransform",(void*) UnityEngine_AnimationClip_get_hasGenericRootTransform);
	mono_add_internal_call("UnityEngine.AnimationClip::get_hasMotionCurves",(void*) UnityEngine_AnimationClip_get_hasMotionCurves);
	mono_add_internal_call("UnityEngine.AnimationClip::get_hasRootCurves",(void*) UnityEngine_AnimationClip_get_hasRootCurves);
	mono_add_internal_call("UnityEngine.AnimationClip::Internal_CreateAnimationClip",(void*) UnityEngine_AnimationClip_Internal_CreateAnimationClip);
	mono_add_internal_call("UnityEngine.Motion::get_isLooping",(void*) UnityEngine_Motion_get_isLooping);
	mono_add_internal_call("UnityEngine.AnimationState::get_time",(void*) UnityEngine_AnimationState_get_time);
	mono_add_internal_call("UnityEngine.AnimationState::set_time",(void*) UnityEngine_AnimationState_set_time);
	mono_add_internal_call("UnityEngine.AnimationState::get_speed",(void*) UnityEngine_AnimationState_get_speed);
	mono_add_internal_call("UnityEngine.AnimationState::set_speed",(void*) UnityEngine_AnimationState_set_speed_2);
	mono_add_internal_call("UnityEngine.AnimationState::get_length",(void*) UnityEngine_AnimationState_get_length_1);
	mono_add_internal_call("UnityEngine.AnimationState::get_name",(void*) UnityEngine_AnimationState_get_name);
	mono_add_internal_call("UnityEngine.AvatarMask::get_transformCount",(void*) UnityEngine_AvatarMask_get_transformCount);
	mono_add_internal_call("UnityEngine.AvatarMask::GetHumanoidBodyPartActive",(void*) UnityEngine_AvatarMask_GetHumanoidBodyPartActive);
	mono_add_internal_call("UnityEngine.AvatarMask::GetTransformPath",(void*) UnityEngine_AvatarMask_GetTransformPath);
	mono_add_internal_call("UnityEngine.AvatarMask::GetTransformWeight",(void*) UnityEngine_AvatarMask_GetTransformWeight);
	mono_add_internal_call("UnityEngine.Animations.AnimationClipPlayable::SetApplyFootIKInternal",(void*) UnityEngine_Animations_AnimationClipPlayable_SetApplyFootIKInternal);
	mono_add_internal_call("UnityEngine.Animations.AnimationClipPlayable::SetRemoveStartOffsetInternal",(void*) UnityEngine_Animations_AnimationClipPlayable_SetRemoveStartOffsetInternal);
	mono_add_internal_call("UnityEngine.Animations.AnimationClipPlayable::SetOverrideLoopTimeInternal",(void*) UnityEngine_Animations_AnimationClipPlayable_SetOverrideLoopTimeInternal);
	mono_add_internal_call("UnityEngine.Animations.AnimationClipPlayable::SetLoopTimeInternal",(void*) UnityEngine_Animations_AnimationClipPlayable_SetLoopTimeInternal);
	mono_add_internal_call("UnityEngine.Animations.AnimationClipPlayable::CreateHandleInternal_Injected",(void*) UnityEngine_Animations_AnimationClipPlayable_CreateHandleInternal_Injected);
	mono_add_internal_call("UnityEngine.Animations.AnimationLayerMixerPlayable::SetLayerMaskFromAvatarMaskInternal",(void*) UnityEngine_Animations_AnimationLayerMixerPlayable_SetLayerMaskFromAvatarMaskInternal);
	mono_add_internal_call("UnityEngine.Animations.AnimationLayerMixerPlayable::CreateHandleInternal_Injected",(void*) UnityEngine_Animations_AnimationLayerMixerPlayable_CreateHandleInternal_Injected_1);
	mono_add_internal_call("UnityEngine.Animations.AnimationMixerPlayable::CreateHandleInternal_Injected",(void*) UnityEngine_Animations_AnimationMixerPlayable_CreateHandleInternal_Injected_2);
	mono_add_internal_call("UnityEngine.Animations.AnimationPlayableExtensions::SetAnimatedPropertiesInternal",(void*) UnityEngine_Animations_AnimationPlayableExtensions_SetAnimatedPropertiesInternal);
	mono_add_internal_call("UnityEngine.Animations.AnimationPlayableGraphExtensions::InternalCreateAnimationOutput",(void*) UnityEngine_Animations_AnimationPlayableGraphExtensions_InternalCreateAnimationOutput);
	mono_add_internal_call("UnityEngine.Animations.AnimationPlayableOutput::InternalSetTarget",(void*) UnityEngine_Animations_AnimationPlayableOutput_InternalSetTarget);
	mono_add_internal_call("UnityEngine.AssetBundle::get_isStreamedSceneAssetBundle",(void*) UnityEngine_AssetBundle_get_isStreamedSceneAssetBundle);
	mono_add_internal_call("UnityEngine.AssetBundle::returnMainAsset",(void*) UnityEngine_AssetBundle_returnMainAsset);
	mono_add_internal_call("UnityEngine.AssetBundle::UnloadAllAssetBundles",(void*) UnityEngine_AssetBundle_UnloadAllAssetBundles);
	mono_add_internal_call("UnityEngine.AssetBundle::GetAllLoadedAssetBundles_Native",(void*) UnityEngine_AssetBundle_GetAllLoadedAssetBundles_Native);
	mono_add_internal_call("UnityEngine.AssetBundle::LoadFromFileAsync_Internal",(void*) UnityEngine_AssetBundle_LoadFromFileAsync_Internal);
	mono_add_internal_call("UnityEngine.AssetBundle::LoadFromFile_Internal",(void*) UnityEngine_AssetBundle_LoadFromFile_Internal);
	mono_add_internal_call("UnityEngine.AssetBundle::LoadFromMemoryAsync_Internal",(void*) UnityEngine_AssetBundle_LoadFromMemoryAsync_Internal);
	mono_add_internal_call("UnityEngine.AssetBundle::LoadFromMemory_Internal",(void*) UnityEngine_AssetBundle_LoadFromMemory_Internal);
	mono_add_internal_call("UnityEngine.AssetBundle::LoadFromStreamAsyncInternal",(void*) UnityEngine_AssetBundle_LoadFromStreamAsyncInternal);
	mono_add_internal_call("UnityEngine.AssetBundle::LoadFromStreamInternal",(void*) UnityEngine_AssetBundle_LoadFromStreamInternal);
	mono_add_internal_call("UnityEngine.AssetBundle::Contains",(void*) UnityEngine_AssetBundle_Contains);
	mono_add_internal_call("UnityEngine.AssetBundle::LoadAsset_Internal",(void*) UnityEngine_AssetBundle_LoadAsset_Internal);
	mono_add_internal_call("UnityEngine.AssetBundle::LoadAssetAsync_Internal",(void*) UnityEngine_AssetBundle_LoadAssetAsync_Internal);
	mono_add_internal_call("UnityEngine.AssetBundle::Unload",(void*) UnityEngine_AssetBundle_Unload);
	mono_add_internal_call("UnityEngine.AssetBundle::UnloadAsync",(void*) UnityEngine_AssetBundle_UnloadAsync);
	mono_add_internal_call("UnityEngine.AssetBundle::GetAllAssetNames",(void*) UnityEngine_AssetBundle_GetAllAssetNames);
	mono_add_internal_call("UnityEngine.AssetBundle::GetAllScenePaths",(void*) UnityEngine_AssetBundle_GetAllScenePaths);
	mono_add_internal_call("UnityEngine.AssetBundle::LoadAssetWithSubAssets_Internal",(void*) UnityEngine_AssetBundle_LoadAssetWithSubAssets_Internal);
	mono_add_internal_call("UnityEngine.AssetBundle::LoadAssetWithSubAssetsAsync_Internal",(void*) UnityEngine_AssetBundle_LoadAssetWithSubAssetsAsync_Internal);
	mono_add_internal_call("UnityEngine.AssetBundle::RecompressAssetBundleAsync_Internal_Injected",(void*) UnityEngine_AssetBundle_RecompressAssetBundleAsync_Internal_Injected);
	mono_add_internal_call("UnityEngine.AssetBundleLoadingCache::get_maxBlocksPerFile",(void*) UnityEngine_AssetBundleLoadingCache_get_maxBlocksPerFile);
	mono_add_internal_call("UnityEngine.AssetBundleLoadingCache::set_maxBlocksPerFile",(void*) UnityEngine_AssetBundleLoadingCache_set_maxBlocksPerFile);
	mono_add_internal_call("UnityEngine.AssetBundleLoadingCache::get_blockCount",(void*) UnityEngine_AssetBundleLoadingCache_get_blockCount);
	mono_add_internal_call("UnityEngine.AssetBundleLoadingCache::set_blockCount",(void*) UnityEngine_AssetBundleLoadingCache_set_blockCount);
	mono_add_internal_call("UnityEngine.AssetBundleLoadingCache::get_blockSize",(void*) UnityEngine_AssetBundleLoadingCache_get_blockSize);
	mono_add_internal_call("UnityEngine.AudioSettings::StartAudioOutput",(void*) UnityEngine_AudioSettings_StartAudioOutput);
	mono_add_internal_call("UnityEngine.AudioSettings::StopAudioOutput",(void*) UnityEngine_AudioSettings_StopAudioOutput);
	mono_add_internal_call("UnityEngine.AudioClip::get_length",(void*) UnityEngine_AudioClip_get_length_2);
	mono_add_internal_call("UnityEngine.AudioClip::get_samples",(void*) UnityEngine_AudioClip_get_samples);
	mono_add_internal_call("UnityEngine.AudioClip::get_channels",(void*) UnityEngine_AudioClip_get_channels);
	mono_add_internal_call("UnityEngine.AudioSource::get_volume",(void*) UnityEngine_AudioSource_get_volume);
	mono_add_internal_call("UnityEngine.AudioSource::set_volume",(void*) UnityEngine_AudioSource_set_volume);
	mono_add_internal_call("UnityEngine.AudioSource::get_clip",(void*) UnityEngine_AudioSource_get_clip_1);
	mono_add_internal_call("UnityEngine.AudioSource::set_clip",(void*) UnityEngine_AudioSource_set_clip);
	mono_add_internal_call("UnityEngine.AudioSource::get_isPlaying",(void*) UnityEngine_AudioSource_get_isPlaying_1);
	mono_add_internal_call("UnityEngine.AudioSource::set_loop",(void*) UnityEngine_AudioSource_set_loop);
	mono_add_internal_call("UnityEngine.AudioSource::set_playOnAwake",(void*) UnityEngine_AudioSource_set_playOnAwake);
	mono_add_internal_call("UnityEngine.AudioSource::set_priority",(void*) UnityEngine_AudioSource_set_priority);
	mono_add_internal_call("UnityEngine.AudioSource::PlayHelper",(void*) UnityEngine_AudioSource_PlayHelper);
	mono_add_internal_call("UnityEngine.AudioSource::Play",(void*) UnityEngine_AudioSource_Play_2);
	mono_add_internal_call("UnityEngine.AudioSource::Stop",(void*) UnityEngine_AudioSource_Stop);
	mono_add_internal_call("UnityEngine.AudioSource::Pause",(void*) UnityEngine_AudioSource_Pause);
	mono_add_internal_call("UnityEngine.Microphone::get_devices",(void*) UnityEngine_Microphone_get_devices);
	mono_add_internal_call("UnityEngine.Microphone::GetMicrophoneDeviceIDFromName",(void*) UnityEngine_Microphone_GetMicrophoneDeviceIDFromName);
	mono_add_internal_call("UnityEngine.Microphone::EndRecord",(void*) UnityEngine_Microphone_EndRecord);
	mono_add_internal_call("UnityEngine.Microphone::IsRecording",(void*) UnityEngine_Microphone_IsRecording);
	mono_add_internal_call("UnityEngine.Audio.AudioPlayableOutput::InternalSetEvaluateOnSeek",(void*) UnityEngine_Audio_AudioPlayableOutput_InternalSetEvaluateOnSeek);
	mono_add_internal_call("UnityEngine.SortingLayer::GetLayerValueFromID",(void*) UnityEngine_SortingLayer_GetLayerValueFromID);
	mono_add_internal_call("UnityEngine.AnimationCurve::get_length",(void*) UnityEngine_AnimationCurve_get_length_3);
	mono_add_internal_call("UnityEngine.AnimationCurve::Evaluate",(void*) UnityEngine_AnimationCurve_Evaluate);
	mono_add_internal_call("UnityEngine.Application::get_isPlaying",(void*) UnityEngine_Application_get_isPlaying_2);
	mono_add_internal_call("UnityEngine.Application::get_isBatchMode",(void*) UnityEngine_Application_get_isBatchMode);
	mono_add_internal_call("UnityEngine.Application::get_dataPath",(void*) UnityEngine_Application_get_dataPath);
	mono_add_internal_call("UnityEngine.Application::get_streamingAssetsPath",(void*) UnityEngine_Application_get_streamingAssetsPath);
	mono_add_internal_call("UnityEngine.Application::get_persistentDataPath",(void*) UnityEngine_Application_get_persistentDataPath);
	mono_add_internal_call("UnityEngine.Application::get_unityVersion",(void*) UnityEngine_Application_get_unityVersion);
	mono_add_internal_call("UnityEngine.Application::get_identifier",(void*) UnityEngine_Application_get_identifier);
	mono_add_internal_call("UnityEngine.Application::get_targetFrameRate",(void*) UnityEngine_Application_get_targetFrameRate);
	mono_add_internal_call("UnityEngine.Application::set_targetFrameRate",(void*) UnityEngine_Application_set_targetFrameRate);
	mono_add_internal_call("UnityEngine.Application::get_platform",(void*) UnityEngine_Application_get_platform);
	mono_add_internal_call("UnityEngine.Application::get_internetReachability",(void*) UnityEngine_Application_get_internetReachability);
	mono_add_internal_call("UnityEngine.Application::OpenURL",(void*) UnityEngine_Application_OpenURL);
	mono_add_internal_call("UnityEngine.Caching::ClearCache",(void*) UnityEngine_Caching_ClearCache);
	mono_add_internal_call("UnityEngine.Camera::get_nearClipPlane",(void*) UnityEngine_Camera_get_nearClipPlane);
	mono_add_internal_call("UnityEngine.Camera::set_nearClipPlane",(void*) UnityEngine_Camera_set_nearClipPlane);
	mono_add_internal_call("UnityEngine.Camera::get_farClipPlane",(void*) UnityEngine_Camera_get_farClipPlane);
	mono_add_internal_call("UnityEngine.Camera::set_farClipPlane",(void*) UnityEngine_Camera_set_farClipPlane);
	mono_add_internal_call("UnityEngine.Camera::get_fieldOfView",(void*) UnityEngine_Camera_get_fieldOfView);
	mono_add_internal_call("UnityEngine.Camera::set_fieldOfView",(void*) UnityEngine_Camera_set_fieldOfView);
	mono_add_internal_call("UnityEngine.Camera::set_renderingPath",(void*) UnityEngine_Camera_set_renderingPath);
	mono_add_internal_call("UnityEngine.Camera::set_allowHDR",(void*) UnityEngine_Camera_set_allowHDR);
	mono_add_internal_call("UnityEngine.Camera::get_orthographicSize",(void*) UnityEngine_Camera_get_orthographicSize);
	mono_add_internal_call("UnityEngine.Camera::set_orthographicSize",(void*) UnityEngine_Camera_set_orthographicSize);
	mono_add_internal_call("UnityEngine.Camera::get_orthographic",(void*) UnityEngine_Camera_get_orthographic);
	mono_add_internal_call("UnityEngine.Camera::set_orthographic",(void*) UnityEngine_Camera_set_orthographic);
	mono_add_internal_call("UnityEngine.Camera::get_transparencySortMode",(void*) UnityEngine_Camera_get_transparencySortMode);
	mono_add_internal_call("UnityEngine.Camera::set_transparencySortMode",(void*) UnityEngine_Camera_set_transparencySortMode);
	mono_add_internal_call("UnityEngine.Camera::get_depth",(void*) UnityEngine_Camera_get_depth);
	mono_add_internal_call("UnityEngine.Camera::set_depth",(void*) UnityEngine_Camera_set_depth);
	mono_add_internal_call("UnityEngine.Camera::get_aspect",(void*) UnityEngine_Camera_get_aspect);
	mono_add_internal_call("UnityEngine.Camera::get_cullingMask",(void*) UnityEngine_Camera_get_cullingMask);
	mono_add_internal_call("UnityEngine.Camera::set_cullingMask",(void*) UnityEngine_Camera_set_cullingMask);
	mono_add_internal_call("UnityEngine.Camera::get_eventMask",(void*) UnityEngine_Camera_get_eventMask);
	mono_add_internal_call("UnityEngine.Camera::set_eventMask",(void*) UnityEngine_Camera_set_eventMask);
	mono_add_internal_call("UnityEngine.Camera::set_useOcclusionCulling",(void*) UnityEngine_Camera_set_useOcclusionCulling);
	mono_add_internal_call("UnityEngine.Camera::get_clearFlags",(void*) UnityEngine_Camera_get_clearFlags);
	mono_add_internal_call("UnityEngine.Camera::set_clearFlags",(void*) UnityEngine_Camera_set_clearFlags);
	mono_add_internal_call("UnityEngine.Camera::get_depthTextureMode",(void*) UnityEngine_Camera_get_depthTextureMode);
	mono_add_internal_call("UnityEngine.Camera::set_depthTextureMode",(void*) UnityEngine_Camera_set_depthTextureMode);
	mono_add_internal_call("UnityEngine.Camera::get_pixelWidth",(void*) UnityEngine_Camera_get_pixelWidth);
	mono_add_internal_call("UnityEngine.Camera::get_pixelHeight",(void*) UnityEngine_Camera_get_pixelHeight);
	mono_add_internal_call("UnityEngine.Camera::get_targetTexture",(void*) UnityEngine_Camera_get_targetTexture);
	mono_add_internal_call("UnityEngine.Camera::set_targetTexture",(void*) UnityEngine_Camera_set_targetTexture);
	mono_add_internal_call("UnityEngine.Camera::get_targetDisplay",(void*) UnityEngine_Camera_get_targetDisplay);
	mono_add_internal_call("UnityEngine.Camera::get_main",(void*) UnityEngine_Camera_get_main);
	mono_add_internal_call("UnityEngine.Camera::WorldToScreenPoint_Injected",(void*) UnityEngine_Camera_WorldToScreenPoint_Injected);
	mono_add_internal_call("UnityEngine.Camera::WorldToViewportPoint_Injected",(void*) UnityEngine_Camera_WorldToViewportPoint_Injected);
	mono_add_internal_call("UnityEngine.Camera::ViewportToWorldPoint_Injected",(void*) UnityEngine_Camera_ViewportToWorldPoint_Injected);
	mono_add_internal_call("UnityEngine.Camera::ScreenToWorldPoint_Injected",(void*) UnityEngine_Camera_ScreenToWorldPoint_Injected);
	mono_add_internal_call("UnityEngine.Camera::ScreenToViewportPoint_Injected",(void*) UnityEngine_Camera_ScreenToViewportPoint_Injected);
	mono_add_internal_call("UnityEngine.Camera::Render",(void*) UnityEngine_Camera_Render);
	mono_add_internal_call("UnityEngine.Camera::CopyFrom",(void*) UnityEngine_Camera_CopyFrom);
	mono_add_internal_call("UnityEngine.Mathf::GammaToLinearSpace",(void*) UnityEngine_Mathf_GammaToLinearSpace);
	mono_add_internal_call("UnityEngine.Mathf::PerlinNoise",(void*) UnityEngine_Mathf_PerlinNoise);
	mono_add_internal_call("UnityEngine.RenderTexture::get_width",(void*) UnityEngine_RenderTexture_get_width);
	mono_add_internal_call("UnityEngine.RenderTexture::set_width",(void*) UnityEngine_RenderTexture_set_width);
	mono_add_internal_call("UnityEngine.RenderTexture::get_height",(void*) UnityEngine_RenderTexture_get_height);
	mono_add_internal_call("UnityEngine.RenderTexture::set_height",(void*) UnityEngine_RenderTexture_set_height);
	mono_add_internal_call("UnityEngine.RenderTexture::set_graphicsFormat",(void*) UnityEngine_RenderTexture_set_graphicsFormat);
	mono_add_internal_call("UnityEngine.RenderTexture::set_depth",(void*) UnityEngine_RenderTexture_set_depth_1);
	mono_add_internal_call("UnityEngine.RenderTexture::ReleaseTemporary",(void*) UnityEngine_RenderTexture_ReleaseTemporary);
	mono_add_internal_call("UnityEngine.QualitySettings::set_shadows",(void*) UnityEngine_QualitySettings_set_shadows);
	mono_add_internal_call("UnityEngine.QualitySettings::set_vSyncCount",(void*) UnityEngine_QualitySettings_set_vSyncCount);
	mono_add_internal_call("UnityEngine.QualitySettings::get_activeColorSpace",(void*) UnityEngine_QualitySettings_get_activeColorSpace);
	mono_add_internal_call("UnityEngine.QualitySettings::SetQualityLevel",(void*) UnityEngine_QualitySettings_SetQualityLevel);
	mono_add_internal_call("UnityEngine.SystemInfo::IsFormatSupported",(void*) UnityEngine_SystemInfo_IsFormatSupported);
	mono_add_internal_call("UnityEngine.SystemInfo::GetCompatibleFormat",(void*) UnityEngine_SystemInfo_GetCompatibleFormat);
	mono_add_internal_call("UnityEngine.SystemInfo::GetGraphicsFormat",(void*) UnityEngine_SystemInfo_GetGraphicsFormat);
	mono_add_internal_call("UnityEngine.Matrix4x4::TRS_Injected",(void*) UnityEngine_Matrix4x4_TRS_Injected);
	mono_add_internal_call("UnityEngine.Matrix4x4::Inverse3DAffine_Injected",(void*) UnityEngine_Matrix4x4_Inverse3DAffine_Injected);
	mono_add_internal_call("UnityEngine.Matrix4x4::Inverse_Injected",(void*) UnityEngine_Matrix4x4_Inverse_Injected);
	mono_add_internal_call("UnityEngine.Matrix4x4::Perspective_Injected",(void*) UnityEngine_Matrix4x4_Perspective_Injected);
	mono_add_internal_call("UnityEngine.Vector3::Slerp_Injected",(void*) UnityEngine_Vector3_Slerp_Injected);
	mono_add_internal_call("UnityEngine.Quaternion::FromToRotation_Injected",(void*) UnityEngine_Quaternion_FromToRotation_Injected);
	mono_add_internal_call("UnityEngine.Quaternion::Inverse_Injected",(void*) UnityEngine_Quaternion_Inverse_Injected_1);
	mono_add_internal_call("UnityEngine.Quaternion::Slerp_Injected",(void*) UnityEngine_Quaternion_Slerp_Injected_1);
	mono_add_internal_call("UnityEngine.Quaternion::Lerp_Injected",(void*) UnityEngine_Quaternion_Lerp_Injected);
	mono_add_internal_call("UnityEngine.Quaternion::Internal_FromEulerRad_Injected",(void*) UnityEngine_Quaternion_Internal_FromEulerRad_Injected);
	mono_add_internal_call("UnityEngine.Quaternion::Internal_ToEulerRad_Injected",(void*) UnityEngine_Quaternion_Internal_ToEulerRad_Injected);
	mono_add_internal_call("UnityEngine.Quaternion::AngleAxis_Injected",(void*) UnityEngine_Quaternion_AngleAxis_Injected);
	mono_add_internal_call("UnityEngine.Quaternion::LookRotation_Injected",(void*) UnityEngine_Quaternion_LookRotation_Injected);
	mono_add_internal_call("UnityEngine.Object::get_hideFlags",(void*) UnityEngine_Object_get_hideFlags);
	mono_add_internal_call("UnityEngine.Object::set_hideFlags",(void*) UnityEngine_Object_set_hideFlags);
	mono_add_internal_call("UnityEngine.Object::Internal_CloneSingle",(void*) UnityEngine_Object_Internal_CloneSingle);
	mono_add_internal_call("UnityEngine.Object::ToString",(void*) UnityEngine_Object_ToString);
	mono_add_internal_call("UnityEngine.Object::FindObjectFromInstanceID",(void*) UnityEngine_Object_FindObjectFromInstanceID);
	mono_add_internal_call("UnityEngine.Object::Destroy",(void*) UnityEngine_Object_Destroy);
	mono_add_internal_call("UnityEngine.Object::DestroyImmediate",(void*) UnityEngine_Object_DestroyImmediate);
	mono_add_internal_call("UnityEngine.Object::FindObjectsOfType",(void*) UnityEngine_Object_FindObjectsOfType);
	mono_add_internal_call("UnityEngine.Object::DontDestroyOnLoad",(void*) UnityEngine_Object_DontDestroyOnLoad);
	mono_add_internal_call("UnityEngine.Transform::get_childCount",(void*) UnityEngine_Transform_get_childCount);
	mono_add_internal_call("UnityEngine.Transform::get_hasChanged",(void*) UnityEngine_Transform_get_hasChanged);
	mono_add_internal_call("UnityEngine.Transform::set_hasChanged",(void*) UnityEngine_Transform_set_hasChanged);
	mono_add_internal_call("UnityEngine.Transform::GetParent",(void*) UnityEngine_Transform_GetParent);
	mono_add_internal_call("UnityEngine.Transform::SetParent",(void*) UnityEngine_Transform_SetParent);
	mono_add_internal_call("UnityEngine.Transform::GetRoot",(void*) UnityEngine_Transform_GetRoot);
	mono_add_internal_call("UnityEngine.Transform::SetAsFirstSibling",(void*) UnityEngine_Transform_SetAsFirstSibling);
	mono_add_internal_call("UnityEngine.Transform::FindRelativeTransformWithPath",(void*) UnityEngine_Transform_FindRelativeTransformWithPath);
	mono_add_internal_call("UnityEngine.Transform::IsChildOf",(void*) UnityEngine_Transform_IsChildOf);
	mono_add_internal_call("UnityEngine.Transform::GetChild",(void*) UnityEngine_Transform_GetChild);
	mono_add_internal_call("UnityEngine.Transform::get_position_Injected",(void*) UnityEngine_Transform_get_position_Injected);
	mono_add_internal_call("UnityEngine.Transform::set_position_Injected",(void*) UnityEngine_Transform_set_position_Injected);
	mono_add_internal_call("UnityEngine.Transform::get_localPosition_Injected",(void*) UnityEngine_Transform_get_localPosition_Injected);
	mono_add_internal_call("UnityEngine.Transform::set_localPosition_Injected",(void*) UnityEngine_Transform_set_localPosition_Injected);
	mono_add_internal_call("UnityEngine.Transform::get_rotation_Injected",(void*) UnityEngine_Transform_get_rotation_Injected);
	mono_add_internal_call("UnityEngine.Transform::set_rotation_Injected",(void*) UnityEngine_Transform_set_rotation_Injected);
	mono_add_internal_call("UnityEngine.Transform::get_localRotation_Injected",(void*) UnityEngine_Transform_get_localRotation_Injected);
	mono_add_internal_call("UnityEngine.Transform::set_localRotation_Injected",(void*) UnityEngine_Transform_set_localRotation_Injected);
	mono_add_internal_call("UnityEngine.Transform::get_localScale_Injected",(void*) UnityEngine_Transform_get_localScale_Injected);
	mono_add_internal_call("UnityEngine.Transform::set_localScale_Injected",(void*) UnityEngine_Transform_set_localScale_Injected);
	mono_add_internal_call("UnityEngine.Transform::get_worldToLocalMatrix_Injected",(void*) UnityEngine_Transform_get_worldToLocalMatrix_Injected);
	mono_add_internal_call("UnityEngine.Transform::get_localToWorldMatrix_Injected",(void*) UnityEngine_Transform_get_localToWorldMatrix_Injected);
	mono_add_internal_call("UnityEngine.Transform::SetPositionAndRotation_Injected",(void*) UnityEngine_Transform_SetPositionAndRotation_Injected);
	mono_add_internal_call("UnityEngine.Transform::Internal_LookAt_Injected",(void*) UnityEngine_Transform_Internal_LookAt_Injected);
	mono_add_internal_call("UnityEngine.Transform::TransformDirection_Injected",(void*) UnityEngine_Transform_TransformDirection_Injected);
	mono_add_internal_call("UnityEngine.Transform::InverseTransformDirection_Injected",(void*) UnityEngine_Transform_InverseTransformDirection_Injected);
	mono_add_internal_call("UnityEngine.Transform::TransformPoint_Injected",(void*) UnityEngine_Transform_TransformPoint_Injected);
	mono_add_internal_call("UnityEngine.Transform::InverseTransformPoint_Injected",(void*) UnityEngine_Transform_InverseTransformPoint_Injected);
	mono_add_internal_call("UnityEngine.Transform::get_lossyScale_Injected",(void*) UnityEngine_Transform_get_lossyScale_Injected);
	mono_add_internal_call("UnityEngine.Component::get_transform",(void*) UnityEngine_Component_get_transform);
	mono_add_internal_call("UnityEngine.Component::get_gameObject",(void*) UnityEngine_Component_get_gameObject);
	mono_add_internal_call("UnityEngine.Component::GetComponentsForListInternal",(void*) UnityEngine_Component_GetComponentsForListInternal);
	mono_add_internal_call("UnityEngine.Component::SendMessage",(void*) UnityEngine_Component_SendMessage);
	mono_add_internal_call("UnityEngine.Component::BroadcastMessage",(void*) UnityEngine_Component_BroadcastMessage);
	mono_add_internal_call("UnityEngine.GameObject::get_transform",(void*) UnityEngine_GameObject_get_transform_1);
	mono_add_internal_call("UnityEngine.GameObject::get_layer",(void*) UnityEngine_GameObject_get_layer);
	mono_add_internal_call("UnityEngine.GameObject::set_layer",(void*) UnityEngine_GameObject_set_layer);
	mono_add_internal_call("UnityEngine.GameObject::get_active",(void*) UnityEngine_GameObject_get_active);
	mono_add_internal_call("UnityEngine.GameObject::get_activeSelf",(void*) UnityEngine_GameObject_get_activeSelf);
	mono_add_internal_call("UnityEngine.GameObject::get_activeInHierarchy",(void*) UnityEngine_GameObject_get_activeInHierarchy);
	mono_add_internal_call("UnityEngine.GameObject::get_tag",(void*) UnityEngine_GameObject_get_tag);
	mono_add_internal_call("UnityEngine.GameObject::set_tag",(void*) UnityEngine_GameObject_set_tag);
	mono_add_internal_call("UnityEngine.GameObject::GetComponent",(void*) UnityEngine_GameObject_GetComponent);
	mono_add_internal_call("UnityEngine.GameObject::GetComponentInChildren",(void*) UnityEngine_GameObject_GetComponentInChildren);
	mono_add_internal_call("UnityEngine.GameObject::GetComponentInParent",(void*) UnityEngine_GameObject_GetComponentInParent);
	mono_add_internal_call("UnityEngine.GameObject::TryGetComponentFastPath",(void*) UnityEngine_GameObject_TryGetComponentFastPath);
	mono_add_internal_call("UnityEngine.GameObject::SetActive",(void*) UnityEngine_GameObject_SetActive);
	mono_add_internal_call("UnityEngine.GameObject::CompareTag",(void*) UnityEngine_GameObject_CompareTag);
	mono_add_internal_call("UnityEngine.GameObject::SendMessage",(void*) UnityEngine_GameObject_SendMessage_1);
	mono_add_internal_call("UnityEngine.GameObject::BroadcastMessage",(void*) UnityEngine_GameObject_BroadcastMessage_1);
	mono_add_internal_call("UnityEngine.GameObject::Internal_CreateGameObject",(void*) UnityEngine_GameObject_Internal_CreateGameObject);
	mono_add_internal_call("UnityEngine.GameObject::Find",(void*) UnityEngine_GameObject_Find);
	mono_add_internal_call("UnityEngine.Behaviour::get_enabled",(void*) UnityEngine_Behaviour_get_enabled);
	mono_add_internal_call("UnityEngine.Behaviour::set_enabled",(void*) UnityEngine_Behaviour_set_enabled);
	mono_add_internal_call("UnityEngine.Behaviour::get_isActiveAndEnabled",(void*) UnityEngine_Behaviour_get_isActiveAndEnabled);
	mono_add_internal_call("UnityEngine.DebugLogHandler::Internal_Log",(void*) UnityEngine_DebugLogHandler_Internal_Log);
	mono_add_internal_call("UnityEngine.DebugLogHandler::Internal_LogException",(void*) UnityEngine_DebugLogHandler_Internal_LogException);
	mono_add_internal_call("UnityEngine.Debug::get_isDebugBuild",(void*) UnityEngine_Debug_get_isDebugBuild);
	mono_add_internal_call("UnityEngine.Debug::ExtractStackTraceNoAlloc",(void*) UnityEngine_Debug_ExtractStackTraceNoAlloc);
	mono_add_internal_call("UnityEngine.Debug::DrawLine_Injected",(void*) UnityEngine_Debug_DrawLine_Injected);
	mono_add_internal_call("UnityEngine.RectOffset::get_left",(void*) UnityEngine_RectOffset_get_left);
	mono_add_internal_call("UnityEngine.RectOffset::get_right",(void*) UnityEngine_RectOffset_get_right);
	mono_add_internal_call("UnityEngine.RectOffset::get_top",(void*) UnityEngine_RectOffset_get_top);
	mono_add_internal_call("UnityEngine.RectOffset::get_bottom",(void*) UnityEngine_RectOffset_get_bottom);
	mono_add_internal_call("UnityEngine.RectOffset::get_horizontal",(void*) UnityEngine_RectOffset_get_horizontal);
	mono_add_internal_call("UnityEngine.RectOffset::get_vertical",(void*) UnityEngine_RectOffset_get_vertical);
	mono_add_internal_call("UnityEngine.Gizmos::DrawLine_Injected",(void*) UnityEngine_Gizmos_DrawLine_Injected_1);
	mono_add_internal_call("UnityEngine.Gizmos::DrawWireSphere_Injected",(void*) UnityEngine_Gizmos_DrawWireSphere_Injected);
	mono_add_internal_call("UnityEngine.Gizmos::DrawWireCube_Injected",(void*) UnityEngine_Gizmos_DrawWireCube_Injected);
	mono_add_internal_call("UnityEngine.Screen::get_width",(void*) UnityEngine_Screen_get_width_1);
	mono_add_internal_call("UnityEngine.Screen::get_height",(void*) UnityEngine_Screen_get_height_1);
	mono_add_internal_call("UnityEngine.Screen::get_dpi",(void*) UnityEngine_Screen_get_dpi);
	mono_add_internal_call("UnityEngine.Screen::get_sleepTimeout",(void*) UnityEngine_Screen_get_sleepTimeout);
	mono_add_internal_call("UnityEngine.Screen::set_sleepTimeout",(void*) UnityEngine_Screen_set_sleepTimeout);
	mono_add_internal_call("UnityEngine.Screen::get_fullScreen",(void*) UnityEngine_Screen_get_fullScreen);
	mono_add_internal_call("UnityEngine.Screen::set_fullScreen",(void*) UnityEngine_Screen_set_fullScreen);
	mono_add_internal_call("UnityEngine.Screen::get_fullScreenMode",(void*) UnityEngine_Screen_get_fullScreenMode);
	mono_add_internal_call("UnityEngine.Screen::set_fullScreenMode",(void*) UnityEngine_Screen_set_fullScreenMode);
	mono_add_internal_call("UnityEngine.Screen::get_cutouts",(void*) UnityEngine_Screen_get_cutouts);
	mono_add_internal_call("UnityEngine.Screen::get_resolutions",(void*) UnityEngine_Screen_get_resolutions);
	mono_add_internal_call("UnityEngine.Screen::get_brightness",(void*) UnityEngine_Screen_get_brightness);
	mono_add_internal_call("UnityEngine.Screen::set_brightness",(void*) UnityEngine_Screen_set_brightness);
	mono_add_internal_call("UnityEngine.Screen::SetResolution",(void*) UnityEngine_Screen_SetResolution);
	mono_add_internal_call("UnityEngine.Graphics::Blit2",(void*) UnityEngine_Graphics_Blit2);
	mono_add_internal_call("UnityEngine.Graphics::Internal_BlitMaterial5",(void*) UnityEngine_Graphics_Internal_BlitMaterial5);
	mono_add_internal_call("UnityEngine.Mesh::get_vertexCount",(void*) UnityEngine_Mesh_get_vertexCount);
	mono_add_internal_call("UnityEngine.Mesh::get_subMeshCount",(void*) UnityEngine_Mesh_get_subMeshCount);
	mono_add_internal_call("UnityEngine.Mesh::set_subMeshCount",(void*) UnityEngine_Mesh_set_subMeshCount);
	mono_add_internal_call("UnityEngine.Mesh::get_canAccess",(void*) UnityEngine_Mesh_get_canAccess);
	mono_add_internal_call("UnityEngine.Mesh::Internal_Create",(void*) UnityEngine_Mesh_Internal_Create);
	mono_add_internal_call("UnityEngine.Mesh::ClearImpl",(void*) UnityEngine_Mesh_ClearImpl);
	mono_add_internal_call("UnityEngine.Mesh::MarkDynamicImpl",(void*) UnityEngine_Mesh_MarkDynamicImpl);
	mono_add_internal_call("UnityEngine.Mesh::HasVertexAttribute",(void*) UnityEngine_Mesh_HasVertexAttribute);
	mono_add_internal_call("UnityEngine.Material::get_shader",(void*) UnityEngine_Material_get_shader);
	mono_add_internal_call("UnityEngine.Material::set_shader",(void*) UnityEngine_Material_set_shader);
	mono_add_internal_call("UnityEngine.Material::get_renderQueue",(void*) UnityEngine_Material_get_renderQueue);
	mono_add_internal_call("UnityEngine.Material::set_renderQueue",(void*) UnityEngine_Material_set_renderQueue);
	mono_add_internal_call("UnityEngine.Material::CreateWithShader",(void*) UnityEngine_Material_CreateWithShader);
	mono_add_internal_call("UnityEngine.Material::CreateWithMaterial",(void*) UnityEngine_Material_CreateWithMaterial);
	mono_add_internal_call("UnityEngine.Material::CreateWithString",(void*) UnityEngine_Material_CreateWithString);
	mono_add_internal_call("UnityEngine.Material::GetTagImpl",(void*) UnityEngine_Material_GetTagImpl);
	mono_add_internal_call("UnityEngine.Material::SetFloatImpl",(void*) UnityEngine_Material_SetFloatImpl);
	mono_add_internal_call("UnityEngine.Material::SetColorImpl_Injected",(void*) UnityEngine_Material_SetColorImpl_Injected);
	mono_add_internal_call("UnityEngine.Material::SetMatrixImpl_Injected",(void*) UnityEngine_Material_SetMatrixImpl_Injected);
	mono_add_internal_call("UnityEngine.Material::SetTextureImpl",(void*) UnityEngine_Material_SetTextureImpl);
	mono_add_internal_call("UnityEngine.Material::GetFloatImpl",(void*) UnityEngine_Material_GetFloatImpl);
	mono_add_internal_call("UnityEngine.Material::GetColorImpl_Injected",(void*) UnityEngine_Material_GetColorImpl_Injected);
	mono_add_internal_call("UnityEngine.Material::GetTextureImpl",(void*) UnityEngine_Material_GetTextureImpl);
	mono_add_internal_call("UnityEngine.Material::SetTextureOffsetImpl_Injected",(void*) UnityEngine_Material_SetTextureOffsetImpl_Injected);
	mono_add_internal_call("UnityEngine.Material::SetTextureScaleImpl_Injected",(void*) UnityEngine_Material_SetTextureScaleImpl_Injected);
	mono_add_internal_call("UnityEngine.Material::HasProperty",(void*) UnityEngine_Material_HasProperty);
	mono_add_internal_call("UnityEngine.Material::EnableKeyword",(void*) UnityEngine_Material_EnableKeyword);
	mono_add_internal_call("UnityEngine.Material::DisableKeyword",(void*) UnityEngine_Material_DisableKeyword);
	mono_add_internal_call("UnityEngine.Material::SetPass",(void*) UnityEngine_Material_SetPass);
	mono_add_internal_call("UnityEngine.Material::CopyPropertiesFromMaterial",(void*) UnityEngine_Material_CopyPropertiesFromMaterial);
	mono_add_internal_call("UnityEngine.Shader::get_isSupported",(void*) UnityEngine_Shader_get_isSupported);
	mono_add_internal_call("UnityEngine.Shader::SetGlobalFloatImpl",(void*) UnityEngine_Shader_SetGlobalFloatImpl);
	mono_add_internal_call("UnityEngine.Shader::SetGlobalMatrixImpl_Injected",(void*) UnityEngine_Shader_SetGlobalMatrixImpl_Injected);
	mono_add_internal_call("UnityEngine.Shader::TagToID",(void*) UnityEngine_Shader_TagToID);
	mono_add_internal_call("UnityEngine.Shader::EnableKeyword",(void*) UnityEngine_Shader_EnableKeyword_1);
	mono_add_internal_call("UnityEngine.Shader::DisableKeyword",(void*) UnityEngine_Shader_DisableKeyword_1);
	mono_add_internal_call("UnityEngine.Shader::WarmupAllShaders",(void*) UnityEngine_Shader_WarmupAllShaders);
	mono_add_internal_call("UnityEngine.Shader::PropertyToID",(void*) UnityEngine_Shader_PropertyToID);
	mono_add_internal_call("UnityEngine.Shader::GetPropertyCount",(void*) UnityEngine_Shader_GetPropertyCount);
	mono_add_internal_call("UnityEngine.Texture::get_isReadable",(void*) UnityEngine_Texture_get_isReadable);
	mono_add_internal_call("UnityEngine.Texture::get_wrapMode",(void*) UnityEngine_Texture_get_wrapMode);
	mono_add_internal_call("UnityEngine.Texture::set_wrapMode",(void*) UnityEngine_Texture_set_wrapMode_2);
	mono_add_internal_call("UnityEngine.Texture::set_filterMode",(void*) UnityEngine_Texture_set_filterMode);
	mono_add_internal_call("UnityEngine.Texture::get_anisoLevel",(void*) UnityEngine_Texture_get_anisoLevel);
	mono_add_internal_call("UnityEngine.Texture::set_anisoLevel",(void*) UnityEngine_Texture_set_anisoLevel);
	mono_add_internal_call("UnityEngine.Texture::set_mipMapBias",(void*) UnityEngine_Texture_set_mipMapBias);
	mono_add_internal_call("UnityEngine.Texture::GetDataWidth",(void*) UnityEngine_Texture_GetDataWidth);
	mono_add_internal_call("UnityEngine.Texture::GetDataHeight",(void*) UnityEngine_Texture_GetDataHeight);
	mono_add_internal_call("UnityEngine.MaterialPropertyBlock::SetFloatImpl",(void*) UnityEngine_MaterialPropertyBlock_SetFloatImpl_1);
	mono_add_internal_call("UnityEngine.GL::Vertex3",(void*) UnityEngine_GL_Vertex3);
	mono_add_internal_call("UnityEngine.GL::MultiTexCoord3",(void*) UnityEngine_GL_MultiTexCoord3);
	mono_add_internal_call("UnityEngine.GL::PushMatrix",(void*) UnityEngine_GL_PushMatrix);
	mono_add_internal_call("UnityEngine.GL::PopMatrix",(void*) UnityEngine_GL_PopMatrix);
	mono_add_internal_call("UnityEngine.GL::LoadOrtho",(void*) UnityEngine_GL_LoadOrtho);
	mono_add_internal_call("UnityEngine.GL::Begin",(void*) UnityEngine_GL_Begin);
	mono_add_internal_call("UnityEngine.GL::End",(void*) UnityEngine_GL_End);
	mono_add_internal_call("UnityEngine.TrailRenderer::get_time",(void*) UnityEngine_TrailRenderer_get_time_1);
	mono_add_internal_call("UnityEngine.TrailRenderer::set_time",(void*) UnityEngine_TrailRenderer_set_time_1);
	mono_add_internal_call("UnityEngine.LineRenderer::set_widthMultiplier",(void*) UnityEngine_LineRenderer_set_widthMultiplier);
	mono_add_internal_call("UnityEngine.LineRenderer::set_positionCount",(void*) UnityEngine_LineRenderer_set_positionCount);
	mono_add_internal_call("UnityEngine.LineRenderer::SetPosition_Injected",(void*) UnityEngine_LineRenderer_SetPosition_Injected);
	mono_add_internal_call("UnityEngine.Renderer::get_enabled",(void*) UnityEngine_Renderer_get_enabled_1);
	mono_add_internal_call("UnityEngine.Renderer::set_enabled",(void*) UnityEngine_Renderer_set_enabled_1);
	mono_add_internal_call("UnityEngine.Renderer::get_shadowCastingMode",(void*) UnityEngine_Renderer_get_shadowCastingMode);
	mono_add_internal_call("UnityEngine.Renderer::set_shadowCastingMode",(void*) UnityEngine_Renderer_set_shadowCastingMode);
	mono_add_internal_call("UnityEngine.Renderer::get_receiveShadows",(void*) UnityEngine_Renderer_get_receiveShadows);
	mono_add_internal_call("UnityEngine.Renderer::set_receiveShadows",(void*) UnityEngine_Renderer_set_receiveShadows);
	mono_add_internal_call("UnityEngine.Renderer::get_motionVectorGenerationMode",(void*) UnityEngine_Renderer_get_motionVectorGenerationMode);
	mono_add_internal_call("UnityEngine.Renderer::set_motionVectorGenerationMode",(void*) UnityEngine_Renderer_set_motionVectorGenerationMode);
	mono_add_internal_call("UnityEngine.Renderer::get_lightProbeUsage",(void*) UnityEngine_Renderer_get_lightProbeUsage);
	mono_add_internal_call("UnityEngine.Renderer::set_lightProbeUsage",(void*) UnityEngine_Renderer_set_lightProbeUsage);
	mono_add_internal_call("UnityEngine.Renderer::get_reflectionProbeUsage",(void*) UnityEngine_Renderer_get_reflectionProbeUsage);
	mono_add_internal_call("UnityEngine.Renderer::set_reflectionProbeUsage",(void*) UnityEngine_Renderer_set_reflectionProbeUsage);
	mono_add_internal_call("UnityEngine.Renderer::get_sortingLayerID",(void*) UnityEngine_Renderer_get_sortingLayerID);
	mono_add_internal_call("UnityEngine.Renderer::set_sortingLayerID",(void*) UnityEngine_Renderer_set_sortingLayerID);
	mono_add_internal_call("UnityEngine.Renderer::get_sortingOrder",(void*) UnityEngine_Renderer_get_sortingOrder);
	mono_add_internal_call("UnityEngine.Renderer::set_sortingOrder",(void*) UnityEngine_Renderer_set_sortingOrder);
	mono_add_internal_call("UnityEngine.Renderer::get_probeAnchor",(void*) UnityEngine_Renderer_get_probeAnchor);
	mono_add_internal_call("UnityEngine.Renderer::set_probeAnchor",(void*) UnityEngine_Renderer_set_probeAnchor);
	mono_add_internal_call("UnityEngine.Renderer::Internal_SetPropertyBlock",(void*) UnityEngine_Renderer_Internal_SetPropertyBlock);
	mono_add_internal_call("UnityEngine.Renderer::Internal_GetPropertyBlock",(void*) UnityEngine_Renderer_Internal_GetPropertyBlock);
	mono_add_internal_call("UnityEngine.Projector::set_orthographic",(void*) UnityEngine_Projector_set_orthographic_1);
	mono_add_internal_call("UnityEngine.Projector::set_orthographicSize",(void*) UnityEngine_Projector_set_orthographicSize_1);
	mono_add_internal_call("UnityEngine.Projector::set_ignoreLayers",(void*) UnityEngine_Projector_set_ignoreLayers);
	mono_add_internal_call("UnityEngine.Projector::get_material",(void*) UnityEngine_Projector_get_material);
	mono_add_internal_call("UnityEngine.Projector::set_material",(void*) UnityEngine_Projector_set_material);
	mono_add_internal_call("UnityEngine.Light::get_type",(void*) UnityEngine_Light_get_type);
	mono_add_internal_call("UnityEngine.Light::get_spotAngle",(void*) UnityEngine_Light_get_spotAngle);
	mono_add_internal_call("UnityEngine.Light::get_intensity",(void*) UnityEngine_Light_get_intensity);
	mono_add_internal_call("UnityEngine.Light::get_bounceIntensity",(void*) UnityEngine_Light_get_bounceIntensity);
	mono_add_internal_call("UnityEngine.Light::get_range",(void*) UnityEngine_Light_get_range);
	mono_add_internal_call("UnityEngine.Light::get_shadows",(void*) UnityEngine_Light_get_shadows);
	mono_add_internal_call("UnityEngine.Light::get_cookieSize",(void*) UnityEngine_Light_get_cookieSize);
	mono_add_internal_call("UnityEngine.Light::get_cookie",(void*) UnityEngine_Light_get_cookie);
	mono_add_internal_call("UnityEngine.MeshFilter::get_sharedMesh",(void*) UnityEngine_MeshFilter_get_sharedMesh);
	mono_add_internal_call("UnityEngine.MeshFilter::set_sharedMesh",(void*) UnityEngine_MeshFilter_set_sharedMesh);
	mono_add_internal_call("UnityEngine.MeshFilter::get_mesh",(void*) UnityEngine_MeshFilter_get_mesh);
	mono_add_internal_call("UnityEngine.MeshFilter::set_mesh",(void*) UnityEngine_MeshFilter_set_mesh);
	mono_add_internal_call("UnityEngine.SkinnedMeshRenderer::BakeMesh",(void*) UnityEngine_SkinnedMeshRenderer_BakeMesh);
	mono_add_internal_call("UnityEngine.Texture2D::get_whiteTexture",(void*) UnityEngine_Texture2D_get_whiteTexture);
	mono_add_internal_call("UnityEngine.Texture2D::get_isReadable",(void*) UnityEngine_Texture2D_get_isReadable_1);
	mono_add_internal_call("UnityEngine.Texture2D::GetPixels",(void*) UnityEngine_Texture2D_GetPixels);
	mono_add_internal_call("UnityEngine.Texture2D::PackTextures",(void*) UnityEngine_Texture2D_PackTextures);
	mono_add_internal_call("UnityEngine.Cubemap::get_isReadable",(void*) UnityEngine_Cubemap_get_isReadable_2);
	mono_add_internal_call("UnityEngine.Texture3D::get_isReadable",(void*) UnityEngine_Texture3D_get_isReadable_3);
	mono_add_internal_call("UnityEngine.Texture2DArray::get_isReadable",(void*) UnityEngine_Texture2DArray_get_isReadable_4);
	mono_add_internal_call("UnityEngine.CubemapArray::get_isReadable",(void*) UnityEngine_CubemapArray_get_isReadable_5);
	mono_add_internal_call("UnityEngine.Cursor::set_visible",(void*) UnityEngine_Cursor_set_visible);
	mono_add_internal_call("UnityEngine.Cursor::get_lockState",(void*) UnityEngine_Cursor_get_lockState);
	mono_add_internal_call("UnityEngine.Cursor::set_lockState",(void*) UnityEngine_Cursor_set_lockState);
	mono_add_internal_call("UnityEngine.PlayerPrefs::GetInt",(void*) UnityEngine_PlayerPrefs_GetInt);
	mono_add_internal_call("UnityEngine.PlayerPrefs::GetFloat",(void*) UnityEngine_PlayerPrefs_GetFloat);
	mono_add_internal_call("UnityEngine.PlayerPrefs::GetString",(void*) UnityEngine_PlayerPrefs_GetString);
	mono_add_internal_call("UnityEngine.PlayerPrefs::HasKey",(void*) UnityEngine_PlayerPrefs_HasKey);
	mono_add_internal_call("UnityEngine.PlayerPrefs::DeleteKey",(void*) UnityEngine_PlayerPrefs_DeleteKey);
	mono_add_internal_call("UnityEngine.PlayerPrefs::Save",(void*) UnityEngine_PlayerPrefs_Save);
	mono_add_internal_call("UnityEngine.PropertyNameUtils::PropertyNameFromString_Injected",(void*) UnityEngine_PropertyNameUtils_PropertyNameFromString_Injected);
	mono_add_internal_call("UnityEngine.Random::RandomRangeInt",(void*) UnityEngine_Random_RandomRangeInt);
	mono_add_internal_call("UnityEngine.Random::InitState",(void*) UnityEngine_Random_InitState);
	mono_add_internal_call("UnityEngine.Random::Range",(void*) UnityEngine_Random_Range);
	mono_add_internal_call("UnityEngine.ResourcesAPIInternal::FindObjectsOfTypeAll",(void*) UnityEngine_ResourcesAPIInternal_FindObjectsOfTypeAll);
	mono_add_internal_call("UnityEngine.ResourcesAPIInternal::FindShaderByName",(void*) UnityEngine_ResourcesAPIInternal_FindShaderByName);
	mono_add_internal_call("UnityEngine.ResourcesAPIInternal::Load",(void*) UnityEngine_ResourcesAPIInternal_Load);
	mono_add_internal_call("UnityEngine.Resources::GetBuiltinResource",(void*) UnityEngine_Resources_GetBuiltinResource);
	mono_add_internal_call("UnityEngine.Resources::UnloadUnusedAssets",(void*) UnityEngine_Resources_UnloadUnusedAssets);
	mono_add_internal_call("UnityEngine.AsyncOperation::get_isDone",(void*) UnityEngine_AsyncOperation_get_isDone);
	mono_add_internal_call("UnityEngine.LayerMask::NameToLayer",(void*) UnityEngine_LayerMask_NameToLayer);
	mono_add_internal_call("UnityEngine.MonoBehaviour::get_useGUILayout",(void*) UnityEngine_MonoBehaviour_get_useGUILayout);
	mono_add_internal_call("UnityEngine.MonoBehaviour::set_useGUILayout",(void*) UnityEngine_MonoBehaviour_set_useGUILayout);
	mono_add_internal_call("UnityEngine.MonoBehaviour::StopCoroutine",(void*) UnityEngine_MonoBehaviour_StopCoroutine);
	mono_add_internal_call("UnityEngine.MonoBehaviour::StopAllCoroutines",(void*) UnityEngine_MonoBehaviour_StopAllCoroutines);
	mono_add_internal_call("UnityEngine.MonoBehaviour::Internal_CancelInvokeAll",(void*) UnityEngine_MonoBehaviour_Internal_CancelInvokeAll);
	mono_add_internal_call("UnityEngine.MonoBehaviour::Internal_IsInvokingAll",(void*) UnityEngine_MonoBehaviour_Internal_IsInvokingAll);
	mono_add_internal_call("UnityEngine.MonoBehaviour::InvokeDelayed",(void*) UnityEngine_MonoBehaviour_InvokeDelayed);
	mono_add_internal_call("UnityEngine.MonoBehaviour::CancelInvoke",(void*) UnityEngine_MonoBehaviour_CancelInvoke);
	mono_add_internal_call("UnityEngine.MonoBehaviour::IsInvoking",(void*) UnityEngine_MonoBehaviour_IsInvoking);
	mono_add_internal_call("UnityEngine.MonoBehaviour::IsObjectMonoBehaviour",(void*) UnityEngine_MonoBehaviour_IsObjectMonoBehaviour);
	mono_add_internal_call("UnityEngine.MonoBehaviour::StartCoroutineManaged",(void*) UnityEngine_MonoBehaviour_StartCoroutineManaged);
	mono_add_internal_call("UnityEngine.MonoBehaviour::StopCoroutineManaged",(void*) UnityEngine_MonoBehaviour_StopCoroutineManaged);
	mono_add_internal_call("UnityEngine.MonoBehaviour::StopCoroutineFromEnumeratorManaged",(void*) UnityEngine_MonoBehaviour_StopCoroutineFromEnumeratorManaged);
	mono_add_internal_call("UnityEngine.MonoBehaviour::GetScriptClassName",(void*) UnityEngine_MonoBehaviour_GetScriptClassName);
	mono_add_internal_call("UnityEngine.ScriptableObject::CreateScriptableObject",(void*) UnityEngine_ScriptableObject_CreateScriptableObject);
	mono_add_internal_call("UnityEngine.ScriptableObject::CreateScriptableObjectInstanceFromType",(void*) UnityEngine_ScriptableObject_CreateScriptableObjectInstanceFromType);
	mono_add_internal_call("UnityEngine.TextAsset::get_bytes",(void*) UnityEngine_TextAsset_get_bytes);
	mono_add_internal_call("UnityEngine.ComputeShader::FindKernel",(void*) UnityEngine_ComputeShader_FindKernel);
	mono_add_internal_call("UnityEngine.ShaderVariantCollection::WarmUp",(void*) UnityEngine_ShaderVariantCollection_WarmUp);
	mono_add_internal_call("UnityEngine.Time::get_time",(void*) UnityEngine_Time_get_time_2);
	mono_add_internal_call("UnityEngine.Time::get_deltaTime",(void*) UnityEngine_Time_get_deltaTime);
	mono_add_internal_call("UnityEngine.Time::get_unscaledTime",(void*) UnityEngine_Time_get_unscaledTime);
	mono_add_internal_call("UnityEngine.Time::get_unscaledDeltaTime",(void*) UnityEngine_Time_get_unscaledDeltaTime);
	mono_add_internal_call("UnityEngine.Time::get_fixedDeltaTime",(void*) UnityEngine_Time_get_fixedDeltaTime);
	mono_add_internal_call("UnityEngine.Time::get_maximumDeltaTime",(void*) UnityEngine_Time_get_maximumDeltaTime);
	mono_add_internal_call("UnityEngine.Time::get_timeScale",(void*) UnityEngine_Time_get_timeScale);
	mono_add_internal_call("UnityEngine.Time::set_timeScale",(void*) UnityEngine_Time_set_timeScale);
	mono_add_internal_call("UnityEngine.Time::get_frameCount",(void*) UnityEngine_Time_get_frameCount);
	mono_add_internal_call("UnityEngine.Time::get_realtimeSinceStartup",(void*) UnityEngine_Time_get_realtimeSinceStartup);
	mono_add_internal_call("UnityEngine.Time::set_captureDeltaTime",(void*) UnityEngine_Time_set_captureDeltaTime);
	mono_add_internal_call("UnityEngine.TouchScreenKeyboard::get_text",(void*) UnityEngine_TouchScreenKeyboard_get_text);
	mono_add_internal_call("UnityEngine.TouchScreenKeyboard::set_text",(void*) UnityEngine_TouchScreenKeyboard_set_text);
	mono_add_internal_call("UnityEngine.TouchScreenKeyboard::set_hideInput",(void*) UnityEngine_TouchScreenKeyboard_set_hideInput);
	mono_add_internal_call("UnityEngine.TouchScreenKeyboard::get_active",(void*) UnityEngine_TouchScreenKeyboard_get_active_1);
	mono_add_internal_call("UnityEngine.TouchScreenKeyboard::set_active",(void*) UnityEngine_TouchScreenKeyboard_set_active);
	mono_add_internal_call("UnityEngine.TouchScreenKeyboard::get_status",(void*) UnityEngine_TouchScreenKeyboard_get_status);
	mono_add_internal_call("UnityEngine.TouchScreenKeyboard::set_characterLimit",(void*) UnityEngine_TouchScreenKeyboard_set_characterLimit);
	mono_add_internal_call("UnityEngine.TouchScreenKeyboard::get_canGetSelection",(void*) UnityEngine_TouchScreenKeyboard_get_canGetSelection);
	mono_add_internal_call("UnityEngine.TouchScreenKeyboard::get_canSetSelection",(void*) UnityEngine_TouchScreenKeyboard_get_canSetSelection);
	mono_add_internal_call("UnityEngine.SpriteRenderer::set_sprite",(void*) UnityEngine_SpriteRenderer_set_sprite);
	mono_add_internal_call("UnityEngine.Sprite::get_texture",(void*) UnityEngine_Sprite_get_texture);
	mono_add_internal_call("UnityEngine.Sprite::get_pixelsPerUnit",(void*) UnityEngine_Sprite_get_pixelsPerUnit);
	mono_add_internal_call("UnityEngine.Sprite::get_associatedAlphaSplitTexture",(void*) UnityEngine_Sprite_get_associatedAlphaSplitTexture);
	mono_add_internal_call("UnityEngine.Sprite::get_vertices",(void*) UnityEngine_Sprite_get_vertices);
	mono_add_internal_call("UnityEngine.Sprite::get_triangles",(void*) UnityEngine_Sprite_get_triangles);
	mono_add_internal_call("UnityEngine.Sprite::get_uv",(void*) UnityEngine_Sprite_get_uv);
	mono_add_internal_call("UnityEngine.Sprite::GetInnerUVs_Injected",(void*) UnityEngine_Sprite_GetInnerUVs_Injected);
	mono_add_internal_call("UnityEngine.Sprite::GetOuterUVs_Injected",(void*) UnityEngine_Sprite_GetOuterUVs_Injected);
	mono_add_internal_call("UnityEngine.Sprite::GetPadding_Injected",(void*) UnityEngine_Sprite_GetPadding_Injected);
	mono_add_internal_call("UnityEngine.Playables.PlayableGraph::IsValid_Injected",(void*) UnityEngine_Playables_PlayableGraph_IsValid_Injected);
	mono_add_internal_call("UnityEngine.Playables.PlayableGraph::Stop_Injected",(void*) UnityEngine_Playables_PlayableGraph_Stop_Injected);
	mono_add_internal_call("UnityEngine.Playables.PlayableGraph::GetPlayableCount_Injected",(void*) UnityEngine_Playables_PlayableGraph_GetPlayableCount_Injected);
	mono_add_internal_call("UnityEngine.Playables.PlayableGraph::CreatePlayableHandle_Injected",(void*) UnityEngine_Playables_PlayableGraph_CreatePlayableHandle_Injected);
	mono_add_internal_call("UnityEngine.Playables.PlayableGraph::CreateScriptOutputInternal_Injected",(void*) UnityEngine_Playables_PlayableGraph_CreateScriptOutputInternal_Injected);
	mono_add_internal_call("UnityEngine.Playables.PlayableGraph::GetRootPlayableInternal_Injected",(void*) UnityEngine_Playables_PlayableGraph_GetRootPlayableInternal_Injected);
	mono_add_internal_call("UnityEngine.Playables.PlayableGraph::ConnectInternal_Injected",(void*) UnityEngine_Playables_PlayableGraph_ConnectInternal_Injected);
	mono_add_internal_call("UnityEngine.Playables.PlayableGraph::DestroyPlayableInternal_Injected",(void*) UnityEngine_Playables_PlayableGraph_DestroyPlayableInternal_Injected);
	mono_add_internal_call("UnityEngine.Playables.PlayableHandle::IsNull_Injected",(void*) UnityEngine_Playables_PlayableHandle_IsNull_Injected);
	mono_add_internal_call("UnityEngine.Playables.PlayableHandle::IsValid_Injected",(void*) UnityEngine_Playables_PlayableHandle_IsValid_Injected_1);
	mono_add_internal_call("UnityEngine.Playables.PlayableHandle::GetPlayableType_Injected",(void*) UnityEngine_Playables_PlayableHandle_GetPlayableType_Injected);
	mono_add_internal_call("UnityEngine.Playables.PlayableHandle::GetJobType_Injected",(void*) UnityEngine_Playables_PlayableHandle_GetJobType_Injected);
	mono_add_internal_call("UnityEngine.Playables.PlayableHandle::SetScriptInstance_Injected",(void*) UnityEngine_Playables_PlayableHandle_SetScriptInstance_Injected);
	mono_add_internal_call("UnityEngine.Playables.PlayableHandle::CanChangeInputs_Injected",(void*) UnityEngine_Playables_PlayableHandle_CanChangeInputs_Injected);
	mono_add_internal_call("UnityEngine.Playables.PlayableHandle::CanSetWeights_Injected",(void*) UnityEngine_Playables_PlayableHandle_CanSetWeights_Injected);
	mono_add_internal_call("UnityEngine.Playables.PlayableHandle::CanDestroy_Injected",(void*) UnityEngine_Playables_PlayableHandle_CanDestroy_Injected);
	mono_add_internal_call("UnityEngine.Playables.PlayableHandle::GetPlayState_Injected",(void*) UnityEngine_Playables_PlayableHandle_GetPlayState_Injected);
	mono_add_internal_call("UnityEngine.Playables.PlayableHandle::Play_Injected",(void*) UnityEngine_Playables_PlayableHandle_Play_Injected);
	mono_add_internal_call("UnityEngine.Playables.PlayableHandle::Pause_Injected",(void*) UnityEngine_Playables_PlayableHandle_Pause_Injected);
	mono_add_internal_call("UnityEngine.Playables.PlayableHandle::GetSpeed_Injected",(void*) UnityEngine_Playables_PlayableHandle_GetSpeed_Injected);
	mono_add_internal_call("UnityEngine.Playables.PlayableHandle::SetSpeed_Injected",(void*) UnityEngine_Playables_PlayableHandle_SetSpeed_Injected);
	mono_add_internal_call("UnityEngine.Playables.PlayableHandle::GetTime_Injected",(void*) UnityEngine_Playables_PlayableHandle_GetTime_Injected);
	mono_add_internal_call("UnityEngine.Playables.PlayableHandle::SetTime_Injected",(void*) UnityEngine_Playables_PlayableHandle_SetTime_Injected);
	mono_add_internal_call("UnityEngine.Playables.PlayableHandle::IsDone_Injected",(void*) UnityEngine_Playables_PlayableHandle_IsDone_Injected);
	mono_add_internal_call("UnityEngine.Playables.PlayableHandle::SetDone_Injected",(void*) UnityEngine_Playables_PlayableHandle_SetDone_Injected);
	mono_add_internal_call("UnityEngine.Playables.PlayableHandle::GetDuration_Injected",(void*) UnityEngine_Playables_PlayableHandle_GetDuration_Injected);
	mono_add_internal_call("UnityEngine.Playables.PlayableHandle::SetDuration_Injected",(void*) UnityEngine_Playables_PlayableHandle_SetDuration_Injected);
	mono_add_internal_call("UnityEngine.Playables.PlayableHandle::GetPropagateSetTime_Injected",(void*) UnityEngine_Playables_PlayableHandle_GetPropagateSetTime_Injected);
	mono_add_internal_call("UnityEngine.Playables.PlayableHandle::SetPropagateSetTime_Injected",(void*) UnityEngine_Playables_PlayableHandle_SetPropagateSetTime_Injected);
	mono_add_internal_call("UnityEngine.Playables.PlayableHandle::GetGraph_Injected",(void*) UnityEngine_Playables_PlayableHandle_GetGraph_Injected);
	mono_add_internal_call("UnityEngine.Playables.PlayableHandle::GetInputCount_Injected",(void*) UnityEngine_Playables_PlayableHandle_GetInputCount_Injected);
	mono_add_internal_call("UnityEngine.Playables.PlayableHandle::SetInputCount_Injected",(void*) UnityEngine_Playables_PlayableHandle_SetInputCount_Injected);
	mono_add_internal_call("UnityEngine.Playables.PlayableHandle::GetOutputCount_Injected",(void*) UnityEngine_Playables_PlayableHandle_GetOutputCount_Injected);
	mono_add_internal_call("UnityEngine.Playables.PlayableHandle::SetOutputCount_Injected",(void*) UnityEngine_Playables_PlayableHandle_SetOutputCount_Injected);
	mono_add_internal_call("UnityEngine.Playables.PlayableHandle::SetInputWeight_Injected",(void*) UnityEngine_Playables_PlayableHandle_SetInputWeight_Injected);
	mono_add_internal_call("UnityEngine.Playables.PlayableHandle::SetDelay_Injected",(void*) UnityEngine_Playables_PlayableHandle_SetDelay_Injected);
	mono_add_internal_call("UnityEngine.Playables.PlayableHandle::GetDelay_Injected",(void*) UnityEngine_Playables_PlayableHandle_GetDelay_Injected);
	mono_add_internal_call("UnityEngine.Playables.PlayableHandle::IsDelayed_Injected",(void*) UnityEngine_Playables_PlayableHandle_IsDelayed_Injected);
	mono_add_internal_call("UnityEngine.Playables.PlayableHandle::GetPreviousTime_Injected",(void*) UnityEngine_Playables_PlayableHandle_GetPreviousTime_Injected);
	mono_add_internal_call("UnityEngine.Playables.PlayableHandle::SetLeadTime_Injected",(void*) UnityEngine_Playables_PlayableHandle_SetLeadTime_Injected);
	mono_add_internal_call("UnityEngine.Playables.PlayableHandle::GetLeadTime_Injected",(void*) UnityEngine_Playables_PlayableHandle_GetLeadTime_Injected);
	mono_add_internal_call("UnityEngine.Playables.PlayableHandle::GetTraversalMode_Injected",(void*) UnityEngine_Playables_PlayableHandle_GetTraversalMode_Injected);
	mono_add_internal_call("UnityEngine.Playables.PlayableHandle::SetTraversalMode_Injected",(void*) UnityEngine_Playables_PlayableHandle_SetTraversalMode_Injected);
	mono_add_internal_call("UnityEngine.Playables.PlayableHandle::GetJobData_Injected",(void*) UnityEngine_Playables_PlayableHandle_GetJobData_Injected);
	mono_add_internal_call("UnityEngine.Playables.PlayableHandle::GetTimeWrapMode_Injected",(void*) UnityEngine_Playables_PlayableHandle_GetTimeWrapMode_Injected);
	mono_add_internal_call("UnityEngine.Playables.PlayableHandle::SetTimeWrapMode_Injected",(void*) UnityEngine_Playables_PlayableHandle_SetTimeWrapMode_Injected);
	mono_add_internal_call("UnityEngine.Playables.PlayableHandle::GetScriptInstance_Injected",(void*) UnityEngine_Playables_PlayableHandle_GetScriptInstance_Injected);
	mono_add_internal_call("UnityEngine.Playables.PlayableHandle::GetInputHandle_Injected",(void*) UnityEngine_Playables_PlayableHandle_GetInputHandle_Injected);
	mono_add_internal_call("UnityEngine.Playables.PlayableHandle::GetOutputHandle_Injected",(void*) UnityEngine_Playables_PlayableHandle_GetOutputHandle_Injected);
	mono_add_internal_call("UnityEngine.Playables.PlayableHandle::SetInputWeightFromIndex_Injected",(void*) UnityEngine_Playables_PlayableHandle_SetInputWeightFromIndex_Injected);
	mono_add_internal_call("UnityEngine.Playables.PlayableHandle::GetInputWeightFromIndex_Injected",(void*) UnityEngine_Playables_PlayableHandle_GetInputWeightFromIndex_Injected);
	mono_add_internal_call("UnityEngine.Playables.PlayableOutputHandle::IsNull_Injected",(void*) UnityEngine_Playables_PlayableOutputHandle_IsNull_Injected_1);
	mono_add_internal_call("UnityEngine.Playables.PlayableOutputHandle::IsValid_Injected",(void*) UnityEngine_Playables_PlayableOutputHandle_IsValid_Injected_2);
	mono_add_internal_call("UnityEngine.Playables.PlayableOutputHandle::GetPlayableOutputType_Injected",(void*) UnityEngine_Playables_PlayableOutputHandle_GetPlayableOutputType_Injected);
	mono_add_internal_call("UnityEngine.Playables.PlayableOutputHandle::GetReferenceObject_Injected",(void*) UnityEngine_Playables_PlayableOutputHandle_GetReferenceObject_Injected);
	mono_add_internal_call("UnityEngine.Playables.PlayableOutputHandle::SetReferenceObject_Injected",(void*) UnityEngine_Playables_PlayableOutputHandle_SetReferenceObject_Injected);
	mono_add_internal_call("UnityEngine.Playables.PlayableOutputHandle::GetUserData_Injected",(void*) UnityEngine_Playables_PlayableOutputHandle_GetUserData_Injected);
	mono_add_internal_call("UnityEngine.Playables.PlayableOutputHandle::SetUserData_Injected",(void*) UnityEngine_Playables_PlayableOutputHandle_SetUserData_Injected);
	mono_add_internal_call("UnityEngine.Playables.PlayableOutputHandle::GetSourcePlayable_Injected",(void*) UnityEngine_Playables_PlayableOutputHandle_GetSourcePlayable_Injected);
	mono_add_internal_call("UnityEngine.Playables.PlayableOutputHandle::SetSourcePlayable_Injected",(void*) UnityEngine_Playables_PlayableOutputHandle_SetSourcePlayable_Injected);
	mono_add_internal_call("UnityEngine.Playables.PlayableOutputHandle::GetSourceOutputPort_Injected",(void*) UnityEngine_Playables_PlayableOutputHandle_GetSourceOutputPort_Injected);
	mono_add_internal_call("UnityEngine.Playables.PlayableOutputHandle::GetWeight_Injected",(void*) UnityEngine_Playables_PlayableOutputHandle_GetWeight_Injected);
	mono_add_internal_call("UnityEngine.Playables.PlayableOutputHandle::SetWeight_Injected",(void*) UnityEngine_Playables_PlayableOutputHandle_SetWeight_Injected);
	mono_add_internal_call("UnityEngine.Playables.PlayableOutputHandle::PushNotification_Injected",(void*) UnityEngine_Playables_PlayableOutputHandle_PushNotification_Injected);
	mono_add_internal_call("UnityEngine.Playables.PlayableOutputHandle::GetNotificationReceivers_Injected",(void*) UnityEngine_Playables_PlayableOutputHandle_GetNotificationReceivers_Injected);
	mono_add_internal_call("UnityEngine.Playables.PlayableOutputHandle::AddNotificationReceiver_Injected",(void*) UnityEngine_Playables_PlayableOutputHandle_AddNotificationReceiver_Injected);
	mono_add_internal_call("UnityEngine.Playables.PlayableOutputHandle::RemoveNotificationReceiver_Injected",(void*) UnityEngine_Playables_PlayableOutputHandle_RemoveNotificationReceiver_Injected);
	mono_add_internal_call("UnityEngine.SceneManagement.Scene::IsValidInternal",(void*) UnityEngine_SceneManagement_Scene_IsValidInternal);
	mono_add_internal_call("UnityEngine.SceneManagement.Scene::GetIsLoadedInternal",(void*) UnityEngine_SceneManagement_Scene_GetIsLoadedInternal);
	mono_add_internal_call("UnityEngine.SceneManagement.Scene::GetRootCountInternal",(void*) UnityEngine_SceneManagement_Scene_GetRootCountInternal);
	mono_add_internal_call("UnityEngine.SceneManagement.Scene::GetRootGameObjectsInternal",(void*) UnityEngine_SceneManagement_Scene_GetRootGameObjectsInternal);
	mono_add_internal_call("UnityEngine.SceneManagement.SceneManager::get_sceneCount",(void*) UnityEngine_SceneManagement_SceneManager_get_sceneCount);
	mono_add_internal_call("UnityEngine.SceneManagement.SceneManager::GetActiveScene_Injected",(void*) UnityEngine_SceneManagement_SceneManager_GetActiveScene_Injected);
	mono_add_internal_call("UnityEngine.SceneManagement.SceneManager::GetSceneByName_Injected",(void*) UnityEngine_SceneManagement_SceneManager_GetSceneByName_Injected);
	mono_add_internal_call("UnityEngine.SceneManagement.SceneManager::GetSceneAt_Injected",(void*) UnityEngine_SceneManagement_SceneManager_GetSceneAt_Injected);
	mono_add_internal_call("UnityEngine.Scripting.GarbageCollector::get_isIncremental",(void*) UnityEngine_Scripting_GarbageCollector_get_isIncremental);
	mono_add_internal_call("UnityEngine.Scripting.GarbageCollector::get_incrementalTimeSliceNanoseconds",(void*) UnityEngine_Scripting_GarbageCollector_get_incrementalTimeSliceNanoseconds);
	mono_add_internal_call("UnityEngine.Scripting.GarbageCollector::set_incrementalTimeSliceNanoseconds",(void*) UnityEngine_Scripting_GarbageCollector_set_incrementalTimeSliceNanoseconds);
	mono_add_internal_call("UnityEngine.Scripting.GarbageCollector::CollectIncremental",(void*) UnityEngine_Scripting_GarbageCollector_CollectIncremental);
	mono_add_internal_call("UnityEngine.U2D.SpriteAtlas::CanBindTo",(void*) UnityEngine_U2D_SpriteAtlas_CanBindTo);
	mono_add_internal_call("UnityEngine.Rendering.GraphicsSettings::get_lightsUseLinearIntensity",(void*) UnityEngine_Rendering_GraphicsSettings_get_lightsUseLinearIntensity);
	mono_add_internal_call("UnityEngine.Rendering.ScriptableRenderContext::GetCameras_Internal_Injected",(void*) UnityEngine_Rendering_ScriptableRenderContext_GetCameras_Internal_Injected);
	mono_add_internal_call("UnityEngine.Experimental.Rendering.GraphicsFormatUtility::GetGraphicsFormat_Native_TextureFormat",(void*) UnityEngine_Experimental_Rendering_GraphicsFormatUtility_GetGraphicsFormat_Native_TextureFormat);
	mono_add_internal_call("UnityEngine.Experimental.Rendering.GraphicsFormatUtility::GetGraphicsFormat_Native_RenderTextureFormat",(void*) UnityEngine_Experimental_Rendering_GraphicsFormatUtility_GetGraphicsFormat_Native_RenderTextureFormat);
	mono_add_internal_call("UnityEngine.Experimental.Rendering.GraphicsFormatUtility::IsSRGBFormat",(void*) UnityEngine_Experimental_Rendering_GraphicsFormatUtility_IsSRGBFormat);
	mono_add_internal_call("UnityEngine.Experimental.Rendering.GraphicsFormatUtility::GetRenderTextureFormat",(void*) UnityEngine_Experimental_Rendering_GraphicsFormatUtility_GetRenderTextureFormat);
	mono_add_internal_call("Unity.Jobs.JobHandle::ScheduleBatchedJobs",(void*) Unity_Jobs_JobHandle_ScheduleBatchedJobs);
	mono_add_internal_call("UnityEngine.Playables.PlayableDirector::set_time",(void*) UnityEngine_Playables_PlayableDirector_set_time_2);
	mono_add_internal_call("UnityEngine.Playables.PlayableDirector::Evaluate",(void*) UnityEngine_Playables_PlayableDirector_Evaluate_1);
	mono_add_internal_call("UnityEngine.Playables.PlayableDirector::Play",(void*) UnityEngine_Playables_PlayableDirector_Play_3);
	mono_add_internal_call("UnityEngine.Playables.PlayableDirector::Stop",(void*) UnityEngine_Playables_PlayableDirector_Stop_1);
	mono_add_internal_call("UnityEngine.Playables.PlayableDirector::Pause",(void*) UnityEngine_Playables_PlayableDirector_Pause_1);
	mono_add_internal_call("UnityEngine.Playables.PlayableDirector::Resume",(void*) UnityEngine_Playables_PlayableDirector_Resume);
	mono_add_internal_call("UnityEngine.Playables.PlayableDirector::GetGenericBinding",(void*) UnityEngine_Playables_PlayableDirector_GetGenericBinding);
	mono_add_internal_call("UnityEngine.ImageConversion::EncodeToPNG",(void*) UnityEngine_ImageConversion_EncodeToPNG);
	mono_add_internal_call("UnityEngine.ImageConversion::EncodeToJPG",(void*) UnityEngine_ImageConversion_EncodeToJPG);
	mono_add_internal_call("UnityEngine.ImageConversion::LoadImage",(void*) UnityEngine_ImageConversion_LoadImage);
	mono_add_internal_call("UnityEngine.Event::get_rawType",(void*) UnityEngine_Event_get_rawType);
	mono_add_internal_call("UnityEngine.Event::get_pointerType",(void*) UnityEngine_Event_get_pointerType);
	mono_add_internal_call("UnityEngine.Event::get_button",(void*) UnityEngine_Event_get_button);
	mono_add_internal_call("UnityEngine.Event::get_modifiers",(void*) UnityEngine_Event_get_modifiers);
	mono_add_internal_call("UnityEngine.Event::get_pressure",(void*) UnityEngine_Event_get_pressure);
	mono_add_internal_call("UnityEngine.Event::get_clickCount",(void*) UnityEngine_Event_get_clickCount);
	mono_add_internal_call("UnityEngine.Event::get_character",(void*) UnityEngine_Event_get_character);
	mono_add_internal_call("UnityEngine.Event::get_keyCode",(void*) UnityEngine_Event_get_keyCode);
	mono_add_internal_call("UnityEngine.Event::get_displayIndex",(void*) UnityEngine_Event_get_displayIndex);
	mono_add_internal_call("UnityEngine.Event::set_displayIndex",(void*) UnityEngine_Event_set_displayIndex);
	mono_add_internal_call("UnityEngine.Event::get_type",(void*) UnityEngine_Event_get_type_1);
	mono_add_internal_call("UnityEngine.Event::set_type",(void*) UnityEngine_Event_set_type);
	mono_add_internal_call("UnityEngine.Event::get_commandName",(void*) UnityEngine_Event_get_commandName);
	mono_add_internal_call("UnityEngine.Event::set_commandName",(void*) UnityEngine_Event_set_commandName);
	mono_add_internal_call("UnityEngine.Event::CopyFromPtr",(void*) UnityEngine_Event_CopyFromPtr);
	mono_add_internal_call("UnityEngine.Event::PopEvent",(void*) UnityEngine_Event_PopEvent);
	mono_add_internal_call("UnityEngine.Event::get_mousePosition_Injected",(void*) UnityEngine_Event_get_mousePosition_Injected);
	mono_add_internal_call("UnityEngine.GUI::get_changed",(void*) UnityEngine_GUI_get_changed);
	mono_add_internal_call("UnityEngine.GUI::set_changed",(void*) UnityEngine_GUI_set_changed);
	mono_add_internal_call("UnityEngine.GUI::get_enabled",(void*) UnityEngine_GUI_get_enabled_2);
	mono_add_internal_call("UnityEngine.GUI::set_enabled",(void*) UnityEngine_GUI_set_enabled_2);
	mono_add_internal_call("UnityEngine.GUIStyle::set_alignment",(void*) UnityEngine_GUIStyle_set_alignment);
	mono_add_internal_call("UnityEngine.GUIStyle::get_fixedWidth",(void*) UnityEngine_GUIStyle_get_fixedWidth);
	mono_add_internal_call("UnityEngine.GUIStyle::get_fixedHeight",(void*) UnityEngine_GUIStyle_get_fixedHeight);
	mono_add_internal_call("UnityEngine.GUIStyle::get_stretchWidth",(void*) UnityEngine_GUIStyle_get_stretchWidth);
	mono_add_internal_call("UnityEngine.GUIStyle::get_stretchHeight",(void*) UnityEngine_GUIStyle_get_stretchHeight);
	mono_add_internal_call("UnityEngine.GUIStyle::set_stretchHeight",(void*) UnityEngine_GUIStyle_set_stretchHeight);
	mono_add_internal_call("UnityEngine.GUIStyle::Internal_Draw_Injected",(void*) UnityEngine_GUIStyle_Internal_Draw_Injected);
	mono_add_internal_call("UnityEngine.GUIStyle::Internal_Draw2_Injected",(void*) UnityEngine_GUIStyle_Internal_Draw2_Injected);
	mono_add_internal_call("UnityEngine.GUIStyle::Internal_CalcSize_Injected",(void*) UnityEngine_GUIStyle_Internal_CalcSize_Injected);
	mono_add_internal_call("UnityEngine.GUIUtility::get_systemCopyBuffer",(void*) UnityEngine_GUIUtility_get_systemCopyBuffer);
	mono_add_internal_call("UnityEngine.GUIUtility::set_systemCopyBuffer",(void*) UnityEngine_GUIUtility_set_systemCopyBuffer);
	mono_add_internal_call("UnityEngine.Input::get_anyKeyDown",(void*) UnityEngine_Input_get_anyKeyDown);
	mono_add_internal_call("UnityEngine.Input::get_inputString",(void*) UnityEngine_Input_get_inputString);
	mono_add_internal_call("UnityEngine.Input::get_imeCompositionMode",(void*) UnityEngine_Input_get_imeCompositionMode);
	mono_add_internal_call("UnityEngine.Input::set_imeCompositionMode",(void*) UnityEngine_Input_set_imeCompositionMode);
	mono_add_internal_call("UnityEngine.Input::get_compositionString",(void*) UnityEngine_Input_get_compositionString);
	mono_add_internal_call("UnityEngine.Input::get_mousePresent",(void*) UnityEngine_Input_get_mousePresent);
	mono_add_internal_call("UnityEngine.Input::get_touchCount",(void*) UnityEngine_Input_get_touchCount);
	mono_add_internal_call("UnityEngine.Input::get_touchSupported",(void*) UnityEngine_Input_get_touchSupported);
	mono_add_internal_call("UnityEngine.Input::set_multiTouchEnabled",(void*) UnityEngine_Input_set_multiTouchEnabled);
	mono_add_internal_call("UnityEngine.Input::GetAxis",(void*) UnityEngine_Input_GetAxis);
	mono_add_internal_call("UnityEngine.Input::GetAxisRaw",(void*) UnityEngine_Input_GetAxisRaw);
	mono_add_internal_call("UnityEngine.Input::GetButtonDown",(void*) UnityEngine_Input_GetButtonDown);
	mono_add_internal_call("UnityEngine.Input::GetMouseButton",(void*) UnityEngine_Input_GetMouseButton);
	mono_add_internal_call("UnityEngine.Input::GetMouseButtonDown",(void*) UnityEngine_Input_GetMouseButtonDown);
	mono_add_internal_call("UnityEngine.Input::GetMouseButtonUp",(void*) UnityEngine_Input_GetMouseButtonUp);
	mono_add_internal_call("UnityEngine.Input::GetTouch_Injected",(void*) UnityEngine_Input_GetTouch_Injected);
	mono_add_internal_call("UnityEngine.Input::GetKeyInt",(void*) UnityEngine_Input_GetKeyInt);
	mono_add_internal_call("UnityEngine.Input::GetKeyUpInt",(void*) UnityEngine_Input_GetKeyUpInt);
	mono_add_internal_call("UnityEngine.Input::GetKeyDownInt",(void*) UnityEngine_Input_GetKeyDownInt);
	mono_add_internal_call("UnityEngine.ParticleSystem::get_particleCount",(void*) UnityEngine_ParticleSystem_get_particleCount);
	mono_add_internal_call("UnityEngine.ParticleSystem::set_time",(void*) UnityEngine_ParticleSystem_set_time_3);
	mono_add_internal_call("UnityEngine.ParticleSystem::EmitOld_Internal",(void*) UnityEngine_ParticleSystem_EmitOld_Internal);
	mono_add_internal_call("UnityEngine.ParticleSystem::SetParticles",(void*) UnityEngine_ParticleSystem_SetParticles);
	mono_add_internal_call("UnityEngine.ParticleSystem::GetParticles",(void*) UnityEngine_ParticleSystem_GetParticles);
	mono_add_internal_call("UnityEngine.ParticleSystem::Simulate",(void*) UnityEngine_ParticleSystem_Simulate);
	mono_add_internal_call("UnityEngine.ParticleSystem::Play",(void*) UnityEngine_ParticleSystem_Play_4);
	mono_add_internal_call("UnityEngine.ParticleSystem::Clear",(void*) UnityEngine_ParticleSystem_Clear);
	mono_add_internal_call("UnityEngine.ParticleSystem::Emit_Internal",(void*) UnityEngine_ParticleSystem_Emit_Internal);
	mono_add_internal_call("UnityEngine.ParticleSystem::Emit_Injected",(void*) UnityEngine_ParticleSystem_Emit_Injected);
	mono_add_internal_call("UnityEngine.ParticleSystemRenderer::get_renderMode",(void*) UnityEngine_ParticleSystemRenderer_get_renderMode);
	mono_add_internal_call("UnityEngine.ParticleSystemRenderer::get_lengthScale",(void*) UnityEngine_ParticleSystemRenderer_get_lengthScale);
	mono_add_internal_call("UnityEngine.ParticleSystemRenderer::set_lengthScale",(void*) UnityEngine_ParticleSystemRenderer_set_lengthScale);
	mono_add_internal_call("UnityEngine.ParticleSystemRenderer::get_velocityScale",(void*) UnityEngine_ParticleSystemRenderer_get_velocityScale);
	mono_add_internal_call("UnityEngine.ParticleSystemRenderer::set_velocityScale",(void*) UnityEngine_ParticleSystemRenderer_set_velocityScale);
	mono_add_internal_call("UnityEngine.ParticleSystemRenderer::GetMeshes",(void*) UnityEngine_ParticleSystemRenderer_GetMeshes);
	mono_add_internal_call("UnityEngine.PhysicsScene2D::Raycast_Internal_Injected",(void*) UnityEngine_PhysicsScene2D_Raycast_Internal_Injected);
	mono_add_internal_call("UnityEngine.PhysicsScene2D::RaycastArray_Internal_Injected",(void*) UnityEngine_PhysicsScene2D_RaycastArray_Internal_Injected);
	mono_add_internal_call("UnityEngine.PhysicsScene2D::RaycastList_Internal_Injected",(void*) UnityEngine_PhysicsScene2D_RaycastList_Internal_Injected);
	mono_add_internal_call("UnityEngine.PhysicsScene2D::CircleCast_Internal_Injected",(void*) UnityEngine_PhysicsScene2D_CircleCast_Internal_Injected);
	mono_add_internal_call("UnityEngine.PhysicsScene2D::GetRayIntersectionArray_Internal_Injected",(void*) UnityEngine_PhysicsScene2D_GetRayIntersectionArray_Internal_Injected);
	mono_add_internal_call("UnityEngine.PhysicsScene2D::OverlapPoint_Internal_Injected",(void*) UnityEngine_PhysicsScene2D_OverlapPoint_Internal_Injected);
	mono_add_internal_call("UnityEngine.Physics2D::get_queriesHitTriggers",(void*) UnityEngine_Physics2D_get_queriesHitTriggers);
	mono_add_internal_call("UnityEngine.Physics2D::IgnoreCollision",(void*) UnityEngine_Physics2D_IgnoreCollision);
	mono_add_internal_call("UnityEngine.Collider2D::set_isTrigger",(void*) UnityEngine_Collider2D_set_isTrigger);
	mono_add_internal_call("UnityEngine.Collider2D::OverlapPoint_Injected",(void*) UnityEngine_Collider2D_OverlapPoint_Injected);
	mono_add_internal_call("UnityEngine.ContactFilter2D::CheckConsistency_Injected",(void*) UnityEngine_ContactFilter2D_CheckConsistency_Injected);
	mono_add_internal_call("UnityEngine.Rigidbody2D::get_mass",(void*) UnityEngine_Rigidbody2D_get_mass);
	mono_add_internal_call("UnityEngine.Rigidbody2D::set_mass",(void*) UnityEngine_Rigidbody2D_set_mass);
	mono_add_internal_call("UnityEngine.Rigidbody2D::set_gravityScale",(void*) UnityEngine_Rigidbody2D_set_gravityScale);
	mono_add_internal_call("UnityEngine.Rigidbody2D::set_bodyType",(void*) UnityEngine_Rigidbody2D_set_bodyType);
	mono_add_internal_call("UnityEngine.Rigidbody2D::MovePosition_Injected",(void*) UnityEngine_Rigidbody2D_MovePosition_Injected);
	mono_add_internal_call("UnityEngine.Rigidbody2D::MoveRotation_Angle",(void*) UnityEngine_Rigidbody2D_MoveRotation_Angle);
	mono_add_internal_call("UnityEngine.CircleCollider2D::set_radius",(void*) UnityEngine_CircleCollider2D_set_radius_1);
	mono_add_internal_call("UnityEngine.PolygonCollider2D::get_pathCount",(void*) UnityEngine_PolygonCollider2D_get_pathCount);
	mono_add_internal_call("UnityEngine.CompositeCollider2D::get_pathCount",(void*) UnityEngine_CompositeCollider2D_get_pathCount_1);
	mono_add_internal_call("UnityEngine.CompositeCollider2D::get_pointCount",(void*) UnityEngine_CompositeCollider2D_get_pointCount);
	mono_add_internal_call("UnityEngine.Joint2D::get_connectedBody",(void*) UnityEngine_Joint2D_get_connectedBody);
	mono_add_internal_call("UnityEngine.Joint2D::set_connectedBody",(void*) UnityEngine_Joint2D_set_connectedBody);
	mono_add_internal_call("UnityEngine.HingeJoint2D::set_useLimits",(void*) UnityEngine_HingeJoint2D_set_useLimits);
	mono_add_internal_call("UnityEngine.Rigidbody::get_mass",(void*) UnityEngine_Rigidbody_get_mass_1);
	mono_add_internal_call("UnityEngine.Rigidbody::set_mass",(void*) UnityEngine_Rigidbody_set_mass_1);
	mono_add_internal_call("UnityEngine.Rigidbody::set_useGravity",(void*) UnityEngine_Rigidbody_set_useGravity);
	mono_add_internal_call("UnityEngine.Rigidbody::set_isKinematic",(void*) UnityEngine_Rigidbody_set_isKinematic);
	mono_add_internal_call("UnityEngine.Rigidbody::set_constraints",(void*) UnityEngine_Rigidbody_set_constraints);
	mono_add_internal_call("UnityEngine.Rigidbody::MovePosition_Injected",(void*) UnityEngine_Rigidbody_MovePosition_Injected_1);
	mono_add_internal_call("UnityEngine.Rigidbody::MoveRotation_Injected",(void*) UnityEngine_Rigidbody_MoveRotation_Injected);
	mono_add_internal_call("UnityEngine.Collider::get_enabled",(void*) UnityEngine_Collider_get_enabled_3);
	mono_add_internal_call("UnityEngine.Collider::set_enabled",(void*) UnityEngine_Collider_set_enabled_3);
	mono_add_internal_call("UnityEngine.Collider::set_isTrigger",(void*) UnityEngine_Collider_set_isTrigger_1);
	mono_add_internal_call("UnityEngine.Collider::ClosestPoint_Injected",(void*) UnityEngine_Collider_ClosestPoint_Injected);
	mono_add_internal_call("UnityEngine.Collider::Raycast_Injected",(void*) UnityEngine_Collider_Raycast_Injected);
	mono_add_internal_call("UnityEngine.SphereCollider::set_radius",(void*) UnityEngine_SphereCollider_set_radius_2);
	mono_add_internal_call("UnityEngine.Joint::get_connectedBody",(void*) UnityEngine_Joint_get_connectedBody_1);
	mono_add_internal_call("UnityEngine.Joint::set_connectedBody",(void*) UnityEngine_Joint_set_connectedBody_1);
	mono_add_internal_call("UnityEngine.Joint::set_enableCollision",(void*) UnityEngine_Joint_set_enableCollision);
	mono_add_internal_call("UnityEngine.HingeJoint::set_useLimits",(void*) UnityEngine_HingeJoint_set_useLimits_1);
	mono_add_internal_call("UnityEngine.PhysicsScene::Internal_RaycastTest_Injected",(void*) UnityEngine_PhysicsScene_Internal_RaycastTest_Injected);
	mono_add_internal_call("UnityEngine.PhysicsScene::Internal_Raycast_Injected",(void*) UnityEngine_PhysicsScene_Internal_Raycast_Injected);
	mono_add_internal_call("UnityEngine.PhysicsScene::Internal_RaycastNonAlloc_Injected",(void*) UnityEngine_PhysicsScene_Internal_RaycastNonAlloc_Injected);
	mono_add_internal_call("UnityEngine.PhysicsScene::Query_SphereCast_Injected",(void*) UnityEngine_PhysicsScene_Query_SphereCast_Injected);
	mono_add_internal_call("UnityEngine.PhysicsScene::Internal_SphereCastNonAlloc_Injected",(void*) UnityEngine_PhysicsScene_Internal_SphereCastNonAlloc_Injected);
	mono_add_internal_call("UnityEngine.PhysicsScene::OverlapSphereNonAlloc_Internal_Injected",(void*) UnityEngine_PhysicsScene_OverlapSphereNonAlloc_Internal_Injected);
	mono_add_internal_call("UnityEngine.Physics::IgnoreCollision",(void*) UnityEngine_Physics_IgnoreCollision_1);
	mono_add_internal_call("UnityEngine.Physics::get_defaultPhysicsScene_Injected",(void*) UnityEngine_Physics_get_defaultPhysicsScene_Injected);
	mono_add_internal_call("UnityEngine.TextGenerator::get_characterCount",(void*) UnityEngine_TextGenerator_get_characterCount);
	mono_add_internal_call("UnityEngine.TextGenerator::get_lineCount",(void*) UnityEngine_TextGenerator_get_lineCount);
	mono_add_internal_call("UnityEngine.TextGenerator::GetCharactersInternal",(void*) UnityEngine_TextGenerator_GetCharactersInternal);
	mono_add_internal_call("UnityEngine.TextGenerator::GetLinesInternal",(void*) UnityEngine_TextGenerator_GetLinesInternal);
	mono_add_internal_call("UnityEngine.TextGenerator::GetVerticesInternal",(void*) UnityEngine_TextGenerator_GetVerticesInternal);
	mono_add_internal_call("UnityEngine.Font::get_material",(void*) UnityEngine_Font_get_material_1);
	mono_add_internal_call("UnityEngine.Font::get_fontNames",(void*) UnityEngine_Font_get_fontNames);
	mono_add_internal_call("UnityEngine.Font::get_dynamic",(void*) UnityEngine_Font_get_dynamic);
	mono_add_internal_call("UnityEngine.Font::get_fontSize",(void*) UnityEngine_Font_get_fontSize);
	mono_add_internal_call("UnityEngine.Font::HasCharacter",(void*) UnityEngine_Font_HasCharacter);
	mono_add_internal_call("UnityEngine.Font::GetCharacterInfo",(void*) UnityEngine_Font_GetCharacterInfo);
	mono_add_internal_call("UnityEngine.Font::RequestCharactersInTexture",(void*) UnityEngine_Font_RequestCharactersInTexture);
	mono_add_internal_call("UnityEngine.Tilemaps.Tilemap::RefreshTile_Injected",(void*) UnityEngine_Tilemaps_Tilemap_RefreshTile_Injected);
	mono_add_internal_call("UnityEngine.CanvasGroup::get_alpha",(void*) UnityEngine_CanvasGroup_get_alpha);
	mono_add_internal_call("UnityEngine.CanvasGroup::set_alpha",(void*) UnityEngine_CanvasGroup_set_alpha);
	mono_add_internal_call("UnityEngine.CanvasGroup::get_interactable",(void*) UnityEngine_CanvasGroup_get_interactable);
	mono_add_internal_call("UnityEngine.CanvasGroup::get_blocksRaycasts",(void*) UnityEngine_CanvasGroup_get_blocksRaycasts);
	mono_add_internal_call("UnityEngine.CanvasGroup::get_ignoreParentGroups",(void*) UnityEngine_CanvasGroup_get_ignoreParentGroups);
	mono_add_internal_call("UnityEngine.CanvasRenderer::set_hasPopInstruction",(void*) UnityEngine_CanvasRenderer_set_hasPopInstruction);
	mono_add_internal_call("UnityEngine.CanvasRenderer::get_materialCount",(void*) UnityEngine_CanvasRenderer_get_materialCount);
	mono_add_internal_call("UnityEngine.CanvasRenderer::set_materialCount",(void*) UnityEngine_CanvasRenderer_set_materialCount);
	mono_add_internal_call("UnityEngine.CanvasRenderer::set_popMaterialCount",(void*) UnityEngine_CanvasRenderer_set_popMaterialCount);
	mono_add_internal_call("UnityEngine.CanvasRenderer::get_absoluteDepth",(void*) UnityEngine_CanvasRenderer_get_absoluteDepth);
	mono_add_internal_call("UnityEngine.CanvasRenderer::get_hasMoved",(void*) UnityEngine_CanvasRenderer_get_hasMoved);
	mono_add_internal_call("UnityEngine.CanvasRenderer::get_cull",(void*) UnityEngine_CanvasRenderer_get_cull);
	mono_add_internal_call("UnityEngine.CanvasRenderer::set_cull",(void*) UnityEngine_CanvasRenderer_set_cull);
	mono_add_internal_call("UnityEngine.CanvasRenderer::SetColor_Injected",(void*) UnityEngine_CanvasRenderer_SetColor_Injected);
	mono_add_internal_call("UnityEngine.CanvasRenderer::GetColor_Injected",(void*) UnityEngine_CanvasRenderer_GetColor_Injected);
	mono_add_internal_call("UnityEngine.CanvasRenderer::EnableRectClipping_Injected",(void*) UnityEngine_CanvasRenderer_EnableRectClipping_Injected);
	mono_add_internal_call("UnityEngine.CanvasRenderer::DisableRectClipping",(void*) UnityEngine_CanvasRenderer_DisableRectClipping);
	mono_add_internal_call("UnityEngine.CanvasRenderer::SetMaterial",(void*) UnityEngine_CanvasRenderer_SetMaterial);
	mono_add_internal_call("UnityEngine.CanvasRenderer::SetPopMaterial",(void*) UnityEngine_CanvasRenderer_SetPopMaterial);
	mono_add_internal_call("UnityEngine.CanvasRenderer::SetTexture",(void*) UnityEngine_CanvasRenderer_SetTexture);
	mono_add_internal_call("UnityEngine.CanvasRenderer::SetAlphaTexture",(void*) UnityEngine_CanvasRenderer_SetAlphaTexture);
	mono_add_internal_call("UnityEngine.CanvasRenderer::SetMesh",(void*) UnityEngine_CanvasRenderer_SetMesh);
	mono_add_internal_call("UnityEngine.CanvasRenderer::Clear",(void*) UnityEngine_CanvasRenderer_Clear_1);
	mono_add_internal_call("UnityEngine.CanvasRenderer::SplitUIVertexStreamsInternal",(void*) UnityEngine_CanvasRenderer_SplitUIVertexStreamsInternal);
	mono_add_internal_call("UnityEngine.CanvasRenderer::SplitIndicesStreamsInternal",(void*) UnityEngine_CanvasRenderer_SplitIndicesStreamsInternal);
	mono_add_internal_call("UnityEngine.CanvasRenderer::CreateUIVertexStreamInternal",(void*) UnityEngine_CanvasRenderer_CreateUIVertexStreamInternal);
	mono_add_internal_call("UnityEngine.RectTransformUtility::PixelAdjustPoint_Injected",(void*) UnityEngine_RectTransformUtility_PixelAdjustPoint_Injected);
	mono_add_internal_call("UnityEngine.RectTransformUtility::PixelAdjustRect_Injected",(void*) UnityEngine_RectTransformUtility_PixelAdjustRect_Injected);
	mono_add_internal_call("UnityEngine.RectTransformUtility::PointInRectangle_Injected",(void*) UnityEngine_RectTransformUtility_PointInRectangle_Injected);
	mono_add_internal_call("UnityEngine.Canvas::get_renderMode",(void*) UnityEngine_Canvas_get_renderMode_1);
	mono_add_internal_call("UnityEngine.Canvas::get_isRootCanvas",(void*) UnityEngine_Canvas_get_isRootCanvas);
	mono_add_internal_call("UnityEngine.Canvas::get_scaleFactor",(void*) UnityEngine_Canvas_get_scaleFactor);
	mono_add_internal_call("UnityEngine.Canvas::set_scaleFactor",(void*) UnityEngine_Canvas_set_scaleFactor);
	mono_add_internal_call("UnityEngine.Canvas::get_referencePixelsPerUnit",(void*) UnityEngine_Canvas_get_referencePixelsPerUnit);
	mono_add_internal_call("UnityEngine.Canvas::set_referencePixelsPerUnit",(void*) UnityEngine_Canvas_set_referencePixelsPerUnit);
	mono_add_internal_call("UnityEngine.Canvas::get_pixelPerfect",(void*) UnityEngine_Canvas_get_pixelPerfect);
	mono_add_internal_call("UnityEngine.Canvas::get_renderOrder",(void*) UnityEngine_Canvas_get_renderOrder);
	mono_add_internal_call("UnityEngine.Canvas::get_overrideSorting",(void*) UnityEngine_Canvas_get_overrideSorting);
	mono_add_internal_call("UnityEngine.Canvas::set_overrideSorting",(void*) UnityEngine_Canvas_set_overrideSorting);
	mono_add_internal_call("UnityEngine.Canvas::get_sortingOrder",(void*) UnityEngine_Canvas_get_sortingOrder_1);
	mono_add_internal_call("UnityEngine.Canvas::set_sortingOrder",(void*) UnityEngine_Canvas_set_sortingOrder_1);
	mono_add_internal_call("UnityEngine.Canvas::get_targetDisplay",(void*) UnityEngine_Canvas_get_targetDisplay_1);
	mono_add_internal_call("UnityEngine.Canvas::get_sortingLayerID",(void*) UnityEngine_Canvas_get_sortingLayerID_1);
	mono_add_internal_call("UnityEngine.Canvas::set_sortingLayerID",(void*) UnityEngine_Canvas_set_sortingLayerID_1);
	mono_add_internal_call("UnityEngine.Canvas::get_rootCanvas",(void*) UnityEngine_Canvas_get_rootCanvas);
	mono_add_internal_call("UnityEngine.Canvas::get_worldCamera",(void*) UnityEngine_Canvas_get_worldCamera);
	mono_add_internal_call("UnityEngine.Canvas::GetDefaultCanvasMaterial",(void*) UnityEngine_Canvas_GetDefaultCanvasMaterial);
	mono_add_internal_call("UnityEngine.Canvas::GetETC1SupportedCanvasMaterial",(void*) UnityEngine_Canvas_GetETC1SupportedCanvasMaterial);
	mono_add_internal_call("UnityEngine.UISystemProfilerApi::BeginSample",(void*) UnityEngine_UISystemProfilerApi_BeginSample);
	mono_add_internal_call("UnityEngine.UISystemProfilerApi::EndSample",(void*) UnityEngine_UISystemProfilerApi_EndSample);
	mono_add_internal_call("UnityEngine.UISystemProfilerApi::AddMarker",(void*) UnityEngine_UISystemProfilerApi_AddMarker);
	mono_add_internal_call("UnityEngine.Networking.UnityWebRequest::get_responseCode",(void*) UnityEngine_Networking_UnityWebRequest_get_responseCode);
	mono_add_internal_call("UnityEngine.Networking.UnityWebRequest::get_isModifiable",(void*) UnityEngine_Networking_UnityWebRequest_get_isModifiable);
	mono_add_internal_call("UnityEngine.Networking.UnityWebRequest::get_result",(void*) UnityEngine_Networking_UnityWebRequest_get_result);
	mono_add_internal_call("UnityEngine.Networking.UnityWebRequest::GetHTTPStatusString",(void*) UnityEngine_Networking_UnityWebRequest_GetHTTPStatusString);
	mono_add_internal_call("UnityEngine.Networking.UnityWebRequest::Abort",(void*) UnityEngine_Networking_UnityWebRequest_Abort);
	mono_add_internal_call("UnityEngine.Networking.UnityWebRequest::GetResponseHeader",(void*) UnityEngine_Networking_UnityWebRequest_GetResponseHeader);
	mono_add_internal_call("UnityEngine.Networking.DownloadHandler::InternalGetByteArray",(void*) UnityEngine_Networking_DownloadHandler_InternalGetByteArray);
}

