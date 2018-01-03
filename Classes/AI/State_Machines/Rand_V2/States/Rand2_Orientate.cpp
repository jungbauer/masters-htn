#include "Rand2_Orientate.h"

Rand2_Orientate::Rand2_Orientate():State(constants::STATE_ORIENTATE)
{
    try
    {
        _transitions.push_back(new Rand2_OrientateToAttack());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Rand2_Orientate() bad_alloc memory error" << std::endl;
    }
}

void Rand2_Orientate::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_Orient());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Rand2_Orientate::getAction() bad_alloc memory error" << std::endl;
    }
}
