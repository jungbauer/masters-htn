#ifndef RAND2_ATTACKTOSHOOT_H
#define RAND2_ATTACKTOSHOOT_H

#include "../../Default/Transitions/Transition.h"

class Rand2_AttackToShoot : public Transition
{
    public:
        Rand2_AttackToShoot();
        bool isTriggered(AI_Info &info);
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif

