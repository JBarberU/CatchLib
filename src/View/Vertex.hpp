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
//	License: The following code is licensed under the Catch22-License
//
//  Description:
//  A simple data holder class for a vertex, holding position and color.
//

#ifndef __Vertex__
#define __Vertex__

struct Vertex {
public:
    float Position[2];
    float Color[4];
    Vertex(float x, float y) {
        Position[0] = x;
        Position[1] = y;
    }
    Vertex(){}
    Vertex(Vertex* v) {
        Position[0] = v->Position[0];
        Position[1] = v->Position[1];
    }
};

#endif /* defined(__Vertex__) */
