#include "Bullet.h"

Bullet::Bullet(VecXY_Float pos, float angle, int tm, int ai_ID, int id):
        position(pos),
        previous_position(pos),
        speed(600),
        orientation(angle),
        radius(2),
        damage(10),
        team(tm),
        agent_ID(ai_ID),
        bullet_ID(id)
{
//    position = pos;
//    previous_position = pos;
//
//    orientation = angle;
//    speed = 600;
//    radius = 2;
//    damage = 10;
//
//    team = tm;
//    agent_ID = ai_ID;
}

VecXY_Float Bullet::getNextPosition(unsigned int deltaTicks)
{
    float x_shift = speed * cos(orientation*constants::PIE/180) * ((float)deltaTicks / 1000.f);
    float y_shift = speed * sin(orientation*constants::PIE/180) * ((float)deltaTicks / 1000.f);

    VecXY_Float nextPos = VecXY_Float(position.getX() + x_shift, position.getY() + y_shift);

    return nextPos;
}

VecXY_Float Bullet::get_Position()
{
    return position;
}

VecXY_Float Bullet::get_Previous_position()
{
    return previous_position;
}

void Bullet::set_Position(VecXY_Float pos)
{
    previous_position = position;
    position = pos;
}

float Bullet::get_Radius()
{
    return radius;
}

float Bullet::get_Orientation()
{
    return orientation;
}

float Bullet::get_Speed()
{
    return speed;
}

float Bullet::get_Damage()
{
    return damage;
}

int Bullet::get_Team()
{
    return team;
}

int Bullet::get_Agent_ID()
{
    return agent_ID;
}

int Bullet::get_Bullet_ID()
{
    return bullet_ID;
}
