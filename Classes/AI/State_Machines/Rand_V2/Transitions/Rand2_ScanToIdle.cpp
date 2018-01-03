#include "Rand2_ScanToIdle.h"

Rand2_ScanToIdle::Rand2_ScanToIdle():Transition(constants::STATE_IDLE)
{

}

bool Rand2_ScanToIdle::isTriggered(AI_Info &info)
{
    if(info.orientationCheck(info.bullet_pos, 1) == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Rand2_ScanToIdle::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_Reset_Engaged());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Rand2_ScanToIdle::getAction() bad_alloc memory error" << std::endl;
    }
}
