//
//  File:	IDeviceRotationResponder.hpp
//  Class:  IDeviceRotationResponder
//  Author: John Barbero Unenge
//          All code is my own except where credited to others.
//  Copyright (c) 2012 John Barbero Unenge. All rights reserved.
//
//	Date:  	10/7/12.
//
//  Description:
//  An interface used for notifying when the device orientation
//  changes.
//
#ifndef CatchiOS_IDeviceRotationResponder_hpp
#define CatchiOS_IDeviceRotationResponder_hpp

enum DeviceOrientation {
    DeviceOrientationLandscapeLeft,
    DeviceOrientationLandscapeRight
};

class IDeviceRotationResponder {
public:
    //  Called when device orientation changes.
    virtual void onRotate(DeviceOrientation orientation) = 0;
};

#endif
