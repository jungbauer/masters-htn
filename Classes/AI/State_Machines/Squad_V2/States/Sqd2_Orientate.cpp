#include "Sqd2_Orientate.h"

Sqd2_Orientate::Sqd2_Orientate():State(constants::STATE_ORIENTATE)
{
    try
    {
        _transitions.push_back(new Sqd2_OrientateToAttack());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Sqd2_Orientate() bad_alloc memory error" << std::endl;
    }
}

void Sqd2_Orientate::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_Orient());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Sqd2_Orientate::getAction() bad_alloc memory error" << std::endl;
    }
}
