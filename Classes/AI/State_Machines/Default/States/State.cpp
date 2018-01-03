#include "State.h"

State::State(constants::StateType type): state_type(type)
{

}

constants::StateType State::getStateType()
{
    return state_type;
}

vector<Transition*> State::getTransitions()
{
    return _transitions;
}
