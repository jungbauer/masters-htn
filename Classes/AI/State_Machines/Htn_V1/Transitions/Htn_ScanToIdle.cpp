#include "Htn_ScanToIdle.h"

Htn_ScanToIdle::Htn_ScanToIdle():Transition(constants::STATE_IDLE)
{

}

bool Htn_ScanToIdle::isTriggered(AI_Info &info)
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

void Htn_ScanToIdle::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_Reset_Engaged());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Htn_ScanToIdle::getAction() bad_alloc memory error" << std::endl;
    }
}
