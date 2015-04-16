//
//  Dog.cpp
//  G53GRA
//
//  Created by Jason Chen on 4/12/15.
//  Copyright (c) 2015 NottinghamUniversity. All rights reserved.
//

#include <stdlib.h>
#include <math.h>
#include "Environment.h"
#include "Dog.h"

using namespace dog;


Dog::Dog(Position* pos)
    : pos(pos)
{
    unsigned int time_ui = int( time(NULL) );
    srand(time_ui);
    
    r = 8;
    angle = 0;
    pos->y_angle = 90;
    
    
    x_start = pos->x;
    z_start = pos->z;
    
    bump_stage = 0;
    pos->y += BUMP_RANGE;
    bump_start = pos->y;
    
    leg_stage = 0;
    leg_current_target = LEG_RANGE;
    
    texture_manager = new TextureManager();
    head_box = new GLuint[6];
    head_box[0] = texture_manager->loadImage("img/dog_head_front.bmp");
    head_box[1] = texture_manager->loadImage("img/dog_half_brown.bmp");
    head_box[2] = head_box[1];
    head_box[3] = head_box[1];
    head_box[4] = texture_manager->loadImage("img/dog_brown.bmp");
    head_box[5] = texture_manager->loadImage("img/dog_white.bmp");
    
    brown_box = new GLuint[6];
    brown_box[0] = head_box[4];
    brown_box[1] = head_box[4];
    brown_box[2] = head_box[4];
    brown_box[3] = head_box[4];
    brown_box[4] = head_box[4];
    brown_box[5] = head_box[4];
    
    leg_box = new GLuint[6];
    leg_box[0] = head_box[1];
    leg_box[1] = head_box[1];
    leg_box[2] = head_box[1];
    leg_box[3] = head_box[1];
    leg_box[4] = head_box[4];
    leg_box[5] = head_box[5];
    
    // body
    body_config.width = BODY_WIDTH;
    body_config.height = BODY_HEIGHT;
    body_config.depth = BODY_DEPTH;
    body_pos.y = LEG_HEIGHT + BODY_HEIGHT / 2;
    
    // head
    head_config.width = HEAD_WIDTH;
    head_config.height = HEAD_HEIGHT;
    head_config.depth = HEAD_DEPTH;
    head_pos.y = body_pos.y + body_config.height / 2 + head_config.height / 2 - 1;
    head_pos.z = body_config.depth / 2;
    head_pos.x_angle = -8;
    
    // ear
    ear_config.width = EAR_WIDTH;
    ear_config.height = EAR_HEIGHT;
    ear_config.depth = EAR_DEPTH;
    
    // left ear
    l_ear_pos.x = - head_config.width / 2 - EAR_WIDTH / 2 + EAR_HEIGHT / 2;
    l_ear_pos.y = head_pos.y + head_config.height / 2 - EAR_GAP;
    l_ear_pos.z = head_pos.z;
    l_ear_pos.x_piv = EAR_WIDTH / 2;
    l_ear_pos.z_angle = 60;
    
    // right ear
    r_ear_pos.x = head_config.width / 2 + EAR_WIDTH / 2 - EAR_HEIGHT / 2;
    r_ear_pos.y = l_ear_pos.y;
    r_ear_pos.z = head_pos.z;
    r_ear_pos.x_piv = -EAR_WIDTH / 2;
    r_ear_pos.z_angle = -60;
    
    // nouse
    nouse_config.width = NOUSE_WIDTH;
    nouse_config.height = NOUSE_HEIGHT;
    nouse_config.depth = NOUSE_DEPTH;
    nouse_pos.x = head_pos.x;
    nouse_pos.y = head_pos.y - nouse_config.height / 2;
    nouse_pos.z = head_pos.z + HEAD_DEPTH / 2 + NOUSE_DEPTH / 2;
    
    // tail
    tail_config.width = TAIL_WIDTH;
    tail_config.height = TAIL_HEIGHT;
    tail_config.depth = TAIL_DEPTH;
    tail_pos.y = body_pos.y + BODY_HEIGHT / 2 - TAIL_GAP;
    tail_pos.z = -body_config.depth / 2 - tail_config.depth / 2;
    tail_pos.z_piv = TAIL_DEPTH / 2;
    tail_pos.x_angle = 60;
    
    // leg
    leg_config.width = LEG_WIDTH;
    leg_config.height = LEG_HEIGHT;
    leg_config.depth = LEG_DEPTH;
    
    // left top leg
    lt_leg_pos.x = - body_config.width / 2 + leg_config.width / 2 + LEG_EDGE_X_GAP;
    lt_leg_pos.y = leg_config.height / 2;
    lt_leg_pos.z = body_config.depth / 2 - leg_config.width / 2 - LEG_EDGE_Z_GAP;
    lt_leg_pos.y_piv = leg_config.height / 2;
    
    // right top leg
    rt_leg_pos.x = body_config.width / 2 - leg_config.width / 2 - LEG_EDGE_X_GAP;
    rt_leg_pos.y = leg_config.height / 2;
    rt_leg_pos.z = body_config.depth / 2 - leg_config.width / 2 - LEG_EDGE_Z_GAP;
    rt_leg_pos.y_piv = leg_config.height / 2;
    
    // left bottom leg
    lb_leg_pos.x = - body_config.width / 2 + leg_config.width / 2 + LEG_EDGE_X_GAP;
    lb_leg_pos.y = leg_config.height / 2;
    lb_leg_pos.z = - body_config.depth / 2 + leg_config.width / 2 + LEG_EDGE_Z_GAP;
    lb_leg_pos.y_piv = leg_config.height / 2;
    
    // right bottom leg
    rb_leg_pos.x = body_config.width / 2 - leg_config.width / 2 - LEG_EDGE_X_GAP;
    rb_leg_pos.y = leg_config.height / 2;
    rb_leg_pos.z = - body_config.depth / 2 + leg_config.width / 2 + LEG_EDGE_Z_GAP;
    rb_leg_pos.y_piv = leg_config.height / 2;
}

