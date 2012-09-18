//
//  InputManager.hpp
//  CatchLib
//
//  Created by John Barbero Unenge on 9/17/12.
//  Copyright (c) 2012 John Barbero Unenge. All rights reserved.
//

#ifndef CatchiOS_InputManager_h
#define CatchiOS_InputManager_h
typedef InputType {
    TOUCH;
    MENU_BUTTON
};

class InputManager{
    // Should be a float value between 0 and 1    
    void passInputEvent(InputType input, float locX, float locY);
};


#endif
