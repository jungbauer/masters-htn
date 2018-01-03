#ifndef SQD5_ATTACKTOORIENTATE_H
#define SQD5_ATTACKTOORIENTATE_H

#include "../../Default/Transitions/Transition.h"

class Sqd5_AttackToOrientate : public Transition
{
    public:
        Sqd5_AttackToOrientate();
        bool isTriggered(AI_Info &info);
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
