//
//  Sofa.cpp
//  G53GRA
//
//  Created by Jason Chen on 3/26/15.
//  Copyright (c) 2015 NottinghamUniversity. All rights reserved.
//

#include "TextureManager.h"
#include "Environment.h"
#include "Armchair.h"

using namespace sofa;

Armchair::Armchair(Position* pos) : pos(pos)
{
    texture_manager = new TextureManager();
    
    sofa_box = new GLuint[6];
    sofa_box[0] = texture_manager->loadImage("img/leather.bmp");
    sofa_box[1] = sofa_box[0];
    sofa_box[2] = sofa_box[1];
    sofa_box[3] = sofa_box[2];
    sofa_box[4] = sofa_box[3];
    sofa_box[5] = sofa_box[4];
    
    // sofa flat
    sit_config.width = WIDTH;
    sit_config.height = SIT_THICK;
    sit_config.depth = SIT_DEPTH;
    sit_pos.x = 0;
    sit_pos.y = SIT_THICK / 2;
    sit_pos.z = 0;
    
    // sofa back
    back_config.width = WIDTH;
    back_config.height = BACK_HEIGHT;
    back_config.depth = BACK_THICK;
    back_pos.x = 0;
    back_pos.y = BACK_HEIGHT / 2;
    back_pos.z = - (SIT_DEPTH / 2. + BACK_THICK / 2. + GAP);
    
    // sofa side left
    ls_config.width = SIDE_THICK;
    ls_config.height = SIDE_HEIGHT;
    ls_config.depth = sit_config.depth + back_config.depth;
    ls_pos.x = - (WIDTH + SIDE_THICK) / 2 - GAP;
    ls_pos.y = SIDE_HEIGHT / 2;
    ls_pos.z = - (BACK_THICK + GAP) / 2;
    
    // sofa side right
    rs_config.width = SIDE_THICK;
    rs_config.height = SIDE_HEIGHT;
    rs_config.depth = sit_config.depth + back_config.depth;
    rs_pos.x = (WIDTH + SIDE_THICK) / 2 + GAP;
    rs_pos.y = SIDE_HEIGHT / 2;
    rs_pos.z = - (BACK_THICK + GAP) / 2;
    
}

void Armchair::Draw()
{
    // color
    GLfloat ambient[] = { 0.58f, 0.27f, 0.21f, 1.f };     // Define the ambient material colour property K_a
    GLfloat diffuse[] = { 0.29f, 0.14f, 0.11f, 1.f };     // Define the diffuse material colour property K_d
    GLfloat specular[] = { 0.3f, 0.2f, 0.1f, 0.8f };    // Define the specular material colour property K_s
    GLfloat shininess[] = { 123. };
    
    // Draw
    glPushMatrix();
    glTranslatef(pos->x, pos->y, pos->z);
    glRotatef(pos->z_angel, 0.f, 0.f, 1.f);
    glRotatef(pos->y_angel, 0.f, 1.f, 0.f);
    glRotatef(pos->x_angel, 1.f, 0.f, 0.f);
    
    // dress color
    glPushAttrib(GL_ALL_ATTRIB_BITS);
    glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
    // create
    createSquare(sit_config, sit_pos, sofa_box);
    createSquare(back_config, back_pos, sofa_box);
    createSquare(ls_config, ls_pos, sofa_box);
    createSquare(rs_config, rs_pos, sofa_box);
    glPopAttrib();
    // end color

    glPopMatrix();
}

void Armchair::Update( const double& deltaTime )
{
    
}

void Armchair::HandleKey(int key, int state, int x, int y)
{
    
}