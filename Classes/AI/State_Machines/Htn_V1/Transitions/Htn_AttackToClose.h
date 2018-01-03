#ifndef HTN_ATTACKTOCLOSE_H
#define HTN_ATTACKTOCLOSE_H

#include "../../Default/Transitions/Transition.h"
#include "../../../Actions/Act_Pathfind.h"

class Htn_AttackToClose : public Transition
{
    public:
    Htn_AttackToClose();
        bool isTriggered(AI_Info &info);
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
