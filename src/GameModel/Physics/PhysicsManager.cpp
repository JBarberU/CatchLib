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

Vector2d* GRAVITY_VECTOR = new Vector2d(0.0, -0.5);
Vector2d* VECTOR_X_ONLY = new Vector2d(1,0);
Vector2d* VECTOR_Y_ONLY = new Vector2d(0.0,1);

const double FRICTION = 0.90;

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
        m_pBodyArray->m_bodies[i]->applyForce(dt);
    }
    
    for (int i = 0; i < m_pBodyArray->m_index; i++) {
        if (m_pBodyArray->m_bodies[i]->isStationary())
            continue;
        
        for (int j = 0; j < m_pBodyArray->m_index; j++) {
            if (m_pBodyArray->m_bodies[i] == m_pBodyArray->m_bodies[j])
                continue;
            
            Vector2d* collision = m_pBodyArray->m_bodies[i]->isCollidingWithBody(m_pBodyArray->m_bodies[j]);
            
            if (collision != 0) {
                if (collision->m_y != 0) {
                    m_pBodyArray->m_bodies[i]->maskMovementVector(FRICTION, 0);
                }
                m_pBodyArray->m_bodies[i]->translateBy(collision);
                Vector2d* applicationVector = new Vector2d(collision, 1.0);
                m_pBodyArray->m_bodies[i]->addVector(applicationVector);
                m_pBodyArray->m_bodies[i]->applyForce(dt);
                delete applicationVector;
            }
            
            delete collision;
        }
        
    }
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