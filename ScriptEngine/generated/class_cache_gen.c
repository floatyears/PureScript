
#include "class_cache_gen.h"
MonoImage* mono_get_image_mscorlib()
{
	static MonoImage* img;
	if(!img)
		img = mono_get_image("mscorlib.dll");
	return img;
}
MonoImage* mono_get_image_UnityEngine_AnimationModule()
{
	static MonoImage* img;
	if(!img)
		img = mono_get_image("UnityEngine.AnimationModule.dll");
	return img;
}
MonoImage* mono_get_image_UnityEngine_CoreModule()
{
	static MonoImage* img;
	if(!img)
		img = mono_get_image("UnityEngine.CoreModule.dll");
	return img;
}
MonoImage* mono_get_image_UnityEngine_AssetBundleModule()
{
	static MonoImage* img;
	if(!img)
		img = mono_get_image("UnityEngine.AssetBundleModule.dll");
	return img;
}
MonoImage* mono_get_image_UnityEngine_AudioModule()
{
	static MonoImage* img;
	if(!img)
		img = mono_get_image("UnityEngine.AudioModule.dll");
	return img;
}
MonoImage* mono_get_image_UnityEngine_Physics2DModule()
{
	static MonoImage* img;
	if(!img)
		img = mono_get_image("UnityEngine.Physics2DModule.dll");
	return img;
}
MonoImage* mono_get_image_UnityEngine_PhysicsModule()
{
	static MonoImage* img;
	if(!img)
		img = mono_get_image("UnityEngine.PhysicsModule.dll");
	return img;
}
MonoImage* mono_get_image_UnityEngine_UIModule()
{
	static MonoImage* img;
	if(!img)
		img = mono_get_image("UnityEngine.UIModule.dll");
	return img;
}
Il2CppImage* il2cpp_get_image_UnityEngine_AIModule()
{
	static Il2CppImage* img;
	if(!img)
		img = il2cpp_get_image("UnityEngine.AIModule.dll");
	return img;
}
Il2CppImage* il2cpp_get_image_UnityEngine_AnimationModule()
{
	static Il2CppImage* img;
	if(!img)
		img = il2cpp_get_image("UnityEngine.AnimationModule.dll");
	return img;
}
Il2CppImage* il2cpp_get_image_UnityEngine_AssetBundleModule()
{
	static Il2CppImage* img;
	if(!img)
		img = il2cpp_get_image("UnityEngine.AssetBundleModule.dll");
	return img;
}
Il2CppImage* il2cpp_get_image_UnityEngine_AudioModule()
{
	static Il2CppImage* img;
	if(!img)
		img = il2cpp_get_image("UnityEngine.AudioModule.dll");
	return img;
}
Il2CppImage* il2cpp_get_image_UnityEngine_CoreModule()
{
	static Il2CppImage* img;
	if(!img)
		img = il2cpp_get_image("UnityEngine.CoreModule.dll");
	return img;
}
Il2CppImage* il2cpp_get_image_UnityEngine_DirectorModule()
{
	static Il2CppImage* img;
	if(!img)
		img = il2cpp_get_image("UnityEngine.DirectorModule.dll");
	return img;
}
Il2CppImage* il2cpp_get_image_UnityEngine_IMGUIModule()
{
	static Il2CppImage* img;
	if(!img)
		img = il2cpp_get_image("UnityEngine.IMGUIModule.dll");
	return img;
}
Il2CppImage* il2cpp_get_image_UnityEngine_ParticleSystemModule()
{
	static Il2CppImage* img;
	if(!img)
		img = il2cpp_get_image("UnityEngine.ParticleSystemModule.dll");
	return img;
}
Il2CppImage* il2cpp_get_image_UnityEngine_Physics2DModule()
{
	static Il2CppImage* img;
	if(!img)
		img = il2cpp_get_image("UnityEngine.Physics2DModule.dll");
	return img;
}
Il2CppImage* il2cpp_get_image_UnityEngine_PhysicsModule()
{
	static Il2CppImage* img;
	if(!img)
		img = il2cpp_get_image("UnityEngine.PhysicsModule.dll");
	return img;
}
Il2CppImage* il2cpp_get_image_UnityEngine_TextRenderingModule()
{
	static Il2CppImage* img;
	if(!img)
		img = il2cpp_get_image("UnityEngine.TextRenderingModule.dll");
	return img;
}
Il2CppImage* il2cpp_get_image_UnityEngine_TilemapModule()
{
	static Il2CppImage* img;
	if(!img)
		img = il2cpp_get_image("UnityEngine.TilemapModule.dll");
	return img;
}
Il2CppImage* il2cpp_get_image_UnityEngine_UIModule()
{
	static Il2CppImage* img;
	if(!img)
		img = il2cpp_get_image("UnityEngine.UIModule.dll");
	return img;
}
Il2CppImage* il2cpp_get_image_UnityEngine_UnityWebRequestModule()
{
	static Il2CppImage* img;
	if(!img)
		img = il2cpp_get_image("UnityEngine.UnityWebRequestModule.dll");
	return img;
}
MonoClass* mono_get_class_System_Boolean()
{
	static MonoClass* klass;
	if(!klass)
		klass = mono_get_class(mono_get_image_mscorlib(),"System","Boolean");
	return klass;
}
MonoClass* mono_get_class_System_Byte()
{
	static MonoClass* klass;
	if(!klass)
		klass = mono_get_class(mono_get_image_mscorlib(),"System","Byte");
	return klass;
}
MonoClass* mono_get_class_System_SByte()
{
	static MonoClass* klass;
	if(!klass)
		klass = mono_get_class(mono_get_image_mscorlib(),"System","SByte");
	return klass;
}
MonoClass* mono_get_class_System_Char()
{
	static MonoClass* klass;
	if(!klass)
		klass = mono_get_class(mono_get_image_mscorlib(),"System","Char");
	return klass;
}
MonoClass* mono_get_class_System_Int16()
{
	static MonoClass* klass;
	if(!klass)
		klass = mono_get_class(mono_get_image_mscorlib(),"System","Int16");
	return klass;
}
MonoClass* mono_get_class_System_Int32()
{
	static MonoClass* klass;
	if(!klass)
		klass = mono_get_class(mono_get_image_mscorlib(),"System","Int32");
	return klass;
}
MonoClass* mono_get_class_System_Int64()
{
	static MonoClass* klass;
	if(!klass)
		klass = mono_get_class(mono_get_image_mscorlib(),"System","Int64");
	return klass;
}
MonoClass* mono_get_class_System_Single()
{
	static MonoClass* klass;
	if(!klass)
		klass = mono_get_class(mono_get_image_mscorlib(),"System","Single");
	return klass;
}
MonoClass* mono_get_class_System_Double()
{
	static MonoClass* klass;
	if(!klass)
		klass = mono_get_class(mono_get_image_mscorlib(),"System","Double");
	return klass;
}
MonoClass* mono_get_class_System_IntPtr()
{
	static MonoClass* klass;
	if(!klass)
		klass = mono_get_class(mono_get_image_mscorlib(),"System","IntPtr");
	return klass;
}
MonoClass* mono_get_class_UnityEngine_RuntimeAnimatorController()
{
	static MonoClass* klass;
	if(!klass)
		klass = mono_get_class(mono_get_image_UnityEngine_AnimationModule(),"UnityEngine","RuntimeAnimatorController");
	return klass;
}
MonoClass* mono_get_class_UnityEngine_Avatar()
{
	static MonoClass* klass;
	if(!klass)
		klass = mono_get_class(mono_get_image_UnityEngine_AnimationModule(),"UnityEngine","Avatar");
	return klass;
}
MonoClass* mono_get_class_UnityEngine_AnimationClip()
{
	static MonoClass* klass;
	if(!klass)
		klass = mono_get_class(mono_get_image_UnityEngine_AnimationModule(),"UnityEngine","AnimationClip");
	return klass;
}
MonoClass* mono_get_class_UnityEngine_Object()
{
	static MonoClass* klass;
	if(!klass)
		klass = mono_get_class(mono_get_image_UnityEngine_CoreModule(),"UnityEngine","Object");
	return klass;
}
MonoClass* mono_get_class_UnityEngine_AssetBundle()
{
	static MonoClass* klass;
	if(!klass)
		klass = mono_get_class(mono_get_image_UnityEngine_AssetBundleModule(),"UnityEngine","AssetBundle");
	return klass;
}
MonoClass* mono_get_class_UnityEngine_AssetBundleCreateRequest()
{
	static MonoClass* klass;
	if(!klass)
		klass = mono_get_class(mono_get_image_UnityEngine_AssetBundleModule(),"UnityEngine","AssetBundleCreateRequest");
	return klass;
}
MonoClass* mono_get_class_UnityEngine_AssetBundleRequest()
{
	static MonoClass* klass;
	if(!klass)
		klass = mono_get_class(mono_get_image_UnityEngine_AssetBundleModule(),"UnityEngine","AssetBundleRequest");
	return klass;
}
MonoClass* mono_get_class_UnityEngine_AsyncOperation()
{
	static MonoClass* klass;
	if(!klass)
		klass = mono_get_class(mono_get_image_UnityEngine_CoreModule(),"UnityEngine","AsyncOperation");
	return klass;
}
MonoClass* mono_get_class_UnityEngine_AssetBundleRecompressOperation()
{
	static MonoClass* klass;
	if(!klass)
		klass = mono_get_class(mono_get_image_UnityEngine_AssetBundleModule(),"UnityEngine","AssetBundleRecompressOperation");
	return klass;
}
MonoClass* mono_get_class_UnityEngine_AudioClip()
{
	static MonoClass* klass;
	if(!klass)
		klass = mono_get_class(mono_get_image_UnityEngine_AudioModule(),"UnityEngine","AudioClip");
	return klass;
}
MonoClass* mono_get_class_UnityEngine_RenderTexture()
{
	static MonoClass* klass;
	if(!klass)
		klass = mono_get_class(mono_get_image_UnityEngine_CoreModule(),"UnityEngine","RenderTexture");
	return klass;
}
MonoClass* mono_get_class_UnityEngine_Camera()
{
	static MonoClass* klass;
	if(!klass)
		klass = mono_get_class(mono_get_image_UnityEngine_CoreModule(),"UnityEngine","Camera");
	return klass;
}
MonoClass* mono_get_class_UnityEngine_Transform()
{
	static MonoClass* klass;
	if(!klass)
		klass = mono_get_class(mono_get_image_UnityEngine_CoreModule(),"UnityEngine","Transform");
	return klass;
}
MonoClass* mono_get_class_UnityEngine_GameObject()
{
	static MonoClass* klass;
	if(!klass)
		klass = mono_get_class(mono_get_image_UnityEngine_CoreModule(),"UnityEngine","GameObject");
	return klass;
}
MonoClass* mono_get_class_UnityEngine_Component()
{
	static MonoClass* klass;
	if(!klass)
		klass = mono_get_class(mono_get_image_UnityEngine_CoreModule(),"UnityEngine","Component");
	return klass;
}
MonoClass* mono_get_class_UnityEngine_Shader()
{
	static MonoClass* klass;
	if(!klass)
		klass = mono_get_class(mono_get_image_UnityEngine_CoreModule(),"UnityEngine","Shader");
	return klass;
}
MonoClass* mono_get_class_UnityEngine_Texture()
{
	static MonoClass* klass;
	if(!klass)
		klass = mono_get_class(mono_get_image_UnityEngine_CoreModule(),"UnityEngine","Texture");
	return klass;
}
MonoClass* mono_get_class_UnityEngine_Material()
{
	static MonoClass* klass;
	if(!klass)
		klass = mono_get_class(mono_get_image_UnityEngine_CoreModule(),"UnityEngine","Material");
	return klass;
}
MonoClass* mono_get_class_UnityEngine_Mesh()
{
	static MonoClass* klass;
	if(!klass)
		klass = mono_get_class(mono_get_image_UnityEngine_CoreModule(),"UnityEngine","Mesh");
	return klass;
}
MonoClass* mono_get_class_UnityEngine_Texture2D()
{
	static MonoClass* klass;
	if(!klass)
		klass = mono_get_class(mono_get_image_UnityEngine_CoreModule(),"UnityEngine","Texture2D");
	return klass;
}
MonoClass* mono_get_class_UnityEngine_Coroutine()
{
	static MonoClass* klass;
	if(!klass)
		klass = mono_get_class(mono_get_image_UnityEngine_CoreModule(),"UnityEngine","Coroutine");
	return klass;
}
MonoClass* mono_get_class_UnityEngine_ScriptableObject()
{
	static MonoClass* klass;
	if(!klass)
		klass = mono_get_class(mono_get_image_UnityEngine_CoreModule(),"UnityEngine","ScriptableObject");
	return klass;
}
MonoClass* mono_get_class_System_UInt16()
{
	static MonoClass* klass;
	if(!klass)
		klass = mono_get_class(mono_get_image_mscorlib(),"System","UInt16");
	return klass;
}
MonoClass* mono_get_class_System_Object()
{
	static MonoClass* klass;
	if(!klass)
		klass = mono_get_class(mono_get_image_mscorlib(),"System","Object");
	return klass;
}
MonoClass* mono_get_class_UnityEngine_Playables_INotificationReceiver()
{
	static MonoClass* klass;
	if(!klass)
		klass = mono_get_class(mono_get_image_UnityEngine_CoreModule(),"UnityEngine.Playables","INotificationReceiver");
	return klass;
}
MonoClass* mono_get_class_UnityEngine_Collider2D()
{
	static MonoClass* klass;
	if(!klass)
		klass = mono_get_class(mono_get_image_UnityEngine_Physics2DModule(),"UnityEngine","Collider2D");
	return klass;
}
MonoClass* mono_get_class_UnityEngine_Rigidbody2D()
{
	static MonoClass* klass;
	if(!klass)
		klass = mono_get_class(mono_get_image_UnityEngine_Physics2DModule(),"UnityEngine","Rigidbody2D");
	return klass;
}
MonoClass* mono_get_class_UnityEngine_Rigidbody()
{
	static MonoClass* klass;
	if(!klass)
		klass = mono_get_class(mono_get_image_UnityEngine_PhysicsModule(),"UnityEngine","Rigidbody");
	return klass;
}
MonoClass* mono_get_class_UnityEngine_Canvas()
{
	static MonoClass* klass;
	if(!klass)
		klass = mono_get_class(mono_get_image_UnityEngine_UIModule(),"UnityEngine","Canvas");
	return klass;
}
Il2CppClass* il2cpp_get_class_UnityEngine_AI_NavMeshAgent()
{
	static Il2CppClass* klass;
	if(!klass)
	{
		klass = il2cpp_get_class(il2cpp_get_image_UnityEngine_AIModule(),"UnityEngine.AI","NavMeshAgent");
		if(klass == NULL){ platform_log("il2cpp class not found: %s-%s", "UnityEngine.AI", "NavMeshAgent"); };
	}
	return klass;
}
Il2CppClass* il2cpp_get_class_UnityEngine_Animator()
{
	static Il2CppClass* klass;
	if(!klass)
	{
		klass = il2cpp_get_class(il2cpp_get_image_UnityEngine_AnimationModule(),"UnityEngine","Animator");
		if(klass == NULL){ platform_log("il2cpp class not found: %s-%s", "UnityEngine", "Animator"); };
	}
	return klass;
}
Il2CppClass* il2cpp_get_class_UnityEngine_Animation()
{
	static Il2CppClass* klass;
	if(!klass)
	{
		klass = il2cpp_get_class(il2cpp_get_image_UnityEngine_AnimationModule(),"UnityEngine","Animation");
		if(klass == NULL){ platform_log("il2cpp class not found: %s-%s", "UnityEngine", "Animation"); };
	}
	return klass;
}
Il2CppClass* il2cpp_get_class_UnityEngine_AnimationClip()
{
	static Il2CppClass* klass;
	if(!klass)
	{
		klass = il2cpp_get_class(il2cpp_get_image_UnityEngine_AnimationModule(),"UnityEngine","AnimationClip");
		if(klass == NULL){ platform_log("il2cpp class not found: %s-%s", "UnityEngine", "AnimationClip"); };
	}
	return klass;
}
Il2CppClass* il2cpp_get_class_UnityEngine_Motion()
{
	static Il2CppClass* klass;
	if(!klass)
	{
		klass = il2cpp_get_class(il2cpp_get_image_UnityEngine_AnimationModule(),"UnityEngine","Motion");
		if(klass == NULL){ platform_log("il2cpp class not found: %s-%s", "UnityEngine", "Motion"); };
	}
	return klass;
}
Il2CppClass* il2cpp_get_class_UnityEngine_AnimationState()
{
	static Il2CppClass* klass;
	if(!klass)
	{
		klass = il2cpp_get_class(il2cpp_get_image_UnityEngine_AnimationModule(),"UnityEngine","AnimationState");
		if(klass == NULL){ platform_log("il2cpp class not found: %s-%s", "UnityEngine", "AnimationState"); };
	}
	return klass;
}
Il2CppClass* il2cpp_get_class_UnityEngine_AvatarMask()
{
	static Il2CppClass* klass;
	if(!klass)
	{
		klass = il2cpp_get_class(il2cpp_get_image_UnityEngine_AnimationModule(),"UnityEngine","AvatarMask");
		if(klass == NULL){ platform_log("il2cpp class not found: %s-%s", "UnityEngine", "AvatarMask"); };
	}
	return klass;
}
Il2CppClass* il2cpp_get_class_UnityEngine_AssetBundle()
{
	static Il2CppClass* klass;
	if(!klass)
	{
		klass = il2cpp_get_class(il2cpp_get_image_UnityEngine_AssetBundleModule(),"UnityEngine","AssetBundle");
		if(klass == NULL){ platform_log("il2cpp class not found: %s-%s", "UnityEngine", "AssetBundle"); };
	}
	return klass;
}
Il2CppClass* il2cpp_get_class_UnityEngine_AudioClip()
{
	static Il2CppClass* klass;
	if(!klass)
	{
		klass = il2cpp_get_class(il2cpp_get_image_UnityEngine_AudioModule(),"UnityEngine","AudioClip");
		if(klass == NULL){ platform_log("il2cpp class not found: %s-%s", "UnityEngine", "AudioClip"); };
	}
	return klass;
}
Il2CppClass* il2cpp_get_class_UnityEngine_AudioSource()
{
	static Il2CppClass* klass;
	if(!klass)
	{
		klass = il2cpp_get_class(il2cpp_get_image_UnityEngine_AudioModule(),"UnityEngine","AudioSource");
		if(klass == NULL){ platform_log("il2cpp class not found: %s-%s", "UnityEngine", "AudioSource"); };
	}
	return klass;
}
Il2CppClass* il2cpp_get_class_UnityEngine_AnimationCurve()
{
	static Il2CppClass* klass;
	if(!klass)
	{
		klass = il2cpp_get_class(il2cpp_get_image_UnityEngine_CoreModule(),"UnityEngine","AnimationCurve");
		if(klass == NULL){ platform_log("il2cpp class not found: %s-%s", "UnityEngine", "AnimationCurve"); };
	}
	return klass;
}
Il2CppClass* il2cpp_get_class_UnityEngine_Camera()
{
	static Il2CppClass* klass;
	if(!klass)
	{
		klass = il2cpp_get_class(il2cpp_get_image_UnityEngine_CoreModule(),"UnityEngine","Camera");
		if(klass == NULL){ platform_log("il2cpp class not found: %s-%s", "UnityEngine", "Camera"); };
	}
	return klass;
}
Il2CppClass* il2cpp_get_class_UnityEngine_RenderTexture()
{
	static Il2CppClass* klass;
	if(!klass)
	{
		klass = il2cpp_get_class(il2cpp_get_image_UnityEngine_CoreModule(),"UnityEngine","RenderTexture");
		if(klass == NULL){ platform_log("il2cpp class not found: %s-%s", "UnityEngine", "RenderTexture"); };
	}
	return klass;
}
Il2CppClass* il2cpp_get_class_UnityEngine_Object()
{
	static Il2CppClass* klass;
	if(!klass)
	{
		klass = il2cpp_get_class(il2cpp_get_image_UnityEngine_CoreModule(),"UnityEngine","Object");
		if(klass == NULL){ platform_log("il2cpp class not found: %s-%s", "UnityEngine", "Object"); };
	}
	return klass;
}
Il2CppClass* il2cpp_get_class_UnityEngine_Transform()
{
	static Il2CppClass* klass;
	if(!klass)
	{
		klass = il2cpp_get_class(il2cpp_get_image_UnityEngine_CoreModule(),"UnityEngine","Transform");
		if(klass == NULL){ platform_log("il2cpp class not found: %s-%s", "UnityEngine", "Transform"); };
	}
	return klass;
}
Il2CppClass* il2cpp_get_class_UnityEngine_Component()
{
	static Il2CppClass* klass;
	if(!klass)
	{
		klass = il2cpp_get_class(il2cpp_get_image_UnityEngine_CoreModule(),"UnityEngine","Component");
		if(klass == NULL){ platform_log("il2cpp class not found: %s-%s", "UnityEngine", "Component"); };
	}
	return klass;
}
Il2CppClass* il2cpp_get_class_UnityEngine_GameObject()
{
	static Il2CppClass* klass;
	if(!klass)
	{
		klass = il2cpp_get_class(il2cpp_get_image_UnityEngine_CoreModule(),"UnityEngine","GameObject");
		if(klass == NULL){ platform_log("il2cpp class not found: %s-%s", "UnityEngine", "GameObject"); };
	}
	return klass;
}
Il2CppClass* il2cpp_get_class_UnityEngine_Behaviour()
{
	static Il2CppClass* klass;
	if(!klass)
	{
		klass = il2cpp_get_class(il2cpp_get_image_UnityEngine_CoreModule(),"UnityEngine","Behaviour");
		if(klass == NULL){ platform_log("il2cpp class not found: %s-%s", "UnityEngine", "Behaviour"); };
	}
	return klass;
}
Il2CppClass* il2cpp_get_class_UnityEngine_RectOffset()
{
	static Il2CppClass* klass;
	if(!klass)
	{
		klass = il2cpp_get_class(il2cpp_get_image_UnityEngine_CoreModule(),"UnityEngine","RectOffset");
		if(klass == NULL){ platform_log("il2cpp class not found: %s-%s", "UnityEngine", "RectOffset"); };
	}
	return klass;
}
Il2CppClass* il2cpp_get_class_UnityEngine_Texture()
{
	static Il2CppClass* klass;
	if(!klass)
	{
		klass = il2cpp_get_class(il2cpp_get_image_UnityEngine_CoreModule(),"UnityEngine","Texture");
		if(klass == NULL){ platform_log("il2cpp class not found: %s-%s", "UnityEngine", "Texture"); };
	}
	return klass;
}
Il2CppClass* il2cpp_get_class_UnityEngine_Material()
{
	static Il2CppClass* klass;
	if(!klass)
	{
		klass = il2cpp_get_class(il2cpp_get_image_UnityEngine_CoreModule(),"UnityEngine","Material");
		if(klass == NULL){ platform_log("il2cpp class not found: %s-%s", "UnityEngine", "Material"); };
	}
	return klass;
}
Il2CppClass* il2cpp_get_class_UnityEngine_Mesh()
{
	static Il2CppClass* klass;
	if(!klass)
	{
		klass = il2cpp_get_class(il2cpp_get_image_UnityEngine_CoreModule(),"UnityEngine","Mesh");
		if(klass == NULL){ platform_log("il2cpp class not found: %s-%s", "UnityEngine", "Mesh"); };
	}
	return klass;
}
Il2CppClass* il2cpp_get_class_UnityEngine_Shader()
{
	static Il2CppClass* klass;
	if(!klass)
	{
		klass = il2cpp_get_class(il2cpp_get_image_UnityEngine_CoreModule(),"UnityEngine","Shader");
		if(klass == NULL){ platform_log("il2cpp class not found: %s-%s", "UnityEngine", "Shader"); };
	}
	return klass;
}
Il2CppClass* il2cpp_get_class_UnityEngine_MaterialPropertyBlock()
{
	static Il2CppClass* klass;
	if(!klass)
	{
		klass = il2cpp_get_class(il2cpp_get_image_UnityEngine_CoreModule(),"UnityEngine","MaterialPropertyBlock");
		if(klass == NULL){ platform_log("il2cpp class not found: %s-%s", "UnityEngine", "MaterialPropertyBlock"); };
	}
	return klass;
}
Il2CppClass* il2cpp_get_class_UnityEngine_TrailRenderer()
{
	static Il2CppClass* klass;
	if(!klass)
	{
		klass = il2cpp_get_class(il2cpp_get_image_UnityEngine_CoreModule(),"UnityEngine","TrailRenderer");
		if(klass == NULL){ platform_log("il2cpp class not found: %s-%s", "UnityEngine", "TrailRenderer"); };
	}
	return klass;
}
Il2CppClass* il2cpp_get_class_UnityEngine_LineRenderer()
{
	static Il2CppClass* klass;
	if(!klass)
	{
		klass = il2cpp_get_class(il2cpp_get_image_UnityEngine_CoreModule(),"UnityEngine","LineRenderer");
		if(klass == NULL){ platform_log("il2cpp class not found: %s-%s", "UnityEngine", "LineRenderer"); };
	}
	return klass;
}
Il2CppClass* il2cpp_get_class_UnityEngine_Renderer()
{
	static Il2CppClass* klass;
	if(!klass)
	{
		klass = il2cpp_get_class(il2cpp_get_image_UnityEngine_CoreModule(),"UnityEngine","Renderer");
		if(klass == NULL){ platform_log("il2cpp class not found: %s-%s", "UnityEngine", "Renderer"); };
	}
	return klass;
}
Il2CppClass* il2cpp_get_class_UnityEngine_Projector()
{
	static Il2CppClass* klass;
	if(!klass)
	{
		klass = il2cpp_get_class(il2cpp_get_image_UnityEngine_CoreModule(),"UnityEngine","Projector");
		if(klass == NULL){ platform_log("il2cpp class not found: %s-%s", "UnityEngine", "Projector"); };
	}
	return klass;
}
Il2CppClass* il2cpp_get_class_UnityEngine_Light()
{
	static Il2CppClass* klass;
	if(!klass)
	{
		klass = il2cpp_get_class(il2cpp_get_image_UnityEngine_CoreModule(),"UnityEngine","Light");
		if(klass == NULL){ platform_log("il2cpp class not found: %s-%s", "UnityEngine", "Light"); };
	}
	return klass;
}
Il2CppClass* il2cpp_get_class_UnityEngine_MeshFilter()
{
	static Il2CppClass* klass;
	if(!klass)
	{
		klass = il2cpp_get_class(il2cpp_get_image_UnityEngine_CoreModule(),"UnityEngine","MeshFilter");
		if(klass == NULL){ platform_log("il2cpp class not found: %s-%s", "UnityEngine", "MeshFilter"); };
	}
	return klass;
}
Il2CppClass* il2cpp_get_class_UnityEngine_SkinnedMeshRenderer()
{
	static Il2CppClass* klass;
	if(!klass)
	{
		klass = il2cpp_get_class(il2cpp_get_image_UnityEngine_CoreModule(),"UnityEngine","SkinnedMeshRenderer");
		if(klass == NULL){ platform_log("il2cpp class not found: %s-%s", "UnityEngine", "SkinnedMeshRenderer"); };
	}
	return klass;
}
Il2CppClass* il2cpp_get_class_UnityEngine_Texture2D()
{
	static Il2CppClass* klass;
	if(!klass)
	{
		klass = il2cpp_get_class(il2cpp_get_image_UnityEngine_CoreModule(),"UnityEngine","Texture2D");
		if(klass == NULL){ platform_log("il2cpp class not found: %s-%s", "UnityEngine", "Texture2D"); };
	}
	return klass;
}
Il2CppClass* il2cpp_get_class_UnityEngine_Cubemap()
{
	static Il2CppClass* klass;
	if(!klass)
	{
		klass = il2cpp_get_class(il2cpp_get_image_UnityEngine_CoreModule(),"UnityEngine","Cubemap");
		if(klass == NULL){ platform_log("il2cpp class not found: %s-%s", "UnityEngine", "Cubemap"); };
	}
	return klass;
}
Il2CppClass* il2cpp_get_class_UnityEngine_Texture3D()
{
	static Il2CppClass* klass;
	if(!klass)
	{
		klass = il2cpp_get_class(il2cpp_get_image_UnityEngine_CoreModule(),"UnityEngine","Texture3D");
		if(klass == NULL){ platform_log("il2cpp class not found: %s-%s", "UnityEngine", "Texture3D"); };
	}
	return klass;
}
Il2CppClass* il2cpp_get_class_UnityEngine_Texture2DArray()
{
	static Il2CppClass* klass;
	if(!klass)
	{
		klass = il2cpp_get_class(il2cpp_get_image_UnityEngine_CoreModule(),"UnityEngine","Texture2DArray");
		if(klass == NULL){ platform_log("il2cpp class not found: %s-%s", "UnityEngine", "Texture2DArray"); };
	}
	return klass;
}
Il2CppClass* il2cpp_get_class_UnityEngine_CubemapArray()
{
	static Il2CppClass* klass;
	if(!klass)
	{
		klass = il2cpp_get_class(il2cpp_get_image_UnityEngine_CoreModule(),"UnityEngine","CubemapArray");
		if(klass == NULL){ platform_log("il2cpp class not found: %s-%s", "UnityEngine", "CubemapArray"); };
	}
	return klass;
}
Il2CppClass* il2cpp_get_class_UnityEngine_AsyncOperation()
{
	static Il2CppClass* klass;
	if(!klass)
	{
		klass = il2cpp_get_class(il2cpp_get_image_UnityEngine_CoreModule(),"UnityEngine","AsyncOperation");
		if(klass == NULL){ platform_log("il2cpp class not found: %s-%s", "UnityEngine", "AsyncOperation"); };
	}
	return klass;
}
Il2CppClass* il2cpp_get_class_UnityEngine_MonoBehaviour()
{
	static Il2CppClass* klass;
	if(!klass)
	{
		klass = il2cpp_get_class(il2cpp_get_image_UnityEngine_CoreModule(),"UnityEngine","MonoBehaviour");
		if(klass == NULL){ platform_log("il2cpp class not found: %s-%s", "UnityEngine", "MonoBehaviour"); };
	}
	return klass;
}
Il2CppClass* il2cpp_get_class_UnityEngine_Coroutine()
{
	static Il2CppClass* klass;
	if(!klass)
	{
		klass = il2cpp_get_class(il2cpp_get_image_UnityEngine_CoreModule(),"UnityEngine","Coroutine");
		if(klass == NULL){ platform_log("il2cpp class not found: %s-%s", "UnityEngine", "Coroutine"); };
	}
	return klass;
}
Il2CppClass* il2cpp_get_class_UnityEngine_ScriptableObject()
{
	static Il2CppClass* klass;
	if(!klass)
	{
		klass = il2cpp_get_class(il2cpp_get_image_UnityEngine_CoreModule(),"UnityEngine","ScriptableObject");
		if(klass == NULL){ platform_log("il2cpp class not found: %s-%s", "UnityEngine", "ScriptableObject"); };
	}
	return klass;
}
Il2CppClass* il2cpp_get_class_UnityEngine_TextAsset()
{
	static Il2CppClass* klass;
	if(!klass)
	{
		klass = il2cpp_get_class(il2cpp_get_image_UnityEngine_CoreModule(),"UnityEngine","TextAsset");
		if(klass == NULL){ platform_log("il2cpp class not found: %s-%s", "UnityEngine", "TextAsset"); };
	}
	return klass;
}
Il2CppClass* il2cpp_get_class_UnityEngine_ComputeShader()
{
	static Il2CppClass* klass;
	if(!klass)
	{
		klass = il2cpp_get_class(il2cpp_get_image_UnityEngine_CoreModule(),"UnityEngine","ComputeShader");
		if(klass == NULL){ platform_log("il2cpp class not found: %s-%s", "UnityEngine", "ComputeShader"); };
	}
	return klass;
}
Il2CppClass* il2cpp_get_class_UnityEngine_ShaderVariantCollection()
{
	static Il2CppClass* klass;
	if(!klass)
	{
		klass = il2cpp_get_class(il2cpp_get_image_UnityEngine_CoreModule(),"UnityEngine","ShaderVariantCollection");
		if(klass == NULL){ platform_log("il2cpp class not found: %s-%s", "UnityEngine", "ShaderVariantCollection"); };
	}
	return klass;
}
Il2CppClass* il2cpp_get_class_UnityEngine_TouchScreenKeyboard()
{
	static Il2CppClass* klass;
	if(!klass)
	{
		klass = il2cpp_get_class(il2cpp_get_image_UnityEngine_CoreModule(),"UnityEngine","TouchScreenKeyboard");
		if(klass == NULL){ platform_log("il2cpp class not found: %s-%s", "UnityEngine", "TouchScreenKeyboard"); };
	}
	return klass;
}
Il2CppClass* il2cpp_get_class_UnityEngine_SpriteRenderer()
{
	static Il2CppClass* klass;
	if(!klass)
	{
		klass = il2cpp_get_class(il2cpp_get_image_UnityEngine_CoreModule(),"UnityEngine","SpriteRenderer");
		if(klass == NULL){ platform_log("il2cpp class not found: %s-%s", "UnityEngine", "SpriteRenderer"); };
	}
	return klass;
}
Il2CppClass* il2cpp_get_class_UnityEngine_Sprite()
{
	static Il2CppClass* klass;
	if(!klass)
	{
		klass = il2cpp_get_class(il2cpp_get_image_UnityEngine_CoreModule(),"UnityEngine","Sprite");
		if(klass == NULL){ platform_log("il2cpp class not found: %s-%s", "UnityEngine", "Sprite"); };
	}
	return klass;
}
Il2CppClass* il2cpp_get_class_UnityEngine_Playables_INotification()
{
	static Il2CppClass* klass;
	if(!klass)
	{
		klass = il2cpp_get_class(il2cpp_get_image_UnityEngine_CoreModule(),"UnityEngine.Playables","INotification");
		if(klass == NULL){ platform_log("il2cpp class not found: %s-%s", "UnityEngine.Playables", "INotification"); };
	}
	return klass;
}
Il2CppClass* il2cpp_get_class_UnityEngine_Playables_INotificationReceiver()
{
	static Il2CppClass* klass;
	if(!klass)
	{
		klass = il2cpp_get_class(il2cpp_get_image_UnityEngine_CoreModule(),"UnityEngine.Playables","INotificationReceiver");
		if(klass == NULL){ platform_log("il2cpp class not found: %s-%s", "UnityEngine.Playables", "INotificationReceiver"); };
	}
	return klass;
}
Il2CppClass* il2cpp_get_class_UnityEngine_U2D_SpriteAtlas()
{
	static Il2CppClass* klass;
	if(!klass)
	{
		klass = il2cpp_get_class(il2cpp_get_image_UnityEngine_CoreModule(),"UnityEngine.U2D","SpriteAtlas");
		if(klass == NULL){ platform_log("il2cpp class not found: %s-%s", "UnityEngine.U2D", "SpriteAtlas"); };
	}
	return klass;
}
Il2CppClass* il2cpp_get_class_UnityEngine_Playables_PlayableDirector()
{
	static Il2CppClass* klass;
	if(!klass)
	{
		klass = il2cpp_get_class(il2cpp_get_image_UnityEngine_DirectorModule(),"UnityEngine.Playables","PlayableDirector");
		if(klass == NULL){ platform_log("il2cpp class not found: %s-%s", "UnityEngine.Playables", "PlayableDirector"); };
	}
	return klass;
}
Il2CppClass* il2cpp_get_class_UnityEngine_Event()
{
	static Il2CppClass* klass;
	if(!klass)
	{
		klass = il2cpp_get_class(il2cpp_get_image_UnityEngine_IMGUIModule(),"UnityEngine","Event");
		if(klass == NULL){ platform_log("il2cpp class not found: %s-%s", "UnityEngine", "Event"); };
	}
	return klass;
}
Il2CppClass* il2cpp_get_class_UnityEngine_GUIStyle()
{
	static Il2CppClass* klass;
	if(!klass)
	{
		klass = il2cpp_get_class(il2cpp_get_image_UnityEngine_IMGUIModule(),"UnityEngine","GUIStyle");
		if(klass == NULL){ platform_log("il2cpp class not found: %s-%s", "UnityEngine", "GUIStyle"); };
	}
	return klass;
}
Il2CppClass* il2cpp_get_class_UnityEngine_GUIContent()
{
	static Il2CppClass* klass;
	if(!klass)
	{
		klass = il2cpp_get_class(il2cpp_get_image_UnityEngine_IMGUIModule(),"UnityEngine","GUIContent");
		if(klass == NULL){ platform_log("il2cpp class not found: %s-%s", "UnityEngine", "GUIContent"); };
	}
	return klass;
}
Il2CppClass* il2cpp_get_class_UnityEngine_ParticleSystem()
{
	static Il2CppClass* klass;
	if(!klass)
	{
		klass = il2cpp_get_class(il2cpp_get_image_UnityEngine_ParticleSystemModule(),"UnityEngine","ParticleSystem");
		if(klass == NULL){ platform_log("il2cpp class not found: %s-%s", "UnityEngine", "ParticleSystem"); };
	}
	return klass;
}
Il2CppClass* il2cpp_get_class_UnityEngine_ParticleSystemRenderer()
{
	static Il2CppClass* klass;
	if(!klass)
	{
		klass = il2cpp_get_class(il2cpp_get_image_UnityEngine_ParticleSystemModule(),"UnityEngine","ParticleSystemRenderer");
		if(klass == NULL){ platform_log("il2cpp class not found: %s-%s", "UnityEngine", "ParticleSystemRenderer"); };
	}
	return klass;
}
Il2CppClass* il2cpp_get_class_UnityEngine_Collider2D()
{
	static Il2CppClass* klass;
	if(!klass)
	{
		klass = il2cpp_get_class(il2cpp_get_image_UnityEngine_Physics2DModule(),"UnityEngine","Collider2D");
		if(klass == NULL){ platform_log("il2cpp class not found: %s-%s", "UnityEngine", "Collider2D"); };
	}
	return klass;
}
Il2CppClass* il2cpp_get_class_UnityEngine_Rigidbody2D()
{
	static Il2CppClass* klass;
	if(!klass)
	{
		klass = il2cpp_get_class(il2cpp_get_image_UnityEngine_Physics2DModule(),"UnityEngine","Rigidbody2D");
		if(klass == NULL){ platform_log("il2cpp class not found: %s-%s", "UnityEngine", "Rigidbody2D"); };
	}
	return klass;
}
Il2CppClass* il2cpp_get_class_UnityEngine_CircleCollider2D()
{
	static Il2CppClass* klass;
	if(!klass)
	{
		klass = il2cpp_get_class(il2cpp_get_image_UnityEngine_Physics2DModule(),"UnityEngine","CircleCollider2D");
		if(klass == NULL){ platform_log("il2cpp class not found: %s-%s", "UnityEngine", "CircleCollider2D"); };
	}
	return klass;
}
Il2CppClass* il2cpp_get_class_UnityEngine_PolygonCollider2D()
{
	static Il2CppClass* klass;
	if(!klass)
	{
		klass = il2cpp_get_class(il2cpp_get_image_UnityEngine_Physics2DModule(),"UnityEngine","PolygonCollider2D");
		if(klass == NULL){ platform_log("il2cpp class not found: %s-%s", "UnityEngine", "PolygonCollider2D"); };
	}
	return klass;
}
Il2CppClass* il2cpp_get_class_UnityEngine_CompositeCollider2D()
{
	static Il2CppClass* klass;
	if(!klass)
	{
		klass = il2cpp_get_class(il2cpp_get_image_UnityEngine_Physics2DModule(),"UnityEngine","CompositeCollider2D");
		if(klass == NULL){ platform_log("il2cpp class not found: %s-%s", "UnityEngine", "CompositeCollider2D"); };
	}
	return klass;
}
Il2CppClass* il2cpp_get_class_UnityEngine_Joint2D()
{
	static Il2CppClass* klass;
	if(!klass)
	{
		klass = il2cpp_get_class(il2cpp_get_image_UnityEngine_Physics2DModule(),"UnityEngine","Joint2D");
		if(klass == NULL){ platform_log("il2cpp class not found: %s-%s", "UnityEngine", "Joint2D"); };
	}
	return klass;
}
Il2CppClass* il2cpp_get_class_UnityEngine_HingeJoint2D()
{
	static Il2CppClass* klass;
	if(!klass)
	{
		klass = il2cpp_get_class(il2cpp_get_image_UnityEngine_Physics2DModule(),"UnityEngine","HingeJoint2D");
		if(klass == NULL){ platform_log("il2cpp class not found: %s-%s", "UnityEngine", "HingeJoint2D"); };
	}
	return klass;
}
Il2CppClass* il2cpp_get_class_UnityEngine_Rigidbody()
{
	static Il2CppClass* klass;
	if(!klass)
	{
		klass = il2cpp_get_class(il2cpp_get_image_UnityEngine_PhysicsModule(),"UnityEngine","Rigidbody");
		if(klass == NULL){ platform_log("il2cpp class not found: %s-%s", "UnityEngine", "Rigidbody"); };
	}
	return klass;
}
Il2CppClass* il2cpp_get_class_UnityEngine_Collider()
{
	static Il2CppClass* klass;
	if(!klass)
	{
		klass = il2cpp_get_class(il2cpp_get_image_UnityEngine_PhysicsModule(),"UnityEngine","Collider");
		if(klass == NULL){ platform_log("il2cpp class not found: %s-%s", "UnityEngine", "Collider"); };
	}
	return klass;
}
Il2CppClass* il2cpp_get_class_UnityEngine_SphereCollider()
{
	static Il2CppClass* klass;
	if(!klass)
	{
		klass = il2cpp_get_class(il2cpp_get_image_UnityEngine_PhysicsModule(),"UnityEngine","SphereCollider");
		if(klass == NULL){ platform_log("il2cpp class not found: %s-%s", "UnityEngine", "SphereCollider"); };
	}
	return klass;
}
Il2CppClass* il2cpp_get_class_UnityEngine_Joint()
{
	static Il2CppClass* klass;
	if(!klass)
	{
		klass = il2cpp_get_class(il2cpp_get_image_UnityEngine_PhysicsModule(),"UnityEngine","Joint");
		if(klass == NULL){ platform_log("il2cpp class not found: %s-%s", "UnityEngine", "Joint"); };
	}
	return klass;
}
Il2CppClass* il2cpp_get_class_UnityEngine_HingeJoint()
{
	static Il2CppClass* klass;
	if(!klass)
	{
		klass = il2cpp_get_class(il2cpp_get_image_UnityEngine_PhysicsModule(),"UnityEngine","HingeJoint");
		if(klass == NULL){ platform_log("il2cpp class not found: %s-%s", "UnityEngine", "HingeJoint"); };
	}
	return klass;
}
Il2CppClass* il2cpp_get_class_UnityEngine_TextGenerator()
{
	static Il2CppClass* klass;
	if(!klass)
	{
		klass = il2cpp_get_class(il2cpp_get_image_UnityEngine_TextRenderingModule(),"UnityEngine","TextGenerator");
		if(klass == NULL){ platform_log("il2cpp class not found: %s-%s", "UnityEngine", "TextGenerator"); };
	}
	return klass;
}
Il2CppClass* il2cpp_get_class_UnityEngine_Font()
{
	static Il2CppClass* klass;
	if(!klass)
	{
		klass = il2cpp_get_class(il2cpp_get_image_UnityEngine_TextRenderingModule(),"UnityEngine","Font");
		if(klass == NULL){ platform_log("il2cpp class not found: %s-%s", "UnityEngine", "Font"); };
	}
	return klass;
}
Il2CppClass* il2cpp_get_class_UnityEngine_Tilemaps_Tilemap()
{
	static Il2CppClass* klass;
	if(!klass)
	{
		klass = il2cpp_get_class(il2cpp_get_image_UnityEngine_TilemapModule(),"UnityEngine.Tilemaps","Tilemap");
		if(klass == NULL){ platform_log("il2cpp class not found: %s-%s", "UnityEngine.Tilemaps", "Tilemap"); };
	}
	return klass;
}
Il2CppClass* il2cpp_get_class_UnityEngine_CanvasGroup()
{
	static Il2CppClass* klass;
	if(!klass)
	{
		klass = il2cpp_get_class(il2cpp_get_image_UnityEngine_UIModule(),"UnityEngine","CanvasGroup");
		if(klass == NULL){ platform_log("il2cpp class not found: %s-%s", "UnityEngine", "CanvasGroup"); };
	}
	return klass;
}
Il2CppClass* il2cpp_get_class_UnityEngine_CanvasRenderer()
{
	static Il2CppClass* klass;
	if(!klass)
	{
		klass = il2cpp_get_class(il2cpp_get_image_UnityEngine_UIModule(),"UnityEngine","CanvasRenderer");
		if(klass == NULL){ platform_log("il2cpp class not found: %s-%s", "UnityEngine", "CanvasRenderer"); };
	}
	return klass;
}
Il2CppClass* il2cpp_get_class_UnityEngine_Canvas()
{
	static Il2CppClass* klass;
	if(!klass)
	{
		klass = il2cpp_get_class(il2cpp_get_image_UnityEngine_UIModule(),"UnityEngine","Canvas");
		if(klass == NULL){ platform_log("il2cpp class not found: %s-%s", "UnityEngine", "Canvas"); };
	}
	return klass;
}
Il2CppClass* il2cpp_get_class_UnityEngine_RectTransform()
{
	static Il2CppClass* klass;
	if(!klass)
	{
		klass = il2cpp_get_class(il2cpp_get_image_UnityEngine_CoreModule(),"UnityEngine","RectTransform");
		if(klass == NULL){ platform_log("il2cpp class not found: %s-%s", "UnityEngine", "RectTransform"); };
	}
	return klass;
}
Il2CppClass* il2cpp_get_class_UnityEngine_Networking_UnityWebRequest()
{
	static Il2CppClass* klass;
	if(!klass)
	{
		klass = il2cpp_get_class(il2cpp_get_image_UnityEngine_UnityWebRequestModule(),"UnityEngine.Networking","UnityWebRequest");
		if(klass == NULL){ platform_log("il2cpp class not found: %s-%s", "UnityEngine.Networking", "UnityWebRequest"); };
	}
	return klass;
}
Il2CppClass* il2cpp_get_class_UnityEngine_Networking_DownloadHandler()
{
	static Il2CppClass* klass;
	if(!klass)
	{
		klass = il2cpp_get_class(il2cpp_get_image_UnityEngine_UnityWebRequestModule(),"UnityEngine.Networking","DownloadHandler");
		if(klass == NULL){ platform_log("il2cpp class not found: %s-%s", "UnityEngine.Networking", "DownloadHandler"); };
	}
	return klass;
}

