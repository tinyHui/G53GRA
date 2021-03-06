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
    GLfloat face_ambient[] = { 1.f, .6588f, .6844f, 1.f };     // Define the ambient material colour property K_a
    GLfloat face_diffuse[] = { 1.f, .6588f, .6844f, 1.f };     // Define the diffuse material colour property K_d
    GLfloat face_specular[] = { .2f, .2f, .2f, 1.f };    // Define the specular material colour property K_s
    GLfloat face_shininess[] = { 0. };
    
    GLfloat leg_ambient[] = { 0.3f, 0.3f, 0.3f, 1.f };     // Define the ambient material colour property K_a
    GLfloat leg_diffuse[] = { 0.3f, 0.3f, 0.3f, 1.f };     // Define the diffuse material colour property K_d
    GLfloat leg_specular[] = { .2f, .2f, .2f, 1.f };    // Define the specular material colour property K_s
    GLfloat leg_shininess[] = { 0. };
    
    glDisable(GL_COLOR_MATERIAL);
    // Draw
    glPushMatrix();
    glTranslatef(pos->x, pos->y, pos->z);
    glRotatef(pos->z_angle, 0.f, 0.f, 1.f);
    glRotatef(pos->y_angle, 0.f, 1.f, 0.f);
    glRotatef(pos->x_angle, 1.f, 0.f, 0.f);
    
    glPushAttrib(GL_LIGHTING);
    glMaterialfv(GL_FRONT, GL_AMBIENT, face_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, face_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, face_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, face_shininess);
    createCuboid(back_config, back_pos);
    createCuboid(sit_config, sit_pos);
    glPopAttrib();

    glPushAttrib(GL_LIGHTING);
    glMaterialfv(GL_FRONT, GL_AMBIENT, leg_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, leg_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, leg_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, leg_shininess);
    createCuboid(leg_config, lt_leg_pos);
    createCuboid(leg_config, rt_leg_pos);
    createCuboid(leg_config, lb_leg_pos);
    createCuboid(leg_config, rb_leg_pos);
    glPopAttrib();
    
    glPopMatrix();
    glDisable(GL_COLOR_MATERIAL);
}

void Chair::Update( const double& deltaTime )
{
    
}

void Chair::HandleKey(int key, int state, int x, int y)
{
    
}