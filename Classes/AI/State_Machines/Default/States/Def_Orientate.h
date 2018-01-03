#ifndef DEF_ORIENTATE_H
#define DEF_ORIENTATE_H

#include "State.h"
#include "../Transitions/Def_OrientateToAttack.h"

#include "../../../Actions/Act_Orient.h"

class Def_Orientate : public State
{
    public:
        Def_Orientate();
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif

