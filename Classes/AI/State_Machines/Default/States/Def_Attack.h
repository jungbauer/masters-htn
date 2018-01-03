#ifndef DEF_ATTACK_H
#define DEF_ATTACK_H

#include "State.h"
#include "../Transitions/Def_AttackToIdle.h"
#include "../Transitions/Def_AttackToClose.h"
#include "../Transitions/Def_AttackToShoot.h"
#include "../Transitions/Def_AttackToOrientate.h"

#include "../../../Actions/Act_Choose_Target.h"

class Def_Attack : public State
{
    public:
        Def_Attack();
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
