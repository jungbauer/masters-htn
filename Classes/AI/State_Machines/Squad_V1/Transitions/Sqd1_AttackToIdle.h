#ifndef SQD1_ATTACKTOIDLE_H
#define SQD1_ATTACKTOIDLE_H

#include "../../Default/Transitions/Transition.h"

class Sqd1_AttackToIdle : public Transition
{
    public:
        Sqd1_AttackToIdle();
        bool isTriggered(AI_Info &info);
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
