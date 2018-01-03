#include "Sqd4_IdleToChase.h"

Sqd4_IdleToChase::Sqd4_IdleToChase():Transition(constants::STATE_CHASE)
{

}

bool Sqd4_IdleToChase::isTriggered(AI_Info &info)
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

void Sqd4_IdleToChase::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_Set_Support_Location());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Sqd4_IdleToChase::getAction() bad_alloc memory error" << std::endl;
    }
}
