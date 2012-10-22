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
    
    //  Updates the game model
    void update(float dt);
    
    //  Gets which point to center the game on
    Vector2d* getCenterPoint();
    
    //  Causes the player to jump
    void playerJump();
    //  Makes the player thow his chainsaw
    void playerThrowAt(int x, int y);
    
    //  Inherited from IEventListener
    void onEvent (EEvent event, void* source);
};
