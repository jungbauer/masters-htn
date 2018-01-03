#ifndef SQD1_ATTACKTOCLOSE_H
#define SQD1_ATTACKTOCLOSE_H

#include "../../Default/Transitions/Transition.h"

#include "../../../Actions/Act_Pathfind.h"

class Sqd1_AttackToClose : public Transition
{
    public:
        Sqd1_AttackToClose();
        bool isTriggered(AI_Info &info);
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
