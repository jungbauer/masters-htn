#ifndef BULLET_H
#define BULLET_H

#include <cmath>

#include "Utils/Constants.h"
#include "Utils/VecXY_Float.h"

class Bullet {
	public:
        Bullet(VecXY_Float pos, float angle, int tm, int ai_ID, int id);
        VecXY_Float getNextPosition(unsigned int deltaTicks);
        void set_Position(VecXY_Float pos);
        VecXY_Float get_Position();
        VecXY_Float get_Previous_position();
        float get_Radius();
        float get_Orientation();
        float get_Speed();
        float get_Damage();
        int get_Team();
        int get_Agent_ID();
        int get_Bullet_ID();

    private:
        VecXY_Float position;
        VecXY_Float previous_position;
        float speed;
        float orientation;
        float radius;
        float damage;
        int team;
        int agent_ID;
        int bullet_ID;
};

#endif


