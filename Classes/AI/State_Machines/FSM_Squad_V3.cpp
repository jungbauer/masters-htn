#include "FSM_Squad_V3.h"

FSM_Squad_V3::FSM_Squad_V3():StateMachine(constants::FSM_SQUAD_V3),
        sqd3_idle_state(Sqd3_Idle()),
        moving_state(Sqd3_Moving()),
        attack_state(Sqd3_Attack()),
        close_state(Sqd3_Close()),
        orientate_state(Sqd3_Orientate()),
        shoot_state(Sqd3_Shoot()),
        scan_state(Sqd3_Scan()),
        chase_state(Sqd3_Chase()),
        search_state(Sqd3_Search())
{
    _initialState = &sqd3_idle_state;
    _currentState = &sqd3_idle_state;
}

void FSM_Squad_V3::set_State(constants::StateType state)
{
    switch(state)
        {
            case constants::STATE_IDLE:
            {
                _currentState = &sqd3_idle_state;
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
