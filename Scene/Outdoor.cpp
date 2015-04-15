//
//  Room.cpp
//  G53GRA
//
//  Created by Jason Chen on 3/23/15.
//  Copyright (c) 2015 NottinghamUniversity. All rights reserved.
//

#include "TextureManager.h"
#include "Environment.h"
#include "Outdoor.h"

using namespace room;

Outdoor::Outdoor(datastruct::SquareConfig* config, datastruct::Position* pos)
        : width(config->width), depth(config->depth), height(config->height),
          pos(pos)
{
    texture_manager = new TextureManager();
    floor_box = new GLuint[6];
//    floor_box[0] = texture_manager->loadImage("Resources/floor.bmp");
//    floor_box[1] = floor_box[0];
//    floor_box[2] = floor_box[1];
//    floor_box[3] = floor_box[2];
//    floor_box[4] = floor_box[3];
//    floor_box[5] = floor_box[4];
    
    // left
    lw_config.width = depth;
    lw_config.depth = WALL_THICK;
    lw_config.height = height;
    lw_pos.x = - width / 2. + WALL_THICK / 2;
    lw_pos.y = height / 2.;
    lw_pos.z = 0;
    lw_pos.y_angel = 90;
    
    // right
    rw_config.width = depth;
    rw_config.depth = WALL_THICK;
    rw_config.height = height;
    rw_pos.x = width / 2. - WALL_THICK / 2;
    rw_pos.y = height / 2.;
    rw_pos.z = 0;
    rw_pos.y_angel = 90;

    // front
    fw_config.width = width;
    fw_config.depth = WALL_THICK;
    fw_config.height = height;
    fw_pos.x = 0;
    fw_pos.y = height / 2. - WALL_THICK / 2;
    fw_pos.z = depth / 2.;
    
    // back
    bw_config.width = width;
    bw_config.depth = WALL_THICK;
    bw_config.height = height;
    bw_pos.x = 0;
    bw_pos.y = height / 2.;
    bw_pos.z = - depth / 2. + WALL_THICK / 2;

    // top
    tw_config.width = width;
    tw_config.depth = depth;
    tw_config.height = WALL_THICK;
    tw_pos.x = 0;
    tw_pos.y = height - WALL_THICK / 2;
    tw_pos.z = 0;
    
    // bottom
    mw_config.width = width;
    mw_config.depth = depth;
    mw_config.height = WALL_THICK;
    mw_pos.x = 0;
    mw_pos.y = 0;
    mw_pos.z = 0;
}

void Outdoor::Draw()
{
    GLfloat mat_ambient[] = { 1., 1., 1., 1. };     // Define the ambient material colour property K_a
    GLfloat mat_diffuse[] = { 1., 1., 1., 1. };     // Define the diffuse material colour property K_d
    GLfloat mat_specular[] = { 1., 1., 1., 1. };    // Define the specular material colour property K_s
    GLfloat mat_shininess[] = { 128. };

    glPushMatrix();
    glPushAttrib(GL_LIGHTING);                          // Push/remember the materail settings before overriding the defaults
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_shininess);
    glTranslatef(pos->x, pos->y, pos->z);
    glRotatef(pos->z_angel, 0.f, 0.f, 1.f);
    glRotatef(pos->y_angel, 0.f, 1.f, 0.f);
    glRotatef(pos->x_angel, 1.f, 0.f, 0.f);
    
    // outdoor wall
    createSquare(fw_config, fw_pos);
    createSquare(lw_config, lw_pos);
    createSquare(rw_config, rw_pos);
    createSquare(bw_config, bw_pos);
    createSquare(tw_config, tw_pos);
    createSquare(mw_config, mw_pos);
    
    glPopAttrib();
    glPopMatrix();
}

void Outdoor::Update( const double& deltaTime )
{
    
}

void Outdoor::HandleKey(int key, int state, int x, int y)
{
    
}