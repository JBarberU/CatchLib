//
//  File:		PlatformBlock.cpp
//  Class:      PlatformBlock
//  Author:     Sebastian Odbjer
//              All code is my own except where credited to others.
//
//	Copyright (c) 2012 by Catch22. All Rights Reserved.
//  Date: 		05/10-2012

#include "PlatformBlock.hpp"
#include "../../EventHandling/EventBus.hpp"
#include "../../Helper/Logger.hpp"
#include "../../../Box2D/Collision/Shapes/b2PolygonShape.h"

PlatformBlock::PlatformBlock(Blocktype type, Vector2d* vector)
{
	this->m_type = type;
	this->m_body = generatePBody(vector);
	EventBus::getSharedInstance()->publishEvent(PBODY_CREATED_PHYSICS, (PBody *)m_body);
	//make something listen to this->body for collisions.

}

PlatformBlock::~PlatformBlock()
{

}

Vector2d* PlatformBlock::getStartVector()
{
    double x = this->m_body->getShape()->GetVertex(0).x;
    double y = this->m_body->getShape()->GetVertex(0).y;
    
    for (int i = 0; i < this->m_body->getShape()->GetVertexCount(); i++) {
        b2Vec2 v = this->m_body->getShape()->GetVertex(i);
        
        if (x < v.x)
            continue;
        
        if (y > v.y)
            continue;
        
        x = v.x;
        y = v.y;
    }
    
	return new Vector2d(x,y);
}

Vector2d* PlatformBlock::getEndVector()
{
    double x = this->m_body->getShape()->GetVertex(0).x;
    double y = this->m_body->getShape()->GetVertex(0).y;
    
    for (int i = 0; i < this->m_body->getShape()->GetVertexCount(); i++) {
        b2Vec2 v = this->m_body->getShape()->GetVertex(i);

        if (x > v.x)
            continue;
        
        if (y > v.y)
            continue;
        
        x = v.x;
        y = v.y;
    }
    
	return new Vector2d(x,y);
}

Blocktype PlatformBlock::getType()
{
	return m_type;
}

PBody* PlatformBlock::generatePBody(Vector2d* vector)
{
	Vector2d* endVector = new Vector2d(vector);
    PBodyType type;
	if(m_type == INCLINE) {
		//Set the end points at a set distance in x and y to create a 30 degree incline
		*endVector+=Vector2d(2, 1);
        type = PB_PLATFORM_1;
	} else if (m_type == DECLINE) {
		//Set the end points at a set distance in x and y to create a 30 degree decline
		*endVector+=Vector2d(2, -1);
        type = PB_PLATFORM_3;
	} else if (m_type == HORIZONTAL) {
		//Set the end points at a set distance in x and y to create a horizontal line
		*endVector+=Vector2d(2, 0);
        type = PB_PLATFORM_2;
	}
    
    int32 num = 4;
    const b2Vec2* vertecies = new b2Vec2[num]{
        b2Vec2(endVector->m_x, 0.f),
        b2Vec2(endVector->m_x, endVector->m_y),
        b2Vec2(vector->m_x, vector->m_y),
        b2Vec2(vector->m_x, 0.f),
    };
    
    b2Vec2 position;
    
    // Set position to origin
    position.Set((vector->m_x + endVector->m_x) / 2, (vector->m_y + endVector->m_y) / 2);
    
    b2PolygonShape shape;
    shape.Set(vertecies, num);
	
    PBody* body = new PBody(shape, position, true, false, type);
    
	return body;
}

