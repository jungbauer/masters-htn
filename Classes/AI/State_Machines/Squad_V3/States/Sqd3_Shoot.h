#ifndef SQD3_SHOOT_H
#define SQD3_SHOOT_H

#include "../../Default/States/State.h"
#include "../Transitions/Sqd3_ShootToAttack.h"

#include "../../../Actions/Act_Fire.h"

class Sqd3_Shoot : public State
{
    public:
        Sqd3_Shoot();

        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif

