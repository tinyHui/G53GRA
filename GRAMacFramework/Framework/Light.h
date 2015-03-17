//
//  Light.h
//  G53GRA
//
//  Created by Jason Chen on 3/16/15.
//  Copyright (c) 2015 NottinghamUniversity. All rights reserved.
//

#pragma once

#include "Object.h"

class Camera;

class Light : public Object
{
public:
    Light();
    ~Light(){};
    
    void Draw();
    void Update( const double& deltatime );
    
private:
    float position[3], ambient[4], diffuse[4], specular[4];
};
