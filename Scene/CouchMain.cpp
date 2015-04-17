//
//  Sofa.cpp
//  G53GRA
//
//  Created by Jason Chen on 3/26/15.
//  Copyright (c) 2015 NottinghamUniversity. All rights reserved.
//

#include "TextureManager.h"
#include "Environment.h"
#include "CouchMain.h"

using namespace sofa;

CouchMain::CouchMain(Position* pos) : pos(pos)
{
    texture_manager = new TextureManager();
    
    leather_box = new GLuint[6];
    leather_box[0] = texture_manager->loadImage("img/leather.bmp");
    leather_box[1] = leather_box[0];
    leather_box[2] = leather_box[0];
    leather_box[3] = leather_box[0];
    leather_box[4] = leather_box[0];
    leather_box[5] = leather_box[0];
    
    wood_box = new GLuint[6];
    wood_box[0] = texture_manager->loadImage("img/wood.bmp");
    wood_box[1] = wood_box[0];
    wood_box[2] = wood_box[0];
    wood_box[3] = wood_box[0];
    wood_box[4] = wood_box[0];
    wood_box[5] = wood_box[0];

    // sofa flat
    sit_config.width = WIDTH;
    sit_config.height = SIT_THICK;
    sit_config.depth = SIT_DEPTH;
    sit1_pos.x = - (WIDTH + GAP);
    sit1_pos.y = SIT_THICK / 2;
    sit1_pos.z = 0;
    sit2_pos.x = 0;
    sit2_pos.y = SIT_THICK / 2;
    sit2_pos.z = 0;
    sit3_pos.x = WIDTH + GAP;
    sit3_pos.y = SIT_THICK / 2;
    sit3_pos.z = 0;
    
    // sofa back
    back_config.width = WIDTH;
    back_config.height = BACK_HEIGHT;
    back_config.depth = BACK_THICK;
    back1_pos.x = - (WIDTH + GAP);
    back1_pos.y = BACK_HEIGHT / 2;
    back1_pos.z = - (SIT_DEPTH / 2. + BACK_THICK / 2. + GAP);
    back1_pos.x_angle = -5;
    back2_pos.x = 0;
    back2_pos.y = BACK_HEIGHT / 2;
    back2_pos.z = - (SIT_DEPTH / 2. + BACK_THICK / 2. + GAP);
    back2_pos.x_angle = -5;
    back3_pos.x = WIDTH + GAP;
    back3_pos.y = BACK_HEIGHT / 2;
    back3_pos.z = - (SIT_DEPTH / 2. + BACK_THICK / 2. + GAP);
    back3_pos.x_angle = -5;
    
    // sofa side
    s_config.width = SIDE_THICK;
    s_config.height = SIDE_HEIGHT;
    s_config.depth = SIDE_WIDTH;
    ls_pos.x = sit1_pos.x - (WIDTH + SIDE_THICK) / 2 - GAP;
    ls_pos.y = SIDE_HEIGHT / 2;
    ls_pos.z = - (BACK_THICK + GAP) / 2;
    ls_pos.x_angle = 0;
    ls_pos.y_angle = 0;
    ls_pos.z_angle = 0;
    rs_pos.x = sit3_pos.x + (WIDTH + SIDE_THICK) / 2 + GAP;
    rs_pos.y = SIDE_HEIGHT / 2;
    rs_pos.z = ls_pos.z;
    rs_pos.x_angle = 0;
    rs_pos.y_angle = 0;
    rs_pos.z_angle = 0;
}

void CouchMain::Draw()
{
    // color
    GLfloat ambient[] = { 0.27f, 0.27f, 0.21f, 1.f };     // Define the ambient material colour property K_a
    GLfloat diffuse[] = { 0.11f, 0.14f, 0.11f, 1.f };     // Define the diffuse material colour property K_d
    GLfloat specular[] = { 0.1f, 0.1f, 0.1f, 0.8f };    // Define the specular material colour property K_s
    GLfloat shininess[] = { 10. };
    
    // Draw
    glPushMatrix();
    glTranslatef(pos->x, pos->y, pos->z);
    glRotatef(pos->z_angle, 0.f, 0.f, 1.f);
    glRotatef(pos->y_angle, 0.f, 1.f, 0.f);
    glRotatef(pos->x_angle, 1.f, 0.f, 0.f);
    
    glPushAttrib(GL_ALL_ATTRIB_BITS);
    glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
    createCuboid(sit_config, sit1_pos, leather_box);
    createCuboid(sit_config, sit2_pos, leather_box);
    createCuboid(sit_config, sit3_pos, leather_box);
    createCuboid(back_config, back1_pos, leather_box);
    createCuboid(back_config, back2_pos, leather_box);
    createCuboid(back_config, back3_pos, leather_box);
    createCuboid(s_config, ls_pos, wood_box);
    createCuboid(s_config, rs_pos, wood_box);
    glPopAttrib();
    
    glPopMatrix();
}

void CouchMain::Update( const double& deltaTime )
{
    
}

void CouchMain::HandleKey(int key, int state, int x, int y)
{
    
}