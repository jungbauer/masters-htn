#ifndef SQD3_SEARCHTOATTACK_H
#define SQD3_SEARCHTOATTACK_H

#include "../../Default/Transitions/Transition.h"

class Sqd3_SearchToAttack : public Transition
{
    public:
        Sqd3_SearchToAttack();
        bool isTriggered(AI_Info &info);
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
