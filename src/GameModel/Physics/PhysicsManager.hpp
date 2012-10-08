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

#include "PBody.hpp"
#include "../../EventHandling/IEventListener.hpp"

struct PBodyArray {
    PBody** m_bodies;
    int m_index;
    int m_size;
    PBodyArray() {
        m_index = 0;
        m_size = 20;
        m_bodies = new PBody*[m_size];
    }
    ~PBodyArray() {
        delete [] m_bodies;
    }
};

class PhysicsManager : public IEventListener {
private:
    PBodyArray* m_pBodyArray;
    
    bool isColliding(PBody* b1, PBody* b2);
    
public:
    PhysicsManager();
    ~PhysicsManager();
    
    void update(float dt);
    
    void addPBody(PBody* pBody);
    void removePBody(PBody* pBody);
    
    void onEvent (EEvent event, void* source);
};

#include <iostream>

#endif /* defined(__CatchiOS__PhysicsManager__) */
