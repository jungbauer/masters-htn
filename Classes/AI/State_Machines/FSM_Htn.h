#ifndef FSM_HTN_H
#define FSM_HTN_H

#include "StateMachine.h"

#include "Htn_V1/States/Htn_Idle.h"
#include "Htn_V1/States/Htn_Moving.h"
#include "Htn_V1/States/Htn_Attack.h"
#include "Htn_V1/States/Htn_Close.h"
#include "Htn_V1/States/Htn_Orientate.h"
#include "Htn_V1/States/Htn_Shoot.h"
#include "Htn_V1/States/Htn_Scan.h"
#include "Htn_V1/States/Htn_Chase.h"
#include "Htn_V1/States/Htn_Search.h"

class FSM_Htn : public StateMachine
{
public:
    FSM_Htn();

    void set_State(constants::StateType state);

private:

    Htn_Idle htn_idle_state;
    Htn_Moving moving_state;
    Htn_Attack attack_state;
    Htn_Close close_state;
    Htn_Orientate orientate_state;
    Htn_Shoot shoot_state;
    Htn_Scan scan_state;
    Htn_Chase chase_state;
    Htn_Search search_state;
};

#endif