//
//  File:       EventBus.hpp
//  Class:      EventBus
//  Author:     Jesper Persson and Sebastian Odbjer
//              All code is our own except where credited to others.
//
//	Copyright (c) 2012 by Catch22. All Rights Reserved.
//  Date: 		02/10-2012
//
//	License: The following code is licensed under the Catch22-License
//
//  Description: A class for representing a chainsaw in the gameworld.
//  The chainsaw is a physical body, capable of moving in any given
//  direction, as well as colliding with other physical bodies.
//  The chainsaw is always moving towards a target, leaving for 
//  other classes to tell it what to do, if any, once the target is
//  reached.
//
//

#include "../Physics/PBody.hpp"

class Chainsaw : public PBody
{    
public:
    Chainsaw(b2Vec2 size, b2Vec2 position, b2Vec2 target, bool stationary, bool rotatable, PBodyType tag);
    ~Chainsaw();
    // Returns true if chainsaw has passed it's target.
    bool targetReached();
    void update();
    void setTarget(b2Vec2);
    void setBody(b2Body* body);
    
private:
    bool m_targetReached;
    b2Vec2 m_target;
};