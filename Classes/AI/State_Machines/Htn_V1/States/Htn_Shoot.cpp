#include "Htn_Shoot.h"

Htn_Shoot::Htn_Shoot():State(constants::STATE_SHOOT)
{
    try
    {
        _transitions.push_back(new Htn_ShootToAttack());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Htn_Shoot() bad_alloc memory error" << std::endl;
    }
}

void Htn_Shoot::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_Fire());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Htn_Shoot::getAction() bad_alloc memory error" << std::endl;
    }
}
