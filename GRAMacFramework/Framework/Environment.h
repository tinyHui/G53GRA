//
//  Environment.h
//  G53GRA
//
//  Created by Jason Chen on 3/2/15.
//  Copyright (c) 2015 NottinghamUniversity. All rights reserved.
//

#pragma once

namespace datastruct {
    // basic struct
    struct Env {
        int width;
        int depth;
    };
    
    struct Color {
        float r = 0;
        float g = 0;
        float b = 0;
    };
    
    struct Position {
        float x;
        float y = 0;
        float z;
        float x_angel = 0;
        float y_angel = 0;
        float z_angel = 0;
    };
    
    struct Vertice {
        Vertice( float x, float y, float z, Vertice* next ) : x(x), y(y), z(z), next(next) {}
        float x;
        float y;
        float z;
        Vertice* next;
    };
    
    struct SquareConfig {
        float width;
        float height;
        float depth;
        Color color;
    };
}

namespace camera {
    using namespace datastruct;
    struct Config {
        float x;
        float y;
        float z;
        float x_angel;
        float y_angel;
        float z_angel;
        float speed;
        float far_clipping_plane;
    };
    constexpr Config CAMERA = { 0.f, 10.f, 0.f, 20.f, 0.f, 0.f, 1.f, 1000.f };
}

namespace wall {
    using namespace datastruct;
    struct Config {
        Position pos;
        float width;
        float height;
        float depth = 2.f;
    };
}

namespace chair {
    using namespace datastruct;
    struct Config {
        float width = 3;
        float sit_thick = 0.2;
        float sit_depth = 4;
        float back_thick = 0.2;
        float back_height = 5;
        float leg_thick = 0.2;
        float leg_height = 4;
    };
}
