#include "FSM_Squad_V4.h"

FSM_Squad_V4::FSM_Squad_V4():StateMachine(constants::FSM_SQUAD_V4),
        sqd4_idle_state(Sqd4_Idle()),
        moving_state(Sqd4_Moving()),
        attack_state(Sqd4_Attack()),
        close_state(Sqd4_Close()),
        orientate_state(Sqd4_Orientate()),
        shoot_state(Sqd4_Shoot()),
        chase_state(Sqd4_Chase()),
        search_state(Sqd4_Search())
{
    _initialState = &sqd4_idle_state;
    _currentState = &sqd4_idle_state;
}

void FSM_Squad_V4::set_State(constants::StateType state)
{
    switch(state)
        {
            case constants::STATE_IDLE:
            {
                _currentState = &sqd4_idle_state;
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

            default:
            {
                _currentState = &sqd4_idle_state;
            }
        }
}
