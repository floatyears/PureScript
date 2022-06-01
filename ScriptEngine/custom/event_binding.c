
#include "engine_include.h"
#include "event_binding.h"

void init_event_method(EventMethodDesc* desc, MonoClass *monoklass, Il2CppClass* ilklass, const char* method_name, int param_count, Il2CppMethodPointer hook2)
{
    if(monoklass == NULL || ilklass == NULL)
        return;
	desc->hooked = mono_lookup_method(method_name,monoklass,param_count);
	desc->orign = hook_method2(ilklass, method_name, param_count, hook2);
}

void init_event_gen();
void add_object_instantiate_proxy_method();

void init_event()
{
	init_event_gen();
	add_object_instantiate_proxy_method();
}

//forward declearation
Il2CppObject* UnityEngine_Object_Internal_CloneSingle_hook(Il2CppObject*);
Il2CppObject* UnityEngine_Object_Internal_CloneSingleWithoutAwake_hook(Il2CppObject*);
Il2CppObject* UnityEngine_Object_Internal_CloneSingleWithParent_hook(Il2CppObject* data, Il2CppObject* parent, bool worldPositionStays);
Il2CppObject* UnityEngine_Object_INTERNAL_CALL_Internal_InstantiateSingleWithParent_hook(Il2CppObject* data, Il2CppObject* parent, void* pos, void* rot); //Vector3 pos, Quaternion rot
Il2CppObject* UnityEngine_Object_Internal_InstantiateSingle_Injected_hook(Il2CppObject* data, void* pos, void* rot); //Vector3 pos, Quaternion rot
Il2CppObject* UnityEngine_Object_Internal_InstantiateSingleWithParent_Injected_hook(Il2CppObject* data, Il2CppObject* parent, void* pos, void* rot); //Vector3 pos, Quaternion rot
void UnityEngine_SceneManagement_SceneManager_Internal_SceneLoaded(void* scene, int32_t mode, const MethodInfo* imethod); //Vector3 pos, Quaternion rot

EventMethodDesc instantiate_proxy_methods[10];
void add_object_instantiate_proxy_method()
{
	//il2cpp_get_class_UnityEngine_Object() 获取class会导致SEGV_MAPERR的崩溃，暂时不清楚原因
	//Il2CppClass* klass = il2cpp_get_class_UnityEngine_Object();
	//platform_log("class ptr: %d", klass);
	Il2CppClass* klass = il2cpp_search_class("UnityEngine.CoreModule.dll", "UnityEngine", "Object");
	platform_log("class ptr: %d", klass);
	instantiate_proxy_methods[0].orign = hook_icall_method("UnityEngine.Object::Internal_CloneSingle", (Il2CppMethodPointer)UnityEngine_Object_Internal_CloneSingle_hook);
	instantiate_proxy_methods[1].orign = hook_icall_method("UnityEngine.Object::Internal_CloneSingleWithoutAwake", (Il2CppMethodPointer)UnityEngine_Object_Internal_CloneSingleWithoutAwake_hook);
	instantiate_proxy_methods[2].orign = hook_icall_method("UnityEngine.Object::Internal_CloneSingleWithParent", (Il2CppMethodPointer)UnityEngine_Object_Internal_CloneSingleWithParent_hook);
	//instantiate_proxy_methods[3].orign = hook_method2(klass, "INTERNAL_CALL_Internal_InstantiateSingleWithParent", 4, (Il2CppMethodPointer)UnityEngine_Object_INTERNAL_CALL_Internal_InstantiateSingleWithParent);

	instantiate_proxy_methods[4].orign = hook_icall_method("UnityEngine.Object::Internal_InstantiateSingle_Injected", (Il2CppMethodPointer)UnityEngine_Object_Internal_InstantiateSingle_Injected_hook);
	instantiate_proxy_methods[5].orign = hook_icall_method("UnityEngine.Object::Internal_InstantiateSingleWithParent_Injected", (Il2CppMethodPointer)UnityEngine_Object_Internal_InstantiateSingleWithParent_Injected_hook);


	klass = il2cpp_search_class("UnityEngine.dll", "UnityEngine.SceneManagement", "SceneManager");
	platform_log("class ptr: %d", klass);
	instantiate_proxy_methods[6].orign = hook_method2(klass, "Internal_SceneLoaded", 2, (Il2CppMethodPointer)UnityEngine_SceneManagement_SceneManager_Internal_SceneLoaded);

}

