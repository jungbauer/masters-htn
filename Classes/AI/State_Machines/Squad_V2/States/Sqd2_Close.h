#ifndef SQD2_CLOSE_H
#define SQD2_CLOSE_H

#include "../../Default/States/State.h"

#include "../Transitions/Sqd2_CloseToAttack.h"

#include "../../../Actions/Act_Follow_Path.h"

class Sqd2_Close : public State
{
    public:
        Sqd2_Close();
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif

