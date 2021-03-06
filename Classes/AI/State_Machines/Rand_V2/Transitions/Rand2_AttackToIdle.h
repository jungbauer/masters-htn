#ifndef RAND2_ATTACKTOIDLE_H
#define RAND2_ATTACKTOIDLE_H

#include "../../Default/Transitions/Transition.h"
#include "../../../Actions/Act_Reset_Engaged.h"

class Rand2_AttackToIdle : public Transition
{
    public:
        Rand2_AttackToIdle();
        bool isTriggered(AI_Info &info);
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
