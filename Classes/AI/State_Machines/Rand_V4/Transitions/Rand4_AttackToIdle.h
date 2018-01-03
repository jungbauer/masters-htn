#ifndef RAND4_ATTACKTOIDLE_H
#define RAND4_ATTACKTOIDLE_H

#include "../../Default/Transitions/Transition.h"
#include "../../../Actions/Act_Reset_Engaged.h"

class Rand4_AttackToIdle : public Transition
{
    public:
        Rand4_AttackToIdle();
        bool isTriggered(AI_Info &info);
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
