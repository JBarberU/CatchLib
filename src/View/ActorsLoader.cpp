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
//	License: The following code is licensed under the Catch22-License
//


#include "ActorsLoader.hpp"
#include "../Helper/Logger.hpp"

Actor* MAIN_CHARACTER = 0;
Actor* PLATFORM_1 = 0;
Actor* PLATFORM_2 = 0;
Actor* PLATFORM_3 = 0;
Actor* OBSTACLE_BOX = 0;

const double IMAGE_WIDTH = 2048;
const double IMAGE_HEIGHT = 2048;

void ActorsLoader::initMainCharacter(int textureID)
{
    
    double sW = 111;
    double sH = 133;
    
    // Player character
    Sprite* s0 = new Sprite(0*sW/IMAGE_WIDTH    ,0*sH/IMAGE_HEIGHT
                            , sW/IMAGE_WIDTH  , sH/IMAGE_HEIGHT , textureID, false);
    
    Sprite* s1 = new Sprite(1*sW/IMAGE_WIDTH    ,0*sH/IMAGE_HEIGHT
                            , sW/IMAGE_WIDTH  , sH/IMAGE_HEIGHT , textureID, false);
    
    Sprite* s2 = new Sprite(2*sW/IMAGE_WIDTH    ,0*sH/IMAGE_HEIGHT
                            , sW/IMAGE_WIDTH  , sH/IMAGE_HEIGHT, textureID, false);
    
    Sprite* s3 = new Sprite(3*sW/IMAGE_WIDTH    ,0*sH/IMAGE_HEIGHT
                            , sW/IMAGE_WIDTH  , sH/IMAGE_HEIGHT , textureID, false);
    
    Sprite* s4 = new Sprite(4*sW/IMAGE_WIDTH    ,0*sH/IMAGE_HEIGHT
                            , sW/IMAGE_WIDTH  , sH/IMAGE_HEIGHT , textureID, false);
    
    Sprite* s5 = new Sprite(5*sW/IMAGE_WIDTH    ,0*sH/IMAGE_HEIGHT
                            , sW/IMAGE_WIDTH  , sH/IMAGE_HEIGHT , textureID, false);
    
    Sprite** sp = new Sprite*[6];
    sp[0] = s0;
    sp[1] = s1;
    sp[2] = s2;
    sp[3] = s3;
    sp[4] = s4;
    sp[5] = s5;
    
    SpriteArray* arr = new SpriteArray(sp, 6);
    
    Animation* a = new Animation(arr, s1, 100, true);
    Animation** aArr = new Animation*[1];
    aArr[0] = a;
    AnimationArray* aAnimArr = new AnimationArray(aArr, 1);
    
    MAIN_CHARACTER = new Actor(aAnimArr, a, new Vector2d(1.f, 1.f),
                           new OffsetMatrix(new Vector2d(0.f,0.f), new Vector2d(0.f,0.f), new Vector2d(0.f,0.f), new Vector2d(0.f,0.f)));
//                                                new Vector2d(.75f, 0.2f),
//                                                new Vector2d(.75f, 0.2f),
//                                                new Vector2d(.75f, .4f),
//                                                new Vector2d(.75f, .4f)));
}
void ActorsLoader::initPlatforms(int textureID)
{
    // Platform 1
    Sprite* s1 = new Sprite(26/IMAGE_WIDTH,
    						266/IMAGE_HEIGHT,
    						203/IMAGE_WIDTH,
    						696/IMAGE_HEIGHT,
    						textureID, false);
    
    Sprite** sp1 = new Sprite*[1];
    sp1[0] = s1;
    
    
    SpriteArray* arr1 = new SpriteArray(sp1, 1);
    
    Animation* a1 = new Animation(arr1, s1, 300, true);
    Animation** aArr1 = new Animation*[1];
    aArr1[0] = a1;
    AnimationArray* aAnimArr1 = new AnimationArray(aArr1, 1);
    
    PLATFORM_1 = new Actor(aAnimArr1, a1, new Vector2d(1.f, 3.5f),
                           new OffsetMatrix(new Vector2d(0.f,0.f), new Vector2d(0.f,0.f), new Vector2d(0.f,0.f), new Vector2d(0.f,0.f)));
//                                            new Vector2d(0.f,6.f), new Vector2d(0.f,6.f),
//                                            new Vector2d(0.f, -8.f), new Vector2d(0.f,-8.f)));
    
    // Platform 3
    Sprite* s3 = new Sprite(26/IMAGE_WIDTH,
    						266/IMAGE_HEIGHT,
    						203/IMAGE_WIDTH,
    						696/IMAGE_HEIGHT,
    						textureID, true);
    
    Sprite** sp3 = new Sprite*[1];
    sp3[0] = s3;
    
    
    SpriteArray* arr3 = new SpriteArray(sp3, 1);
    
    Animation* a3 = new Animation(arr3, s3, 300, true);
    Animation** aArr3 = new Animation*[1];
    aArr3[0] = a3;
    AnimationArray* aAnimArr3 = new AnimationArray(aArr3, 1);
    
    PLATFORM_3 = new Actor(aAnimArr3, a3, new Vector2d(1.f, 3.5f),
                           new OffsetMatrix(new Vector2d(0.f,0.f), new Vector2d(0.f,0.f), new Vector2d(0.f,0.f), new Vector2d(0.f,0.f)));
//                                            new Vector2d(0.f,6.f), new Vector2d(0.f,6.f),
//                                            new Vector2d(0.f, -8.f), new Vector2d(0.f,-8.f)));
    
    // Platform 2
    Sprite* s2 = new Sprite(281/IMAGE_WIDTH,
    						266/IMAGE_HEIGHT,
    						221/IMAGE_WIDTH,
    						696/IMAGE_HEIGHT,
    						textureID, false);
    
    Sprite** sp2 = new Sprite*[1];
    sp2[0] = s2;
    
    
    SpriteArray* arr2 = new SpriteArray(sp2, 1);
    
    Animation* a2 = new Animation(arr2, s2, 300, true);
    Animation** aArr2 = new Animation*[1];
    aArr2[0] = a2;
    AnimationArray* aAnimArr2 = new AnimationArray(aArr2, 1);
    
    PLATFORM_2 = new Actor(aAnimArr2, a2, new Vector2d(1.f, 3.5f),
                           new OffsetMatrix(new Vector2d(0.f,0.f), new Vector2d(0.f,0.f), new Vector2d(0.f,0.f), new Vector2d(0.f,0.f)));
//                                            new Vector2d(0.f,6.f), new Vector2d(0.f,6.f),
//                                            new Vector2d(0.f, -8.f), new Vector2d(0.f,-8.f)));
    
//    Sprite* s3 = new Sprite();
    
    
}
void ActorsLoader::initObstacle(int textureID)
{
    //  Obstacle Box
    Sprite* s1 = new Sprite(19.0/128.0           ,19.0/128.0          , 2.0/128.0  , 2.0/128.0 , textureID, true);
    
    Sprite** sp = new Sprite*[1];
    sp[0] = s1;
    
    
    SpriteArray* arr1 = new SpriteArray(sp, 1);
    
    Animation* a = new Animation(arr1, s1, 1, true);
    Animation** aArr = new Animation*[1];
    aArr[0] = a;
    AnimationArray* aAnimArr = new AnimationArray(aArr, 1);
    
    OBSTACLE_BOX = new Actor(aAnimArr, a, new Vector2d(1.2, 1.2));
}

