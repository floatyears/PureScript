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

#if defined(__cplusplus)
extern "C"
{
#endif // __cplusplus
	extern void* g_manageFuncPtr;
	extern MonoDomain *g_domain;

	typedef void(*print_log)(char* data);

	int mono_setup(char* bundleDir, const char* dllName);
	int mono_exit();
	void set_log_callback(print_log callback);
	MonoAssembly* load_assembly(const char *name, const char *culture);
	void unhandled_exception_handler(MonoObject *exc, void *user_data);

	MonoObject* mono_runtime_invoke_try(MonoMethod *method, void *obj, void **params);

#if defined(__cplusplus)
}
#endif // __cplusplus

#endif /* runtime_h */