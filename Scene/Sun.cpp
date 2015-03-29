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
    float ambient[]  = { .18f, .18f, .155f, 0.1f };
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambient);
}


void Sun::Update( const double& deltatime )
{
}