#ifndef SQD1_CLOSETOATTACK_H
#define SQD1_CLOSETOATTACK_H

#include "../../Default/Transitions/Transition.h"

class Sqd1_CloseToAttack : public Transition
{
    public:
        Sqd1_CloseToAttack();
        bool isTriggered(AI_Info &info);
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
