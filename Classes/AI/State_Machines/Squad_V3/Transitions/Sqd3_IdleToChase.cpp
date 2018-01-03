#include "Sqd3_IdleToChase.h"

Sqd3_IdleToChase::Sqd3_IdleToChase():Transition(constants::STATE_CHASE)
{

}

bool Sqd3_IdleToChase::isTriggered(AI_Info &info)
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

void Sqd3_IdleToChase::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_Set_Support_Location());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Sqd3_IdleToChase::getAction() bad_alloc memory error" << std::endl;
    }
}
