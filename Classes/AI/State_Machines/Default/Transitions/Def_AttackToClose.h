#ifndef DEF_ATTACKTOCLOSE_H
#define DEF_ATTACKTOCLOSE_H

#include "Transition.h"
#include "../../../Actions/Act_Pathfind.h"

class Def_AttackToClose : public Transition
{
    public:
        Def_AttackToClose();
        bool isTriggered(AI_Info &info);
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
