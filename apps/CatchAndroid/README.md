#CatchAndroid

##Description

This is an Android wrapper for the C++ gamecore (CatchLib) for the course DAT255 at Chalmers University of Technology.
  
  
##Team members
  
  
* JBarberU (John Barbero Unenge)
* flygarNgit (Alexander Hederstaf)
* Pungsnigel (Jesper Persson)
* rappp (Jonatan Rapp)
* Z3B0 (Sebastian Odbjer)

SCRUM Master: JBarberU  
Project Owner: Z3B0
  
##Installing


To compile and install this project you'll need to have:  
  
* Android SDK installed on your system, preferably with the tools folder exported to $PATH  
* Android NDK exported to $PATH  
* GNU Make  
* Apache Ant (or simply called Ant)  
* Git  

If you are going to help developing this project you'll probably also want:
  
* An IDE such as Eclipse.  
* The ADT plugin for Eclipse.  
* The CDT plugin Eclipse.  
  
To get this game built and installed you'll need to clone down the CatchAndroid repository first to some location on your harddrive. Inside the **_CatchAndroid_** directory you'll find one called **_jni/_**, jump into that directory. In here you should either clone down the **_CatchLib_** repository or create a symbolic link to wherever you'd rather put that repo. Leading to the following:

	SomePlace/CatchAndroid/jni/CatchLib

Where **_CatchLib_** is either a symbolic link or a real directory.

Now, jump back into the **_CatchAndroid_** directory.

Next step is to configure your local path variables for Android, which is done with the following command:

	$ android update project --path .
	
When that's done you just run this command:

	$ make debug
	
If it succeeds you should end up with a runnable APK inside the **_bin/_** folder.

