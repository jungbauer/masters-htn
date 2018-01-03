#include "Rand4_IdleToMove.h"

Rand4_IdleToMove::Rand4_IdleToMove():Transition(constants::STATE_MOVING)
{

}

bool Rand4_IdleToMove::isTriggered(AI_Info &info)
{
    if(info.visibleEnemiesCheck() == false)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Rand4_IdleToMove::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_Rand_Pathfind());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Rand4_IdleToMove::getAction() bad_alloc memory error" << std::endl;
    }
}
