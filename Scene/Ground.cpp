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

using namespace globalconf;

Ground::Ground()
{
}

Ground::~Ground()
{
}

void Ground::Draw()
{
    glColor3f(0.f, 0.f, 0.f);
    
    Block::createSquare({ 0, 0, 0 }, ENV.width, 0, ENV.depth);
    
    // reset
    glColor3f(0.f, 0.f, 0.f);
}

void Ground::Update(const double& delta_time)
{
}

void Ground::HandleKey(int key, int state, int x, int y)
{
}