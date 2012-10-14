//
//  GameModel.cpp
//  CatchiOS
//
//  Created by John Barbero Unenge on 10/7/12.
//  Copyright (c) 2012 John Barbero Unenge. All rights reserved.
//

#include "GameModel.hpp"
#include "../EventHandling/EventBus.hpp"
#include "../Helper/Logger.hpp"

GameModel::GameModel()
{
    m_physicsManager = new PhysicsManager();
	m_gameMap = new GameMap();
    
    PBody* body = new PBody(new Vector2d(0, 0), new Vector2d(480, 50), false, true, false, PB_PLATFORM);
    PBody* body2 = new PBody(new Vector2d(240, 51), new Vector2d(20, 50), false, true, false, PB_PLATFORM);
    
    EventBus::getSharedInstance()->publishEvent(PBODY_CREATED, (PBody *)body);
    EventBus::getSharedInstance()->publishEvent(PBODY_CREATED, (PBody *)body2);
    
    m_player = new Player();
    Log(LOG_INFO, "GameModel", "GameModel has been constructed.");
}
GameModel::~GameModel()
{
    
}

void GameModel::update(float dt)
{
    m_physicsManager->update(dt);
    m_gameMap->update();
}

void GameModel::playerJump()
{
    m_player->jump();
}
void GameModel::playerThrowAt(int x, int y)
{
    Log(LOG_INFO, "GameModel", generateCString("Player threw his chainsaw at: %i,%i", x, y));
}
