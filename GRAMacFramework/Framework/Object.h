
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
    
    void createSquare(datastruct::SquareConfig config, datastruct::Position pos, GLuint* texids=nullptr, bool inverse=false)
    {
        using namespace datastruct;
        
        bool have_texture = texids != nullptr;
        
        if (!inverse) {
            glPushMatrix();
            glTranslatef(pos.x + pos.x_piv, pos.y + pos.y_piv, pos.z + pos.z_piv);
            glRotated(pos.x_angel, 1., 0, 0);
            glRotated(pos.y_angel, 0, 1., 0);
            glRotated(pos.z_angel, 0, 0, 1.);
            glTranslatef(-pos.x_piv, -pos.y_piv, -pos.z_piv);
            glScalef(config.width, config.height, config.depth);
            
            // Front Face
            if (have_texture && texids[0]) {
                glEnable(GL_TEXTURE_2D);
                glBindTexture(GL_TEXTURE_2D, texids[0]);
            }
            glBegin(GL_QUADS);
            glNormal3f(0.f, 0.f, 1.f);
            if (have_texture && texids[0]) glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.5f, -0.5f,  0.5f);  // Bottom Left Of The Texture and Quad
            if (have_texture && texids[0]) glTexCoord2f(1.0f, 0.0f); glVertex3f( 0.5f, -0.5f,  0.5f);  // Bottom Right Of The Texture and Quad
            if (have_texture && texids[0]) glTexCoord2f(1.0f, 1.0f); glVertex3f( 0.5f,  0.5f,  0.5f);  // Top Right Of The Texture and Quad
            if (have_texture && texids[0]) glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.5f,  0.5f,  0.5f);  // Top Left Of The Texture and Quad
            glEnd();
            if (have_texture && texids[0]) glDisable(GL_TEXTURE_2D);
                
            // Back Face
            if (have_texture && texids[1]) {
                glBindTexture(GL_TEXTURE_2D, texids[1]);
                glEnable(GL_TEXTURE_2D);
            }
            glBegin(GL_QUADS);
            glNormal3f(0.f, 0.f, -1.f);
            if (have_texture && texids[1]) glTexCoord2f(1.0f, 0.0f); glVertex3f(-0.5f, -0.5f, -0.5f);  // Bottom Right Of The Texture and Quad
            if (have_texture && texids[1]) glTexCoord2f(1.0f, 1.0f); glVertex3f(-0.5f,  0.5f, -0.5f);  // Top Right Of The Texture and Quad
            if (have_texture && texids[1]) glTexCoord2f(0.0f, 1.0f); glVertex3f( 0.5f,  0.5f, -0.5f);  // Top Left Of The Texture and Quad
            if (have_texture && texids[1]) glTexCoord2f(0.0f, 0.0f); glVertex3f( 0.5f, -0.5f, -0.5f);  // Bottom Left Of The Texture and Quad
            glEnd();
            if (have_texture && texids[1]) glDisable(GL_TEXTURE_2D);
            
            // Top Face
            if (have_texture && texids[4]) {
                glBindTexture(GL_TEXTURE_2D, texids[4]);
                glEnable(GL_TEXTURE_2D);
            }
            glBegin(GL_QUADS);
            glNormal3f(0.f, 1.f, 0.f);
            if (have_texture && texids[4]) glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.5f,  0.5f, -0.5f);  // Top Left Of The Texture and Quad
            if (have_texture && texids[4]) glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.5f,  0.5f,  0.5f);  // Bottom Left Of The Texture and Quad
            if (have_texture && texids[4]) glTexCoord2f(1.0f, 0.0f); glVertex3f( 0.5f,  0.5f,  0.5f);  // Bottom Right Of The Texture and Quad
            if (have_texture && texids[4]) glTexCoord2f(1.0f, 1.0f); glVertex3f( 0.5f,  0.5f, -0.5f);  // Top Right Of The Texture and Quad
            glEnd();
            if (have_texture && texids[4]) glDisable(GL_TEXTURE_2D);
        
            // Bottom Face
            if (have_texture && texids[5]) {
                glBindTexture(GL_TEXTURE_2D, texids[5]);
                glEnable(GL_TEXTURE_2D);
            }
            glBegin(GL_QUADS);
            glNormal3f(0.f, -1.f, 0.f);
            if (have_texture && texids[5]) glTexCoord2f(1.0f, 1.0f); glVertex3f(-0.5f, -0.5f, -0.5f);  // Top Right Of The Texture and Quad
            if (have_texture && texids[5]) glTexCoord2f(0.0f, 1.0f); glVertex3f( 0.5f, -0.5f, -0.5f);  // Top Left Of The Texture and Quad
            if (have_texture && texids[5]) glTexCoord2f(0.0f, 0.0f); glVertex3f( 0.5f, -0.5f,  0.5f);  // Bottom Left Of The Texture and Quad
            if (have_texture && texids[5]) glTexCoord2f(1.0f, 0.0f); glVertex3f(-0.5f, -0.5f,  0.5f);  // Bottom Right Of The Texture and Quad
            glEnd();
            if (have_texture && texids[5]) glDisable(GL_TEXTURE_2D);
            
            // Right face
            if (have_texture && texids[3]) {
                glBindTexture(GL_TEXTURE_2D, texids[3]);
                glEnable(GL_TEXTURE_2D);
            }
            glBegin(GL_QUADS);
            glNormal3f(1.f, 0.f, 0.f);
            if (have_texture && texids[3]) glTexCoord2f(1.0f, 0.0f); glVertex3f( 0.5f, -0.5f, -0.5f);  // Bottom Right Of The Texture and Quad
            if (have_texture && texids[3]) glTexCoord2f(1.0f, 1.0f); glVertex3f( 0.5f,  0.5f, -0.5f);  // Top Right Of The Texture and Quad
            if (have_texture && texids[3]) glTexCoord2f(0.0f, 1.0f); glVertex3f( 0.5f,  0.5f,  0.5f);  // Top Left Of The Texture and Quad
            if (have_texture && texids[3]) glTexCoord2f(0.0f, 0.0f); glVertex3f( 0.5f, -0.5f,  0.5f);  // Bottom Left Of The Texture and Quad
            glEnd();
            if (have_texture && texids[3]) glDisable(GL_TEXTURE_2D);
            
            // Left Face
            if (have_texture && texids[2]) {
                glBindTexture(GL_TEXTURE_2D, texids[2]);
                glEnable(GL_TEXTURE_2D);
            }
            glBegin(GL_QUADS);
            glNormal3f(-1.f, 0.f, 0.f);
            if (have_texture && texids[2]) glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.5f, -0.5f, -0.5f);  // Bottom Left Of The Texture and Quad
            if (have_texture && texids[2]) glTexCoord2f(1.0f, 0.0f); glVertex3f(-0.5f, -0.5f,  0.5f);  // Bottom Right Of The Texture and Quad
            if (have_texture && texids[2]) glTexCoord2f(1.0f, 1.0f); glVertex3f(-0.5f,  0.5f,  0.5f);  // Top Right Of The Texture and Quad
            if (have_texture && texids[2]) glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.5f,  0.5f, -0.5f);  // Top Left Of The Texture and Quad
            glEnd();
            if (have_texture && texids[2]) glDisable(GL_TEXTURE_2D);
            
            glPopMatrix();
        } else {
            glPushMatrix();
            glTranslatef(pos.x + pos.x_piv, pos.y + pos.y_piv, pos.z + pos.z_piv);
            glRotated(pos.x_angel, 1., 0, 0);
            glRotated(pos.y_angel, 0, 1., 0);
            glRotated(pos.z_angel, 0, 0, 1.);
            glTranslatef(-pos.x_piv, -pos.y_piv, -pos.z_piv);
            glScalef(config.width, config.height, config.depth);
            
            // Front Face
            if (have_texture && texids[0]) {
                glEnable(GL_TEXTURE_2D);
                glBindTexture(GL_TEXTURE_2D, texids[0]);
            }
            glBegin(GL_QUADS);
            glNormal3f(0.f, 0.f, 1.f);
            if (have_texture && texids[0]) glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.5f,  0.5f,  0.5f);  // Top Left Of The Texture and Quad
            if (have_texture && texids[0]) glTexCoord2f(1.0f, 1.0f); glVertex3f( 0.5f,  0.5f,  0.5f);  // Top Right Of The Texture and Quad
            if (have_texture && texids[0]) glTexCoord2f(1.0f, 0.0f); glVertex3f( 0.5f, -0.5f,  0.5f);  // Bottom Right Of The Texture and Quad
            if (have_texture && texids[0]) glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.5f, -0.5f,  0.5f);  // Bottom Left Of The Texture and Quad
            glEnd();
            if (have_texture && texids[0]) glDisable(GL_TEXTURE_2D);
            
            // Back Face
            if (have_texture && texids[1]) {
                glBindTexture(GL_TEXTURE_2D, texids[1]);
                glEnable(GL_TEXTURE_2D);
            }
            glBegin(GL_QUADS);
            glNormal3f(0.f, 0.f, -1.f);
            if (have_texture && texids[1]) glTexCoord2f(0.0f, 0.0f); glVertex3f( 0.5f, -0.5f, -0.5f);  // Bottom Left Of The Texture and Quad
            if (have_texture && texids[1]) glTexCoord2f(0.0f, 1.0f); glVertex3f( 0.5f,  0.5f, -0.5f);  // Top Left Of The Texture and Quad
            if (have_texture && texids[1]) glTexCoord2f(1.0f, 1.0f); glVertex3f(-0.5f,  0.5f, -0.5f);  // Top Right Of The Texture and Quad
            if (have_texture && texids[1]) glTexCoord2f(1.0f, 0.0f); glVertex3f(-0.5f, -0.5f, -0.5f);  // Bottom Right Of The Texture and Quad
            glEnd();
            if (have_texture && texids[1]) glDisable(GL_TEXTURE_2D);
            
            // Top Face
            if (have_texture && texids[4]) {
                glBindTexture(GL_TEXTURE_2D, texids[4]);
                glEnable(GL_TEXTURE_2D);
            }
            glBegin(GL_QUADS);
            glNormal3f(0.f, 1.f, 0.f);
            if (have_texture && texids[4]) glTexCoord2f(1.0f, 1.0f); glVertex3f( 0.5f,  0.5f, -0.5f);  // Top Right Of The Texture and Quad
            if (have_texture && texids[4]) glTexCoord2f(1.0f, 0.0f); glVertex3f( 0.5f,  0.5f,  0.5f);  // Bottom Right Of The Texture and Quad
            if (have_texture && texids[4]) glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.5f,  0.5f,  0.5f);  // Bottom Left Of The Texture and Quad
            if (have_texture && texids[4]) glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.5f,  0.5f, -0.5f);  // Top Left Of The Texture and Quad
            glEnd();
            if (have_texture && texids[4]) glDisable(GL_TEXTURE_2D);
            
            // Bottom Face
            if (have_texture && texids[5]) {
                glBindTexture(GL_TEXTURE_2D, texids[5]);
                glEnable(GL_TEXTURE_2D);
            }
            glBegin(GL_QUADS);
            glNormal3f(0.f, -1.f, 0.f);
            if (have_texture && texids[5]) glTexCoord2f(1.0f, 0.0f); glVertex3f(-0.5f, -0.5f,  0.5f);  // Bottom Right Of The Texture and Quad
            if (have_texture && texids[5]) glTexCoord2f(0.0f, 0.0f); glVertex3f( 0.5f, -0.5f,  0.5f);  // Bottom Left Of The Texture and Quad
            if (have_texture && texids[5]) glTexCoord2f(0.0f, 1.0f); glVertex3f( 0.5f, -0.5f, -0.5f);  // Top Left Of The Texture and Quad
            if (have_texture && texids[5]) glTexCoord2f(1.0f, 1.0f); glVertex3f(-0.5f, -0.5f, -0.5f);  // Top Right Of The Texture and Quad
            glEnd();
            if (have_texture && texids[5]) glDisable(GL_TEXTURE_2D);
            
            // Right face
            if (have_texture && texids[3]) {
                glBindTexture(GL_TEXTURE_2D, texids[3]);
                glEnable(GL_TEXTURE_2D);
            }
            glBegin(GL_QUADS);
            glNormal3f(1.f, 0.f, 0.f);
            if (have_texture && texids[3]) glTexCoord2f(0.0f, 0.0f); glVertex3f( 0.5f, -0.5f,  0.5f);  // Bottom Left Of The Texture and Quad
            if (have_texture && texids[3]) glTexCoord2f(0.0f, 1.0f); glVertex3f( 0.5f,  0.5f,  0.5f);  // Top Left Of The Texture and Quad
            if (have_texture && texids[3]) glTexCoord2f(1.0f, 1.0f); glVertex3f( 0.5f,  0.5f, -0.5f);  // Top Right Of The Texture and Quad
            if (have_texture && texids[3]) glTexCoord2f(1.0f, 0.0f); glVertex3f( 0.5f, -0.5f, -0.5f);  // Bottom Right Of The Texture and Quad
            glEnd();
            if (have_texture && texids[3]) glDisable(GL_TEXTURE_2D);
            
            // Left Face
            if (have_texture && texids[2]) {
                glBindTexture(GL_TEXTURE_2D, texids[2]);
                glEnable(GL_TEXTURE_2D);
            }
            glBegin(GL_QUADS);
            glNormal3f(-1.f, 0.f, 0.f);
            if (have_texture && texids[2]) glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.5f,  0.5f, -0.5f);  // Top Left Of The Texture and Quad
            if (have_texture && texids[2]) glTexCoord2f(1.0f, 1.0f); glVertex3f(-0.5f,  0.5f,  0.5f);  // Top Right Of The Texture and Quad
            if (have_texture && texids[2]) glTexCoord2f(1.0f, 0.0f); glVertex3f(-0.5f, -0.5f,  0.5f);  // Bottom Right Of The Texture and Quad
            if (have_texture && texids[2]) glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.5f, -0.5f, -0.5f);  // Bottom Left Of The Texture and Quad
            glEnd();
            if (have_texture && texids[2]) glDisable(GL_TEXTURE_2D);
            
            glPopMatrix();
        }
    }
    
    void createCylinder(datastruct::CylinderConfig config, datastruct::Position pos)
    {
        using namespace datastruct;
        GLUquadricObj* quadratic = gluNewQuadric();;
        
        glPushMatrix();
        glTranslatef(pos.x, pos.y, pos.z);
        glRotated(pos.x_angel, 1., 0, 0);
        glRotated(pos.y_angel, 0, 1., 0);
        glRotated(pos.z_angel, 0, 0, 1.);
        glRotated(90, 1, 0, 0);
        glScaled(config.x_zoom, config.y_zoom, config.z_zoom);
        
        glTranslatef(0, 0, -config.height / 2);
        gluCylinder(quadratic, config.bottom_r, config.top_r, config.height, 50, 50);
        glTranslatef(0, 0, config.height / 2);
        
        // draw a solid unit cylinder
        float res = 0.01f * M_PI;                // resolution (in radians: equivalent to 18 degrees)
        float r = config.top_r;
        float x = r, z = 0.f;                   // initialise x and z on right of cylinder centre
        float t = 0.f;                          // initialise angle as 0
        // top
        glTranslatef(0, 0, config.height / 2);
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
        glTranslatef(0, 0, -config.height / 2);

        // bottom
        r = config.bottom_r;
        x = r, z = 0.f;
        t = 0.f;
        glTranslatef(0, 0, -config.height / 2);
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
        
        glTranslatef(0, 0, config.height / 2);
        glPopMatrix();
    }
};
