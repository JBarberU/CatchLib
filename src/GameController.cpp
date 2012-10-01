//
//  GameController.cpp
//  CatchiOS
//
//  Created by John Barbero Unenge on 9/24/12.
//  Copyright (c) 2012 John Barbero Unenge. All rights reserved.
//

#include "GameController.hpp"
#include "Logger.hpp"
#include "InputManager.hpp"


GameController::GameController(int width, int height, const char* resourcesPath)
{
    Log(LOG_INFO, "GameController", generateCString("GameCon: %ix%i anPB: %s", width, height, resourcesPath));
    
    InputManager::getSharedManager()->addInputListener(this);
    
    m_fileManager = new FileManager(resourcesPath);
    m_renderer = new GLRenderer();
    m_renderer->init(width, height);
}
GameController::~GameController()
{
    Log(LOG_INFO, "GameController", "Destroyed GameController");
    m_renderer->~GLRenderer();
}

void GameController::setRenderer(GLRenderer* r)
{
	this->m_renderer = r;
}
GLRenderer* GameController::getRenderer()
{
	return m_renderer;
}

void GameController::didRecieveInputEvent(InputType type, int locX, int locY)
{
	Log(LOG_EVENT, "GameController",  "DidRecieveInputEvent");
    m_fileManager->loadTextureFromFile("color");
}
