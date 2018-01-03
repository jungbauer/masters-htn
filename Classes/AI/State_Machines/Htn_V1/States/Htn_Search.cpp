#include "Htn_Search.h"

Htn_Search::Htn_Search():State(constants::STATE_SEARCH)
{
    try
    {
        _transitions.push_back(new Htn_SearchToAttack());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Htn_Search() bad_alloc memory error" << std::endl;
    }
}

void Htn_Search::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_Spot_Search());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Htn_Search::getAction() bad_alloc memory error" << std::endl;
    }
}
