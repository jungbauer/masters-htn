#ifndef FSM_RAND_V2_H
#define FSM_RAND_V2_H

#include "StateMachine.h"

#include "Rand_V2/States/Rand2_Idle.h"
#include "Rand_V2/States/Rand2_Moving.h"
#include "Rand_V2/States/Rand2_Attack.h"
#include "Rand_V2/States/Rand2_Close.h"
#include "Rand_V2/States/Rand2_Orientate.h"
#include "Rand_V2/States/Rand2_Shoot.h"
#include "Rand_V2/States/Rand2_Scan.h"

class FSM_Rand_V2 : public StateMachine
{
    public:
        FSM_Rand_V2();

        void set_State(constants::StateType state);

    private:

        Rand2_Idle rand2_idle_state;
        Rand2_Moving moving_state;
        Rand2_Attack attack_state;
        Rand2_Close close_state;
        Rand2_Orientate orientate_state;
        Rand2_Shoot shoot_state;
        Rand2_Scan scan_state;
};

#endif

