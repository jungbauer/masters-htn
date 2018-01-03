#ifndef SQD1_ATTACKTOORIENTATE_H
#define SQD1_ATTACKTOORIENTATE_H

#include "../../Default/Transitions/Transition.h"

class Sqd1_AttackToOrientate : public Transition
{
    public:
        Sqd1_AttackToOrientate();
        bool isTriggered(AI_Info &info);
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
