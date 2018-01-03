#include "Rand3_Search.h"

Rand3_Search::Rand3_Search():State(constants::STATE_SEARCH)
{
    try
    {
        _transitions.push_back(new Rand3_SearchToAttack());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Rand3_Search() bad_alloc memory error" << std::endl;
    }
}

void Rand3_Search::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_Spot_Search());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Rand3_Search::getAction() bad_alloc memory error" << std::endl;
    }
}
