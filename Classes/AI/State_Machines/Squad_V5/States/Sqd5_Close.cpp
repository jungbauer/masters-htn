#include "Sqd5_Close.h"

Sqd5_Close::Sqd5_Close():State(constants::STATE_CLOSE)
{
    try
    {
        _transitions.push_back(new Sqd5_CloseToAttack());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Sqd5_Close() bad_alloc memory error" << std::endl;
    }
}

void Sqd5_Close::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_Follow_Path());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Sqd5_Close::getAction() bad_alloc memory error" << std::endl;
    }
}
