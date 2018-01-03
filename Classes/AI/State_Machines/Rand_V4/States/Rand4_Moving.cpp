#include "Rand4_Moving.h"

Rand4_Moving::Rand4_Moving():State(constants::STATE_MOVING)
{
    try
    {
        _transitions.push_back(new Rand4_MoveToScan());
        _transitions.push_back(new Rand4_MoveToIdle());
        // Transition to attack handled by Agent.
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Rand4_Moving() bad_alloc memory error" << std::endl;
    }
}

void Rand4_Moving::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_Follow_Path());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Rand4_Moving::getAction() bad_alloc memory error" << std::endl;
    }
}
