#ifndef RAND3_ATTACKTOCHASE_H
#define RAND3_ATTACKTOCHASE_H

#include "../../Default/Transitions/Transition.h"
#include "../../../Actions/Act_Pathfind.h"

class Rand3_AttackToChase : public Transition
{
    public:
        Rand3_AttackToChase();
        bool isTriggered(AI_Info &info);
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
