//
//  GameController.hpp
//  CatchiOS
//
//  Created by John Barbero Unenge on 9/24/12.
//  Copyright (c) 2012 John Barbero Unenge. All rights reserved.
//

#ifndef CatchiOS_GameController_hpp
#define CatchiOS_GameController_hpp

#include "GLRenderer.hpp"
#include "FileManager.hpp"
#include "IInputListener.hpp"

class GameController : public IInputListener {
private:
    GLRenderer* m_renderer;
    FileManager* m_fileManager;
public:
    GameController(int width, int height);
    ~GameController();

    void setRenderer(GLRenderer* r);
    GLRenderer* getRenderer();
};

#endif
