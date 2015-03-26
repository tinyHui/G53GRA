//
//  Clock.cpp
//  G53GRA
//
//  Created by Jason Chen on 3/26/15.
//  Copyright (c) 2015 NottinghamUniversity. All rights reserved.
//

#include "Environment.h"
#include "Clock.h"

using namespace time_clock;

Clock::Clock(datastruct::Position* pos) : pos(pos)
{
}

void Clock::Draw()
{
    // clock base
    CylinderConfig* cb_config = new CylinderConfig();
    cb_config->top_r = R;
    cb_config->bottom_r = R;
    cb_config->height = BASE_THICK;
    Position* cb_pos = new Position();
    cb_pos->x = 0;
    cb_pos->y = 0;
    cb_pos->z = 0;
    
    glPushMatrix();
    glTranslatef(pos->x, pos->y, pos->z);
    glRotatef(pos->z_angel, 0.f, 0.f, 1.f);
    glRotatef(pos->y_angel, 0.f, 1.f, 0.f);
    glRotatef(pos->x_angel, 1.f, 0.f, 0.f);
    createCylinder(cb_config, cb_pos);
    glRotatef(-pos->x_angel, 1.f, 0.f, 0.f);
    glRotatef(-pos->y_angel, 0.f, 1.f, 0.f);
    glRotatef(-pos->z_angel, 0.f, 0.f, 1.f);
    glTranslatef(-pos->x, -pos->y, -pos->z);
    glPopMatrix();
}

void Clock::Update(const double& deltaTime)
{
    
}

void Clock::HandleKey(int key, int state, int x, int y)
{
    
}
