#ifndef SQD5_MOVETOIDLE_H
#define SQD5_MOVETOIDLE_H

#include "../../Default/Transitions/Transition.h"

class Sqd5_MoveToIdle : public Transition
{
    public:
        Sqd5_MoveToIdle();
        bool isTriggered(AI_Info &info);
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
