#ifndef FSM_SQUAD_V2_H
#define FSM_SQUAD_V2_H

#include "StateMachine.h"

#include "Squad_V2/States/Sqd2_Idle.h"
#include "Squad_V2/States/Sqd2_Moving.h"
#include "Squad_V2/States/Sqd2_Attack.h"
#include "Squad_V2/States/Sqd2_Close.h"
#include "Squad_V2/States/Sqd2_Orientate.h"
#include "Squad_V2/States/Sqd2_Shoot.h"
#include "Squad_V2/States/Sqd2_Scan.h"
#include "Squad_V2/States/Sqd2_Chase.h"
#include "Squad_V2/States/Sqd2_Search.h"

class FSM_Squad_V2 : public StateMachine
{
    public:
        FSM_Squad_V2();

        void set_State(constants::StateType state);

    private:

        Sqd2_Idle sqd2_idle_state;
        Sqd2_Moving moving_state;
        Sqd2_Attack attack_state;
        Sqd2_Close close_state;
        Sqd2_Orientate orientate_state;
        Sqd2_Shoot shoot_state;
        Sqd2_Scan scan_state;
        Sqd2_Chase chase_state;
        Sqd2_Search search_state;
};

#endif

