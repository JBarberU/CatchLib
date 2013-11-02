//
//  File:	ObstacleBox.hpp
//  Class	ObstacleBox
//  Author	Jonatan Rapp
//			All code is my own except where credited to others.
//
//  Copyright © 2012 Catch22. All Rights Reserved.
//
//  Date: Oct 8, 2012
//
//	License: The following code is licensed under the Catch22-License
//
//  Description: A class for representing a obstacle formed like a box.



#include "Obstacle.hpp"

class ObstacleBox : Obstacle {

private:
	bool m_destroyed;
	double m_height;

public:
	~ObstacleBox();
	ObstacleBox(Vector2d* position, float height);

	/**
	 * Publishes an "destroyed Pbody event" on the eventbus to let the handlers know
	 * it has been destroyed.
	 */
	void destroy();

	/**
	 * @see Obstacle.hpp
	 */
	void generatePbody(Vector2d position);
};

