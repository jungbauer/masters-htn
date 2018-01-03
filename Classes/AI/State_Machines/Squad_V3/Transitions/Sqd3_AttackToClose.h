#ifndef SQD3_ATTACKTOCLOSE_H
#define SQD3_ATTACKTOCLOSE_H

#include "../../Default/Transitions/Transition.h"
#include "../../../Actions/Act_Pathfind.h"

class Sqd3_AttackToClose : public Transition
{
    public:
        Sqd3_AttackToClose();
        bool isTriggered(AI_Info &info);
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