void Dog::Draw()
{
//    SquareConfig a;
//    a.width = width_range;
//    a.height = 10;
//    a.depth = depth_range;
//    Position b;
//    b.x = 0;
//    b.y = 0;
//    b.z = 0;
    
    // Draw
    glPushMatrix();
    glTranslatef(pos->x, pos->y, pos->z);
    glRotatef(pos->z_angle, 0.f, 0.f, 1.f);
    glRotatef(pos->y_angle, 0.f, 1.f, 0.f);
    glRotatef(pos->x_angle, 1.f, 0.f, 0.f);
    
    nouse_pos.x_angle = head_pos.x_angle;
    l_ear_pos.x_angle = head_pos.x_angle;
    r_ear_pos.x_angle = head_pos.x_angle;
    
//    glPushAttrib(GL_ALL_ATTRIB_BITS);
//    glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
//    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
//    glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
//    glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
    createSquare(head_config, head_pos, head_box);
    createSquare(ear_config, l_ear_pos, brown_box);
    createSquare(ear_config, r_ear_pos, brown_box);
    glPushAttrib(GL_ALL_ATTRIB_BITS);
    glColor3f(0.f, 0.f, 0.f);
    createSquare(nouse_config, nouse_pos);
    glPopAttrib();
    createSquare(body_config, body_pos, brown_box);
    createSquare(tail_config, tail_pos, brown_box);
    createSquare(leg_config, lt_leg_pos, leg_box);
    createSquare(leg_config, rt_leg_pos, leg_box);
    createSquare(leg_config, lb_leg_pos, leg_box);
    createSquare(leg_config, rb_leg_pos, leg_box);
    
//    createSquare(a, b);
    
//    glPopAttrib();
    
    glPopMatrix();
}

void Dog::Update( const double& deltaTime )
{
    // dump
    if (pos->y - bump_start <= -BUMP_RANGE) {
        bump_stage = 0;
    } else if (pos->y - bump_start >= BUMP_RANGE) {
        bump_stage = 1;
    }
    
    switch (bump_stage) {
        case 0:
            pos->x_angle += BODY_SPEED;
            l_ear_pos.z_angle += EAR_SPEED;
            r_ear_pos.z_angle -= EAR_SPEED;
            tail_pos.y_angle += TAIL_SPEED;
            pos->y += BUMP_SPEED;
            break;
        case 1:
            pos->x_angle -= BODY_SPEED;
            l_ear_pos.z_angle -= EAR_SPEED;
            r_ear_pos.z_angle += EAR_SPEED;
            tail_pos.y_angle -= TAIL_SPEED;
            pos->y -= BUMP_SPEED;
            break;
        default:
            break;
    }
    
    // leg swing
    if (lt_leg_pos.x_angle <= -LEG_RANGE) {
        leg_stage = 0;
    } else if (lt_leg_pos.x_angle >= LEG_RANGE) {
        leg_stage = 1;
    }
    
    switch (leg_stage) {
        case 0:
            head_pos.x_angle += HEAD_SPEED;
            lt_leg_pos.x_angle += LEG_SPEED;
            rt_leg_pos.x_angle += LEG_SPEED;
            lb_leg_pos.x_angle -= LEG_SPEED;
            rb_leg_pos.x_angle -= LEG_SPEED;
            break;
        case 1:
            head_pos.x_angle -= HEAD_SPEED;
            lt_leg_pos.x_angle -= LEG_SPEED;
            rt_leg_pos.x_angle -= LEG_SPEED;
            lb_leg_pos.x_angle += LEG_SPEED;
            rb_leg_pos.x_angle += LEG_SPEED;
            break;
        default:
            break;
    }
    
    // move
    pos->y_angle = 90 + angle;
    if (angle == 360) {
        angle = 0;
        pos->y_angle = 90;
    }
    pos->x = x_start + r * sin(angle*M_PI/180);
    pos->z = z_start + r * cos(angle*M_PI/180);
    
    angle += 5 + float(rand()) / float(RAND_MAX) * 0.5 * (float(rand()) / float(RAND_MAX) > 0.5 ? -1 : 1);
    x_start += float(rand()) / float(RAND_MAX) * 0.15 * (float(rand()) / float(RAND_MAX) > 0.5 ? -1 : 1);
    z_start += float(rand()) / float(RAND_MAX) * 0.1 * (float(rand()) / float(RAND_MAX) > 0.5 ? -1 : 1);
    r += float(rand()) / float(RAND_MAX) * 0.2 * (float(rand()) / float(RAND_MAX) > 0.5 ? -1 : 1);
}

void Dog::HandleKey(int key, int state, int x, int y)
{
}