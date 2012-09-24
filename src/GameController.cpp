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

GameController::GameController(int width, int height)
{
    Log(LOG_INFO, "GameController", "Constructed GameController");
    
    InputManager::getSharedManager()->addInputListener(this);
    
    m_fileManager = new FileManager("CatchLib/src");
    m_renderer = new GLRenderer();
    m_renderer->init(width, height);
}
GameController::~GameController()
{
    Log(LOG_INFO, "GameController", "Destroyed GameController");
    m_renderer->~GLRenderer();
}

void IInputListener::didRecieveInputEvent(InputType type, float locX, float locY)
{
    Log(LOG_EVENT, "GameController", "DidRecieveInputEvent");
}