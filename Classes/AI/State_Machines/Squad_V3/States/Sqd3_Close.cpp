#include "Sqd3_Close.h"

Sqd3_Close::Sqd3_Close():State(constants::STATE_CLOSE)
{
    try
    {
        _transitions.push_back(new Sqd3_CloseToAttack());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Sqd3_Close() bad_alloc memory error" << std::endl;
    }
}

void Sqd3_Close::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_Follow_Path());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Sqd3_Close::getAction() bad_alloc memory error" << std::endl;
    }
}
