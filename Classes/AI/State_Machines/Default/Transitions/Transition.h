#ifndef TRANSITION_H
#define TRANSITION_H

#include <vector>

#include "../../../../Utils/Constants.h"
#include "../../../../Utils/log.h"
#include "../../../AI_Info.h"
#include "../../../Actions/Action.h"
#include "../../../Actions/Act_None.h"

class Transition
{
    public:
    Transition(constants::StateType target);
    virtual ~Transition(){}

    virtual bool isTriggered(AI_Info &info){return false;};

    constants::StateType getTargetState();

    virtual void getAction(vector<Action*> &actions, AI_Info &info)
    {
        try
        {
            actions.push_back(new Act_None());
        }
        catch(std::bad_alloc& e)
        {
            std::cerr << "Transition::getAction() bad_alloc memory error" << std::endl;
        }
    }

    protected:
        constants::StateType _targetState;
};

#endif
