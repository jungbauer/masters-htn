#ifndef SQD5_ATTACKTOIDLE_H
#define SQD5_ATTACKTOIDLE_H

#include "../../Default/Transitions/Transition.h"
#include "../../../Actions/Act_Reset_Engaged.h"

class Sqd5_AttackToIdle : public Transition
{
    public:
        Sqd5_AttackToIdle();
        bool isTriggered(AI_Info &info);
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
