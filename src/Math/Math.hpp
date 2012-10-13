//
//  File:	Math.hpp
//  Class:  Math
//  Author: John Barbero Unenge
//          All code is my own except where credited to others.
//
//  Copyright (c) Catch22. All rights reserved.
//
//  Date:   11/10-2012
//

#include "Vector2d.hpp"
#include <stdexcept>

#ifndef __CatchiOS__Math__
#define __CatchiOS__Math__

class Math {
public:
    
    //  Takes a vector and generates its corresponding unit vector
    //  If zero vector is passed it will throw an invalid_argument exception
    static Vector2d* generateUnitVectorOf(Vector2d* vector) throw(std::invalid_argument);
};

#endif /* defined(__CatchiOS__Math__) */
