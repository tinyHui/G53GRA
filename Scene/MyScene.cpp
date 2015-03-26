
/*
Use this as the starting point to your work.
For each object in your scene, #include its header file then add it to the scene with AddObjectToScene()
*/

#include "Environment.h"
#include "MyScene.h"
#include "Light.h"
#include "Chair.h"
#include "Table.h"
#include "Cell.h"
#include "WallShelf.h"

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
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_POLYGON_SMOOTH);
    
    Position* chair1_pos = new Position();
    chair1_pos->x = 8.9;
    chair1_pos->z = -24.5;
    chair1_pos->y_angel = -40;
    Chair* chair1 = new Chair(chair1_pos);
    AddObjectToScene(chair1);

    Position* table1_pos = new Position();
    table1_pos->x = 5;
    table1_pos->z = -20;
    table1_pos->y_angel = 20;
    Table* table1 = new Table(table1_pos);
    AddObjectToScene(table1);
    
    CellConfig* room1_config = new CellConfig();
    room1_config->width = 60.f;
    room1_config->depth = 80.f;
    room1_config->height = 30.f;
    room1_config->have_top =false;
    Position* room1_pos = new Position();
    room1_pos->x = 0;
    room1_pos->y = 0;
    room1_pos->z = 0;
    Cell* room1 = new Cell(room1_config, room1_pos);
    AddObjectToScene(room1);
    
    SquareShelf* wall_shelf1_config = new SquareShelf();
    wall_shelf1_config->width = 10;
    wall_shelf1_config->depth = 3;
    Position* wall_shelf1_pos = new Position();
    wall_shelf1_pos->x = -10;
    wall_shelf1_pos->y = 10;
    wall_shelf1_pos->z = -(room1_config->depth - wall_shelf1_config->depth) / 2;
    WallShelf* shelf1 = new WallShelf(wall_shelf1_config, wall_shelf1_pos);
    AddObjectToScene(shelf1);
}