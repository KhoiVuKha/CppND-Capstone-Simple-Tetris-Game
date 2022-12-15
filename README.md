# CPPND: Capstone Simple Tetris Game Repo

This is a Simple Tetris Game Repo for the Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213).
This project structure is inherited from [The empty starter Github repositry](https://github.com/udacity/CppND-Capstone-Hello-World).
And Simple Tetris Game is cloned from [CppND-Capstone-Tetris-Game](https://github.com/Federico-abss/Udacity_Cpp/tree/master/CppND-Capstone-Tetris-Game).

With adding some features as follow:
* Move all config for screen to main.cpp.
* Fix code to show window title ans close button, also display score and FPS.
* Move handle input evens to Controller class (Added Controller class).
* Move render business to Render class (Added Render class).
* Add score log when terminate the game.

Here is image captured from the game:

![image](https://user-images.githubusercontent.com/15206083/187814719-9aadf42b-7ae0-4a1c-9513-e520e2329e53.png)

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  >Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source.
  * MacOS chip M2:
  `git clone https://github.com/libsdl-org/SDL.git -b SDL2`
  
  `cd SDL`
  
  `mkdir build`
  
  `cd build`
  
  `../configure`
  
  `make`
  
  `sudo make install`
  
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SimpleTetrisGame`.

## How to play

* Player should place the falling tetrominos in a way that the Well has as less as possible empty cells. 
* When line in the Well has no empty cells, it is deleted. 
* Player can rotate tetrominos, accelerate their fall. 
* Player fails, when at least one figure exaggerates the game field on the top. 
* For one deleted line player receives 100 scores.

Controll the game by some key evens:
* Left arrow  - move the tetromino left.
* Right arrow - move the tetromino right.
* Down        - move the tetromino down.
* Space       - Rotate the tetromino.

## Project structure

The Simple Tetris game code consists of five main classes: Game, Tetromino, Well, Controller, and Renderer.
* To begin, main creates a Controller, a Game, and a Renderer object. Game stores a Tetromino and Well object as part of the state.
* main calls Game::Run to start the game loop.

Here is project structure:

![image](https://user-images.githubusercontent.com/15206083/187814522-8fec3d5b-27d4-43ef-830e-ab1fd8a7c2ed.png)


## The following rubric points are addressed

* README
  * A README with instructions is included with the project.
  * The README indicates which project is chosen (As in beginning of the README.md file). The project also indicates the file and class structure (as in Project structure section).
  * The README includes information about each rubric point addressed.

* Compiling and Testing
  * The project code compile and run without errors

* Loops, Functions, I/O
  * The project demonstrates an understanding of C++ functions and control structures: file src/main.cpp:13:16; file src/controller.cpp (line 8 - line 42) - HandleInput method - use of multiple switch case.
  * The project accepts user input and processes the input using the SDL library.

* Object Oriented Programming
  * The project uses Object Oriented Programming techniques. Can be seen in each file except main.cpp
  * Classes use appropriate access specifiers for class members. Classes encapsulate behavior. Classes abstract implementation details from their interfaces. can be seen in tetromino.h, controller.h, game.h, renderer.h...
  * Class constructors utilize member initialization lists: file src/renderer.cpp:8

* Memory Management
  * The project makes use of references in function declarations: src/controller.h:9, /src/game.h:15, /src/game.h:25, /src/renderer.h:14, ...
  * The project uses destructors appropriately: src/renderer.cpp:34:38
