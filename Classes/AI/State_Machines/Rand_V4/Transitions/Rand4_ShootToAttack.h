#ifndef RAND4_SHOOTTOATTACK_H
#define RAND4_SHOOTTOATTACK_H

#include "../../Default/Transitions/Transition.h"

class Rand4_ShootToAttack : public Transition
{
    public:
        Rand4_ShootToAttack();
        bool isTriggered(AI_Info &info);
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif

