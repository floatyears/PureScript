#ifndef runtime_android_h
#define runtime_android_h

#if __ANDROID__
#include <stdlib.h>
#include <jni.h>
#include <android/log.h>

#include <linux/prctl.h>
#include <pthread.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <dirent.h>
#include <errno.h>
#include <sys/system_properties.h>



#define MONO_API __attribute__ ((__visibility__ ("default")))

#define INTERNAL_LIB_HANDLE ((void*)(size_t)-1)
#define DEFAULT_DIRECTORY_MODE S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH

typedef struct {
	struct _monodroid_ifaddrs* ifa_next; /* Pointer to the next structure.      */

	char* ifa_name;                      /* Name of this network interface.     */
	unsigned int ifa_flags;              /* Flags as from SIOCGIFFLAGS ioctl.   */

	struct sockaddr* ifa_addr;           /* Network address of this interface.  */
	struct sockaddr* ifa_netmask;        /* Netmask of this interface.          */
	union {
		/* At most one of the following two is valid.  If the IFF_BROADCAST
		   bit is set in `ifa_flags', then `ifa_broadaddr' is valid.  If the
		   IFF_POINTOPOINT bit is set, then `ifa_dstaddr' is valid.
		   It is never the case that both these bits are set at once.  */
		struct sockaddr* ifu_broadaddr;  /* Broadcast address of this interface. */
		struct sockaddr* ifu_dstaddr;    /* Point-to-point destination address.  */
	} ifa_ifu;
	void* ifa_data;               /* Address-specific data (may be unused).  */
} m_ifaddrs;

typedef int (*get_ifaddr_fn)(m_ifaddrs** ifap);
typedef void (*freeifaddr_fn)(m_ifaddrs* ifap);

#ifdef __cplusplus
extern "C" {
#endif

static jclass AndroidRunner_klass;
static jmethodID AndroidRunner_WriteLineToInstrumentation_method;

static JavaVM* jvm;
char file_dir[2048], cache_dir[2048], native_library_dir[2048];

static void* my_dlsym(void* handle, const char* name, char** err, void* user_data);
static void* my_dlopen(const char* name, int flags, char** err, void* user_data);

static JNIEnv* mono_jvm_get_jnienv(void);
static void mono_jvm_initialize(JavaVM* vm);
void AndroidInit(JNIEnv* env, jstring j_files_dir, jstring j_cache_dir,
	jstring j_native_library_dir, jstring j_assembly_dir, jstring j_assembly_name, jboolean is_debugger, jboolean is_profiler, jboolean wait_for_lldb);
void Java_com_scriptengine_library_ScriptEngine_AndroidJniInit(JNIEnv* env, jobject thiz, jstring j_files_dir, jstring j_cache_dir,
	jstring j_native_library_dir, jstring j_assembly_dir, jstring j_assembly_name, jboolean is_debugger, jboolean is_profiler, jboolean wait_for_lldb);

void _log(const char* format, ...);
void _runtime_log(const char* log_domain, const char* log_level, const char* message, int32_t fatal, void* user_data);
void strncpy_str(JNIEnv* env, char* buff, jstring str, int nbuff);
char* m_strdup_printf(const char* format, ...);
int m_make_directory(const char* path, int mode);
int m_create_directory(const char* pathname, int mode);
void create_and_set(const char* home, const char* relativePath, const char* envvar);

MONO_API int monodroid_get_system_property(const char* name, char** value);
MONO_API void monodroid_free(void* ptr);
void init_sock_addr(struct sockaddr** res, const char* str_addr);
MONO_API int monodroid_getifaddrs(m_ifaddrs** ifap);
MONO_API void monodroid_freeifaddrs(m_ifaddrs* ifap);
MONO_API int _monodroid_get_android_api_level(void);
MONO_API int _monodroid_get_network_interface_up_state(void* ifname, int* is_up);
MONO_API int _monodroid_get_network_interface_supports_multicast(void* ifname, int* supports_multicast);
MONO_API int _monodroid_get_dns_servers(void** dns_servers_array);
static jobject lref_to_gref(JNIEnv* env, jobject lref);

#ifdef __cplusplus
} /* extern "C" */
#endif
#endif
#endif