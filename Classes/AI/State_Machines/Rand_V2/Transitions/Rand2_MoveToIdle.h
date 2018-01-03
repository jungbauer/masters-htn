#ifndef RAND2_MOVETOIDLE_H
#define RAND2_MOVETOIDLE_H

#include "../../Default/Transitions/Transition.h"

class Rand2_MoveToIdle : public Transition
{
    public:
        Rand2_MoveToIdle();
        bool isTriggered(AI_Info &info);
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
