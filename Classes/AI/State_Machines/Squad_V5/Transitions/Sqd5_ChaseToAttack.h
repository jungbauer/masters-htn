#ifndef SQD5_CHASETOATTACK_H
#define SQD5_CHASETOATTACK_H

#include "../../Default/Transitions/Transition.h"

class Sqd5_ChaseToAttack : public Transition
{
    public:
        Sqd5_ChaseToAttack();
        bool isTriggered(AI_Info &info);
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
