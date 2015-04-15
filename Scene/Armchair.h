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

class Armchair : public Object
{
public:
    Armchair(datastruct::Position* pos);
    ~Armchair(){};
    
    void Draw();
    void Update(const double& deltaTime);
    void HandleKey(int key, int state, int x, int y);
    
private:
    datastruct::Position* pos;
     
    TextureManager* texture_manager;
    GLuint* sofa_box;
    
    datastruct::SquareConfig sit_config;
    datastruct::SquareConfig back_config;
    datastruct::SquareConfig ls_config;
    datastruct::SquareConfig rs_config;
    datastruct::Position sit_pos;
    datastruct::Position back_pos;
    datastruct::Position ls_pos;
    datastruct::Position rs_pos;
};

