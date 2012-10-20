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
#include "../../Math/Math.hpp"

PBody::PBody(Vector2dArray* vectorArray, Vector2d* centerOfMassOffset, bool affectedByGravity, bool stationaryObject, bool rotatableObject, PBodyType tag)
{
    m_vectorArray = vectorArray;
    m_centerOfMassOffset = centerOfMassOffset;
    m_affectedByGravity = affectedByGravity;
    m_stationaryObject = stationaryObject;
    m_rotatableObject = rotatableObject;
    
    m_movementVector = new Vector2d(0.0,0.0);
    m_tag = tag;
}
PBody::PBody(Vector2dArray* vectorArray, bool affectedByGravity, bool stationaryObject, bool rotatableObject, PBodyType tag)
{
    m_vectorArray = vectorArray;
    m_centerOfMassOffset = new Vector2d(0.0,0.0);
    m_affectedByGravity = affectedByGravity;
    m_stationaryObject = stationaryObject;
    m_rotatableObject = rotatableObject;
    
    m_movementVector = new Vector2d(0.0,0.0);
    m_tag = tag;
}
PBody::PBody(Vector2dArray* vectorArray, bool stationaryObject, PBodyType tag)
{
    m_vectorArray = vectorArray;
    m_centerOfMassOffset = new Vector2d(0.0,0.0);
    m_affectedByGravity = !stationaryObject;
    m_stationaryObject = stationaryObject;
    m_rotatableObject = !stationaryObject;
    
    m_movementVector = new Vector2d(0.0,0.0);
    m_tag = tag;
}
PBody::PBody(Vector2d* position, Vector2d* size, bool affectedByGravity, bool stationaryObject, bool rotatableObject, PBodyType tag)
{
    Vector2d** vArr = new Vector2d*[4];
    vArr[0] = new Vector2d(position->m_x, position->m_y);
    vArr[1] = new Vector2d(position->m_x, position->m_y + size->m_y);
    vArr[2] = new Vector2d(position->m_x + size->m_x, position->m_y + size->m_y);
    vArr[3] = new Vector2d(position->m_x + size->m_x, position->m_y);
    
    m_vectorArray = new Vector2dArray(vArr, 4);
    m_centerOfMassOffset = new Vector2d(0.0,0.0);
    m_affectedByGravity = affectedByGravity;
    m_stationaryObject = stationaryObject;
    m_rotatableObject = rotatableObject;
    
    m_movementVector = new Vector2d(0.0,0.0);
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
    
    Log(LOG_INFO, "PBody", generateCString("Applying force: %d,%d", this->m_movementVector->m_x, this->m_movementVector->m_y));
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
    m_movementVector = new Vector2d(0.0,0.0);
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
    for (int i = 0; i < this->m_vectorArray->m_size; i++) {
        *this->m_vectorArray->m_vectors[i] += *vector;
    }
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
Vector2d* PBody::isCollidingWithBody(PBody* otherBody)
{
//    for (int a = 0; a < this->m_vectorArray->m_size; a++) {
//        Vector2d* v = new Vector2d();
//    }
    
    Vector2d** axes1 = this->getAxes();
    Vector2d** axes2 = otherBody->getAxes();
    
    double overlap = -1;
    Vector2d* smallestAxis = 0;
    
    Vector2d* axis;
    Vector2d* proj1;
    Vector2d* proj2;
    
    double tmpOver;
    for (int a = 0; a < this->m_vectorArray->m_size; a++) {
        axis = axes1[a];
        
        
        proj1 = this->projectionOnVector(axis);
        proj2 = otherBody->projectionOnVector(axis);
        
        if ((proj1->m_x < proj2->m_x && proj1->m_y < proj2->m_x) || (
            proj2->m_x < proj1->m_x && proj2->m_y < proj1->m_x)) {

            delete proj1;
            delete proj2;
            
            for (int i = 0; i < this->m_vectorArray->m_size; i++)
                delete [] axes1[i];
            
            delete [] axes1;
            
            for (int i = 0; i < otherBody->m_vectorArray->m_size; i++)
                delete [] axes2[i];
            
            delete [] axes2;
            
            return 0;
        } else {
            if (proj1->m_y > proj2->m_x && proj2->m_y > proj1->m_y) {
                tmpOver = proj1->m_y - proj2->m_x;
            }
            else if (proj2->m_y > proj1->m_x && proj1->m_y > proj2->m_y) {
                tmpOver = proj2->m_y - proj1->m_x;
            }
            else if (proj1->m_x > proj2->m_x && proj1->m_y < proj2->m_y) {
                tmpOver = proj1->m_y-proj1->m_x;
            }
            else if (proj2->m_x > proj1->m_x && proj2->m_y < proj1->m_y) {
                tmpOver = proj2->m_y-proj2->m_x;
            }
            
            if (overlap == -1 || tmpOver < overlap) {
                overlap = tmpOver;
                smallestAxis = axis;
            }
        }
        
        delete proj1;
        delete proj2;
        
    }
    
    for (int a = 0; a < otherBody->m_vectorArray->m_size; a++) {
        axis = axes2[a];
        
        proj1 = this->projectionOnVector(axis);
        proj2 = otherBody->projectionOnVector(axis);
        
        if ((proj1->m_x < proj2->m_x && proj1->m_y < proj2->m_x) ||
            (proj2->m_x < proj1->m_x && proj2->m_y < proj1->m_x)) {
            delete proj1;
            delete proj2;
            
            for (int i = 0; i < this->m_vectorArray->m_size; i++)
                delete [] axes1[i];
            
            delete [] axes1;
            
            for (int i = 0; i < otherBody->m_vectorArray->m_size; i++)
                delete [] axes2[i];
            
            delete [] axes2;
            
            return 0;
        } else {
            if (proj1->m_y > proj2->m_x && proj2->m_y > proj1->m_y) {
                tmpOver = proj1->m_y - proj2->m_x;
            }
            else if (proj2->m_y > proj1->m_x && proj1->m_y > proj2->m_y) {
                tmpOver = proj2->m_y - proj1->m_x;
            }
            else if (proj1->m_x > proj2->m_x && proj1->m_y < proj2->m_y) {
                tmpOver = proj1->m_y-proj1->m_x;
            }
            else if (proj2->m_x > proj1->m_x && proj2->m_y < proj1->m_y) {
                tmpOver = proj2->m_y-proj2->m_x;
            }
            
            if (overlap == -1 || tmpOver < overlap) {
                overlap = tmpOver;
                smallestAxis = axis;
            }
        }
        
        delete proj1;
        delete proj2;
    }
    
    Vector2d* returnVector = new Vector2d(smallestAxis, overlap);
    
    
    for (int i = 0; i < this->m_vectorArray->m_size; i++)
        delete [] axes1[i];
    
    delete [] axes1;
    
    for (int i = 0; i < otherBody->m_vectorArray->m_size; i++)
        delete [] axes2[i];
    
    delete [] axes2;
    
    return returnVector;
}
PBodyType PBody::getTag()
{
    return m_tag;
}
Vector2d* PBody::getSize()
{
    double xmin = this->m_vectorArray->m_size > 0 ? this->m_vectorArray->m_vectors[0]->m_x : 0;
    double xmax = this->m_vectorArray->m_size > 0 ? this->m_vectorArray->m_vectors[0]->m_x : 0;
    double ymin = this->m_vectorArray->m_size > 0 ? this->m_vectorArray->m_vectors[0]->m_y : 0;
    double ymax = this->m_vectorArray->m_size > 0 ? this->m_vectorArray->m_vectors[0]->m_y : 0;
    
    for (int i = 0; i < this->m_vectorArray->m_size; i++) {
        xmin = this->m_vectorArray->m_vectors[i]->m_x < xmin ? this->m_vectorArray->m_vectors[i]->m_x : xmin;
        ymin = this->m_vectorArray->m_vectors[i]->m_y < ymin ? this->m_vectorArray->m_vectors[i]->m_y : ymin;
        
        xmax = this->m_vectorArray->m_vectors[i]->m_x > xmax ? this->m_vectorArray->m_vectors[i]->m_x : xmax;
        ymax = this->m_vectorArray->m_vectors[i]->m_y > ymax ? this->m_vectorArray->m_vectors[i]->m_y : ymax;
    }
    
    return new Vector2d(xmax - xmin, ymax - ymin);
}
Vector2d* PBody::getPosition()
{
    double x = this->m_vectorArray->m_size > 0 ? this->m_vectorArray->m_vectors[0]->m_x : 0;
    double y = this->m_vectorArray->m_size > 0 ? this->m_vectorArray->m_vectors[0]->m_y : 0;
    
    for (int i = 0; i < this->m_vectorArray->m_size; i++) {
        x = this->m_vectorArray->m_vectors[i]->m_x < x ? this->m_vectorArray->m_vectors[i]->m_x : x;
        y = this->m_vectorArray->m_vectors[i]->m_y < y ? this->m_vectorArray->m_vectors[i]->m_y : y;
    }
    
    return new Vector2d(x, y);
}

Vector2d** PBody::getAxes()
{
    Vector2d** edges = this->getEdges();
    Vector2d** axes = new Vector2d*[this->m_vectorArray->m_size];
    
    for (int i = 0; i < this->m_vectorArray->m_size; i++) {
        Vector2d* v = new Vector2d(edges[i]->m_y, -edges[i]->m_x);
        axes[i] = Math::generateUnitVectorOf(v);
        delete v;
        delete [] edges[i];
    }
    
    delete [] edges;
    
    return axes;
}

Vector2d** PBody::getEdges()
{
    Vector2d** edges = new Vector2d*[this->m_vectorArray->m_size];
    
    for (int a = 0; a < this->m_vectorArray->m_size; a++) {
        Vector2d* p1 = this->m_vectorArray->m_vectors[a];
        Vector2d* p2 = this->m_vectorArray->m_vectors[a + 1 == this->m_vectorArray->m_size ? 0 : a + 1];
        
        edges[a] = new Vector2d(p1->m_x - p2->m_x, p1->m_y - p2->m_y);
    }
    
    return edges;
}
Vector2d* PBody::projectionOnVector(Vector2d* axis)
{
    double min = this->m_vectorArray->m_vectors[0]->m_x*axis->m_x + this->m_vectorArray->m_vectors[0]->m_y*axis->m_y;
    double max = min;
    
    for (int i = 0; i < this->m_vectorArray->m_size; i++) {
        double dot = this->m_vectorArray->m_vectors[i]->m_x*axis->m_x + this->m_vectorArray->m_vectors[i]->m_y*axis->m_y;
        
        min = min < dot ? min : dot;
        max = max < dot ? dot : max;
    }
    return new Vector2d(min, max);
}
