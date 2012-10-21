//
//  File:	ActorsLoader.hpp
//  Class:  ActorsLoader
//  Author: John Barbero Unenge
//          All code is my own except where credited to others.
//
//  Copyright (c) 2012 Catch22. All Rights Reserved.
//
//	Date:  	5/10/12.
//
//  Description:
//  This class is used to hold Actor data. This is used since
//  data loading in Android is quite tedious.
//


#ifndef __CatchiOS__ActorsLoader__
#define __CatchiOS__ActorsLoader__

#include "Actor.hpp"

class ActorsLoader {
private:
    static void initMainCharacter(int textureID);
    static void initPlatforms(int textureID);
    static void initObstacle(int textureID);
    
public:
    //  Initialise the ActorLoader
    static void init(int textureID);
    
    //  Create a new MainCharacter Actor
    static Actor* newMainCharacterActor();
    static Actor* newPlatformActor_1();
    static Actor* newPlatformActor_2();
    static Actor* newPlatformActor_3();
    static Actor* newObstacleBoxActor();
};

#endif /* defined(__CatchiOS__ActorsLoader__) */