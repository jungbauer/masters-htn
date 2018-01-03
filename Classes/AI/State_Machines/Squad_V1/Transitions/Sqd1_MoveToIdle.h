#ifndef SQD1_MOVETOIDLE_H
#define SQD1_MOVETOIDLE_H

#include "../../Default/Transitions/Transition.h"
#include "../../../Actions/Act_None.h"

class Sqd1_MoveToIdle : public Transition
{
    public:
        Sqd1_MoveToIdle();
        bool isTriggered(AI_Info &info);
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
