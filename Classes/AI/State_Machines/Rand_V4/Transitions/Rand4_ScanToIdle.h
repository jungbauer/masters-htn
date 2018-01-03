#ifndef RAND4_SCANTOIDLE_H
#define RAND4_SCANTOIDLE_H

#include "../../Default/Transitions/Transition.h"
#include "../../../Actions/Act_Reset_Engaged.h"

class Rand4_ScanToIdle : public Transition
{
    public:
        Rand4_ScanToIdle();
        bool isTriggered(AI_Info &info);
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
