#ifndef RAND3_ATTACKTOSHOOT_H
#define RAND3_ATTACKTOSHOOT_H

#include "../../Default/Transitions/Transition.h"

class Rand3_AttackToShoot : public Transition
{
    public:
        Rand3_AttackToShoot();
        bool isTriggered(AI_Info &info);
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif

