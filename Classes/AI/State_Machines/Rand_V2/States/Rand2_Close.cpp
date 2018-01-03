#include "Rand2_Close.h"

Rand2_Close::Rand2_Close():State(constants::STATE_CLOSE)
{
    try
    {
        _transitions.push_back(new Rand2_CloseToAttack());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Rand2_Close() bad_alloc memory error" << std::endl;
    }
}

void Rand2_Close::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_Follow_Path());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Rand2_Close::getAction() bad_alloc memory error" << std::endl;
    }
}
