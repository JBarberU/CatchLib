//
//  File:	CoordinatesManager.hpp
//  Author: John Barbero Unenge 
//	Date:  	10/22/12.
//
//  Copyright (c) 2012 Catch22. All rights reserved.
//
//	All code is my own except where credited to others.
//


#ifndef __CoordinatesManager__
#define __CoordinatesManager__

#include "../Math/Vector2d.hpp"

class CoordinatesManager {
private:
    static CoordinatesManager* s_CoordinatesManager;
    CoordinatesManager();

    Vector2d* m_worldCoordinate;
    
public:
    //  Get an instance of the shared coordinates manager
    static CoordinatesManager* getSharedInstance();
    
    //  Updates the world coordinate
    void updateWorldCoordinate(Vector2d worldCoordinate);
    
    //  Convert world coordinates to screen coordinates
    Vector2d* getScreenCoordinates(Vector2d worldCoordinates);
    
    //  Converts screen coordinates to world coordinates
    Vector2d* getWorldCoordinates(Vector2d screenCoordinates);

    //  Convert world coordinates to screen coordinates
    void getScreenCoordinates(Vector2d worldCoordinates, Vector2d& screenVector);

    //  Converts screen coordinates to world coordinates
    void getWorldCoordinates(Vector2d screenCoordinates, Vector2d& worldVector);
};

#endif /* defined(__CoordinatesManager__) */
