LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE := il2cpp
LOCAL_SRC_FILES := E:/Projects/Project_LZ/client/Build/Android/unityLibrary/src/main/jniLibs/$(TARGET_ARCH_ABI)/libil2cpp.so
include $(PREBUILT_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE := MonoPosixHelper
LOCAL_SRC_FILES := $(LOCAL_PATH)/../lib/$(TARGET_ARCH_ABI)/libMonoPosixHelper.a
include $(PREBUILT_STATIC_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE := monosgen-2.0
LOCAL_EXPORT_C_INCLUDES := ./include
LOCAL_SRC_FILES := $(LOCAL_PATH)/../lib/$(TARGET_ARCH_ABI)/libmonosgen-2.0.a
include $(PREBUILT_STATIC_LIBRARY)

# LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

IL2CPP_INCLUDE_DIR := $(UnityEditorPath)/Data/il2cpp/libil2cpp
# $(warning $(IL2CPP_INCLUDE_DIR))
# $(warning $(APP_ABI))

FILE_LIST := $(wildcard $(LOCAL_PATH)/custom/*.cpp)
FILE_LIST := $(wildcard $(LOCAL_PATH)/custom/*.c)
FILE_LIST += $(wildcard $(LOCAL_PATH)/generated/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/generated/*.c)
FILE_LIST += $(wildcard $(LOCAL_PATH)/main/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/main/*.c)
FILE_LIST += $(wildcard $(LOCAL_PATH)/*.c)

LOCAL_MODULE := ScriptEngine
LOCAL_SRC_FILES := $(FILE_LIST:$(LOCAL_PATH)/%=%)

LOCAL_C_INCLUDES += ./ \
					$(IL2CPP_INCLUDE_DIR) \
					./include \

LOCAL_CFLAGS += -pie -fPIC -Wall -Wno-comment -fno-strict-aliasing
# LOCAL_LDFLAGS += -pie -fPIC
# LOCAL_ALLOW_UNDEFINED_SYMBOLS := true

LOCAL_SHARED_LIBRARIES := il2cpp
LOCAL_STATIC_LIBRARIES := MonoPosixHelper monosgen-2.0
LOCAL_LDLIBS    := -lm -llog -landroid -lz

include $(BUILD_SHARED_LIBRARY)