#include "Sqd5_Chase.h"

Sqd5_Chase::Sqd5_Chase():State(constants::STATE_CHASE)
{
    try
    {
        _transitions.push_back(new Sqd5_ChaseToAttack());
        _transitions.push_back(new Sqd5_ChaseToSearch());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Sqd5_Chase() bad_alloc memory error" << std::endl;
    }
}

void Sqd5_Chase::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_Follow_Path());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Sqd5_Chase::getAction() bad_alloc memory error" << std::endl;
    }
}
