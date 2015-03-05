//
//  Environment.h
//  G53GRA
//
//  Created by Jason Chen on 3/2/15.
//  Copyright (c) 2015 NottinghamUniversity. All rights reserved.
//

#pragma once

class Enviornment
{

private:
    struct Camera {
        float x;
        float y;
        float z;
        float speed;
    };
    constexpr static Camera CAMERA = { 0.f, 5.f, -1500.f, 2.f };
    
    struct Env {
        int cell_size;
        int width;
        int depth;
    };
    constexpr static Env ENV = { 1, 2000, 4000 };
    

public:
    // global config
    constexpr static float CM_X = CAMERA.x;
    constexpr static float CM_Y = CAMERA.y;
    constexpr static float CM_Z = CAMERA.z;
    constexpr static float CM_S = CAMERA.speed;
    constexpr static float ENV_WIDTH = ENV.width;
    constexpr static float ENV_DEPTH = ENV.depth;
    constexpr static float CELL_SIZE = ENV.cell_size;
    
    // stair
    constexpr static int ST_HEIGHT_PL = 30;
};

