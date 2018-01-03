#include "Rand4_Search.h"

Rand4_Search::Rand4_Search():State(constants::STATE_SEARCH)
{
    try
    {
        _transitions.push_back(new Rand4_SearchToAttack());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Rand4_Search() bad_alloc memory error" << std::endl;
    }
}

void Rand4_Search::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_Spot_Search());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Rand4_Search::getAction() bad_alloc memory error" << std::endl;
    }
}
