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

PBody::PBody(Vector2dArray* vectorArray, Vector2d* centerOfMassOffset, bool affectedByGravity, bool stationaryObject, bool rotatableObject, PBodyType tag)
{
    m_vectorArray = vectorArray;
    m_centerOfMassOffset = centerOfMassOffset;
    m_affectedByGravity = affectedByGravity;
    m_stationaryObject = stationaryObject;
    m_rotatableObject = rotatableObject;
    
    m_movementVector = new Vector2d(0,0);
    m_tag = tag;
}
PBody::PBody(Vector2dArray* vectorArray, bool affectedByGravity, bool stationaryObject, bool rotatableObject, PBodyType tag)
{
    m_vectorArray = vectorArray;
    m_centerOfMassOffset = new Vector2d(0,0);
    m_affectedByGravity = affectedByGravity;
    m_stationaryObject = stationaryObject;
    m_rotatableObject = rotatableObject;
    
    m_movementVector = new Vector2d(0,0);
    m_tag = tag;
}
PBody::PBody(Vector2dArray* vectorArray, bool stationaryObject, PBodyType tag)
{
    m_vectorArray = vectorArray;
    m_centerOfMassOffset = new Vector2d(0,0);
    m_affectedByGravity = !stationaryObject;
    m_stationaryObject = stationaryObject;
    m_rotatableObject = !stationaryObject;
    
    m_movementVector = new Vector2d(0,0);
    m_tag = tag;
}
PBody::PBody(Vector2d* position, Vector2d* size, bool affectedByGravity, bool stationaryObject, bool rotatableObject, PBodyType tag)
{
    Vector2d** vArr = new Vector2d*[4];
    vArr[0] = new Vector2d(position->m_x, position->m_y);
    vArr[1] = new Vector2d(position->m_x + size->m_x, position->m_y);
    vArr[2] = new Vector2d(position->m_x, position->m_y + size->m_y);
    vArr[3] = new Vector2d(position->m_x + size->m_x, position->m_y + size->m_y);
    
    m_vectorArray = new Vector2dArray(vArr, 4);
    m_centerOfMassOffset = new Vector2d(0,0);
    m_affectedByGravity = affectedByGravity;
    m_stationaryObject = stationaryObject;
    m_rotatableObject = rotatableObject;
    
    m_movementVector = new Vector2d(0,0);
    m_tag = tag;
}

PBody::~PBody()
{

    delete m_centerOfMassOffset;
    delete m_movementVector;
    delete m_vectorArray;
}

void PBody::applyForce(float dt)
{
    for (int i = 0; i < m_vectorArray->m_size; i++) {
        m_vectorArray->m_vectors[i]->m_x += (m_movementVector->m_x * dt);
        m_vectorArray->m_vectors[i]->m_y += (m_movementVector->m_y * dt);
    }
}
void PBody::revertForce(float dt)
{
    for (int i = 0; i < m_vectorArray->m_size; i++) {
        m_vectorArray->m_vectors[i]->m_x -= (m_movementVector->m_x * dt);
        m_vectorArray->m_vectors[i]->m_y -= (m_movementVector->m_y * dt);
    }
}
void PBody::applyForceWithMask(Vector2d* mask, float dt)
{
    for (int i = 0; i < m_vectorArray->m_size; i++) {
        m_vectorArray->m_vectors[i]->m_x += ((m_movementVector->m_x * mask->m_x) * dt);
        m_vectorArray->m_vectors[i]->m_y += ((m_movementVector->m_y * mask->m_y) * dt);
    }
}
void PBody::revertForceWithMask(Vector2d* mask, float dt)
{
    for (int i = 0; i < m_vectorArray->m_size; i++) {
        m_vectorArray->m_vectors[i]->m_x -= ((m_movementVector->m_x * mask->m_x) * dt);
        m_vectorArray->m_vectors[i]->m_y -= ((m_movementVector->m_y * mask->m_y) * dt);
    }
}
void PBody::addVector(Vector2d* vector)
{
    *m_movementVector += *vector;
}
void PBody::removeVector(Vector2d* vector)
{
    *m_movementVector -= vector;
}
void PBody::resetMovementVector()
{
    m_movementVector = new Vector2d(0,0);
}
void PBody::maskMovementVector(float x, float y)
{
    this->m_movementVector->m_x *= x;
    this->m_movementVector->m_y *= y;
}
void PBody::rotateAround(Vector2d* pivotPoint, float degrees)
{
    // Implement me plxzz
}
void PBody::translateBy(Vector2d* vector)
{
    // Implement me plxzz
}


Vector2dArray* PBody::getVectorArray()
{
    return m_vectorArray;
}

bool PBody::isAffectedByGravity()
{
    return m_affectedByGravity;
}
bool PBody::isStationary()
{
    return m_stationaryObject;
}
bool PBody::isCollidingWithBody(PBody* otherBody)
{
    float min_x_1 = this->m_vectorArray->m_vectors[0]->m_x;
    float max_x_1 = this->m_vectorArray->m_vectors[0]->m_x;
    float min_x_2 = otherBody->m_vectorArray->m_vectors[0]->m_x;
    float max_x_2 = otherBody->m_vectorArray->m_vectors[0]->m_x;
    
    float min_y_1 = this->m_vectorArray->m_vectors[0]->m_y;
    float max_y_1 = this->m_vectorArray->m_vectors[0]->m_y;
    float min_y_2 = otherBody->m_vectorArray->m_vectors[0]->m_y;
    float max_y_2 = otherBody->m_vectorArray->m_vectors[0]->m_y;
    
    for (int i = 0; i < this->m_vectorArray->m_size; i++) {
        min_x_1 = min_x_1 > this->m_vectorArray->m_vectors[i]->m_x ? this->m_vectorArray->m_vectors[i]->m_x : min_x_1;
        max_x_1 = max_x_1 < this->m_vectorArray->m_vectors[i]->m_x ? this->m_vectorArray->m_vectors[i]->m_x : max_x_1;
        
        min_y_1 = min_y_1 > this->m_vectorArray->m_vectors[i]->m_y ? this->m_vectorArray->m_vectors[i]->m_y : min_y_1;
        max_y_1 = max_y_1 < this->m_vectorArray->m_vectors[i]->m_y ? this->m_vectorArray->m_vectors[i]->m_y : max_y_1;
    }
        
    for (int i = 0; i < otherBody->m_vectorArray->m_size; i++) {
        min_x_2 = min_x_2 > otherBody->m_vectorArray->m_vectors[i]->m_x ? otherBody->m_vectorArray->m_vectors[i]->m_x : min_x_2;
        max_x_2 = max_x_2 < otherBody->m_vectorArray->m_vectors[i]->m_x ? otherBody->m_vectorArray->m_vectors[i]->m_x : max_x_2;
        
        min_y_2 = min_y_2 > otherBody->m_vectorArray->m_vectors[i]->m_y ? otherBody->m_vectorArray->m_vectors[i]->m_y : min_y_2;
        max_y_2 = max_y_2 < otherBody->m_vectorArray->m_vectors[i]->m_y ? otherBody->m_vectorArray->m_vectors[i]->m_y : max_y_2;
    }
    
    if (!((min_x_1 < min_x_2 && max_x_1 < min_x_2) || (min_x_2 < min_x_1 && max_x_2 < min_x_1)))
        if (!((min_y_1 < min_y_2 && max_y_1 < min_y_2) || (min_y_2 < min_y_1 && max_y_2 < min_y_1))) {
            return true;
        }
    return false;
}
PBodyType PBody::getTag()
{
    return m_tag;
}