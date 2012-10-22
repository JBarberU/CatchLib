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
#include "../../Helper/Logger.hpp"
#include "../Physics/EPBodyType.hpp"

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
    
    Log(LOG_INFO, "Chainsaw", generateCString("The chainsaw is at position %d,%d ,  moving towards %d, %d" , getPosition().x, getPosition().y, m_target.x, m_target.y));
    this->getBody()->SetTransform(getPosition() + dir, 0.f);
    if (this->getPosition().x > m_target.x && this->getPosition().y > m_target.y){
        m_targetReached = true;
    }
}

void Chainsaw::setBody(b2Body* body)
{
    PBody::setBody(body);
    this->getBody()->SetGravityScale(0);
}

void Chainsaw::onCollide(PBody* other)
{
    if (other->getTag() == PB_PLATFORM_1 ||
        other->getTag() == PB_PLATFORM_2 ||
        other->getTag() == PB_PLATFORM_3) {
        m_targetReached = true;
    }
}


