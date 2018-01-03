#ifndef RAND4_ATTACK_H
#define RAND4_ATTACK_H

#include "../../Default/States/State.h"
#include "../Transitions/Rand4_AttackToChase.h"
#include "../Transitions/Rand4_AttackToIdle.h"
#include "../Transitions/Rand4_AttackToClose.h"
#include "../Transitions/Rand4_AttackToShoot.h"
#include "../Transitions/Rand4_AttackToOrientate.h"

#include "../../../Actions/Act_Choose_Target_V2.h"

class Rand4_Attack : public State
{
    public:
        Rand4_Attack();
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
