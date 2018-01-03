#ifndef FSM_SQUAD_V1_H
#define FSM_SQUAD_V1_H

#include "StateMachine.h"

#include "Squad_V1/States/Sqd1_Idle.h"
#include "Squad_V1/States/Sqd1_Moving.h"
#include "Squad_V1/States/Sqd1_Attack.h"
#include "Squad_V1/States/Sqd1_Close.h"
#include "Squad_V1/States/Sqd1_Orientate.h"
#include "Squad_V1/States/Sqd1_Shoot.h"

class FSM_Squad_V1 : public StateMachine
{
    public:
        FSM_Squad_V1();

        void set_State(constants::StateType state);

    private:

        Sqd1_Idle sqd1_idle_state;
        Sqd1_Moving moving_state;
        Sqd1_Attack attack_state;
        Sqd1_Close close_state;
        Sqd1_Orientate orientate_state;
        Sqd1_Shoot shoot_state;
};

#endif


