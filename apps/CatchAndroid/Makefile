debug:
	ndk-build
		$(MAKE) -C jni/CatchLib compile
			./jni/CatchLib/Tests.so | grep 'All tests passed';
				ant debug
	
release:
	ndk-build
	ant release