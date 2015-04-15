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


Dog::Dog(Position* pos) : pos(pos)
{
    unsigned int time_ui = int( time(NULL) );
    srand(time_ui);
    
    x_start = pos->x;
    z_start = pos->z;
    walk_end = true;
    
    dump_stage = 0;
    dump_start = pos->y;
    
    leg_stage = 0;
    leg_current_target = LEG_RANGE;
    
    texture_manager = new TextureManager();
    
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
    head_pos.x_angel = -8;
    
    // ear
    ear_config.width = EAR_WIDTH;
    ear_config.height = EAR_HEIGHT;
    ear_config.depth = EAR_DEPTH;
    
    // left ear
    l_ear_pos.x = - head_config.width / 2 - EAR_WIDTH / 2 + EAR_HEIGHT / 2;
    l_ear_pos.y = head_pos.y + head_config.height / 2 - EAR_GAP;
    l_ear_pos.z = head_pos.z;
    l_ear_pos.x_piv = EAR_WIDTH / 2;
    l_ear_pos.z_angel = 60;
    
    // right ear
    r_ear_pos.x = head_config.width / 2 + EAR_WIDTH / 2 - EAR_HEIGHT / 2;
    r_ear_pos.y = l_ear_pos.y;
    r_ear_pos.z = head_pos.z;
    r_ear_pos.x_piv = -EAR_WIDTH / 2;
    r_ear_pos.z_angel = -60;
    
    // nouse
    nouse_config.width = NOUSE_WIDTH;
    nouse_config.height = NOUSE_HEIGHT;
    nouse_config.depth = NOUSE_DEPTH;
    nouse_pos.x = head_pos.x;
    nouse_pos.y = head_pos.y;
    nouse_pos.z = head_pos.z + HEAD_DEPTH / 2 + NOUSE_DEPTH / 2;
    
    // tail
    tail_config.width = TAIL_WIDTH;
    tail_config.height = TAIL_HEIGHT;
    tail_config.depth = TAIL_DEPTH;
    tail_pos.y = body_pos.y + BODY_HEIGHT / 2 - TAIL_GAP;
    tail_pos.z = -body_config.depth / 2 - tail_config.depth / 2;
    tail_pos.z_piv = TAIL_DEPTH / 2;
    tail_pos.x_angel = 60;
    
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
    // Draw
    glPushMatrix();
    glTranslatef(pos->x, pos->y, pos->z);
    glRotatef(pos->z_angel, 0.f, 0.f, 1.f);
    glRotatef(pos->y_angel, 0.f, 1.f, 0.f);
    glRotatef(pos->x_angel, 1.f, 0.f, 0.f);
    
    nouse_pos.x_angel = head_pos.x_angel;
    l_ear_pos.x_angel = head_pos.x_angel;
    r_ear_pos.x_angel = head_pos.x_angel;
    
//    glPushAttrib(GL_ALL_ATTRIB_BITS);
//    glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
//    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
//    glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
//    glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
    createSquare(head_config, head_pos);
    createSquare(ear_config, l_ear_pos);
    createSquare(ear_config, r_ear_pos);
    createSquare(nouse_config, nouse_pos);
    createSquare(body_config, body_pos);
    createSquare(tail_config, tail_pos);
    createSquare(leg_config, lt_leg_pos);
    createSquare(leg_config, rt_leg_pos);
    createSquare(leg_config, lb_leg_pos);
    createSquare(leg_config, rb_leg_pos);
//    glPopAttrib();
    
    glPopMatrix();
}

void Dog::Update( const double& deltaTime )
{
    // dump
    if (pos->y - dump_start <= -DUMP_RANGE) {
        dump_stage = 0;
    } else if (pos->y - dump_start >= DUMP_RANGE) {
        dump_stage = 1;
    }
    
    switch (dump_stage) {
        case 0:
            pos->x_angel += BODY_SPEED;
            l_ear_pos.z_angel += EAR_SPEED;
            r_ear_pos.z_angel -= EAR_SPEED;
            tail_pos.y_angel += TAIL_SPEED;
            pos->y += DUMP_SPEED;
            break;
        case 1:
            pos->x_angel -= BODY_SPEED;
            l_ear_pos.z_angel -= EAR_SPEED;
            r_ear_pos.z_angel += EAR_SPEED;
            tail_pos.y_angel -= TAIL_SPEED;
            pos->y -= DUMP_SPEED;
            break;
        default:
            break;
    }
    
    // leg swing
    if (lt_leg_pos.x_angel <= -LEG_RANGE) {
        leg_stage = 0;
    } else if (lt_leg_pos.x_angel >= LEG_RANGE) {
        leg_stage = 1;
    }
    
    switch (leg_stage) {
        case 0:
            head_pos.x_angel += HEAD_SPEED;
            lt_leg_pos.x_angel += LEG_SPEED;
            rt_leg_pos.x_angel -= LEG_SPEED;
            lb_leg_pos.x_angel -= LEG_SPEED;
            rb_leg_pos.x_angel += LEG_SPEED;
            break;
        case 1:
            head_pos.x_angel -= HEAD_SPEED;
            lt_leg_pos.x_angel -= LEG_SPEED;
            rt_leg_pos.x_angel += LEG_SPEED;
            lb_leg_pos.x_angel += LEG_SPEED;
            rb_leg_pos.x_angel -= LEG_SPEED;
            break;
        default:
            break;
    }
    
    // move
    if (walk_end) {
        if (pos->x - x_start > WALK_OFFSET_LIM) {
            pos->y_angel = -90;
        } else if (pos->z - z_start > WALK_OFFSET_LIM) {
            pos->y_angel = 180;
        } else if (pos->x - x_start < -WALK_OFFSET_LIM) {
            pos->y_angel = 90;
        } else if (pos->z - z_start < -WALK_OFFSET_LIM) {
            pos->y_angel = 0;
        } else {
            pos->y_angel = float(rand()) / float(RAND_MAX) * 360.f;
        }
        walk_range = WALK_DIST_MIN + float(rand()) / float(RAND_MAX) * float(WALK_DIST_MAX - WALK_DIST_MIN);
        walk_end = false;
    }
    
    pos->x += WALK_SPEED * sin(pos->y_angel*M_PI/180);
    pos->z += WALK_SPEED * cos(pos->y_angel*M_PI/180);
    
    walk_range -= WALK_SPEED;
    walk_end = walk_range < 0;
}

void Dog::HandleKey(int key, int state, int x, int y)
{
}