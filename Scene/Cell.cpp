//
//  Room.cpp
//  G53GRA
//
//  Created by Jason Chen on 3/23/15.
//  Copyright (c) 2015 NottinghamUniversity. All rights reserved.
//

#include "Environment.h"
#include "Cell.h"

using namespace room;

Cell::Cell(datastruct::CellConfig* config, datastruct::Position* pos)
        : width(config->width), depth(config->depth), height(config->height),
          have_front(config->have_front), have_back(config->have_back), have_left(config->have_left),
          have_right(config->have_right), have_top(config->have_top), have_bottom(config->have_bottom),
          pos(pos)
{
}

void Cell::Draw()
{
    GLfloat mat_ambient[] = { 1., 1., 1., 1. };     // Define the ambient material colour property K_a
    GLfloat mat_diffuse[] = { 1., 1., 1., 1. };     // Define the diffuse material colour property K_d
    GLfloat mat_specular[] = { 1., 1., 1., 0.2 };    // Define the specular material colour property K_s
    GLfloat mat_shininess[] = { 128. };
    
    glPushAttrib(GL_LIGHTING);                          // Push/remember the materail settings before overriding the defaults
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    
    glPushMatrix();
    glColor3f(0.95f, 0.95f, 0.95f);
    glTranslatef(pos->x, pos->y, pos->z);
    glRotatef(pos->z_angel, 0.f, 0.f, 1.f);
    glRotatef(pos->y_angel, 0.f, 1.f, 0.f);
    glRotatef(pos->x_angel, 1.f, 0.f, 0.f);
    
    // front wall
    if (have_front) {
        SquareConfig* fw_config = new SquareConfig();
        fw_config->width = width;
        fw_config->depth = WALL_THICK;
        fw_config->height = height;
        Position* fw_pos = new Position();
        fw_pos->x = 0;
        fw_pos->y = height / 2. - WALL_THICK / 2;
        fw_pos->z = depth / 2.;
        createSquare(fw_config, fw_pos);
    }
    
    // left wall
    if (have_left) {
        SquareConfig* lw_config = new SquareConfig();
        lw_config->width = depth;
        lw_config->depth = WALL_THICK;
        lw_config->height = height;
        Position* lw_pos = new Position();
        lw_pos->x = - width / 2. + WALL_THICK / 2;
        lw_pos->y = height / 2.;
        lw_pos->z = 0;
        lw_pos->y_angel = 90;
        createSquare(lw_config, lw_pos);
    }
    
    // right wall
    if (have_right) {
        SquareConfig* rw_config = new SquareConfig();
        rw_config->width = depth;
        rw_config->depth = WALL_THICK;
        rw_config->height = height;
        Position* rw_pos = new Position();
        rw_pos->x = width / 2. - WALL_THICK / 2;
        rw_pos->y = height / 2.;
        rw_pos->z = 0;
        rw_pos->y_angel = 90;
        createSquare(rw_config, rw_pos);
    }
    
    // back
    if (have_back) {
        SquareConfig* bw_config = new SquareConfig();
        bw_config->width = width;
        bw_config->depth = WALL_THICK;
        bw_config->height = height;
        Position* bw_pos = new Position();
        bw_pos->x = 0;
        bw_pos->y = height / 2.;
        bw_pos->z = - depth / 2. + WALL_THICK / 2;
        createSquare(bw_config, bw_pos);
    }
    
    // top
    if (have_top) {
        SquareConfig* tw_config = new SquareConfig();
        tw_config->width = width;
        tw_config->depth = depth;
        tw_config->height = WALL_THICK;
        Position* tw_pos = new Position();
        tw_pos->x = 0;
        tw_pos->y = height - WALL_THICK / 2;
        tw_pos->z = 0;
        createSquare(tw_config, tw_pos);
    }
    
    // bottom
    if (have_bottom) {
        SquareConfig* mw_config = new SquareConfig();
        mw_config->width = width;
        mw_config->depth = depth;
        mw_config->height = WALL_THICK;
        Position* mw_pos = new Position();
        mw_pos->x = 0;
        mw_pos->y = 0;
        mw_pos->z = 0;
        createSquare(mw_config, mw_pos);
    }
    
    glRotatef(-pos->x_angel, 1.f, 0.f, 0.f);
    glRotatef(-pos->y_angel, 0.f, 1.f, 0.f);
    glRotatef(-pos->z_angel, 0.f, 0.f, 1.f);
    glTranslatef(-pos->x, -pos->y, -pos->z);
    glPopMatrix();
    glPopAttrib();
}

void Cell::Update( const double& deltaTime )
{
    
}

void Cell::HandleKey(int key, int state, int x, int y)
{
    
}