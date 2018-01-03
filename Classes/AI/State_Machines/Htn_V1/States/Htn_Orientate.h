#ifndef HTN_ORIENTATE_H
#define HTN_ORIENTATE_H

#include "../../Default/States/State.h"
#include "../Transitions/Htn_OrientateToAttack.h"

#include "../../../Actions/Act_Orient.h"

class Htn_Orientate : public State
{
    public:
    Htn_Orientate();
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif

