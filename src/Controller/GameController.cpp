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

#include "GameController.hpp"
#include "../Helper/Logger.hpp"
#include "../Helper/InputManager.hpp"
#include "../Helper/Constants.hpp"


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
    m_renderer->centerCameraOn(*m_gameModel->getCenterPoint());
    
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
        m_gameModel->playerThrowAt(conX / m_deviceHeight, conY / m_deviceWidth);
    }
    
	Log(LOG_EVENT, "GameController",  "DidRecieveInputEvent");
}
