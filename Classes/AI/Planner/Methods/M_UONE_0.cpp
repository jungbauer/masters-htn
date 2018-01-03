#include "M_UONE_0.h"

M_UONE_0::M_UONE_0() : Method() {
    methodId = 0;
    subTasks.push_back(new Task_FirstIdleToVulA());
}

bool M_UONE_0::checkConditions(WorldState worldState) {
    return worldState.idleCount() == 1;
}
