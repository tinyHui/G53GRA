//
//  Sofa.cpp
//  G53GRA
//
//  Created by Jason Chen on 3/26/15.
//  Copyright (c) 2015 NottinghamUniversity. All rights reserved.
//

#include "Environment.h"
#include "Armchair.h"

using namespace sofa;

Armchair::Armchair(Position* pos) : pos(pos)
{
}

void Armchair::Draw()
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
    Position* sit_pos = new Position();
    sit_pos->x = 0;
    sit_pos->y = SIT_THICK / 2;
    sit_pos->z = 0;
    
    // sofa back
    SquareConfig* back_config = new SquareConfig();
    back_config->width = WIDTH;
    back_config->height = BACK_HEIGHT;
    back_config->depth = BACK_THICK;
    Position* back_pos = new Position();
    back_pos->x = 0;
    back_pos->y = BACK_HEIGHT / 2;
    back_pos->z = - (SIT_DEPTH / 2. + BACK_THICK / 2. + GAP);
    
    // sofa side left
    SquareConfig* ls_config = new SquareConfig();
    ls_config->width = SIDE_THICK;
    ls_config->height = SIDE_HEIGHT;
    ls_config->depth = sit_config->depth + back_config->depth;
    Position* ls_pos = new Position();
    ls_pos->x = - (WIDTH + SIDE_THICK) / 2 - GAP;
    ls_pos->y = SIDE_HEIGHT / 2;
    ls_pos->z = - (BACK_THICK + GAP) / 2;
    
    // sofa side right
    SquareConfig* rs_config = new SquareConfig();
    rs_config->width = SIDE_THICK;
    rs_config->height = SIDE_HEIGHT;
    rs_config->depth = sit_config->depth + back_config->depth;
    Position* rs_pos = new Position();
    rs_pos->x = (WIDTH + SIDE_THICK) / 2 + GAP;
    rs_pos->y = SIDE_HEIGHT / 2;
    rs_pos->z = - (BACK_THICK + GAP) / 2;
    
    // Draw
    glPushMatrix();
    glColor3f(0.58f, 0.27f, 0.21f);
    glTranslatef(pos->x, pos->y, pos->z);
    glRotatef(pos->z_angel, 0.f, 0.f, 1.f);
    glRotatef(pos->y_angel, 0.f, 1.f, 0.f);
    glRotatef(pos->x_angel, 1.f, 0.f, 0.f);
    createSquare(sit_config, sit_pos);
    createSquare(back_config, back_pos);
    createSquare(ls_config, ls_pos);
    createSquare(rs_config, rs_pos);
    glRotatef(-pos->x_angel, 1.f, 0.f, 0.f);
    glRotatef(-pos->y_angel, 0.f, 1.f, 0.f);
    glRotatef(-pos->z_angel, 0.f, 0.f, 1.f);
    glTranslatef(-pos->x, -pos->y, -pos->z);
    glPopMatrix();
    
    glPopAttrib();
}

void Armchair::Update( const double& deltaTime )
{
    
}

void Armchair::HandleKey(int key, int state, int x, int y)
{
    
}