#ifndef SQD3_SEARCH_H
#define SQD3_SEARCH_H

#include "../../Default/States/State.h"
#include "../Transitions/Sqd3_SearchToAttack.h"

#include "../../../Actions/Act_Spot_Search.h"

class Sqd3_Search : public State
{
    public:
        Sqd3_Search();
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
