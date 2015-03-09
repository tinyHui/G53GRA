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

using namespace datastruct;
using namespace globalconf;

Block::Block()
{
}

Block::~Block()
{
}


void Block::createPrism(Vertice* v, Position p, float h)
{
    float size = ENV.cell_size;
    
    int x = p.x * size;
    int y = p.y * size;
    int z = p.z * size;
    
    glTranslatef(x, y, z);
    
    int vertice_num = 0;
    float top_y = h / 2.;
    float btm_y = - h / 2.;
    Vertice* current_v = v;
    
    // update size
    while (current_v != nullptr) {
        glVertex3d(current_v->x, top_y, current_v->z);
        current_v->x *= size;
        current_v->z *= size;
        current_v = current_v->next;
        vertice_num++;
    }
    
    glPushMatrix();

    // top
    glBegin(GL_LINE_LOOP);
    while (current_v != nullptr) {
        glVertex3d(current_v->x, top_y, current_v->z);
        current_v = current_v->next;
    }
    glEnd();
    
    // bottom
    current_v = v;
    glBegin(GL_LINE_LOOP);
    while (current_v != nullptr) {
        glVertex3d(current_v->x, btm_y, current_v->z);
        current_v = current_v->next;
    }
    glEnd();
    
    // side
    Vertice* v1 = v;
    Vertice* v2 = v1->next;
    for (int i = 0; i < vertice_num; i++) {
        glBegin(GL_LINE_LOOP);
        glVertex3d(v1->x, top_y, v1->z);
        glVertex3d(v2->x, top_y, v2->z);
        glVertex3d(v2->x, btm_y, v2->z);
        glVertex3d(v1->x, btm_y, v1->z);
        glEnd();

        v1 = v2;
        if (i < vertice_num - 2) {
            v2 = v1->next;
        } else {
            v2 = v;
        }
    }
    glPopMatrix();
    
    glTranslatef(-x, -y, -z);
}


void Block::createTruncated(Vertice* bv, datastruct::Vertice *tv, datastruct::Position p, float h)
{
    
}


void Block::createSquare(Position p, float w, float h, float d)
{
    float size = ENV.cell_size;
    
    int x = p.x * size;
    int y = p.y * size;
    int z = p.z * size;
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


void Block::createCube(Position p)
{
    float size = ENV.cell_size;
    createSquare(p, size, size, size);
}
