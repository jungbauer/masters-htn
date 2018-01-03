#ifndef SQD4_ATTACK_H
#define SQD4_ATTACK_H

#include "../../Default/States/State.h"
#include "../Transitions/Sqd4_AttackToIdle.h"
#include "../Transitions/Sqd4_AttackToClose.h"
#include "../Transitions/Sqd4_AttackToShoot.h"
#include "../Transitions/Sqd4_AttackToOrientate.h"

#include "../../../Actions/Act_Choose_Target.h"

class Sqd4_Attack : public State
{
    public:
        Sqd4_Attack();
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
