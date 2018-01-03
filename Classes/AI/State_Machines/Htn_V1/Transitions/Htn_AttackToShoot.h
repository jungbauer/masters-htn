#ifndef HTN_ATTACKTOSHOOT_H
#define HTN_ATTACKTOSHOOT_H

#include "../../Default/Transitions/Transition.h"

class Htn_AttackToShoot : public Transition
{
    public:
        Htn_AttackToShoot();
        bool isTriggered(AI_Info &info);
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif

