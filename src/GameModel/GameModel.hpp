//
//  File:       GameModel.hpp
//  Class:      GameModel
//  Author:     Jesper Persson
//              All code is my own except where credited to others.
//
//	Copyright (c) 2012 by Catch22. All Rights Reserved.
//  Date: 		29/09-2012
//
//	License: The following code is licensed under the Catch22-License
//
//
//#include "Map/GameMap.hpp"
#include "Physics/PhysicsManager.hpp"
#include "Entities/Player.hpp"

class GameModel {
private:
//    GameMap*    m_gameMap;
    PhysicsManager* m_physicsManager;
    Player* m_player;
    
public:
	~GameModel();
	GameModel();
    
    void update(float dt);
    
    void playerJump();
    void playerThrowAt(int x, int y);
};
