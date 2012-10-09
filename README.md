CatchLib
========

Description
-----------

A C++ gamecore for the course DAT255 at Chalmers University of Technology. It utilizes OpenGL ES for rendering and homebrew physics.


Team members
------------

* JBarberU (John Barbero Unenge)
* flygarNgit (Alexander Hederstaf)
* Pungsnigel (Jesper Persson)
* rappp (Jonatan Rapp)
* Z3B0 (Sebastian Odbjer)

SCRUM Master: JBarberU Project Owner: Z3B0


Tets
----

To run the tests you'll need to create a new project/target in Eclipse (new C++ project).

Then enter the following commands in Terminal (example name of the project is CatchTests): 
  
$ cd "PathToCatchTests/CatchTests/src"  
$ rm CatchTests.cpp  
$ ln -s "PathToCatchLib/CatchLib/tests" tests  
$ mkdir src  
$ cd src  
$ ln -s "PathToCatchLib/CatchLib/src/GameModel" GameModel  
$ ln -s "PathToCatchLib/CatchLib/src/Helper" Helper  
$ ln -s "PathToCatchLib/CatchLib/src/EventHandling" EventHandling  
  
(If more packages are added they'll all have to be symlinked in this fashion)  
  
The important thing is that Controller and View packages are not symlinked as they will cause build failure as they utilize code only available on mobile devices.  
  
The resulting directory structure should look like this:  
$ ls "PathToCatchTests/CatchTests/src"  
src/ tests/  
  
$ ls "PathToCatchTests/CatchTests/src/src"  
EventHandling/ GameModel/ Helper/  
  
If the test won't compile for seemingly mysterious reasons, try cleaning the project (Project->Clean... in Eclipse).