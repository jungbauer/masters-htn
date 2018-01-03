#ifndef FSM_SQUAD_V4_H
#define FSM_SQUAD_V4_H

#include "StateMachine.h"

#include "Squad_V4/States/Sqd4_Idle.h"
#include "Squad_V4/States/Sqd4_Moving.h"
#include "Squad_V4/States/Sqd4_Attack.h"
#include "Squad_V4/States/Sqd4_Close.h"
#include "Squad_V4/States/Sqd4_Orientate.h"
#include "Squad_V4/States/Sqd4_Shoot.h"
#include "Squad_V4/States/Sqd4_Chase.h"
#include "Squad_V4/States/Sqd4_Search.h"

class FSM_Squad_V4 : public StateMachine
{
    public:
        FSM_Squad_V4();

        void set_State(constants::StateType state);

    private:

        Sqd4_Idle sqd4_idle_state;
        Sqd4_Moving moving_state;
        Sqd4_Attack attack_state;
        Sqd4_Close close_state;
        Sqd4_Orientate orientate_state;
        Sqd4_Shoot shoot_state;
        Sqd4_Chase chase_state;
        Sqd4_Search search_state;
};

#endif

