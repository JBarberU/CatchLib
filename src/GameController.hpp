//
//  GameController.hpp
//  CatchiOS
//
//  Created by John Barbero Unenge on 9/24/12.
//  Copyright (c) 2012 John Barbero Unenge. All rights reserved.
//

#ifndef CatchiOS_GameController_hpp
#define CatchiOS_GameController_hpp

#include "IRenderer.hpp"
#include "FileManager.hpp"
#include "IInputListener.hpp"
#include "EInputType.hpp"
#include "EventHandling/IEventListener.hpp"
#include "EventHandling/EEvent.hpp"

class GameController : public IInputListener, public IEventListener {
private:
    IRenderer* m_renderer;
    FileManager* m_fileManager;
public:
    GameController(int width, int height, const char* resourcesPath);
    ~GameController();

    void update(float dt);
    
    //  IInputListener
    virtual void didRecieveInputEvent(InputType type, int locX, int locY);

    virtual void onEvent(EEvent event, void* source);
};

#endif
