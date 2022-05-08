
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
Il2CppObject* UnityEngine_Object_Internal_CloneSingle(Il2CppObject*);
Il2CppObject* UnityEngine_Object_Internal_CloneSingleWithoutAwake(Il2CppObject*);
Il2CppObject* UnityEngine_Object_Internal_CloneSingleWithParent(Il2CppObject* data, Il2CppObject* parent, bool worldPositionStays);
Il2CppObject* UnityEngine_Object_INTERNAL_CALL_Internal_InstantiateSingleWithParent(Il2CppObject* data, Il2CppObject* parent, void* pos, void* rot); //Vector3 pos, Quaternion rot
Il2CppObject* UnityEngine_Object_Internal_InstantiateSingle_Injected(Il2CppObject* data, void* pos, void* rot); //Vector3 pos, Quaternion rot
Il2CppObject* UnityEngine_Object_Internal_InstantiateSingleWithParent_Injected(Il2CppObject* data, Il2CppObject* parent, void* pos, void* rot); //Vector3 pos, Quaternion rot
void UnityEngine_SceneManagement_SceneManager_Internal_SceneLoaded(void* scene, int32_t mode, const MethodInfo* imethod); //Vector3 pos, Quaternion rot

EventMethodDesc instantiate_proxy_methods[10];
void add_object_instantiate_proxy_method()
{
	//il2cpp_get_class_UnityEngine_Object() 获取class会导致SEGV_MAPERR的崩溃，暂时不清楚原因
	//Il2CppClass* klass = il2cpp_get_class_UnityEngine_Object();
	//platform_log("class ptr: %d", klass);
	Il2CppClass* klass = il2cpp_search_class("UnityEngine.CoreModule.dll", "UnityEngine", "Object");
	platform_log("class ptr: %d", klass);
	instantiate_proxy_methods[0].orign = hook_icall_method("UnityEngine.Object::Internal_CloneSingle", (Il2CppMethodPointer)UnityEngine_Object_Internal_CloneSingle);
	instantiate_proxy_methods[1].orign = hook_icall_method("UnityEngine.Object::Internal_CloneSingleWithoutAwake", (Il2CppMethodPointer)UnityEngine_Object_Internal_CloneSingleWithoutAwake);
	instantiate_proxy_methods[2].orign = hook_icall_method("UnityEngine.Object::Internal_CloneSingleWithParent", (Il2CppMethodPointer)UnityEngine_Object_Internal_CloneSingleWithParent);
	//instantiate_proxy_methods[3].orign = hook_method2(klass, "INTERNAL_CALL_Internal_InstantiateSingleWithParent", 4, (Il2CppMethodPointer)UnityEngine_Object_INTERNAL_CALL_Internal_InstantiateSingleWithParent);

	instantiate_proxy_methods[4].orign = hook_icall_method("UnityEngine.Object::Internal_InstantiateSingle_Injected", (Il2CppMethodPointer)UnityEngine_Object_Internal_InstantiateSingle_Injected);
	instantiate_proxy_methods[5].orign = hook_icall_method("UnityEngine.Object::Internal_InstantiateSingleWithParent_Injected", (Il2CppMethodPointer)UnityEngine_Object_Internal_InstantiateSingleWithParent_Injected);


	klass = il2cpp_search_class("UnityEngine.dll", "UnityEngine.SceneManagement", "SceneManager");
	platform_log("class ptr: %d", klass);
	instantiate_proxy_methods[6].orign = hook_method2(klass, "Internal_SceneLoaded", 2, (Il2CppMethodPointer)UnityEngine_SceneManagement_SceneManager_Internal_SceneLoaded);

}

MonoObject* UnityEngine_GameObject_Internal_AddComponentWithType_il2cpp(Il2CppObject* obj, Il2CppReflectionType* type)
{
	typedef Il2CppObject* (*AddComponentWithType) (Il2CppObject*, Il2CppReflectionType*);
	static AddComponentWithType icall;
	if (!icall)
		icall = (AddComponentWithType)il2cpp_resolve_icall("UnityEngine.GameObject::Internal_AddComponentWithType");
	Il2CppObject* res = icall(obj, type);
	return res;
}


