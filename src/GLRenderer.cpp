//
//  FileManager.hpp
//  CatchLib
//
//  Created by John Barbero Unenge on 9/17/12.
//  Copyright (c) 2012 John Barbero Unenge. All rights reserved.
//

#include "Logger.hpp"
#include "GLRenderer.hpp"
#include "InputManager.hpp"

GLRenderer::GLRenderer()
{
	Log(LOG_INFO, "GLRenderer", "Constructed a GLRenderer!");
    
}
GLRenderer::~GLRenderer()
{
	Log(LOG_INFO, "GLRenderer", "Destroyed a GLRenderer!");
}


void GLRenderer::init(int width, int height)
{
	Log(LOG_INFO, "GLRenderer", "Initialized GLRenderer");
    InputManager::getSharedManager()->passInputEvent(TOUCH, 1, 3);
}

void GLRenderer::render()
{
	Log(LOG_INFO, "GLRenderer", "Rendering!");
}
