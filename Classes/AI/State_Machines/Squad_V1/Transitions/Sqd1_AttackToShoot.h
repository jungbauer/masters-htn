#ifndef SQD1_ATTACKTOSHOOT_H
#define SQD1_ATTACKTOSHOOT_H

#include "../../Default/Transitions/Transition.h"

class Sqd1_AttackToShoot : public Transition
{
    public:
        Sqd1_AttackToShoot();
        bool isTriggered(AI_Info &info);
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif

