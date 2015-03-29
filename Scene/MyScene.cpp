
/*
Use this as the starting point to your work.
For each object in your scene, #include its header file then add it to the scene with AddObjectToScene()
*/

#include "Environment.h"
#include "MyScene.h"
#include "Chair.h"
#include "Armchair.h"
#include "Couch.h"
#include "Table.h"
#include "Cell.h"
#include "WallShelf.h"
#include "Clock.h"
#include "Lamp.h"
#include "Sun.h"
#include "LampLight.h"

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
    glEnable(GL_COLOR_MATERIAL);
//    glFrontFace(GL_CCW);
    glEnable(GL_LIGHTING);
    glEnable(GL_DEPTH_TEST);
    
    CellConfig* room1_config = new CellConfig();
    room1_config->width = 70;
    room1_config->depth = 65;
    room1_config->height = 30;
    room1_config->have_top = false;
    room1_config->have_front = false;
    Position* room1_pos = new Position();
    room1_pos->x = 0;
    room1_pos->y = 0;
    room1_pos->z = 0;
    Cell* room1 = new Cell(room1_config, room1_pos);
    AddObjectToScene(room1);
    
//    Position* chair1_pos = new Position();
//    chair1_pos->x = 10;
//    chair1_pos->z = -26;
//    chair1_pos->y_angel = -40;
//    Chair* chair1 = new Chair(chair1_pos);
//    AddObjectToScene(chair1);
    
    Position* sofa1_pos = new Position();
    sofa1_pos->x = -2;
    sofa1_pos->z = -23;
    Couch* sofa1 = new Couch(sofa1_pos);
    AddObjectToScene(sofa1);
    
    Position* sofa2_pos = new Position();
    sofa2_pos->x = -26;
    sofa2_pos->z = -8;
    sofa2_pos->y_angel = 90;
    Armchair* sofa2 = new Armchair(sofa2_pos);
    AddObjectToScene(sofa2);

    Position* table1_pos = new Position();
    table1_pos->x = 18;
    table1_pos->z = -15;
    table1_pos->y_angel = 20;
    Table* table1 = new Table(table1_pos);
    AddObjectToScene(table1);
    
    SquareShelf* wall_shelf1_config = new SquareShelf();
    wall_shelf1_config->width = 15;
    wall_shelf1_config->depth = 3;
    Position* wall_shelf1_pos = new Position();
    wall_shelf1_pos->x = (room1_config->width - wall_shelf1_config->depth) / 2;;
    wall_shelf1_pos->y = 15;
    wall_shelf1_pos->z = 11;
    wall_shelf1_pos->y_angel = 90;
    WallShelf* shelf1 = new WallShelf(wall_shelf1_config, wall_shelf1_pos);
    AddObjectToScene(shelf1);

    Position* clock_pos = new Position();
    clock_pos->x = wall_shelf1_pos->x;
    clock_pos->y = wall_shelf1_pos->y + wall_shelf::THICK + time_clock::R;
    clock_pos->z = wall_shelf1_pos->z + 2;
    clock_pos->x_angel = -70;
    clock_pos->y_angel = 92;
    Clock* clock1 = new Clock(clock_pos);
    AddObjectToScene(clock1);
    
//    CellConfig* ground_box1_config = new CellConfig();
//    ground_box1_config->width = 5;
//    ground_box1_config->depth = 5;
//    ground_box1_config->height = 5;
//    ground_box1_config->have_front = false;
//    Position* ground_box1_pos = new Position();
//    ground_box1_pos->x = -17;
//    ground_box1_pos->y = 0;
//    ground_box1_pos->z = -28;
//    ground_box1_pos->y_angel = 25;
//    Cell* ground_box1 = new Cell(ground_box1_config, ground_box1_pos);
//    AddObjectToScene(ground_box1);
//    
//    CellConfig* ground_box2_config = new CellConfig();
//    ground_box2_config->width = 5;
//    ground_box2_config->depth = 5;
//    ground_box2_config->height = 5;
//    ground_box2_config->have_front = false;
//    Position* ground_box2_pos = new Position();
//    ground_box2_pos->x = -23;
//    ground_box2_pos->y = 0;
//    ground_box2_pos->z = -18;
//    ground_box2_pos->y_angel = 10;
//    Cell* ground_box2 = new Cell(ground_box2_config, ground_box2_pos);
//    AddObjectToScene(ground_box2);

    Position* lamp1_pos = new Position();
    lamp1_pos->x = -29;
    lamp1_pos->z = -24;
    lamp1_pos->y_angel = 45;
    Lamp* lamp1 = new Lamp(lamp1_pos);
    AddObjectToScene(lamp1);
    
    Sun* sun = new Sun();
    AddObjectToScene(sun);
    
    LampLight* lamp_light = new LampLight(lamp1_pos);
    AddObjectToScene(lamp_light);
    
}