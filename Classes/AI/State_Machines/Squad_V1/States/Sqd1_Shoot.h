#ifndef SQD1_SHOOT_H
#define SQD1_SHOOT_H

#include "../../Default/States/State.h"
#include "../Transitions/Sqd1_ShootToAttack.h"

#include "../../../Actions/Act_Fire.h"

class Sqd1_Shoot : public State
{
    public:
        Sqd1_Shoot();

        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif

