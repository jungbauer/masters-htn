#ifndef HTN_SHOOT_H
#define HTN_SHOOT_H

#include "../../Default/States/State.h"
#include "../Transitions/Htn_ShootToAttack.h"

#include "../../../Actions/Act_Fire.h"

class Htn_Shoot : public State
{
    public:
        Htn_Shoot();

        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif

