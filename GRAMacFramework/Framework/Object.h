
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
        float half_width = config->width / 2.;
        float half_depth = config->depth / 2.;
        float half_height = config->height / 2.;
        
        Vertice* v1 = new Vertice(- half_width, half_height, half_depth, nullptr );
        Vertice* v2 = new Vertice(half_width, half_height, half_depth, v1 );
        Vertice* v3 = new Vertice(half_width, half_height, -half_depth, v2 );
        Vertice* v4 = new Vertice(- half_width, half_height, -half_depth, v3 );
        
        Vertice* v5 = new Vertice(- half_width, -half_height, half_depth, nullptr );
        Vertice* v6 = new Vertice(half_width, -half_height, half_depth, v5 );
        Vertice* v7 = new Vertice(half_width, -half_height, -half_depth, v6 );
        Vertice* v8 = new Vertice(- half_width, -half_height, -half_depth, v7 );
        
        createTruncated(v8, v4, pos);
    }
    
    
    void createTruncated(datastruct::Vertice* bv, datastruct::Vertice *tv, datastruct::Position* pos)
    {
        using namespace datastruct;
//        glColor3f(color.r, color.g, color.b);
        
        int vertice_num = 0;
        
        glTranslatef(pos->x, pos->y, pos->z);
        glRotatef(pos->x_angel, 1.f, 0.f, 0.f);
        glRotatef(pos->y_angel, 0.f, 1.f, 0.f);
        glRotatef(pos->z_angel, 0.f, 0.f, 1.f);
        
        // top
        Vertice* draw_tv = tv;
        glBegin(GL_LINE_LOOP);
        while (draw_tv != nullptr) {
            glVertex3d(draw_tv->x, draw_tv->y, draw_tv->z);
            draw_tv = draw_tv->next;
            vertice_num++;
        }
        glEnd();
        
        // bottom
        Vertice* draw_bv = bv;
        glBegin(GL_LINE_LOOP);
        while (draw_bv != nullptr) {
            glVertex3d(draw_bv->x, draw_bv->y, draw_bv->z);
            draw_bv = draw_bv->next;
        }
        glEnd();
        
        // side
        Vertice* draw_v1 = tv;
        Vertice* draw_v2 = draw_v1->next;
        Vertice* draw_v4 = bv;
        Vertice* draw_v3 = draw_v4->next;
        for (int i = 0; i < vertice_num; i++) {
            glBegin(GL_LINE_LOOP);
            glVertex3d(draw_v1->x, draw_v1->y, draw_v1->z);
            glVertex3d(draw_v2->x, draw_v2->y, draw_v2->z);
            glVertex3d(draw_v3->x, draw_v3->y, draw_v3->z);
            glVertex3d(draw_v4->x, draw_v4->y, draw_v4->z);
            glEnd();
            
            draw_v1 = draw_v2;
            draw_v4 = draw_v3;
            if (i < vertice_num - 2) {
                draw_v2 = draw_v1->next;
                draw_v3 = draw_v4->next;
            } else {
                draw_v2 = tv;
                draw_v3 = bv;
            }
        }
        
        glRotatef(-pos->z_angel, 0.f, 0.f, 1.f);
        glRotatef(-pos->y_angel, 0.f, 1.f, 0.f);
        glRotatef(-pos->x_angel, 1.f, 0.f, 0.f);
        glTranslatef(-pos->x, -pos->y, -pos->z);
    }
};
