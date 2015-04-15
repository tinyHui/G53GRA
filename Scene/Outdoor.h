//
//  Room.h
//  G53GRA
//
//  Created by Jason Chen on 3/23/15.
//  Copyright (c) 2015 NottinghamUniversity. All rights reserved.
//

#include "Environment.h"
#include "Object.h"

class Outdoor : public Object
{
public:
    Outdoor(datastruct::SquareConfig* config, datastruct::Position* pos);
    ~Outdoor(){};
    
    void Draw();
    void Update(const double& deltaTime);
    void HandleKey(int key, int state, int x, int y);
    
private:
    datastruct::Position* pos;
    
    TextureManager* texture_manager;
    GLuint* skybox;

    datastruct::SquareConfig box_config;
    datastruct::Position box_pos;
};
