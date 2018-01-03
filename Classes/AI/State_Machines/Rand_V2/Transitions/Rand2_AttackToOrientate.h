#ifndef RAND2_ATTACKTOORIENTATE_H
#define RAND2_ATTACKTOORIENTATE_H

#include "../../Default/Transitions/Transition.h"

class Rand2_AttackToOrientate : public Transition
{
    public:
        Rand2_AttackToOrientate();
        bool isTriggered(AI_Info &info);
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
