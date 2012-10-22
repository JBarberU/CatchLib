//
//  File:   GameController.hpp
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
//  Description:
//  The controller for the game. It keeps track of game rules
//  and keep all parts together.

#ifndef CatchiOS_GameController_hpp
#define CatchiOS_GameController_hpp

#include "../View/IRenderer.hpp"
#include "../Helper/IInputListener.hpp"
#include "../Helper/EInputType.hpp"
#include "../View/CLTexture.hpp"
#include "IDeviceRotationResponder.hpp"
#include "../GameModel/GameModel.hpp"

class GameController : public IInputListener, public IDeviceRotationResponder {
private:
    IRenderer*  m_renderer;
    GameModel*  m_gameModel;
    DeviceOrientation m_deviceOrientation;
    
    int m_deviceWidth, m_deviceHeight;
    
public:
    GameController(int width, int height, CLTexture* texture);
    ~GameController();

    //  Update the GameController
    void update(float dt);
    
    //  Ingerited from IDeviceResponder
    void onRotate(DeviceOrientation orientation);
    
    //  Inherited from IInputListener
    virtual void didRecieveInputEvent(InputType type, int locX, int locY);
};

#endif
