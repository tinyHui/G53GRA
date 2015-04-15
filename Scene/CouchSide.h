//
//  Sofa.h
//  G53GRA
//
//  Created by Jason Chen on 3/26/15.
//  Copyright (c) 2015 NottinghamUniversity. All rights reserved.
//

#include "TextureManager.h"
#include "Environment.h"
#include "Object.h"

class CouchSide : public Object
{
public:
    CouchSide(datastruct::Position* pos);
    ~CouchSide(){};
    
    void Draw();
    void Update(const double& deltaTime);
    void HandleKey(int key, int state, int x, int y);
    
private:
    datastruct::Position* pos;
    TextureManager* texture_manager;
    GLuint* leather_box;
    GLuint* wood_box;

    datastruct::SquareConfig sit_config;
    datastruct::Position sit1_pos;
    datastruct::Position sit2_pos;
    datastruct::SquareConfig back_config;
    datastruct::Position back1_pos;
    datastruct::Position back2_pos;
    datastruct::SquareConfig s_config;
    datastruct::Position ls_pos;
    datastruct::Position rs_pos;
};

