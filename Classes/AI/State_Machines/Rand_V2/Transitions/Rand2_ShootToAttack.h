#ifndef RAND2_SHOOTTOATTACK_H
#define RAND2_SHOOTTOATTACK_H

#include "../../Default/Transitions/Transition.h"

class Rand2_ShootToAttack : public Transition
{
    public:
        Rand2_ShootToAttack();
        bool isTriggered(AI_Info &info);
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif

