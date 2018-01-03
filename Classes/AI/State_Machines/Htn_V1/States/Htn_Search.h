#ifndef HTN_SEARCH_H
#define HTN_SEARCH_H

#include "../../Default/States/State.h"
#include "../Transitions/Htn_SearchToAttack.h"

#include "../../../Actions/Act_Spot_Search.h"

class Htn_Search : public State
{
    public:
        Htn_Search();
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
