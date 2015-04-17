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

Room::Room(datastruct::CuboidConfig* config, datastruct::Position* pos)
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
    
    
    dining_hall_box = new GLuint[6];
    dining_hall_box[0] = wood[0];
    dining_hall_box[1] = wood[0];
    dining_hall_box[2] = wood[0];
    dining_hall_box[3] = wood[0];
    dining_hall_box[4] = room_box[5];
    dining_hall_box[5] = wood[0];
    
    
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
    r_tvw_sub_config.height = DHALL_HEIGHT;
    r_tvw_sub_pos.x = - config->width / 2 + TV_WALL_RIGHT_WIDTH / 2;
    r_tvw_sub_pos.y = DHALL_HEIGHT / 2;
    r_tvw_sub_pos.z = config->depth / 2 - DHALL_DEPTH - TV_WALL_RIGHT_THICK / 2;
    // TV wall
    tvw_config.width = TV_WALL_WIDTH;
    tvw_config.depth = TV_WALL_THICK;
    tvw_config.height = TV_WALL_HEIGHT;
    tvw_pos.x = r_tvw_sub_pos.x + r_tvw_sub_config.width / 2 + tvw_config.width / 2;
    tvw_pos.y = tvw_config.height / 2;
    tvw_pos.z = config->depth / 2 - DHALL_DEPTH - TV_WALL_THICK / 2;
    // TV wall sub left
    l_tvw_sub_config.width = TV_WALL_LEFT_WIDTH;
    l_tvw_sub_config.depth = TV_WALL_LEFT_THICK;
    l_tvw_sub_config.height = DHALL_HEIGHT;
    l_tvw_sub_pos.x = tvw_pos.x + tvw_config.width / 2 + l_tvw_sub_config.width / 2;
    l_tvw_sub_pos.y = l_tvw_sub_config.height / 2;
    l_tvw_sub_pos.z = r_tvw_sub_pos.z;
    
    // dining_hall floor
    DHALL_big_config.width = DHALL_WIDTH;
    DHALL_big_config.depth = DHALL_DEPTH;
    DHALL_big_config.height = DHALL_HEIGHT;
    DHALL_big_pos.x = - config->width / 2 + DHALL_big_config.width / 2;
    DHALL_big_pos.y = DHALL_big_config.height / 2;
    DHALL_big_pos.z = config->depth / 2 - DHALL_DEPTH / 2;
    DHALL_small_config.width = config->width - DHALL_big_config.width;
    DHALL_small_config.depth = DHALL_DEPTH / 3;
    DHALL_small_config.height = DHALL_HEIGHT;
    DHALL_small_pos.x = DHALL_big_pos.x + DHALL_big_config.width / 2 + DHALL_small_config.width / 2;
    DHALL_small_pos.y = DHALL_big_pos.y;
    DHALL_small_pos.z = config->depth / 2 - DHALL_small_config.depth / 2;
    
    // base stair
    stair_config.width = DHALL_small_config.width;
    stair_config.depth = STAIR_DEPTH;
    stair_pos.x = DHALL_small_pos.x;
    stair_pos.z = config->depth / 2 - DHALL_small_config.depth - STAIR_DEPTH * (STAIR_LEVEL + 0.5);
}

void Room::Draw()
{
//    // wall
    GLfloat wall_ambient[] = { 1.f, 1.f, 1.f, 1.f };     // Define the ambient material colour property K_a
    GLfloat wall_diffuse[] = { 1.f, 1.f, 1.f, 1.f };     // Define the diffuse material colour property K_d
    GLfloat wall_specular[] = { .2f, .2f, .2f, 1.f };    // Define the specular material colour property K_s
    GLfloat wall_shininess[] = { 0. };
    
    glDisable(GL_COLOR_MATERIAL);
    glPushMatrix();

    glTranslatef(pos->x, pos->y, pos->z);
    glRotatef(pos->z_angle, 0.f, 0.f, 1.f);
    glRotatef(pos->y_angle, 0.f, 1.f, 0.f);
    glRotatef(pos->x_angle, 1.f, 0.f, 0.f);

    // room wall
    glPushAttrib(GL_LIGHTING);
    glMaterialfv(GL_FRONT, GL_AMBIENT, wall_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, wall_diffuse);
//    glMaterialfv(GL_FRONT, GL_SPECULAR, wall_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, wall_shininess);
    createCuboid(room_wall_config, room_wall_pos, room_box, true);
    glPopAttrib();
    
    // paint
    createCuboid(paint_config, paint_pos, paint_box);

    // tv wall
    createCuboid(r_tvw_sub_config, r_tvw_sub_pos, wood);
    createCuboid(tvw_config, tvw_pos, tv_wall_box);
    createCuboid(l_tvw_sub_config, l_tvw_sub_pos, wood);

    // dining_hall floor
    createCuboid(DHALL_big_config, DHALL_big_pos, dining_hall_box);
    createCuboid(DHALL_small_config, DHALL_small_pos, dining_hall_box);
    
    float stair_pos_z = stair_pos.z;
    // stairs
    for (int c=0; c < STAIR_LEVEL; c++) {
        stair_config.height += STAIR_THICK;
        stair_pos.y += STAIR_THICK / 2;
        stair_pos.z += STAIR_DEPTH;
        createCuboid(stair_config, stair_pos, dining_hall_box);
    }

    glPopMatrix();
    glEnable(GL_COLOR_MATERIAL);

    stair_config.height = 0;
    stair_pos.y = 0;
    stair_pos.z = stair_pos_z;
}

void Room::Update( const double& deltaTime )
{
}

void Room::HandleKey(int key, int state, int x, int y)
{
    
}