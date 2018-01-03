#ifndef SQD4_SEARCHTOATTACK_H
#define SQD4_SEARCHTOATTACK_H

#include "../../Default/Transitions/Transition.h"

class Sqd4_SearchToAttack : public Transition
{
    public:
        Sqd4_SearchToAttack();
        bool isTriggered(AI_Info &info);
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
