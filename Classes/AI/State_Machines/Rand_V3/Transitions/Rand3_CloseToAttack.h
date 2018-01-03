#ifndef RAND3_CLOSETOATTACK_H
#define RAND3_CLOSETOATTACK_H

#include "../../Default/Transitions/Transition.h"

class Rand3_CloseToAttack : public Transition
{
    public:
        Rand3_CloseToAttack();
        bool isTriggered(AI_Info &info);
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
