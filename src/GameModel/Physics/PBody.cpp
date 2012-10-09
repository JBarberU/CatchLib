//
//  File:       PBody.cpp
//  Class:      PBody
//  Author:     Jesper Persson
//              All code is my own except where credited to others.
//
//	Copyright (c) 2012 by Catch22. All Rights Reserved.
//  Date: 		29/09-2012
//

#include "PBody.hpp"
#include "../../Helper/Logger.hpp"

PBody::PBody(bool affectedByGravity, bool isStationary, Vector2d* position, Vector2d* size, Vector2d* movement)
{
    m_position = position;
    m_size = size;
    m_movement = movement;
    m_affectedByGravity = affectedByGravity;
    m_stationary = isStationary;
}
PBody::~PBody()
{
    delete m_position;
    delete m_size;
    delete m_movement;
}

void PBody::applyForce(float dt)
{
    *m_position += (*m_movement * dt);
}
void PBody::revertForce(float dt)
{
    *m_position -= (*m_movement * dt);
}
void PBody::addVector(Vector2d* vector)
{
    *m_movement += *vector;
    Log(LOG_INFO, "PBody", generateCString("AddingvectorY: %d Movement: %d", vector->m_y, m_movement->m_y));
}
void PBody::removeVector(Vector2d* vector)
{
    *m_movement -= *vector;
    Log(LOG_INFO, "PBody", generateCString("Removing vectorY: %d Movement: %d", vector->m_y, m_movement->m_y));
}
void PBody::resetMovementVector()
{
    this->m_movement->zap();
}

Vector2d* PBody::getPosition()
{
    return m_position;
}
Vector2d* PBody::getSize()
{
    return m_size;
}
bool PBody::isAffectedByGravity()
{
    return m_affectedByGravity;
}
bool PBody::isStationary()
{
    return m_stationary;
}
bool PBody::isColliding(PBody* otherBody)
{
    if (this->getPosition()->m_x + this->getSize()->m_x - 1 < otherBody->getPosition()->m_x)
        return false;
    if (this->getPosition()->m_y > otherBody->getPosition()->m_y + otherBody->getSize()->m_y - 1)
        return false;
    if (this->getPosition()->m_x > otherBody->getPosition()->m_x + otherBody->getSize()->m_x - 1)
        return false;
    if (this->getPosition()->m_y + this->getSize()->m_y - 1 < otherBody->getPosition()->m_y)
        return false;
    
    return true;
}
bool PBody::intersectionWithPoint(Vector2d* point)
{
    if (point->m_x < this->getPosition()->m_x)
        return false;
    if (point->m_y < this->getPosition()->m_y)
        return false;
    if (point->m_x > this->getPosition()->m_x + this->getSize()->m_x - 1)
        return false;
    if (point->m_y > this->getPosition()->m_y + this->getSize()->m_y - 1)
        return false;
    
    return true;
}
