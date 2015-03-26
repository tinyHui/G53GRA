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
}

void Table::Draw()
{
    Config* table = new Config();
    
    // table bottom
    SquareConfig* bottom_config = new SquareConfig();
    bottom_config->width = table->bottom_width;
    bottom_config->height = table->bottom_thick;
    bottom_config->depth = table->bottom_depth;
    Position* bottom_pos = new Position();
    bottom_pos->x = 0;
    bottom_pos->y = table->bottom_thick / 2;
    bottom_pos->z = 0;
    
    // table leg
    CylinderConfig* leg_config = new CylinderConfig();
    leg_config->top_r = table->leg_r;
    leg_config->bottom_r = table->leg_r;
    leg_config->height = table->leg_height;
    Position* leg_pos = new Position();
    leg_pos->x = 0;
    leg_pos->y = bottom_pos->y + table->leg_height / 2;
    leg_pos->z = 0;
    
    // table face
    CylinderConfig* face_config = new CylinderConfig();
    face_config->top_r = table->face_r;
    face_config->bottom_r = table->face_r;
    face_config->height = table->face_thick;
    Position* face_pos = new Position();
    face_pos->x = 0;
    face_pos->y = leg_pos->y + leg_config->height / 2;
    face_pos->z = 0;

    // Draw
    glPushMatrix();
    glTranslatef(pos->x, pos->y, pos->z);
    glRotatef(pos->z_angel, 0.f, 0.f, 1.f);
    glRotatef(pos->y_angel, 0.f, 1.f, 0.f);
    glRotatef(pos->x_angel, 1.f, 0.f, 0.f);
    createCylinder(face_config, face_pos);
    createCylinder(leg_config, leg_pos);
    createSquare(bottom_config, bottom_pos);
    glRotatef(-pos->x_angel, 1.f, 0.f, 0.f);
    glRotatef(-pos->y_angel, 0.f, 1.f, 0.f);
    glRotatef(-pos->z_angel, 0.f, 0.f, 1.f);  
    glTranslatef(-pos->x, -pos->y, -pos->z);
    glPopMatrix();
}

void Table::Update( const double& deltaTime )
{
    
}

void Table::HandleKey(int key, int state, int x, int y)
{
    
}