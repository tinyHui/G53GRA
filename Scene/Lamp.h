//
//  Lamp.h
//  G53GRA
//
//  Created by Jason Chen on 3/27/15.
//  Copyright (c) 2015 NottinghamUniversity. All rights reserved.
//

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

    datastruct::SquareConfig bottom_config;
    datastruct::Position bottom_pos;
    datastruct::CylinderConfig leg_config;
    datastruct::Position leg_pos;
    datastruct::SquareConfig light_config;
    datastruct::Position light_pos;
    
    float position[4], ambient[4], diffuse[4], specular[4];
};

