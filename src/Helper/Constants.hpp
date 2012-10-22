//
//  File:	Constants.hpp
//  Author: John Barbero Unenge 
//	Date:  	10/20/12.
//
//  Copyright (c) 2012 John Barbero Unenge. All rights reserved.
//
//	All code is my own except where credited to others.
//
//	License: The following code is licensed under the Catch22-License
//


#ifndef __CatchiOS__Constants__
#define __CatchiOS__Constants__

class Constants {
private:
    static double gameWidth;
    static double gameHeight;
    
public:
    //  Sets the game width and height from pixel sizes
    static void init(double screenWidth, double screenHeight);
    //  Get the game width in game coordinates
    static double getGameWidth();
    //  Get the game height in game coordinates
    static double getGameHeight();
};

#endif /* defined(__CatchiOS__Constants__) */
