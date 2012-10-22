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
//	License: The following code is licensed under the Catch22-License
//


#include "Actor.hpp"
#include "../Helper/Logger.hpp"
#include "../Helper/Constants.hpp"

Actor::Actor(AnimationArray* animations, Animation* currentAnimation, Vector2d* halfSize, OffsetMatrix* offsetMatrix)
{
    CreateActor(animations, currentAnimation, halfSize, offsetMatrix);
}
Actor::Actor(AnimationArray* animations, Animation* currentAnimation, Vector2d* halfSize)
{
    CreateActor(animations, currentAnimation, halfSize, new OffsetMatrix(new Vector2d(0.f, 0.f), new Vector2d(0.f, 0.f), new Vector2d(0.f, 0.f), new Vector2d(0.f, 0.f)));
}
Actor::Actor(Actor* actor)
{
    CreateActor(new AnimationArray(actor->m_animations), new Animation(actor->m_currentAnimation), new Vector2d(actor->m_halfSize), new OffsetMatrix(actor->m_offset));
}
void Actor::CreateActor(AnimationArray* animations, Animation* currentAnimation, Vector2d* halfSize, OffsetMatrix* offsetMatrix)
{
    m_pBody = 0;
    
    m_animations = animations;
    m_currentAnimation = currentAnimation;
    m_halfSize = halfSize;
    m_offset = offsetMatrix;
}

void Actor::setPBody(PBody* pBody)
{
    m_pBody = pBody;
}
const Vertex* Actor::getVertexData()
{    
    if (m_pBody != 0) {
        
        const Vertex* v = new const Vertex[4]
        {
            Vertex(m_pBody->getBody()->GetPosition().x - m_offset->m_topLeft->m_x,
                   m_pBody->getBody()->GetPosition().y + m_halfSize->m_y * 2 + m_offset->m_topLeft->m_y),
            Vertex(m_pBody->getBody()->GetPosition().x + m_halfSize->m_x * 2 + m_offset->m_topRight->m_x,
                   m_pBody->getBody()->GetPosition().y + m_halfSize->m_y * 2 + m_offset->m_topRight->m_y),
            Vertex(m_pBody->getBody()->GetPosition().x + m_halfSize->m_x * 2 + m_offset->m_bottomRight->m_x,
                   m_pBody->getBody()->GetPosition().y - m_offset->m_bottomRight->m_y),
            Vertex(m_pBody->getBody()->GetPosition().x - m_offset->m_bottomLeft->m_x,
                   m_pBody->getBody()->GetPosition().y - m_offset->m_bottomLeft->m_y),
        };
        
        return v;
    }
    
    return 0;
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
float Actor::getAngle()
{
    return this->m_pBody->getBody()->GetAngle();
}
