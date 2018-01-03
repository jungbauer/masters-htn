#ifndef SQD4_SHOOT_H
#define SQD4_SHOOT_H

#include "../../Default/States/State.h"
#include "../Transitions/Sqd4_ShootToAttack.h"

#include "../../../Actions/Act_Fire.h"

class Sqd4_Shoot : public State
{
    public:
        Sqd4_Shoot();

        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif

