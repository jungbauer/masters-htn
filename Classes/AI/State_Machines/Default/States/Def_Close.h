#ifndef DEF_CLOSE_H
#define DEF_CLOSE_H

#include "State.h"

#include "../Transitions/Def_CloseToAttack.h"

#include "../../../Actions/Act_Follow_Path.h"

class Def_Close : public State
{
    public:
        Def_Close();
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif

