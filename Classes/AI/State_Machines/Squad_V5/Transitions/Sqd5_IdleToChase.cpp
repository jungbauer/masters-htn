#include "Sqd5_IdleToChase.h"

Sqd5_IdleToChase::Sqd5_IdleToChase():Transition(constants::STATE_CHASE)
{

}

bool Sqd5_IdleToChase::isTriggered(AI_Info &info)
{
    if((info.engaged == false) && (info.squad_support_flag == true))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Sqd5_IdleToChase::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_Set_Support_Location());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Sqd5_IdleToChase::getAction() bad_alloc memory error" << std::endl;
    }
}
