#ifndef RAND4_ATTACKTOORIENTATE_H
#define RAND4_ATTACKTOORIENTATE_H

#include "../../Default/Transitions/Transition.h"

class Rand4_AttackToOrientate : public Transition
{
    public:
        Rand4_AttackToOrientate();
        bool isTriggered(AI_Info &info);
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
