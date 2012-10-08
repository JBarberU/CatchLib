//
//  Player.h
//  CatchiOS
//
//  Created by John Barbero Unenge on 10/7/12.
//  Copyright (c) 2012 John Barbero Unenge. All rights reserved.
//

#ifndef __CatchiOS__Player__
#define __CatchiOS__Player__

#include "../Physics/PBody.hpp"

class Player {
private:
    PBody* m_body;
    
public:
    Player();
    ~Player();
    
    void jump();
};

#endif /* defined(__CatchiOS__Player__) */