//private static extern UnityEngine.Object Internal_CloneSingle([NotNull("NullExceptionObject")] UnityEngine.Object data);
Il2CppObject* UnityEngine_Object_Internal_CloneSingle_hook(Il2CppObject* data)
{
	const int index = 0;
	typedef Il2CppObject* (*THUNK_METHOD RuntimeMethod) (Il2CppObject* data);
	static RuntimeMethod thunk;
	if (!thunk)
		thunk = instantiate_proxy_methods[index].orign;
	Il2CppObject* ret = thunk(data);
	platform_log("UnityEngine_Object_Internal_CloneSingle_hook: %s", il2cpp_class_get_name(il2cpp_object_get_class(ret)));
	process_proxy_component(ret);
	return ret;
}

Il2CppObject* UnityEngine_Object_Internal_CloneSingleWithoutAwake_hook(Il2CppObject* data)
{
	const int index = 1;
	typedef Il2CppObject* (*THUNK_METHOD RuntimeMethod) (Il2CppObject* data);
	static RuntimeMethod thunk;
	if (!thunk)
		thunk = instantiate_proxy_methods[index].orign;
	Il2CppObject* ret = thunk(data);
	platform_log("UnityEngine_Object_Internal_CloneSingleWithoutAwake_hook: %s", il2cpp_class_get_name(il2cpp_object_get_class(ret)));
	process_proxy_component(ret);
	return ret;
}

Il2CppObject* UnityEngine_Object_Internal_CloneSingleWithParent_hook(Il2CppObject* data, Il2CppObject* parent, bool worldPositionStays)
{
	const int index = 2;
	typedef Il2CppObject* (*THUNK_METHOD RuntimeMethod) (Il2CppObject* data, Il2CppObject* parent, bool worldPositionStays);
	static RuntimeMethod thunk;
	if (!thunk)
		thunk = instantiate_proxy_methods[index].orign;
	Il2CppObject* ret = thunk(data, parent, worldPositionStays);
	platform_log("UnityEngine_Object_Internal_CloneSingleWithParent_hook: %s", il2cpp_class_get_name(il2cpp_object_get_class(ret)));
	process_proxy_component(ret);
	return ret;
}

Il2CppObject* UnityEngine_Object_INTERNAL_CALL_Internal_InstantiateSingleWithParent_hook(Il2CppObject* data, Il2CppObject* parent, void* pos, void* rot)
{
	const int index = 3;
	typedef Il2CppObject* (*THUNK_METHOD RuntimeMethod) (Il2CppObject* data, Il2CppObject* parent, void* pos, void* rot);
	static RuntimeMethod thunk;
	if (!thunk)
		thunk = instantiate_proxy_methods[index].orign;
	Il2CppObject* ret = thunk(data, parent, pos, rot);
	platform_log("UnityEngine_Object_INTERNAL_CALL_Internal_InstantiateSingleWithParent_hook: %s", il2cpp_class_get_name(il2cpp_object_get_class(ret)));
	process_proxy_component(ret);
	return ret;
}

Il2CppObject* UnityEngine_Object_Internal_InstantiateSingle_Injected_hook(Il2CppObject* data, void* pos, void* rot)
{
	const int index = 4;
	typedef Il2CppObject* (*THUNK_METHOD RuntimeMethod) (Il2CppObject* data, void* pos, void* rot);
	static RuntimeMethod thunk;
	if (!thunk)
		thunk = instantiate_proxy_methods[index].orign;
	Il2CppObject* ret = thunk(data, pos, rot);
	platform_log("UnityEngine_Object_Internal_InstantiateSingle_Injected_hook: %s", il2cpp_class_get_name(il2cpp_object_get_class(ret)));
	process_proxy_component(ret);
	return ret;
}

