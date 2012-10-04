//
//  IRenderer.h
//  CatchiOS
//
//  Created by John Barbero Unenge on 10/1/12.
//  Copyright (c) 2012 John Barbero Unenge. All rights reserved.
//

#ifndef __CatchiOS__IRenderer__
#define __CatchiOS__IRenderer__

class IRenderer {
public:
    virtual void init(int width, int height) = 0;
    virtual void render() = 0;
    virtual void update(float dt) = 0;
};

IRenderer* CreateRendererWithOpenGL10();
IRenderer* CreateRendererWithOpenGL20();

#endif /* defined(__CatchiOS__IRenderer__) */
