#ifndef SQD3_MOVETOIDLE_H
#define SQD3_MOVETOIDLE_H

#include "../../Default/Transitions/Transition.h"

class Sqd3_MoveToIdle : public Transition
{
    public:
        Sqd3_MoveToIdle();
        bool isTriggered(AI_Info &info);
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