Il2CppObject* UnityEngine_Object_Internal_InstantiateSingleWithParent_Injected_hook(Il2CppObject* data, Il2CppObject* parent, void* pos, void* rot)
{
	const int index = 5;
	typedef Il2CppObject* (*THUNK_METHOD RuntimeMethod) (Il2CppObject* data, Il2CppObject* parent, void* pos, void* rot);
	static RuntimeMethod thunk;
	if (!thunk)
		thunk = instantiate_proxy_methods[index].orign;
	Il2CppObject* ret = thunk(data, parent, pos, rot);
	platform_log("UnityEngine_Object_Internal_InstantiateSingleWithParent_Injected_hook: %s", il2cpp_class_get_name(il2cpp_object_get_class(ret)));
	process_proxy_component(ret);
	return ret;
}

void UnityEngine_SceneManagement_SceneManager_Internal_SceneLoaded(void* scene, int32_t mode, const MethodInfo* imethod)
{
	const int index = 6;
	typedef void (*THUNK_METHOD RuntimeMethod) (void* scene, int32_t mode, MethodInfo* imethod);
	static RuntimeMethod thunk;
	if (!thunk)
		thunk = instantiate_proxy_methods[index].orign;

	typedef int32_t (*ICallMethod1) (int32_t handle);
	static ICallMethod1 icall_roots_count;
	if (!icall_roots_count)
		icall_roots_count = il2cpp_resolve_icall("UnityEngine.SceneManagement.Scene::GetRootCountInternal");

	platform_log("scene loaded handle: %d", scene);
	int32_t handle = (int)scene; //scene这里实际上已经是一个struct了，而不是指针
	int32_t count = icall_roots_count(handle);
	platform_log("scene loaded roots count: %d", count);

	//typedef void (*ICallMethod2) (int32_t handle, Il2CppObject* resultRootList, MethodInfo* imethod);
	//static ICallMethod2 icall_roots;
	//if (!icall_roots)
	//	icall_roots = il2cpp_resolve_icall("UnityEngine.SceneManagement.Scene::GetRootGameObjectsInternal");

	//Il2CppClass* klass = il2cpp_search_class("UnityEngine.dll", "UnityEngine", "GameObject");
	//Il2CppArray* retArr = il2cpp_array_new(klass, count);
	//Il2CppArray** refArg = &retArr;
	//icall_roots(handle, refArg); //传入的参数是List<GameObject>，需要传入指针的指针，这个方式不好处理，换一种方式

	Il2CppClass* klass = il2cpp_search_class("UnityEngine.dll", "UnityEngine.SceneManagement", "Scene");
	typedef Il2CppArray* (*ICallMethod2) (Il2CppObject* scene);
	static ICallMethod2 icall_roots;
	if (!icall_roots)
	{
		Il2CppMethodPointer* method = il2cpp_get_native_method_ptr(klass, "GetRootGameObjects", 0);//
		icall_roots = method;
	}
		 
	Il2CppObject* sceneObj = il2cpp_object_new(klass);
	//platform_log("scene loaded roots count1: %s-%d-%d", il2cpp_class_get_name(klass), il2cpp_class_instance_size(klass), sizeof(Il2CppObject));
	void* field = (char*)sceneObj + sizeof(Il2CppObject);
	il2cpp_gc_wbarrier_set_field(sceneObj, (void**)field, handle);
	platform_log("scene loaded roots count2: %d", * (int*)field);
	Il2CppArray* retArr = icall_roots(sceneObj);

	platform_log("scene loaded roots complete");

	for (int i = 0; i < count; i++)
	{
		Il2CppObject* obj = il2cpp_array_get(retArr, Il2CppObject*, i);
		process_proxy_component(obj);
	}

	thunk(scene, mode, imethod);
}