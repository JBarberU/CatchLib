//
//  Logger.cpp
//  CatchiOS
//
//  Created by John Barbero Unenge on 9/20/12.
//  Copyright (c) 2012 John Barbero Unenge. All rights reserved.
//

#include "Logger.hpp"
#include <iostream>

void Log(LogTag tag, const char* title, const char* message)
{
    const char* tag_str;
    
    switch (tag) {
        case LOG_INFO:
            tag_str = "LOG_INFO";
            break;
        case LOG_EVENT:
            tag_str = "LOG_EVENT";
            break;
        case LOG_ERROR:
            tag_str = ">>>> LOG_ERROR <<<<";
            break;
        default:
            tag_str = "UNKNOWN_LOG_TAG";
            break;
    }
    
    std::cout << tag_str << "\t" << title << "\t" << message << "\n";
}