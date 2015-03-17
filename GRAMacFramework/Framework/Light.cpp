//
//  Light.cpp
//  G53GRA
//
//  Created by Jason Chen on 3/16/15.
//  Copyright (c) 2015 NottinghamUniversity. All rights reserved.
//

#include "Light.h"

Light::Light()
{
    position[0] = 0.0;
    position[1] = 0.0;
    position[2] = -20.0;
    
    ambient[0] = 0.15;  // Set ambient colour of the light
    ambient[1] = 0.15;
    ambient[2] = 0.1;
    ambient[3] = 1.0;
    
    diffuse[0] = 0.8;   // Set diffuse colour of the light
    diffuse[1] = 0.0;
    diffuse[2] = 0.0;
    diffuse[3] = 1.0;
    
    specular[0] = 1.0;  // Set specular colour of the light
    specular[1] = 1.0;
    specular[2] = 1.0;
    specular[3] = 1.0;
}


void Light::Draw()
{
    glEnable(GL_LIGHTING);
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
    glLightfv(GL_LIGHT0, GL_POSITION, position);
}


void Light::Update( const double& deltatime )
{
}
