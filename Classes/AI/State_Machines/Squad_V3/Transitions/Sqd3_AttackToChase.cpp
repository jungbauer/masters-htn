#include "Sqd3_AttackToChase.h"

Sqd3_AttackToChase::Sqd3_AttackToChase():Transition(constants::STATE_CHASE)
{}

bool Sqd3_AttackToChase::isTriggered(AI_Info &info)
{
    // IF no seen enemies && current target is not dead && target pos is within search range
    if((info.visibleEnemiesCheck() == false) && (info.deadEnemiesCheck(info.attack_target.agent_ID) == false) && (info.searchRangeCheck(info.attack_target, 1)))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Sqd3_AttackToChase::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_Pathfind(info.attack_target.current_position));
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Sqd3_AttackToChase::getAction() bad_alloc memory error" << std::endl;
    }
}

