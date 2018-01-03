#ifndef RAND4_SHOOT_H
#define RAND4_SHOOT_H

#include "../../Default/States/State.h"
#include "../Transitions/Rand4_ShootToAttack.h"

#include "../../../Actions/Act_Fire.h"

class Rand4_Shoot : public State
{
    public:
        Rand4_Shoot();

        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif

