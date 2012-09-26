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
#include <GLES/gl.h>
#include <GLES/glext.h>
#endif

#ifndef CatchiOS_FileManager_h
#define CatchiOS_FileManager_h
struct Texture{
	GLint           internalFormat;
    GLsizei         width;
    GLsizei         height;
    GLenum          format;
    GLenum          type;
    const GLvoid*   data;
};

class GLRenderer {
public:
	GLRenderer();
	~GLRenderer();

	void init(int width, int height);
	void render();
    
private:
    GLuint BuildShader(const char* source, GLenum shaderType) const;
    GLuint BuildProgram(const char* vShader, const char* fShader) const;
    void ApplyOrtho(float maxX, float maxY) const;
    void GLRenderer::ApplyRotation(float degrees) const;
    
    GLuint m_simpleProgram;
    GLuint m_framebuffer;
    GLuint m_renderbuffer;
};


#endif
