#ifndef SQD2_SCANTOIDLE_H
#define SQD2_SCANTOIDLE_H

#include "../../Default/Transitions/Transition.h"
#include "../../../Actions/Act_Reset_Engaged.h"

class Sqd2_ScanToIdle : public Transition
{
    public:
        Sqd2_ScanToIdle();
        bool isTriggered(AI_Info &info);
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
