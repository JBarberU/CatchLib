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
//    m_gameMap = new GameMap();
    
    PBody* body = new PBody(false, true, new Vector2d(0, 0), new Vector2d(320, 5), new Vector2d(0,0));
    EventBus::getSharedInstance()->publishEvent(PBODY_CREATED, (PBody *)body);
    
    m_player = new Player();
    Log(LOG_INFO, "GameModel", "GameModel has been constructed.");
}
GameModel::~GameModel()
{
    
}

void GameModel::update(float dt)
{
    m_physicsManager->update(dt);
}

void GameModel::playerJump()
{
    m_player->jump();
}