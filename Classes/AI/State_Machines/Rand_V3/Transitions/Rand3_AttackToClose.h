#ifndef RAND3_ATTACKTOCLOSE_H
#define RAND3_ATTACKTOCLOSE_H

#include "../../Default/Transitions/Transition.h"
#include "../../../Actions/Act_Pathfind.h"

class Rand3_AttackToClose : public Transition
{
    public:
        Rand3_AttackToClose();
        bool isTriggered(AI_Info &info);
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
