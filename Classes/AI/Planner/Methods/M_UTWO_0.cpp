#include "M_UTWO_0.h"

M_UTWO_0::M_UTWO_0() : Method() {
    methodId = 0;
    subTasks.push_back(new Task_FirstIdleToVulA());
    subTasks.push_back(new Task_SecondIdleToVulA());
}

bool M_UTWO_0::checkConditions(WorldState worldState) {
    return worldState.idleCount() == 2;
}
