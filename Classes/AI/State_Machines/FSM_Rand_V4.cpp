#include "FSM_Rand_V4.h"

FSM_Rand_V4::FSM_Rand_V4():StateMachine(constants::FSM_RAND_V4),
        rand4_idle_state(Rand4_Idle()),
        moving_state(Rand4_Moving()),
        attack_state(Rand4_Attack()),
        close_state(Rand4_Close()),
        orientate_state(Rand4_Orientate()),
        shoot_state(Rand4_Shoot()),
        scan_state(Rand4_Scan()),
        chase_state(Rand4_Chase()),
        search_state(Rand4_Search())
{
    _initialState = &rand4_idle_state;
    _currentState = &rand4_idle_state;
}

void FSM_Rand_V4::set_State(constants::StateType state)
{
    switch(state)
        {
            case constants::STATE_IDLE:
            {
                _currentState = &rand4_idle_state;
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
