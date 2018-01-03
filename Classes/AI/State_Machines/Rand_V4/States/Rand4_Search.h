#ifndef RAND4_SEARCH_H
#define RAND4_SEARCH_H

#include "../../Default/States/State.h"
#include "../Transitions/Rand4_SearchToAttack.h"

#include "../../../Actions/Act_Spot_Search.h"

class Rand4_Search : public State
{
    public:
        Rand4_Search();
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
