#if __ANDROID__
#include "runtime_android.h"

static jclass AndroidRunner_klass = NULL;
static jmethodID AndroidRunner_WriteLineToInstrumentation_method = NULL;

static JavaVM* jvm = NULL;
static JNIEnv* jniEnv = NULL;
char file_dir[2048], cache_dir[2048], native_library_dir[2048];

void
_runtime_log(const char* log_domain, const char* log_level, const char* message, int32_t fatal, void* user_data)
{
	//JNIEnv* env;
	//jstring j_message;

	//if (jvm == NULL)
	//	__android_log_assert("", "mono-sdks", "%s: jvm is NULL", __func__);

	//if (AndroidRunner_klass == NULL)
	//	__android_log_assert("", "mono-sdks", "%s: AndroidRunner_klass is NULL", __func__);
	//if (AndroidRunner_WriteLineToInstrumentation_method == NULL)
	//	__android_log_assert("", "mono-sdks", "%s: AndroidRunner_WriteLineToInstrumentation_method is NULL", __func__);

	//env = jniEnv;// mono_jvm_get_jnienv();

	//j_message = (*env)->NewStringUTF(env, message);

	//(*env)->CallStaticVoidMethod(env, AndroidRunner_klass, AndroidRunner_WriteLineToInstrumentation_method, j_message);

	//(*env)->DeleteLocalRef(env, j_message);

	/* Still print it on the logcat */

	android_LogPriority android_log_level;
	switch (*log_level) {
	case 'e': /* error */
		android_log_level = ANDROID_LOG_FATAL;
		break;
	case 'c': /* critical */
		android_log_level = ANDROID_LOG_ERROR;
		break;
	case 'w': /* warning */
		android_log_level = ANDROID_LOG_WARN;
		break;
	case 'm': /* message */
		android_log_level = ANDROID_LOG_INFO;
		break;
	case 'i': /* info */
		android_log_level = ANDROID_LOG_DEBUG;
		break;
	case 'd': /* debug */
		android_log_level = ANDROID_LOG_VERBOSE;
		break;
	default:
		android_log_level = ANDROID_LOG_UNKNOWN;
		break;
	}

	__android_log_write(android_log_level, log_domain, message);
	if (android_log_level == ANDROID_LOG_FATAL)
		abort();
}

void
_log(const char* format, ...)
{
	va_list args;
	char* buf;
	int nbuf;

	errno = 0;

	va_start(args, format);
	nbuf = vasprintf(&buf, format, args);
	va_end(args);

	if (buf == NULL || nbuf == -1)
		__android_log_assert("", "mono-sdks", "%s: vasprintf failed, error: \"%s\" (%d), nbuf = %d, buf = \"%s\"", __func__, strerror(errno), errno, nbuf, buf ? buf : "(null)");

	_runtime_log("mono-sdks", "debug", buf, 0, NULL);

	free(buf);
}

void
strncpy_str(JNIEnv* env, char* buff, jstring str, int nbuff)
{
	jboolean isCopy = 0;
	const char* copy_buff = (*env)->GetStringUTFChars(env, str, &isCopy);
	strncpy(buff, copy_buff, nbuff);
	if (isCopy)
		(*env)->ReleaseStringUTFChars(env, str, copy_buff);
}

char*
m_strdup_printf(const char* format, ...)
{
	char* ret;
	va_list args;
	int n;

	va_start(args, format);
	n = vasprintf(&ret, format, args);
	va_end(args);
	if (n == -1)
		return NULL;

	return ret;
}

int
m_make_directory(const char* path, int mode)
{
#if WINDOWS
	return mkdir(path);
#else
	return mkdir(path, mode);
#endif
}

int
m_create_directory(const char* pathname, int mode)
{
	if (mode <= 0)
		mode = DEFAULT_DIRECTORY_MODE;

	if (!pathname || *pathname == '\0') {
		errno = EINVAL;
		return -1;
	}

	mode_t oldumask = umask(022);
	char* path = strdup(pathname);
	int rv, ret = 0;
	char* d;
	for (d = path; *d; ++d) {
		if (*d != '/')
			continue;
		*d = 0;
		if (*path) {
			rv = m_make_directory(path, mode);
			if (rv == -1 && errno != EEXIST) {
				ret = -1;
				break;
			}
		}
		*d = '/';
	}
	free(path);
	if (ret == 0)
		ret = m_make_directory(pathname, mode);
	umask(oldumask);

	return ret;
}

void
create_and_set(const char* home, const char* relativePath, const char* envvar)
{
	char* dir = m_strdup_printf("%s/%s", home, relativePath);
	int rv = m_create_directory(dir, DEFAULT_DIRECTORY_MODE);
	if (rv < 0 && errno != EEXIST)
		_log("Failed to create XDG directory %s. %s", dir, strerror(errno));
	if (envvar)
		setenv(envvar, dir, 1);
	free(dir);
}

