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

void PBody::applyForce(float dt)
{
    *m_position += (Vector2d(m_movement) *= dt);
}
void PBody::revertForce(float dt)
{
    *m_position -= (Vector2d(m_movement) *= dt);
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
void PBody::resetMovementVector() {
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
PBody::PBody(bool affectedByGravity, Vector2d* position, Vector2d* size, Vector2d* movement)
{
    m_position = position;
    m_size = size;
    m_movement = movement;
    m_affectedByGravity = affectedByGravity;
}
bool PBody::isAffectedByGravity()
{
    return m_affectedByGravity;
}