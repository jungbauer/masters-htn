#include "FSM_Squad_V5.h"

FSM_Squad_V5::FSM_Squad_V5():StateMachine(constants::FSM_SQUAD_V5),
        sqd5_idle_state(Sqd5_Idle()),
        moving_state(Sqd5_Moving()),
        attack_state(Sqd5_Attack()),
        close_state(Sqd5_Close()),
        orientate_state(Sqd5_Orientate()),
        shoot_state(Sqd5_Shoot()),
        chase_state(Sqd5_Chase()),
        search_state(Sqd5_Search())
{
    _initialState = &sqd5_idle_state;
    _currentState = &sqd5_idle_state;
}

void FSM_Squad_V5::set_State(constants::StateType state)
{
    switch(state)
        {
            case constants::STATE_IDLE:
            {
                _currentState = &sqd5_idle_state;
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
                _currentState = &sqd5_idle_state;
            }
        }
}
