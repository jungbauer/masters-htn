#include "M_UTHREE_3.h"

M_UTHREE_3::M_UTHREE_3() : Method() {
    methodId = 3;
    subTasks.push_back(new Task_FirstIdleToClosestEngaged());
}

bool M_UTHREE_3::checkConditions(WorldState worldState) {
    return (worldState.idleCount() == 1 && worldState.engagedCount() == 2);
}
