#include "Sqd1_Attack.h"

Sqd1_Attack::Sqd1_Attack():State(constants::STATE_ATTACK)
{
    try
    {
        _transitions.push_back(new Sqd1_AttackToIdle);
        _transitions.push_back(new Sqd1_AttackToOrientate);
        _transitions.push_back(new Sqd1_AttackToClose);
        _transitions.push_back(new Sqd1_AttackToShoot);
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Sqd1_Attack() bad_alloc memory error" << std::endl;
    }
}

void Sqd1_Attack::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_Choose_Target());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Sqd1_Attack::getAction() bad_alloc memory error" << std::endl;
    }
}
