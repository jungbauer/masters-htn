#include "Sqd3_ChaseToSearch.h"

Sqd3_ChaseToSearch::Sqd3_ChaseToSearch():Transition(constants::STATE_SEARCH)
{

}

bool Sqd3_ChaseToSearch::isTriggered(AI_Info &info)
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

void Sqd3_ChaseToSearch::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_Setup_Search());
    }
    catch(std::bad_alloc& e)
    {
       std::cerr << "Sqd3_ChaseToSearch::getAction() bad_alloc memory error" << std::endl;
    }
}
