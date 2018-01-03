#include "Sqd5_Shoot.h"

Sqd5_Shoot::Sqd5_Shoot():State(constants::STATE_SHOOT)
{
    try
    {
        _transitions.push_back(new Sqd5_ShootToAttack());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Sqd5_Shoot() bad_alloc memory error" << std::endl;
    }
}

void Sqd5_Shoot::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_Fire());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Sqd5_Shoot::getAction() bad_alloc memory error" << std::endl;
    }
}