void ActorsLoader::init(int textureID)
{
    ActorsLoader::initMainCharacter(textureID);
    ActorsLoader::initPlatforms(textureID);
    ActorsLoader::initObstacle(textureID);
}
Actor* ActorsLoader::newMainCharacterActor()
{
    if (MAIN_CHARACTER == 0) {
        Log(LOG_ERROR, "ActorsLoader", "MAIN_CHARACTER is null, probably because init was never called.");
        return 0;
    }
    
    return new Actor(MAIN_CHARACTER);
}
Actor* ActorsLoader::newPlatformActor_1()
{
    if (PLATFORM_1 == 0) {
        Log(LOG_ERROR, "ActorsLoader", "PLATFORM_1 is null, probably because init was never called.");
        return 0;
    }
    
    return new Actor(PLATFORM_1);
}
Actor* ActorsLoader::newPlatformActor_2()
{
    if (PLATFORM_2 == 0) {
        Log(LOG_ERROR, "ActorsLoader", "PLATFORM_1 is null, probably because init was never called.");
        return 0;
    }
    
    return new Actor(PLATFORM_2);
}


Actor* ActorsLoader::newPlatformActor_3()
{
    if (PLATFORM_3 == 0) {
        Log(LOG_ERROR, "ActorsLoader", "PLATFORM_1 is null, probably because init was never called.");
        return 0;
    }
    
    return new Actor(PLATFORM_3);
}

Actor* ActorsLoader::newObstacleBoxActor()
{
    if (OBSTACLE_BOX == 0) {
        Log(LOG_ERROR, "ActorsLoader", "PLATFORM_1 is null, probably because init was never called.");
        return 0;
    }
    
    return new Actor(OBSTACLE_BOX);
}
