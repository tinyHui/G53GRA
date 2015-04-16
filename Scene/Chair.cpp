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
    // chair sit
    sit_config.width = WIDTH;
    sit_config.height = SIT_THICK;
    sit_config.depth = SIT_DEPTH;
    sit_pos.x = 0;
    sit_pos.y = LEG_HEIGHT;
    sit_pos.z = 0;
    
    // chair back
    back_config.width = WIDTH;
    back_config.height = BACK_HEIGHT;
    back_config.depth = BACK_THICK;
    back_pos.x = 0;
    back_pos.y = sit_pos.y + BACK_HEIGHT / 2;
    back_pos.z = - SIT_DEPTH / 2 + SIT_THICK / 2.;
    back_pos.y_piv = - BACK_HEIGHT / 2;
    back_pos.x_angle = -10.;
    
    // leg
    leg_config.width = LEG_THICK;
    leg_config.height = LEG_HEIGHT;
    leg_config.depth = LEG_THICK;
    // left top leg
    lt_leg_pos.x = - WIDTH / 2. + LEG_THICK / 2.;
    lt_leg_pos.y = LEG_HEIGHT / 2.;
    lt_leg_pos.z = - SIT_DEPTH / 2. + LEG_THICK / 2;
    
    // right top leg
    rt_leg_pos.x = WIDTH / 2. - LEG_THICK / 2.;
    rt_leg_pos.y = LEG_HEIGHT / 2.;
    rt_leg_pos.z = - SIT_DEPTH / 2. + LEG_THICK / 2;
    
    // left bottom leg
    lb_leg_pos.x = - WIDTH / 2. + LEG_THICK / 2.;
    lb_leg_pos.y = LEG_HEIGHT / 2.;
    lb_leg_pos.z = SIT_DEPTH / 2. - LEG_THICK / 2;
    
    // right bottom leg
    rb_leg_pos.x = WIDTH / 2. - LEG_THICK / 2.;
    rb_leg_pos.y = LEG_HEIGHT / 2.;
    rb_leg_pos.z = SIT_DEPTH / 2. - LEG_THICK / 2;
}

void Chair::Draw()
{    
    // Draw
    glPushMatrix();
    glTranslatef(pos->x, pos->y, pos->z);
    glRotatef(pos->z_angle, 0.f, 0.f, 1.f);
    glRotatef(pos->y_angle, 0.f, 1.f, 0.f);
    glRotatef(pos->x_angle, 1.f, 0.f, 0.f);
    glPushAttrib(GL_ALL_ATTRIB_BITS);
    glColor3f(1.f, .6588f, .6844f);
    createSquare(back_config, back_pos);
    createSquare(sit_config, sit_pos);
    glColor3f(.3f, .3f, .3f);
    createSquare(leg_config, lt_leg_pos);
    createSquare(leg_config, rt_leg_pos);
    createSquare(leg_config, lb_leg_pos);
    createSquare(leg_config, rb_leg_pos);
    glPopAttrib();
    glPopMatrix();
}

void Chair::Update( const double& deltaTime )
{
    
}

void Chair::HandleKey(int key, int state, int x, int y)
{
    
}