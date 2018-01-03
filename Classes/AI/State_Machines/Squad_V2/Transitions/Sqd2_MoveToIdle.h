#ifndef SQD2_MOVETOIDLE_H
#define SQD2_MOVETOIDLE_H

#include "../../Default/Transitions/Transition.h"

class Sqd2_MoveToIdle : public Transition
{
    public:
        Sqd2_MoveToIdle();
        bool isTriggered(AI_Info &info);
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
