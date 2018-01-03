#include "Rand3_ChaseToSearch.h"

Rand3_ChaseToSearch::Rand3_ChaseToSearch():Transition(constants::STATE_SEARCH)
{

}

bool Rand3_ChaseToSearch::isTriggered(AI_Info &info)
{
    if(info.path.complete_Check() == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Rand3_ChaseToSearch::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_Setup_Search());
    }
    catch(std::bad_alloc& e)
    {
       std::cerr << "Rand3_ChaseToSearch::getAction() bad_alloc memory error" << std::endl;
    }
}
