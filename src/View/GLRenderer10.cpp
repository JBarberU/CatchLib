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
#include "ActorsLoader.hpp"

const Vertex shape[] = {
    Vertex(0,0),
    Vertex(1,0),
    Vertex(0,1),
    Vertex(1,1),
};
const Vertex txPos[] = {
    Vertex(0,0),
    Vertex(1,0),
    Vertex(0,1),
    Vertex(1,1),
    
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
#endif
}
GLRenderer10::~GLRenderer10()
{
	Log(LOG_INFO, "GLRenderer10", "Destroyed a GLRenderer10!");
}

GLuint texID;

void GLRenderer10::init(int width, int height, CLTexture* texture)
{
    
#ifdef __APPLE__
    glFramebufferRenderbufferOES(GL_FRAMEBUFFER_OES, GL_COLOR_ATTACHMENT0_OES, GL_RENDERBUFFER_OES, m_renderbuffer);
#endif
    
	Log(LOG_INFO, "GLRenderer10", generateCString("Init WH: %ix%i", width, height));
 
    glViewport(0, 0, width, height);
    
    glMatrixMode(GL_PROJECTION);
    
    // Initialize the projection matrix.
    const float maxX = 2;
    const float maxY = 3;
    glOrthof(-maxX, +maxX, -maxY, +maxY, -1, 1);
    
    glMatrixMode(GL_MODELVIEW);
    glBlendFunc(GL_ONE, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_BLEND);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    glEnableClientState(GL_VERTEX_ARRAY);
        
    m_actors = new ActorArray();
    
    ActorsLoader::init(m_texture);
    this->addActor(ActorsLoader::newMainCharacterActor());
    
    m_texture = this->loadTexture(texture);
}

GLuint GLRenderer10::loadTexture(CLTexture* texture)
{
    GLuint tID;
    
    glGenTextures(1, &tID);
    glBindTexture(GL_TEXTURE_2D, tID);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, texture->getWidth(), texture->getHeight(), 0, GL_RGBA, GL_UNSIGNED_BYTE, texture->getData());
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    
    return tID;
}

void GLRenderer10::render()
{    
    glClearColor(10, 0.5f, 0.5f, 1);
    glClear(GL_COLOR_BUFFER_BIT);

    glBindTexture(GL_TEXTURE_2D, m_texture);
    
    
    for (int i = 0; i < m_actors->m_index; i++) {
        glVertexPointer(2, GL_FLOAT, sizeof(Vertex), &m_actors->m_actors[i]->getVertexData()[0].Position[0]);
        glTexCoordPointer(2, GL_FLOAT, sizeof(Vertex), &m_actors->m_actors[i]->getTextureVertexData()[0].Position[0]);
        
        glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
    }
}

void GLRenderer10::update(float dt)
{    
//    glRotatef(200*dt, 0, 0, 1);
    
    for (int i = 0; i < m_actors->m_index; i++) {
        m_actors->m_actors[i]->update(dt);
    }
}
void GLRenderer10::addActor(Actor* actor)
{
    if (m_actors == 0)
        m_actors = new ActorArray();
    
    if (m_actors->m_index == m_actors->m_size) {
        Log(LOG_INFO, "GLRenderer10", "Needed to expand actor array");
        m_actors->m_size += 20;
        Actor** newActors = new Actor*[m_actors->m_size];
        
        for (int i = 0; i < m_actors->m_index; i++) {
            newActors[i] = m_actors->m_actors[i];
        }
        
        m_actors->m_actors = newActors;
    }
    
    Log(LOG_INFO, "GLRenderer10", "Added an actor");
    m_actors->m_actors[m_actors->m_index++] = actor;
}
void GLRenderer10::removeActor(Actor* actor)
{
    if (actor == 0)
        return;
    
    for (int i = 0; i < m_actors->m_index; i++) {
        if (m_actors->m_actors[i] == actor) {
            m_actors->m_actors[i] = m_actors->m_actors[--m_actors->m_index];
        }
    }
}
