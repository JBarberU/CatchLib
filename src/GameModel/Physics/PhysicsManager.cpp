//
//  PhysicsManager.cpp
//  CatchiOS
//
//  Created by John Barbero Unenge on 10/7/12.
//  Copyright (c) 2012 Catch22. All rights reserved.
//
//	License: The following code is licensed under the Catch22-License
//

#include "PhysicsManager.hpp"
#include "../../EventHandling/EventBus.hpp"
#include "../../Helper/Logger.hpp"
#include "../../Helper/Constants.hpp"

#include "../../../Box2D/Dynamics/b2Fixture.h"

#include <iterator>
const b2Vec2 GRAVITY_VECTOR = b2Vec2(0.f, -10.f);

PhysicsManager::PhysicsManager()
{
    this->m_world = new b2World(b2Vec2(GRAVITY_VECTOR));
    this->m_world->SetAllowSleeping(true);
//    this->CreateWorld();
    
    
    EventBus::getSharedInstance()->addEventListener(this);
}
PhysicsManager::~PhysicsManager()
{
    
}

void PhysicsManager::CreateWorld()
{
    b2BodyDef   bodyDef;
    bodyDef.type = b2_staticBody;
    bodyDef.position = b2Vec2(0.f, 0.f);
    
    b2FixtureDef fixDef;
    b2PolygonShape shape;
    
    b2Body* body = m_world->CreateBody(&bodyDef);
    
    shape.SetAsBox(Constants::getGameWidth(), 0, b2Vec2(Constants::getGameWidth()/2, 0.f), 0);
    body->SetUserData((void*)PB_DEADLY_SURFACE);
    fixDef.shape = &shape;
    body->CreateFixture(&fixDef);
    
    shape.SetAsBox(0.f, Constants::getGameHeight(), b2Vec2(0.f, Constants::getGameHeight()/2.f), 0.f);
    fixDef.shape = &shape;
    body->CreateFixture(&fixDef);
    
    shape.SetAsBox(0.f, Constants::getGameHeight(), b2Vec2(Constants::getGameWidth(), Constants::getGameHeight()/2.f), 0.f);
    fixDef.shape = &shape;
    body->CreateFixture(&fixDef);
    
}

void PhysicsManager::update(float dt)
{
    m_world->Step(dt, 1, 1);
}



void PhysicsManager::addPBody(PBody* pBody)
{
    this->m_pBodyArray.push_back(pBody);
    
    if (pBody->getBody() == 0) {
        pBody->setBody(m_world->CreateBody(pBody->getBodyDefinition()));
    }
    
    Log(LOG_INFO, "PhysicsManager", "Added PBody");
}

void PhysicsManager::removePBody(PBody* pBody)
{
    std::vector<PBody*>::iterator it;
    for (it = m_pBodyArray.begin(); it != m_pBodyArray.end(); ++it) {
        if (pBody == *it) {
            m_pBodyArray.erase(it);
        }
    }
}

void PhysicsManager::onEvent (EEvent event, void* source)
{
    if (event == PBODY_CREATED_PHYSICS) {
        this->addPBody((PBody *)source);
        EventBus::getSharedInstance()->publishEvent(PBODY_CREATED_ACTORS, source);
    }
}
