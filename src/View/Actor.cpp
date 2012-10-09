//
//  File:   Actor.cpp
//  Class:  Actor
//  Author: John Barbero Unenge
//          All code is my own except where credited to others.
//
//  Copyright (c) 2012 Catch22. All Rights Reserved.
//
//  Date:   2/10/12
//


#include "Actor.hpp"
#include "../Helper/Logger.hpp"

//  Used until proper model object is used to track rendering location
const Vertex txPos[] = {
    Vertex(100.0f ,100.0f),
    Vertex(132.0f ,100.0f),
    Vertex(100.0f ,132.0f),
    Vertex(132.0f ,132.0f),
};

Actor::Actor(AnimationArray* animations, Animation* currentAnimation)
{
    m_pBody = 0;
    
    m_animations = animations;
    m_currentAnimation = currentAnimation;
}
Actor::Actor(Actor* actor)
{
    m_pBody = 0;
    
    Animation** newAnimations = new Animation*[actor->m_animations->m_size];
    for (int i = 0; i < actor->m_animations->m_size; i++) {
        newAnimations[i] = new Animation(actor->m_animations->m_animationArray[i]);
    }
    
    m_animations = new AnimationArray(newAnimations, actor->m_animations->m_size);
    m_currentAnimation = m_animations->m_animationArray[0];
}
void Actor::setPBody(PBody* pBody)
{
    m_pBody = pBody;
}
const Vertex* Actor::getVertexData()
{
    if (m_pBody != 0) {
        Vertex* v = new Vertex[4];
        v[0] = Vertex(m_pBody->getPosition()->m_x ,m_pBody->getPosition()->m_y);
        v[1] = Vertex(m_pBody->getPosition()->m_x + m_pBody->getSize()->m_x,m_pBody->getPosition()->m_y);
        v[2] = Vertex(m_pBody->getPosition()->m_x ,m_pBody->getPosition()->m_y + m_pBody->getSize()->m_y);
        v[3] = Vertex(m_pBody->getPosition()->m_x + m_pBody->getSize()->m_x,m_pBody->getPosition()->m_y + m_pBody->getSize()->m_y);
        
        return v;
    }
    
    return txPos;
}
const Vertex* Actor::getTextureVertexData()
{
    if (m_currentAnimation == 0) {
        Log(LOG_ERROR, "Actor", "Current animation null!");
        return 0;
    }
    
    return m_currentAnimation->getTextureVertexData();
}
int Actor::getTextureID()
{
    return m_currentAnimation->getTextureID();
}
void Actor::update(float dt){
    m_currentAnimation->update(dt);
}