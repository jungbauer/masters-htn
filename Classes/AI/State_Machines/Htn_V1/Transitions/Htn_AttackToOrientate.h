#ifndef HTN_ATTACKTOORIENTATE_H
#define HTN_ATTACKTOORIENTATE_H

#include "../../Default/Transitions/Transition.h"

class Htn_AttackToOrientate : public Transition
{
    public:
    Htn_AttackToOrientate();
        bool isTriggered(AI_Info &info);
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
