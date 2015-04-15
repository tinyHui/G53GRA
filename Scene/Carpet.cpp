//
//  Carpet.cpp
//  G53GRA
//
//  Created by Jason Chen on 3/31/15.
//  Copyright (c) 2015 NottinghamUniversity. All rights reserved.
//

#include "Environment.h"
#include "Carpet.h"

using namespace carpet;

Carpet::Carpet(Config* config, Position* pos) : config(config), pos(pos)
{
    texture_manager = new TextureManager();
    carpet_box = new GLuint[6];
    carpet_box[4] = texture_manager->loadImage("Resources/carpet.bmp");
    carpet_box[5] = carpet_box[4];

    // carpet body
    carpet_config.width = config->width;
    carpet_config.height = THICK;
    carpet_config.depth = config->depth;
    carpet_pos.x = 0;
    carpet_pos.y = THICK / 2;
    carpet_pos.z = 0;
}

void Carpet::Draw()
{
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
    
    glPushAttrib(GL_ALL_ATTRIB_BITS);
    glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
    createSquare(carpet_config, carpet_pos, carpet_box);
    glPopAttrib();

    glPopMatrix();
}

void Carpet::Update( const double& deltaTime )
{
    
}

void Carpet::HandleKey(int key, int state, int x, int y)
{
    
}