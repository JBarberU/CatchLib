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

#include "IRenderer.hpp"

class GLRenderer10 : public IRenderer{
public:
	GLRenderer10();
	~GLRenderer10();

	void init(int width, int height);
	void render();
    void update(float dt);

private:
    GLuint m_framebuffer;
    GLuint m_renderbuffer;
};