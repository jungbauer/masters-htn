#include "Rand3_Close.h"

Rand3_Close::Rand3_Close():State(constants::STATE_CLOSE)
{
    try
    {
        _transitions.push_back(new Rand3_CloseToAttack());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Rand3_Close() bad_alloc memory error" << std::endl;
    }
}

void Rand3_Close::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_Follow_Path());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Rand3_Close::getAction() bad_alloc memory error" << std::endl;
    }
}
