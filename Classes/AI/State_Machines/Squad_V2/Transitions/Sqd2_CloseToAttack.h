#ifndef SQD2_CLOSETOATTACK_H
#define SQD2_CLOSETOATTACK_H

#include "../../Default/Transitions/Transition.h"

#include "../../../Actions/Act_Target_Flagged.h"

class Sqd2_CloseToAttack : public Transition
{
    public:
        Sqd2_CloseToAttack();
        bool isTriggered(AI_Info &info);
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
