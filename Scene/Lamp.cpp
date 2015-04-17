//
//  Lamp.cpp
//  G53GRA
//
//  Created by Jason Chen on 3/27/15.
//  Copyright (c) 2015 NottinghamUniversity. All rights reserved.
//

#include "TextureManager.h"
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
    shade_config.width = LIGHT_WIDTH;
    shade_config.depth = LIGHT_DEPTH;
    shade_config.height = LIGHT_THICK;
    shade_pos.x = 0;
    shade_pos.y = leg_pos.y + leg_config.height / 2;
    shade_pos.z = 0;
}

void Lamp::Draw()
{
    GLfloat shade_color[] = { .9f, .9f, .9f, 1.f };
    GLfloat shininess[] = { 2.f };
    
    // Draw
    glPushMatrix();
    glTranslatef(pos->x, pos->y, pos->z);
    glRotatef(pos->z_angle, 0.f, 0.f, 1.f);
    glRotatef(pos->y_angle, 0.f, 1.f, 0.f);
    glRotatef(pos->x_angle, 1.f, 0.f, 0.f);
    
    glPushAttrib(GL_ALL_ATTRIB_BITS);
    glMaterialfv(GL_FRONT, GL_EMISSION, shade_color);
    createCuboid(shade_config, shade_pos);
    glPopAttrib();
    
    glPushAttrib(GL_ALL_ATTRIB_BITS);
    glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
    createCylinder(leg_config, leg_pos);
    createCuboid(bottom_config, bottom_pos);
    glPopAttrib();
    
    glPopMatrix();
}

void Lamp::Update( const double& deltaTime )
{
}

void Lamp::HandleKey(int key, int state, int x, int y)
{
    
}
