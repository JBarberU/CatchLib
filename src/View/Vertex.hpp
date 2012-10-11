//
//  File:   Vertex.h
//  Class:  Vertex
//  Author: John Barbero Unenge
//          All code is my own except for where credited to others.
//
//  Copyright (c) 2012 Catch22. All Rights Reserved.
//
//  Date:   2/10-2012
//
//  Description:
//  A simple data holder class for a vertex, holding position and color.
//

#ifndef CatchiOS_Vertex_h
#define CatchiOS_Vertex_h

struct Vertex {
public:
    float Position[2];
    float Color[4];
    Vertex(float x, float y) {
        Position[0] = x;
        Position[1] = y;
    }
    Vertex(){}
};

#endif
