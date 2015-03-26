//
//  ShelfOnWall.h
//  G53GRA
//
//  Created by Jason Chen on 3/25/15.
//  Copyright (c) 2015 NottinghamUniversity. All rights reserved.
//

#include "Environment.h"
#include "Object.h"

class WallShelf : public Object
{
public:
    WallShelf(datastruct::SquareShelf* config, datastruct::Position* pos);
    ~WallShelf(){};
    
    void Draw();
    void Update(const double& deltaTime);
    void HandleKey(int key, int state, int x, int y);
    
private:
    datastruct::SquareShelf* config;
    datastruct::Position* pos;
};