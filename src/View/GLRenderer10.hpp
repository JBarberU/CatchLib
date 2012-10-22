//
//  File:   GLRenderer10.hpp
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
//  Description:
//  A class used for rendering with OpenGL ES 1.0. It implements
//  the functions in IRenderer.
//
#ifdef __IPHONE_NA
#include <OpenGLES/ES1/gl.h>
#include <OpenGLES/ES1/glext.h>
#else
#include <GLES/gl.h>
#include <GLES/glext.h>
#endif

#include "IRenderer.hpp"
#include "CLTexture.hpp"

#include "../EventHandling/IEventListener.hpp"

class GLRenderer10 : public IRenderer, public IEventListener{
public:
	GLRenderer10();
	~GLRenderer10();

    //  Inherited from IRenderer
	void init(int width, int height, CLTexture* texture);
	void render();
    void update(float dt);
    void onRotate(DeviceOrientation orientation);
    void addActor(Actor* actor);
    void removeActor(Actor* actor);
    void centerCameraOn(Vector2d point);
    
    //  Inherited from IEventListener
    void onEvent (EEvent event, void* source);

private:
    GLuint m_framebuffer;
    GLuint m_texture;
    GLuint m_renderbuffer;
    
    Sprite* m_background;
    const Vertex* m_screenVertecies;
    
    ActorArray* m_actors;
    
    GLfloat m_currentAngle;
    GLfloat m_desiredAngle;
    
    float m_deviceWidth;
    float m_deviceHeight;
    
    Vector2d m_cameraPos;
    
    GLuint loadTexture(CLTexture *texture);
    void DrawBackground();
};