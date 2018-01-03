#include "Def_Shoot.h"

Def_Shoot::Def_Shoot():State(constants::STATE_SHOOT)
{
    try
    {
        _transitions.push_back(new Def_ShootToAttack());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Def_Shoot() bad_alloc memory error" << std::endl;
    }
}

void Def_Shoot::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_Fire());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Def_Shoot::getAction() bad_alloc memory error" << std::endl;
    }
}
