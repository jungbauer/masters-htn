#include "Rand3_Moving.h"

Rand3_Moving::Rand3_Moving():State(constants::STATE_MOVING)
{
    try
    {
        _transitions.push_back(new Rand3_MoveToScan());
        _transitions.push_back(new Rand3_MoveToIdle());
        // Transition to attack handled by Agent.
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Rand3_Moving() bad_alloc memory error" << std::endl;
    }
}

void Rand3_Moving::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_Follow_Path());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Rand3_Moving::getAction() bad_alloc memory error" << std::endl;
    }
}
