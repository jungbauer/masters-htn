#ifndef SQD4_ATTACKTOCLOSE_H
#define SQD4_ATTACKTOCLOSE_H

#include "../../Default/Transitions/Transition.h"
#include "../../../Actions/Act_Pathfind.h"

class Sqd4_AttackToClose : public Transition
{
    public:
        Sqd4_AttackToClose();
        bool isTriggered(AI_Info &info);
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
