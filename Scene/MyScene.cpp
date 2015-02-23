
/*
Use this as the starting point to your work.
For each object in your scene, #include its header file then add it to the scene with AddObjectToScene()
*/

#include "MyScene.h"
#include "Triangle.h"

// Constructor creates your Scene and initialises the base class Scene
MyScene::MyScene( int argc, char **argv, const char *title, const int windowWidth, const int windowHeight ) : Scene(argc, argv, title, windowWidth, windowHeight)
{
}


// Initialise your scene by adding all the objects you want to be in the scene here
void MyScene::Init()
{
    // set background colour
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    // create and add a new triangle to the scene
    Triangle *t = new Triangle();
    AddObjectToScene(t);
}