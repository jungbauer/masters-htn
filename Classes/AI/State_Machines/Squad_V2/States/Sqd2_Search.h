#ifndef SQD2_SEARCH_H
#define SQD2_SEARCH_H

#include "../../Default/States/State.h"
#include "../Transitions/Sqd2_SearchToAttack.h"

#include "../../../Actions/Act_Spot_Search.h"

class Sqd2_Search : public State
{
    public:
        Sqd2_Search();
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
