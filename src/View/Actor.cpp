//
//  Actor.cpp
//  CatchiOS
//
//  Created by John Barbero Unenge on 10/2/12.
//  Copyright (c) 2012 John Barbero Unenge. All rights reserved.
//

#include "Actor.hpp"

Actor::Actor(Animation** animations, Animation* currentAnimation)
{
    m_animations = animations;
    m_currentAnimation = currentAnimation;
}
const Vertex* Actor::getVertexData()
{
    // Needs to keep track of a model object in order to do
    // something here :)
    return 0;
}
const Vertex* Actor::getTextureVertexData()
{
    if (m_currentAnimation == 0)
        return 0;
    
    return m_currentAnimation->getTextureVertexData();
}
int Actor::getTextureID()
{
    return m_currentAnimation->getTextureID();
}
void Actor::update(float dt){
    m_currentAnimation->update(dt);
}