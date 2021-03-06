#include "Sqd4_SearchToAttack.h"

Sqd4_SearchToAttack::Sqd4_SearchToAttack():Transition(constants::STATE_ATTACK)
{

}

bool Sqd4_SearchToAttack::isTriggered(AI_Info &info)
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

void Sqd4_SearchToAttack::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_None());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Sqd4_SearchToAttack::getAction() bad_alloc memory error" << std::endl;
    }
}

