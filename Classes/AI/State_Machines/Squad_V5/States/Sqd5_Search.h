#ifndef SQD5_SEARCH_H
#define SQD5_SEARCH_H

#include "../../Default/States/State.h"
#include "../Transitions/Sqd5_SearchToAttack.h"

#include "../../../Actions/Act_Spot_Search.h"

class Sqd5_Search : public State
{
    public:
        Sqd5_Search();
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
