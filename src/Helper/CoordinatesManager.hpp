//
//  File:	CoordinatesManager.hpp
//  Author: John Barbero Unenge 
//	Date:  	10/22/12.
//
//  Copyright (c) 2012 John Barbero Unenge. All rights reserved.
//
//	All code is my own except where credited to others.
//


#ifndef __CatchiOS__CoordinatesManager__
#define __CatchiOS__CoordinatesManager__

#include "../Math/Vector2d.hpp"

class CoordinatesManager {
private:
    static CoordinatesManager* s_CoordinatesManager;
    CoordinatesManager();

    Vector2d* m_worldCoordinate;
    
public:
    static CoordinatesManager* getSharedInstance();
    
    void updateWorldCoordinate(Vector2d worldCoordinate);
    Vector2d* getScreenCoordinates(Vector2d worldCoordinates);
    Vector2d* getWorldCoordinates(Vector2d screenCoordinates);
    
    void getScreenCoordinates(Vector2d worldCoordinates, Vector2d& screenVector);
    void getWorldCoordinates(Vector2d screenCoordinates, Vector2d& worldVector);
};

#endif /* defined(__CatchiOS__CoordinatesManager__) */
