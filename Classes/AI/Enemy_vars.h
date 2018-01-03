#ifndef ENEMY_VARS_H
#define ENEMY_VARS_H

#include "../Utils/VecXY_Float.h"

/// AI Class
class Enemy_vars {
	public:
        Enemy_vars(VecXY_Float startPos, float orient, int tm, int ID, float heal);
        Enemy_vars();

        VecXY_Float current_position;
        float orientation;  // Facing in degrees

        int agent_ID;   //unique ID reference for agent

        int team;
        float health;
        bool alive;

        //methods---------------------------


    private:

};

#endif


