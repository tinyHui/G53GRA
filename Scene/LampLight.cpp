//
//  LampLight.cpp
//  G53GRA
//
//  Created by Jason Chen on 3/29/15.
//  Copyright (c) 2015 NottinghamUniversity. All rights reserved.
//

#include "LampLight.h"

using namespace datastruct;

LampLight::LampLight(Position* lamp_pos) : lamp_pos(lamp_pos)
{
}


void LampLight::Draw()
{
    float y = lamp_pos->y + lamp::BOTTOM_THICK + lamp::LEG_HEIGHT + lamp::LIGHT_THICK / 2;

    float ambient[]  = { .3f, .25f, .2f, 0.2f };
    float diffuse[]  = { .2f, .3f, .4f, 0.1f };
    float specular[] = { 0.1f, 0.1f, 0.1f, 0.1f };
    float position[] = { lamp_pos->x, y, lamp_pos->z, 1.f };
    
    glLightfv(GL_LIGHT1, GL_AMBIENT, ambient);      // set ambient parameter of light source
    glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuse);      // set diffuse parameter of light source
    glLightfv(GL_LIGHT1, GL_SPECULAR, specular);    // set specular parameter of light source
    glLightfv(GL_LIGHT1, GL_POSITION, position);    // set direction vector of light source
    glEnable(GL_LIGHT1);
}


void LampLight::Update( const double& deltatime )
{
}