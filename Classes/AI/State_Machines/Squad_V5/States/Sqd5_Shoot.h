#ifndef SQD5_SHOOT_H
#define SQD5_SHOOT_H

#include "../../Default/States/State.h"
#include "../Transitions/Sqd5_ShootToAttack.h"

#include "../../../Actions/Act_Fire.h"

class Sqd5_Shoot : public State
{
    public:
        Sqd5_Shoot();

        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif

