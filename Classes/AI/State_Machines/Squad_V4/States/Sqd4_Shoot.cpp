#include "Sqd4_Shoot.h"

Sqd4_Shoot::Sqd4_Shoot():State(constants::STATE_SHOOT)
{
    try
    {
        _transitions.push_back(new Sqd4_ShootToAttack());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Sqd4_Shoot() bad_alloc memory error" << std::endl;
    }
}

void Sqd4_Shoot::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_Fire());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Sqd4_Shoot::getAction() bad_alloc memory error" << std::endl;
    }
}
