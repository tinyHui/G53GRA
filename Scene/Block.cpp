//
//  Block.cpp
//  G53GRA
//
//  Created by Jason Chen on 3/3/15.
//  Copyright (c) 2015 NottinghamUniversity. All rights reserved.
//

#ifdef _WIN32
#include <Windows.h>
#include <GL\gl.h>
#include <GL\glu.h>
#include <GL\glut.h>
#else
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#endif

#include "Environment.h"
#include "Block.h"


Block::Block()
{
}

Block::~Block()
{
}

void Block::create(float x, float y, float z, float w, float h, float d)
{
    float size = Enviornment::CELL_SIZE;
    
    x *= size;
    y *= size;
    z *= size;
    w *= size;
    h *= size;
    d *= size;
    
    glTranslatef(x, y, z);
    
    glPushMatrix();
    // font
    //    glBegin(GL_POLYGON);
    glBegin(GL_LINE_LOOP);
    glVertex3d(-w / 2, h / 2, d / 2);
    glVertex3d(w / 2, h / 2, d / 2);
    glVertex3d(w / 2, -h / 2, d / 2);
    glVertex3d(-w / 2, -h / 2, d / 2);
    glEnd();
    
    // back
    glBegin(GL_LINE_LOOP);
    glVertex3d(-w / 2, h / 2, -d / 2);
    glVertex3d(w / 2, h / 2, -d / 2);
    glVertex3d(w / 2, -h / 2, -d / 2);
    glVertex3d(-w / 2, -h / 2, -d / 2);
    glEnd();
    
    // top
    glBegin(GL_LINE_LOOP);
    glVertex3d(-w / 2, h / 2, d / 2);
    glVertex3d(w / 2, h / 2, d / 2);
    glVertex3d(w / 2, h / 2, -d / 2);
    glVertex3d(-w / 2, h / 2, -d / 2);
    glEnd();
    
    // bottom
    glBegin(GL_LINE_LOOP);
    glVertex3d(-w / 2, -h / 2, d / 2);
    glVertex3d(w / 2, -h / 2, d / 2);
    glVertex3d(w / 2, -h / 2, -d / 2);
    glVertex3d(-w / 2, -h / 2, -d / 2);
    glEnd();
    
    // left
    glBegin(GL_LINE_LOOP);
    glVertex3d(-w / 2, h / 2, d / 2);
    glVertex3d(-w / 2, -h / 2, d / 2);
    glVertex3d(-w / 2, -h / 2, -d / 2);
    glVertex3d(-w / 2, h / 2, -d / 2);
    glEnd();
    
    // right
    glBegin(GL_LINE_LOOP);
    glVertex3d(w / 2, h / 2, d / 2);
    glVertex3d(w / 2, -h / 2, d / 2);
    glVertex3d(w / 2, -h / 2, -d / 2);
    glVertex3d(w / 2, h / 2, -d / 2);
    glEnd();

    glPopMatrix();
    
    glTranslatef(-x, -y, -z);
    
}

void Block::createCube(float x, float y, float z)
{
    float size = Enviornment::CELL_SIZE;
    create(x, y, z, size, size, size);
}
