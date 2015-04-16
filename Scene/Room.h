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
    datastruct::Position* pos;
    
    TextureManager* texture_manager;
    GLuint* room_box;
    GLuint* paint_box;
    GLuint* wood;
    GLuint* tv_wall_box;
    GLuint* kitchen_box;

    datastruct::SquareConfig room_wall_config;
    datastruct::Position room_wall_pos;
    datastruct::SquareConfig paint_config;
    datastruct::Position paint_pos;
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
    
    float position[4], ambient[4], diffuse[4], specular[4];
};
