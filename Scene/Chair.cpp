//
//  sofa.cpp
//  G53GRA
//
//  Created by Jason Chen on 3/16/15.
//  Copyright (c) 2015 NottinghamUniversity. All rights reserved.
//

#include "Environment.h"
#include "Chair.h"

using namespace chair;

Chair::Chair(Position* pos) : pos(pos)
{
}

void Chair::Draw()
{
    // chair sit
    SquareConfig* sit_config = new SquareConfig();
    sit_config->width = WIDTH;
    sit_config->height = SIT_THICK;
    sit_config->depth = SIT_DEPTH;
    Position* sit_pos = new Position();
    sit_pos->x = 0;
    sit_pos->y = LEG_HEIGHT;
    sit_pos->z = 0;
    
    // chair back
    SquareConfig* back_config = new SquareConfig();
    back_config->width = WIDTH;
    back_config->height = BACK_THICK;
    back_config->depth = BACK_HEIGHT;
    Position* back_pos = new Position();
    back_pos->x = 0;
    back_pos->y = sit_pos->y + BACK_HEIGHT / 2. + SIT_THICK / 2. - 0.1;
    back_pos->z = - SIT_DEPTH / 2. - BACK_THICK / 2. - 0.15;
    back_pos->x_angel = 80.;
    
    // leg
    SquareConfig* leg_config = new SquareConfig();
    leg_config->width = LEG_THICK;
    leg_config->height = LEG_HEIGHT;
    leg_config->depth = LEG_THICK;
    //left top leg
    Position* lt_leg_pos = new Position();
    lt_leg_pos->x = - WIDTH / 2. + LEG_THICK / 2.;
    lt_leg_pos->y = LEG_HEIGHT / 2.;
    lt_leg_pos->z = - SIT_DEPTH / 2. + LEG_THICK / 2;
    
    //right top leg
    Position* rt_leg_pos = new Position();
    rt_leg_pos->x = WIDTH / 2. - LEG_THICK / 2.;
    rt_leg_pos->y = LEG_HEIGHT / 2.;
    rt_leg_pos->z = - SIT_DEPTH / 2. + LEG_THICK / 2;
    
    //left bottom leg
    Position* lb_leg_pos = new Position();
    lb_leg_pos->x = - WIDTH / 2. + LEG_THICK / 2.;
    lb_leg_pos->y = LEG_HEIGHT / 2.;
    lb_leg_pos->z = SIT_DEPTH / 2. - LEG_THICK / 2;
    
    //right bottom leg
    Position* rb_leg_pos = new Position();
    rb_leg_pos->x = WIDTH / 2. - LEG_THICK / 2.;
    rb_leg_pos->y = LEG_HEIGHT / 2.;
    rb_leg_pos->z = SIT_DEPTH / 2. - LEG_THICK / 2;
    
    // Draw
    glPushMatrix();
    glTranslatef(pos->x, pos->y, pos->z);
    glRotatef(pos->z_angel, 0.f, 0.f, 1.f);
    glRotatef(pos->y_angel, 0.f, 1.f, 0.f);
    glRotatef(pos->x_angel, 1.f, 0.f, 0.f);
    createSquare(sit_config, sit_pos);
    createSquare(back_config, back_pos);
    createSquare(leg_config, lt_leg_pos);
    createSquare(leg_config, rt_leg_pos);
    createSquare(leg_config, lb_leg_pos);
    createSquare(leg_config, rb_leg_pos);
    glRotatef(-pos->x_angel, 1.f, 0.f, 0.f);
    glRotatef(-pos->y_angel, 0.f, 1.f, 0.f);
    glRotatef(-pos->z_angel, 0.f, 0.f, 1.f);    
    glTranslatef(-pos->x, -pos->y, -pos->z);
    glPopMatrix();
}

void Chair::Update( const double& deltaTime )
{
    
}

void Chair::HandleKey(int key, int state, int x, int y)
{
    
}