/*
This is the Android specific glue ZZZZOMG

# Issues with the monodroid BCL profile
	This pinvoke should not be on __Internal by libmonodroid.so: System.TimeZoneInfo+AndroidTimeZones:monodroid_get_system_property
	This depends on monodroid native code: System.TimeZoneInfo+AndroidTimeZones.GetDefaultTimeZoneName
*/


static void*
my_dlopen(const char* name, int flags, char** err, void* user_data)
{
	if (!name)
		return INTERNAL_LIB_HANDLE;

	void* res = dlopen(name, convert_dl_flags(flags));

	//TODO handle loading AOT modules from assembly_dir

	return res;
}

static void*
my_dlsym(void* handle, const char* name, char** err, void* user_data)
{
	void* s;

	//if (handle == INTERNAL_LIB_HANDLE) {
	//	s = dlsym(runtime_bootstrap_dso, name);
	//	if (!s && mono_posix_helper_dso)
	//		s = dlsym(mono_posix_helper_dso, name);
	//}
	//else 
	{
		s = dlsym(handle, name);
	}

	if (!s && err) {
		*err = m_strdup_printf("Could not find symbol '%s'.", name);
	}

	return s;
}

MONO_API int
monodroid_get_system_property(const char* name, char** value)
{
	char* pvalue;
	char  sp_value[PROP_VALUE_MAX + 1] = { 0, };
	int   len;

	if (value)
		*value = NULL;

	pvalue = sp_value;
	len = __system_property_get(name, sp_value);

	if (len >= 0 && value) {
		*value = malloc(len + 1);
		if (!*value)
			return -len;
		memcpy(*value, pvalue, len);
		(*value)[len] = '\0';
	}

	return len;
}

MONO_API void
monodroid_free(void* ptr)
{
	free(ptr);
}

void
init_sock_addr(struct sockaddr** res, const char* str_addr)
{
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	inet_pton(AF_INET, str_addr, &addr.sin_addr);

	*res = calloc(1, sizeof(struct sockaddr));
	**(struct sockaddr_in**)res = addr;
}

MONO_API int
monodroid_getifaddrs(m_ifaddrs** ifap)
{
	char buff[1024];
	FILE* f = fopen("/proc/net/route", "r");
	if (f) {
		int i = 0;
		fgets(buff, 1023, f);
		fgets(buff, 1023, f);
		while (!isspace(buff[i]) && i < 1024)
			++i;
		buff[i] = 0;
		fclose(f);
	}
	else {
		strcpy(buff, "wlan0");
	}

	m_ifaddrs* res = calloc(1, sizeof(m_ifaddrs));
	memset(res, 0, sizeof(*res));

	res->ifa_next = NULL;
	res->ifa_name = m_strdup_printf("%s", buff);
	res->ifa_flags = 0;
	res->ifa_ifu.ifu_dstaddr = NULL;
	init_sock_addr(&res->ifa_addr, "192.168.0.1");
	init_sock_addr(&res->ifa_netmask, "255.255.255.0");

	*ifap = res;
	return 0;
}

MONO_API void
monodroid_freeifaddrs(m_ifaddrs* ifap)
{
	free(ifap->ifa_name);
	if (ifap->ifa_addr)
		free(ifap->ifa_addr);
	if (ifap->ifa_netmask)
		free(ifap->ifa_netmask);
	free(ifap);
}

MONO_API int
_monodroid_get_android_api_level(void)
{
	return 24;
}

MONO_API int
_monodroid_get_network_interface_up_state(void* ifname, int* is_up)
{
	*is_up = 1;
	return 1;
}

MONO_API int
_monodroid_get_network_interface_supports_multicast(void* ifname, int* supports_multicast)
{
	*supports_multicast = 0;
	return 1;
}

MONO_API int
_monodroid_get_dns_servers(void** dns_servers_array)
{
	*dns_servers_array = NULL;
	if (!dns_servers_array)
		return -1;

	size_t  len;
	char* dns;
	char* dns_servers[8];
	int     count = 0;
	char    prop_name[] = "net.dnsX";
	int i;
	for (i = 0; i < 8; i++) {
		prop_name[7] = (char)(i + 0x31);
		len = monodroid_get_system_property(prop_name, &dns);
		if (len <= 0) {
			dns_servers[i] = NULL;
			continue;
		}
		dns_servers[i] = strndup(dns, len);
		count++;
	}

	if (count <= 0)
		return 0;

	char** ret = (char**)malloc(sizeof(char*) * count);
	char** p = ret;
	for (i = 0; i < 8; i++) {
		if (!dns_servers[i])
			continue;
		*p++ = dns_servers[i];
	}

	*dns_servers_array = (void*)ret;
	return count;
}

static int initialized = 0;

