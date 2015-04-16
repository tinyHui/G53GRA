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
        float x_angle = 0;
        float y_angle = 0;
        float z_angle = 0;
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
    constexpr Config CAMERA = { 55.f, 18.f, -80.f, 1.f, 500.f };
}

namespace sofa {
    using namespace datastruct;
    constexpr float WIDTH = 12;
    constexpr float SIT_THICK = 6;
    constexpr float SIT_DEPTH = 13;
    constexpr float PILLOW_R = 2;
    constexpr float BACK_THICK = 4;
    constexpr float BACK_HEIGHT = 15;
    constexpr float SIDE_WIDTH = 14;
    constexpr float SIDE_THICK = 5;
    constexpr float SIDE_HEIGHT = 10;
    constexpr float GAP = 0.1;
}

namespace carpet {
    using namespace datastruct;
    struct Config {
        float width;
        float depth;
    };
    constexpr float THICK = 0.2;
    constexpr float CARPET_SOFA_GAP = 14;
    constexpr float CARPET_LAMP_GAP = 15;
}

namespace table {
    using namespace datastruct;
    constexpr float FACE_R = 15;
    constexpr float FACE_THICK = 0.8;
    constexpr float LEG_R = 1.5;
    constexpr float LEG_HEIGHT = 15;
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
    constexpr float TV_WALL_WIDTH = 40;
    constexpr float TV_WALL_THICK = 3;
    constexpr float TV_WALL_HEIGHT = 50;
    constexpr float TV_WALL_LEFT_WIDTH = 25;
    constexpr float TV_WALL_LEFT_THICK = 1;
    constexpr float TV_WALL_RIGHT_WIDTH = 18;
    constexpr float TV_WALL_RIGHT_THICK = 1;
    constexpr float KITCHEN_HEIGHT = 35;
    constexpr float KITCHEN_DEPTH = 85;
    constexpr float KITCHEN_WIDTH = TV_WALL_WIDTH + TV_WALL_LEFT_WIDTH + TV_WALL_RIGHT_WIDTH;
    constexpr float STAIR_DEPTH = 6;
    constexpr int STAIR_LEVEL = 10;
    constexpr float STAIR_THICK = KITCHEN_HEIGHT / STAIR_LEVEL;
}

namespace time_clock {
    using namespace datastruct;
    constexpr float R = 10;
    constexpr float BASE_THICK = 0.5;
    constexpr float HAND_HM_WIDHT = 0.3;
    constexpr float HAND_HOUR_LENGTH = 2;
    constexpr float HAND_MIN_LENGTH = 3.4;
    constexpr float HAND_SEC_WIDHT = 0.1;
    constexpr float HAND_SEC_LENGTH = 4;
    constexpr float HAND_THICK = 0.2;
    constexpr float HAND_OFFSET = 0.5;
    constexpr float HAND_GAP = 0.05;
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
    constexpr float HEAD_WIDTH = 3.5;
    constexpr float HEAD_HEIGHT = 3.3;
    constexpr float HEAD_DEPTH = 3;
    constexpr float EAR_WIDTH = 1.8;
    constexpr float EAR_HEIGHT = 0.25;
    constexpr float EAR_DEPTH = 1;
    constexpr float EAR_GAP = 0.6;
    constexpr float NOUSE_WIDTH = 1.2;
    constexpr float NOUSE_HEIGHT = 0.8;
    constexpr float NOUSE_DEPTH = 0.6;
    constexpr float BODY_WIDTH = 3;
    constexpr float BODY_HEIGHT = 2.5;
    constexpr float BODY_DEPTH = 5;
    constexpr float TAIL_WIDTH = 1.3;
    constexpr float TAIL_HEIGHT = 0.8;
    constexpr float TAIL_DEPTH = 1.2;
    constexpr float TAIL_GAP = 0.8;
    constexpr float LEG_WIDTH = 0.9;
    constexpr float LEG_HEIGHT = 2.1;
    constexpr float LEG_DEPTH = 1;
    constexpr float LEG_EDGE_X_GAP = 0.2;
    constexpr float LEG_EDGE_Z_GAP = 0.2;
    
    constexpr float LEG_RANGE = 80;
    constexpr float LEG_SPEED = 14;
    
    constexpr float BUMP_RANGE = 1.2;
    constexpr float BUMP_SPEED = 0.3;
    
    constexpr float WALK_DIST_MIN = 10;
    constexpr float WALK_SPEED = 0.3;
    
    constexpr float BODY_SPEED = 0.1;
    constexpr float EAR_SPEED = 3;
    constexpr float HEAD_SPEED = 0.5;
    constexpr float TAIL_SPEED = 5;
}
