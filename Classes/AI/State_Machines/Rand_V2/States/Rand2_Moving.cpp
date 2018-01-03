#include "Rand2_Moving.h"

Rand2_Moving::Rand2_Moving():State(constants::STATE_MOVING)
{
    try
    {
        _transitions.push_back(new Rand2_MoveToScan());
        _transitions.push_back(new Rand2_MoveToIdle());
        // Transition to attack handled by Agent.
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Rand2_Moving() bad_alloc memory error" << std::endl;
    }
}

void Rand2_Moving::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_Follow_Path());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Rand2_Moving::getAction() bad_alloc memory error" << std::endl;
    }
}
