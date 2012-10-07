//
//  File:	IDeviceRotationResponder.hpp
//  Author: John Barbero Unenge 
//	Date:  	10/7/12.
//
//  Copyright (c) 2012 John Barbero Unenge. All rights reserved.
//
//	All code is my own except where credited to others.
//


#ifndef CatchiOS_IDeviceRotationResponder_hpp
#define CatchiOS_IDeviceRotationResponder_hpp

enum DeviceOrientation {
    DeviceOrientationLandscapeLeft,
    DeviceOrientationLandscapeRight
};

class IDeviceRotationResponder {
public:
    virtual void onRotate(DeviceOrientation orientation) = 0;
};

#endif
