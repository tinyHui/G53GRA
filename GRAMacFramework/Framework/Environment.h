//
//  Environment.h
//  G53GRA
//
//  Created by Jason Chen on 3/2/15.
//  Copyright (c) 2015 NottinghamUniversity. All rights reserved.
//

#pragma once

namespace datastruct {
    // struct
    struct Position {
        float x;
        float y;
        float z;
    };
    
    struct Vertice {
        float x;
        float z;
        Vertice* next;
    };
    
    struct CameraConf {
        Position pos;
        float speed;
    };
    
    struct Env {
        int cell_size;
        int width;
        int depth;
    };
}

// global config
namespace globalconf {
    using namespace datastruct;
    
    constexpr CameraConf CAMERA = { { 0.f, 50.f, -500.f }, 10.f };
    constexpr Env ENV = { 1, 2000, 2000 };
    
    // stair
    constexpr int ST_HEIGHT_PL = 20;
}

