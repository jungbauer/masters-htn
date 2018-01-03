#ifndef DEF_ATTACKTOSHOOT_H
#define DEF_ATTACKTOSHOOT_H

#include "Transition.h"

class Def_AttackToShoot : public Transition
{
    public:
        Def_AttackToShoot();
        bool isTriggered(AI_Info &info);
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif

