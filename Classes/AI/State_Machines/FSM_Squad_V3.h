#ifndef FSM_SQUAD_V3_H
#define FSM_SQUAD_V3_H

#include "StateMachine.h"

#include "Squad_V3/States/Sqd3_Idle.h"
#include "Squad_V3/States/Sqd3_Moving.h"
#include "Squad_V3/States/Sqd3_Attack.h"
#include "Squad_V3/States/Sqd3_Close.h"
#include "Squad_V3/States/Sqd3_Orientate.h"
#include "Squad_V3/States/Sqd3_Shoot.h"
#include "Squad_V3/States/Sqd3_Scan.h"
#include "Squad_V3/States/Sqd3_Chase.h"
#include "Squad_V3/States/Sqd3_Search.h"

class FSM_Squad_V3 : public StateMachine
{
    public:
        FSM_Squad_V3();

        void set_State(constants::StateType state);

    private:

        Sqd3_Idle sqd3_idle_state;
        Sqd3_Moving moving_state;
        Sqd3_Attack attack_state;
        Sqd3_Close close_state;
        Sqd3_Orientate orientate_state;
        Sqd3_Shoot shoot_state;
        Sqd3_Scan scan_state;
        Sqd3_Chase chase_state;
        Sqd3_Search search_state;
};

#endif

