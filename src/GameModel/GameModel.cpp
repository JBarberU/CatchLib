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
        m_chainsaw->update(dt);
        if (m_chainsaw->targetReached()){
            //m_chainsaw->setTarget(m_player->getPosition());
            m_chainsaw = 0;
        }
    }
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
    if (m_chainsaw == 0){
                        
        b2Vec2 spawn = b2Vec2(m_player->getPosition().x, m_player->getPosition().y);
    
        m_chainsaw = new Chainsaw(b2Vec2(1.0, 1.0 ),spawn , b2Vec2(x,y), false, true, PB_PLAYER);
    }
}

void GameModel::onEvent(EEvent event, void* source)
{
    if (event == COLLIDED_WITH_PLAYER && ((PBody *)source)->getTag() == PB_CHAINSAW){
        delete m_chainsaw;
        m_chainsaw = 0;
    }
}
void GameModel::onEvent(EEvent event, void* source)
{
	if(event == COLLIDED_WITH_PLAYER && ((PBody *)source)->getTag() == PB_CHAINSAW){
		delete m_chainsaw;
	}
}
