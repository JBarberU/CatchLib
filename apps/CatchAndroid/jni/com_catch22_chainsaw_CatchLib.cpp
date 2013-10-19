#include <com_catch22_chainsaw_CatchLib.h>
#include "CatchLib/src/Helper/Logger.hpp"
#include "CatchLib/src/Controller/GameController.hpp"
#include "CatchLib/src/Helper/InputManager.hpp"
#include "CatchLib/src/Helper/EInputType.hpp"
#include "CatchLib/src/View/CLTexture.hpp"
#include "CatchLib/src/Helper/CStringer.hpp"

GameController* s_controller;

JNIEXPORT void JNICALL Java_com_catch22_chainsaw_GLRenderer_nUpdate
  (JNIEnv *env, jclass clazz, jfloat dt)
{
	s_controller->update(dt);
}
JNIEXPORT void JNICALL Java_com_catch22_chainsaw_GLRenderer_nInit(JNIEnv *env, jclass clazz, jint width, jint height, jintArray arr)
{
	jint* values = env->GetIntArrayElements(arr, 0);
	int imgWidth  = (int) *values++;
	int imgHeight = (int) *values++;
	unsigned char* data = new unsigned char[imgWidth * imgHeight * 4];
	for (int i = 0; i < imgWidth * imgHeight * 4; i += 4) {
		data[i]   = (unsigned char) ((values[i/4] >> 16) & 0xFF);
		data[i+1] = (unsigned char) ((values[i/4] >> 8) & 0xFF);
		data[i+2] = (unsigned char) ((values[i/4]) & 0xFF);
		data[i+3] = (unsigned char) ((values[i/4] >> 24) & 0xFF);
	}
	CLTexture* texture = new CLTexture();
	texture->setData(data, imgWidth, imgHeight);

	s_controller = new GameController((int)width, (int)height, texture);

	Log(LOG_INFO, "com_catch22_chainsaw_CatchLib", "Done with init");
}

JNIEXPORT void JNICALL Java_com_catch22_chainsaw_GameView_nPassInputEvent(JNIEnv *env, jclass clazz, jint type, jint x, jint y)
{
	InputType iType;
	switch(type){
	case 0:
		iType = TOUCH;
		break;
	case 1:
		iType = MENU_BUTTON;
		break;
	};
	InputManager::getSharedManager()->passInputEvent(iType, x,y);
}

JNIEXPORT void JNICALL Java_com_catch22_chainsaw_GameActivity_updateDeviceOrientation(JNIEnv* enc, jclass clazz, jint deviceOrientation)
{
	if (s_controller == 0)
		return;

	DeviceOrientation orientation;

	switch (deviceOrientation) {
	case 0:
		orientation = DeviceOrientationLandscapeRight;
		break;
	case 1:
		orientation = DeviceOrientationLandscapeLeft;
		break;
	};

    s_controller->onRotate(orientation);

}
