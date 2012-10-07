//
//  File:	ActorsLoader.cpp
//  Author: John Barbero Unenge 
//	Date:  	10/5/12.
//
//  Copyright (c) 2012 John Barbero Unenge. All rights reserved.
//
//	All code is my own except where credited to others.
//


#include "ActorsLoader.hpp"
#include "../Helper/Logger.hpp"

const Actor* MAIN_CHARACTER;

void ActorsLoader::init(int textureID)
{
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
    
    Animation* a = new Animation(arr, s1, 150, true);
    Animation** aArr = new Animation*[1];
    aArr[0] = a;
    AnimationArray* aAnimArr = new AnimationArray(aArr, 1);
    
    MAIN_CHARACTER = new Actor(aAnimArr, a);
}

Actor* ActorsLoader::newMainCharacterActor()
{
    if (MAIN_CHARACTER == 0) {
        Log(LOG_ERROR, "ActorsLoader", "MAIN_CHARACTER is null, probably because init was never called.");
        return 0;
    }
    
    return new Actor(*MAIN_CHARACTER);
}