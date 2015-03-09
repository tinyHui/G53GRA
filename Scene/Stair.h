//
//  Stair.h
//  G53GRA
//
//  Created by Jason Chen on 3/2/15.
//  Copyright (c) 2015 NottinghamUniversity. All rights reserved.
//

#pragma once

#include "Environment.h"
#include "Object.h"

class Stair : public Object
{
public:
    Stair(datastruct::StairConfig* config);
    ~Stair();
    
    void Draw();
    void Update( const double& deltaTime );
    void HandleKey(int key, int state, int x, int y );
    
    float* getTopY();
    
private:
    datastruct::StairConfig* config;
};

