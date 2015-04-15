
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
#include "LampLight.h"
#include "Outdoor.h"
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
    glEnable(GL_LIGHTING);
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_DEPTH_TEST);
    
    // living room
    SquareConfig* room_config = new SquareConfig();
    room_config->width = 120;
    room_config->depth = 180;
    room_config->height = 100;
    Position* room_pos = new Position();
    room_pos->x = 20;
    room_pos->y = 0;
    room_pos->z = 50;
    Room* living_room = new Room(room_config, room_pos);
    AddObjectToScene(living_room);
    
    Position* clock_pos = new Position();
    clock_pos->x = room_pos->x + room_config->width / 2 - time_clock::BASE_THICK - 1;
    clock_pos->y = room::KITCHEN_HEIGHT + 48;
    clock_pos->z = room_pos->z + room_config->depth / 2 - 30;
    clock_pos->x_angel = 83;
    clock_pos->y_angel = 90;
    Clock* clock1 = new Clock(clock_pos);
    AddObjectToScene(clock1);

    Position* lamp1_pos = new Position();
    lamp1_pos->x = -29;
    lamp1_pos->z = -24;
    lamp1_pos->y_angel = 45;
    Lamp* lamp1 = new Lamp(lamp1_pos);
    AddObjectToScene(lamp1);
    
    Position* couch_main_pos = new Position();
    couch_main_pos->x = 2;
    couch_main_pos->z = -28;
    CouchMain* couch_main = new CouchMain(couch_main_pos);
    AddObjectToScene(couch_main);
    
    Position* couch_sidel_pos = new Position();
    couch_sidel_pos->x = 29;
    couch_sidel_pos->z = -5;
    couch_sidel_pos->y_angel = -90;
    CouchSide* couch_sidel = new CouchSide(couch_sidel_pos);
    AddObjectToScene(couch_sidel);
    
    Position* couch_sider_pos = new Position();
    couch_sider_pos->x = -24;
    couch_sider_pos->z = -5;
    couch_sider_pos->y_angel = 90;
    CouchSide* couch_sider = new CouchSide(couch_sider_pos);
    AddObjectToScene(couch_sider);
    
    carpet::Config* carpet_config = new carpet::Config();
    carpet_config->width = 35;
    carpet_config->depth = 32;
    Position* carpet_pos = new Position();
    carpet_pos->x = 3;
    carpet_pos->z = -2;
    Carpet* carpet = new Carpet(carpet_config, carpet_pos);
    AddObjectToScene(carpet);

    // kitchen
    Position* table_pos = new Position();
    table_pos->x = room_pos->x - 20;
    table_pos->y = room::KITCHEN_HEIGHT;
    table_pos->z = room_pos->z - room::TV_WALL_Z + 30;
    table_pos->y_angel = 20;
    Table* table = new Table(table_pos);
    AddObjectToScene(table);

    Position* chair1_pos = new Position();
    chair1_pos->x = table_pos->x - 20;
    chair1_pos->y = table_pos->y;
    chair1_pos->z = table_pos->z;
    chair1_pos->y_angel = 90;
    Chair* chair1 = new Chair(chair1_pos);
    AddObjectToScene(chair1);
    
    Position* chair2_pos = new Position();
    chair2_pos->x = table_pos->x + 20;
    chair2_pos->y = table_pos->y;
    chair2_pos->z = table_pos->z;
    chair2_pos->y_angel = -90;
    Chair* chair2 = new Chair(chair2_pos);
    AddObjectToScene(chair2);
    
    Position* chair3_pos = new Position();
    chair3_pos->x = table_pos->x;
    chair3_pos->y = table_pos->y;
    chair3_pos->z = table_pos->z - 20;
    chair3_pos->y_angel = 0;
    Chair* chair3 = new Chair(chair3_pos);
    AddObjectToScene(chair3);
    
    Position* chair4_pos = new Position();
    chair4_pos->x = table_pos->x;
    chair4_pos->y = table_pos->y;
    chair4_pos->z = table_pos->z + 20;
    chair4_pos->y_angel = 180;
    Chair* chair4 = new Chair(chair4_pos);
    AddObjectToScene(chair4);
    
    Position* chair5_pos = new Position();
    chair5_pos->x = table_pos->x + 14;
    chair5_pos->y = table_pos->y;
    chair5_pos->z = table_pos->z + 14;
    chair5_pos->y_angel = -135;
    Chair* chair5 = new Chair(chair5_pos);
    AddObjectToScene(chair5);
    
    Position* chair6_pos = new Position();
    chair6_pos->x = table_pos->x + 14;
    chair6_pos->y = table_pos->y;
    chair6_pos->z = table_pos->z - 14;
    chair6_pos->y_angel = -45;
    Chair* chair6 = new Chair(chair6_pos);
    AddObjectToScene(chair6);
    
    Position* chair7_pos = new Position();
    chair7_pos->x = table_pos->x - 14;
    chair7_pos->y = table_pos->y;
    chair7_pos->z = table_pos->z - 14;
    chair7_pos->y_angel = 45;
    Chair* chair7 = new Chair(chair7_pos);
    AddObjectToScene(chair7);
    
    Position* chair8_pos = new Position();
    chair8_pos->x = table_pos->x - 14;
    chair8_pos->y = table_pos->y;
    chair8_pos->z = table_pos->z + 14;
    chair8_pos->y_angel = 135;
    Chair* chair8 = new Chair(chair8_pos);
    AddObjectToScene(chair8);
    
    // yard
    SquareConfig* outdoor_config = new SquareConfig();
    outdoor_config->width = room_config->width + dog::WALK_OFFSET_LIM * 3;
    outdoor_config->depth = room_config->depth + dog::WALK_OFFSET_LIM * 3;
    outdoor_config->height = room_config->height + 100;
    Position* outdoor_pos = new Position();
    outdoor_pos->x = room_pos->x;
    outdoor_pos->y = -0.01;
    outdoor_pos->z = room_pos->z - dog::WALK_OFFSET_LIM;
    Outdoor* outdoor = new Outdoor(outdoor_config, outdoor_pos);
    AddObjectToScene(outdoor);
    //    Position* armchair_pos = new Position();
    //    armchair_pos->x = -23;
    //    armchair_pos->z = -10;
    //    armchair_pos->y_angel = 90;
    //    Armchair* armchair = new Armchair(armchair_pos);
    //    AddObjectToScene(armchair);
    Position* dog_pos = new Position();
    dog_pos->x = room_pos->x;
    dog_pos->z = room_pos->z - room_config->depth / 2 - dog::WALK_OFFSET_LIM - 10;
    Dog* dog = new Dog(dog_pos);
    AddObjectToScene(dog);
    
    Sun* sun = new Sun();
    AddObjectToScene(sun);

    LampLight* lamp_light = new LampLight(lamp1_pos);
    AddObjectToScene(lamp_light);
}