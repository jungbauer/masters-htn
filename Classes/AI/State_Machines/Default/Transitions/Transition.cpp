#include "Transition.h"

Transition::Transition(constants::StateType target):_targetState(target)
{}

constants::StateType Transition::getTargetState()
{
    return _targetState;
}
