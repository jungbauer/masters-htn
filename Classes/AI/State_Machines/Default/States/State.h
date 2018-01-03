#ifndef STATE_H
#define STATE_H

#include <vector>

#include "../../../../Utils/Constants.h"
#include "../../../../Utils/log.h"
#include "../Transitions/Transition.h"

#include "../../../Actions/Action.h"
#include "../../../Actions/Act_None.h"

#include "../../../AI_Info.h"

using namespace std;

class State
{
    public:
    State(constants::StateType type);

    virtual ~State()
    {
        for(unsigned int i = 0; i < _transitions.size(); i++)
        {
            delete _transitions[i];
        }
        _transitions.clear();
    }

    constants::StateType getStateType();

    virtual void getAction(vector<Action*> &actions, AI_Info &info)
    {
        try
        {
            actions.push_back(new Act_None());
        }
        catch(std::bad_alloc& e)
        {
            std::cerr << "State::getAction() bad_alloc memory error" << std::endl;
        }
    }

    vector<Transition*> getTransitions();

    /*virtual int getEntryAction()
    { return (0); }

    virtual int getExitAction()
    { return (0); }

    virtual int getTransitions()
    { return (0); }*/

    protected:
        constants::StateType state_type;
        vector<Transition*> _transitions;
};

#endif
