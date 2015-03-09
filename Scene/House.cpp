//
//  House.cpp
//  G53GRA
//
//  Created by Jason Chen on 3/5/15.
//  Copyright (c) 2015 NottinghamUniversity. All rights reserved.
//

#include "Environment.h"
#include "House.h"
#include "Block.h"

using namespace datastruct;
using namespace globalconf;

House::House(HouseConfig* config) : config(config)
{
}

House::~House()
{
}

void House::Draw()
{
    // draw bottom body
    float btm_body_width = config->btm_body_width;
    float btm_body_deepth = config->btm_body_deepth;
    float btm_body_height = config->btm_body_height;
    Position btm_body_pos = { config->base_pos.x, config->base_pos.y + btm_body_height / 2, config->base_pos.z };
    Block::createSquare(btm_body_pos, btm_body_width, btm_body_height, btm_body_deepth);
    
    // draw top body
    float top_body_width = config->top_body_width;
    float top_body_deepth = config->top_body_deepth;
    float top_body_height = config->top_body_height;
    Position top_body_pos = { config->base_pos.x, btm_body_pos.y + btm_body_height / 2 + top_body_height / 2, config->base_pos.z };
    Block::createSquare(top_body_pos, top_body_width, top_body_height, top_body_deepth);
}

void House::Update(const double& delta_time)
{
}

void House::HandleKey(int key, int state, int x, int y)
{
}