#ifndef DEF_IDLE_H
#define DEF_IDLE_H

#include "State.h"
#include "../Transitions/Def_IdleToMove.h"

class Def_Idle : public State
{
    public:
        Def_Idle();
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
