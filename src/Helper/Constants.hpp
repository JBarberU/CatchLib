//
//  File:	Constants.hpp
//  Author: John Barbero Unenge 
//	Date:  	10/20/12.
//
//  Copyright (c) 2012 John Barbero Unenge. All rights reserved.
//
//	All code is my own except where credited to others.
//


#ifndef __CatchiOS__Constants__
#define __CatchiOS__Constants__

class Constants {
private:
    static double gameWidth;
    static double gameHeight;
    
public:
    static void init(double screenWidth, double screenHeight);
    static double getGameWidth();
    static double getGameHeight();
};

#endif /* defined(__CatchiOS__Constants__) */
