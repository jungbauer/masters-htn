#include "Rand2_Shoot.h"

Rand2_Shoot::Rand2_Shoot():State(constants::STATE_SHOOT)
{
    try
    {
        _transitions.push_back(new Rand2_ShootToAttack());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Rand2_Shoot() bad_alloc memory error" << std::endl;
    }
}

void Rand2_Shoot::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_Fire());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Rand2_Shoot::getAction() bad_alloc memory error" << std::endl;
    }
}
