//
//  File:   IRenderable.hpp
//  Class:  IRenderable
//  Author: John Barbero Unenge
//          All code is my own except where credited to others.
//
//  Copyright (c) 2012 Catch22. All Rights Reserved.
//
//  Date:   2/10-2012
//
//  Description:
//  This is an interface used for objects that can be rendered.
//

#ifndef CatchiOS_IRenderable_hpp
#define CatchiOS_IRenderable_hpp

#include "Vertex.hpp"

class IRenderable {
public:
    //  Get the geometric data for some renderable object.
    virtual const Vertex* getVertexData() = 0;
    
    //  Get the geometric data for the texture of some renderable object.
    virtual const Vertex* getTextureVertexData() = 0;
    
    //  Get the texture ID
    virtual int getTextureID() = 0;
    
    //  Respond to update
    virtual void update(float dt) = 0;

    //  Get the rotation angle of the renderable
    virtual float getAngle() = 0;
};

#endif
