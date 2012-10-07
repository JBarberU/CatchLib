//
//  FileManager.hpp
//  CatchLib
//
//  Created by John Barbero Unenge on 9/17/12.
//  Copyright (c) 2012 John Barbero Unenge. All rights reserved.
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

class GLRenderer10 : public IRenderer{
public:
	GLRenderer10();
	~GLRenderer10();

	void init(int width, int height, CLTexture* texture);
	void render();
    void update(float dt);
    void onRotate(DeviceOrientation orientation);
    
    void addActor(Actor* actor);
    void removeActor(Actor* actor);

private:
    GLuint m_framebuffer;
    GLuint m_texture;
    GLuint m_renderbuffer;
    
    ActorArray* m_actors;
    
    GLfloat m_currentAngle;
    GLfloat m_desiredAngle;
    
    float m_deviceWidth;
    float m_deviceHeight;
    
    GLuint loadTexture(CLTexture *texture);
};