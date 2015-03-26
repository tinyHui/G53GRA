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
    
    struct CellConfig {
        float width;
        float height;
        float depth;
        bool have_front = true;
        bool have_back = true;
        bool have_left = true;
        bool have_right = true;
        bool have_top = true;
        bool have_bottom = true;
        Color color;
    };
    
    struct SquareShelf {
        float width;
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
//    constexpr Config CAMERA = { 0.f, 80.f, 0.f, 90.f, 0.f, 0.f, 0.3f, 1000.f };
    constexpr Config CAMERA = { 0.f, 15.f, 15.f, 10.f, 0.f, 0.f, 1.f, 500.f };
}

namespace sofa {
    using namespace datastruct;
    struct Config {
        float width = 6;
        float sit_thick = 0.5;
        float sit_depth = 6.3;
        float back_thick = 0.5;
        float back_height = 7;
        float leg_thick = 0.5;
        float leg_height = 7;
    };
}

namespace table {
    using namespace datastruct;
    struct Config {
        float face_r = 4;
        float face_thick = 0.8;
        float leg_r = 0.5;
        float leg_height = 9.5;
        float bottom_width = 2.5;
        float bottom_depth = 2.5;
        float bottom_thick = 0.8;
    };
}

namespace room {
    using namespace datastruct;
    constexpr float WALL_THICK = 0.2;
}

namespace wall_shelf {
    using namespace datastruct;
    constexpr float THICK = 0.8;
}

namespace time_clock {
    using namespace datastruct;
    constexpr float R = 1.5;
    constexpr float BASE_THICK = 0.5;
    constexpr float HAND_THICK = 0.5;
}