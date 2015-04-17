//
//  Lamp.h
//  G53GRA
//
//  Created by Jason Chen on 3/27/15.
//  Copyright (c) 2015 NottinghamUniversity. All rights reserved.
//

#include "TextureManager.h"
#include "Environment.h"
#include "Object.h"

class Lamp : public Object
{
public:
    Lamp(datastruct::Position* pos);
    ~Lamp(){};
    
    void Draw();
    void Update(const double& deltaTime);
    void HandleKey(int key, int state, int x, int y);
    
private:
    datastruct::Position* pos;
    datastruct::CuboidConfig bottom_config;
    datastruct::Position bottom_pos;
    datastruct::CylinderConfig leg_config;
    datastruct::Position leg_pos;
    datastruct::CuboidConfig shade_config;
    datastruct::Position shade_pos;
};

