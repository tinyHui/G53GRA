
/*
Use this as the starting point to your work.
For each object in your scene, #include its header file then add it to the scene with AddObjectToScene()
*/

#include "MyScene.h"
#include "Triangle.h"
#include "Ground.h"
#include "Stair.h"

// Constructor creates your Scene and initialises the base class Scene
MyScene::MyScene( int argc, char **argv, const char *title, const int windowWidth, const int windowHeight ) : Scene(argc, argv, title, windowWidth, windowHeight)
{
}


// Initialise your scene by adding all the objects you want to be in the scene here
void MyScene::Init()
{
    // set background colour
    glClearDepth(1);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_CULL_FACE);
    
    Ground *ground = new Ground();
    AddObjectToScene(ground);

    Stair *stair = new Stair();
    AddObjectToScene(stair);
}