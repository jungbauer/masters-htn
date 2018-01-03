#include "FSM_Default.h"

FSM_Default::FSM_Default():StateMachine(constants::FSM_DEFAULT),
        def_idle_state(Def_Idle()),
        moving_state(Def_Moving()),
        attack_state(Def_Attack()),
        close_state(Def_Close()),
        orientate_state(Def_Orientate()),
        shoot_state(Def_Shoot())
{
    _initialState = &def_idle_state;
    _currentState = &def_idle_state;
}

void FSM_Default::set_State(constants::StateType state)
{
    switch(state)
        {
            case constants::STATE_IDLE:
            {
                _currentState = &def_idle_state;
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
                _currentState = &def_idle_state;
            }
        }
}
