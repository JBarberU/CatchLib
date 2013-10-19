/**
 *
 *  File:		GameActivity.java
 *  Class:      GameActivity
 *  Author:     Alexander Hederstaf, Jesper Persson, John Barbero Unenge
 *              All code is my own except where credited to others.
 *
 *	Copyright © 2012 by Catch22. All Rights Reserved.
 *  Date: 		Sep 17, 2012
 */

package com.catch22.chainsaw;

import android.app.Activity;
import android.content.pm.ActivityInfo;
import android.os.Bundle;
import android.view.OrientationEventListener;
import android.view.Window;
import android.view.WindowManager;

public class GameActivity extends Activity {

	static {
    	System.loadLibrary("catchLib");
    }
	
	private GameView gameView;
	private int deviceAngle = 90;
	
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        
        requestWindowFeature(Window.FEATURE_NO_TITLE);
        getWindow().setFlags(WindowManager.LayoutParams.FLAG_FULLSCREEN, WindowManager.LayoutParams.FLAG_FULLSCREEN);
        
        this.setRequestedOrientation(ActivityInfo.SCREEN_ORIENTATION_PORTRAIT);
        
        // TODO This listener has to be removed when the app is terminated
        new OrientationEventListener(this) {
			
			@Override
			public void onOrientationChanged(int orientation) {
				if (orientation > 45 && orientation < 135 && deviceAngle != 90) {
					updateDeviceOrientation(0);
					deviceAngle = 90;
				}
				else if (orientation > 225  && orientation < 315 && deviceAngle != 270) {
					updateDeviceOrientation(1);
					deviceAngle = 270;
				}
			}
		}.enable();
        
        gameView = new GameView(this);
        setContentView(gameView);
    }

    @Override
    protected void onPause() {
    	super.onPause();
    	gameView.onPause();
    }
    
    @Override
    protected void onResume() {
    	super.onResume();
    	gameView.onResume();
    }
    
    public static native void updateDeviceOrientation(int orientation);
}