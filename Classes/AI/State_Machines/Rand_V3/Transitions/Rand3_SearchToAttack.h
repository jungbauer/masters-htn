#ifndef RAND3_SEARCHTOATTACK_H
#define RAND3_SEARCHTOATTACK_H

#include "../../Default/Transitions/Transition.h"

class Rand3_SearchToAttack : public Transition
{
    public:
        Rand3_SearchToAttack();
        bool isTriggered(AI_Info &info);
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
