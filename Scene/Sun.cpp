//
//  Sun.cpp
//  G53GRA
//
//  Created by Jason Chen on 3/27/15.
//  Copyright (c) 2015 NottinghamUniversity. All rights reserved.
//

#include "Environment.h"
#include "Sun.h"

using namespace datastruct;

Sun::Sun()
{
}


void Sun::Draw()
{
    float ambient[]  = { .1f, .1f, .1f, 0.1f };
    float diffuse[]  = { 0.1f, 0.1f, 0.1f, 0.1f };
    float specular[] = { 0.01f, 0.01f, 0.01f, 0.01f };
    float position[] = { 300, 300, 500, 0.f };
    
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);      // set ambient parameter of light source
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);      // set diffuse parameter of light source
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular);    // set specular parameter of light source
    glLightfv(GL_LIGHT0, GL_POSITION, position);    // set direction vector of light source
    glEnable(GL_LIGHT0);
}


void Sun::Update( const double& deltatime )
{
}