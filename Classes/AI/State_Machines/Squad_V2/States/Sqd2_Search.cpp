#include "Sqd2_Search.h"

Sqd2_Search::Sqd2_Search():State(constants::STATE_SEARCH)
{
    try
    {
        _transitions.push_back(new Sqd2_SearchToAttack());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Sqd2_Search() bad_alloc memory error" << std::endl;
    }
}

void Sqd2_Search::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_Spot_Search());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Sqd2_Search::getAction() bad_alloc memory error" << std::endl;
    }
}
