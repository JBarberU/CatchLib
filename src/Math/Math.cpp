//
//  File:	Math.cpp
//  Author: John Barbero Unenge 
//	Date:  	10/11/12.
//
//  Copyright (c) 2012 John Barbero Unenge. All rights reserved.
//
//	All code is my own except where credited to others.
//


#include "Math.hpp"
#include <math.h>

Vector2d* Math::generateUnitVectorOf(Vector2d* vector)
{
    if (vector->m_x == 0 && vector->m_y == 0) {
        return new Vector2d(0,0);
    }
    
    float scalar = sqrtf((vector->m_x * vector->m_x) + (vector->m_y * vector->m_y));
    
    Vector2d* returnVector = new Vector2d(vector->m_x/scalar, vector->m_y/scalar);
    
    return returnVector;
}