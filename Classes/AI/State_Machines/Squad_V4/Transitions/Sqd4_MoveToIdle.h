#ifndef SQD4_MOVETOIDLE_H
#define SQD4_MOVETOIDLE_H

#include "../../Default/Transitions/Transition.h"

class Sqd4_MoveToIdle : public Transition
{
    public:
        Sqd4_MoveToIdle();
        bool isTriggered(AI_Info &info);
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
