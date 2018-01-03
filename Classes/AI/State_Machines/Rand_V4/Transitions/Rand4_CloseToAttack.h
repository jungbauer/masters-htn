#ifndef RAND4_CLOSETOATTACK_H
#define RAND4_CLOSETOATTACK_H

#include "../../Default/Transitions/Transition.h"

#include "../../../Actions/Act_Target_Flagged.h"

class Rand4_CloseToAttack : public Transition
{
    public:
        Rand4_CloseToAttack();
        bool isTriggered(AI_Info &info);
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
