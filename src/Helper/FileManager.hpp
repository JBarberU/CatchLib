//
//  File:       FileManager.hpp
//  Class:      FileManager
//  Structs:    CLTexture
//  Author:     John Barbero Unenge
//              All code is my own except where credited to others.
//
//  Date: 17/9-2012
//
//  Description:
//  The purpose of FileManager is to provide a system specific 
//  filemanager. The C++ core declare the format in which it 
//  wants the data and each platform that uses the C++ core 
//  needs to implement this header in a suitable way.
//
//  Methods:
//
//  loadTextureFromFile
//    Loads a texture from a file with the given name.
//    The return of the function should be of the herin 
//    declared struct CLTexture, which is what the core 
//    needs for later binding OpenGL textures.
#ifdef __APPLE__
#include <OpenGLES/ES1/gl.h>
#include <OpenGLES/ES1/glext.h>
#else
#include <GLES/gl.h>
#include <GLES/glext.h>
#endif

#include <string>
#include "../View/SCLTexture.hpp"

//  FileManager
//  Used for managing the files (should have different 
//  implementation on different devices).
class FileManager {

public:
    static CLTexture* loadTexture(const char* fileName);
};
