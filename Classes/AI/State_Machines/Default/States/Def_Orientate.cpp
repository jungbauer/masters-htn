#include "Def_Orientate.h"

Def_Orientate::Def_Orientate():State(constants::STATE_ORIENTATE)
{
    try
    {
        _transitions.push_back(new Def_OrientateToAttack());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Def_Orientate() bad_alloc memory error" << std::endl;
    }
}

void Def_Orientate::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_Orient());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Def_Orientate::getAction() bad_alloc memory error" << std::endl;
    }
}
