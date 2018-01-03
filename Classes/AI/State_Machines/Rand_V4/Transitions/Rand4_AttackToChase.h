#ifndef RAND4_ATTACKTOCHASE_H
#define RAND4_ATTACKTOCHASE_H

#include "../../Default/Transitions/Transition.h"
#include "../../../Actions/Act_Pathfind.h"

class Rand4_AttackToChase : public Transition
{
    public:
        Rand4_AttackToChase();
        bool isTriggered(AI_Info &info);
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
