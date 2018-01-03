#include "FSM_Htn.h"

FSM_Htn::FSM_Htn():StateMachine(constants::FSM_CMD_HTN),
                             htn_idle_state(Htn_Idle()),
                             moving_state(Htn_Moving()),
                             attack_state(Htn_Attack()),
                             close_state(Htn_Close()),
                             orientate_state(Htn_Orientate()),
                             shoot_state(Htn_Shoot()),
                             scan_state(Htn_Scan()),
                             chase_state(Htn_Chase()),
                             search_state(Htn_Search())
{
    _initialState = &htn_idle_state;
    _currentState = &htn_idle_state;
}

void FSM_Htn::set_State(constants::StateType state)
{
    switch(state)
    {
        case constants::STATE_IDLE:
        {
            _currentState = &htn_idle_state;
        }
            break;

        case constants::STATE_MOVING:
        {
            _currentState = &moving_state;
        }
            break;

        case constants::STATE_ATTACK:
        {
            _currentState = &attack_state;
        }
            break;

        case constants::STATE_SHOOT:
        {
            _currentState = &shoot_state;
        }
            break;

        case constants::STATE_ORIENTATE:
        {
            _currentState = &orientate_state;
        }
            break;

        case constants::STATE_CLOSE:
        {
            _currentState = &close_state;
        }
            break;

        case constants::STATE_SCAN:
        {
            _currentState = &scan_state;
        }
            break;

        case constants::STATE_CHASE:
        {
            _currentState = &chase_state;
        }
            break;

        case constants::STATE_SEARCH:
        {
            _currentState = &search_state;
        }
            break;


// Default explicitly excluded to make sure all states are covered.
//            default:
//            {
//                _currentState = &idle_state;
//            }
    }
}
