//
//  File:   GLRenderer20.hpp
//  Class:  GLRenderer20
//  Author: John Barbero Unenge
//          All code is my own except where credited to others.
//
//  Copyright (c) 2012 Catch22. All Rights Reserved.
//
//  Date:   17/9/2012.
//
//	License: The following code is licensed under the Catch22-License
//
//  Description:
//  A class used for rendering with OpenGL ES 2.0. It implements
//  the functions in IRenderer.
//
#if __IPHONE_NA
#include <OpenGLES/ES2/gl.h>
#else
#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>
#endif

#include "CLTexture.hpp"
#include "IRenderer.hpp"

#ifndef CatchiOS_FileManager_h
#define CatchiOS_FileManager_h

class GLRenderer20 : public IRenderer {
public:
	GLRenderer20();
	~GLRenderer20();

    //  Inherited by IRenderer
	void init(int width, int height, CLTexture* texture);
	void render();
    void update(float dt);
    void onRotate(DeviceOrientation orientation);
    virtual void addActor(Actor* actor);
    virtual void removeActor(Actor* actor);
    virtual void centerCameraOn(Vector2d point);
    
private:
    //  Build a shader.
    GLuint BuildShader(const char* source, GLenum shaderType) const;
    
    //  Build a shader program from a vertex shader and a fragment shader.
    GLuint BuildProgram(const char* vShader, const char* fShader) const;
    
    //  Function to set ortho
    void ApplyOrtho(float maxX, float maxY) const;
    
    //  Function to apply rotation.
    void ApplyRotation(float degrees) const;
    
    GLuint m_simpleProgram;
    GLuint m_framebuffer;
    GLuint m_renderbuffer;
};


#endif
