#ifndef SQD2_ATTACKTOCHASE_H
#define SQD2_ATTACKTOCHASE_H

#include "../../Default/Transitions/Transition.h"
#include "../../../Actions/Act_Pathfind.h"

class Sqd2_AttackToChase : public Transition
{
    public:
        Sqd2_AttackToChase();
        bool isTriggered(AI_Info &info);
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
