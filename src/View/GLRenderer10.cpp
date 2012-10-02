//
//  FileManager.hpp
//  CatchLib
//
//  Created by John Barbero Unenge on 9/17/12.
//  Copyright (c) 2012 John Barbero Unenge. All rights reserved.
//

#include "../Helper/Logger.hpp"
#include "GLRenderer10.hpp"
#include "Vertex.hpp"

// Define the positions and colors of two triangles.
const Vertex Vertecies[] = {
    {{-0.5f, -0.866f},  {1, 1, 0.5f, 1}},
    {{0.5f, -0.866f},   {1, 1, 0.5f, 1}},
    {{0, 1},            {1, 1, 0.5f, 1}},
    
    {{-0.5f, -0.866f},  {0.5f, 0.5f, 0.5f}},
    {{0.5f, -0.866f},   {0.5f, 0.5f, 0.5f}},
    {{0, -0.4f},        {0.5f, 0.5f, 0.5f}},
};

IRenderer* CreateRendererWithOpenGL10()
{
    return new GLRenderer10();
}

GLRenderer10::GLRenderer10()
{
    Log(LOG_INFO, "GLRenderer10", "Constructed a GLRenderer!");
#ifdef __APPLE__
    Log(LOG_INFO, "GLRenderer10", "Additional iOS setup!");
    glGenRenderbuffersOES(1, &m_renderbuffer);
    glBindRenderbufferOES(GL_RENDERBUFFER_OES, m_renderbuffer);
    
    // Create the framebuffer object and attach the color buffer.
    glGenFramebuffersOES(1, &m_framebuffer);
    glBindFramebufferOES(GL_FRAMEBUFFER_OES, m_framebuffer);
    glFramebufferRenderbufferOES(GL_FRAMEBUFFER_OES, GL_COLOR_ATTACHMENT0_OES, GL_RENDERBUFFER_OES, m_renderbuffer);
#endif
}
GLRenderer10::~GLRenderer10()
{
	Log(LOG_INFO, "GLRenderer10", "Destroyed a GLRenderer10!");
}


void GLRenderer10::init(int width, int height)
{
	Log(LOG_INFO, "GLRenderer10", generateCString("Init WH: %ix%i", width, height));
 
    glViewport(0, 0, width, height);
    
    glMatrixMode(GL_PROJECTION);
    
    // Initialize the projection matrix.
    const float maxX = 2;
    const float maxY = 3;
    glOrthof(-maxX, +maxX, -maxY, +maxY, -1, 1);
    
    glMatrixMode(GL_MODELVIEW);
}

void GLRenderer10::render()
{
    glClearColor(1, 0.5f, 0.5f, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    
    
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    
    glVertexPointer(2, GL_FLOAT, sizeof(Vertex), &Vertecies[0].Position[0]);
    glColorPointer(4, GL_FLOAT, sizeof(Vertex), &Vertecies[0].Color[0]);
    
    GLsizei vertexCount = sizeof(Vertecies) / sizeof(Vertex);
    glDrawArrays(GL_TRIANGLES, 0, vertexCount);
    
    glDisable(GL_VERTEX_ARRAY);
    glDisable(GL_COLOR_ARRAY);
}

void GLRenderer10::update(float dt)
{
    
}
