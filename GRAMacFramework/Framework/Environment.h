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
//    constexpr Config CAMERA = { 0.f, 80.f, 0.f, 90.f, 0.f, 0.f, 0.3f, 500.f };
    constexpr Config CAMERA = { 13.f, 20.f, 25.f, 10.f, -18.f, 0.f, 1.f, 500.f };
}

namespace chair {
    using namespace datastruct;
    constexpr float WIDTH = 6;
    constexpr float SIT_THICK = 0.5;
    constexpr float SIT_DEPTH = 6.3;
    constexpr float BACK_THICK = 0.5;
    constexpr float BACK_HEIGHT = 7;
    constexpr float LEG_THICK = 0.5;
    constexpr float LEG_HEIGHT = 7;
}

namespace sofa {
    using namespace datastruct;
    constexpr float WIDTH = 10;
    constexpr float SIT_THICK = 5;
    constexpr float SIT_DEPTH = 6;
    constexpr float PILLOW_R = 2;
    constexpr float BACK_THICK = 4;
    constexpr float BACK_HEIGHT = 12;
    constexpr float SIDE_THICK = 3;
    constexpr float SIDE_HEIGHT = 9;
    constexpr float GAP = 0.1;
}

namespace table {
    using namespace datastruct;
    constexpr float FACE_R = 4;
    constexpr float FACE_THICK = 0.8;
    constexpr float LEG_R = 0.5;
    constexpr float LEG_HEIGHT = 9.5;
    constexpr float BOTTOM_WIDTH = 2.5;
    constexpr float BOTTOM_DEPTH = 2.5;
    constexpr float BOTTOM_THICK = 0.8;
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

namespace lamp {
    using namespace datastruct;
    constexpr float LIGHT_WIDTH = 6;
    constexpr float LIGHT_DEPTH = 6;
    constexpr float LIGHT_THICK = 5;
    constexpr float LEG_R = 0.5;
    constexpr float LEG_HEIGHT = 18;
    constexpr float BOTTOM_WIDTH = 3;
    constexpr float BOTTOM_DEPTH = 3;
    constexpr float BOTTOM_THICK = 0.8;
}