//
//  OffsetMatrix.hpp
//  CatchiOS
//
//  Created by John Barbero Unenge on 10/15/12.
//  Copyright (c) 2012 John Barbero Unenge. All rights reserved.
//
//	License: The following code is licensed under the Catch22-License

#ifndef CatchiOS_OffsetMatrix_hpp
#define CatchiOS_OffsetMatrix_hpp

#include "../Math/Vector2d.hpp"

struct OffsetMatrix {
    Vector2d* m_bottomLeft;
    Vector2d* m_bottomRight;
    Vector2d* m_topLeft;
    Vector2d* m_topRight;
    OffsetMatrix(Vector2d* bottomLeft, Vector2d* bottomRight, Vector2d* topLeft, Vector2d* topRight) {
        m_bottomLeft = bottomLeft;
        m_bottomRight = bottomRight;
        m_topLeft = topLeft;
        m_topRight = topRight;
    }
    OffsetMatrix(OffsetMatrix* matrix) {
        this->m_bottomLeft = matrix->m_bottomLeft;
        this->m_bottomRight = matrix->m_bottomRight;
        this->m_topLeft = matrix->m_topLeft;
        this->m_topRight = matrix->m_topRight;
    }
};

#endif
