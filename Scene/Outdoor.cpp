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
        : pos(pos)
{
    texture_manager = new TextureManager();
    skybox = new GLuint[6];
    skybox[0] = texture_manager->loadImage("img/skybox_front.bmp");
    skybox[1] = texture_manager->loadImage("img/skybox_back.bmp");
    skybox[2] = texture_manager->loadImage("img/skybox_left.bmp");
    skybox[3] = texture_manager->loadImage("img/skybox_right.bmp");
    skybox[4] = texture_manager->loadImage("img/skybox_up.bmp");
    skybox[5] = texture_manager->loadImage("img/skybox_down.bmp");
    
    box_config.width = config->width;
    box_config.height = config->height;
    box_config.depth = config->depth;
    box_pos.x = 0;
    box_pos.y = 0;
    box_pos.z = 0;
}

void Outdoor::Draw()
{
    glPushMatrix();
    glPushAttrib(GL_LIGHTING);                          // Push/remember the materail settings before overriding the defaults
    glTranslatef(pos->x, pos->y, pos->z);
    
    // outdoor wall
    createSquare(box_config, box_pos, skybox, true);
    
    glPopAttrib();
    glPopMatrix();
}

void Outdoor::Update( const double& deltaTime )
{
    
}

void Outdoor::HandleKey(int key, int state, int x, int y)
{
    
}