#ifndef SQD5_ATTACKTOCLOSE_H
#define SQD5_ATTACKTOCLOSE_H

#include "../../Default/Transitions/Transition.h"
#include "../../../Actions/Act_Pathfind.h"

class Sqd5_AttackToClose : public Transition
{
    public:
        Sqd5_AttackToClose();
        bool isTriggered(AI_Info &info);
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
