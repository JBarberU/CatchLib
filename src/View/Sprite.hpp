//
//  File:   Sprite.hpp
//  Class:  Sprite
//  Author: John Barbero Unenge
//          All code is my own except where credited to others.
//
//  Copyright (c) 2012 Catch22. All Rights Reserved.
//
//  Date:   2/10-2012
//
//	License: The following code is licensed under the Catch22-License
//
//  Description:
//  A class used to hold sprite data. That is what texture
//  it's supposed to use and and what part of it to use. This
//  is analog to a frame of a movie animation.
//

#ifndef __CatchiOS__Sprite__
#define __CatchiOS__Sprite__

#include "Vertex.hpp"

class Sprite {
private:
    int             m_textureID;
    const Vertex*   m_vertex;
    
public:
    Sprite(float spriteLocX, float spriteLocY, float spriteLocWidth, float spriteLocHeight, int textureID, bool mirror);
    Sprite(Sprite* sprite);
    Sprite(Vertex* vertecies, int num_vertecies, int textureID);
    ~Sprite();
    
    //  Get the geomertic data for the texture.
    const Vertex* getTextureVertexData();
    
    //  Get the texture to use.
    int getTextureID();
};

#endif /* defined(__CatchiOS__Sprite__) */

