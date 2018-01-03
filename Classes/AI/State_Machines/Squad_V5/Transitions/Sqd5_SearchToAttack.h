#ifndef SQD5_SEARCHTOATTACK_H
#define SQD5_SEARCHTOATTACK_H

#include "../../Default/Transitions/Transition.h"

class Sqd5_SearchToAttack : public Transition
{
    public:
        Sqd5_SearchToAttack();
        bool isTriggered(AI_Info &info);
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
