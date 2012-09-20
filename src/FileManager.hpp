//
//  FileManager.hpp
//  CatchLib
//
//  Created by John Barbero Unenge on 9/17/12.
//  Copyright (c) 2012 John Barbero Unenge. All rights reserved.
//

#if TARGET_OS_IPHONE
#include <OpenGLES/ES1/glext.h>
#else
#include <GLES/gl.h>
#include <GLES/glext.h>
#endif

struct Texture{
    GLint           internalFormat;
    GLsizei         width;
    GLsizei         height;
    GLenum          format;
    GLenum          type;
    const GLvoid*   data;
};

class FileManager {
public:
    Texture* loadTextureFromFile(const char* file);
};
