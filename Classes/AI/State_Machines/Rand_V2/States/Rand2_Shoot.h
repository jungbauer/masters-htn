#ifndef RAND2_SHOOT_H
#define RAND2_SHOOT_H

#include "../../Default/States/State.h"
#include "../Transitions/Rand2_ShootToAttack.h"

#include "../../../Actions/Act_Fire.h"

class Rand2_Shoot : public State
{
    public:
        Rand2_Shoot();

        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif

