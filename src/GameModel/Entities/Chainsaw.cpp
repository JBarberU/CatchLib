//
//  File:       EventBus.hpp
//  Class:      EventBus
//  Author:     Jesper Persson and Sebastian Odbjer
//              All code is our own except where credited to others.
//
//	Copyright (c) 2012 by Catch22. All Rights Reserved.
//  Date: 		02/10-2012
//
//	License: The following code is licensed under the Catch22-License
//

#include "Chainsaw.hpp"
#include "../../EventHandling/EventBus.hpp"
#include "../../EventHandling/EEvent.hpp"

Chainsaw::Chainsaw (b2Vec2 size, b2Vec2 position,b2Vec2 target,  bool stationary, bool rotatable, PBodyType tag) :
    PBody(size, position, stationary, rotatable, tag)
{
    m_target = target;
    m_targetReached = false;
    EventBus::getSharedInstance()->publishEvent(PBODY_CREATED_PHYSICS, this);
}

void Chainsaw::setBody(b2Body* body)
{
    this->getBodyDefinition()->gravityScale = 0;
    PBody::setBody(body);
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


