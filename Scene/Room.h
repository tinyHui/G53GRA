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
    Room(datastruct::BlockConfig* config, datastruct::Position* pos);
    ~Room(){};
    
    void Draw();
    void Update(const double& deltaTime);
    void HandleKey(int key, int state, int x, int y);
    
private:
    float width;
    float depth;
    float height;
    datastruct::Position* pos;
};
