#ifndef FSM_DEFAULT_H
#define FSM_DEFAULT_H

#include "StateMachine.h"

#include "Default/States/Def_Idle.h"
#include "Default/States/Def_Moving.h"
#include "Default/States/Def_Attack.h"
#include "Default/States/Def_Close.h"
#include "Default/States/Def_Orientate.h"
#include "Default/States/Def_Shoot.h"

class FSM_Default : public StateMachine
{
    public:
        FSM_Default();

        void set_State(constants::StateType state);

    private:

        Def_Idle def_idle_state;
        Def_Moving moving_state;
        Def_Attack attack_state;
        Def_Close close_state;
        Def_Orientate orientate_state;
        Def_Shoot shoot_state;
};

#endif

