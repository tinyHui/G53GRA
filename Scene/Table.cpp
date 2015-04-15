//
//  Table.cpp
//  G53GRA
//
//  Created by Jason Chen on 3/23/15.
//  Copyright (c) 2015 NottinghamUniversity. All rights reserved.
//

#include "Environment.h"
#include "Table.h"

using namespace table;

Table::Table(Position* pos) : pos(pos)
{
    // table bottom
    bottom_config.width = BOTTOM_WIDTH;
    bottom_config.height = BOTTOM_THICK;
    bottom_config.depth = BOTTOM_DEPTH;
    bottom_pos.x = 0;
    bottom_pos.y = BOTTOM_THICK / 2;
    bottom_pos.z = 0;
    
    // table leg
    leg_config.top_r = LEG_R;
    leg_config.bottom_r = LEG_R;
    leg_config.height = LEG_HEIGHT;
    leg_pos.x = 0;
    leg_pos.y = bottom_pos.y + LEG_HEIGHT / 2;
    leg_pos.z = 0;
    
    // table face
    face_config.top_r = FACE_R;
    face_config.bottom_r = FACE_R;
    face_config.height = FACE_THICK;
    face_pos.x = 0;
    face_pos.y = leg_pos.y + leg_config.height / 2;
    face_pos.z = 0;
}

void Table::Draw()
{
    // Draw
    glPushMatrix();
    glTranslatef(pos->x, pos->y, pos->z);
    glRotatef(pos->z_angel, 0.f, 0.f, 1.f);
    glRotatef(pos->y_angel, 0.f, 1.f, 0.f);
    glRotatef(pos->x_angel, 1.f, 0.f, 0.f);
    createCylinder(face_config, face_pos);
    createCylinder(leg_config, leg_pos);
    createSquare(bottom_config, bottom_pos);
    glPopMatrix();
}

void Table::Update( const double& deltaTime )
{
    
}

void Table::HandleKey(int key, int state, int x, int y)
{
    
}