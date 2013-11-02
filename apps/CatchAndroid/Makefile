default:
	$(MAKE) debug

debug:
	ndk-build
	ant debug
	
install:
	adb install -d -r bin/GameActivity-debug.apk

release:
	ndk-build
	ant release

clean:
	ndk-build clean
	ant clean
