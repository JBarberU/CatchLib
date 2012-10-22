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
#include "Physics/PBody.hpp"

GameModel::GameModel()
{
    m_physicsManager = new PhysicsManager();
	m_gameMap = new GameMap();
    
    m_player = new Player();
}
GameModel::~GameModel()
{
    
}

void GameModel::update(float dt)
{
    m_physicsManager->update(dt);
    m_player->update();
    m_gameMap->update(m_player->getPosition().x);
}
Vector2d* GameModel::getCenterPoint()
{
    return new Vector2d(m_player->getPosition().x, m_player->getPosition().y);
}

void GameModel::playerJump()
{
    m_player->jump();
}
void GameModel::playerThrowAt(int x, int y)
{
    Log(LOG_INFO, "GameModel", generateCString("Player threw his chainsaw at: %i,%i", x, y));
}
