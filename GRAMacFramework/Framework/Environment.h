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
        Vertice( float x, float z, Vertice* next ) : x(x), z(z), next(next) {}
        float x;
        float z;
        Vertice* next;
    };
    
    struct CameraConf {
        Position pos;
        float speed;
        float far_clipping_plane;
    };
    
    struct Env {
        int cell_size;
        int width;
        int depth;
    };
    
    struct StairConfig {
        float width;
        float deepth;
        int level;
        float diff;
        Position base_pos;
        Vertice* v;
    };
    
    struct HouseConfig {
        float top_body_width;
        float top_body_deepth;
        float top_body_height;
        float btm_body_width;
        float btm_body_deepth;
        float btm_body_height;
        Position base_pos;
    };
}

// global config
namespace globalconf {
    using namespace datastruct;
    
    constexpr CameraConf CAMERA = { { 0.f, 100.f, -500.f }, 5.f, 1000.f };
    constexpr Env ENV = { 1, 300, 300 };
    
    // stair
    constexpr int ST_HEIGHT_PL = 30;
}

