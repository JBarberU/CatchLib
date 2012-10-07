//
//  File:	ActorsLoader.hpp
//  Author: John Barbero Unenge 
//	Date:  	10/5/12.
//
//  Copyright (c) 2012 John Barbero Unenge. All rights reserved.
//
//	All code is my own except where credited to others.
//


#ifndef __CatchiOS__ActorsLoader__
#define __CatchiOS__ActorsLoader__

#include "Actor.hpp"

class ActorsLoader {
    
public:
    static void init(int textureID);
    static Actor* newMainCharacterActor();
};

#endif /* defined(__CatchiOS__ActorsLoader__) */
