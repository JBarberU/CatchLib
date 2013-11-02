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

Actor MAIN_CHARACTER;
Actor CHAINSAW;
Actor PLATFORM_1;
Actor PLATFORM_2;
Actor PLATFORM_3;
Actor OBSTACLE_BOX;

const double IMAGE_WIDTH = 2048;
const double IMAGE_HEIGHT = 2048;

void ActorsLoader::initMainCharacter(int textureID)
{
    
    double sW = 111; // Character sprite width in pixels
    double sH = 133; // Character sprite height in pixels
    
    // Player character
    Sprite* s0 = new Sprite(0*sW/IMAGE_WIDTH    ,2/IMAGE_HEIGHT
                            , sW/IMAGE_WIDTH  , sH/IMAGE_HEIGHT , textureID, false);
    
    Sprite* s1 = new Sprite(1*sW/IMAGE_WIDTH    ,2/IMAGE_HEIGHT
                            , sW/IMAGE_WIDTH  , sH/IMAGE_HEIGHT , textureID, false);
    
    Sprite* s2 = new Sprite(2*sW/IMAGE_WIDTH    ,2/IMAGE_HEIGHT
                            , sW/IMAGE_WIDTH  , sH/IMAGE_HEIGHT, textureID, false);
    
    Sprite* s3 = new Sprite(3*sW/IMAGE_WIDTH    ,2/IMAGE_HEIGHT
                            , sW/IMAGE_WIDTH  , sH/IMAGE_HEIGHT , textureID, false);
    
    Sprite* s4 = new Sprite(4*sW/IMAGE_WIDTH    ,2/IMAGE_HEIGHT
                            , sW/IMAGE_WIDTH  , sH/IMAGE_HEIGHT , textureID, false);
    
    Sprite* s5 = new Sprite(5*sW/IMAGE_WIDTH    ,2/IMAGE_HEIGHT
                            , sW/IMAGE_WIDTH  , sH/IMAGE_HEIGHT , textureID, false);
    
    Sprite** sp = new Sprite*[6];
    sp[0] = s0;
    sp[1] = s1;
    sp[2] = s2;
    sp[3] = s3;
    sp[4] = s4;
    sp[5] = s5;
    
    SpriteArray* arr = new SpriteArray(sp, 6);
    
    Animation a = new Animation(arr, s1, 100, true);
    int FIRST_ANIMATION = 0;
    std::vector<Animation> animations;
    animations.push_back(a);

    MAIN_CHARACTER = Actor(animations, FIRST_ANIMATION, Vector2d(1.f, 1.f),
                           OffsetMatrix(new Vector2d(0.f,0.f), new Vector2d(0.f,0.f), new Vector2d(0.f,0.f), new Vector2d(0.f,0.f)));
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
    
    Animation a1 = new Animation(arr1, s1, 300, true);
    int FIRST_ANIMATION1 = 0;
    std::vector<Animation> animations1;
    animations1.push_back(a1);

    PLATFORM_1 = Actor(animations1, FIRST_ANIMATION1, Vector2d(1.f, 3.5f),
                    OffsetMatrix(
						   new Vector2d(0.05f,0.f),
						   new Vector2d(-0.13f,0.f),
						   new Vector2d(0.05f,0.f),
						   new Vector2d(-0.13f,0.f)));
    
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
    int FIRST_ANIMATION3 = 0;
    std::vector<Animation> animations3;
    animations3.push_back(a3);
    
    PLATFORM_3 = Actor(animations3, FIRST_ANIMATION3, new Vector2d(1.f, 3.5f),
					new OffsetMatrix(
						   new Vector2d(0.05f,0.f),
						   new Vector2d(-0.13f,0.f),
						   new Vector2d(0.05f,0.f),
						   new Vector2d(-0.13f,0.f)));
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
    int FIRST_ANIMATION2 = 0;
    std::vector<Animation> animations2;
    animations2.push_back(a2);
    
    PLATFORM_2 = Actor(animations2, FIRST_ANIMATION2, new Vector2d(1.f, 3.5f),
                           new OffsetMatrix(
                        		   new Vector2d(0.16f,0.f),
                        		   new Vector2d(-0.15f,0.f),
                        		   new Vector2d(0.16f,0.f),
                        		   new Vector2d(-0.15f,0.f)));
    
//    Sprite* s3 = new Sprite();
    
    
}

void ActorsLoader::initChainsaw(int textureID)
{
	//  Chainsaw
	Sprite* s1 = new Sprite(  5/IMAGE_WIDTH,
							185/IMAGE_HEIGHT,
							 64/IMAGE_WIDTH,
							 27/IMAGE_HEIGHT,
							textureID, false);

	Sprite* s2 = new Sprite(  5/IMAGE_WIDTH,
							218/IMAGE_HEIGHT,
							 64/IMAGE_WIDTH,
							 27/IMAGE_HEIGHT,
							textureID, false);

	Sprite** sp = new Sprite*[2];
	sp[0] = s1;
	sp[1] = s2;

	SpriteArray* arr1 = new SpriteArray(sp, 2);

	Animation* a = new Animation(arr1, s1, 50, true);
    int FIRST_ANIMATION = 0;
    std::vector<Animation> animations;
    animations.push_back(a);

    CHAINSAW = Actor(animations, FIRST_ANIMATION, Vector2d(0.6f, 0.3f));
}

void ActorsLoader::initObstacle(int textureID)
{
    //  Obstacle Box
    Sprite* s1 = new Sprite(896/IMAGE_WIDTH,
							  2/IMAGE_HEIGHT,
							161/IMAGE_WIDTH,
							159/IMAGE_HEIGHT,
							textureID, true);
    
    Sprite** sp = new Sprite*[1];
    sp[0] = s1;
    
    
    SpriteArray* arr1 = new SpriteArray(sp, 1);
    
    Animation* a = new Animation(arr1, s1, 1, true);
    int FIRST_ANIMATION = 0;
    std::vector<Animation> animations;
    animations.push_back(a);
    
    OBSTACLE_BOX = Actor(animations, FIRST_ANIMATION, Vector2d(1.0f, 1.0f));
}

void ActorsLoader::init(int textureID)
{
    ActorsLoader::initMainCharacter(textureID);
    ActorsLoader::initPlatforms(textureID);
    ActorsLoader::initChainsaw(textureID);
    ActorsLoader::initObstacle(textureID);
}
Actor ActorsLoader::newMainCharacterActor()
{
    return MAIN_CHARACTER;
}

Actor ActorsLoader::newPlatformActor_1()
{
    return PLATFORM_1;
}
Actor ActorsLoader::newPlatformActor_2()
{
    return PLATFORM_2;
}


Actor ActorsLoader::newPlatformActor_3()
{
    return PLATFORM_3;
}

Actor ActorsLoader::newChainsawActor()
{
    return CHAINSAW;
}

Actor ActorsLoader::newObstacleBoxActor()
{
    return OBSTACLE_BOX;
}
