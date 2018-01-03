#ifndef SQD2_ATTACKTOIDLE_H
#define SQD2_ATTACKTOIDLE_H

#include "../../Default/Transitions/Transition.h"
#include "../../../Actions/Act_Reset_Engaged.h"

class Sqd2_AttackToIdle : public Transition
{
    public:
        Sqd2_AttackToIdle();
        bool isTriggered(AI_Info &info);
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
