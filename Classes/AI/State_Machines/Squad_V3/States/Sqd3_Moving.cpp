#include "Sqd3_Moving.h"

Sqd3_Moving::Sqd3_Moving():State(constants::STATE_MOVING)
{
    try
    {
        _transitions.push_back(new Sqd3_MoveToScan());
        _transitions.push_back(new Sqd3_MoveToChase());
        _transitions.push_back(new Sqd3_MoveToIdle());
        // Transition to attack handled by Agent.
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Sqd3_Moving() bad_alloc memory error" << std::endl;
    }
}

void Sqd3_Moving::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_Follow_Path());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Sqd3_Moving::getAction() bad_alloc memory error" << std::endl;
    }
}
