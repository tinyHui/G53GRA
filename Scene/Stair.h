//
//  Stair.h
//  G53GRA
//
//  Created by Jason Chen on 3/2/15.
//  Copyright (c) 2015 NottinghamUniversity. All rights reserved.
//

#pragma once

#include "Object.h"

class Stair : public Object
{
public:
    Stair();
    ~Stair();
    
    void Draw();
    void Update( const double& deltaTime );
    void HandleKey(int key, int state, int x, int y );
    
private:
    struct StairConf {
        int level;
        int x;
        int z;
        int width;
        int depth;
        int diff_w;
        int diff_d;
    };
    
    float xrot, yrot, zrot;
    float scale;
    
    void buildStair(StairConf stair);
};

