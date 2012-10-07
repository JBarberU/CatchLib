//
//  FileManager.hpp
//  CatchLib
//
//  Created by John Barbero Unenge on 9/17/12.
//  Copyright (c) 2012 John Barbero Unenge. All rights reserved.
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

	void init(int width, int height, CLTexture* texture);
	void render();
    void update(float dt);
    void onRotate(DeviceOrientation orientation);
    
    virtual void addActor(Actor* actor);
    virtual void removeActor(Actor* actor);
    
private:
    GLuint BuildShader(const char* source, GLenum shaderType) const;
    GLuint BuildProgram(const char* vShader, const char* fShader) const;
    void ApplyOrtho(float maxX, float maxY) const;
    void ApplyRotation(float degrees) const;
    
    GLuint m_simpleProgram;
    GLuint m_framebuffer;
    GLuint m_renderbuffer;
};


#endif
