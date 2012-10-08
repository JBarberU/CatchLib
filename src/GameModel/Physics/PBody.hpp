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

#include "Vector2d.hpp"

class PBody
{
private:
	Vector2d* m_position;
    Vector2d* m_size;
    bool m_affectedByGravity;
    
public:
//  FIXME: Should be made private again
    Vector2d* m_movement;

    
	~PBody();
	PBody(bool affectedByGravity, Vector2d* position, Vector2d* size, Vector2d* movement);
    
    void applyForce(float dt);
    void revertForce(float dt);
    void addVector(Vector2d* vector);
    void removeVector(Vector2d* vector);
    void resetMovementVector();
    Vector2d* getPosition();
    Vector2d* getSize();
    bool isAffectedByGravity();
    bool isStationary();
    bool isColliding(PBody* otherBody);
    bool intersectionWithPoint(Vector2d* point);
};
