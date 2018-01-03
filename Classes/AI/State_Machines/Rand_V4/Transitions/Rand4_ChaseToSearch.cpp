#include "Rand4_ChaseToSearch.h"

Rand4_ChaseToSearch::Rand4_ChaseToSearch():Transition(constants::STATE_SEARCH)
{

}

bool Rand4_ChaseToSearch::isTriggered(AI_Info &info)
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

void Rand4_ChaseToSearch::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_Setup_Search());
    }
    catch(std::bad_alloc& e)
    {
       std::cerr << "Rand4_ChaseToSearch::getAction() bad_alloc memory error" << std::endl;
    }
}
