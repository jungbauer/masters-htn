#include "M_UTHREE_2.h"

M_UTHREE_2::M_UTHREE_2() : Method() {
    methodId = 2;
    subTasks.push_back(new Task_FirstIdleToEngaged());
    subTasks.push_back(new Task_SecondIdleToEngaged());
}

bool M_UTHREE_2::checkConditions(WorldState worldState) {
    return (worldState.idleCount() == 2 && worldState.engagedCount() == 1);
}
