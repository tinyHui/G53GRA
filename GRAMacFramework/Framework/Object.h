
/*
 This is the class you will use to add objects to your scene.
 First create a new class for the object that you want to draw.
 Then make your new class inherit the 'Object' class.
 This way your new class will be able to override all the functions that an object may want to do.
 If you want to draw the new object you have created then you will need to override the Draw() function.
 If you want to update the object every frame you need to override the Update( const double& deltaTime ) function.
 If you want your object to recieve keyboard or mouse commands then override the Handle...() functions.
 Once you have done this you can add your new object to the scene with AddObjectToScene() in the Init function of MyScene.
 */

#pragma once

#include <stdlib.h>
#include <cmath>
#include "Scene.h"
#include "Environment.h"

class Object
{
public:
    Object(void) {}
    virtual ~Object(void) {}
    
    // Called each frame after updates are done to draw it to the screen
    virtual void Draw(){};
    
    // Called each frame to update.
    virtual void Update( const double& deltaTime ){};
    
    // Called when keyboard input is received - x and y are the mouse coordinates at the time when the key was pressed
    virtual void HandleKey(int key, int state, int x, int y ){}
    // Called when a mouse button is pressed, or released.  x and y are the mouse position
    virtual void HandleMouseClick( int button, int state, int x, int y ){}
    // Called when the mouse moves if a button is pressed, x and y are the mouse position
    virtual void HandleMouseMotion( int x, int y ){}
    // Called every time the mouse moves, x and y are the mouse position.
    virtual void HandlePassiveMouseMotion( int x, int y ){}
    
    void createSquare(datastruct::SquareConfig* config, datastruct::Position* pos)
    {
        using namespace datastruct;
        glTranslatef(pos->x, pos->y, pos->z);
        glRotated(pos->x_angel, 1., 0, 0);
        glRotated(pos->y_angel, 0, 1., 0);
        glRotated(pos->z_angel, 0, 0, 1.);
        glPushMatrix();
        glScalef(config->width, config->height, config->depth);
        glutSolidCube(1.f);
        glPopMatrix();
        glRotated(-pos->z_angel, 0, 0, 1.);
        glRotated(-pos->y_angel, 0, 1., 0);
        glRotated(-pos->x_angel, 1., 0, 0);
        glTranslatef(-pos->x, -pos->y, -pos->z);
    }
    
    void createCylinder(datastruct::CylinderConfig* config, datastruct::Position* pos)
    {
        using namespace datastruct;
        GLUquadricObj* quadratic = gluNewQuadric();;
        glTranslatef(pos->x, pos->y, pos->z);
        glRotated(pos->x_angel, 1., 0, 0);
        glRotated(pos->y_angel, 0, 1., 0);
        glRotated(pos->z_angel, 0, 0, 1.);
        glRotated(90, 1, 0, 0);
        
        glPushMatrix();
        glScaled(config->x_zoom, config->y_zoom, config->z_zoom);
        
        glTranslatef(0, 0, -config->height / 2);
        gluCylinder(quadratic, config->bottom_r, config->top_r, config->height, 50, 50);
        glTranslatef(0, 0, config->height / 2);
        
        // draw a solid unit cylinder
        float res = 0.01f * M_PI;                // resolution (in radians: equivalent to 18 degrees)
        float r = config->top_r;
        float x = r, z = 0.f;                   // initialise x and z on right of cylinder centre
        float t = 0.f;                          // initialise angle as 0
        // top
        glTranslatef(0, 0, config->height / 2);
        glRotated(-90, 1., 0, 0);
        glBegin(GL_POLYGON);
        do{
            glVertex3f(x, 0.f, z);    // top
            t += res;               // add increment to angle
            x = r * cos(t);           // move x and z around circle
            z = r * sin(t);
        } while (t <= 2 * M_PI);
        glEnd();
        glRotated(90., 1., 0, 0);
        glTranslatef(0, 0, -config->height / 2);

        // bottom
        r = config->bottom_r;
        x = r, z = 0.f;
        t = 0.f;
        glTranslatef(0, 0, -config->height / 2);
        glRotated(90, 1., 0, 0);
        glBegin(GL_POLYGON);
        do{
            glVertex3f(x, 0.f, z);    // top
            t += res;               // add increment to angle
            x = r * cos(t);           // move x and z around circle
            z = r * sin(t);
        } while (t <= 2 * M_PI);
        glEnd();
        glRotated(-90, 1., 0, 0);
        
        glTranslatef(0, 0, config->height / 2);
        glPopMatrix();
        
        glRotated(-90, 1, 0, 0);
        glRotated(-pos->z_angel, 0, 0, 1.);
        glRotated(-pos->y_angel, 0, 1., 0);
        glRotated(-pos->x_angel, 1., 0, 0);
        glTranslatef(-pos->x, -pos->y, -pos->z);
    }
};
