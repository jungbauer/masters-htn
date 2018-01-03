#ifndef RAND4_MOVETOIDLE_H
#define RAND4_MOVETOIDLE_H

#include "../../Default/Transitions/Transition.h"

class Rand4_MoveToIdle : public Transition
{
    public:
        Rand4_MoveToIdle();
        bool isTriggered(AI_Info &info);
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
