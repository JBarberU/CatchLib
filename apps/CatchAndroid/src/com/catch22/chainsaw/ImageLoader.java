/**
 *
 *  File:		ImageLoader.java
 *  Class:      ImageLoader
 *  Author:     Alexander Hederstaf
 *              All code is my own except where credited to others.
 *
 *	Copyright © 2012 by Catch22. All Rights Reserved.
 *  Date: 		Oct 3, 2012
 */

package com.catch22.chainsaw;

import java.io.IOException;
import java.io.InputStream;

import android.content.Context;
import android.content.res.AssetManager;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.util.Log;

/**
 * ImageLoader loads Assets from the Android file system and returns
 * the pixel data for usage in C++ core.
 */
public class ImageLoader {
	
	/**
	 * Hide constructor as this is a utility class
	 */
	private ImageLoader() { }
	
	
	/**
	 * 
	 * Loads a png image resource from the assets of the application and extracts
	 * the color data. Puts the data in an integer array and returns this array.
	 * <p>
	 * Each integer image data is in the ARGB format.
	 * 
	 * @param fileName
	 * 		The name of the image file to be loaded. Exclude .png file ending
	 * 		and only include path inside the assets folder.
	 * @param context
	 * 		An android context with access to the fileName image resource.
	 * @return
	 * 		A integer array with pixel data from the provided image
	 * 		in ARGB format.
	 */
	public static int[] loadTextureData(String fileName, Context context) {
		if (context == null) {
			throw new IllegalStateException();
		}
		AssetManager assets = context.getAssets();
		InputStream is = null;

		int[] imageData = null;
		try {
			is = assets.open(fileName + ".png");
			Bitmap bm = BitmapFactory.decodeStream(is);
			int width = bm.getWidth();
			int height = bm.getHeight();
			/*
			 * Create an array of size width*height + 2 and
			 * save the first two positions in the array to
			 * store width and height. This information is 
			 * needed in the C++ code.
			 */
			imageData = new int[width * height + 2];
			bm.getPixels(imageData, 2, width, 0, 0, width, height);
			imageData[0] = width;
			imageData[1] = height;
		} catch (IOException e) {
			Log.e("AndroidImgLoad", "IO-Exception Loading Image");
			return new int[]{0, 0};
		}
		return imageData;
	}
}