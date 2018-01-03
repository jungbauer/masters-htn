#ifndef RAND2_ATTACKTOCLOSE_H
#define RAND2_ATTACKTOCLOSE_H

#include "../../Default/Transitions/Transition.h"
#include "../../../Actions/Act_Pathfind.h"

class Rand2_AttackToClose : public Transition
{
    public:
        Rand2_AttackToClose();
        bool isTriggered(AI_Info &info);
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
