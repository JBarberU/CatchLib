//
//  File:   GLRenderer10.cpp
//  Class:  GLRenderer10
//  Author: John Barbero Unenge
//          All code is my own except where credited to others.
//
//  Copyright (c) 2012. All Rights Reserved.
//
//  Date:   17/9/12
//
//	License: The following code is licensed under the Catch22-License
//
#include "../Helper/Logger.hpp"
#include "GLRenderer10.hpp"
#include "Vertex.hpp"
#include "../Helper/FileManager.hpp"
#include "ActorsLoader.hpp"
#include "../EventHandling/EventBus.hpp"

#include "../Helper/Constants.hpp"
#include "../Helper/CoordinatesManager.hpp"

const GLfloat ANGLE_LEFT = -90;
const GLfloat ANGLE_RIGHT = 90;

IRenderer* CreateRendererWithOpenGL10()
{
    return new GLRenderer10();
}

GLRenderer10::GLRenderer10() : m_cameraPos(0.f, 0.f)
{

    Log(LOG_INFO, "GLRenderer10", "Constructed a GLRenderer!");
    
//    OpenGL ES 1.0 implementation in Android doesn't support creating
//    your own framebuffer and renderbuffer so we have to do this only
//    when compiling for iOS.
#ifdef __APPLE__
    Log(LOG_INFO, "GLRenderer10", "Additional iOS setup!");
    glGenRenderbuffersOES(1, &m_renderbuffer);
    glBindRenderbufferOES(GL_RENDERBUFFER_OES, m_renderbuffer);
    
    // Create the framebuffer object and attach the color buffer.
    glGenFramebuffersOES(1, &m_framebuffer);
    glBindFramebufferOES(GL_FRAMEBUFFER_OES, m_framebuffer);
#endif
    EventBus::getSharedInstance()->addEventListener(this);
}
GLRenderer10::~GLRenderer10()
{
	Log(LOG_INFO, "GLRenderer10", "Destroyed a GLRenderer10!");
}

void GLRenderer10::init(int width, int height, CLTexture* texture)
{
    
#ifdef __APPLE__
    glFramebufferRenderbufferOES(GL_FRAMEBUFFER_OES, GL_COLOR_ATTACHMENT0_OES, GL_RENDERBUFFER_OES, m_renderbuffer);
#endif
     
    glViewport(0, 0, width, height);
    
    // Initialize the projection matrix.
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrthof(0, Constants::getGameHeight(), m_cameraPos.m_x - Constants::getGameWidth() / 2, Constants::getGameWidth() / 2, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    
    glBlendFunc(GL_ONE, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_BLEND);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    glEnableClientState(GL_VERTEX_ARRAY);
    
    m_desiredAngle = ANGLE_LEFT;
    m_currentAngle = m_desiredAngle;
    m_deviceWidth = width;
    m_deviceHeight = height;
     
    ActorsLoader::init(m_texture);
    
    m_background = new Sprite(0.f, 1.f/2.f, 1.f, 1.f/2.f, m_texture, false);
    m_screenVertecies = new Vertex[4]{
        Vertex(Constants::getGameHeight()   , Constants::getGameWidth()),
        Vertex(Constants::getGameHeight()   , -Constants::getGameWidth()),
        Vertex(0  , -Constants::getGameWidth()),
        Vertex(0  , Constants::getGameWidth()),
    };
    
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
    
    delete texture;
    
    return tID;
}
void GLRenderer10::DrawBackground()
{
    glPushMatrix();
    glLoadIdentity();
    glVertexPointer(2, GL_FLOAT, sizeof(Vertex), &m_screenVertecies[0].Position[0]);
    glTexCoordPointer(2, GL_FLOAT, sizeof(Vertex), &m_background->getTextureVertexData()[0].Position[0]);
    
    glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
    glPopMatrix();
}
void GLRenderer10::render()
{    
    glClearColor(10, 0.5f, 0.5f, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    
    this->DrawBackground();
    
    glPushMatrix();
    glLoadIdentity();
    if (m_desiredAngle == 90)
        glTranslatef(Constants::getGameHeight(), 0, 0);
    else
        glTranslatef(0, Constants::getGameWidth(), 0);
    glRotatef(m_currentAngle, 0, 0, 1);
    
    Vector2d camera;
    CoordinatesManager::getSharedInstance()->getWorldCoordinates(Vector2d(0.f, 0.f), camera);
    
    glTranslatef(-(camera.m_x - Constants::getGameWidth() / 2), 0.f, 0.f);
    
    glBindTexture(GL_TEXTURE_2D, m_texture);
    
    for (auto it = m_actors.begin(); it != m_actors.end(); it++) {
        const Vertex* vertexData = (*it).getVertexData();
        glVertexPointer(2, GL_FLOAT, sizeof(Vertex), &vertexData[0].Position[0]);
        const Vertex* textureData = (*it).getTextureVertexData();
        glTexCoordPointer(2, GL_FLOAT, sizeof(Vertex), &textureData[0].Position[0]);
        
        glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
        delete [] vertexData;
    
    }
    glPopMatrix();
}

void GLRenderer10::update(float dt)
{
    if (m_currentAngle != m_desiredAngle) {
        // If the desired angle is greater than the current angle, add 1, otherwise -1.
        m_currentAngle += m_desiredAngle > m_currentAngle ? 10 : -10;
    }
    
    for (auto it = m_actors.begin(); it != m_actors.end(); it++) {
        (*it).update(dt);
    }
}
void GLRenderer10::addActor(const Actor &actor)
{
    m_actors.push_back(actor);
}
void GLRenderer10::onRotate(DeviceOrientation orientation)
{
    switch (orientation) {
        case DeviceOrientationLandscapeLeft:
            m_desiredAngle = ANGLE_LEFT;
            break;
            
        case DeviceOrientationLandscapeRight:
            m_desiredAngle = ANGLE_RIGHT;
            break;
    }
    
}

// Not removing anything at this point!!
void GLRenderer10::removeActor(const Actor &actor)
{
    // m_actors
}
void GLRenderer10::centerCameraOn(Vector2d point)
{
    
    m_cameraPos = Vector2d(point);
    
}
void GLRenderer10::onEvent (EEvent event, void* source)
{
    if (event == PBODY_CREATED_ACTORS) {

        Actor* newActor;
        switch (((PBody *) source)->getTag()) {
            case PB_PLAYER:
                newActor = ActorsLoader::newMainCharacterActor();
                break;
            case PB_PLATFORM_1:
                newActor = ActorsLoader::newPlatformActor_1();
                break;
            case PB_PLATFORM_2:
                newActor = ActorsLoader::newPlatformActor_2();
                break;
            case PB_PLATFORM_3:
                newActor = ActorsLoader::newPlatformActor_3();
                break;
            case PB_CHAINSAW:
                newActor = ActorsLoader::newChainsawActor();
                break;
            case PB_OBSTACLE_BOX:
                newActor = ActorsLoader::newObstacleBoxActor();
                break;
            default:
                return;
        }
        
        newActor->setPBody((PBody *) source);
        this->addActor(*newActor);
    }
}
