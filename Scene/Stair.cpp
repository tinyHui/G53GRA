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

Stair::Stair() : xrot(0.0f), yrot(0.0f), zrot(0.0f), scale(1)
{
}

Stair::~Stair()
{
}

void Stair::Draw()
{
    // main stair config
    StairConf main_stair;
    main_stair.level = 3;
    main_stair.x = 0;
    main_stair.z = 100;
    main_stair.width = 600;
    main_stair.depth = 600;
    main_stair.diff_w = 100;
    main_stair.diff_d = 100;
    
    glColor3f(0.f, 0.f, 0.f);
    
    // build main stair
    buildStair(main_stair);
}

void Stair::buildStair(StairConf stair)
{
    for (int l = 0; l < stair.level; l++) {
        int y = Enviornment::ST_HEIGHT_PL / 2 + l * Enviornment::ST_HEIGHT_PL;
        int w = stair.width - l * stair.diff_w;
        int d = stair.depth - l * stair.diff_d;
        
        Block::create(stair.x, y, stair.z, w, Enviornment::ST_HEIGHT_PL, d);
    }
}




void Stair::Update(const double& delta_time)
{
}

void Stair::HandleKey(int key, int state, int x, int y)
{
}