#ifndef RAND4_CLOSE_H
#define RAND4_CLOSE_H

#include "../../Default/States/State.h"

#include "../Transitions/Rand4_CloseToAttack.h"

#include "../../../Actions/Act_Follow_Path.h"

class Rand4_Close : public State
{
    public:
        Rand4_Close();
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif

