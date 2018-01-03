#ifndef DEF_SHOOT_H
#define DEF_SHOOT_H

#include "State.h"
#include "../Transitions/Def_ShootToAttack.h"

#include "../../../Actions/Act_Fire.h"

class Def_Shoot : public State
{
    public:
        Def_Shoot();

        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif

