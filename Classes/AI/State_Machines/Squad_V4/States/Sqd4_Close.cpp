#include "Sqd4_Close.h"

Sqd4_Close::Sqd4_Close():State(constants::STATE_CLOSE)
{
    try
    {
        _transitions.push_back(new Sqd4_CloseToAttack());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Sqd4_Close() bad_alloc memory error" << std::endl;
    }
}

void Sqd4_Close::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_Follow_Path());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Sqd4_Close::getAction() bad_alloc memory error" << std::endl;
    }
}
