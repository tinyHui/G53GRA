//
//  Clock.cpp
//  G53GRA
//
//  Created by Jason Chen on 3/26/15.
//  Copyright (c) 2015 NottinghamUniversity. All rights reserved.
//

#include <ctime>
#include "TextureManager.h"
#include "Environment.h"
#include "Clock.h"

using namespace time_clock;

Clock::Clock(datastruct::Position* pos) : pos(pos)
{
    texture_manager = new TextureManager();
    
    clock_box = new GLuint[6];
    clock_box[0] = texture_manager->loadImage("img/clock.bmp");
    clock_box[1] = NULL;
    clock_box[2] = NULL;
    clock_box[3] = NULL;
    clock_box[4] = NULL;
    clock_box[5] = NULL;

    // clock base
    cb_config.width = R;
    cb_config.depth = BASE_THICK;
    cb_config.height = R;
    cb_pos.x = 0;
    cb_pos.y = 0;
    cb_pos.z = 0;
    
    // hour hand
    h_hand_config.width = HAND_HM_WIDHT;
    h_hand_config.height = HAND_HOUR_LENGTH;
    h_hand_config.depth = HAND_THICK;
    h_hand_pos.y = HAND_HOUR_LENGTH / 2 - HAND_OFFSET;
    h_hand_pos.z = HAND_THICK + HAND_GAP;
    h_hand_pos.y_piv = - HAND_HOUR_LENGTH / 2 + HAND_OFFSET;
    h_hand_pos.z_angle = 0;
    
    // minute hand
    m_hand_config.width = HAND_HM_WIDHT;
    m_hand_config.height = HAND_MIN_LENGTH;
    m_hand_config.depth = HAND_THICK;
    m_hand_pos.y = HAND_MIN_LENGTH / 2 - HAND_OFFSET;
    m_hand_pos.z = h_hand_pos.z + HAND_THICK + HAND_GAP;
    m_hand_pos.y_piv = - HAND_MIN_LENGTH / 2 + HAND_OFFSET;
    m_hand_pos.z_angle = 0;
    
    // second hand
    s_hand_config.width = HAND_SEC_WIDHT;
    s_hand_config.height = HAND_SEC_LENGTH;
    s_hand_config.depth = HAND_THICK;
    s_hand_pos.y = HAND_SEC_LENGTH / 2 - HAND_OFFSET;
    s_hand_pos.z = s_hand_pos.z + HAND_THICK + HAND_GAP;
    s_hand_pos.y_piv = - HAND_SEC_LENGTH / 2 + HAND_OFFSET;
    s_hand_pos.z_angle = 0;
}

void Clock::Draw()
{   
    glPushMatrix();
    glTranslatef(pos->x, pos->y, pos->z);
    glRotatef(pos->z_angle, 0.f, 0.f, 1.f);
    glRotatef(pos->y_angle, 0.f, 1.f, 0.f);
    glRotatef(pos->x_angle, 1.f, 0.f, 0.f);
    createSquare(cb_config, cb_pos, clock_box);
    glPushAttrib(GL_ALL_ATTRIB_BITS);
    glColor3f(0.f, 0.f, 0.f);
    createSquare(h_hand_config, h_hand_pos);
    createSquare(m_hand_config, m_hand_pos);
    createSquare(s_hand_config, s_hand_pos);
    glPopAttrib();
    glPopMatrix();
}

void Clock::Update(const double& deltaTime)
{
    time( &current_time );                   // Get the current time
    local_time = localtime( &current_time );  // Convert the current time to the local time
    float hour   = local_time->tm_hour < 12 ? local_time->tm_hour : local_time->tm_hour - 12;
    float min    = local_time->tm_min;
    float sec    = local_time->tm_sec;
    
    float hour_angle = hour / 12.f * 360.f;
    float min_angle = min / 60.f * 360.f;
    float sec_angle = sec / 60.f * 360.f;
    
    h_hand_pos.z_angle = -hour_angle;
    m_hand_pos.z_angle = -min_angle;
    s_hand_pos.z_angle = -sec_angle;
}

void Clock::HandleKey(int key, int state, int x, int y)
{
    
}
