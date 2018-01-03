#include "Rand4_Chase.h"

Rand4_Chase::Rand4_Chase():State(constants::STATE_CHASE)
{
    try
    {
        _transitions.push_back(new Rand4_ChaseToAttack());
        _transitions.push_back(new Rand4_ChaseToSearch());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Rand4_Chase() bad_alloc memory error" << std::endl;
    }
}

void Rand4_Chase::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_Follow_Path());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Rand4_Chase::getAction() bad_alloc memory error" << std::endl;
    }
}
