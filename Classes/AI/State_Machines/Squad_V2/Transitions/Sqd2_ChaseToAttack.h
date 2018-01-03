#ifndef SQD2_CHASETOATTACK_H
#define SQD2_CHASETOATTACK_H

#include "../../Default/Transitions/Transition.h"

class Sqd2_ChaseToAttack : public Transition
{
    public:
        Sqd2_ChaseToAttack();
        bool isTriggered(AI_Info &info);
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
