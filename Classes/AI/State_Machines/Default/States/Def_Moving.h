#ifndef DEF_MOVING_H
#define DEF_MOVING_H

#include "State.h"
#include "../Transitions/Def_MoveToIdle.h"

#include "../../../Actions/Act_Follow_Path.h"

class Def_Moving : public State
{
    public:
        Def_Moving();
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
