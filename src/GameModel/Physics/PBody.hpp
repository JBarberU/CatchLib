//
//  File:       PBody.hpp
//  Class:      PBody
//  Author:     Jesper Persson
//              All code is my own except where credited to others.
//
//	Copyright (c) 2012 by Catch22. All Rights Reserved.
//  Date: 		29/09-2012
//
//  Description:
//	A class for representing a Physical Body.
//	All Physical Bodies will be solid (collidable) and affected by
//  in game physics. They will each have a position in the GameMap
//  and a directional vector.
//
//
#pragma once

#include "../../Math/Vector2d.hpp"
#include "EPBodyType.hpp"

struct Vector2dArray {
    Vector2d**  m_vectors;
    int         m_size;
    Vector2dArray(Vector2d** vectors, int size)
    {
        m_vectors = vectors;
        m_size = size;
    }
};

class PBody
{
private:
	Vector2dArray*  m_vectorArray;
    Vector2d*       m_centerOfMassOffset;
    bool            m_affectedByGravity;
    bool            m_stationaryObject;
    bool            m_rotatableObject;
    
    Vector2d*       m_movementVector;
    
    PBodyType       m_tag;
    
public:
	PBody(Vector2dArray* vectorArray, Vector2d* centerOfMassOffset, bool affectedByGravity, bool stationaryObject, bool rotatableObject, PBodyType tag);
    PBody(Vector2dArray* vectorArray, bool affectedByGravity, bool stationaryObject, bool rotatableObject, PBodyType tag);
    PBody(Vector2dArray* vectorArray, bool stationaryObject, PBodyType tag);
    PBody(Vector2d* position, Vector2d* size, bool affectedByGravity, bool stationaryObject, bool rotatableObject, PBodyType tag);
    ~PBody();
    
    virtual void applyForce(float dt);
    virtual void revertForce(float dt);
    virtual void applyForceWithMask(Vector2d* mask, float dt);
    virtual void revertForceWithMask(Vector2d* mask, float dt);
    void addVector(Vector2d* vector);
    void removeVector(Vector2d* vector);
    void resetMovementVector();
    void maskMovementVector(float x, float y);
    void rotateAround(Vector2d* pivotPoint, float degrees);
    void translateBy(Vector2d* vector);
    
    Vector2dArray* getVectorArray();
    
    bool isAffectedByGravity();
    bool isStationary();
    virtual Vector2d* isCollidingWithBody(PBody* otherBody);
    PBodyType getTag();
    Vector2d* getSize();
    Vector2d* getPosition();
    
    Vector2d** getAxes();
    Vector2d** getEdges();
    Vector2d* projectionOnVector(Vector2d* axis);
};
