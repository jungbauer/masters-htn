#ifndef RAND3_SEARCH_H
#define RAND3_SEARCH_H

#include "../../Default/States/State.h"
#include "../Transitions/Rand3_SearchToAttack.h"

#include "../../../Actions/Act_Spot_Search.h"

class Rand3_Search : public State
{
    public:
        Rand3_Search();
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
