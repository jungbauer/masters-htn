#include "FSM_Rand_V2.h"

FSM_Rand_V2::FSM_Rand_V2():StateMachine(constants::FSM_RAND_V2),
        rand2_idle_state(Rand2_Idle()),
        moving_state(Rand2_Moving()),
        attack_state(Rand2_Attack()),
        close_state(Rand2_Close()),
        orientate_state(Rand2_Orientate()),
        shoot_state(Rand2_Shoot()),
        scan_state(Rand2_Scan())
{
    _initialState = &rand2_idle_state;
    _currentState = &rand2_idle_state;
}

void FSM_Rand_V2::set_State(constants::StateType state)
{
    switch(state)
        {
            case constants::STATE_IDLE:
            {
                _currentState = &rand2_idle_state;
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

            default:
            {
                _currentState = &rand2_idle_state;
            }
        }
}
