#include "Htn_Close.h"

Htn_Close::Htn_Close():State(constants::STATE_CLOSE)
{
    try
    {
        _transitions.push_back(new Htn_CloseToAttack());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Htn_Close() bad_alloc memory error" << std::endl;
    }
}

void Htn_Close::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_Follow_Path());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Htn_Close::getAction() bad_alloc memory error" << std::endl;
    }
}
