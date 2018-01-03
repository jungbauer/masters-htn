#ifndef ACTION_H
#define ACTION_H

#include "../../Utils/Constants.h"

using namespace std;

class Action
{
    public:
        Action();
        Action(constants::Actions type);
        virtual ~Action(){}; //http://www.gamedev.net/topic/502940-c-delete-base-class-pointer-which-actually-holds-a-derived-class-pointer/

        constants::Actions action_type;

    private:
};

#endif
