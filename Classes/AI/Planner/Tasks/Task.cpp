#include "Task.h"

Task::Task() {
    taskType = constants::PT_TYPE_PRIMITIVE;
    taskName = constants::PT_NONE;
}

Task::Task(constants::PlannerTaskType type, constants::PlannerTasks name){
    taskType = type;
    taskName = name;
}
