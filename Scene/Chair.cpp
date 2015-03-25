//
//  Chair.cpp
//  G53GRA
//
//  Created by Jason Chen on 3/16/15.
//  Copyright (c) 2015 NottinghamUniversity. All rights reserved.
//

#include "Environment.h"
#include "Chair.h"


using namespace chair;

Chair::Chair(Position* chair_pos) : chair_pos(chair_pos)
{
}

void Chair::Draw()
{
    Color* main_color = new Color();
    main_color->r = 75;
    main_color->g = 52;
    main_color->b = 0;
    Config* chair = new Config();
    
    // chair flat
    SquareConfig* sit_config = new SquareConfig();
    sit_config->width = chair->width;
    sit_config->height = chair->sit_thick;
    sit_config->depth = chair->sit_depth;
    sit_config->color = *main_color;
    Position* sit_pos = new Position();
    sit_pos->x = 0;
    sit_pos->y = chair->leg_height;
    sit_pos->z = 0;
    
    // chair back
    SquareConfig* back_config = new SquareConfig();
    back_config->width = chair->width;
    back_config->height = chair->back_thick;
    back_config->depth = chair->back_height;
    back_config->color = *main_color;
    Position* back_pos = new Position();
    back_pos->x = 0;
    back_pos->y = sit_pos->y + chair->back_height / 2. + chair->sit_thick / 2. - 0.1;
    back_pos->z = - chair->sit_depth / 2. - chair->back_thick / 2. - 0.15;
    back_pos->x_angel = 80.;
    
    // leg
    SquareConfig* leg_config = new SquareConfig();
    leg_config->width = chair->leg_thick;
    leg_config->height = chair->leg_height;
    leg_config->depth = chair->leg_thick;
    leg_config->color = *main_color;
    //left top leg
    Position* lt_leg_pos = new Position();
    lt_leg_pos->x = - chair->width / 2. + chair->leg_thick / 2.;
    lt_leg_pos->y = chair->leg_height / 2.;
    lt_leg_pos->z = - chair->sit_depth / 2. + chair->leg_thick / 2;
    
    //right top leg
    Position* rt_leg_pos = new Position();
    rt_leg_pos->x = chair->width / 2. - chair->leg_thick / 2.;
    rt_leg_pos->y = chair->leg_height / 2.;
    rt_leg_pos->z = - chair->sit_depth / 2. + chair->leg_thick / 2;
    
    //left bottom leg
    Position* lb_leg_pos = new Position();
    lb_leg_pos->x = - chair->width / 2. + chair->leg_thick / 2.;
    lb_leg_pos->y = chair->leg_height / 2.;
    lb_leg_pos->z = chair->sit_depth / 2. - chair->leg_thick / 2;
    
    //right bottom leg
    Position* rb_leg_pos = new Position();
    rb_leg_pos->x = chair->width / 2. - chair->leg_thick / 2.;
    rb_leg_pos->y = chair->leg_height / 2.;
    rb_leg_pos->z = chair->sit_depth / 2. - chair->leg_thick / 2;
    
    // Draw
    glPushMatrix();
    glTranslatef(chair_pos->x, chair_pos->y, chair_pos->z);
    glRotatef(chair_pos->x_angel, 1.f, 0.f, 0.f);
    glRotatef(chair_pos->y_angel, 0.f, 1.f, 0.f);
    glRotatef(chair_pos->z_angel, 0.f, 0.f, 1.f);
    createSquare(sit_config, sit_pos);
    createSquare(back_config, back_pos);
    createSquare(leg_config, lt_leg_pos);
    createSquare(leg_config, rt_leg_pos);
    createSquare(leg_config, lb_leg_pos);
    createSquare(leg_config, rb_leg_pos);
    glRotatef(-chair_pos->z_angel, 0.f, 0.f, 1.f);
    glRotatef(-chair_pos->y_angel, 0.f, 1.f, 0.f);
    glRotatef(-chair_pos->x_angel, 1.f, 0.f, 0.f);
    glTranslatef(-chair_pos->x, -chair_pos->y, -chair_pos->z);
    glPopMatrix();
}

void Chair::Update( const double& deltaTime )
{
    
}

void Chair::HandleKey(int key, int state, int x, int y)
{
    
}