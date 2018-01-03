#ifndef RAND3_SHOOT_H
#define RAND3_SHOOT_H

#include "../../Default/States/State.h"
#include "../Transitions/Rand3_ShootToAttack.h"

#include "../../../Actions/Act_Fire.h"

class Rand3_Shoot : public State
{
    public:
        Rand3_Shoot();

        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif

