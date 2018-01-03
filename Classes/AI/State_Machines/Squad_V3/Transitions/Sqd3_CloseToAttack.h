#ifndef SQD3_CLOSETOATTACK_H
#define SQD3_CLOSETOATTACK_H

#include "../../Default/Transitions/Transition.h"

#include "../../../Actions/Act_Target_Flagged.h"

class Sqd3_CloseToAttack : public Transition
{
    public:
        Sqd3_CloseToAttack();
        bool isTriggered(AI_Info &info);
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
