#ifndef FSM_RAND_V4_H
#define FSM_RAND_V4_H

#include "StateMachine.h"

#include "Rand_V4/States/Rand4_Idle.h"
#include "Rand_V4/States/Rand4_Moving.h"
#include "Rand_V4/States/Rand4_Attack.h"
#include "Rand_V4/States/Rand4_Close.h"
#include "Rand_V4/States/Rand4_Orientate.h"
#include "Rand_V4/States/Rand4_Shoot.h"
#include "Rand_V4/States/Rand4_Scan.h"
#include "Rand_V4/States/Rand4_Chase.h"
#include "Rand_V4/States/Rand4_Search.h"

class FSM_Rand_V4 : public StateMachine
{
    public:
        FSM_Rand_V4();

        void set_State(constants::StateType state);

    private:

        Rand4_Idle rand4_idle_state;
        Rand4_Moving moving_state;
        Rand4_Attack attack_state;
        Rand4_Close close_state;
        Rand4_Orientate orientate_state;
        Rand4_Shoot shoot_state;
        Rand4_Scan scan_state;
        Rand4_Chase chase_state;
        Rand4_Search search_state;
};

#endif

