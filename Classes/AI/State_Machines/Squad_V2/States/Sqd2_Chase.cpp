#include "Sqd2_Chase.h"

Sqd2_Chase::Sqd2_Chase():State(constants::STATE_CHASE)
{
    try
    {
        _transitions.push_back(new Sqd2_ChaseToAttack());
        _transitions.push_back(new Sqd2_ChaseToSearch());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Sqd2_Chase() bad_alloc memory error" << std::endl;
    }
}

void Sqd2_Chase::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_Follow_Path());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Sqd2_Chase::getAction() bad_alloc memory error" << std::endl;
    }
}
