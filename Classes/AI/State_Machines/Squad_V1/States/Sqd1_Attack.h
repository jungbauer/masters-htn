#ifndef SQD1_ATTACK_H
#define SQD1_ATTACK_H

#include "../../Default/States/State.h"
#include "../Transitions/Sqd1_AttackToIdle.h"
#include "../Transitions/Sqd1_AttackToClose.h"
#include "../Transitions/Sqd1_AttackToShoot.h"
#include "../Transitions/Sqd1_AttackToOrientate.h"

#include "../../../Actions/Act_Choose_Target.h"

class Sqd1_Attack : public State
{
    public:
        Sqd1_Attack();

        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
