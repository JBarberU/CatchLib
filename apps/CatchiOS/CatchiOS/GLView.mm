//
//  GLView.m
//  CatchiOS
//
//  Created by John Barbero Unenge on 9/20/12.
//  Copyright (c) 2012 John Barbero Unenge. All rights reserved.
//

#import "GLView.h"
#import "Logger.hpp"
#include "FileManager.hpp"

@implementation GLView

+ (Class) layerClass
{
    return [CAEAGLLayer class];
}

- (id)initWithFrame:(CGRect)frame
{
    if ([super initWithFrame:frame]) {
        CAEAGLLayer* eaglLayer = (CAEAGLLayer*) super.layer;
        eaglLayer.opaque = YES;
        
        EAGLRenderingAPI api = kEAGLRenderingAPIOpenGLES1;
        m_glContext = [[EAGLContext alloc] initWithAPI:api];
                
        if (!m_glContext || ![EAGLContext setCurrentContext:m_glContext]) {
            return nil;
        }
        
        m_gameController = new GameController(CGRectGetWidth(frame), CGRectGetHeight(frame), FileManager::loadTexture("texture_library"));
        [m_glContext renderbufferStorage:GL_RENDERBUFFER fromDrawable:eaglLayer];
        
        [self drawView:nil];
         
        m_timestamp = CACurrentMediaTime();
        CADisplayLink* displayLink = [CADisplayLink displayLinkWithTarget:self selector:@selector(drawView:)];
        
        [displayLink addToRunLoop:[NSRunLoop currentRunLoop] forMode:NSDefaultRunLoopMode];
        
        [[UIDevice currentDevice] beginGeneratingDeviceOrientationNotifications];
        
        [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(didRotate:) name:UIDeviceOrientationDidChangeNotification object:nil];
        
        Log(LOG_INFO, "GLView", "Reached end of init");
    }
    
    return self;
}
- (void) didRotate:(NSNotification *)notification
{
    DeviceOrientation orientation;
    
    switch ([[UIDevice currentDevice] orientation]) {
        case UIDeviceOrientationLandscapeLeft:
            orientation = DeviceOrientationLandscapeLeft;
            break;
        case UIDeviceOrientationLandscapeRight:
            orientation = DeviceOrientationLandscapeRight;
            break;
        default:
            orientation = DeviceOrientationLandscapeLeft;
            break;
    }
    m_gameController->onRotate(orientation);
}
- (void) drawView: (CADisplayLink*) displayLink
{
    if (displayLink != nil) {
        float elapsedSeconds = displayLink.timestamp - m_timestamp;
        m_timestamp = displayLink.timestamp;
        m_gameController->update(elapsedSeconds);
        [m_glContext presentRenderbuffer:GL_RENDERBUFFER];
    }
}

@end
