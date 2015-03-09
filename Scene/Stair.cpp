//
//  Stair.cpp
//  G53GRA
//
//  Created by Jason Chen on 3/2/15.
//  Copyright (c) 2015 NottinghamUniversity. All rights reserved.
//

#include "Environment.h"
#include "Stair.h"
#include "Block.h"

using namespace datastruct;
using namespace globalconf;

Stair::Stair(StairConfig* conf) : config(conf)
{
}

Stair::~Stair()
{
}

void Stair::Draw()
{
    StairConfig* stair_config = config;
    float y = stair_config->base_pos.y + ST_HEIGHT_PL / 2.;
    Position pos = { stair_config->base_pos.x, y, stair_config->base_pos.z };
    
    float width_diff_rate = stair_config->diff / stair_config->width;
    float deepth_diff_rate = stair_config->diff / stair_config->deepth;
    
    for (int l = 0; l < stair_config->level; l++) {
        glPushMatrix();
        glScalef( 1.0 - l * width_diff_rate, 1.0, 1.0 - l * deepth_diff_rate);
        Block::createPrism(stair_config->v, pos, ST_HEIGHT_PL);
        glPopMatrix();
        pos.y += ST_HEIGHT_PL;
    }
}


void Stair::Update(const double& delta_time)
{
}

void Stair::HandleKey(int key, int state, int x, int y)
{
}

float* Stair::getTopY()
{
    float* top_y = new float();
    *top_y = config->base_pos.y + config->level * ST_HEIGHT_PL;
    return top_y;
}