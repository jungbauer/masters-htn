#include "Rand3_Orientate.h"

Rand3_Orientate::Rand3_Orientate():State(constants::STATE_ORIENTATE)
{
    try
    {
        _transitions.push_back(new Rand3_OrientateToAttack());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Rand3_Orientate() bad_alloc memory error" << std::endl;
    }
}

void Rand3_Orientate::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_Orient());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Rand3_Orientate::getAction() bad_alloc memory error" << std::endl;
    }
}
