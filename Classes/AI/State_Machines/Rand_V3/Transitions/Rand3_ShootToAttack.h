#ifndef RAND3_SHOOTTOATTACK_H
#define RAND3_SHOOTTOATTACK_H

#include "../../Default/Transitions/Transition.h"

class Rand3_ShootToAttack : public Transition
{
    public:
        Rand3_ShootToAttack();
        bool isTriggered(AI_Info &info);
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif

