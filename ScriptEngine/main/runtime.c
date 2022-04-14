#include "runtime.h"


#ifdef WIN32
#include <windows.h>
#include <direct.h>
#endif

#include "mono/jit/jit.h"
#include "mono/metadata/environment.h"
#include "mono/utils/mono-publib.h"
#include "mono/utils/mono-logger.h"
#include "mono/metadata/assembly.h"
#include "mono/metadata/mono-debug.h"
#include "mono/metadata/exception.h"
#include "mono/metadata/threads.h"
#include "mono/metadata/appdomain.h"
#include "mono/metadata/sgen-bridge.h"

#include "il2cpp_support.h"

#include <sys/stat.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdarg.h>



//typedef char bool;
#define false 0
#define true 1

MonoDomain *g_domain;
extern char native_library_dir[2048];

char* mono_runtime_bundle_path;
char* mono_runtime_reload_path;

bool
file_exists(const char *path)
{
	struct stat buffer;
	return stat(path, &buffer) == 0;
}

char *
strdup_printf(const char *msg, ...)
{
	va_list args;
	char *formatted = NULL;

	va_start(args, msg);
	printf(formatted, msg, args);
	va_end(args);

	return formatted;
}


static char formatted[1024];
void _platform_log(const char* _format, ...)
{
#if _MSC_VER
	va_list args;
	va_start(args, _format);
	vsnprintf(formatted, 1024, _format, args);
	va_end(args);
	printf(formatted);
//#elif __ANDROID__
//	va_list args;
//	va_start(args, _format);
//	vsnprintf(formatted, 1024, _format, args);
//	va_end(args);
//	__android_log_print(4, //android_LogPriority::ANDROID_LOG_INFO to_android_priority(log_level),
//		/* TODO: provide a proper app name */
//		"mono", formatted);
//#else
//	va_list args;
//	va_start(args, _format);
//	vsnprintf(formatted, 1024, _format, args);
//	va_end(args);
//	printf(formatted);
#endif
}

extern const char *ios_bundle_path(void);

const char * runtime_bundle_path(void)
{
    if(mono_runtime_bundle_path != NULL)
        return mono_runtime_bundle_path;
 
#if RUNTIME_IOS
	mono_runtime_bundle_path = ios_bundle_path();
#elif __ANDROID__
	printf("doc_path=%s\n", mono_runtime_bundle_path);
#else
	if ((mono_runtime_bundle_path = _getcwd(NULL, 0)) == NULL)
		perror("getcwd error");
	else
		printf("doc_path=%s\n", mono_runtime_bundle_path);
#endif

	return mono_runtime_bundle_path;
}


MonoAssembly*
load_assembly(const char *name, const char *culture)
{
	char *load_dir = mono_runtime_reload_path;
	char path[1024];
	int res;
    const char *post = name + strlen(name) -4;

	if (culture && strcmp(culture, ""))
		res = snprintf(path, sizeof(path) - 1, "%s/%s/%s", load_dir, culture, name);
    else if(strcmp(post, ".dll") == 0 || strcmp(post, ".exe") == 0)
        res = snprintf(path, sizeof(path) - 1, "%s/%s", load_dir, name);
	else
		res = snprintf(path, sizeof(path) - 1, "%s/%s.dll", load_dir, name);
	assert(res > 0);

	if (!file_exists(path))
	{
		load_dir = runtime_bundle_path();
		if (culture && strcmp(culture, ""))
			res = snprintf(path, sizeof(path) - 1, "%s/Managed/%s/%s", load_dir, culture, name);
		else if (strcmp(post, ".dll") == 0 || strcmp(post, ".exe") == 0)
			res = snprintf(path, sizeof(path) - 1, "%s/Managed/%s", load_dir, name);
		else
			res = snprintf(path, sizeof(path) - 1, "%s/Managed/%s.dll", load_dir, name);
		assert(res > 0);
	}

	printf("load_assembly load path: %s \n", path);
	if (file_exists(path)) {
		MonoAssembly *assembly = mono_assembly_open(path, NULL);
		assert(assembly);
		return assembly;
	}
	return NULL;
}

void check_mono_exception(MonoException* mono);
static void main_function (MonoDomain *domain, const char *file, int argc, char** argv)
{

	MonoAssembly *assembly = load_assembly("Adapter.wrapper.dll", NULL);

	if (!assembly)
		return;

	MonoImage* img = mono_assembly_get_image(assembly);
	MonoClass* klass = mono_class_from_name(img, "PureScript.Mono", "ScriptEngine");
	MonoMethod* main = mono_class_get_method_from_name(klass, "Main", 1);

	/*
	 * mono_jit_exec() will run the Main() method in the assembly.
	 * The return value needs to be looked up from
	 * System.Environment.ExitCode.
	 */
	 //mono_jit_exec(domain, assembly, argc, argv);

	MonoObject *exc = NULL;
	int res = mono_runtime_run_main(main, argc, argv, &exc);
	check_mono_exception(exc);
	
	
	/*if (exc != NULL)
		return;

	assembly = load_assembly(file, NULL);
	if (!assembly)
		return;

	img = mono_assembly_get_image(assembly);
	klass = mono_class_from_name(img, "", "MonoEntry");
	main = mono_class_get_method_from_name(klass, "Main", 1);

	int res = mono_runtime_run_main(main, argc, argv, &exc);
	//mono_runtime_invoke(main, 0, NULL, &exc);

	check_mono_exception(exc);*/
}

const char* resolve_assembly(const char* request);
static MonoAssembly*
assembly_preload_hook(MonoAssemblyName *aname, char **assemblies_path, void* user_data)
{
	const char *name = resolve_assembly(mono_assembly_name_get_name(aname));
	const char *culture = mono_assembly_name_get_culture(aname);

	return load_assembly(name, culture);
}

void
log_callback_default(const char *log_domain, const char *log_level, const char *message, mono_bool fatal, void *user_data)
{
	platform_log("(%s %s) %s", log_domain, log_level, message);
	if (fatal) {
		platform_log("Exit code: %d.", 1);
		exit(1);
	}
}

MonoObject *
mono_exception_property(MonoObject *obj, const char *name, char is_virtual)
{
	MonoMethod *get = NULL;
	MonoMethod *get_virt = NULL;
	MonoObject *exc = NULL;

	get = mono_class_get_method_from_name(mono_get_exception_class(), name, 0);
	if (get) {
		if (is_virtual) {
			get_virt = mono_object_get_virtual_method(obj, get);
			if (get_virt)
				get = get_virt;
		}

		return (MonoObject *)mono_runtime_invoke(get, obj, NULL, &exc);
	}
	else {
		platform_log("Could not find the property System.Exception.%s", name);
	}

	return NULL;
}

static char *
fetch_exception_property_string(MonoObject *obj, const char *name, bool is_virtual)
{
	MonoString *str = (MonoString *)mono_exception_property(obj, name, is_virtual);
	return str ? mono_string_to_utf8(str) : NULL;
}

void
unhandled_exception_handler(MonoObject *exc, void *user_data)
{
	//NSMutableString *msg = [[NSMutableString alloc] init];
	MonoClass *type = mono_object_get_class(exc);
	const char* type_name = mono_class_get_name(type);
	//char *type_name = strdup_printf("%s.%s", mono_class_get_namespace(type), mono_class_get_name(type));
	char *trace = fetch_exception_property_string(exc, "get_StackTrace", true);
	char *message = fetch_exception_property_string(exc, "get_Message", true);

	platform_log("Unhandled managed exception:\n");
	platform_log("%s (%s)\n%s\n", message, type_name, trace ? trace : "");

	if (trace != NULL)
		mono_free(trace);
	if (message != NULL)
		mono_free(message);

	//os_log_info (OS_LOG_DEFAULT, "%@", msg);
	platform_log("Exit code: %d.", 1);
	exit(1);
}

void il2cpp_thread_attach_callback(Il2CppThread* thread)
{
	mono_thread_attach(g_domain);
}

void il2cpp_thread_dettach_callback(Il2CppThread* thread)
{
	mono_thread_detach(g_domain);
}

/*
static int malloc_count = 0;

static void* custom_malloc(size_t bytes)
{
	++malloc_count;
	return malloc(bytes);
}*/

/* Implemented by generated code */
void mono_register_icall(void);
void register_assembly_map();

#if RUNTIME_IOS
#define __STRDUP strdup
void mono_ios_runtime_init(void);
#elif __ANDROID__
#define __STRDUP strdup
#else
#define __STRDUP _strdup
#endif

void mono_debug() {

	mono_debug_init(MONO_DEBUG_FORMAT_MONO);

	static const char* options[] = {
		  "--soft-breakpoints",
		  "--debugger-agent=transport=dt_socket,address=127.0.0.1:10001,embedding=1,server=y,suspend=n"
	};
	mono_jit_parse_options(sizeof(options) / sizeof(char*), (char**)options);
}

int 
mono_setup(char* reloadDir, const char* file) {

	mono_runtime_reload_path = __STRDUP(reloadDir);

	int retval = 0;

	//MonoAllocatorVTable mem_vtable = {custom_malloc};
	//mono_set_allocator_vtable (&mem_vtable);
	mono_install_assembly_preload_hook(assembly_preload_hook, NULL);

#if __ANDROID__
	setenv("MONO_LOG_LEVEL", "info", 1);
	setenv("MONO_LOG_MASK", "all", 1);
#endif
	mono_install_unhandled_exception_hook(unhandled_exception_handler, NULL);
	mono_trace_set_log_handler(log_callback_default, NULL); //
	mono_set_signal_chaining(true);
	mono_set_crash_chaining(true);

#if __ANDROID__
	//char* buff = native_library_dir;
	char buff[512];// = "/data/data/com.eeyoo.LZ/libmono-native.so";
	sprintf(buff, "%s/libmono-native.so", native_library_dir);
	platform_log("navtive lib path: %s", buff);
	mono_dllmap_insert(NULL, "System.Native", NULL, buff, NULL);
	mono_dllmap_insert(NULL, "System.Net.Security.Native", NULL, buff, NULL);
#endif

	mono_debug();
	
#if RUNTIME_IOS
	const char* rootdir = runtime_bundle_path();
#else
	const char* rootdir = mono_runtime_reload_path;
#endif

	mono_set_dirs(rootdir, rootdir);
	platform_log("dll load dir: %s", rootdir);

	/*
	 * Load the default Mono configuration file, this is needed
	 * if you are planning on using the dllmaps defined on the
	 * system configuration
	 */
	//mono_config_parse (NULL);
	/*
	 * mono_jit_init() creates a domain: each assembly is
	 * loaded and run in a MonoDomain.
	 */

#if RUNTIME_IOS
	mono_ios_runtime_init();
    g_domain = mono_domain_get();
#else
	g_domain = mono_jit_init (file);
	mono_domain_set(g_domain, false);
	mono_thread_attach(g_domain);
#endif
	
	register_assembly_map();
	/*
	 * We add our special internal call, so that C# code
	 * can call us back.
	 */
	mono_register_icall();

	size_t thread_cnt = 0;
	Il2CppThread** threads = il2cpp_get_all_threads(&thread_cnt);
	platform_log("current il2cpp attached thread count: %d", thread_cnt);
	//il2cpp_set_thread_callback(il2cpp_thread_attach_callback, il2cpp_thread_dettach_callback);
	//gc thread attach to il2cpp
	//mono_gc_wait_for_bridge_processing

	char *managed_argv[2];
	managed_argv[0] = file;
	managed_argv[1] = file;
	main_function (g_domain, file, 2, managed_argv);
	
	return retval;
}

int mono_exit()
{
	platform_log("exit mono env");
	int retval = mono_environment_exitcode_get ();

	mono_jit_cleanup (mono_domain_get());
	return retval;
}
