#ifndef il2cpp_support_h
#define il2cpp_support_h

#include <stdint.h>
#include "glib.h"


#include "il2cpp-blob.h"
#include "il2cpp-metadata.h"

#ifdef __cplusplus
extern "C" {
#endif


void init_il2cpp();

#if !defined(_WIN32)
	#include <il2cpp-api.h>
#else
	#include "il2cpp-api-types.h"

//#include "il2cpp-runtime-metadata.h"

#define DO_API(r, n, p)		typedef r (*_##n) p;
#include "il2cpp-api-functions.h"
#undef DO_API

#define DO_API(r, n, p)		extern _##n n
#include "il2cpp-api-functions.h"
#undef DO_API

#endif

#define false 0
#define true 1

typedef struct Il2CppArrayType Il2CppArrayType;
typedef struct Il2CppGenericClass Il2CppGenericClass;

typedef struct FieldInfo
{
    const char* name;
    const Il2CppType* type;
    Il2CppClass* parent;
    int32_t offset; // If offset is -1, then it's thread static
    uint32_t token;
} FieldInfo;

typedef struct Il2CppType
{
    union
    {
        // We have this dummy field first because pre C99 compilers (MSVC) can only initializer the first value in a union.
        void* dummy;
        TypeDefinitionIndex __klassIndex; /* for VALUETYPE and CLASS at startup */
        Il2CppMetadataTypeHandle typeHandle; /* for VALUETYPE and CLASS at runtime */
        const Il2CppType* type;   /* for PTR and SZARRAY */
        Il2CppArrayType* array; /* for ARRAY */
        //MonoMethodSignature *method;
        GenericParameterIndex __genericParameterIndex; /* for VAR and MVAR at startup */
        Il2CppMetadataGenericParameterHandle genericParameterHandle; /* for VAR and MVAR at runtime */
        Il2CppGenericClass* generic_class; /* for GENERICINST */
    } data;
    unsigned int attrs : 16; /* param attributes or field flags */
    Il2CppTypeEnum type : 8;
    unsigned int num_mods : 5;  /* max 64 modifiers follow at the end */
    unsigned int byref : 1;
    unsigned int pinned : 1;  /* valid when included in a local var signature */
    unsigned int valuetype : 1;
    //MonoCustomMod modifiers [MONO_ZERO_LEN_ARRAY]; /* this may grow */
} Il2CppType;


typedef void (*ThreadAttachDetachCallback)(Il2CppThread* thread);
void il2cpp_set_thread_callback(ThreadAttachDetachCallback attach, ThreadAttachDetachCallback detach);
Il2CppThread** il2cpp_get_all_threads(size_t* thread_count);

Il2CppImage* il2cpp_get_image(const char* assembly);
Il2CppClass* il2cpp_get_class(Il2CppImage* image, const char* _namespace, const char* name);
Il2CppClass* il2cpp_search_class(const char* assembly, const char* _namespace, const char* name);
Il2CppMethodPointer hook_method(const char* assembly, const char* _namespace, const char* name, const char* method, int32_t param_count, Il2CppMethodPointer hook);
Il2CppMethodPointer hook_method2(Il2CppClass* klass, const char* method, int32_t param_count, Il2CppMethodPointer hook);
Il2CppMethodPointer hook_icall_method(const char* method, Il2CppMethodPointer hook);
Il2CppMethodPointer il2cpp_get_native_method_ptr(Il2CppClass* klass, const char* method, int32_t param_count);

Il2CppClass* il2cpp_get_exception_class();
Il2CppObject * il2cpp_exception_property(Il2CppObject *obj, const char *name, char is_virtual);

char* il2cpp_array_addr_with_size(Il2CppArray *array, int32_t size, uintptr_t idx);

#define il2cpp_array_addr(array, type, index) ((type*)(void*) il2cpp_array_addr_with_size (array, sizeof (type), index))
#define il2cpp_array_get(array, type, index) ( *(type*)il2cpp_array_addr ((array), type, (index)) )
#define il2cpp_array_set(array, type, index, value)    \
    do {    \
        type *__p = (type *) il2cpp_array_addr ((array), type, (index));    \
        *__p = (value); \
    } while (0)
#define il2cpp_array_setref(array, index, value)  \
    do {    \
        void* *__p = (void* *) il2cpp_array_addr ((array), void*, (index)); \
        /* il2cpp_gc_wbarrier_set_arrayref ((array), __p, (MonoObject*)(value));    */\
         *__p = (value);    \
    } while (0)

#ifdef __cplusplus
} /* extern "C" */
#endif
#endif
