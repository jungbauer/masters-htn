#ifndef SQD2_ATTACKTOSHOOT_H
#define SQD2_ATTACKTOSHOOT_H

#include "../../Default/Transitions/Transition.h"

class Sqd2_AttackToShoot : public Transition
{
    public:
        Sqd2_AttackToShoot();
        bool isTriggered(AI_Info &info);
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif

