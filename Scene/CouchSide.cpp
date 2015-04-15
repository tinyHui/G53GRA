//
//  Sofa.cpp
//  G53GRA
//
//  Created by Jason Chen on 3/26/15.
//  Copyright (c) 2015 NottinghamUniversity. All rights reserved.
//

#include "TextureManager.h"
#include "Environment.h"
#include "CouchSide.h"

using namespace sofa;

CouchSide::CouchSide(Position* pos) : pos(pos)
{
    texture_manager = new TextureManager();
    sofa_box = new GLuint[6];
    sofa_box[0] = texture_manager->loadImage("Resources/sofa.bmp");
    sofa_box[1] = sofa_box[0];
    sofa_box[2] = sofa_box[1];
    sofa_box[3] = sofa_box[2];
    sofa_box[4] = sofa_box[3];
    sofa_box[5] = sofa_box[4];

    // sofa flat
    sit_config.width = WIDTH;
    sit_config.height = SIT_THICK;
    sit_config.depth = SIT_DEPTH;
    sit1_pos.x = - (WIDTH + GAP) / 2;
    sit1_pos.y = SIT_THICK / 2;
    sit1_pos.z = 0;
    sit2_pos.x = (WIDTH + GAP) / 2;
    sit2_pos.y = SIT_THICK / 2;
    sit2_pos.z = 0;
    
    // sofa back
    back_config.width = WIDTH;
    back_config.height = BACK_HEIGHT;
    back_config.depth = BACK_THICK;
    back1_pos.x = sit1_pos.x;
    back1_pos.y = BACK_HEIGHT / 2;
    back1_pos.z = - (SIT_DEPTH / 2. + BACK_THICK / 2. + GAP);
    back2_pos.x = sit2_pos.x;
    back2_pos.y = BACK_HEIGHT / 2;
    back2_pos.z = - (SIT_DEPTH / 2. + BACK_THICK / 2. + GAP);
    
    // sofa side
    s_config.width = SIDE_THICK;
    s_config.height = SIDE_HEIGHT;
    s_config.depth = sit_config.depth + back_config.depth;
    ls_pos.x = sit1_pos.x - (WIDTH + SIDE_THICK) / 2 - GAP;
    ls_pos.y = SIDE_HEIGHT / 2;
    ls_pos.z = - (BACK_THICK + GAP) / 2;
    rs_pos.x = sit2_pos.x + (WIDTH + SIDE_THICK) / 2 + GAP;
    rs_pos.y = SIDE_HEIGHT / 2;
    rs_pos.z = - (BACK_THICK + GAP) / 2;
}

void CouchSide::Draw()
{
    // color
    GLfloat ambient[] = { 0.27f, 0.27f, 0.21f, 1.f };     // Define the ambient material colour property K_a
    GLfloat diffuse[] = { 0.11f, 0.14f, 0.11f, 1.f };     // Define the diffuse material colour property K_d
    GLfloat specular[] = { 0.1f, 0.1f, 0.1f, 0.8f };    // Define the specular material colour property K_s
    GLfloat shininess[] = { 10. };
    
    // Draw
    glPushMatrix();
    glTranslatef(pos->x, pos->y, pos->z);
    glRotatef(pos->z_angel, 0.f, 0.f, 1.f);
    glRotatef(pos->y_angel, 0.f, 1.f, 0.f);
    glRotatef(pos->x_angel, 1.f, 0.f, 0.f);
    
    glPushAttrib(GL_ALL_ATTRIB_BITS);
    glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
    createSquare(sit_config, sit1_pos, sofa_box);
    createSquare(sit_config, sit2_pos, sofa_box);
    createSquare(back_config, back1_pos, sofa_box);
    createSquare(back_config, back2_pos, sofa_box);
    createSquare(s_config, ls_pos, sofa_box);
    createSquare(s_config, rs_pos, sofa_box);
    glPopAttrib();
    
    glPopMatrix();
}

void CouchSide::Update( const double& deltaTime )
{
    
}

void CouchSide::HandleKey(int key, int state, int x, int y)
{
    
}