//
//  Room.cpp
//  G53GRA
//
//  Created by Jason Chen on 3/23/15.
//  Copyright (c) 2015 NottinghamUniversity. All rights reserved.
//

#include "Environment.h"
#include "Room.h"

using namespace room;

Room::Room(datastruct::BlockConfig* config, datastruct::Position* pos)
        : width(config->width), depth(config->depth), height(config->height), pos(pos)
{
}

void Room::Draw()
{
    // left wall
    SquareConfig* lw_config = new SquareConfig();
    lw_config->width = depth;
    lw_config->depth = THICK;
    lw_config->height = height;
    Position* lw_pos = new Position();
    lw_pos->x = pos->x - width / 2.;
    lw_pos->y = pos->y + height / 2.;
    lw_pos->z = pos->z;
    lw_pos->y_angel = 90;
    
    // right wall
    SquareConfig* rw_config = new SquareConfig();
    rw_config->width = depth;
    rw_config->depth = THICK;
    rw_config->height = height;
    Position* rw_pos = new Position();
    rw_pos->x = pos->x + width / 2.;
    rw_pos->y = pos->y + height / 2.;
    rw_pos->z = pos->z;
    rw_pos->y_angel = 90;
    
    // back wall
    SquareConfig* bw_config = new SquareConfig();
    bw_config->width = width;
    bw_config->depth = THICK;
    bw_config->height = height;
    Position* bw_pos = new Position();
    bw_pos->x = pos->x;
    bw_pos->y = pos->y + height / 2.;
    bw_pos->z = pos->z - depth / 2.;
    
    // front wall
    SquareConfig* fw_config = new SquareConfig();
    fw_config->width = width;
    fw_config->depth = THICK;
    fw_config->height = height;
    Position* fw_pos = new Position();
    fw_pos->x = pos->x;
    fw_pos->y = pos->y + height / 2.;
    fw_pos->z = pos->z + depth / 2.;
    
    // roof
    SquareConfig* rf_config = new SquareConfig();
    rf_config->width = width;
    rf_config->depth = depth;
    rf_config->height = THICK;
    Position* rf_pos = new Position();
    rf_pos->x = pos->x;
    rf_pos->y = pos->y + height;
    rf_pos->z = pos->z;

    
    // Draw
    glPushMatrix();
    createSquare(lw_config, lw_pos);
    createSquare(rw_config, rw_pos);
    createSquare(bw_config, bw_pos);
    createSquare(fw_config, fw_pos);
//    createSquare(rf_config, rf_pos);
    glPopMatrix();
}

void Room::Update( const double& deltaTime )
{
    
}

void Room::HandleKey(int key, int state, int x, int y)
{
    
}