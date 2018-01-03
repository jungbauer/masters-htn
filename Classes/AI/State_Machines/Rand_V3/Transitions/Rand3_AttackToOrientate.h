#ifndef RAND3_ATTACKTOORIENTATE_H
#define RAND3_ATTACKTOORIENTATE_H

#include "../../Default/Transitions/Transition.h"

class Rand3_AttackToOrientate : public Transition
{
    public:
        Rand3_AttackToOrientate();
        bool isTriggered(AI_Info &info);
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
