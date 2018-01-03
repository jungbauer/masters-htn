#ifndef SQD4_CHASETOATTACK_H
#define SQD4_CHASETOATTACK_H

#include "../../Default/Transitions/Transition.h"

class Sqd4_ChaseToAttack : public Transition
{
    public:
        Sqd4_ChaseToAttack();
        bool isTriggered(AI_Info &info);
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
