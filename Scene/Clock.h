//
//  Clock.h
//  G53GRA
//
//  Created by Jason Chen on 3/26/15.
//  Copyright (c) 2015 NottinghamUniversity. All rights reserved.
//

#include "TextureManager.h"
#include "Environment.h"
#include "Object.h"

class Clock : public Object
{
public:
    Clock(datastruct::Position* pos);
    ~Clock(){};
    
    void Draw();
    void Update(const double& deltaTime);
    void HandleKey(int key, int state, int x, int y);
    
private:
    time_t current_time;
    struct tm *local_time;
    
    TextureManager* texture_manager;
    GLuint* clock_box;
    
    datastruct::Position* pos;
    datastruct::CuboidConfig leg_config;
    datastruct::Position leg_pos;
    datastruct::CuboidConfig cb_config;
    datastruct::Position cb_pos;
    
    datastruct::CuboidConfig h_hand_config;
    datastruct::Position h_hand_pos;
    datastruct::CuboidConfig m_hand_config;
    datastruct::Position m_hand_pos;
    datastruct::CuboidConfig s_hand_config;
    datastruct::Position s_hand_pos;
};
