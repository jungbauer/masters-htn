#ifndef HTN_MOVETOIDLE_H
#define HTN_MOVETOIDLE_H

#include "../../Default/Transitions/Transition.h"

class Htn_MoveToIdle : public Transition
{
    public:
    Htn_MoveToIdle();
        bool isTriggered(AI_Info &info);
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
