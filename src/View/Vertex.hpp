//
//  Vertex.h
//  CatchiOS
//
//  Created by John Barbero Unenge on 10/2/12.
//  Copyright (c) 2012 John Barbero Unenge. All rights reserved.
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
    Vertex();
};

#endif
