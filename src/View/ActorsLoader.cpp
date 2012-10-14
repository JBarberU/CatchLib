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

const double IMAGE_WIDTH = 2048;
const double IMAGE_HEIGHT = 2048;

void ActorsLoader::initMainCharacter(int textureID)
{
    
    double sW = 172;
    double sH = 160;
    
    // Player character
    Sprite* s0 = new Sprite(0*sW/IMAGE_WIDTH    ,0*sH/IMAGE_HEIGHT
                            , sW/IMAGE_WIDTH  , sH/IMAGE_HEIGHT , textureID);
    
    Sprite* s1 = new Sprite(1*sW/IMAGE_WIDTH    ,0*sH/IMAGE_HEIGHT
                            , sW/IMAGE_WIDTH  , sH/IMAGE_HEIGHT , textureID);
    
    Sprite* s2 = new Sprite(2*sW/IMAGE_WIDTH    ,0*sH/IMAGE_HEIGHT
                            , sW/IMAGE_WIDTH  , sH/IMAGE_HEIGHT, textureID);
    
    Sprite* s3 = new Sprite(3*sW/IMAGE_WIDTH    ,0*sH/IMAGE_HEIGHT
                            , sW/IMAGE_WIDTH  , sH/IMAGE_HEIGHT , textureID);
    
    Sprite* s4 = new Sprite(4*sW/IMAGE_WIDTH    ,0*sH/IMAGE_HEIGHT
                            , sW/IMAGE_WIDTH  , sH/IMAGE_HEIGHT , textureID);
    
    Sprite* s5 = new Sprite(5*sW/IMAGE_WIDTH    ,0*sH/IMAGE_HEIGHT
                            , sW/IMAGE_WIDTH  , sH/IMAGE_HEIGHT , textureID);
    
    
    Sprite** sp = new Sprite*[6];
    sp[0] = s0;
    sp[1] = s1;
    sp[2] = s2;
    sp[3] = s3;
    sp[4] = s4;
    sp[5] = s5;
    
    SpriteArray* arr = new SpriteArray(sp, 6);
    
    Animation* a = new Animation(arr, s1, 150, true);
    Animation** aArr = new Animation*[1];
    aArr[0] = a;
    AnimationArray* aAnimArr = new AnimationArray(aArr, 1);
    
    MAIN_CHARACTER = new Actor(aAnimArr, a);
}
void ActorsLoader::initPlatform(int textureID)
{
    // Platform
    Sprite* s1 = new Sprite(19.0/128.0           ,19.0/128.0          , 2.0/128.0  , 2.0/128.0 , textureID);
    
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