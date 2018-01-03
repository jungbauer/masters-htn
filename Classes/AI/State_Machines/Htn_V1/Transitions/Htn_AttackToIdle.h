#ifndef HTN_ATTACKTOIDLE_H
#define HTN_ATTACKTOIDLE_H

#include "../../Default/Transitions/Transition.h"
#include "../../../Actions/Act_Reset_Engaged.h"

class Htn_AttackToIdle : public Transition
{
    public:
    Htn_AttackToIdle();
        bool isTriggered(AI_Info &info);
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
