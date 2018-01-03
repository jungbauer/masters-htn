#ifndef RAND4_SEARCHTOATTACK_H
#define RAND4_SEARCHTOATTACK_H

#include "../../Default/Transitions/Transition.h"

class Rand4_SearchToAttack : public Transition
{
    public:
        Rand4_SearchToAttack();
        bool isTriggered(AI_Info &info);
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
