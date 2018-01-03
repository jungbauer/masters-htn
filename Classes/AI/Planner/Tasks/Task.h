#ifndef PT_TASK_H
#define PT_TASK_H

#include "../../../Utils/Constants.h"

class Task {
    public:
        Task();
        Task(constants::PlannerTaskType type, constants::PlannerTasks name);

        constants::PlannerTaskType taskType;
        constants::PlannerTasks taskName;
};


#endif
