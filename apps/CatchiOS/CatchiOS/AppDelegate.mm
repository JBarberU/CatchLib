//
//  AppDelegate.m
//  CatchiOS
//
//  Created by John Barbero Unenge on 9/6/12.
//  Copyright (c) 2012 John Barbero Unenge. All rights reserved.
//

#import "AppDelegate.h"
#import "GLView.h"
#import "InputManager.hpp"
#import "EInputType.hpp"

@implementation AppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    CGRect screenBounds = [[UIScreen mainScreen] bounds];
    
    m_window = [[UIWindow alloc] initWithFrame:screenBounds];
    m_view = [[GLView alloc] initWithFrame:screenBounds];
    
    [m_window addSubview:m_view];
    [m_window makeKeyAndVisible];
    
    return YES;
}

- (void) touchesBegan:(NSSet *)touches withEvent:(UIEvent *)event
{
    if (touches != nil && [touches count] > 0) {
        for (UITouch* touch in touches) {
            InputManager::getSharedManager()->passInputEvent(TOUCH, [touch locationInView:m_view].x, [touch locationInView:m_view].y);
        }
    }
}
- (void) touchesCancelled:(NSSet *)touches withEvent:(UIEvent *)event
{
    
}
- (void) touchesEnded:(NSSet *)touches withEvent:(UIEvent *)event
{
    
}
- (void) touchesMoved:(NSSet *)touches withEvent:(UIEvent *)event
{
    
}

- (void)applicationWillResignActive:(UIApplication *)application
{
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
}

- (void)applicationDidEnterBackground:(UIApplication *)application
{
    // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later. 
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
}

- (void)applicationWillEnterForeground:(UIApplication *)application
{
    // Called as part of the transition from the background to the inactive state; here you can undo many of the changes made on entering the background.
}

- (void)applicationDidBecomeActive:(UIApplication *)application
{
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
}

- (void)applicationWillTerminate:(UIApplication *)application
{
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}

@end
