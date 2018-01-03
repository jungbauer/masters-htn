#include "Sqd3_Orientate.h"

Sqd3_Orientate::Sqd3_Orientate():State(constants::STATE_ORIENTATE)
{
    try
    {
        _transitions.push_back(new Sqd3_OrientateToAttack());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Sqd3_Orientate() bad_alloc memory error" << std::endl;
    }
}

void Sqd3_Orientate::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_Orient());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Sqd3_Orientate::getAction() bad_alloc memory error" << std::endl;
    }
}
