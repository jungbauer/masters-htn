#ifndef SQD2_ORIENTATE_H
#define SQD2_ORIENTATE_H

#include "../../Default/States/State.h"
#include "../Transitions/Sqd2_OrientateToAttack.h"

#include "../../../Actions/Act_Orient.h"

class Sqd2_Orientate : public State
{
    public:
        Sqd2_Orientate();
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif

