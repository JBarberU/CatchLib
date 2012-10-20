
//
//  GameModel.hpp
//  CatchLib
//
//  Created by Jesper Persson on 9/29/12.
//  Copyright (c) 2012 Jesper Persson. All rights reserved.
//
//
//
//
//#include "Map/GameMap.hpp"
#include "Physics/PhysicsManager.hpp"
#include "Entities/Player.hpp"
#include "Map/GameMap.hpp"

class GameModel {
private:
	GameMap* m_gameMap;
    PhysicsManager* m_physicsManager;
    Player* m_player;
    
public:
	~GameModel();
	GameModel();
    
    void update(float dt);
    
    void playerJump();
    void playerThrowAt(int x, int y);
};
