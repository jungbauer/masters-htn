#include "Sqd2_Shoot.h"

Sqd2_Shoot::Sqd2_Shoot():State(constants::STATE_SHOOT)
{
    try
    {
        _transitions.push_back(new Sqd2_ShootToAttack());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Sqd2_Shoot() bad_alloc memory error" << std::endl;
    }
}

void Sqd2_Shoot::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_Fire());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Sqd2_Shoot::getAction() bad_alloc memory error" << std::endl;
    }
}
