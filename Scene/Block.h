//
//  Block.h
//  G53GRA
//
//  Created by Jason Chen on 3/3/15.
//  Copyright (c) 2015 NottinghamUniversity. All rights reserved.
//

#pragma once

class Block
{
    
public:
    Block();
    ~Block();
    
    static void create(float x, float y, float z, float w, float h, float d);
    static void createCube(float x, float y, float z);
    
private:
    float size;
    
};


