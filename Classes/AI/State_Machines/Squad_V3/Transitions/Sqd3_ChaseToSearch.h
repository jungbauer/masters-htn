#ifndef SQD3_CHASETOSEARCH_H
#define SQD3_CHASETOSEARCH_H

#include "../../Default/Transitions/Transition.h"
#include "../../../Actions/Act_Setup_Search.h"

class Sqd3_ChaseToSearch : public Transition
{
    public:
        Sqd3_ChaseToSearch();
        bool isTriggered(AI_Info &info);
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
