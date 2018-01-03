#include "M_BC_1.h"

M_BC_1::M_BC_1() : Method() {
    methodId = 1;
    subTasks.push_back(new Task_UseTwo());
}

bool M_BC_1::checkConditions(WorldState worldState) {
    return worldState.aliveSquads() == 2;
}
