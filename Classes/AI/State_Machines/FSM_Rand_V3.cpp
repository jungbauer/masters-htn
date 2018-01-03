#include "FSM_Rand_V3.h"

FSM_Rand_V3::FSM_Rand_V3():StateMachine(constants::FSM_RAND_V3),
        rand3_idle_state(Rand3_Idle()),
        moving_state(Rand3_Moving()),
        attack_state(Rand3_Attack()),
        close_state(Rand3_Close()),
        orientate_state(Rand3_Orientate()),
        shoot_state(Rand3_Shoot()),
        scan_state(Rand3_Scan()),
        chase_state(Rand3_Chase()),
        search_state(Rand3_Search())
{
    _initialState = &rand3_idle_state;
    _currentState = &rand3_idle_state;
}

void FSM_Rand_V3::set_State(constants::StateType state)
{
    switch(state)
        {
            case constants::STATE_IDLE:
            {
                _currentState = &rand3_idle_state;
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
