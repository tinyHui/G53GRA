
/*
The starting point for your work, this class overides the Scene class. You can add to it as more parts
of the coursework become possible by overriding functions from the Scene class. Initially, you can set up
the scene using the Init() function.
*/

#pragma once

#include "Scene.h"

class MyScene : public Scene
{

public:

	// Constructor is called when the program starts
    MyScene( int argc, char **argv, const char *title, const int windowWidth, const int windowHeight );
	// Destructor is called when the program ends
    ~MyScene(){};

private:

	// Initialise function is called just before the window opens
    // Use it to add all the objects to the scene that you would like to draw
	void Init();

};
