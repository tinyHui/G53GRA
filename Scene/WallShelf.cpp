//
//  ShelfOnWall.cpp
//  G53GRA
//
//  Created by Jason Chen on 3/25/15.
//  Copyright (c) 2015 NottinghamUniversity. All rights reserved.
//

#include "Environment.h"
#include "WallShelf.h"

using namespace wall_shelf;

WallShelf::WallShelf(SquareShelf* config, Position* pos)
                : config(config), pos(pos)
{
}

void WallShelf::Draw()
{
    SquareConfig* shelf_config = new SquareConfig();
    shelf_config->width = config->width;
    shelf_config->height = THICK;
    shelf_config->depth = config->depth;
    Position* shelf_pos = new Position();
    shelf_pos->x = 0;
    shelf_pos->y = 0;
    shelf_pos->z = 0;
    
    glPushMatrix();
    glTranslatef(pos->x, pos->y, pos->z);
    glRotatef(pos->z_angel, 0.f, 0.f, 1.f);
    glRotatef(pos->y_angel, 0.f, 1.f, 0.f);
    glRotatef(pos->x_angel, 1.f, 0.f, 0.f);
    createSquare(shelf_config, shelf_pos);
    glRotatef(-pos->x_angel, 1.f, 0.f, 0.f);
    glRotatef(-pos->y_angel, 0.f, 1.f, 0.f);
    glRotatef(-pos->z_angel, 0.f, 0.f, 1.f);
    glTranslatef(-pos->x, -pos->y, -pos->z);
    glPopMatrix();
}

void WallShelf::Update( const double& deltaTime )
{
    
}

void WallShelf::HandleKey(int key, int state, int x, int y)
{
    
}
