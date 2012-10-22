//
//  File:   FileManager.hpp
//  Class:  FileManager
//  Author: John Barbero Unenge
//      All code is my own except where credited to others.
//
//  Copyright (c) 2012 Catch22. All Rights Reserved.
//
//  Date: 17/9-2012
//
//	License: The following code is licensed under the Catch22-License
//
//  Description:
//  The purpose of FileManager is to provide a system specific 
//  filemanager. The C++ core declare the format in which it 
//  wants the data and each platform that uses the C++ core 
//  needs to implement this header in a suitable way.
//
#ifdef __APPLE__
#include <OpenGLES/ES1/gl.h>
#include <OpenGLES/ES1/glext.h>
#else
#include <GLES/gl.h>
#include <GLES/glext.h>
#endif

#include <string>
#include "../View/CLTexture.hpp"

class FileManager {

public:
    //  Loads a texture from file and stores it in a
    //  CLTexture which contains all the information
    //  needed to create an OpenGL texture.
    static CLTexture* loadTexture(const char* fileName);
};
