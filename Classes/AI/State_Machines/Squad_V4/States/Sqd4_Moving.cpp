#include "Sqd4_Moving.h"

Sqd4_Moving::Sqd4_Moving():State(constants::STATE_MOVING)
{
    try
    {
        _transitions.push_back(new Sqd4_MoveToChase());
        _transitions.push_back(new Sqd4_MoveToIdle());
        // Transition to attack handled by Agent.
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Sqd4_Moving() bad_alloc memory error" << std::endl;
    }
}

void Sqd4_Moving::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_Follow_Path());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Sqd4_Moving::getAction() bad_alloc memory error" << std::endl;
    }
}
