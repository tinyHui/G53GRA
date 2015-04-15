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
        : width(config->width), depth(config->depth), height(config->height),
          pos(pos)
{
    texture_manager = new TextureManager();
    floor_box = new GLuint[6];
    floor_box[0] = texture_manager->loadImage("Resources/floor.bmp");
    floor_box[1] = floor_box[0];
    floor_box[2] = floor_box[1];
    floor_box[3] = floor_box[2];
    floor_box[4] = floor_box[3];
    floor_box[5] = floor_box[4];

    // front wall
    fw_config.width = width;
    fw_config.depth = WALL_THICK;
    fw_config.height = height;
    fw_pos.x = 0;
    fw_pos.y = height / 2. - WALL_THICK / 2;
    fw_pos.z = depth / 2.;
    
    // left wall
    lw_config.width = depth;
    lw_config.depth = WALL_THICK;
    lw_config.height = height;
    lw_pos.x = - width / 2. + WALL_THICK / 2;
    lw_pos.y = height / 2.;
    lw_pos.z = 0;
    lw_pos.y_angel = 90;
    
    // right wall
    rw_config.width = depth;
    rw_config.depth = WALL_THICK;
    rw_config.height = height;
    rw_pos.x = width / 2. - WALL_THICK / 2;
    rw_pos.y = height / 2.;
    rw_pos.z = 0;
    rw_pos.y_angel = 90;

    // back
    bw_config.width = width;
    bw_config.depth = WALL_THICK;
    bw_config.height = height;
    bw_pos.x = 0;
    bw_pos.y = height / 2.;
    bw_pos.z = - depth / 2. + WALL_THICK / 2;

    // top
    tw_config.width = width;
    tw_config.depth = depth;
    tw_config.height = WALL_THICK;
    tw_pos.x = 0;
    tw_pos.y = height - WALL_THICK / 2;
    tw_pos.z = 0;
    
    // bottom
    mw_config.width = width;
    mw_config.depth = depth;
    mw_config.height = WALL_THICK;
    mw_pos.x = 0;
    mw_pos.y = 0;
    mw_pos.z = 0;
    
    // TV wall sub right
    tvw_sub_right_config.width = TV_WALL_RIGHT_WIDTH;
    tvw_sub_right_config.depth = TV_WALL_RIGHT_THICK;
    tvw_sub_right_config.height = KITCHEN_HEIGHT;
    tvw_sub_right_pos.x =  -width / 2 + tvw_sub_right_config.width / 2;
    tvw_sub_right_pos.y = tvw_sub_right_config.height / 2;
    tvw_sub_right_pos.z = TV_WALL_Z;
    // TV wall
    tvw_config.width = TV_WALL_WIDTH;
    tvw_config.depth = TV_WALL_THICK;
    tvw_config.height = TV_WALL_HEIGHT;
    tvw_pos.x = tvw_sub_right_pos.x + tvw_sub_right_config.width / 2 + tvw_config.width / 2;
    tvw_pos.y = tvw_config.height / 2;
    tvw_pos.z = tvw_sub_right_pos.z + tvw_sub_right_config.depth / 2 - tvw_config.depth / 2;
    // TV wall sub left
    tvw_sub_left_config.width = TV_WALL_LEFT_WIDTH;
    tvw_sub_left_config.depth = TV_WALL_LEFT_THICK;
    tvw_sub_left_config.height = KITCHEN_HEIGHT;
    tvw_sub_left_pos.x = tvw_pos.x + tvw_config.width / 2 + tvw_sub_left_config.width / 2;
    tvw_sub_left_pos.y = tvw_sub_left_config.height / 2;
    tvw_sub_left_pos.z = tvw_sub_right_pos.z;
    // TV shelf
    tv_shelf_config.width = TV_SHELF_WIDTH;
    tv_shelf_config.depth = TV_SHELF_DEPTH;
    tv_shelf_config.height = TV_SHELF_THICK;
    tv_shelf_pos.x = tvw_pos.x;
    tv_shelf_pos.y = 10;
    tv_shelf_pos.z = tvw_pos.z - tv_shelf_config.depth / 2;
    
    // kitchen floor
    kit_big_config.width = tvw_sub_right_config.width + tvw_config.width + tvw_sub_left_config.width;
    kit_big_config.depth = depth / 2 - tvw_sub_right_pos.z - tvw_sub_right_config.depth / 2;
    kit_big_config.height = KITCHEN_HEIGHT;
    kit_big_pos.x = - width / 2 + kit_big_config.width / 2;
    kit_big_pos.y = kit_big_config.height / 2;
    kit_big_pos.z = tvw_sub_right_pos.z + kit_big_config.depth / 2;
    kit_small_config.width = width - kit_big_config.width;
    kit_small_config.depth = depth / 2 - STAIR_BASE_Z - STAIR_DEPTH * STAIR_LEVEL;
    kit_small_config.height = KITCHEN_HEIGHT;
    kit_small_pos.x = kit_big_pos.x + kit_big_config.width / 2 + kit_small_config.width / 2;
    kit_small_pos.y = kit_big_pos.y;
    kit_small_pos.z = depth / 2 - kit_small_config.depth / 2;
    
    // base stair
    stair_config.width = kit_small_config.width;
    stair_config.depth = STAIR_DEPTH;
    stair_pos.x = kit_small_pos.x;
}

void Room::Draw()
{
    GLfloat mat_ambient[] = { 1., 1., 1., 1. };     // Define the ambient material colour property K_a
    GLfloat mat_diffuse[] = { 1., 1., 1., 1. };     // Define the diffuse material colour property K_d
    GLfloat mat_specular[] = { 1., 1., 1., 1. };    // Define the specular material colour property K_s
    GLfloat mat_shininess[] = { 128. };

    glPushMatrix();
    glPushAttrib(GL_LIGHTING);                          // Push/remember the materail settings before overriding the defaults
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_shininess);
    glTranslatef(pos->x, pos->y, pos->z);
    glRotatef(pos->z_angel, 0.f, 0.f, 1.f);
    glRotatef(pos->y_angel, 0.f, 1.f, 0.f);
    glRotatef(pos->x_angel, 1.f, 0.f, 0.f);
    
    // room wall
    createSquare(fw_config, fw_pos);
    createSquare(lw_config, lw_pos);
    createSquare(rw_config, rw_pos);
//    createSquare(bw_config, bw_pos);
    createSquare(tw_config, tw_pos);
    createSquare(mw_config, mw_pos, floor_box);
    
    // tv wall
    createSquare(tvw_sub_right_config, tvw_sub_right_pos);
    createSquare(tvw_config, tvw_pos);
    createSquare(tvw_sub_left_config, tvw_sub_left_pos);
    createSquare(tv_shelf_config, tv_shelf_pos);
    
    
    // kitchen floor
    createSquare(kit_big_config, kit_big_pos);
    createSquare(kit_small_config, kit_small_pos);
    
    // stairs
    for (int c=0; c < STAIR_LEVEL; c++) {
        stair_config.height += STAIR_THICK;
        stair_pos.y += STAIR_THICK / 2;
        stair_pos.z += stair_config.depth;
        createSquare(stair_config, stair_pos);
    }
    
    glPopAttrib();
    glPopMatrix();
    
    stair_config.height = 0;
    stair_pos.y = 0;
    stair_pos.z = STAIR_BASE_Z;
}

void Room::Update( const double& deltaTime )
{
    
}

void Room::HandleKey(int key, int state, int x, int y)
{
    
}