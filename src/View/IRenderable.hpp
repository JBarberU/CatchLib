//
//  IRenderable.hpp
//  CatchiOS
//
//  Created by John Barbero Unenge on 10/2/12.
//  Copyright (c) 2012 John Barbero Unenge. All rights reserved.
//

#ifndef CatchiOS_IRenderable_hpp
#define CatchiOS_IRenderable_hpp

#include "Vertex.hpp"

class IRenderable {
public:
    virtual const Vertex* getVertexData() = 0;
    virtual const Vertex* getTextureVertexData() = 0;
    virtual int getTextureID() = 0;
    virtual void update(float dt) = 0;
};

#endif
