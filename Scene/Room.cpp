//
//  Room.cpp
//  G53GRA
//
//  Created by Jason Chen on 3/23/15.
//  Copyright (c) 2015 NottinghamUniversity. All rights reserved.
//

#include "TextureManager.h"
#include "Environment.h"
#include "Room.h"

using namespace room;

Room::Room(datastruct::SquareConfig* config, datastruct::Position* pos)
    : pos(pos)
{
    texture_manager = new TextureManager();
    
    wood = new GLuint[6];
    wood[0] = texture_manager->loadImage("img/wood.bmp");
    wood[1] = wood[0];
    wood[2] = wood[1];
    wood[3] = wood[2];
    wood[4] = wood[3];
    wood[5] = wood[4];
    
    tv_wall_box = new GLuint[6];
    tv_wall_box[0] = texture_manager->loadImage("img/block.bmp");
    tv_wall_box[1] = tv_wall_box[0];
    tv_wall_box[2] = tv_wall_box[0];
    tv_wall_box[3] = tv_wall_box[0];
    tv_wall_box[4] = tv_wall_box[0];
    tv_wall_box[5] = tv_wall_box[0];
    
    room_box = new GLuint[6];
    room_box[0] = texture_manager->loadImage("img/room_front.bmp");;
    room_box[1] = texture_manager->loadImage("img/room_back.bmp");
    room_box[2] = NULL;
    room_box[3] = NULL;
    room_box[4] = NULL;
    room_box[5] = texture_manager->loadImage("img/tile.bmp");
    
    paint_box = new GLuint[6];
    paint_box[0] = texture_manager->loadImage("img/paint.bmp");
    paint_box[1] = NULL;
    paint_box[2] = NULL;
    paint_box[3] = NULL;
    paint_box[4] = NULL;
    paint_box[5] = NULL;
    
    
    kitchen_box = new GLuint[6];
    kitchen_box[0] = wood[0];
    kitchen_box[1] = wood[0];
    kitchen_box[2] = wood[0];
    kitchen_box[3] = wood[0];
    kitchen_box[4] = room_box[5];
    kitchen_box[5] = wood[0];
    
    
    // wall
    room_wall_config.width = config->width;
    room_wall_config.depth = config->depth;
    room_wall_config.height = config->height;
    room_wall_pos.x = 0;
    room_wall_pos.y = config->height / 2;
    room_wall_pos.z = 0;
    
    // paint
    paint_config.width = 30;
    paint_config.height = 42;
    paint_config.depth = 2;
    paint_pos.x = -config->width / 2 + paint_config.depth / 2;
    paint_pos.y = 60;
    paint_pos.z = -30;
    paint_pos.y_angle = 90;
    
    // TV wall sub right
    r_tvw_sub_config.width = TV_WALL_RIGHT_WIDTH;
    r_tvw_sub_config.depth = TV_WALL_RIGHT_THICK;
    r_tvw_sub_config.height = KITCHEN_HEIGHT;
    r_tvw_sub_pos.x = - config->width / 2 + TV_WALL_RIGHT_WIDTH / 2;
    r_tvw_sub_pos.y = KITCHEN_HEIGHT / 2;
    r_tvw_sub_pos.z = config->depth / 2 - KITCHEN_DEPTH - TV_WALL_RIGHT_THICK / 2;
    // TV wall
    tvw_config.width = TV_WALL_WIDTH;
    tvw_config.depth = TV_WALL_THICK;
    tvw_config.height = TV_WALL_HEIGHT;
    tvw_pos.x = r_tvw_sub_pos.x + r_tvw_sub_config.width / 2 + tvw_config.width / 2;
    tvw_pos.y = tvw_config.height / 2;
    tvw_pos.z = config->depth / 2 - KITCHEN_DEPTH - TV_WALL_THICK / 2;
    // TV wall sub left
    l_tvw_sub_config.width = TV_WALL_LEFT_WIDTH;
    l_tvw_sub_config.depth = TV_WALL_LEFT_THICK;
    l_tvw_sub_config.height = KITCHEN_HEIGHT;
    l_tvw_sub_pos.x = tvw_pos.x + tvw_config.width / 2 + l_tvw_sub_config.width / 2;
    l_tvw_sub_pos.y = l_tvw_sub_config.height / 2;
    l_tvw_sub_pos.z = r_tvw_sub_pos.z;
    
    // kitchen floor
    kit_big_config.width = KITCHEN_WIDTH;
    kit_big_config.depth = KITCHEN_DEPTH;
    kit_big_config.height = KITCHEN_HEIGHT;
    kit_big_pos.x = - config->width / 2 + kit_big_config.width / 2;
    kit_big_pos.y = kit_big_config.height / 2;
    kit_big_pos.z = config->depth / 2 - KITCHEN_DEPTH / 2;
    kit_small_config.width = config->width - kit_big_config.width;
    kit_small_config.depth = KITCHEN_DEPTH / 3;
    kit_small_config.height = KITCHEN_HEIGHT;
    kit_small_pos.x = kit_big_pos.x + kit_big_config.width / 2 + kit_small_config.width / 2;
    kit_small_pos.y = kit_big_pos.y;
    kit_small_pos.z = config->depth / 2 - kit_small_config.depth / 2;
    
    // base stair
    stair_config.width = kit_small_config.width;
    stair_config.depth = STAIR_DEPTH;
    stair_pos.x = kit_small_pos.x;
    stair_pos.z = config->depth / 2 - kit_small_config.depth - STAIR_DEPTH * (STAIR_LEVEL + 0.5);

    
    // light
    ambient[0] = .3f;
    ambient[1] = .3f;
    ambient[2] = .3f;
    ambient[3] = .3f;
    
    diffuse[0] = .3f;
    diffuse[1] = .3f;
    diffuse[1] = .3f;
    diffuse[1] = .3f;
    
    specular[0] = .1f;
    specular[1] = .1f;
    specular[2] = .1f;
    specular[3] = .1f;
    
    position[0] = 0;
    position[1] = 0;
    position[2] = 0;
    position[3] = 0.f;
}

