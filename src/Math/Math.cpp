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

#include "../Helper/Logger.hpp"

Vector2d* Math::generateUnitVectorOf(Vector2d* vector) throw(std::invalid_argument)
{
    if (vector->m_x == 0 && vector->m_y == 0) {
        throw std::invalid_argument("Passed zero vector, your argument is invalid.");
    }
    
    float scalar = sqrtf((vector->m_x * vector->m_x) + (vector->m_y * vector->m_y));
    
    Vector2d* returnVector = new Vector2d(vector->m_x/scalar, vector->m_y/scalar);
    
    return returnVector;
}