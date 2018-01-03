#ifndef RAND3_SCANTOIDLE_H
#define RAND3_SCANTOIDLE_H

#include "../../Default/Transitions/Transition.h"
#include "../../../Actions/Act_Reset_Engaged.h"

class Rand3_ScanToIdle : public Transition
{
    public:
        Rand3_ScanToIdle();
        bool isTriggered(AI_Info &info);
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