void Room::Draw()
{
    glPushMatrix();
//    glPushAttrib(GL_LIGHTING);                          // Push/remember the materail settings before overriding the defaults
//    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient);
//    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse);
//    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
//    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_shininess);
    glTranslatef(pos->x, pos->y, pos->z);
    glRotatef(pos->z_angle, 0.f, 0.f, 1.f);
    glRotatef(pos->y_angle, 0.f, 1.f, 0.f);
    glRotatef(pos->x_angle, 1.f, 0.f, 0.f);

    // room wall
    createSquare(room_wall_config, room_wall_pos, room_box, true);
    
    // paint
    createSquare(paint_config, paint_pos, paint_box);

    // tv wall
    createSquare(r_tvw_sub_config, r_tvw_sub_pos, wood);
    createSquare(tvw_config, tvw_pos, tv_wall_box);
    createSquare(l_tvw_sub_config, l_tvw_sub_pos, wood);

    // kitchen floor
    createSquare(kit_big_config, kit_big_pos, kitchen_box);
    createSquare(kit_small_config, kit_small_pos, kitchen_box);
    
    float stair_pos_z = stair_pos.z;
    // stairs
    for (int c=0; c < STAIR_LEVEL; c++) {
        stair_config.height += STAIR_THICK;
        stair_pos.y += STAIR_THICK / 2;
        stair_pos.z += STAIR_DEPTH;
        createSquare(stair_config, stair_pos, kitchen_box);
    }

    glPopMatrix();

    stair_config.height = 0;
    stair_pos.y = 0;
    stair_pos.z = stair_pos_z;
    
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);      // set ambient parameter of light source
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);      // set diffuse parameter of light source
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular);    // set specular parameter of light source
    glLightfv(GL_LIGHT0, GL_POSITION, position);    // set direction vector of light source
    glEnable(GL_LIGHT0);
}

void Room::Update( const double& deltaTime )
{
    
}

void Room::HandleKey(int key, int state, int x, int y)
{
    
}