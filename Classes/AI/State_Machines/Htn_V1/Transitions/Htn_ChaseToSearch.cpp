#include "Htn_ChaseToSearch.h"

Htn_ChaseToSearch::Htn_ChaseToSearch():Transition(constants::STATE_SEARCH)
{

}

bool Htn_ChaseToSearch::isTriggered(AI_Info &info)
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

void Htn_ChaseToSearch::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_Setup_Search());
    }
    catch(std::bad_alloc& e)
    {
       std::cerr << "Htn_ChaseToSearch::getAction() bad_alloc memory error" << std::endl;
    }
}
