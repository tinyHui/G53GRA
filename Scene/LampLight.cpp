//
//  LampLight.cpp
//  G53GRA
//
//  Created by Jason Chen on 3/29/15.
//  Copyright (c) 2015 NottinghamUniversity. All rights reserved.
//

#include "LampLight.h"

using namespace datastruct;

LampLight::LampLight(Position* pos)
{
    light_position[0] = pos->x;
    light_position[1] = pos->y;
    light_position[2] = pos->z;
    light_position[3] = 1;
}


void LampLight::Draw()
{
}


void LampLight::Update( const double& deltaTime )
{
    GLfloat light_ambient[] = { .2f, .18f, .1f, .2f };
    GLfloat light_diffuse[] = { .3f, .2f, .1f, .1f };
    GLfloat light_specular[] = { .1f, .1f, .1f, .1f };
    
    glLightfv(GL_LIGHT1, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT1, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT1, GL_POSITION, light_position);
    glLightf(GL_LIGHT1, GL_LINEAR_ATTENUATION, 0.001);
    glEnable(GL_LIGHT1);
}