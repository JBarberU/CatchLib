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
    Vector2d(Vector2d* vec);
    double m_x, m_y;
    double lengthSquared();
    void zap();
    
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
