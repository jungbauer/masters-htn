#ifndef SQD3_ATTACKTOIDLE_H
#define SQD3_ATTACKTOIDLE_H

#include "../../Default/Transitions/Transition.h"
#include "../../../Actions/Act_Reset_Engaged.h"

class Sqd3_AttackToIdle : public Transition
{
    public:
        Sqd3_AttackToIdle();
        bool isTriggered(AI_Info &info);
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
