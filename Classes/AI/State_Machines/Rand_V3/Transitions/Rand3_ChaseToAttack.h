#ifndef RAND3_CHASETOATTACK_H
#define RAND3_CHASETOATTACK_H

#include "../../Default/Transitions/Transition.h"

class Rand3_ChaseToAttack : public Transition
{
    public:
        Rand3_ChaseToAttack();
        bool isTriggered(AI_Info &info);
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
