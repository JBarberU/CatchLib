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
    m_animations = animations;
    m_currentAnimation = currentAnimation;
}
Actor::Actor(Actor* actor)
{
    Animation** newAnimations = new Animation*[actor->m_animations->m_size];
    for (int i = 0; i < actor->m_animations->m_size; i++) {
        newAnimations[i] = new Animation(actor->m_animations->m_animationArray[i]);
    }
    
    m_animations = new AnimationArray(newAnimations, actor->m_animations->m_size);
    m_currentAnimation = m_animations->m_animationArray[0];
}
const Vertex* Actor::getVertexData()
{
    // Needs to keep track of a model object in order to do
    // something here :)
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