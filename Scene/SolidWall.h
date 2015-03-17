//
//  SolidWall.h
//  G53GRA
//
//  Created by Jason Chen on 3/16/15.
//  Copyright (c) 2015 NottinghamUniversity. All rights reserved.
//

#pragma once

#include "Environment.h"
#include "Object.h"

class SolidWall : public Object
{
public:
    SolidWall(wall::Config* config);
    ~SolidWall(){};
    
    void Draw();
    void Update( const double& deltaTime );
    void HandleKey(int key, int state, int x, int y );
    
private:
    wall::Config* config;
};
