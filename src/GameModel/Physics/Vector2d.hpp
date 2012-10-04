//
//  Vector2d.hpp
//  CatchiOS
//
//  Created by John Barbero Unenge on 10/2/12.
//  Copyright (c) 2012 John Barbero Unenge. All rights reserved.
//

#ifndef __CatchiOS__Vector__
#define __CatchiOS__Vector__

struct Vector2d {
    Vector2d(double x, double y);
    double m_x, m_y;
    double lengthSquared();
    Vector2d operator=(const Vector2d);
    bool operator==(const Vector2d);
    Vector2d operator+=(const Vector2d);
    Vector2d operator-=(const Vector2d);
};

#endif /* defined(__CatchiOS__Vector__) */
