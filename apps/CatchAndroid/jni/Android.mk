LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

FILE_LIST := $(wildcard $(LOCAL_PATH)/*.cpp) #jni folder
FILE_LIST += $(wildcard $(LOCAL_PATH)/CatchLib/src/*.cpp)   #catchlib src folder
FILE_LIST += $(wildcard $(LOCAL_PATH)/CatchLib/src/**/*.cpp)	#catchlib src subfolder
FILE_LIST += $(wildcard $(LOCAL_PATH)/CatchLib/src/**/**/*.cpp)		#catchlib src subfolder subfolder
FILE_LIST += $(wildcard $(LOCAL_PATH)/CatchLib/Box2D/*/*.cpp)   #Box2d 
FILE_LIST += $(wildcard $(LOCAL_PATH)/CatchLib/Box2D/*/*/*.cpp)   #Box2d

LOCAL_SRC_FILES := $(FILE_LIST:$(LOCAL_PATH)/%=%)
LOCAL_MODULE := catchLib
LOCAL_LDLIBS := -lGLESv2 -lGLESv1_CM -llog
LOCAL_CFLAGS := -std=c++11

include $(BUILD_SHARED_LIBRARY)
