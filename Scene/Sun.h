//
//  Sun.h
//  G53GRA
//
//  Created by Jason Chen on 3/27/15.
//  Copyright (c) 2015 NottinghamUniversity. All rights reserved.
//

#pragma once

#include "Object.h"

class Sun : public Object
{
public:
    Sun();
    ~Sun(){};
    
    void Draw();
    void Update( const double& deltatime );
};