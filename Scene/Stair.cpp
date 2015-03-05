//
//  Stair.cpp
//  G53GRA
//
//  Created by Jason Chen on 3/2/15.
//  Copyright (c) 2015 NottinghamUniversity. All rights reserved.
//

#include "Environment.h"
#include "Stair.h"
#include "Block.h"

using namespace datastruct;
using namespace globalconf;

Stair::Stair()
{
}

Stair::~Stair()
{
}

void Stair::Draw()
{
    // main stair config
    Vertice v1 = { -200, 200, nullptr };
    Vertice v2 = { -200, -180, &v1 };
    Vertice v3 = { -170, -180, &v2 };
    Vertice v4 = { -170, -240, &v3 };
    Vertice v5 = { 170, -240, &v4 };
    Vertice v6 = { 170, -180, &v5 };
    Vertice v7 = { 200, -180, &v6 };
    Vertice v9 = { 200, 200, &v7 };
    
    StairConf main_stair;
    main_stair.level = 3;
    main_stair.diff = 30;
    main_stair.v = &v9;
    main_stair.pos = { 0, 0, 100 };
    
    glColor3f(0.f, 0.f, 0.f);
    
    // build main stair
    buildStairBase(main_stair);
}

void Stair::buildStairBase(StairConf stair)
{
    glColor3b(255, 0, 0);
    for (int l = 0; l < stair.level; l++) {
        Vertice* current_v = stair.v;
        while (current_v != nullptr) {
            if (current_v->x < 0) {
                current_v->x += stair.diff;
            } else if (current_v->x > 0) {
                current_v->x -= stair.diff;
            }
            if (current_v->z < 0) {
                current_v->z += stair.diff;
            } else if (current_v->z > 0) {
                current_v->z -= stair.diff;
            }
            current_v = current_v->next;
        }
        stair.pos.y += ST_HEIGHT_PL;
        Block::createPrism(stair.v, stair.pos, ST_HEIGHT_PL);
    }
}




void Stair::Update(const double& delta_time)
{
}

void Stair::HandleKey(int key, int state, int x, int y)
{
}