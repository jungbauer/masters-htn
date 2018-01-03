#include "Sqd4_ChaseToSearch.h"

Sqd4_ChaseToSearch::Sqd4_ChaseToSearch():Transition(constants::STATE_SEARCH)
{

}

bool Sqd4_ChaseToSearch::isTriggered(AI_Info &info)
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

void Sqd4_ChaseToSearch::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_Setup_Search());
    }
    catch(std::bad_alloc& e)
    {
       std::cerr << "Sqd4_ChaseToSearch::getAction() bad_alloc memory error" << std::endl;
    }
}
