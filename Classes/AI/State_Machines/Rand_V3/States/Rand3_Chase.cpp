#include "Rand3_Chase.h"

Rand3_Chase::Rand3_Chase():State(constants::STATE_CHASE)
{
    try
    {
        _transitions.push_back(new Rand3_ChaseToAttack());
        _transitions.push_back(new Rand3_ChaseToSearch());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Rand3_Chase() bad_alloc memory error" << std::endl;
    }
}

void Rand3_Chase::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_Follow_Path());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Rand3_Chase::getAction() bad_alloc memory error" << std::endl;
    }
}
