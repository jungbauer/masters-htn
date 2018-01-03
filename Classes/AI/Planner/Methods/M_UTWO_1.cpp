#include "M_UTWO_1.h"

M_UTWO_1::M_UTWO_1() : Method() {
    methodId = 1;
    subTasks.push_back(new Task_FirstIdleToEngaged());
}

bool M_UTWO_1::checkConditions(WorldState worldState) {
    return (worldState.idleCount() == 1 && worldState.engagedCount() == 1);
}
