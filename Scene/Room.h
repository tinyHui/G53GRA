//
//  Room.h
//  G53GRA
//
//  Created by Jason Chen on 3/23/15.
//  Copyright (c) 2015 NottinghamUniversity. All rights reserved.
//

#include "Environment.h"
#include "Object.h"

class Room : public Object
{
public:
    Room(datastruct::SquareConfig* config, datastruct::Position* pos);
    ~Room(){};
    
    void Draw();
    void Update(const double& deltaTime);
    void HandleKey(int key, int state, int x, int y);
    
private:
    float width;
    float depth;
    float height;
    datastruct::Position* pos;
    
    TextureManager* texture_manager;
    GLuint* tile;
    GLuint* wood;
    GLuint* tv_wall_box;
    GLuint* kitchen_box;

    datastruct::SquareConfig fw_config;
    datastruct::Position fw_pos;
    datastruct::SquareConfig lw_config;
    datastruct::Position lw_pos;
    datastruct::SquareConfig rw_config;
    datastruct::Position rw_pos;
    datastruct::SquareConfig bw_config;
    datastruct::Position bw_pos;
    datastruct::SquareConfig tw_config;
    datastruct::Position tw_pos;
    datastruct::SquareConfig mw_config;
    datastruct::Position mw_pos;
    datastruct::SquareConfig r_tvw_sub_config;
    datastruct::Position r_tvw_sub_pos;
    datastruct::SquareConfig tvw_config;
    datastruct::Position tvw_pos;
    datastruct::SquareConfig l_tvw_sub_config;
    datastruct::Position l_tvw_sub_pos;
    datastruct::SquareConfig kit_big_config;
    datastruct::Position kit_big_pos;
    datastruct::SquareConfig kit_small_config;
    datastruct::Position kit_small_pos;
    datastruct::SquareConfig stair_config;
    datastruct::Position stair_pos;
};
