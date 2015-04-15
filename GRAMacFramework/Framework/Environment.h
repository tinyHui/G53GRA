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
    
    struct Position {
        float x = 0;
        float y = 0;
        float z = 0;
        float x_piv = 0;
        float y_piv = 0;
        float z_piv = 0;
        float x_angel = 0;
        float y_angel = 0;
        float z_angel = 0;
    };
    
    struct SquareConfig {
        float width;
        float height;
        float depth;
    };

    struct CylinderConfig {
        float x_zoom = 1;
        float y_zoom = 1;
        float z_zoom = 1;
        float top_r;
        float bottom_r;
        float height;
    };
}

namespace camera {
    using namespace datastruct;
    struct Config {
        float x;
        float y;
        float z;
        float speed;
        float far_clipping_plane;
    };
//    constexpr Config CAMERA = { 0.f, 80.f, 0.f, 90.f, 0.f, 0.f, 0.3f, 500.f };
    constexpr Config CAMERA = { 75.f, 18.f, -30.f, 1.f, 500.f };
}

namespace sofa {
    using namespace datastruct;
    constexpr float WIDTH = 10;
    constexpr float SIT_THICK = 5;
    constexpr float SIT_DEPTH = 9;
    constexpr float PILLOW_R = 2;
    constexpr float BACK_THICK = 4;
    constexpr float BACK_HEIGHT = 12;
    constexpr float SIDE_THICK = 3;
    constexpr float SIDE_HEIGHT = 9;
    constexpr float GAP = 0.1;
}

namespace carpet {
    using namespace datastruct;
    struct Config {
        float width;
        float depth;
    };
    constexpr float THICK = 0.2;
}

namespace table {
    using namespace datastruct;
    constexpr float FACE_R = 15;
    constexpr float FACE_THICK = 0.8;
    constexpr float LEG_R = 1.5;
    constexpr float LEG_HEIGHT = 13;
    constexpr float BOTTOM_WIDTH = 8;
    constexpr float BOTTOM_DEPTH = 8;
    constexpr float BOTTOM_THICK = 1;
}

namespace chair {
    using namespace datastruct;
    constexpr float WIDTH = 8;
    constexpr float SIT_THICK = 0.5;
    constexpr float SIT_DEPTH = 9;
    constexpr float BACK_THICK = 0.5;
    constexpr float BACK_HEIGHT = 10;
    constexpr float LEG_THICK = 0.5;
    constexpr float LEG_HEIGHT = 9;
    constexpr int NUM = 5;
}

namespace room {
    using namespace datastruct;
    constexpr float WALL_THICK = 0.2;
    constexpr float KITCHEN_HEIGHT = 35;
    constexpr float TV_WALL_WIDTH = 40;
    constexpr float TV_WALL_THICK = 3;
    constexpr float TV_WALL_HEIGHT = 45;
    constexpr float TV_WALL_Z = -10;
    constexpr float TV_WALL_LEFT_WIDTH = 25;
    constexpr float TV_WALL_LEFT_THICK = 1;
    constexpr float TV_WALL_RIGHT_WIDTH = 18;
    constexpr float TV_WALL_RIGHT_THICK = 1;
    constexpr float TV_SHELF_WIDTH = 30;
    constexpr float TV_SHELF_DEPTH = 7;
    constexpr float TV_SHELF_THICK = 1;
    constexpr float STAIR_DEPTH = 6;
    constexpr int STAIR_LEVEL = 10;
    constexpr float STAIR_THICK = KITCHEN_HEIGHT / STAIR_LEVEL;
    constexpr float STAIR_BASE_Z = -40;
}

namespace wall_shelf {
    using namespace datastruct;
    constexpr float THICK = 0.8;
}

namespace time_clock {
    using namespace datastruct;
    constexpr float R = 5;
    constexpr float BASE_THICK = 0.5;
    constexpr float HAND_THICK = 0.5;
}

namespace lamp {
    using namespace datastruct;
    constexpr float LIGHT_WIDTH = 6;
    constexpr float LIGHT_DEPTH = 6;
    constexpr float LIGHT_THICK = 5.5;
    constexpr float LEG_R = 0.2;
    constexpr float LEG_HEIGHT = 18;
    constexpr float BOTTOM_WIDTH = 3;
    constexpr float BOTTOM_DEPTH = 3;
    constexpr float BOTTOM_THICK = 0.8;
}

namespace dog {
    using namespace datastruct;
    constexpr float HEAD_WIDTH = 7;
    constexpr float HEAD_HEIGHT = 6.5;
    constexpr float HEAD_DEPTH = 6;
    constexpr float EAR_WIDTH = 3;
    constexpr float EAR_HEIGHT = 0.5;
    constexpr float EAR_DEPTH = 2;
    constexpr float EAR_GAP = 1.1;
    constexpr float NOUSE_WIDTH = 2;
    constexpr float NOUSE_HEIGHT = 1.5;
    constexpr float NOUSE_DEPTH = 0.8;
    constexpr float BODY_WIDTH = 6;
    constexpr float BODY_HEIGHT = 5;
    constexpr float BODY_DEPTH = 10;
    constexpr float TAIL_WIDTH = 2.3;
    constexpr float TAIL_HEIGHT = 1.5;
    constexpr float TAIL_DEPTH = 2.3;
    constexpr float TAIL_GAP = 1.2;
    constexpr float LEG_WIDTH = 1.8;
    constexpr float LEG_HEIGHT = 4.3;
    constexpr float LEG_DEPTH = 2;
    constexpr float LEG_EDGE_X_GAP = 0.5;
    constexpr float LEG_EDGE_Z_GAP = 0.5;
    
    constexpr float LEG_RANGE = 30;
    constexpr float LEG_SPEED = 2;
    
    constexpr float DUMP_RANGE = 0.3;
    constexpr float DUMP_SPEED = 0.04;
    
    constexpr float WALK_OFFSET_LIM = 20;
    constexpr float WALK_DIST_MIN = 10;
    constexpr float WALK_DIST_MAX = WALK_OFFSET_LIM;
    constexpr float WALK_SPEED = 0.3;
    
    constexpr float BODY_SPEED = 0.3;
    constexpr float EAR_SPEED = 3;
    constexpr float HEAD_SPEED = 0.5;
    constexpr float TAIL_SPEED = 5;
}
