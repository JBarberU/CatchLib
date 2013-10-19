//
//  File:       Logger.cpp
//  Author:     John Barbero Unenge, Alexander Hederstaf
//              All code is my own except where credited to others.
//
//  Date: 20/9-2012
//
//	Description:
//	Implementation of the Logger functionality for Android.
//
//	Includes:
//	android/log.h, CatchLib/src/Logger.hpp

#include <android/log.h>
#include "CatchLib/src/Helper/Logger.hpp"

void Log(LogTag tag, const char* title, const char* message)
{
	int prio;

	switch (tag) {
	case LOG_INFO :
		prio = ANDROID_LOG_INFO;
		break;
	case LOG_EVENT :
		prio = ANDROID_LOG_DEBUG;
		break;
	case LOG_ERROR :
		prio = ANDROID_LOG_ERROR;
		break;
	}
	__android_log_write(prio, title, message);
}
