//
//  Lamp.cpp
//  G53GRA
//
//  Created by Jason Chen on 3/27/15.
//  Copyright (c) 2015 NottinghamUniversity. All rights reserved.
//

#include "Environment.h"
#include "Lamp.h"

using namespace lamp;

Lamp::Lamp(Position* pos) : pos(pos)
{
}

void Lamp::Draw()
{
    // lamp bottom
    SquareConfig* bottom_config = new SquareConfig();
    bottom_config->width = BOTTOM_WIDTH;
    bottom_config->height = BOTTOM_THICK;
    bottom_config->depth = BOTTOM_DEPTH;
    Position* bottom_pos = new Position();
    bottom_pos->x = 0;
    bottom_pos->y = BOTTOM_THICK / 2;
    bottom_pos->z = 0;
    
    // lamp leg
    CylinderConfig* leg_config = new CylinderConfig();
    leg_config->top_r = LEG_R;
    leg_config->bottom_r = LEG_R;
    leg_config->height = LEG_HEIGHT;
    Position* leg_pos = new Position();
    leg_pos->x = 0;
    leg_pos->y = bottom_pos->y + LEG_HEIGHT / 2;
    leg_pos->z = 0;
    
    // lamp face
    SquareConfig* light_config = new SquareConfig();
    light_config->width = LIGHT_WIDTH;
    light_config->depth = LIGHT_DEPTH;
    light_config->height = LIGHT_THICK;
    Position* light_pos = new Position();
    light_pos->x = 0;
    light_pos->y = leg_pos->y + leg_config->height / 2;
    light_pos->z = 0;
    
    // Draw
    glPushMatrix();
    glTranslatef(pos->x, pos->y, pos->z);
    glRotatef(pos->z_angel, 0.f, 0.f, 1.f);
    glRotatef(pos->y_angel, 0.f, 1.f, 0.f);
    glRotatef(pos->x_angel, 1.f, 0.f, 0.f);
    glColor3f(1.f, 0.9647f, 0.7135f);
    createSquare(light_config, light_pos);
    glColor3f(0.94f, 0.94f, 0.94f);
    createCylinder(leg_config, leg_pos);
    createSquare(bottom_config, bottom_pos);
    glRotatef(-pos->x_angel, 1.f, 0.f, 0.f);
    glRotatef(-pos->y_angel, 0.f, 1.f, 0.f);
    glRotatef(-pos->z_angel, 0.f, 0.f, 1.f);
    glTranslatef(-pos->x, -pos->y, -pos->z);
    glPopMatrix();
}

void Lamp::Update( const double& deltaTime )
{
    
}

void Lamp::HandleKey(int key, int state, int x, int y)
{
    
}
