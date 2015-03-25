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
    
    struct SquareConfig {
        float width;
        float height;
        float depth;
        Color color;
    };
    
    struct CylinderConfig {
        float x_zoom = 1;
        float y_zoom = 1;
        float z_zoom = 1;
        float top_r;
        float bottom_r;
        float height;
        Color color;
    };
    
    struct BlockConfig {
        float width;
        float height;
        float depth;
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
//    constexpr Config CAMERA = { 0.f, 20.f, 35.f, 20.f, 0.f, 0.f, 0.3f, 1000.f };
    constexpr Config CAMERA = { 0.f, 80.f, 0.f, 90.f, 0.f, 0.f, 1.f, 500.f };
}

namespace chair {
    using namespace datastruct;
    struct Config {
        float width = 3;
        float sit_thick = 0.5;
        float sit_depth = 3.5;
        float back_thick = 0.2;
        float back_height = 4;
        float leg_thick = 0.2;
        float leg_height = 4;
    };
}

namespace table {
    using namespace datastruct;
    struct Config {
        float face_r = 3.;
        float face_thick = 0.5;
        float leg_r = 0.2;
        float leg_height = 5.5;;
        float bottom_width = 1.5;
        float bottom_depth = 1.5;
        float bottom_thick = 0.3;
    };
}

namespace room {
    using namespace datastruct;
    constexpr float THICK = 0.2;
}
