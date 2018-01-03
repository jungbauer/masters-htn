#ifndef RAND4_ATTACKTOSHOOT_H
#define RAND4_ATTACKTOSHOOT_H

#include "../../Default/Transitions/Transition.h"

class Rand4_AttackToShoot : public Transition
{
    public:
        Rand4_AttackToShoot();
        bool isTriggered(AI_Info &info);
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif

