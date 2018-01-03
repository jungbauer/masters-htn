#ifndef RAND4_ATTACKTOCLOSE_H
#define RAND4_ATTACKTOCLOSE_H

#include "../../Default/Transitions/Transition.h"
#include "../../../Actions/Act_Pathfind.h"

class Rand4_AttackToClose : public Transition
{
    public:
        Rand4_AttackToClose();
        bool isTriggered(AI_Info &info);
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
