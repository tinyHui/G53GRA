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
    
    tile = new GLuint[6];
    tile[0] = texture_manager->loadImage("img/tile.bmp");
    tile[1] = tile[0];
    tile[2] = tile[1];
    tile[3] = tile[2];
    tile[4] = tile[3];
    tile[5] = tile[4];
    
    kitchen_box = new GLuint[6];
    kitchen_box[0] = NULL;
    kitchen_box[1] = NULL;
    kitchen_box[2] = wood[0];
    kitchen_box[3] = wood[0];
    kitchen_box[4] = tile[0];
    kitchen_box[5] = NULL;
    
    
    // front wall
    fw_config.width = width - 2 * WALL_THICK;
    fw_config.depth = WALL_THICK;
    fw_config.height = height;
    fw_pos.x = 0;
    fw_pos.y = height / 2. - WALL_THICK / 2;
    fw_pos.z = depth / 2.;
    
    // back
    bw_config.width = fw_config.width;
    bw_config.depth = WALL_THICK;
    bw_config.height = height;
    bw_pos.x = 0;
    bw_pos.y = height / 2.;
    bw_pos.z = - depth / 2.;
    
    // left wall
    rw_config.width = depth;
    rw_config.depth = WALL_THICK;
    rw_config.height = height;
    rw_pos.x = - width / 2. + WALL_THICK / 2;
    rw_pos.y = height / 2.;
    rw_pos.z = 0;
    rw_pos.y_angel = 90;
    
    // right wall
    lw_config.width = depth;
    lw_config.depth = WALL_THICK;
    lw_config.height = height;
    lw_pos.x = width / 2. - WALL_THICK / 2;
    lw_pos.y = height / 2.;
    lw_pos.z = 0;
    lw_pos.y_angel = 90;
    
    // top
    tw_config.width = fw_config.width;
    tw_config.depth = depth;
    tw_config.height = WALL_THICK;
    tw_pos.x = 0;
    tw_pos.y = height - WALL_THICK / 2;
    tw_pos.z = 0;
    
    // bottom
    mw_config.width = fw_config.width;
    mw_config.depth = depth;
    mw_config.height = WALL_THICK;
    mw_pos.x = 0;
    mw_pos.y = 0;
    mw_pos.z = 0;
    
    // TV wall sub right
    r_tvw_sub_config.width = TV_WALL_RIGHT_WIDTH;
    r_tvw_sub_config.depth = TV_WALL_RIGHT_THICK;
    r_tvw_sub_config.height = KITCHEN_HEIGHT;
    r_tvw_sub_pos.x = rw_pos.x + WALL_THICK / 2 + TV_WALL_RIGHT_WIDTH / 2;
    r_tvw_sub_pos.y = r_tvw_sub_config.height / 2;
    r_tvw_sub_pos.z = TV_WALL_Z;
    // TV wall
    tvw_config.width = TV_WALL_WIDTH;
    tvw_config.depth = TV_WALL_THICK;
    tvw_config.height = TV_WALL_HEIGHT;
    tvw_pos.x = r_tvw_sub_pos.x + r_tvw_sub_config.width / 2 + tvw_config.width / 2;
    tvw_pos.y = tvw_config.height / 2;
    tvw_pos.z = r_tvw_sub_pos.z + r_tvw_sub_config.depth / 2 - tvw_config.depth / 2;
    // TV wall sub left
    l_tvw_sub_config.width = TV_WALL_LEFT_WIDTH;
    l_tvw_sub_config.depth = TV_WALL_LEFT_THICK;
    l_tvw_sub_config.height = KITCHEN_HEIGHT;
    l_tvw_sub_pos.x = tvw_pos.x + tvw_config.width / 2 + l_tvw_sub_config.width / 2;
    l_tvw_sub_pos.y = l_tvw_sub_config.height / 2;
    l_tvw_sub_pos.z = r_tvw_sub_pos.z;
    
    // kitchen floor
    kit_big_config.width = r_tvw_sub_config.width + tvw_config.width + l_tvw_sub_config.width;
    kit_big_config.depth = depth / 2 - r_tvw_sub_pos.z - r_tvw_sub_config.depth / 2;
    kit_big_config.height = KITCHEN_HEIGHT;
    kit_big_pos.x = rw_pos.x + WALL_THICK / 2 + kit_big_config.width / 2;
    kit_big_pos.y = kit_big_config.height / 2;
    kit_big_pos.z = r_tvw_sub_pos.z + r_tvw_sub_config.depth / 2 + kit_big_config.depth / 2;
    kit_small_config.width = bw_config.width - kit_big_config.width;
    kit_small_config.depth = depth / 2 - STAIR_BASE_Z - STAIR_DEPTH * STAIR_LEVEL - STAIR_DEPTH / 2;
    kit_small_config.height = KITCHEN_HEIGHT;
    kit_small_pos.x = kit_big_pos.x + kit_big_config.width / 2 + kit_small_config.width / 2;
    kit_small_pos.y = kit_big_pos.y;
    kit_small_pos.z = depth / 2 - kit_small_config.depth / 2;
    
    // base stair
    stair_config.width = kit_small_config.width;
    stair_config.depth = STAIR_DEPTH;
    stair_pos.x = kit_small_pos.x;
    stair_pos.x_angel = 0;
    stair_pos.y_angel = 0;
    stair_pos.z_angel = 0;
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
    glRotatef(pos->z_angel, 0.f, 0.f, 1.f);
    glRotatef(pos->y_angel, 0.f, 1.f, 0.f);
    glRotatef(pos->x_angel, 1.f, 0.f, 0.f);
    
    // room wall
    createSquare(fw_config, fw_pos);
    createSquare(lw_config, lw_pos);
    createSquare(rw_config, rw_pos);
    //    createSquare(bw_config, bw_pos);
    createSquare(tw_config, tw_pos);
    createSquare(mw_config, mw_pos, tile);
    
    // tv wall
    createSquare(r_tvw_sub_config, r_tvw_sub_pos, wood);
    createSquare(tvw_config, tvw_pos, tv_wall_box);
    createSquare(l_tvw_sub_config, l_tvw_sub_pos, wood);
    
    // kitchen floor
    createSquare(kit_big_config, kit_big_pos, kitchen_box);
    createSquare(kit_small_config, kit_small_pos, tile);
    
    // stairs
    for (int c=0; c < STAIR_LEVEL; c++) {
        stair_config.height += STAIR_THICK;
        stair_pos.y += STAIR_THICK / 2;
        stair_pos.z += stair_config.depth;
        createSquare(stair_config, stair_pos, tile);
    }
    
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