//
//  Sofa.cpp
//  G53GRA
//
//  Created by Jason Chen on 3/26/15.
//  Copyright (c) 2015 NottinghamUniversity. All rights reserved.
//

#include "Environment.h"
#include "Couch.h"

using namespace sofa;

Couch::Couch(Position* pos) : pos(pos)
{
}

void Couch::Draw()
{
    GLfloat mat_ambient[] = { 0.58f, 0.27f, 0.21f, 1.f };     // Define the ambient material colour property K_a
    GLfloat mat_diffuse[] = { 0.29f, 0.14f, 0.11f, 1.f };     // Define the diffuse material colour property K_d
    GLfloat mat_specular[] = { 0.3f, 0.2f, 0.1f, 0.8f };    // Define the specular material colour property K_s
    GLfloat mat_shininess[] = { 10. };
    
    glPushAttrib(GL_ALL_ATTRIB_BITS);
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    
    // sofa flat
    SquareConfig* sit_config = new SquareConfig();
    sit_config->width = WIDTH;
    sit_config->height = SIT_THICK;
    sit_config->depth = SIT_DEPTH;
    Position* sit1_pos = new Position();
    sit1_pos->x = - (WIDTH + GAP);
    sit1_pos->y = SIT_THICK / 2;
    sit1_pos->z = 0;
    Position* sit2_pos = new Position();
    sit2_pos->x = 0;
    sit2_pos->y = SIT_THICK / 2;
    sit2_pos->z = 0;
    Position* sit3_pos = new Position();
    sit3_pos->x = WIDTH + GAP;
    sit3_pos->y = SIT_THICK / 2;
    sit3_pos->z = 0;

    
    // sofa back
    SquareConfig* back_config = new SquareConfig();
    back_config->width = WIDTH;
    back_config->height = BACK_HEIGHT;
    back_config->depth = BACK_THICK;
    Position* back1_pos = new Position();
    back1_pos->x = - (WIDTH + GAP);
    back1_pos->y = BACK_HEIGHT / 2;
    back1_pos->z = - (SIT_DEPTH / 2. + BACK_THICK / 2. + GAP);
    Position* back2_pos = new Position();
    back2_pos->x = 0;
    back2_pos->y = BACK_HEIGHT / 2;
    back2_pos->z = - (SIT_DEPTH / 2. + BACK_THICK / 2. + GAP);
    Position* back3_pos = new Position();
    back3_pos->x = WIDTH + GAP;
    back3_pos->y = BACK_HEIGHT / 2;
    back3_pos->z = - (SIT_DEPTH / 2. + BACK_THICK / 2. + GAP);
    
    // sofa side
    SquareConfig* s_config = new SquareConfig();
    s_config->width = SIDE_THICK;
    s_config->height = SIDE_HEIGHT;
    s_config->depth = sit_config->depth + back_config->depth;
    Position* ls_pos = new Position();
    ls_pos->x = sit1_pos->x - (WIDTH + SIDE_THICK) / 2 - GAP;
    ls_pos->y = SIDE_HEIGHT / 2;
    ls_pos->z = - (BACK_THICK + GAP) / 2;
    Position* rs_pos = new Position();
    rs_pos->x = sit3_pos->x + (WIDTH + SIDE_THICK) / 2 + GAP;
    rs_pos->y = SIDE_HEIGHT / 2;
    rs_pos->z = - (BACK_THICK + GAP) / 2;
    
    // Draw
    glPushMatrix();
    glColor3f(0.58f, 0.27f, 0.21f);
    glTranslatef(pos->x, pos->y, pos->z);
    glRotatef(pos->z_angel, 0.f, 0.f, 1.f);
    glRotatef(pos->y_angel, 0.f, 1.f, 0.f);
    glRotatef(pos->x_angel, 1.f, 0.f, 0.f);
    createSquare(sit_config, sit1_pos);
    createSquare(sit_config, sit2_pos);
    createSquare(sit_config, sit3_pos);
    createSquare(back_config, back1_pos);
    createSquare(back_config, back2_pos);
    createSquare(back_config, back3_pos);
    createSquare(s_config, ls_pos);
    createSquare(s_config, rs_pos);
    glRotatef(-pos->x_angel, 1.f, 0.f, 0.f);
    glRotatef(-pos->y_angel, 0.f, 1.f, 0.f);
    glRotatef(-pos->z_angel, 0.f, 0.f, 1.f);
    glTranslatef(-pos->x, -pos->y, -pos->z);
    glPopMatrix();
    
    glPopAttrib();
}

void Couch::Update( const double& deltaTime )
{
    
}

void Couch::HandleKey(int key, int state, int x, int y)
{
    
}