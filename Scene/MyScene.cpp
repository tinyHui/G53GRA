
/*
Use this as the starting point to your work.
For each object in your scene, #include its header file then add it to the scene with AddObjectToScene()
*/

#include "Environment.h"
#include "MyScene.h"
#include "Triangle.h"
#include "Ground.h"
#include "Stair.h"
#include "House.h"

using namespace datastruct;
using namespace globalconf;

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
//    
//    Ground *ground = new Ground();
//    AddObjectToScene(ground);

    // main stair
    Vertice* v1 = new Vertice( -160, 150, nullptr );
    Vertice* v2 = new Vertice( -160, -150, v1 );
    Vertice* v3 = new Vertice( -130, -150, v2 );
    Vertice* v4 = new Vertice( -130, -220, v3 );
    Vertice* v5 = new Vertice( 130, -220, v4 );
    Vertice* v6 = new Vertice( 130, -150, v5 );
    Vertice* v7 = new Vertice( 160, -150, v6 );
    Vertice* v9 = new Vertice( 160, 150, v7 );
    
    StairConfig* main_stair_config = new StairConfig();
    main_stair_config->width = 320.;
    main_stair_config->deepth = 370.;
    main_stair_config->level = 3;
    main_stair_config->diff = 50.;
    main_stair_config->base_pos = { 0, 0, 10 };
    main_stair_config->v = v9;
    
    Stair *main_stair = new Stair(main_stair_config);
    AddObjectToScene(main_stair);
    
    // main house
    HouseConfig* main_house_config = new HouseConfig();
    main_house_config->top_body_width = 120.;
    main_house_config->top_body_deepth = 80.;
    main_house_config->top_body_height = 20.;
    main_house_config->btm_body_width = 150.;
    main_house_config->btm_body_deepth = 100.;
    main_house_config->btm_body_height = 80.;
    main_house_config->base_pos = {main_stair_config->base_pos.x, *main_stair->getTopY(), main_stair_config->base_pos.z - 50};
    
    House *house = new House(main_house_config);
    AddObjectToScene(house);
}