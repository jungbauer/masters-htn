#include "Sqd5_Attack.h"

Sqd5_Attack::Sqd5_Attack():State(constants::STATE_ATTACK)
{
    try
    {
        _transitions.push_back(new Sqd5_AttackToIdle());
        _transitions.push_back(new Sqd5_AttackToOrientate());
        _transitions.push_back(new Sqd5_AttackToClose());
        _transitions.push_back(new Sqd5_AttackToShoot());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Sqd5_Attack() bad_alloc memory error" << std::endl;
    }
}

void Sqd5_Attack::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_Choose_Target_V2());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Sqd5_Attack::getAction() bad_alloc memory error" << std::endl;
    }
}
