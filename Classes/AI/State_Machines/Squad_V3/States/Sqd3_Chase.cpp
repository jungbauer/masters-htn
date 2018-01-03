#include "Sqd3_Chase.h"

Sqd3_Chase::Sqd3_Chase():State(constants::STATE_CHASE)
{
    try
    {
        _transitions.push_back(new Sqd3_ChaseToAttack());
        _transitions.push_back(new Sqd3_ChaseToSearch());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Sqd3_Chase() bad_alloc memory error" << std::endl;
    }
}

void Sqd3_Chase::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_Follow_Path());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Sqd3_Chase::getAction() bad_alloc memory error" << std::endl;
    }
}
