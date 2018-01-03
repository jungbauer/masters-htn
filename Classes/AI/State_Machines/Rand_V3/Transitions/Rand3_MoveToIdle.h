#ifndef RAND3_MOVETOIDLE_H
#define RAND3_MOVETOIDLE_H

#include "../../Default/Transitions/Transition.h"

class Rand3_MoveToIdle : public Transition
{
    public:
        Rand3_MoveToIdle();
        bool isTriggered(AI_Info &info);
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
