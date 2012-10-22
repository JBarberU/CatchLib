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
//	License: The following code is licensed under the Catch22-License
//
//  Description:
//  This class is used to hold Actor data. This is used since
//  data loading in Android is quite tedious.
//


#ifndef __ActorsLoader__
#define __ActorsLoader__

#include "Actor.hpp"

class ActorsLoader {
private:
    static void initMainCharacter(int textureID);
    static void initPlatforms(int textureID);
    static void initObstacle(int textureID);
    
public:
    //  Initialise the ActorLoader
    static void init(int textureID);
    
    /**
     * Creates a MainCharacter Actor.
     */
    static Actor* newMainCharacterActor();

    /**
     * Creates a Platform Actor of type 1.
     * This is a INCLINE platform.
     */
    static Actor* newPlatformActor_1();

    /**
     * Creates a Platform Actor of type 2.
     * This is a HORIZONTAL platform.
     */
    static Actor* newPlatformActor_2();

    /**
     * Creates a Platform Actor of type 3.
     * This is a DECLINE platform.
     */
    static Actor* newPlatformActor_3();

    /**
     * Creates an Obstacle Actor.
     */
    static Actor* newObstacleBoxActor();
};

#endif /* defined(__ActorsLoader__) */
