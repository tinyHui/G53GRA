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

Table::Table(Position* table_pos) : table_pos(table_pos)
{
}

void Table::Draw()
{
    Color* main_color = new Color();
    main_color->r = 75;
    main_color->g = 52;
    main_color->b = 0;
    Config* table = new Config();
    
    // table bottom
    SquareConfig* bottom_config = new SquareConfig();
    bottom_config->width = table->bottom_width;
    bottom_config->height = table->bottom_thick;
    bottom_config->depth = table->bottom_depth;
    Position* bottom_pos = new Position();
    bottom_pos->x = 0;
    bottom_pos->y = 0;
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
    glTranslatef(table_pos->x, table_pos->y, table_pos->z);
    glRotatef(table_pos->x_angel, 1.f, 0.f, 0.f);
    glRotatef(table_pos->y_angel, 0.f, 1.f, 0.f);
    glRotatef(table_pos->z_angel, 0.f, 0.f, 1.f);
    createCylinder(face_config, face_pos);
    createCylinder(leg_config, leg_pos);
    createSquare(bottom_config, bottom_pos);
    glRotatef(-table_pos->z_angel, 0.f, 0.f, 1.f);
    glRotatef(-table_pos->y_angel, 0.f, 1.f, 0.f);
    glRotatef(-table_pos->x_angel, 1.f, 0.f, 0.f);
    glTranslatef(-table_pos->x, -table_pos->y, -table_pos->z);
    glPopMatrix();
}

void Table::Update( const double& deltaTime )
{
    
}

void Table::HandleKey(int key, int state, int x, int y)
{
    
}