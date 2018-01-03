#include "Sqd3_MoveToChase.h"

Sqd3_MoveToChase::Sqd3_MoveToChase():Transition(constants::STATE_CHASE)
{

}

bool Sqd3_MoveToChase::isTriggered(AI_Info &info)
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

void Sqd3_MoveToChase::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_Set_Support_Location());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Sqd3_MoveToChase::getAction() bad_alloc memory error" << std::endl;
    }
}
