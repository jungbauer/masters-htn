#include "Sqd3_Shoot.h"

Sqd3_Shoot::Sqd3_Shoot():State(constants::STATE_SHOOT)
{
    try
    {
        _transitions.push_back(new Sqd3_ShootToAttack());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Sqd3_Shoot() bad_alloc memory error" << std::endl;
    }
}

void Sqd3_Shoot::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_Fire());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Sqd3_Shoot::getAction() bad_alloc memory error" << std::endl;
    }
}
