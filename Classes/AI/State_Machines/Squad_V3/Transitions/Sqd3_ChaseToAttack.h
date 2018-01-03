#ifndef SQD3_CHASETOATTACK_H
#define SQD3_CHASETOATTACK_H

#include "../../Default/Transitions/Transition.h"

class Sqd3_ChaseToAttack : public Transition
{
    public:
        Sqd3_ChaseToAttack();
        bool isTriggered(AI_Info &info);
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
