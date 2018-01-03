#include "Sqd5_Moving.h"

Sqd5_Moving::Sqd5_Moving():State(constants::STATE_MOVING)
{
    try
    {
        _transitions.push_back(new Sqd5_MoveToChase());
        _transitions.push_back(new Sqd5_MoveToIdle());
        // Transition to attack handled by Agent.
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Sqd5_Moving() bad_alloc memory error" << std::endl;
    }
}

void Sqd5_Moving::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_Follow_Path());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Sqd5_Moving::getAction() bad_alloc memory error" << std::endl;
    }
}
