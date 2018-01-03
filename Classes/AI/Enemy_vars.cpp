#include "Enemy_vars.h"

Enemy_vars::Enemy_vars(VecXY_Float startPos, float orient, int tm, int ID, float heal):
        current_position(startPos),
        orientation(orient),
        agent_ID(ID),
        team(tm),
        health(heal),
        alive(true)
{
//    current_position = startPos;
//    orientation = orient;
//    agent_ID = ID;
//
//    team = tm;
//    health = heal;
//    alive = true;
}

Enemy_vars::Enemy_vars():
        current_position(VecXY_Float(-1,-1)),
        orientation(0),
        agent_ID(-1),
        team(-1),
        health(-1),
        alive(false)
{
//    current_position = VecXY_Float(-1,-1);
//    orientation = 0;
//    agent_ID = -1;
//
//    team = -1;
//    health = -1;
//    alive = false;
}
