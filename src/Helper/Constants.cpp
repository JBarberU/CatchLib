//
//  File:	Constants.cpp
//  Author: John Barbero Unenge 
//	Date:  	10/20/12.
//
//  Copyright (c) 2012 John Barbero Unenge. All rights reserved.
//
//	All code is my own except where credited to others.
//
//	License: The following code is licensed under the Catch22-License
//


#include "Constants.hpp"

double Constants::gameWidth;
double Constants::gameHeight;

void Constants::init(double screenWidth, double screenHeight)
{
    gameWidth = 18;
    gameHeight = (screenWidth / screenHeight) * gameWidth;
}

double Constants::getGameWidth()
{
    return gameWidth;
}
double Constants::getGameHeight()
{
    return gameHeight;
}
