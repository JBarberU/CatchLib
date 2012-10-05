//
//  IRenderer.h
//  CatchiOS
//
//  Created by John Barbero Unenge on 10/1/12.
//  Copyright (c) 2012 John Barbero Unenge. All rights reserved.
//

#ifndef __CatchiOS__IRenderer__
#define __CatchiOS__IRenderer__

#include "Actor.hpp"
#include "CLTexture.hpp"

struct ActorArray {
    Actor**  m_actors;
    int     m_size;
    int     m_index;
    ActorArray() {
        m_size = 20;
        m_index = 0;
        m_actors = new Actor*[m_size];
    }
};

class IRenderer {
public:
    virtual void init(int width, int height, CLTexture* texture) = 0;
    virtual void render() = 0;
    virtual void update(float dt) = 0;
    
    virtual void addActor(Actor* actor) = 0;
    virtual void removeActor(Actor* actor) = 0;
};

IRenderer* CreateRendererWithOpenGL10();
IRenderer* CreateRendererWithOpenGL20();

#endif /* defined(__CatchiOS__IRenderer__) */
