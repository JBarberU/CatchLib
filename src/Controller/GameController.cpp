//
//  File:   GameController.cpp
//  Class:  GameController
//  Author: John Barbero Unenge
//      All code is my own except where credited to others.
//
//  Copyright (c) 2012 Catch22. All Rights Reserved.
//
//  Date:   24/9/12
//
//	License: The following code is licensed under the Catch22-License
//

#include "GameController.hpp"
#include "../Helper/Logger.hpp"
#include "../Helper/InputManager.hpp"
#include "../Helper/Constants.hpp"
#include "../Helper/CoordinatesManager.hpp"

#include "../Helper/CoordinatesManager.hpp"

GameController::GameController(int width, int height, CLTexture* texture)
{
	srand ( time(NULL) );

    Constants::init(width, height);
    
    m_deviceWidth = width;
    m_deviceHeight = height;
    
    m_deviceOrientation = DeviceOrientationLandscapeLeft;
    InputManager::getSharedManager()->addInputListener(this);

    m_renderer = CreateRendererWithOpenGL10();
    m_renderer->init(m_deviceWidth, m_deviceHeight, texture);
    m_gameModel = new GameModel();
}
GameController::~GameController()
{
    Log(LOG_INFO, "GameController", "Destroyed GameController");
}

void GameController::update(float dt)
{
    m_renderer->update(dt);
    m_gameModel->update(dt);

    CoordinatesManager::getSharedInstance()->updateWorldCoordinate(Vector2d(m_gameModel->getCenterPoint()->m_x, 0.f));
    
    m_renderer->render();
}
void GameController::onRotate(DeviceOrientation orientation)
{
    m_deviceOrientation = orientation;
    m_renderer->onRotate(m_deviceOrientation);
}
void GameController::didRecieveInputEvent(InputType type, int locX, int locY)
{
    
    int conX, conY;
    
    switch (this->m_deviceOrientation) {
        case DeviceOrientationLandscapeLeft:
            conX = locY;
            conY = locX;
            break;
        case DeviceOrientationLandscapeRight:
            conX = m_deviceHeight - locY;
            conY = m_deviceWidth - locX;
            break;
    }
    
    if (conX < m_deviceHeight * 0.3) {
        m_gameModel->playerJump();
    } else {
        Vector2d worldCoords;
        CoordinatesManager::getSharedInstance()->getWorldCoordinates(Vector2d((float)locY / (float)m_deviceHeight  * Constants::getGameWidth(), (float)locX / (float)m_deviceWidth * Constants::getGameHeight()), worldCoords);
        Log(LOG_INFO, "GameController", generateCString("ScreenCoords: %d, %d",((float)locX / (float)m_deviceWidth * Constants::getGameWidth()), ((float)locY / (float)m_deviceHeight * Constants::getGameHeight())));
        Log(LOG_INFO, "GameController", generateCString("WorldCoords: %d, %d",worldCoords.m_x, worldCoords.m_y));
        m_gameModel->playerThrowAt(worldCoords.m_x, worldCoords.m_y);
    }
    
	Log(LOG_EVENT, "GameController",  "DidRecieveInputEvent");
}
