#include "Rand3_ScanToIdle.h"

Rand3_ScanToIdle::Rand3_ScanToIdle():Transition(constants::STATE_IDLE)
{

}

bool Rand3_ScanToIdle::isTriggered(AI_Info &info)
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

void Rand3_ScanToIdle::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_Reset_Engaged());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Rand3_ScanToIdle::getAction() bad_alloc memory error" << std::endl;
    }
}
