//
//  Actor.cpp
//  CatchiOS
//
//  Created by John Barbero Unenge on 10/2/12.
//  Copyright (c) 2012 John Barbero Unenge. All rights reserved.
//

#include "Actor.hpp"
#include "../Helper/Logger.hpp"

const Vertex txPos[] = {
    Vertex(0.0f ,0.0f),
    Vertex(1.0f ,0.0f),
    Vertex(0.0f ,1.0f),
    Vertex(1.0f ,1.0f),
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