/* -*- Mode: C; tab-width: 4; indent-tabs-mode: t; c-basic-offset: 4 -*- */
//
//  runtime.h
//  test-runner
//
//  Created by Zoltan Varga on 11/12/17.
//  Copyright © 2017 Zoltan Varga. All rights reserved.
//
#ifndef runtime_h
#define runtime_h

#include <mono/jit/jit.h>
//#include <mono/metadata/object.h>

#if __ANDROID__
#include "runtime_android.h"
#endif

#if TARGET_OS_IPHONE || TARGET_IPHONE_SIMULATOR || TARGET_OS_TV || TARGET_TVOS_SIMULATOR
#define RUNTIME_IOS 1
#endif

#if defined(__cplusplus)
extern "C"
{
#endif // __cplusplus

#if __ANDROID__
#define platform_log(FORMAT, ...) _log(FORMAT, ##__VA_ARGS__)
#else
#define platform_log(FORMAT, ...) _platform_log(FORMAT, ##__VA_ARGS__)
#endif

	void _platform_log(const char* _format, ...);

	extern MonoDomain *g_domain;

	typedef void(*print_log)(char* data);

	int mono_setup(char* reloadDir, const char* dllName);
	int mono_exit();

	void set_log_callback(print_log callback);
	MonoAssembly* load_assembly(const char *name, const char *culture);

	MonoObject * mono_exception_property(MonoObject *obj, const char *name, char is_virtual);

	const char * runtime_bundle_path(void);
#if defined(__cplusplus)
}
#endif // __cplusplus

#endif /* runtime_h */
