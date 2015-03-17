//
//  SolidWall.cpp
//  G53GRA
//
//  Created by Jason Chen on 3/16/15.
//  Copyright (c) 2015 NottinghamUniversity. All rights reserved.
//

#include "Environment.h"
#include "SolidWall.h"


using namespace wall;

SolidWall::SolidWall(Config* config) : config(config)
{
}

void SolidWall::Draw()
{
    SquareConfig* wall_config = new SquareConfig();
    wall_config->width = config->width;
    wall_config->depth = config->depth;
    wall_config->height = config->height;
    Position* wall_pos = new Position();
    wall_pos->x = config->pos.x;
    wall_pos->y = config->pos.y;
    wall_pos->z = config->pos.z + config->height / 2;
    
    glPushMatrix();

    createSquare(wall_config, wall_pos);

    glPopMatrix();
}

void SolidWall::Update( const double& deltaTime )
{
    
}

void SolidWall::HandleKey(int key, int state, int x, int y)
{
    
}