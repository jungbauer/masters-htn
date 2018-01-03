#include "M_BC_0.h"

M_BC_0::M_BC_0() : Method() {
    subTasks.push_back(new Task_UseThree());
    methodId = 0;
}

bool M_BC_0::checkConditions(WorldState worldState) {
    return worldState.aliveSquads() == 3;
}
