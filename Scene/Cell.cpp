//
//  Room.cpp
//  G53GRA
//
//  Created by Jason Chen on 3/23/15.
//  Copyright (c) 2015 NottinghamUniversity. All rights reserved.
//

#include "Environment.h"
#include "Cell.h"

using namespace room;

Cell::Cell(datastruct::CellConfig* config, datastruct::Position* pos)
        : width(config->width), depth(config->depth), height(config->height), pos(pos),
          have_front(config->have_front), have_back(config->have_back), have_left(config->have_left),
          have_right(config->have_right), have_top(config->have_top), have_bottom(config->have_bottom)
{
}

void Cell::Draw()
{
    // front wall
    if (have_front) {
        SquareConfig* fw_config = new SquareConfig();
        fw_config->width = width;
        fw_config->depth = WALL_THICK;
        fw_config->height = height;
        Position* fw_pos = new Position();
        fw_pos->x = pos->x;
        fw_pos->y = pos->y + height / 2.;
        fw_pos->z = pos->z + depth / 2.;
        glPushMatrix();
        createSquare(fw_config, fw_pos);
        glPopMatrix();
    }
    
    // left wall
    if (have_left) {
        SquareConfig* lw_config = new SquareConfig();
        lw_config->width = depth;
        lw_config->depth = WALL_THICK;
        lw_config->height = height;
        Position* lw_pos = new Position();
        lw_pos->x = pos->x - width / 2.;
        lw_pos->y = pos->y + height / 2.;
        lw_pos->z = pos->z;
        lw_pos->y_angel = 90;
        glPushMatrix();
        createSquare(lw_config, lw_pos);
        glPopMatrix();
    }
    
    // right wall
    if (have_right) {
        SquareConfig* rw_config = new SquareConfig();
        rw_config->width = depth;
        rw_config->depth = WALL_THICK;
        rw_config->height = height;
        Position* rw_pos = new Position();
        rw_pos->x = pos->x + width / 2.;
        rw_pos->y = pos->y + height / 2.;
        rw_pos->z = pos->z;
        rw_pos->y_angel = 90;
        glPushMatrix();
        createSquare(rw_config, rw_pos);
        glPopMatrix();
    }
    
    // back
    if (have_back) {
        SquareConfig* bw_config = new SquareConfig();
        bw_config->width = width;
        bw_config->depth = WALL_THICK;
        bw_config->height = height;
        Position* bw_pos = new Position();
        bw_pos->x = pos->x;
        bw_pos->y = pos->y + height / 2.;
        bw_pos->z = pos->z - depth / 2.;
        glPushMatrix();
        createSquare(bw_config, bw_pos);
        glPopMatrix();
    }
    
    // top
    if (have_top) {
        SquareConfig* tw_config = new SquareConfig();
        tw_config->width = width;
        tw_config->depth = depth;
        tw_config->height = WALL_THICK;
        Position* tw_pos = new Position();
        tw_pos->x = pos->x;
        tw_pos->y = pos->y + height;
        tw_pos->z = pos->z;
        glPushMatrix();
        createSquare(tw_config, tw_pos);
        glPopMatrix();
    }
}

void Cell::Update( const double& deltaTime )
{
    
}

void Cell::HandleKey(int key, int state, int x, int y)
{
    
}