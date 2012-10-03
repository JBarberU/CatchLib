//
//  GameController.cpp
//  CatchiOS
//
//  Created by John Barbero Unenge on 9/24/12.
//  Copyright (c) 2012 John Barbero Unenge. All rights reserved.
//

#include "GameController.hpp"
<<<<<<< HEAD:src/Controller/GameController.cpp
#include "../Helper/Logger.hpp"
#include "../Helper/InputManager.hpp"
=======
#include "Logger.hpp"
#include "InputManager.hpp"
>>>>>>> No longer testing EventBus via the GameController:src/GameController.cpp


GameController::GameController(int width, int height, const char* resourcesPath)
{
    Log(LOG_INFO, "GameController", generateCString("GameCon: %ix%i anPB: %s", width, height, resourcesPath));
    
    InputManager::getSharedManager()->addInputListener(this);
    
    m_fileManager = new FileManager(resourcesPath);
    m_renderer = CreateRendererWithOpenGL10();
    m_renderer->init(width, height);
}
GameController::~GameController()
{
    Log(LOG_INFO, "GameController", "Destroyed GameController");
}

void GameController::update(float dt)
{
    m_renderer->update(dt);
    m_renderer->render();
}

void GameController::didRecieveInputEvent(InputType type, int locX, int locY)
{
	Log(LOG_EVENT, "GameController",  "DidRecieveInputEvent");
    m_fileManager->loadTextureFromFile("color");
}
