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
    Stair();
    ~Stair();
    
    void Draw();
    void Update( const double& deltaTime );
    void HandleKey(int key, int state, int x, int y );
    
private:
    struct StairConf {
        datastruct::Vertice* v;
        datastruct::Position pos;
        int diff;
        int level;
    };
    
    void buildStairBase(StairConf stair);
};

