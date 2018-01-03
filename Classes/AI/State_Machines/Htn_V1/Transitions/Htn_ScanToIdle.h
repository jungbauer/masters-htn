#ifndef HTN_SCANTOIDLE_H
#define HTN_SCANTOIDLE_H

#include "../../Default/Transitions/Transition.h"
#include "../../../Actions/Act_Reset_Engaged.h"

class Htn_ScanToIdle : public Transition
{
    public:
    Htn_ScanToIdle();
        bool isTriggered(AI_Info &info);
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
