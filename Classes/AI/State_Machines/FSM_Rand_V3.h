#ifndef FSM_RAND_V3_H
#define FSM_RAND_V3_H

#include "StateMachine.h"

#include "Rand_V3/States/Rand3_Idle.h"
#include "Rand_V3/States/Rand3_Moving.h"
#include "Rand_V3/States/Rand3_Attack.h"
#include "Rand_V3/States/Rand3_Close.h"
#include "Rand_V3/States/Rand3_Orientate.h"
#include "Rand_V3/States/Rand3_Shoot.h"
#include "Rand_V3/States/Rand3_Scan.h"
#include "Rand_V3/States/Rand3_Chase.h"
#include "Rand_V3/States/Rand3_Search.h"

class FSM_Rand_V3 : public StateMachine
{
    public:
        FSM_Rand_V3();

        void set_State(constants::StateType state);

    private:

        Rand3_Idle rand3_idle_state;
        Rand3_Moving moving_state;
        Rand3_Attack attack_state;
        Rand3_Close close_state;
        Rand3_Orientate orientate_state;
        Rand3_Shoot shoot_state;
        Rand3_Scan scan_state;
        Rand3_Chase chase_state;
        Rand3_Search search_state;
};

#endif

