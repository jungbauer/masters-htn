#ifndef COMPOUNDTASK_H
#define COMPOUNDTASK_H


#include "Task.h"
#include "../Methods/Method.h"

class CompoundTask : public Task {
    public:
        CompoundTask();
        CompoundTask(constants::PlannerTasks name);

        vector<Method*> methods;

};


#endif
