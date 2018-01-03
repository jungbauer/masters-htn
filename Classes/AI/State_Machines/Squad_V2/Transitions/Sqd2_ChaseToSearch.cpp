#include "Sqd2_ChaseToSearch.h"

Sqd2_ChaseToSearch::Sqd2_ChaseToSearch():Transition(constants::STATE_SEARCH)
{

}

bool Sqd2_ChaseToSearch::isTriggered(AI_Info &info)
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

void Sqd2_ChaseToSearch::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_Setup_Search());
    }
    catch(std::bad_alloc& e)
    {
       std::cerr << "Sqd2_ChaseToSearch::getAction() bad_alloc memory error" << std::endl;
    }
}
