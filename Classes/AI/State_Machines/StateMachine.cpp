#include "StateMachine.h"

StateMachine::StateMachine():
        fsm_type(constants::FSM_IDLE),
        idle_state(Idle())
{
    _initialState = &idle_state;
    _currentState = _initialState;

//    fsm_type = constants::FSM_IDLE;
}

StateMachine::StateMachine(constants::StateMachines type):
        fsm_type(type),
        idle_state(Idle())
{
    _initialState = &idle_state;
    _currentState = _initialState;

//    fsm_type = type;
}

constants::StateType StateMachine::getState()
{
    return _currentState->getStateType();
}

constants::StateMachines StateMachine::get_FSM_Type()
{
    return fsm_type;
}

void StateMachine::update(vector<Action*> &action_list, AI_Info &info)
{
    bool transTriggered = false;
    Transition *triggeredTrans;

    vector<Transition*> transitions = _currentState->getTransitions();
    vector<Transition*>::iterator iter = transitions.begin();

    while(iter != transitions.end() && !transTriggered)
    {
        if((*iter)->isTriggered(info))
        {
            //cout << "trans triggered" << endl;
            triggeredTrans = (*iter);
            transTriggered = true;
        }
        iter++;
    }

    if(transTriggered)
    {
        triggeredTrans->getAction(action_list, info);

        constants::StateType state = triggeredTrans->getTargetState();
        set_State(state);
    }
    else
    {
        _currentState->getAction(action_list, info);
    }

    //cout << "end state updating" << endl;
}

void StateMachine::set_State(constants::StateType state)
{
    _currentState = &idle_state;
}

bool StateMachine::attackStatesCheck()
{
    bool already_here = false;

    switch(_currentState->getStateType())
    {
        case constants::STATE_ATTACK:
        case constants::STATE_ORIENTATE:
        case constants::STATE_CLOSE:
        case constants::STATE_SHOOT:
        {
            already_here = true;
        }
        break;

        default:
        {
            already_here = false;
        }
    }

    return already_here;
}
