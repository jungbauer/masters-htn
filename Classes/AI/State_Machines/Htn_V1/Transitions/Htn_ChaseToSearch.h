#ifndef HTN_CHASETOSEARCH_H
#define HTN_CHASETOSEARCH_H

#include "../../Default/Transitions/Transition.h"
#include "../../../Actions/Act_Setup_Search.h"

class Htn_ChaseToSearch : public Transition
{
    public:
    Htn_ChaseToSearch();
        bool isTriggered(AI_Info &info);
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
