#include "M_UTHREE_0.h"

M_UTHREE_0::M_UTHREE_0() : Method() {
    methodId = 0;
    subTasks.push_back(new Task_SquadOneToVulA());
    subTasks.push_back(new Task_SquadTwoToVulA());
    subTasks.push_back(new Task_SquadThreeToVulB());
}

bool M_UTHREE_0::checkConditions(WorldState worldState) {
    return (worldState.idleCount() == 3 && worldState.healthyCount() == 3);
}
