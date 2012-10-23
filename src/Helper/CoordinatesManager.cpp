//
//  File:	CoordinatesManager.cpp
//  Author: John Barbero Unenge 
//	Date:  	10/22/12.
//
//  Copyright (c) 2012 Catch22. All rights reserved.
//
//	All code is my own except where credited to others.
//


#include "CoordinatesManager.hpp"

CoordinatesManager* CoordinatesManager::s_CoordinatesManager;

CoordinatesManager* CoordinatesManager::getSharedInstance()
{
    if (s_CoordinatesManager == 0)
        s_CoordinatesManager = new CoordinatesManager();
    
    return s_CoordinatesManager;
}
CoordinatesManager::CoordinatesManager()
{
    this->m_worldCoordinate = new Vector2d(0.f, 0.f);
}
void CoordinatesManager::updateWorldCoordinate(Vector2d worldCoordinate)
{
    this->m_worldCoordinate->m_x = worldCoordinate.m_x;
    this->m_worldCoordinate->m_y = worldCoordinate.m_y;
}
Vector2d* CoordinatesManager::getScreenCoordinates(Vector2d worldCoordinates)
{
    return new Vector2d(worldCoordinates.m_x - this->m_worldCoordinate->m_x, worldCoordinates.m_y - this->m_worldCoordinate->m_y);
}
Vector2d* CoordinatesManager::getWorldCoordinates(Vector2d screenCoordinates)
{
    return new Vector2d(screenCoordinates.m_x + this->m_worldCoordinate->m_x, screenCoordinates.m_y + this->m_worldCoordinate->m_y);
}
void CoordinatesManager::getScreenCoordinates(Vector2d worldCoordinates, Vector2d& screenVector)
{
    screenVector.m_x = worldCoordinates.m_x - this->m_worldCoordinate->m_x;
    screenVector.m_y = worldCoordinates.m_y - this->m_worldCoordinate->m_y;
}
void CoordinatesManager::getWorldCoordinates(Vector2d screenCoordinates, Vector2d& worldVector)
{
    worldVector.m_x = screenCoordinates.m_x + this->m_worldCoordinate->m_x;
    worldVector.m_y = screenCoordinates.m_y + this->m_worldCoordinate->m_y;
}

