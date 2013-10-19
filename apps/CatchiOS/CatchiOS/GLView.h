//
//  GLView.h
//  CatchiOS
//
//  Created by John Barbero Unenge on 9/20/12.
//  Copyright (c) 2012 John Barbero Unenge. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <OpenGLES//EAGL.h>
#import <QuartzCore/QuartzCore.h>
#import "GameController.hpp"

@interface GLView : UIView {
    EAGLContext* m_glContext;
    GameController* m_gameController;
    float m_timestamp;
}

- (void) drawView: (CADisplayLink*) displayLink;
- (void) didRotate: (NSNotification*) notification;

@end
