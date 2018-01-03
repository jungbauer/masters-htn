#ifndef SQD2_ATTACKTOORIENTATE_H
#define SQD2_ATTACKTOORIENTATE_H

#include "../../Default/Transitions/Transition.h"

class Sqd2_AttackToOrientate : public Transition
{
    public:
        Sqd2_AttackToOrientate();
        bool isTriggered(AI_Info &info);
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
