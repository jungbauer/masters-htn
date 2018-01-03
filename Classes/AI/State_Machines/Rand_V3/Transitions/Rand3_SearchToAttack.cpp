#include "Rand3_SearchToAttack.h"

Rand3_SearchToAttack::Rand3_SearchToAttack():Transition(constants::STATE_ATTACK)
{

}

bool Rand3_SearchToAttack::isTriggered(AI_Info &info)
{
    // IF there are visible enemies OR agent has finished spinning in a circle.
    if((info.visibleEnemiesCheck() == true) || (info.search_rotation >= 360))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Rand3_SearchToAttack::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_None());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Rand3_SearchToAttack::getAction() bad_alloc memory error" << std::endl;
    }
}

