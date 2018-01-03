#include "Rand4_Close.h"

Rand4_Close::Rand4_Close():State(constants::STATE_CLOSE)
{
    try
    {
        _transitions.push_back(new Rand4_CloseToAttack());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Rand4_Close() bad_alloc memory error" << std::endl;
    }
}

void Rand4_Close::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_Follow_Path());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Rand4_Close::getAction() bad_alloc memory error" << std::endl;
    }
}
