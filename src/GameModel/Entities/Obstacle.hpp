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
//	License: The following code is licensed under the Catch22-License
//
//  Description:
//	Abstract class meant to be extended by obstacles.
//	Obstacles are objects that can be destroyed by the chainsaw.


#include "../Physics/PBody.hpp"
#include "../../EventHandling/EventBus.hpp"
#include "../../Helper/Logger.hpp"
#include "../../../Box2D/Collision/Shapes/b2PolygonShape.h"

class Obstacle {

public:
	/**
	 * Removes the Obstacle in a suitable way to this specific obstacle.
	 */
	virtual void destroy() = 0;
	/**
	 * Generates the physical body of the obstacle.
	 */
	virtual void generatePbody(Vector2d position) = 0;
	PBody* m_body;
};

