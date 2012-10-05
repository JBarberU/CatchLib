//
//  GameController.hpp
//  CatchiOS
//
//  Created by John Barbero Unenge on 9/24/12.
//  Copyright (c) 2012 John Barbero Unenge. All rights reserved.
//

#ifndef CatchiOS_GameController_hpp
#define CatchiOS_GameController_hpp

#include "../View/IRenderer.hpp"
#include "../Helper/IInputListener.hpp"
#include "../Helper/EInputType.hpp"
#include "../View/CLTexture.hpp"

class GameController : public IInputListener {
private:
    IRenderer* m_renderer;
public:
    GameController(int width, int height, CLTexture* texture);
    ~GameController();

    void update(float dt);
    
    //  IInputListener
    virtual void didRecieveInputEvent(InputType type, int locX, int locY);
};

#endif
