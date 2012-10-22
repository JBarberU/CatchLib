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
#include "../Helper/Constants.hpp"

GameModel::GameModel()
{
    m_physicsManager = new PhysicsManager();
	m_gameMap = new GameMap();
    
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
            Log(LOG_INFO, "Chainsaw", "The Chainsaw has reached its target!!  ****");
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
    double convertedX = x * Constants::getGameWidth();
    double convertedY = y * Constants::getGameHeight();
                        
    b2Vec2 target = b2Vec2( convertedX + m_player->getPosition().x, convertedY + m_player->getPosition().y);
    b2Vec2 spawn = b2Vec2(m_player->getPosition().x + 3, m_player->getPosition().y + 3);
    m_chainsaw = new Chainsaw(b2Vec2(1.0, 1.0 ),spawn , target, false, true, PB_PLAYER);
    Log(LOG_INFO, "GameModel", generateCString("Player threw his chainsaw at: %i,%i", x, y));
}

void GameModel::onEvent(EEvent event, void* source)
{
    if(event == COLLIDED_WITH_PLAYER && ((PBody *)source)->getTag() == PB_CHAINSAW){
        delete m_chainsaw;  
    }
}
