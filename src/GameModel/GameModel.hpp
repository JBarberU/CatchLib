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
#include "Map/GameMap.hpp"
#include "Entities/Chainsaw.hpp"
#include "../EventHandling/IEventListener.hpp"

class GameModel : public IEventListener{
private:
	GameMap* m_gameMap;
    PhysicsManager* m_physicsManager;
    Player* m_player;
    Chainsaw* m_chainsaw;
    
public:
	~GameModel();
	GameModel();
    
    void update(float dt);
    
    Vector2d* getCenterPoint();
    
    void playerJump();
    void playerThrowAt(int x, int y);
    
    void onEvent (EEvent event, void* source);
};
