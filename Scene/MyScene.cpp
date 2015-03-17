
/*
Use this as the starting point to your work.
For each object in your scene, #include its header file then add it to the scene with AddObjectToScene()
*/

#include "Environment.h"
#include "MyScene.h"
#include "Light.h"
#include "Chair.h"

using namespace datastruct;

// Constructor creates your Scene and initialises the base class Scene
MyScene::MyScene( int argc, char **argv, const char *title, const int windowWidth, const int windowHeight ) : Scene(argc, argv, title, windowWidth, windowHeight)
{
}

// Initialise your scene by adding all the objects you want to be in the scene here
void MyScene::Init()
{
    // set background colour
    glClearDepth(1);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_CULL_FACE);
    
    Light* l = new Light();
    AddObjectToScene(l);
    
    Position* chair1_pos = new Position();
    chair1_pos->x = 0;
    chair1_pos->z = -20;
    chair1_pos->y_angel = 30;
    Chair* chair1 = new Chair(chair1_pos);
    AddObjectToScene(chair1);
}