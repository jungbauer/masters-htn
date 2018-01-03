#include "Sqd2_MoveToIdle.h"

Sqd2_MoveToIdle::Sqd2_MoveToIdle():Transition(constants::STATE_IDLE)
{

}

bool Sqd2_MoveToIdle::isTriggered(AI_Info &info)
{
    if(info.path.complete_Check() == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Sqd2_MoveToIdle::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_None());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Sqd2_MoveToIdle::getAction() bad_alloc memory error" << std::endl;
    }
}
