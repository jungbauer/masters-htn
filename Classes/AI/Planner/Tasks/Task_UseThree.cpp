#include "Task_UseThree.h"

Task_UseThree::Task_UseThree() : CompoundTask(constants::PT_USE_THREE) {
    methods.push_back(new M_UTHREE_0());
    methods.push_back(new M_UTHREE_1());
    methods.push_back(new M_UTHREE_2());
    methods.push_back(new M_UTHREE_3());
}
