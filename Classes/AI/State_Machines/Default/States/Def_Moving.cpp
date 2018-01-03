#include "Def_Moving.h"

Def_Moving::Def_Moving():State(constants::STATE_MOVING)
{
    try
    {
        _transitions.push_back(new Def_MoveToIdle());
        // Transition to attack handled by Agent.
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Def_Moving() bad_alloc memory error" << std::endl;
    }
}

void Def_Moving::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_Follow_Path());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Def_Moving::getAction() bad_alloc memory error" << std::endl;
    }
}
