//
//  FileManager.hpp
//  CatchLib
//
//  Created by John Barbero Unenge on 9/17/12.
//  Copyright (c) 2012 John Barbero Unenge. All rights reserved.
//

#ifdef __APPLE__
#include <OpenGLES/ES1/gl.h>
#include <OpenGLES/ES1/glext.h>
#else
#include <GLES/gl.h>
#include <GLES/glext.h>
#endif

struct CLTexture{
    GLint           internalFormat;
    GLsizei         width;
    GLsizei         height;
    GLenum          format;
    GLenum          type;
    const GLvoid*   data;
};
class FileManager {
public:
    CLTexture* loadTextureFromFile(const char* file);
};
