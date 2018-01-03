#include "FSM_Squad_V1.h"

FSM_Squad_V1::FSM_Squad_V1():StateMachine(constants::FSM_SQUAD_V1),
        sqd1_idle_state(Sqd1_Idle()),
        moving_state(Sqd1_Moving()),
        attack_state(Sqd1_Attack()),
        close_state(Sqd1_Close()),
        orientate_state(Sqd1_Orientate()),
        shoot_state(Sqd1_Shoot())
{
    _initialState = &sqd1_idle_state;
    _currentState = &sqd1_idle_state;
}

void FSM_Squad_V1::set_State(constants::StateType state)
{
    switch(state)
        {
            case constants::STATE_IDLE:
            {
                _currentState = &sqd1_idle_state;
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

            default:
            {
                _currentState = &sqd1_idle_state;
            }
        }
}

