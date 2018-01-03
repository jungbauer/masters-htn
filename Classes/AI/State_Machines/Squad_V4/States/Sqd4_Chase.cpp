#include "Sqd4_Chase.h"

Sqd4_Chase::Sqd4_Chase():State(constants::STATE_CHASE)
{
    try
    {
        _transitions.push_back(new Sqd4_ChaseToAttack());
        _transitions.push_back(new Sqd4_ChaseToSearch());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Sqd4_Chase() bad_alloc memory error" << std::endl;
    }
}

void Sqd4_Chase::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_Follow_Path());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Sqd4_Chase::getAction() bad_alloc memory error" << std::endl;
    }
}
