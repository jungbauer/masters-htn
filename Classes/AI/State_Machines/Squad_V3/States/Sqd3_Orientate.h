#ifndef SQD3_ORIENTATE_H
#define SQD3_ORIENTATE_H

#include "../../Default/States/State.h"
#include "../Transitions/Sqd3_OrientateToAttack.h"

#include "../../../Actions/Act_Orient.h"

class Sqd3_Orientate : public State
{
    public:
        Sqd3_Orientate();
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif

