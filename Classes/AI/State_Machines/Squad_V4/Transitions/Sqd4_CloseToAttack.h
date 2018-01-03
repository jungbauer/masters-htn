#ifndef SQD4_CLOSETOATTACK_H
#define SQD4_CLOSETOATTACK_H

#include "../../Default/Transitions/Transition.h"

class Sqd4_CloseToAttack : public Transition
{
    public:
        Sqd4_CloseToAttack();
        bool isTriggered(AI_Info &info);
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
