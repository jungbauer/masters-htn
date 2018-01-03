#ifndef SQD3_ATTACK_H
#define SQD3_ATTACK_H

#include "../../Default/States/State.h"
#include "../Transitions/Sqd3_AttackToChase.h"
#include "../Transitions/Sqd3_AttackToIdle.h"
#include "../Transitions/Sqd3_AttackToClose.h"
#include "../Transitions/Sqd3_AttackToShoot.h"
#include "../Transitions/Sqd3_AttackToOrientate.h"

#include "../../../Actions/Act_Choose_Target_V2.h"

class Sqd3_Attack : public State
{
    public:
        Sqd3_Attack();
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
