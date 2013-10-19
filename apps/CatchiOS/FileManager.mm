//
//  FileManager.m
//  CatchiOS
//
//  Created by John Barbero Unenge on 10/4/12.
//  Copyright (c) 2012 John Barbero Unenge. All rights reserved.
//

#import "FileManager.hpp"
#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>

CLTexture* FileManager::loadTexture(const char* fileName)
{
    CGImage* spriteImage = [UIImage imageNamed:[NSString stringWithFormat:@"%s.png", fileName]].CGImage;
	// Get the width and height of the image
	int width = CGImageGetWidth(spriteImage);
	int height = CGImageGetHeight(spriteImage);
	// Texture dimensions must be a power of 2. If you write an application that allows users to supply an image,
	// you'll want to add code that checks the dimensions and takes appropriate action if they are not a power of 2.
    
	if(spriteImage) {
		// Allocated memory needed for the bitmap context
		GLubyte* spriteData = (GLubyte *) calloc(width * height * 4, sizeof(GLubyte));
		// Uses the bitmap creation function provided by the Core Graphics framework.
		CGContextRef spriteContext = CGBitmapContextCreate(spriteData, width, height, 8, width * 4, CGImageGetColorSpace(spriteImage), kCGImageAlphaPremultipliedLast);
		// After you create the context, you can draw the sprite image to the context.
		CGContextDrawImage(spriteContext, CGRectMake(0.0, 0.0, (CGFloat)width, (CGFloat)height), spriteImage);
		// You don't need the context at this point, so you need to release it to avoid memory leaks.
		CGContextRelease(spriteContext);
        
        CLTexture* texture = new CLTexture();
        texture->setData(spriteData, width, height);
        
        free(spriteData);
        
        return texture;
    }
    
    return 0;
}
