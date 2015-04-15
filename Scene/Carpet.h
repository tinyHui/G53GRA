//
//  Carpet.h
//  G53GRA
//
//  Created by Jason Chen on 3/31/15.
//  Copyright (c) 2015 NottinghamUniversity. All rights reserved.
//

#include "TextureManager.h"
#include "Environment.h"
#include "Object.h"

class Carpet : public Object
{
public:
    Carpet(carpet::Config* config, datastruct::Position* pos);
    ~Carpet(){};
    
    void Draw();
    void Update(const double& deltaTime);
    void HandleKey(int key, int state, int x, int y);
    
private:
    carpet::Config* config;
    datastruct::Position* pos;
    TextureManager* texture_manager;
    GLuint* carpet_box;

    datastruct::SquareConfig carpet_config;
    datastruct::Position carpet_pos;
};