static jobject
lref_to_gref(JNIEnv* env, jobject lref)
{
	jobject g;
	if (lref == 0)
		return 0;
	g = (*env)->NewGlobalRef(env, lref);
	(*env)->DeleteLocalRef(env, lref);
	return g;
}

void
AndroidInit(JNIEnv* env, jstring j_files_dir, jstring j_cache_dir,
	jstring j_native_library_dir, jstring j_assembly_dir, jstring j_assembly_name, jboolean is_debugger, jboolean is_profiler, jboolean wait_for_lldb)
{
	char buff[1024], assembly_dir[2048], assembly_name[2048];

	_log("IN %s\n", __func__);
	strncpy_str(env, file_dir, j_files_dir, sizeof(file_dir));
	strncpy_str(env, cache_dir, j_cache_dir, sizeof(cache_dir));
	strncpy_str(env, native_library_dir, j_native_library_dir, sizeof(native_library_dir));
	strncpy_str(env, assembly_dir, j_assembly_dir, sizeof(assembly_dir));
	strncpy_str(env, assembly_name, j_assembly_name, sizeof(assembly_name));

	_log("-- file dir %s", file_dir);
	_log("-- cache dir %s", cache_dir);
	_log("-- native library dir %s", native_library_dir);
	_log("-- assembly dir %s", assembly_dir);
	_log("-- assembly name %s", assembly_name);
	_log("-- is debugger %d", is_debugger);
	_log("-- is profiler %d", is_profiler);
	prctl(PR_SET_DUMPABLE, 1);
}

void
Java_com_scriptengine_library_ScriptEngine_AndroidJniInit(JNIEnv* env, jobject thiz, jstring j_files_dir, jstring j_cache_dir,
	jstring j_native_library_dir, jstring j_assembly_dir, jstring j_assembly_name, jboolean is_debugger, jboolean is_profiler, jboolean wait_for_lldb)
{
	char buff[1024], assembly_dir[2048], assembly_name[2048];

	_log("IN %s\n", __func__);
	strncpy_str(env, file_dir, j_files_dir, sizeof(file_dir));
	strncpy_str(env, cache_dir, j_cache_dir, sizeof(cache_dir));
	strncpy_str(env, native_library_dir, j_native_library_dir, sizeof(native_library_dir));
	strncpy_str(env, assembly_dir, j_assembly_dir, sizeof(assembly_dir));
	strncpy_str(env, assembly_name, j_assembly_name, sizeof(assembly_name));

	_log("-- file dir %s", file_dir);
	_log("-- cache dir %s", cache_dir);
	_log("-- native library dir %s", native_library_dir);
	_log("-- assembly dir %s", assembly_dir);
	_log("-- assembly name %s", assembly_name);
	_log("-- is debugger %d", is_debugger);
	_log("-- is profiler %d", is_profiler);
	prctl(PR_SET_DUMPABLE, 1);
}

static void
mono_jvm_initialize(JavaVM* vm)
{
	JNIEnv* env;

	if (initialized)
		return;

	jvm = vm;
	if (!jvm)
		__android_log_assert("", "mono-sdks", "%s: fatal error: Could not get JVM", __func__);

	int res = (*jvm)->GetEnv(jvm, (void**)&env, JNI_VERSION_1_6);
	if (!env)
		__android_log_assert("", "mono-sdks", "%s: fatal error: Could not create env, res = %d", __func__, res);

	//AndroidRunner_klass = lref_to_gref(env, (*env)->FindClass(env, "org/mono/android/AndroidRunner"));
	//if (!AndroidRunner_klass)
	//	__android_log_assert("", "mono-sdks", "%s: fatal error: Could not find AndroidRunner_klass", __func__);

	//AndroidRunner_WriteLineToInstrumentation_method = (*env)->GetStaticMethodID(env, AndroidRunner_klass, "WriteLineToInstrumentation", "(Ljava/lang/String;)V");
	//if (!AndroidRunner_WriteLineToInstrumentation_method)
	//	__android_log_assert("", "mono-sdks", "%s: fatal error: Could not find AndroidRunner_WriteLineToInstrumentation_method", __func__);

	initialized = 1;
}


JNIEXPORT jint JNICALL
JNI_OnLoad(JavaVM* vm, void* reserved)
{
	mono_jvm_initialize(vm);
	return JNI_VERSION_1_6;
}

static JNIEnv*
mono_jvm_get_jnienv(void)
{
	JNIEnv* env;

	if (!initialized)
		__android_log_assert("", "mono-sdks", "%s: Fatal error: jvm not initialized", __func__);

	(*jvm)->GetEnv(jvm, (void**)&env, JNI_VERSION_1_6);
	if (env)
		return env;

	(*jvm)->AttachCurrentThread(jvm, (void**)&env, NULL);
	if (env)
		return env;

	__android_log_assert("", "mono-sdks", "%s: Fatal error: Could not create env", __func__);
}


#endif