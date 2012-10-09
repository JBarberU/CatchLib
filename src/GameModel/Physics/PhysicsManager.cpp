//
//  PhysicsManager.cpp
//  CatchiOS
//
//  Created by John Barbero Unenge on 10/7/12.
//  Copyright (c) 2012 John Barbero Unenge. All rights reserved.
//

#include "PhysicsManager.hpp"
#include "../../EventHandling/EventBus.hpp"
#include "../../Helper/Logger.hpp"

Vector2d * GRAVITY_VECTOR = new Vector2d(0.0, -15.0);

PhysicsManager::PhysicsManager()
{
    m_pBodyArray = 0;
    EventBus::getSharedInstance()->addEventListener(this);
}
PhysicsManager::~PhysicsManager()
{
    
}

void PhysicsManager::update(float dt)
{
    if (m_pBodyArray == 0) {
        Log(LOG_ERROR, "PhysicsManager", "PBodiesArray is null!");
        return;
    }
    
    for (int i = 0; i < m_pBodyArray->m_index; i++) {
        if (m_pBodyArray->m_bodies[i]->isAffectedByGravity()) {
            m_pBodyArray->m_bodies[i]->addVector(GRAVITY_VECTOR);
            m_pBodyArray->m_bodies[i]->applyForce(dt);
        }
    }
    for (int i = 0; i < m_pBodyArray->m_index; i++) {
        for (int j = 0; j < m_pBodyArray->m_index; j++) {
            if (m_pBodyArray->m_bodies[i]->isStationary() && m_pBodyArray->m_bodies[i] != m_pBodyArray->m_bodies[j] && m_pBodyArray->m_bodies[i]->isColliding(m_pBodyArray->m_bodies[j])) {
                if (m_pBodyArray->m_bodies[i]->isAffectedByGravity()) {
                    m_pBodyArray->m_bodies[i]->revertForce(dt);
                    m_pBodyArray->m_bodies[i]->resetMovementVector();
                }
                if (m_pBodyArray->m_bodies[j]->isAffectedByGravity()) {
                    m_pBodyArray->m_bodies[j]->revertForce(dt);
                    m_pBodyArray->m_bodies[j]->resetMovementVector();
                }
                PBody**  source = new PBody*[2];
                source[0] = m_pBodyArray->m_bodies[i];
                source[1] =  m_pBodyArray->m_bodies[j];
                EventBus::getSharedInstance()->publishEvent(DID_COLLIDE, source);
                delete [] source;
            }
        }
    }
//    Log(LOG_INFO, "PhysicsManager", "Updating");
}



void PhysicsManager::addPBody(PBody* pBody)
{
    if (m_pBodyArray == 0)
        m_pBodyArray = new PBodyArray();
    
    if (m_pBodyArray->m_index == m_pBodyArray->m_size) {
        m_pBodyArray->m_size += 20;
        PBody** newPBody = new PBody*[m_pBodyArray->m_size];
        for (int i = 0; i < m_pBodyArray->m_index; i++) {
            newPBody[i] = m_pBodyArray->m_bodies[i];
        }
        m_pBodyArray->m_bodies = newPBody;
    }
    
    m_pBodyArray->m_bodies[m_pBodyArray->m_index++] = pBody;
}

void PhysicsManager::removePBody(PBody* pBody)
{
    for (int i = 0; i < m_pBodyArray->m_index; i++) {
        if (m_pBodyArray->m_bodies[i] == pBody) {
            m_pBodyArray->m_bodies[i] = m_pBodyArray->m_bodies[--m_pBodyArray->m_index];
        }
    }
}

bool PhysicsManager::isColliding(PBody* b1, PBody* b2)
{
    if (b1->getPosition()->m_x + b1->getSize()->m_x < b2->getPosition()->m_x)
        return false;
    if (b1->getPosition()->m_y > b2->getPosition()->m_y + b2->getSize()->m_y)
        return false;
    if (b1->getPosition()->m_x > b2->getPosition()->m_x + b2->getSize()->m_x)
        return false;
    if (b1->getPosition()->m_y + b1->getSize()->m_y < b2->getPosition()->m_y)
        return false;
    
    return true;
}

void PhysicsManager::onEvent (EEvent event, void* source)
{
    if (event == PBODY_CREATED)
        this->addPBody((PBody *)source);
}