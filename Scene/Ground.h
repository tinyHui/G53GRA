//
//  Ground.h
//  G53GRA
//
//  Created by Jason Chen on 2/23/15.
//  Copyright (c) 2015 NottinghamUniversity. All rights reserved.
//

#pragma once

#include "Object.h"

class Ground : public Object
{
public:
    Ground();
    ~Ground();
    
    void Draw();
    void Update(const double& deltaTime);
    void HandleKey(int key, int state, int x, int y);
    
private:
    float xrot, yrot, zrot;
    float scale;
};


