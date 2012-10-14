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
    
    
    Vector2d** v2Arr = new Vector2d*[4];
    
    v2Arr[0] = new Vector2d(-20.0,-6.0);
    v2Arr[1] = new Vector2d(-20.0,-6.0);
    v2Arr[2] = new Vector2d(20,6.0);
    v2Arr[3] = new Vector2d(20,0.0);
    
    Vector2dArray* vArr = new Vector2dArray(v2Arr, 4);
    
    PBody* tri = new PBody(vArr, true, PB_PLATFORM);
    
    PBody* body2 = new PBody(new Vector2d(6.0, 2.0), new Vector2d(0.5, 1), false, true, false, PB_OBSTACLE_BOX);
    
    EventBus::getSharedInstance()->publishEvent(PBODY_CREATED, (PBody *)tri);
    EventBus::getSharedInstance()->publishEvent(PBODY_CREATED, (PBody *)body2);
    
    m_player = new Player();
    EventBus::getSharedInstance()->publishEvent(PBODY_CREATED, (PBody *)m_player);
    
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
void GameModel::playerThrowAt(int x, int y)
{
    Log(LOG_INFO, "GameModel", generateCString("Player threw his chainsaw at: %i,%i", x, y));
}