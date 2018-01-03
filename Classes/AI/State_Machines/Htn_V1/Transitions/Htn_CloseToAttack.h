#ifndef HTN_CLOSETOATTACK_H
#define HTN_CLOSETOATTACK_H

#include "../../Default/Transitions/Transition.h"

#include "../../../Actions/Act_Target_Flagged.h"

class Htn_CloseToAttack : public Transition
{
    public:
    Htn_CloseToAttack();
        bool isTriggered(AI_Info &info);
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
