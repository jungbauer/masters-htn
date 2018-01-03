#ifndef RAND4_CHASETOSEARCH_H
#define RAND4_CHASETOSEARCH_H

#include "../../Default/Transitions/Transition.h"
#include "../../../Actions/Act_Setup_Search.h"

class Rand4_ChaseToSearch : public Transition
{
    public:
        Rand4_ChaseToSearch();
        bool isTriggered(AI_Info &info);
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
