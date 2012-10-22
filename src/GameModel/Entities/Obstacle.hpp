//
//  File:	Obstacle.hpp
//  Class	Obstacle
//  Author	Jonatan Rapp
//			All code is my own except where credited to others.
//
//  Copyright © 2012 Catch22. All Rights Reserved.
//
//  Date: Oct 8, 2012
//
//  Description:
//	Abstract class meant to be extended by obstacles.
//
//	License: The following code is licensed under the Catch22-License
//

#include "../Physics/PBody.hpp"
#include "../../EventHandling/EventBus.hpp"
#include "../../Helper/Logger.hpp"
#include "../../../Box2D/Collision/Shapes/b2PolygonShape.h"

class Obstacle {

public:
	virtual void destroy() = 0;
	virtual void generatePbody(Vector2d position) = 0;
	PBody* m_body;
};

