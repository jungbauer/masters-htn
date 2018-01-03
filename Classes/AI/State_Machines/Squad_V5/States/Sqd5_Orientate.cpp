#include "Sqd5_Orientate.h"

Sqd5_Orientate::Sqd5_Orientate():State(constants::STATE_ORIENTATE)
{
    try
    {
        _transitions.push_back(new Sqd5_OrientateToAttack());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Sqd5_Orientate() bad_alloc memory error" << std::endl;
    }
}

void Sqd5_Orientate::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_Orient());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Sqd5_Orientate::getAction() bad_alloc memory error" << std::endl;
    }
}
