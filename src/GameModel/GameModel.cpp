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
    m_player = new Player();
    m_chainsaw = 0;
    
}
GameModel::~GameModel()
{
    
}

void GameModel::update(float dt)
{
    if (m_chainsaw != 0){
        if (m_chainsaw->targetReached()){
            m_chainsaw->setTarget(m_player->getPosition());
        }
        m_chainsaw->update(dt);
    }
    m_physicsManager->update(dt);
    m_player->update();
//    m_gameMap->update();
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
    b2Vec2 target = b2Vec2(x,y);
    m_chainsaw = new Chainsaw(b2Vec2(0.3, 0.3 ), m_player->getPosition(), target, false, true, PB_PLATFORM_1);
    Log(LOG_INFO, "GameModel", generateCString("Player threw his chainsaw at: %i,%i", x, y));
}