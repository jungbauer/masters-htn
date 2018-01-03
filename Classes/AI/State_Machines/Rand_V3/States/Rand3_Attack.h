#ifndef RAND3_ATTACK_H
#define RAND3_ATTACK_H

#include "../../Default/States/State.h"
#include "../Transitions/Rand3_AttackToChase.h"
#include "../Transitions/Rand3_AttackToIdle.h"
#include "../Transitions/Rand3_AttackToClose.h"
#include "../Transitions/Rand3_AttackToShoot.h"
#include "../Transitions/Rand3_AttackToOrientate.h"

#include "../../../Actions/Act_Choose_Target.h"

class Rand3_Attack : public State
{
    public:
        Rand3_Attack();
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
