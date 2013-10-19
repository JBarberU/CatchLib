/**
 *
 *  File:		GameView.java
 *  Class:      GameView
 *  Author:     Alexander Hederstaf
 *  Co-Authors: Jesper Persson, John Barbero Unenge
 *              All code is my own except where credited to others.
 *
 *	Copyright © 2012 by Catch22. All Rights Reserved.
 *  Date: 		Sep 18, 2012
 */

package com.catch22.chainsaw;

import javax.microedition.khronos.egl.EGL10;
import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.egl.EGLContext;
import javax.microedition.khronos.egl.EGLDisplay;
import javax.microedition.khronos.opengles.GL10;

import android.content.Context;
import android.opengl.GLSurfaceView;
import android.util.DisplayMetrics;
import android.view.Display;
import android.view.MotionEvent;
import android.view.View;
import android.view.WindowManager;

/**
 * GameView is a GLSurfaceView and sets up rendering for native
 * C++ rendering. Initiates the games core with the first call
 * to nInit.
 */
public class GameView extends GLSurfaceView {

	private GLRenderer renderer;
	
	/**
	 * Create a new GameView, setting up the View for native openGL
	 * rendering.
	 * @param context
	 * 		Android Application context.
	 */
	public GameView(Context context) {
		super(context);
		WindowManager m = (WindowManager) context.getSystemService(Context.WINDOW_SERVICE);
		Display d = m.getDefaultDisplay();
		DisplayMetrics dm = new DisplayMetrics();
		d.getMetrics(dm);
		setEGLContextFactory(new GameContextFactory());
		renderer = new GLRenderer(dm.widthPixels, dm.heightPixels, context);
		setRenderer(renderer);
		initTouch();
	}
	
	/**
	 * Creates a touch listener for the application.
	 * Sends event to the c++ core for further
	 * processing.
	 */
	private void initTouch() {
		this.setOnTouchListener(new OnTouchListener() {
			public boolean onTouch(View v, MotionEvent event) {
				if (event.getAction() == MotionEvent.ACTION_DOWN) {
					GameView.nPassInputEvent(0, (int)event.getX(), (int)event.getY());
					return true;
				}
				return false;
			}
		});
	}

	/**
	 * pause rendering when requested.
	 */
	public void onPause() {
		
	}
	
	/**
	 * resume rendering when requested.
	 */
	public void onResume() {
		
	}
	/*
	 * Native function for passing input data to the native C++ code.
	 */
	public static native void nPassInputEvent(int type, int x, int y);

}

/**
 * ContextFactory for setting up rendering in specific ways, changes rendering to
 * use opengl1.
 */
class GameContextFactory implements GLSurfaceView.EGLContextFactory {

	/**
	 * From egl.h
	 */
	private final static int EGL_CONTEXT_CLIENT_VERSION = 0x3098;
	
	/**
	 * Creates a new openGL context that uses openGL version 1.
	 */
	public EGLContext createContext(EGL10 egl, EGLDisplay display, EGLConfig eglConfig) {
		int[] attr_list = {EGL_CONTEXT_CLIENT_VERSION, 1, EGL10.EGL_NONE};
		return egl.eglCreateContext(display, eglConfig, EGL10.EGL_NO_CONTEXT, attr_list);
	}

	/**
	 * Destroys the openGL context.
	 */
	public void destroyContext(EGL10 egl, EGLDisplay display, EGLContext context) {
		egl.eglDestroyContext(display, context);
	}
}

/**
 * GLRenderer handles the rendering. The GLSurfaceView passes
 * render calls to this at specified intervals.
 */
class GLRenderer implements GLSurfaceView.Renderer {

	private int width;
	private int height;
	private Context context;
	private static final int MAXIMUM_FPS = 1000 / 60;
	
	private long timeLastFrame, newTime, dt;

	/**
	 * Create a new GLRenderer used for rendering on the GLSurfaceView.
	 * @param width 
	 * 		Width of the View
	 * @param height 
	 * 		Height of the View
	 * @param context
	 * 		Android Application context.
	 */
	public GLRenderer(int width, int height, Context context) {
		this.context = context;
		this.width = width;
		this.height = height;
	}
	
	/* Overriden method */
	public void onDrawFrame(GL10 gl) {
		/*
		 * To make the rendering smooth we use deltaTime
		 * in our rendering rather than assuming a constant
		 * frame rate.
		 */
		newTime = System.currentTimeMillis();
		dt = newTime - timeLastFrame;
		
		if (dt < MAXIMUM_FPS) {
			try {
				Thread.sleep(MAXIMUM_FPS - dt);
			} catch (InterruptedException e) { }
		}
		nUpdate(dt / 1000.0f);
		timeLastFrame = newTime;
	}
	/* Overriden method */
	public void onSurfaceChanged(GL10 gl, int width, int height) {}

	/* Overriden method */
	public void onSurfaceCreated(GL10 gl, EGLConfig config) {
		nInit(this.width, this.height, ImageLoader.loadTextureData("texture_library", this.context));
		timeLastFrame = System.currentTimeMillis();
	}		
	
	/**
	 * Native method stub for update calls.
	 * 
	 * @param dt
	 * 		The time passed in milli-seconds since the last call to nUpdate.
	 */
	public static native void nUpdate(float dt);
	
	/**
	 * Native method stub for initiation call.
	 * 
	 * @param width
	 * 		Width of the Screen and GLSurfaceView.
	 * @param height
	 * 		Height of the Screen and GLSurfaceView.
	 * @param data
	 * 		TextureData stored as pixel data in an integer-array.
	 */
	public static native void nInit(int width, int height, int[] data);
}