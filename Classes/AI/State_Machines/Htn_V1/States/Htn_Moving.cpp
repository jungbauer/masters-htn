#include "Htn_Moving.h"

Htn_Moving::Htn_Moving():State(constants::STATE_MOVING)
{
    try
    {
        _transitions.push_back(new Htn_MoveToScan());
        _transitions.push_back(new Htn_MoveToIdle());
        // Transition to attack handled by Agent.
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Htn_Moving() bad_alloc memory error" << std::endl;
    }
}

void Htn_Moving::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_Follow_Path_Orient());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Htn_Moving::getAction() bad_alloc memory error" << std::endl;
    }
}
