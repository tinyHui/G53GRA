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
    Room(datastruct::CuboidConfig* config, datastruct::Position* pos);
    ~Room(){};
    
    void Draw();
    void Update(const double& deltaTime);
    void HandleKey(int key, int state, int x, int y);
    
private:
    datastruct::Position* pos;
    
    TextureManager* texture_manager;
    GLuint* room_box;
    GLuint* paint_box;
    GLuint* wood;
    GLuint* tv_wall_box;
    GLuint* dining_hall_box;

    datastruct::CuboidConfig room_wall_config;
    datastruct::Position room_wall_pos;
    datastruct::CuboidConfig paint_config;
    datastruct::Position paint_pos;
    datastruct::CuboidConfig r_tvw_sub_config;
    datastruct::Position r_tvw_sub_pos;
    datastruct::CuboidConfig tvw_config;
    datastruct::Position tvw_pos;
    datastruct::CuboidConfig l_tvw_sub_config;
    datastruct::Position l_tvw_sub_pos;
    datastruct::CuboidConfig DHALL_big_config;
    datastruct::Position DHALL_big_pos;
    datastruct::CuboidConfig DHALL_small_config;
    datastruct::Position DHALL_small_pos;
    datastruct::CuboidConfig stair_config;
    datastruct::Position stair_pos;
};
