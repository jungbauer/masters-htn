#include "M_UTHREE_1.h"

M_UTHREE_1::M_UTHREE_1() : Method() {
    methodId = 1;
    subTasks.push_back(new Task_SquadOneToVulA());
    subTasks.push_back(new Task_SquadTwoToVulA());
    subTasks.push_back(new Task_SquadThreeToVulA());
}

bool M_UTHREE_1::checkConditions(WorldState worldState) {
    return (worldState.idleCount() == 3 && worldState.healthyCount() < 3);
}
