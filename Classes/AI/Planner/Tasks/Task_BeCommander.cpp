#include "Task_BeCommander.h"

Task_BeCommander::Task_BeCommander() : CompoundTask(constants::PT_BE_COMMANDER) {
    methods.push_back(new M_BC_0());
    methods.push_back(new M_BC_1());
    methods.push_back(new M_BC_2());
}
