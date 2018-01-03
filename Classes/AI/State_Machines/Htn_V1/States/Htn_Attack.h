#ifndef HTN_ATTACK_H
#define HTN_ATTACK_H

#include "../../Default/States/State.h"
#include "../Transitions/Htn_AttackToChase.h"
#include "../Transitions/Htn_AttackToIdle.h"
#include "../Transitions/Htn_AttackToClose.h"
#include "../Transitions/Htn_AttackToShoot.h"
#include "../Transitions/Htn_AttackToOrientate.h"

#include "../../../Actions/Act_Choose_Target_V2.h"

class Htn_Attack : public State
{
    public:
        Htn_Attack();
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
