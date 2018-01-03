#ifndef SQD2_SEARCHTOATTACK_H
#define SQD2_SEARCHTOATTACK_H

#include "../../Default/Transitions/Transition.h"

class Sqd2_SearchToAttack : public Transition
{
    public:
        Sqd2_SearchToAttack();
        bool isTriggered(AI_Info &info);
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
