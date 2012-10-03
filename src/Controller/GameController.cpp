//
//  GameController.cpp
//  CatchiOS
//
//  Created by John Barbero Unenge on 9/24/12.
//  Copyright (c) 2012 John Barbero Unenge. All rights reserved.
//

#include "GameController.hpp"
#include "../Helper/Logger.hpp"
#include "../Helper/InputManager.hpp"


GameController::GameController(int width, int height, const char* resourcesPath)
{
    Log(LOG_INFO, "GameController", generateCString("GameCon: %ix%i anPB: %s", width, height, resourcesPath));
    
    InputManager::getSharedManager()->addInputListener(this);
    
    m_fileManager = new FileManager(resourcesPath);
    m_renderer = CreateRendererWithOpenGL10();
    m_renderer->init(width, height);
    EventBus* bus =EventBus::getSharedInstance();
    bus->addEventListener(this);
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
	//Log(LOG_EVENT, "GameController",  "DidRecieveInputEvent");
   // m_fileManager->loadTextureFromFile("color");
    EventBus* bus =EventBus::getSharedInstance();
    Log(LOG_EVENT, "GameController", "Publishing event...");
    bus->publishEvent(GAME_STARTED, this);
    bus->removeEventListener(this);
    Log(LOG_EVENT, "GameController", "Publishing event...");
    bus->publishEvent(GAME_STARTED, this);
 


}

void GameController::onEvent(EEvent event, void* source)
{
	Log(LOG_EVENT, "GameController", "Event recieved!");
}
