#ifndef DEF_MOVETOIDLE_H
#define DEF_MOVETOIDLE_H

#include "Transition.h"

class Def_MoveToIdle : public Transition
{
    public:
        Def_MoveToIdle();
        bool isTriggered(AI_Info &info);
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