void process_proxy_component(Il2CppObject* gameObj)
{
	typedef Il2CppArray* (*ICallMethod) (Il2CppObject* thiz, Il2CppReflectionType* searchType, bool useSearchTypeAsArrayReturnType, bool recursive, bool includeInactive, bool reverse, Il2CppObject* resultList);
	static ICallMethod icall;
	if (!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.GameObject::GetComponentsInternal");

	Il2CppReflectionType* i2searchType = get_monobehaviour_proxy_rtype();
	Il2CppArray* retArr = icall(gameObj, i2searchType, 1, 1, 1, 0, NULL);
	int len = il2cpp_array_length(retArr);
	platform_log("proxy component count: %d", len);
	for (int i = 0; i < len; i++) {
		Il2CppObject* i2obj = il2cpp_array_get(retArr, Il2CppObject*, i);
		//Il2CppObject* go = UnityEngine_Component_get_gameObject(i2obj);
		Il2CppClass* i2class = il2cpp_object_get_class(i2obj);
		platform_log("proxy component class: %s", il2cpp_class_get_name(i2class));
		MonoClass* mclass = get_mono_class(i2class);
		if (mclass == NULL) {
			platform_log("proxy component class not found: %s", il2cpp_class_get_name(i2class));
			continue;
		}
		//添加monobehaviour wrapper
		Il2CppObject* comp = UnityEngine_GameObject_Internal_AddComponentWithType_il2cpp(gameObj, get_monobehaviour_wrapper_rtype());
		//添加mono侧的monobehaviour
		MonoObject* mobj = get_mono_wrapper_object_delay_init(comp, mclass, true);
		//复制数据
		copy_il2cpp_class_data_to_mono(i2obj, mobj);
		//初始化
		call_wrapper_init(comp, mobj);
	}
}

Il2CppObject* UnityEngine_Component_get_gameObject_il2cpp(Il2CppObject* thiz)
{
	typedef Il2CppObject* (*ICallMethod) (Il2CppObject* thiz);
	static ICallMethod icall;
	if (!icall)
		icall = (ICallMethod)il2cpp_resolve_icall("UnityEngine.Component::get_gameObject");
	Il2CppObject* i2res = icall(thiz);
	return i2res;
}

//private static extern UnityEngine.Object Internal_CloneSingle([NotNull("NullExceptionObject")] UnityEngine.Object data);
Il2CppObject* UnityEngine_Object_Internal_CloneSingle(Il2CppObject* data)
{
	const int index = 0;
	typedef Il2CppObject* (*THUNK_METHOD RuntimeMethod) (Il2CppObject* data);
	static RuntimeMethod thunk;
	if (!thunk)
		thunk = instantiate_proxy_methods[index].orign;
	Il2CppObject* ret = thunk(data);
	process_proxy_component(ret);
	return ret;
}

Il2CppObject* UnityEngine_Object_Internal_CloneSingleWithoutAwake(Il2CppObject* data)
{
	const int index = 1;
	typedef Il2CppObject* (*THUNK_METHOD RuntimeMethod) (Il2CppObject* data);
	static RuntimeMethod thunk;
	if (!thunk)
		thunk = instantiate_proxy_methods[index].orign;
	Il2CppObject* ret = thunk(data);
	process_proxy_component(ret);
	return ret;
}

Il2CppObject* UnityEngine_Object_Internal_CloneSingleWithParent(Il2CppObject* data, Il2CppObject* parent, bool worldPositionStays)
{
	const int index = 2;
	typedef Il2CppObject* (*THUNK_METHOD RuntimeMethod) (Il2CppObject* data, Il2CppObject* parent, bool worldPositionStays);
	static RuntimeMethod thunk;
	if (!thunk)
		thunk = instantiate_proxy_methods[index].orign;
	Il2CppObject* ret = thunk(data, parent, worldPositionStays);
	process_proxy_component(ret);
	return ret;
}

Il2CppObject* UnityEngine_Object_INTERNAL_CALL_Internal_InstantiateSingleWithParent(Il2CppObject* data, Il2CppObject* parent, void* pos, void* rot)
{
	const int index = 3;
	typedef Il2CppObject* (*THUNK_METHOD RuntimeMethod) (Il2CppObject* data, Il2CppObject* parent, void* pos, void* rot);
	static RuntimeMethod thunk;
	if (!thunk)
		thunk = instantiate_proxy_methods[index].orign;
	Il2CppObject* ret = thunk(data, parent, pos, rot);
	process_proxy_component(ret);
	return ret;
}

Il2CppObject* UnityEngine_Object_Internal_InstantiateSingle_Injected(Il2CppObject* data, void* pos, void* rot)
{
	const int index = 4;
	typedef Il2CppObject* (*THUNK_METHOD RuntimeMethod) (Il2CppObject* data, void* pos, void* rot);
	static RuntimeMethod thunk;
	if (!thunk)
		thunk = instantiate_proxy_methods[index].orign;
	Il2CppObject* ret = thunk(data, pos, rot);
	process_proxy_component(ret);
	return ret;
}

Il2CppObject* UnityEngine_Object_Internal_InstantiateSingleWithParent_Injected(Il2CppObject* data, Il2CppObject* parent, void* pos, void* rot)
{
	const int index = 5;
	typedef Il2CppObject* (*THUNK_METHOD RuntimeMethod) (Il2CppObject* data, Il2CppObject* parent, void* pos, void* rot);
	static RuntimeMethod thunk;
	if (!thunk)
		thunk = instantiate_proxy_methods[index].orign;
	Il2CppObject* ret = thunk(data, parent, pos, rot);
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