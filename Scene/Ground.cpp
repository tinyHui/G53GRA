//
//  Ground.cpp
//  G53GRA
//
//  Created by Jason Chen on 2/23/15.
//  Copyright (c) 2015 NottinghamUniversity. All rights reserved.
//

#include "Environment.h"
#include "Ground.h"
#include "Block.h"


Ground::Ground() : xrot(0.0f), yrot(0.0f), zrot(0.0f), scale(1)
{
}

Ground::~Ground()
{
}

void Ground::Draw()
{
    int width = Enviornment::ENV_WIDTH;
    int depth = Enviornment::ENV_DEPTH;
    
    glColor3f(0.f, 0.f, 0.f);
    
    Block::create(0, 0, 0, width, 0, depth);
    
    // reset
    glColor3f(0.f, 0.f, 0.f);
}

void Ground::Update(const double& delta_time)
{
}

void Ground::HandleKey(int key, int state, int x, int y)
{
}