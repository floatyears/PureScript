// MonoLib.cpp : 定义 DLL 应用程序的导出函数。
//

#include "runtime.h"
#include "Mediator.h"
#include "mono/metadata/exception.h"

// Macro to put before functions that need to be exposed to C#
#ifdef _WIN32
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT 
#endif


void* g_manageFuncPtr = NULL;

DLLEXPORT void SetupMono(char* bundleDir, const char* dllName)
{
	mono_setup(bundleDir,dllName);
}

DLLEXPORT void CloseMono()
{
	mono_exit();
}

DLLEXPORT void SetFuncPointer(void * ptr)
{
	g_manageFuncPtr = ptr;
}

DLLEXPORT void* GetFuncPointer()
{
	return g_manageFuncPtr;
}
