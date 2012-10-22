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
    //  Construcs a Vector with the given x and y
    Vector2d(double x, double y);
    
    //  Constructs a vector that has the same x and y as vec
    Vector2d(Vector2d* vec);
    
    //  Constructs a vector that has the length magnitude and the same
    //  direction as vec
    Vector2d(Vector2d* vec, double magnitude);
    Vector2d();
    double m_x, m_y;
    
    //  Gives you the length squared
    double lengthSquared();
    
    //  Sets x and y to zero
    void zap();
    
    //  Checks if two vectors overlap
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
