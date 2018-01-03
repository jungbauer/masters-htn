#ifndef DEF_ATTACKTOIDLE_H
#define DEF_ATTACKTOIDLE_H

#include "Transition.h"

class Def_AttackToIdle : public Transition
{
    public:
        Def_AttackToIdle();
        bool isTriggered(AI_Info &info);
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
