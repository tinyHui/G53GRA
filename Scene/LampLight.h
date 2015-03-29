//
//  LampLight.h
//  G53GRA
//
//  Created by Jason Chen on 3/29/15.
//  Copyright (c) 2015 NottinghamUniversity. All rights reserved.
//

#pragma once

#include "Environment.h"
#include "Object.h"

class LampLight : public Object
{
public:
    LampLight(datastruct::Position* lamp_pos);
    ~LampLight(){};
    
    void Draw();
    void Update( const double& deltatime );

private:
    datastruct::Position* lamp_pos;
};
