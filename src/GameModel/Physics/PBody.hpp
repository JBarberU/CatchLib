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
#include "../../../Box2D/Dynamics/b2Body.h"
#include "../../../Box2D/Collision/Shapes/b2PolygonShape.h"

class PBody
{
private:
    b2Body*                 m_body;
    b2PolygonShape          m_shape;
    b2BodyDef               m_bodyDefinition;
    PBodyType               m_tag;
    
public:
    PBody(b2PolygonShape shape, b2Vec2 position, bool stationary, bool rotatable, PBodyType tag);
    PBody(b2Vec2 size, b2Vec2 position, bool stationary, bool rotatable, PBodyType tag);
    ~PBody();
    
    b2PolygonShape* getShape();
    b2Body* getBody();
    const b2Vec2 getPosition();
    b2BodyDef* getBodyDefinition();
    void setBody(b2Body* body);
    
    PBodyType getTag();
};
