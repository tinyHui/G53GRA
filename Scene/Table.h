//
//  Chair.h
//  G53GRA
//
//  Created by Jason Chen on 3/16/15.
//  Copyright (c) 2015 NottinghamUniversity. All rights reserved.
//

#include "Environment.h"
#include "Object.h"

class Table : public Object
{
public:
    Table(datastruct::Position* pos);
    Table(){};
    
    void Draw();
    void Update(const double& deltaTime);
    void HandleKey(int key, int state, int x, int y);
    
private:
    datastruct::Position* pos;

    datastruct::CuboidConfig bottom_config;
    datastruct::Position bottom_pos;
    datastruct::CylinderConfig leg_config;
    datastruct::Position leg_pos;
    datastruct::CylinderConfig face_config;
    datastruct::Position face_pos;
};
