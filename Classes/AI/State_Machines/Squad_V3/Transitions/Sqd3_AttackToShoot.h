#ifndef SQD3_ATTACKTOSHOOT_H
#define SQD3_ATTACKTOSHOOT_H

#include "../../Default/Transitions/Transition.h"

class Sqd3_AttackToShoot : public Transition
{
    public:
        Sqd3_AttackToShoot();
        bool isTriggered(AI_Info &info);
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif

