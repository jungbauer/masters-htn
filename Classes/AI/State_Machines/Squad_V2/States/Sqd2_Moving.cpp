#include "Sqd2_Moving.h"

Sqd2_Moving::Sqd2_Moving():State(constants::STATE_MOVING)
{
    try
    {
        _transitions.push_back(new Sqd2_MoveToScan());
        _transitions.push_back(new Sqd2_MoveToIdle());
        // Transition to attack handled by Agent.
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Sqd2_Moving() bad_alloc memory error" << std::endl;
    }
}

void Sqd2_Moving::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_Follow_Path());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Sqd2_Moving::getAction() bad_alloc memory error" << std::endl;
    }
}
