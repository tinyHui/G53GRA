//
//  Block.h
//  G53GRA
//
//  Created by Jason Chen on 3/3/15.
//  Copyright (c) 2015 NottinghamUniversity. All rights reserved.
//

#pragma once

#include "Environment.h"

class Block
{
public:
    Block();
    ~Block();
    
    static void createPrism(datastruct::Vertice* v, datastruct::Position p, float h);
    static void createSquare(datastruct::Position p, float w, float h, float d);
    static void createCube(datastruct::Position p);
    
};


