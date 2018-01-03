#include "Rand4_Orientate.h"

Rand4_Orientate::Rand4_Orientate():State(constants::STATE_ORIENTATE)
{
    try
    {
        _transitions.push_back(new Rand4_OrientateToAttack());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Rand4_Orientate() bad_alloc memory error" << std::endl;
    }
}

void Rand4_Orientate::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_Orient());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Rand4_Orientate::getAction() bad_alloc memory error" << std::endl;
    }
}
