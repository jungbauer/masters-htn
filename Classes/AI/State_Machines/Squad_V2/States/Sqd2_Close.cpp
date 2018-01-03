#include "Sqd2_Close.h"

Sqd2_Close::Sqd2_Close():State(constants::STATE_CLOSE)
{
    try
    {
        _transitions.push_back(new Sqd2_CloseToAttack());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Sqd2_Close() bad_alloc memory error" << std::endl;
    }
}

void Sqd2_Close::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_Follow_Path());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Sqd2_Close::getAction() bad_alloc memory error" << std::endl;
    }
}
