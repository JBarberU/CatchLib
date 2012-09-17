//
//  FileManager.h
//  CatchiOS
//
//  Created by John Barbero Unenge on 9/17/12.
//  Copyright (c) 2012 John Barbero Unenge. All rights reserved.
//

#include <OpenGLES/ES1/gl.h>
#include <OpenGLES/ES1/glext.h>
#include <OpenGLES/ES1/glut.h>

#ifndef CatchiOS_FileManager_h
#define CatchiOS_FileManager_h
struct Texture{
    int     width;
    int     height;
    void*   pixels;
    int     type;
};

class FileManager {
    Texture* loadTextureFromFile(const char* file);
};


#endif
