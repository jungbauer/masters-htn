#ifndef SQD3_ATTACKTOORIENTATE_H
#define SQD3_ATTACKTOORIENTATE_H

#include "../../Default/Transitions/Transition.h"

class Sqd3_AttackToOrientate : public Transition
{
    public:
        Sqd3_AttackToOrientate();
        bool isTriggered(AI_Info &info);
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
