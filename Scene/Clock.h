//
//  Clock.h
//  G53GRA
//
//  Created by Jason Chen on 3/26/15.
//  Copyright (c) 2015 NottinghamUniversity. All rights reserved.
//

#include "Environment.h"
#include "Object.h"

class Clock : public Object
{
public:
    Clock(datastruct::Position* pos);
    ~Clock(){};
    
    void Draw();
    void Update(const double& deltaTime);
    void HandleKey(int key, int state, int x, int y);
    
private:
    datastruct::Position* pos;
    datastruct::SquareConfig leg_config;
    datastruct::Position leg_pos;
    datastruct::CylinderConfig cb_config;
    datastruct::Position cb_pos;
};
