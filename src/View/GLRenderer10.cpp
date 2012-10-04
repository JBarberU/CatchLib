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
#include "../Helper/FileManager.hpp"

// Define the positions and colors of two triangles.
const Vertex Vertecies[] = {
    {{-0.5f, -0.866f},  {1, 1, 0.5f, 1}},
    {{0.5f, -0.866f},   {1, 1, 0.5f, 1}},
    {{0, 1},            {1, 1, 0.5f, 1}},
    
    {{-0.5f, -0.866f},  {0.5f, 0.5f, 0.5f}},
    {{0.5f, -0.866f},   {0.5f, 0.5f, 0.5f}},
    {{0, -0.4f},        {0.5f, 0.5f, 0.5f}},
};

const Vertex shape[] = {
    {{0,0}, {1,1,1,1}},
    {{1,0}, {1,1,1,1}},
    {{0,1}, {1,1,1,1}},
    {{1,1}, {0,0,0,0}},
    
};
const Vertex txPos[] = {
    {{0,0}, {0,0,0,0}},
    {{1,0}, {0,0,0,0}},
    {{0,1}, {0,0,0,0}},
    {{1,1}, {0,0,0,0}},
    
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

GLuint texID;

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
    glBlendFunc(GL_ONE, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_BLEND);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    glEnableClientState(GL_VERTEX_ARRAY);
    
//    CLTexture *texture = FileManager::loadTexture("Sprite");
    
    GLuint imgW = 10;
    GLuint imgH = 10;
    
    GLubyte* imgData = (GLubyte *) calloc(imgW * imgH * 4, sizeof(GLubyte));
    
    for (int i = 0; i < imgW * imgH * 4; i+=4) {
        imgData[i] = 0x00;
        imgData[i+1] = 0x70;
        imgData[i+2] = 0xff;
        imgData[i+3] = 0xff;
    }
    
    CLTexture *texture = new CLTexture();
    texture->width = imgW;
    texture->height = imgH;
    texture->data = imgData;
    
    m_texture = this->loadTexture(texture);
}

GLuint GLRenderer10::loadTexture(CLTexture* texture)
{
    GLuint tID;
    
    glGenTextures(1, &tID);
    glBindTexture(GL_TEXTURE_2D, tID);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, texture->width, texture->height, 0, GL_RGBA, GL_UNSIGNED_BYTE, texture->data);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    return tID;
}

void GLRenderer10::render()
{
//    glBindTexture(GL_TEXTURE_2D, m_texture);
    
    glClearColor(10, 0.5f, 0.5f, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glBindTexture(GL_TEXTURE_2D, m_texture);
    
    glVertexPointer(2, GL_FLOAT, sizeof(Vertex), &shape[0].Position[0]);
    glTexCoordPointer(2, GL_FLOAT, sizeof(Vertex), &txPos[0].Position[0]);

    GLsizei vCount = sizeof(shape) / sizeof(Vertex);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, vCount);

}

void GLRenderer10::update(float dt)
{
    Log(LOG_INFO, "GLRenderer", generateCString("Update with dt: %d", dt));
    
    glMatrixMode(GL_MODELVIEW);
    glRotatef(500*dt, 0, 0, 1);
}


