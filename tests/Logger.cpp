/*
 * Logger.cpp
 *
 *  Created on: Oct 9, 2012
 *      Author: Barber
 */

#include "../src/Helper/Logger.hpp"
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