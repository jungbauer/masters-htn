#ifndef SQD5_CHASETOSEARCH_H
#define SQD5_CHASETOSEARCH_H

#include "../../Default/Transitions/Transition.h"
#include "../../../Actions/Act_Setup_Search.h"

class Sqd5_ChaseToSearch : public Transition
{
    public:
        Sqd5_ChaseToSearch();
        bool isTriggered(AI_Info &info);
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
