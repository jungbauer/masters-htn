#ifndef HTN_SEARCHTOATTACK_H
#define HTN_SEARCHTOATTACK_H

#include "../../Default/Transitions/Transition.h"

class Htn_SearchToAttack : public Transition
{
    public:
    Htn_SearchToAttack();
        bool isTriggered(AI_Info &info);
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
