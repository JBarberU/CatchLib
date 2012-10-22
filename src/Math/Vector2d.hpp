//
//  Vector2d.hpp
//  CatchiOS
//
//  Created by John Barbero Unenge on 10/2/12.
//  Copyright (c) 2012 John Barbero Unenge. All rights reserved.
//
//	License: The following code is licensed under the Catch22-License
//

#ifndef __CatchiOS__Vector__
#define __CatchiOS__Vector__

struct Vector2d {
    Vector2d(double x, double y);
    Vector2d(Vector2d* vec);
    Vector2d(Vector2d* vec, double magnitude);
    Vector2d();
    double m_x, m_y;
    double lengthSquared();
    void zap();
    
    double overlaps(Vector2d* otherVector);
    
    //  Operators
    Vector2d operator=(Vector2d vector);
    bool operator==(Vector2d vector);
    Vector2d operator+=(Vector2d vector);
    Vector2d operator-=(Vector2d vector);
    Vector2d operator*=(double);
    Vector2d operator*(double);
    Vector2d operator*(Vector2d vector);
};

#endif /* defined(__CatchiOS__Vector__) */
