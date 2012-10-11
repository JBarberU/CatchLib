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

Vector2d* GRAVITY_VECTOR = new Vector2d(0.0, -15.);
Vector2d* VECTOR_X_ONLY = new Vector2d(1,0);
Vector2d* VECTOR_Y_ONLY = new Vector2d(0,1);

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
        }
    }
    
    for (int i = 0; i < m_pBodyArray->m_index; i++) {
        if (!m_pBodyArray->m_bodies[i]->isStationary()) {
            
            if (m_pBodyArray->m_bodies[i]->isAffectedByGravity()) {
                m_pBodyArray->m_bodies[i]->applyForceWithMask(VECTOR_X_ONLY, dt);
            
            for (int j = 0; j < m_pBodyArray->m_index; j++) {
                if (m_pBodyArray->m_bodies[i] != m_pBodyArray->m_bodies[j] && m_pBodyArray->m_bodies[i]->isCollidingWithBody(m_pBodyArray->m_bodies[j])) {
                    m_pBodyArray->m_bodies[i]->revertForceWithMask(VECTOR_X_ONLY, dt);
                    Vector2d v = *GRAVITY_VECTOR * *VECTOR_X_ONLY;
                    m_pBodyArray->m_bodies[i]->removeVector(&v);
                    
                    // Extra logic when colliding on the X axis
                    m_pBodyArray->m_bodies[i]->maskMovementVector(0, 1);
                }
            }
            
            
            m_pBodyArray->m_bodies[i]->applyForceWithMask(VECTOR_Y_ONLY, dt);
            for (int j = 0; j < m_pBodyArray->m_index; j++) {
                if (m_pBodyArray->m_bodies[i] != m_pBodyArray->m_bodies[j] && m_pBodyArray->m_bodies[i]->isCollidingWithBody(m_pBodyArray->m_bodies[j])) {
                    m_pBodyArray->m_bodies[i]->revertForceWithMask(VECTOR_Y_ONLY, dt);
                    Vector2d v = *GRAVITY_VECTOR * *VECTOR_Y_ONLY;
                    m_pBodyArray->m_bodies[i]->removeVector(&v);
                    
                    // Extra logic when colliding on the Y axis
                    m_pBodyArray->m_bodies[i]->maskMovementVector(1, 0);
                }
                }
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

void PhysicsManager::onEvent (EEvent event, void* source)
{
    if (event == PBODY_CREATED)
        this->addPBody((PBody *)source);
}