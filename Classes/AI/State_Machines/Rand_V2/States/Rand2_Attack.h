#ifndef RAND2_ATTACK_H
#define RAND2_ATTACK_H

#include "../../Default/States/State.h"
#include "../Transitions/Rand2_AttackToIdle.h"
#include "../Transitions/Rand2_AttackToClose.h"
#include "../Transitions/Rand2_AttackToShoot.h"
#include "../Transitions/Rand2_AttackToOrientate.h"

#include "../../../Actions/Act_Choose_Target.h"

class Rand2_Attack : public State
{
    public:
        Rand2_Attack();
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
