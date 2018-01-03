#ifndef RAND2_CLOSETOATTACK_H
#define RAND2_CLOSETOATTACK_H

#include "../../Default/Transitions/Transition.h"

class Rand2_CloseToAttack : public Transition
{
    public:
        Rand2_CloseToAttack();
        bool isTriggered(AI_Info &info);
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
