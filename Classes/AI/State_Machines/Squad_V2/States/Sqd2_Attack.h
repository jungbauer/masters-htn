#ifndef SQD2_ATTACK_H
#define SQD2_ATTACK_H

#include "../../Default/States/State.h"
#include "../Transitions/Sqd2_AttackToChase.h"
#include "../Transitions/Sqd2_AttackToIdle.h"
#include "../Transitions/Sqd2_AttackToClose.h"
#include "../Transitions/Sqd2_AttackToShoot.h"
#include "../Transitions/Sqd2_AttackToOrientate.h"

#include "../../../Actions/Act_Choose_Target_V2.h"

class Sqd2_Attack : public State
{
    public:
        Sqd2_Attack();
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
