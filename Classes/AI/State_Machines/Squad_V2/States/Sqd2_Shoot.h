#ifndef SQD2_SHOOT_H
#define SQD2_SHOOT_H

#include "../../Default/States/State.h"
#include "../Transitions/Sqd2_ShootToAttack.h"

#include "../../../Actions/Act_Fire.h"

class Sqd2_Shoot : public State
{
    public:
        Sqd2_Shoot();

        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif

