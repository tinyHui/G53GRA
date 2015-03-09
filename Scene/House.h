//
//  House.h
//  G53GRA
//
//  Created by Jason Chen on 3/5/15.
//  Copyright (c) 2015 NottinghamUniversity. All rights reserved.
//

#pragma once

#include "Environment.h"
#include "Object.h"

class House : public Object
{
public:
    House(datastruct::HouseConfig* config);
    ~House();
    
    void Draw();
    void Update( const double& deltaTime );
    void HandleKey(int key, int state, int x, int y );
    
private:
    datastruct::HouseConfig* config;
    
};