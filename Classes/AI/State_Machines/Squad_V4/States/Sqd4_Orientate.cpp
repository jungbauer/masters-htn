#include "Sqd4_Orientate.h"

Sqd4_Orientate::Sqd4_Orientate():State(constants::STATE_ORIENTATE)
{
    try
    {
        _transitions.push_back(new Sqd4_OrientateToAttack());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Sqd4_Orientate() bad_alloc memory error" << std::endl;
    }
}

void Sqd4_Orientate::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_Orient());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Sqd4_Orientate::getAction() bad_alloc memory error" << std::endl;
    }
}
