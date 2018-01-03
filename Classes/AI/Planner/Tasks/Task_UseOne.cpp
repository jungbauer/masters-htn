#include "Task_UseOne.h"

Task_UseOne::Task_UseOne() : CompoundTask(constants::PT_USE_ONE) {
    methods.push_back(new M_UONE_0());
}
