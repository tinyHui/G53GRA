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

    float ambient[]  = { .5f, .3f, .2f, 0.2f };      // ambient light (20% white)
    float diffuse[]  = { .5f, .6f, .5f, 0.1f };      // diffuse light (50% white)
    float specular[] = { 0.1f, 0.1f, 0.1f, 0.1f };      // specular light (100% white)
    float position[] = { lamp_pos->x, y, lamp_pos->z, 1.f };      // directional light (w = 0)
    
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);      // set ambient parameter of light source
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);      // set diffuse parameter of light source
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular);    // set specular parameter of light source
    glLightfv(GL_LIGHT0, GL_POSITION, position);    // set direction vector of light source
    glEnable(GL_LIGHT0);
}


void LampLight::Update( const double& deltatime )
{
}