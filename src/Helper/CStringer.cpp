//
//  CStringer.cpp
//  CatchiOS
//
//  Created by John Barbero Unenge on 10/1/12.
//  Copyright (c) 2012 John Barbero Unenge. All rights reserved.
//

#include "CStringer.hpp"

#include <sstream>
#include <string.h>

int s_overhead = 50;
int s_incrementSize = 50;

char* generateCString(const char* format, ...)
{
    std::ostringstream message;
    
    va_list ap;
    va_start(ap, format);
    
    const char* fCpy = format;
    
    while (*fCpy) {
        if (*fCpy == '%') {
            fCpy++;
            switch (*fCpy) {
                case 's':
                    message << va_arg(ap, const char*);
                    break;
                    
                case 'i':
                    message << va_arg(ap, int);
                    break;
                    
                case 'd':
                    message << va_arg(ap, double);
                    break;
            }
        } else {
            message << (char)*fCpy;
        }
        
        fCpy++;
    }

    va_end(ap);

    char* c = new char[100];
    strcpy(c, message.str().c_str());
    
    return c;
}
