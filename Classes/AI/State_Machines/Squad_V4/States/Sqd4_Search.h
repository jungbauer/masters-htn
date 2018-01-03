#ifndef SQD4_SEARCH_H
#define SQD4_SEARCH_H

#include "../../Default/States/State.h"
#include "../Transitions/Sqd4_SearchToAttack.h"

#include "../../../Actions/Act_Spot_Search.h"

class Sqd4_Search : public State
{
    public:
        Sqd4_Search();
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
