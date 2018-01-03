#include "Rand3_Shoot.h"

Rand3_Shoot::Rand3_Shoot():State(constants::STATE_SHOOT)
{
    try
    {
        _transitions.push_back(new Rand3_ShootToAttack());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Rand3_Shoot() bad_alloc memory error" << std::endl;
    }
}

void Rand3_Shoot::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_Fire());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Rand3_Shoot::getAction() bad_alloc memory error" << std::endl;
    }
}
