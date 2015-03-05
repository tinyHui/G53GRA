//
//  Environment.h
//  G53GRA
//
//  Created by Jason Chen on 3/2/15.
//  Copyright (c) 2015 NottinghamUniversity. All rights reserved.
//

#ifndef __G53GRA__Environment__
#define __G53GRA__Environment__

class Enviornment
{
    struct CameraPos {
        float x;
        float y;
        float z;
    };
public:
    constexpr const static float width = 1000.0;
    constexpr const static float height = 1000.0;
    constexpr const static CameraPos camera = {0.f, 300.f, (float) height - 100};

};

#endif /* defined(__G53GRA__Environment__) */
