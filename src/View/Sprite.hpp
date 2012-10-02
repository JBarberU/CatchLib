//
//  Sprite.hpp
//  CatchiOS
//
//  Created by John Barbero Unenge on 10/2/12.
//  Copyright (c) 2012 John Barbero Unenge. All rights reserved.
//

#ifndef __CatchiOS__Sprite__
#define __CatchiOS__Sprite__

#include "Vertex.hpp"

class Sprite {
private:
    int m_textureID;
    const Vertex *m_vertex;
    
public:
    Sprite(float spriteLocX, float spriteLocY,
           float spriteLocWidth, float spriteLocHeight,
           int textureID);
    ~Sprite();
    
    const Vertex* getVertexData();
    int getTextudeID();
};

#endif /* defined(__CatchiOS__Sprite__) */

