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
//  Description:
//
//	License: The following code is licensed under the Catch22-License
//

#include "Obstacle.hpp"

class ObstacleBox : Obstacle {

private:
	bool m_destroyed;
	double m_height;

public:
	~ObstacleBox();
	ObstacleBox(Vector2d* position, float height);
	void destroy();
	void generatePbody(Vector2d position);
};

