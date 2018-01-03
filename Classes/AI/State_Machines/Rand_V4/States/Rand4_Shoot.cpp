#include "Rand4_Shoot.h"

Rand4_Shoot::Rand4_Shoot():State(constants::STATE_SHOOT)
{
    try
    {
        _transitions.push_back(new Rand4_ShootToAttack());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Rand4_Shoot() bad_alloc memory error" << std::endl;
    }
}

void Rand4_Shoot::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_Fire());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Rand4_Shoot::getAction() bad_alloc memory error" << std::endl;
    }
}
