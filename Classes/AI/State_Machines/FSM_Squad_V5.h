#ifndef FSM_SQUAD_V5_H
#define FSM_SQUAD_V5_H

#include "StateMachine.h"

#include "Squad_V5/States/Sqd5_Idle.h"
#include "Squad_V5/States/Sqd5_Moving.h"
#include "Squad_V5/States/Sqd5_Attack.h"
#include "Squad_V5/States/Sqd5_Close.h"
#include "Squad_V5/States/Sqd5_Orientate.h"
#include "Squad_V5/States/Sqd5_Shoot.h"
#include "Squad_V5/States/Sqd5_Chase.h"
#include "Squad_V5/States/Sqd5_Search.h"

class FSM_Squad_V5 : public StateMachine
{
    public:
        FSM_Squad_V5();

        void set_State(constants::StateType state);

    private:

        Sqd5_Idle sqd5_idle_state;
        Sqd5_Moving moving_state;
        Sqd5_Attack attack_state;
        Sqd5_Close close_state;
        Sqd5_Orientate orientate_state;
        Sqd5_Shoot shoot_state;
        Sqd5_Chase chase_state;
        Sqd5_Search search_state;
};

#endif

