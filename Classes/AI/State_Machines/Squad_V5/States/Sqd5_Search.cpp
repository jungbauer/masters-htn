#include "Sqd5_Search.h"

Sqd5_Search::Sqd5_Search():State(constants::STATE_SEARCH)
{
    try
    {
        _transitions.push_back(new Sqd5_SearchToAttack());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Sqd5_Search() bad_alloc memory error" << std::endl;
    }
}

void Sqd5_Search::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_Spot_Search());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Sqd5_Search::getAction() bad_alloc memory error" << std::endl;
    }
}
