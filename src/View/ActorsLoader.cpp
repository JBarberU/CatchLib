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

const Actor* MAIN_CHARACTER;
const Actor* PLATFORM_1;

void ActorsLoader::init(int textureID)
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
    
    // Platform
    Sprite* s10 = new Sprite(16.0/128.0           ,16.0/128.0          , 2.0/128.0  , 2.0/128.0 , textureID);
    
    Sprite** sp1 = new Sprite*[1];
    sp1[0] = s10;
  
    
    SpriteArray* arr1 = new SpriteArray(sp1, 1);
    
    Animation* a1 = new Animation(arr1, s10, 300, true);
    Animation** aArr1 = new Animation*[1];
    aArr1[0] = a1;
    AnimationArray* aAnimArr1 = new AnimationArray(aArr1, 1);
    
    PLATFORM_1 = new Actor(aAnimArr1, a1);
    
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