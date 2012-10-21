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

#include "../../../Box2D/Dynamics/b2Fixture.h"

PBody::PBody(b2PolygonShape shape, b2Vec2 position, bool stationary, bool rotatable, PBodyType tag)
{
    this->m_body = 0;
    
    this->m_shape = b2PolygonShape(shape);
    
    this->m_bodyDefinition.position = position;
    this->m_bodyDefinition.type = stationary ? b2_staticBody : b2_dynamicBody;
    this->m_bodyDefinition.fixedRotation = !rotatable;
    this->m_tag = tag;
    this->m_bodyDefinition.userData = &m_tag;
}
PBody::PBody(b2Vec2 size, b2Vec2 position, bool stationary, bool rotatable, PBodyType tag)
{
    this->m_body = 0;
    
    int32 num = 4;
    const b2Vec2* vertecies = new b2Vec2[num]{
        b2Vec2(0.f, 0.f),
        b2Vec2(size.x, 0.f),
        b2Vec2(size.x, size.y),
        b2Vec2(0.f, size.y),
    };
    
    this->m_shape.Set(vertecies, num);
    
    this->m_bodyDefinition.position = position;
    this->m_bodyDefinition.type = stationary ? b2_staticBody : b2_dynamicBody;
    this->m_bodyDefinition.fixedRotation = !rotatable;
    this->m_tag = tag;
    this->m_bodyDefinition.userData = &m_tag;
}
PBody::~PBody()
{}

PBodyType PBody::getTag()
{
    return *(PBodyType*)this->m_bodyDefinition.userData;
}
b2PolygonShape* PBody::getShape()
{
    return &this->m_shape;
}
b2Body* PBody::getBody()
{
    return this->m_body;
}
const b2Vec2 PBody::getPosition()
{
//    if (this->m_body == 0)
//        return m_bodyDefinition.position;

    return m_body->GetPosition();
}
b2BodyDef* PBody::getBodyDefinition()
{
    return &this->m_bodyDefinition;
}
void PBody::setBody(b2Body* body)
{
    this->m_body = body;
    
    b2FixtureDef fixDef;
    fixDef.shape = &this->m_shape;
    
    this->m_body->CreateFixture(&fixDef);
}