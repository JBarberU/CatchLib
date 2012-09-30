//
//  FileManager.hpp
//  CatchLib
//
//  Created by John Barbero Unenge on 9/17/12.
//  Copyright (c) 2012 John Barbero Unenge. All rights reserved.
//

#if __APPLE__
#include <OpenGLES/ES2/gl.h>
#else
#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>
#endif

#include "SCLTexture.hpp"

#ifndef CatchiOS_FileManager_h
#define CatchiOS_FileManager_h

class GLRenderer {
public:
	GLRenderer();
	~GLRenderer();

	void init(int width, int height);
	void createFrameBuffer();
	void render();
        
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
