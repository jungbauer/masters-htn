#include "Sqd3_Search.h"

Sqd3_Search::Sqd3_Search():State(constants::STATE_SEARCH)
{
    try
    {
        _transitions.push_back(new Sqd3_SearchToAttack());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Sqd3_Search() bad_alloc memory error" << std::endl;
    }
}

void Sqd3_Search::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_Spot_Search());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Sqd3_Search::getAction() bad_alloc memory error" << std::endl;
    }
}
