#include "Task_UseTwo.h"

Task_UseTwo::Task_UseTwo() : CompoundTask(constants::PT_USE_TWO) {
    methods.push_back(new M_UTWO_0());
    methods.push_back(new M_UTWO_1());
}
