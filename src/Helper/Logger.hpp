//
//  File:       Logger.hpp
//  Author:     John Barbero Unenge
//              All code is my own except where credited to others.
//
//  Copyright (c) 2012 Catch22. All Rights Reserved.
//
//  Date: 17/9-2012
//  
//  Description:
//  This classed is used for logging messages to the terminal. As 
//  system logging works different on different platforms they 
//  have different implementations
//  

#include "CStringer.hpp"

enum LogTag{
	LOG_INFO,
	LOG_EVENT,
	LOG_ERROR
};
//  Takes a message and displays it in the system log.
void Log(LogTag tag, const char* title, const char* message);
