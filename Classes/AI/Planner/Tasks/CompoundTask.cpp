#include "CompoundTask.h"

CompoundTask::CompoundTask() : Task(constants::PT_TYPE_COMPOUND, constants::PT_NONE) {}

CompoundTask::CompoundTask(constants::PlannerTasks name) : Task(constants::PT_TYPE_COMPOUND, name) {}
