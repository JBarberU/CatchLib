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
#include <Lodepng.hpp>


//  CLTexture
//  A struct used to represent an Image in a way that is 
//  relevant to OpenGL. It contains:
//  - internalFormat, which must be one of the following:
//          GL_ALPHA, GL_RGB, GL_RGBA, GL_LUMINANCE, GL_LUMINANCE_ALPHA
//  - width, the width of the image in pixels.
//  - height, the height of the image in pixels.
//  - type, can be one of the following:
//          GL_UNSIGNED_BYTE, GL_UNSIGNED_SHORT_5_6_5, 
//          GL_UNSIGNED_SHORT_4_4_4_4, GL_UNSIGNED_SHORT_5_5_5_1
//  - data, a pointer to the image data in memory.

struct CLTexture{
    GLint           internalFormat;
    GLsizei         width;
    GLsizei         height;
    GLenum          type;
    const GLvoid*   data;
};

//  FileManager
//  Used for managing the files (should have different 
//  implementation on different devices).
class FileManager {
private:
    const char* m_basePath;
    
public:
    
    FileManager(const char* basePath);
    ~FileManager();
    
    //  loadTextureFromFile
    //  Loads a CLTexture from the given filename which 
    //  is then ready for use with OpenGL.
    CLTexture* loadTextureFromFile(const char* file);
};
