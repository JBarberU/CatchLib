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


GameController::GameController(int width, int height, CLTexture* texture)
{
    Log(LOG_INFO, "GameController", generateCString("GameCon: %ix%i", width, height));
    
    InputManager::getSharedManager()->addInputListener(this);
    
    m_renderer = CreateRendererWithOpenGL10();
    m_renderer->init(width, height, texture);
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
}
