//
//  File:		PlatformBlock.cpp
//  Class:      PlatformBlock
//  Author:     Sebastian Odbjer
//              All code is my own except where credited to others.
//
//	Copyright (c) 2012 by Catch22. All Rights Reserved.
//  Date: 		05/10-2012
//
//	License: The following code is licensed under the Catch22-License
//

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
    double x = this->m_body->getShape()->GetVertex(0).x + this->m_body->getPosition().x;
    double y = this->m_body->getShape()->GetVertex(0).y + this->m_body->getPosition().y;
    
    for (int i = 0; i < this->m_body->getShape()->GetVertexCount(); i++) {
        b2Vec2 v = this->m_body->getShape()->GetVertex(i);
        double vx = v.x + this->m_body->getPosition().x;
        double vy = v.y + this->m_body->getPosition().y;
        
        if (x > vx) {
            x = vx;
            y = vy;
        } else if (x == vx && y < vy) {
            y = vy;
        }
    }
	return new Vector2d(x,y);
}

Vector2d* PlatformBlock::getEndVector()
{
    double x = this->m_body->getShape()->GetVertex(0).x + this->m_body->getPosition().x;
    double y = this->m_body->getShape()->GetVertex(0).y + this->m_body->getPosition().y;
    
    for (int i = 0; i < this->m_body->getShape()->GetVertexCount(); i++) {
        b2Vec2 v = this->m_body->getShape()->GetVertex(i);
        double vx = v.x + this->m_body->getPosition().x;
        double vy = v.y + this->m_body->getPosition().y;
        
        if (x < vx) {
            x = vx;
            y = vy;
        } else if (x == vx && y < vy) {
            y = vy;
        }
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
    b2Vec2* vertecies = new b2Vec2[num];

    int max = (vector->m_y > endVector->m_y) ? vector->m_y : endVector->m_y;
    
    vertecies[0] = b2Vec2(2.f, 0.f);
    vertecies[1] = b2Vec2(2.f, 7.f - (max - endVector->m_y));
    vertecies[2] = b2Vec2(0.f, 7.f - (max - vector->m_y));
    vertecies[3] = b2Vec2(0.f, 0.f);

    b2Vec2 position = b2Vec2(vector->m_x, max - 7.f);

    b2PolygonShape shape;
    shape.Set(vertecies, num);
	
    PBody* body = new PBody(shape, position, true, false, type);
        
	return body;
}

