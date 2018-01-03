#ifndef SQD5_ATTACK_H
#define SQD5_ATTACK_H

#include "../../Default/States/State.h"
#include "../Transitions/Sqd5_AttackToIdle.h"
#include "../Transitions/Sqd5_AttackToClose.h"
#include "../Transitions/Sqd5_AttackToShoot.h"
#include "../Transitions/Sqd5_AttackToOrientate.h"

#include "../../../Actions/Act_Choose_Target_V2.h"

class Sqd5_Attack : public State
{
    public:
        Sqd5_Attack();
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
