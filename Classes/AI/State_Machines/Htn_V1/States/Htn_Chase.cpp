#include "Htn_Chase.h"

Htn_Chase::Htn_Chase():State(constants::STATE_CHASE)
{
    try
    {
        _transitions.push_back(new Htn_ChaseToAttack());
        _transitions.push_back(new Htn_ChaseToSearch());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Htn_Chase() bad_alloc memory error" << std::endl;
    }
}

void Htn_Chase::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_Follow_Path());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Htn_Chase::getAction() bad_alloc memory error" << std::endl;
    }
}
