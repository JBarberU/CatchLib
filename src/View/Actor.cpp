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

Actor::Actor(const std::vector<Animation> &animations, int currentAnimationIndex, const Vector2d &halfSize, const OffsetMatrix &offsetMatrix)
{
    CreateActor(animations, currentAnimationIndex, halfSize, offsetMatrix);
}

Actor::Actor(const Actor &actor)
{
    CreateActor(actor.m_animations, actor.m_currentAnimationIndex, actor.m_halfSize, actor.m_offset);
}

void Actor::CreateActor(const std::vector<Animation> &animations, int currentAnimationIndex, const Vector2d &halfSize, const OffsetMatrix &offsetMatrix)
{
    m_pBody = 0;
    
    // Deep copy of the animations
    for (auto it = animations.begin(); it != animations.end(); it++)
    {
        // Create a copy of each of the given Animation
        m_animations.push_back(Animation(*it));
    }

    m_currentAnimationIndex = currentAnimationIndex;
    m_halfSize = halfSize;
    m_offset = offsetMatrix;
}

Actor::~Actor()
{
    // Do nothing at this point
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
        	/* Top right point */
            Vertex(m_pBody->getBody()->GetPosition().x + m_offset.m_topRight->m_x,
                   m_pBody->getBody()->GetPosition().y + m_halfSize.m_y * 2 + m_offset.m_topRight->m_y),
            /* Top left point */
            Vertex(m_pBody->getBody()->GetPosition().x + m_halfSize.m_x * 2 + m_offset.m_topLeft->m_x,
                   m_pBody->getBody()->GetPosition().y + m_halfSize.m_y * 2 + m_offset.m_topLeft->m_y),
			/* Bottom left point */
            Vertex(m_pBody->getBody()->GetPosition().x + m_halfSize.m_x * 2 + m_offset.m_bottomLeft->m_x,
                   m_pBody->getBody()->GetPosition().y + m_offset.m_bottomLeft->m_y),
			/* Bottom right point */
            Vertex(m_pBody->getBody()->GetPosition().x + m_offset.m_bottomRight->m_x,
                   m_pBody->getBody()->GetPosition().y + m_offset.m_bottomRight->m_y),
        };
        
        return v;
    }
    
    return 0;
}

bool Actor::isAnimationOK(const std::string &str)
{
    if (m_currentAnimationIndex >= m_animations.size()) {
        Log(LOG_ERROR, "Actor", (std::string("AnimationIndex > anmationsSize: ") + str).c_str());
        return false;
    }
    return true;
}

const Vertex* Actor::getTextureVertexData()
{
    if (!isAnimationOK("getTextureVertexData"))
        return 0;
    
    return m_animations.at(m_currentAnimationIndex).getTextureVertexData();
}
int Actor::getTextureID()
{
    if (!isAnimationOK("getTextureID"))
        return 0;

    return m_animations.at(m_currentAnimationIndex).getTextureID();
}
void Actor::update(float dt)
{
    if (!isAnimationOK())
        return;

    m_animations.at(m_currentAnimationIndex).update(dt);
}
float Actor::getAngle()
{
    return this->m_pBody->getBody()->GetAngle();
}
