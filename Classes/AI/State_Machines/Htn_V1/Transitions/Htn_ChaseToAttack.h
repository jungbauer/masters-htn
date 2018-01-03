#ifndef HTN_CHASETOATTACK_H
#define HTN_CHASETOATTACK_H

#include "../../Default/Transitions/Transition.h"

class Htn_ChaseToAttack : public Transition
{
    public:
    Htn_ChaseToAttack();
        bool isTriggered(AI_Info &info);
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
