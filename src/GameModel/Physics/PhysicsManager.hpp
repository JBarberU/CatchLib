//
//  File:   PhysicsManager.hpp
//  Class:  PhysicsManager
//  Author: John Barbero Unenge
//          All code is my own except where credited to others.
//
//  Copyright (c) 2012 Catch22. All Rights Reserved.
//
//  Date:   7/10-2012
//
//  Description:
//  This is a class used for managing physics such as
//  collision and applying gravity.
//

#ifndef __CatchiOS__PhysicsManager__
#define __CatchiOS__PhysicsManager__

//  Catch22
#include "PBody.hpp"
#include "../../EventHandling/IEventListener.hpp"

//  Box2D
#include "../../../Box2D/Dynamics/b2Body.h"
#include "../../../Box2D/Dynamics/b2World.h"

//  Other
#include <vector>

class PhysicsManager : public IEventListener {
private:
    std::vector<PBody*>     m_pBodyArray;
    b2World*                m_world;
    
    void CreateWorld();
    
public:
    PhysicsManager();
    ~PhysicsManager();
    
    void update(float dt);
    
    void addPBody(PBody* pBody);
    void removePBody(PBody* pBody);
    
    void onEvent (EEvent event, void* source);
    
    void centerBodyAt(PBody body, Vector2d point);
};

#include <iostream>

#endif /* defined(__CatchiOS__PhysicsManager__) */
