#include "Htn_Orientate.h"

Htn_Orientate::Htn_Orientate():State(constants::STATE_ORIENTATE)
{
    try
    {
        _transitions.push_back(new Htn_OrientateToAttack());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Htn_Orientate() bad_alloc memory error" << std::endl;
    }
}

void Htn_Orientate::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_Orient());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Htn_Orientate::getAction() bad_alloc memory error" << std::endl;
    }
}
