#include "Def_Close.h"

Def_Close::Def_Close():State(constants::STATE_CLOSE)
{
    try
    {
        _transitions.push_back(new Def_CloseToAttack());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Def_Close() bad_alloc memory error" << std::endl;
    }
}

void Def_Close::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_Follow_Path());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Def_Close::getAction() bad_alloc memory error" << std::endl;
    }
}
