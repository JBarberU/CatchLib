//
//  File:   IRenderer.h
//  Class:  IRenderer
//  Author: John Barbero Unenge
//          All code is my own except where credited to others.
//
//  Copyright (c) 2012 Catch22. All Rights Reserved.
//
//  Date:   1/10/12.
//
//	License: The following code is licensed under the Catch22-License
//
//  Description:
//  An interface used to provide basic rendering functionality.
//
#ifndef __IRenderer__
#define __IRenderer__

#include "Actor.hpp"
#include "CLTexture.hpp"
#include "../Controller/IDeviceRotationResponder.hpp"

class IRenderer : public IDeviceRotationResponder{
public:
    //  Initialize the renderer with the provided width, height and texture data.
    virtual void init(int width, int height, CLTexture* texture) = 0;
    
    //  Render one frame
    virtual void render() = 0;
    
    //  Update
    virtual void update(float dt) = 0;
    
    //  Add an actor, which is used to ecapsulate amimations.
    virtual void addActor(const Actor &actor) = 0;
    
    //  Remove the given actor.
    virtual void removeActor(const Actor &actor) = 0;
    
    virtual void centerCameraOn(Vector2d point) = 0;
    
};

//  Create an instance of IRenderer through GLRenderer10
IRenderer* CreateRendererWithOpenGL10();
//  Create an instance of IRenderer through GLRenderer20
IRenderer* CreateRendererWithOpenGL20();

#endif /* defined(__IRenderer__) */
