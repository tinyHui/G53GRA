
/*
Use this as the starting point to your work.
For each object in your scene, #include its header file then add it to the scene with AddObjectToScene()
*/

#include "Environment.h"
#include "MyScene.h"
#include "Chair.h"
#include "Armchair.h"
#include "CouchMain.h"
#include "CouchSide.h"
#include "Carpet.h"
#include "Table.h"
#include "Room.h"
#include "Clock.h"
#include "Lamp.h"
#include "Sun.h"
#include "Dog.h"

using namespace datastruct;

#define WGL_SAMPLE_BUFFERS_ARB	0x2041
#define WGL_SAMPLES_ARB		0x2042
bool arbMultisampleSupported = false;
int arbMultisampleFormat = 0;

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
    glDisable(GL_LIGHTING);
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_DEPTH_TEST);
    
    // living room
    SquareConfig* room_config = new SquareConfig();
    room_config->width = 140;
    room_config->depth = 200;
    room_config->height = 100;
    Position* room_pos = new Position();
    room_pos->x = 0;
    room_pos->y = 0;
    room_pos->z = 0;
    Room* living_room = new Room(room_config, room_pos);
    AddObjectToScene(living_room);

    // livingroom
    carpet::Config* carpet_config = new carpet::Config();
    carpet_config->width = 35;
    carpet_config->depth = 32;
    Position* carpet_pos = new Position();
    carpet_pos->x = -20;
    carpet_pos->z = -52;
    Carpet* carpet = new Carpet(carpet_config, carpet_pos);
    AddObjectToScene(carpet);
    
    Position* couch_main_pos = new Position();
    couch_main_pos->x = carpet_pos->x;
    couch_main_pos->z = carpet_pos->z - carpet_config->depth / 2 - carpet::CARPET_SOFA_GAP;
    CouchMain* couch_main = new CouchMain(couch_main_pos);
    AddObjectToScene(couch_main);

    Position* l_couch_side_pos = new Position();
    l_couch_side_pos->x = carpet_pos->x + carpet_config->width / 2 + carpet::CARPET_SOFA_GAP;
    l_couch_side_pos->z = carpet_pos->z;
    l_couch_side_pos->y_angle = -90;
    CouchSide* couch_sidel = new CouchSide(l_couch_side_pos);
    AddObjectToScene(couch_sidel);

    Position* r_couch_side_pos = new Position();
    r_couch_side_pos->x = carpet_pos->x - carpet_config->width / 2 - carpet::CARPET_SOFA_GAP;
    r_couch_side_pos->z = carpet_pos->z;
    r_couch_side_pos->y_angle = 90;
    CouchSide* couch_sider = new CouchSide(r_couch_side_pos);
    AddObjectToScene(couch_sider);

    // kitchen
    Position* table_pos = new Position();
    table_pos->x = - room_config->width / 2 + room::KITCHEN_WIDTH / 2;
    table_pos->y = room::KITCHEN_HEIGHT;
    table_pos->z = room_config->depth / 2 - room::KITCHEN_DEPTH / 2;
    table_pos->y_angle = 20;
    Table* table = new Table(table_pos);
    AddObjectToScene(table);
    
    Position* chair1_pos = new Position();
    chair1_pos->x = table_pos->x + 11;
    chair1_pos->y = table_pos->y;
    chair1_pos->z = table_pos->z + 11;
    chair1_pos->y_angle = -115;
    Chair* chair1 = new Chair(chair1_pos);
    AddObjectToScene(chair1);
    
    Position* chair2_pos = new Position();
    chair2_pos->x = table_pos->x + 11;
    chair2_pos->y = table_pos->y;
    chair2_pos->z = table_pos->z - 11;
    chair2_pos->y_angle = -45;
    Chair* chair2 = new Chair(chair2_pos);
    AddObjectToScene(chair2);
    
    Position* chair3_pos = new Position();
    chair3_pos->x = table_pos->x - 11;
    chair3_pos->y = table_pos->y;
    chair3_pos->z = table_pos->z - 11;
    chair3_pos->y_angle = 45;
    Chair* chair3 = new Chair(chair3_pos);
    AddObjectToScene(chair3);
    
    Position* chair4_pos = new Position();
    chair4_pos->x = table_pos->x - 11;
    chair4_pos->y = table_pos->y;
    chair4_pos->z = table_pos->z + 11;
    chair4_pos->y_angle = 115;
    Chair* chair4 = new Chair(chair4_pos);
    AddObjectToScene(chair4);
    
    Position* clock_pos = new Position();
    clock_pos->x = room_pos->x + room_config->width / 2 - time_clock::BASE_THICK - 1;
    clock_pos->y = room::KITCHEN_HEIGHT + 48;
    clock_pos->z = room_pos->z + room_config->depth / 2 - 30;
    clock_pos->x_angle = 5;
    clock_pos->y_angle = -90;
    Clock* clock = new Clock(clock_pos);
    AddObjectToScene(clock);
    
    Position* dog_pos = new Position();
    dog_pos->x = -26;
    dog_pos->z = -18;
    Dog* dog = new Dog(dog_pos);
    AddObjectToScene(dog);
    
    Position* lamp_pos = new Position();
    lamp_pos->x = carpet_pos->x - carpet_config->width / 2 - carpet::CARPET_LAMP_GAP;
    lamp_pos->z = carpet_pos->z - carpet_config->depth / 2 - carpet::CARPET_LAMP_GAP;
    lamp_pos->y_angle = 45;
    Lamp* lamp = new Lamp(lamp_pos);
    AddObjectToScene(lamp);
    
    glEnable(GL_LIGHTING);
}