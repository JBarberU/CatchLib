//
//  Vector.cpp
//  CatchiOS
//
//  Created by John Barbero Unenge on 10/2/12.
//  Copyright (c) 2012 John Barbero Unenge. All rights reserved.
//

#include "Vector2d.hpp"
#include "Math.hpp"
#include <math.h>

Vector2d::Vector2d()
{
    this->m_x = 0;
    this->m_y = 0;
}
Vector2d::Vector2d(double x, double y)
{
    this->m_x = x;
    this->m_y = y;
}
Vector2d::Vector2d(Vector2d* vec)
{
    this->m_x = vec->m_x;
    this->m_y = vec->m_y;
}
Vector2d::Vector2d(Vector2d* vec, double magnitude)
{
    Vector2d* unitVector = Math::generateUnitVectorOf(vec);
        
    this->m_x = unitVector->m_x * magnitude;
    this->m_y = unitVector->m_y * magnitude;
    
    delete unitVector;
}

void Vector2d::zap()
{
    this->m_x = 0;
    this->m_y = 0;
}

double Vector2d::overlaps(Vector2d* otherVector)
{
    double tmpOver = 0;
    
    if (this->m_x < otherVector->m_x && this->m_y < otherVector->m_y) {
        tmpOver = this->m_y - otherVector->m_x;
    } else if (otherVector->m_x < this->m_x && otherVector->m_y < this->m_y) {
        tmpOver = otherVector->m_y - this->m_x;
    } else if (this->m_x > otherVector->m_x && this->m_y < otherVector->m_y) {
        tmpOver = this->m_y - this->m_x;
    } else if (otherVector->m_x > this->m_x && otherVector->m_y < this->m_y) {
        tmpOver = otherVector->m_y - this->m_x;
    }
    
    return tmpOver;
}

Vector2d Vector2d::operator=(Vector2d vector)
{
    this->m_x = vector.m_x;
    this->m_y = vector.m_y;
    return *this;
}
bool Vector2d::operator==(Vector2d vector)
{
    return (this->m_x == vector.m_x && this->m_y == vector.m_y);
}
Vector2d Vector2d::operator+=(Vector2d vector){
    this->m_x += vector.m_x;
    this->m_y += vector.m_y;
    return *this;
}
Vector2d Vector2d::operator-=(Vector2d vector){
    this->m_x -= vector.m_x;
    this->m_y -= vector.m_y;
    return *this;
}

Vector2d Vector2d::operator*=(double scale)
{
    this->m_x *=scale;
    this->m_y *=scale;
    return *this;
}
Vector2d Vector2d::operator*(double scale)
{
    return Vector2d(this->m_x * scale, this->m_y * scale);
}
Vector2d Vector2d::operator*(Vector2d vector)
{
    return Vector2d(this->m_x * vector.m_x, this->m_y * vector.m_y);
}

