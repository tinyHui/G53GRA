//
//  sofa.cpp
//  G53GRA
//
//  Created by Jason Chen on 3/16/15.
//  Copyright (c) 2015 NottinghamUniversity. All rights reserved.
//

#include "Environment.h"
#include "Sofa.h"

using namespace sofa;

Sofa::Sofa(Position* pos) : pos(pos)
{
}

void Sofa::Draw()
{
    Config* sofa = new Config();
    
    // sofa flat
    SquareConfig* sit_config = new SquareConfig();
    sit_config->width = sofa->width;
    sit_config->height = sofa->sit_thick;
    sit_config->depth = sofa->sit_depth;
    Position* sit_pos = new Position();
    sit_pos->x = 0;
    sit_pos->y = sofa->leg_height;
    sit_pos->z = 0;
    
    // sofa back
    SquareConfig* back_config = new SquareConfig();
    back_config->width = sofa->width;
    back_config->height = sofa->back_thick;
    back_config->depth = sofa->back_height;
    Position* back_pos = new Position();
    back_pos->x = 0;
    back_pos->y = sit_pos->y + sofa->back_height / 2. + sofa->sit_thick / 2. - 0.1;
    back_pos->z = - sofa->sit_depth / 2. - sofa->back_thick / 2. - 0.15;
    back_pos->x_angel = 80.;
    
    // leg
    SquareConfig* leg_config = new SquareConfig();
    leg_config->width = sofa->leg_thick;
    leg_config->height = sofa->leg_height;
    leg_config->depth = sofa->leg_thick;
    //left top leg
    Position* lt_leg_pos = new Position();
    lt_leg_pos->x = - sofa->width / 2. + sofa->leg_thick / 2.;
    lt_leg_pos->y = sofa->leg_height / 2.;
    lt_leg_pos->z = - sofa->sit_depth / 2. + sofa->leg_thick / 2;
    
    //right top leg
    Position* rt_leg_pos = new Position();
    rt_leg_pos->x = sofa->width / 2. - sofa->leg_thick / 2.;
    rt_leg_pos->y = sofa->leg_height / 2.;
    rt_leg_pos->z = - sofa->sit_depth / 2. + sofa->leg_thick / 2;
    
    //left bottom leg
    Position* lb_leg_pos = new Position();
    lb_leg_pos->x = - sofa->width / 2. + sofa->leg_thick / 2.;
    lb_leg_pos->y = sofa->leg_height / 2.;
    lb_leg_pos->z = sofa->sit_depth / 2. - sofa->leg_thick / 2;
    
    //right bottom leg
    Position* rb_leg_pos = new Position();
    rb_leg_pos->x = sofa->width / 2. - sofa->leg_thick / 2.;
    rb_leg_pos->y = sofa->leg_height / 2.;
    rb_leg_pos->z = sofa->sit_depth / 2. - sofa->leg_thick / 2;
    
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

void Sofa::Update( const double& deltaTime )
{
    
}

void Sofa::HandleKey(int key, int state, int x, int y)
{
    
}