//
//  File:	IDeviceRotationResponder.hpp
//  Class:  IDeviceRotationResponder
//  Author: John Barbero Unenge
//          All code is my own except where credited to others.
//  Copyright (c) 2012 Catch22. All rights reserved.
//
//	Date:  	10/7/12.
//
//	License: The following code is licensed under the Catch22-License
//
//  Description:
//  An interface used for notifying when the device orientation
//  changes.

#ifndef __IDeviceRotationResponder__
#define __IDeviceRotationResponder__

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
