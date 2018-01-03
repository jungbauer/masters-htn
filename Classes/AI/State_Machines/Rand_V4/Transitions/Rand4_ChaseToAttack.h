#ifndef RAND4_CHASETOATTACK_H
#define RAND4_CHASETOATTACK_H

#include "../../Default/Transitions/Transition.h"

class Rand4_ChaseToAttack : public Transition
{
    public:
        Rand4_ChaseToAttack();
        bool isTriggered(AI_Info &info);
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
