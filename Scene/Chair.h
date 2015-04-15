//
//  Chair.h
//  G53GRA
//
//  Created by Jason Chen on 3/16/15.
//  Copyright (c) 2015 NottinghamUniversity. All rights reserved.
//

#include "Environment.h"
#include "Object.h"

class Chair : public Object
{
public:
    Chair(datastruct::Position* pos);
    ~Chair(){};
    
    void Draw();
    void Update(const double& deltaTime);
    void HandleKey(int key, int state, int x, int y);
    
private:
    datastruct::Position* pos;
    datastruct::SquareConfig sit_config;
    datastruct::Position sit_pos;
    datastruct::SquareConfig back_config;
    datastruct::Position back_pos;
    datastruct::SquareConfig leg_config;
    datastruct::Position lt_leg_pos;
    datastruct::Position rt_leg_pos;
    datastruct::Position lb_leg_pos;
    datastruct::Position rb_leg_pos;
};
