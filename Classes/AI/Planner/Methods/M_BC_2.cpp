#include "M_BC_2.h"

M_BC_2::M_BC_2() : Method() {
    subTasks.push_back(new Task_UseOne());
    methodId = 2;
}

bool M_BC_2::checkConditions(WorldState worldState) {
    return worldState.aliveSquads() == 1;
}
