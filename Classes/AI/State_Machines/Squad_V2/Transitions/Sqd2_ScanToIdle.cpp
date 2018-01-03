#include "Sqd2_ScanToIdle.h"

Sqd2_ScanToIdle::Sqd2_ScanToIdle():Transition(constants::STATE_IDLE)
{

}

bool Sqd2_ScanToIdle::isTriggered(AI_Info &info)
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

void Sqd2_ScanToIdle::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_Reset_Engaged());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Sqd2_ScanToIdle::getAction() bad_alloc memory error" << std::endl;
    }
}
