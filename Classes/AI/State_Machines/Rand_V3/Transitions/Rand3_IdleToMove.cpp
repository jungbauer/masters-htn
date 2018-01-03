#include "Rand3_IdleToMove.h"

Rand3_IdleToMove::Rand3_IdleToMove():Transition(constants::STATE_MOVING)
{

}

bool Rand3_IdleToMove::isTriggered(AI_Info &info)
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

void Rand3_IdleToMove::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_Rand_Pathfind());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Rand3_IdleToMove::getAction() bad_alloc memory error" << std::endl;
    }
}
