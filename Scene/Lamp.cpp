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
    // lamp bottom
    bottom_config.width = BOTTOM_WIDTH;
    bottom_config.height = BOTTOM_THICK;
    bottom_config.depth = BOTTOM_DEPTH;
    bottom_pos.x = 0;
    bottom_pos.y = BOTTOM_THICK / 2;
    bottom_pos.z = 0;
    
    // lamp leg
    leg_config.top_r = LEG_R;
    leg_config.bottom_r = LEG_R;
    leg_config.height = LEG_HEIGHT;
    leg_pos.x = 0;
    leg_pos.y = bottom_pos.y + LEG_HEIGHT / 2;
    leg_pos.z = 0;
    
    // lamp light
    light_config.width = LIGHT_WIDTH;
    light_config.depth = LIGHT_DEPTH;
    light_config.height = LIGHT_THICK;
    light_pos.x = 0;
    light_pos.y = leg_pos.y + leg_config.height / 2;
    light_pos.z = 0;
    
    ambient[0] = .3f;
    ambient[1] = .25f;
    ambient[2] = .2f;
    ambient[3] = .2f;
    
    diffuse[0] = .2f;
    diffuse[1] = .3f;
    diffuse[1] = .4f;
    diffuse[1] = .1f;

    specular[0] = .1f;
    specular[1] = .1f;
    specular[2] = .1f;
    specular[3] = .1f;

    position[0] = light_pos.x;
    position[1] = light_pos.y;
    position[2] = light_pos.z;
    position[3] = 1.f;
}

void Lamp::Draw()
{
    GLfloat light_color[] = { 1.f, 0.8f, 0.56f, 1.f };
    GLfloat shininess[] = { 3.f };
    
    // Draw
    glPushMatrix();
    glTranslatef(pos->x, pos->y, pos->z);
    glRotatef(pos->z_angle, 0.f, 0.f, 1.f);
    glRotatef(pos->y_angle, 0.f, 1.f, 0.f);
    glRotatef(pos->x_angle, 1.f, 0.f, 0.f);
    
    glPushAttrib(GL_ALL_ATTRIB_BITS);
    glMaterialfv(GL_FRONT, GL_EMISSION, light_color);
    createSquare(light_config, light_pos);
    glPopAttrib();
    
    glPushAttrib(GL_ALL_ATTRIB_BITS);
    glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
    createCylinder(leg_config, leg_pos);
    createSquare(bottom_config, bottom_pos);
    glPopAttrib();
    
    glPopMatrix();
    
    glLightfv(GL_LIGHT1, GL_AMBIENT, ambient);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuse);
    glLightfv(GL_LIGHT1, GL_SPECULAR, specular);
    glLightfv(GL_LIGHT1, GL_POSITION, position);
    glEnable(GL_LIGHT1);
}

void Lamp::Update( const double& deltaTime )
{
}

void Lamp::HandleKey(int key, int state, int x, int y)
{
    
}
