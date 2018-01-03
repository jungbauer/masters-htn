#ifndef SQD5_ATTACKTOSHOOT_H
#define SQD5_ATTACKTOSHOOT_H

#include "../../Default/Transitions/Transition.h"

class Sqd5_AttackToShoot : public Transition
{
    public:
        Sqd5_AttackToShoot();
        bool isTriggered(AI_Info &info);
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif

