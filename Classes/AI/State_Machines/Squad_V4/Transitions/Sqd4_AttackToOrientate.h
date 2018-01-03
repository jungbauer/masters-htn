#ifndef SQD4_ATTACKTOORIENTATE_H
#define SQD4_ATTACKTOORIENTATE_H

#include "../../Default/Transitions/Transition.h"

class Sqd4_AttackToOrientate : public Transition
{
    public:
        Sqd4_AttackToOrientate();
        bool isTriggered(AI_Info &info);
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
