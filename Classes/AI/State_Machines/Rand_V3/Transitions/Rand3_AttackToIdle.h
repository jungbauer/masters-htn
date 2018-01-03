#ifndef RAND3_ATTACKTOIDLE_H
#define RAND3_ATTACKTOIDLE_H

#include "../../Default/Transitions/Transition.h"
#include "../../../Actions/Act_Reset_Engaged.h"

class Rand3_AttackToIdle : public Transition
{
    public:
        Rand3_AttackToIdle();
        bool isTriggered(AI_Info &info);
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
