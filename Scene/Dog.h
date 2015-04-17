//
//  Dog.h
//  G53GRA
//
//  Created by Jason Chen on 4/12/15.
//  Copyright (c) 2015 NottinghamUniversity. All rights reserved.
//

#include "TextureManager.h"
#include "Environment.h"
#include "Object.h"

class Dog : public Object
{
public:
    Dog(datastruct::Position* pos);
    ~Dog(){};
    
    void Draw();
    void Update(const double& deltaTime);
    void HandleKey(int key, int state, int x, int y);
    
private:
    float r;
    float angle;
    
    float x_start;
    float z_start;
    
    int bump_stage;
    float bump_start;
    
    int leg_stage;
    float leg_current_target;
    
    datastruct::Position* pos;
    TextureManager* texture_manager;
    GLuint* head_box;
    GLuint* brown_box;
    GLuint* leg_box;
    
    datastruct::CuboidConfig head_config;
    datastruct::Position head_pos;
    datastruct::CuboidConfig ear_config;
    datastruct::Position l_ear_pos;
    datastruct::Position r_ear_pos;
    datastruct::CuboidConfig nouse_config;
    datastruct::Position nouse_pos;
    datastruct::CuboidConfig body_config;
    datastruct::Position body_pos;
    datastruct::CuboidConfig tail_config;
    datastruct::Position tail_pos;
    datastruct::CuboidConfig leg_config;
    datastruct::Position lt_leg_pos;
    datastruct::Position rt_leg_pos;
    datastruct::Position lb_leg_pos;
    datastruct::Position rb_leg_pos;
};
