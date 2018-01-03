#include "FSM_Squad_V2.h"

FSM_Squad_V2::FSM_Squad_V2():StateMachine(constants::FSM_SQUAD_V2),
        sqd2_idle_state(Sqd2_Idle()),
        moving_state(Sqd2_Moving()),
        attack_state(Sqd2_Attack()),
        close_state(Sqd2_Close()),
        orientate_state(Sqd2_Orientate()),
        shoot_state(Sqd2_Shoot()),
        scan_state(Sqd2_Scan()),
        chase_state(Sqd2_Chase()),
        search_state(Sqd2_Search())
{
    _initialState = &sqd2_idle_state;
    _currentState = &sqd2_idle_state;
}

void FSM_Squad_V2::set_State(constants::StateType state)
{
    switch(state)
        {
            case constants::STATE_IDLE:
            {
                _currentState = &sqd2_idle_state;
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
