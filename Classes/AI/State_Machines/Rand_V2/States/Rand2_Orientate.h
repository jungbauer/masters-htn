#ifndef RAND2_ORIENTATE_H
#define RAND2_ORIENTATE_H

#include "../../Default/States/State.h"
#include "../Transitions/Rand2_OrientateToAttack.h"

#include "../../../Actions/Act_Orient.h"

class Rand2_Orientate : public State
{
    public:
        Rand2_Orientate();
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif

