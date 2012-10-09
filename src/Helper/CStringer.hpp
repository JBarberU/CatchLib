//
//  File:   CStringer.hpp
//
//  Author: John Barbero Unenge
//      All code is my own except where credited to others.
//
//  Copyright (c) 2012 Catch22. All Rights Reserved.
//
//  Date:   1/10/12
//

#ifndef __CatchiOS__CStringer__
#define __CatchiOS__CStringer__

#include <cstdarg>

//  Generates a string constant from a format string
//  any number of arguments. It currently supports
//  string constants, double values and int values.
//  Example of usage might look like the following:
//      int a = 3;
//      double b = 1.0;
//      const char* c = "Some text";
//      generateCString("Int: %i Double: %d String: %s", a, b, c);
char* generateCString(const char* format, ...);

#endif /* defined(__CatchiOS__CStringer__) */
