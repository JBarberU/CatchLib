//
//  Vector.cpp
//  CatchiOS
//
//  Created by John Barbero Unenge on 10/2/12.
//  Copyright (c) 2012 John Barbero Unenge. All rights reserved.
//

#include "Vector2d.hpp"

Vector2d::Vector2d(double x, double y)
{
    this->m_x = x;
    this->m_y = y;
}
Vector2d & Vector2d::operator=(const Vector2d& v)
{
    this->m_x = v.m_x;
    this->m_y = v.m_y;
    return *this;
}
bool Vector2d::operator==(const Vector2d& v)
{
    return (this->m_x == v.m_x && this->m_y == v.m_y);
}
Vector2d & Vector2d::operator+=(const Vector2d& v){
    this->m_x += v.m_x;
    this->m_y += v.m_y;
    return *this;
}
Vector2d & Vector2d::operator-=(const Vector2d& v){
    this->m_x -= v.m_x;
    this->m_y -= v.m_y;
    return *this;
}

Vector2d Vector2d::operator*=(double scale)
{
    this->m_x *=scale;
    this->m_y *=scale;
    return *this;
}