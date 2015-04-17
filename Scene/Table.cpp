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
    GLfloat face_ambient[] = { 1.f, 1.f, 1.f, 1.f };     // Define the ambient material colour property K_a
    GLfloat face_diffuse[] = { 1.f, 1.f, 1.f, 1.f };     // Define the diffuse material colour property K_d
    GLfloat face_specular[] = { .2f, .2f, .2f, 1.f };    // Define the specular material colour property K_s
    GLfloat face_shininess[] = { 0. };
    
    GLfloat leg_ambient[] = { 0.3f, 0.3f, 0.3f, 1.f };     // Define the ambient material colour property K_a
    GLfloat leg_diffuse[] = { 0.3f, 0.3f, 0.3f, 1.f };     // Define the diffuse material colour property K_d
    GLfloat leg_specular[] = { .2f, .2f, .2f, 1.f };    // Define the specular material colour property K_s
    GLfloat leg_shininess[] = { 0. };
    
    glDisable(GL_COLOR_MATERIAL);
    // Draw
    glPushMatrix();
    glTranslatef(pos->x, pos->y, pos->z);
    glRotatef(pos->z_angle, 0.f, 0.f, 1.f);
    glRotatef(pos->y_angle, 0.f, 1.f, 0.f);
    glRotatef(pos->x_angle, 1.f, 0.f, 0.f);
    
    glPushAttrib(GL_LIGHTING);
    glMaterialfv(GL_FRONT, GL_AMBIENT, face_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, face_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, face_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, face_shininess);
    createCylinder(face_config, face_pos);
    glPopAttrib();
    
    glPushAttrib(GL_LIGHTING);
    glMaterialfv(GL_FRONT, GL_AMBIENT, leg_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, leg_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, leg_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, leg_shininess);
    createCylinder(leg_config, leg_pos);
    createCuboid(bottom_config, bottom_pos);
    glPopAttrib();
    
    glPopMatrix();
    glEnable(GL_COLOR_MATERIAL);
}

void Table::Update( const double& deltaTime )
{
    
}

void Table::HandleKey(int key, int state, int x, int y)
{
    
}