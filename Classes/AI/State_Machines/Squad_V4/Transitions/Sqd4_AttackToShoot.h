#ifndef SQD4_ATTACKTOSHOOT_H
#define SQD4_ATTACKTOSHOOT_H

#include "../../Default/Transitions/Transition.h"

class Sqd4_AttackToShoot : public Transition
{
    public:
        Sqd4_AttackToShoot();
        bool isTriggered(AI_Info &info);
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif

