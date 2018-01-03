#include "Rand4_ScanToIdle.h"

Rand4_ScanToIdle::Rand4_ScanToIdle():Transition(constants::STATE_IDLE)
{

}

bool Rand4_ScanToIdle::isTriggered(AI_Info &info)
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

void Rand4_ScanToIdle::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_Reset_Engaged());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Rand4_ScanToIdle::getAction() bad_alloc memory error" << std::endl;
    }
}
