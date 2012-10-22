//
//  File:       Chainsaw.hpp
//  Class:      Chainsaw
//  Author:     Jesper Persson
//              All code is our own except where credited to others.
//
//	Copyright (c) 2012 by Catch22. All Rights Reserved.
//  Date: 		22/10-2012
//
//	License: The following code is licensed under the Catch22-License
//

#include "Chainsaw.hpp"
#include "../../EventHandling/EventBus.hpp"
#include "../../EventHandling/EEvent.hpp"

double Chainsaw::CHAINSAW_MOVEMENT_SPEED = 10.0;

Chainsaw::Chainsaw (b2Vec2 size, b2Vec2 position,b2Vec2 target,  bool stationary, bool rotatable, PBodyType tag) :
    PBody(size, position, stationary, rotatable, tag)
{
    m_target = target;
    m_targetReached = false;
    EventBus::getSharedInstance()->publishEvent(PBODY_CREATED_PHYSICS, this);
}

bool Chainsaw::targetReached()
{
    return m_targetReached;
}

void Chainsaw::update(float dt)
{
}

void Chainsaw::setTarget(b2Vec2 target)
{
    m_target = target;
}

void Chainsaw::update(float dt)
{
    b2Vec2 dir = m_target - getPosition();
    dir.Normalize();
    dir.x *= CHAINSAW_MOVEMENT_SPEED * dt;
    dir.y *= CHAINSAW_MOVEMENT_SPEED * dt;
    
    this->getBody()->SetTransform(dir, 0.f);
}

void Chainsaw::setBody(b2Body* body)
{
    PBody::setBody(body);
    this->getBody()->SetGravityScale(0);
}


