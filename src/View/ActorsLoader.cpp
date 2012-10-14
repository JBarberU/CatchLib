//
//  File:	ActorsLoader.cpp
//  Class:  ActorsLoader
//  Author: John Barbero Unenge
//          All code is my own except where credited to others.
//
//  Copyright (c) 2012 Catch22. All Rights Reserved.
//
//	Date:  	5/10/12.
//


#include "ActorsLoader.hpp"
#include "../Helper/Logger.hpp"

const Actor* MAIN_CHARACTER = 0;
const Actor* PLATFORM_1 = 0;
const Actor* OBSTACLE_BOX = 0;

void ActorsLoader::initMainCharacter(int textureID)
{
    // Player character
    Sprite* s0 = new Sprite(0           ,0          , 32.0/128  , 32.0/128 , textureID);
    Sprite* s1 = new Sprite(32.0/128.0  ,0          , 32.0/128  , 32.0/128 , textureID);
    Sprite* s2 = new Sprite(64.0/128.0  ,0          , 32.0/128  , 32.0/128, textureID);
    Sprite* s3 = new Sprite(32.0/128.0  ,0          , 32.0/128  , 32.0/128 , textureID);
    
    Sprite** sp = new Sprite*[4];
    sp[0] = s0;
    sp[1] = s1;
    sp[2] = s2;
    sp[3] = s3;
    
    SpriteArray* arr = new SpriteArray(sp, 4);
    
    Animation* a = new Animation(arr, s1, 300, true);
    Animation** aArr = new Animation*[1];
    aArr[0] = a;
    AnimationArray* aAnimArr = new AnimationArray(aArr, 1);
    
    MAIN_CHARACTER = new Actor(aAnimArr, a);
}
void ActorsLoader::initPlatform(int textureID)
{
    // Platform
    Sprite* s1 = new Sprite(16.0/128.0           ,16.0/128.0          , 2.0/128.0  , 2.0/128.0 , textureID);
    
    Sprite** sp = new Sprite*[1];
    sp[0] = s1;
    
    
    SpriteArray* arr1 = new SpriteArray(sp, 1);
    
    Animation* a = new Animation(arr1, s1, 300, true);
    Animation** aArr = new Animation*[1];
    aArr[0] = a;
    AnimationArray* aAnimArr = new AnimationArray(aArr, 1);
    
    PLATFORM_1 = new Actor(aAnimArr, a);
}
void ActorsLoader::initObstacle(int textureID)
{
    //  Obstacle Box
    Sprite* s1 = new Sprite(19.0/128.0           ,19.0/128.0          , 2.0/128.0  , 2.0/128.0 , textureID);
    
    Sprite** sp = new Sprite*[1];
    sp[0] = s1;
    
    
    SpriteArray* arr1 = new SpriteArray(sp, 1);
    
    Animation* a = new Animation(arr1, s1, 300, true);
    Animation** aArr = new Animation*[1];
    aArr[0] = a;
    AnimationArray* aAnimArr = new AnimationArray(aArr, 1);
    
    OBSTACLE_BOX = new Actor(aAnimArr, a);
}

void ActorsLoader::init(int textureID)
{
    ActorsLoader::initMainCharacter(textureID);
    ActorsLoader::initPlatform(textureID);
    ActorsLoader::initObstacle(textureID);    
}
Actor* ActorsLoader::newMainCharacterActor()
{
    if (MAIN_CHARACTER == 0) {
        Log(LOG_ERROR, "ActorsLoader", "MAIN_CHARACTER is null, probably because init was never called.");
        return 0;
    }
    
    return new Actor(*MAIN_CHARACTER);
}
Actor* ActorsLoader::newPlatformActor() {
    if (PLATFORM_1 == 0) {
        Log(LOG_ERROR, "ActorsLoader", "PLATFORM_1 is null, probably because init was never called.");
        return 0;
    }
    
    return new Actor(*PLATFORM_1);
}
Actor* ActorsLoader::newObstacleBoxActor()
{
    if (OBSTACLE_BOX == 0) {
        Log(LOG_ERROR, "ActorsLoader", "PLATFORM_1 is null, probably because init was never called.");
        return 0;
    }
    
    return new Actor(*OBSTACLE_BOX);
}