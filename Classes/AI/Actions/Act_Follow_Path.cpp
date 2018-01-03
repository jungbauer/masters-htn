#include "Act_Follow_Path.h"

Act_Follow_Path::Act_Follow_Path() : Action(constants::ACT_FOLLOW_PATH)
{}

//bool Act_Follow_Path::pop_Check(VecXY_Float pos, float margin)
//{
//    bool reached = false;
//    VecXY_Float diff;
//    diff = pos - end_point;
//
//    if(diff.length() <= margin)
//    {
//        reached = true;
//    }
//    return  reached;
//}
