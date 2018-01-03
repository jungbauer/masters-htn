#ifndef SQD2_ATTACKTOCLOSE_H
#define SQD2_ATTACKTOCLOSE_H

#include "../../Default/Transitions/Transition.h"
#include "../../../Actions/Act_Pathfind.h"

class Sqd2_AttackToClose : public Transition
{
    public:
        Sqd2_AttackToClose();
        bool isTriggered(AI_Info &info);
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
