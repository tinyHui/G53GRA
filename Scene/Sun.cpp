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
}


void Sun::Update( const double& deltatime )
{
    // light
    GLfloat light_ambient[] = { .3f, .3f, .3f, .3f };
    GLfloat light_diffuse[] = { .3f, .3f, .3f, .3f };
    GLfloat light_specular[] = { 1.f, 1.f, 1.f, 1.f };
    GLfloat light_position[] = { 0, 0, 0, 0 };

    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);      // set ambient parameter of light source
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);      // set diffuse parameter of light source
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);    // set specular parameter of light source
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);    // set direction vector of light source
    glEnable(GL_LIGHT0);
}