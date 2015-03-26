//
//  Room.h
//  G53GRA
//
//  Created by Jason Chen on 3/23/15.
//  Copyright (c) 2015 NottinghamUniversity. All rights reserved.
//

#include "Environment.h"
#include "Object.h"

class Cell : public Object
{
public:
    Cell(datastruct::CellConfig* config, datastruct::Position* pos);
    ~Cell(){};
    
    void Draw();
    void Update(const double& deltaTime);
    void HandleKey(int key, int state, int x, int y);
    
private:
    float width;
    float depth;
    float height;
    bool have_front;
    bool have_back;
    bool have_left;
    bool have_right;
    bool have_top;
    bool have_bottom;
    datastruct::Position* pos;
};
