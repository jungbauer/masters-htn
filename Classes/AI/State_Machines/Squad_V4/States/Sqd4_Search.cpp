#include "Sqd4_Search.h"

Sqd4_Search::Sqd4_Search():State(constants::STATE_SEARCH)
{
    try
    {
        _transitions.push_back(new Sqd4_SearchToAttack());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Sqd4_Search() bad_alloc memory error" << std::endl;
    }
}

void Sqd4_Search::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_Spot_Search());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Sqd4_Search::getAction() bad_alloc memory error" << std::endl;
    }
}
