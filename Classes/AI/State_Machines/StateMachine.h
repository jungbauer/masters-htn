#ifndef STATEMACHINE_H
#define STATEMACHINE_H

#include <iostream>
#include <string>
#include <vector>

#include "../AI_Info.h"
#include "../Actions/Action.h"

#include "Default/States/State.h"
#include "Default/States/Idle.h"

using namespace std;

class StateMachine
{
    public:
        StateMachine();
        StateMachine(constants::StateMachines type);

        virtual ~StateMachine(){}

        void update(vector<Action*> &action_list, AI_Info &info);
        constants::StateType getState();
        virtual void set_State(constants::StateType state);
        constants::StateMachines get_FSM_Type();

        bool attackStatesCheck();

    protected:
        constants::StateMachines fsm_type;
        State *_initialState;
        State *_currentState;

        Idle idle_state;

        StateMachine(const StateMachine& that);
        StateMachine& operator=(const StateMachine& that);
};

#endif
