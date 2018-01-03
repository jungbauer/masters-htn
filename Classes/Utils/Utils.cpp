#include "Utils.h"

namespace utils
{
    bool sphere_Sphere_SweepTest(float ra, VecXY_Float A0, VecXY_Float A1, float rb, VecXY_Float B0, VecXY_Float B1)
    {
        // http://www.gamasutra.com/view/feature/131790/simple_intersection_tests_for_games.php?page=2
        // leftout the swap code because i dont need to know the times of collision

//        float u0 = 0;
//        float u1 = 0;

//        VecXY_Float va = A1 - A0;
//        VecXY_Float vb = B1 - B0;
        VecXY_Float AB = B0 - A0;

//        VecXY_Float vab = vb - va;
        float rab = ra + rb;
//        float a = vab.getX()*vab.getX() + vab.getY()*vab.getY(); // dot product of vab * vab
//        float b = 2*(vab.getX()*AB.getX() + vab.getY()*AB.getY()); // 2 * (vab dot AB)
        float dot_AB = AB.getX()*AB.getX() + AB.getY()*AB.getY();
        float rab_2 = rab*rab;
//        float c = dot_AB - rab_2;

        //check if they're currently overlapping
        if(dot_AB <= rab_2)
        {
            return true;
        }

        //check if they hit each other during the frame
//        if(QuadraticFormula(a,b,c,u0,u1))
//        {
//            return true;
//        }

        return false;
    }

    // Return true if r1 and r2 are real
    bool QuadraticFormula(float a, float b, float c, float& r1, float& r2)
    {
        float q = b*b - 4*a*c;
        if(q >= 0)
        {
            float sq = sqrt(q);
            float d = 1 / (2*a);
            r1 = ( -b + sq ) * d;
            r2 = ( -b - sq ) * d;
            return true;//real roots
        }
        else
        {
            return false;//complex roots
        }
    }

    bool check_collision(Box A, Box B)
    {
        //The sides of the rectangles
        int leftA, leftB;
        int rightA, rightB;
        int topA, topB;
        int bottomA, bottomB;

        //Calculate the sides of rect A
        leftA = A.get_x();
        rightA = A.get_x() + A.get_w();
        topA = A.get_y();
        bottomA = A.get_y() + A.get_h();

        //Calculate the sides of rect B
        leftB = B.get_x();
        rightB = B.get_x() + B.get_w();
        topB = B.get_y();
        bottomB = B.get_y() + B.get_h();

        //If any of the sides from A are outside of B
        if( bottomA <= topB )
        {
            return false;
        }

        if( topA >= bottomB )
        {
            return false;
        }

        if( rightA <= leftB )
        {
            return false;
        }

        if( leftA >= rightB )
        {
            return false;
        }

        //If none of the sides from A are outside B
        return true;
    }

    bool check_collision(Box A, float radius, VecXY_Float circle_pos)
    {
        // Using Arvo's algorithm from http://www.gamasutra.com/view/feature/131790/simple_intersection_tests_for_games.php?page=4

        // var setup
        float box_min_x = (float) A.get_x();
        float box_max_x = (float) A.get_x() + (float) A.get_w();
        float box_min_y = (float) A.get_y();
        float box_max_y = (float) A.get_y() + (float) A.get_h();
        float separation = 0.0;
        float distance_squared = 0.0;

        // x checks
        if(circle_pos.getX() < box_min_x)
        {
            separation = circle_pos.getX() - box_min_x;
            distance_squared += separation * separation;
        }
        else if(circle_pos.getX() > box_max_x)
        {
            separation = circle_pos.getX() - box_max_x;
            distance_squared += separation * separation;
        }

        // y checks
        if(circle_pos.getY() < box_min_y)
        {
            separation = circle_pos.getY() - box_min_y;
            distance_squared += separation * separation;
        }
        else if(circle_pos.getY() > box_max_y)
        {
            separation = circle_pos.getY() - box_max_y;
            distance_squared += separation * separation;
        }

        // if radius*radius <= distance_squared we have a collision
        return distance_squared <= radius*radius;
    }

    /* Converts an integer to a string
    -----------------------------------
    Parameters - an integer
    Returns - a string
    */
    std::string intToString(int in)
    {
        std::stringstream out;
        out << in;
        return out.str();
    }

    /* Converts a float to a string
    -----------------------------------
    Parameters - a float
    Returns - a string
    */
    std::string floatToString(float in)
    {
        std::stringstream out;
        out << in;
        return out.str();
    }

    /* Converts a boolean to a string
    -----------------------------------
    Parameters - a boolean
    Returns - a string
    */
    std::string boolToString(bool in)
    {
        std::string out = "false";

        if(in)
        {
            out = "true";
        }

        return out;
    }

    /* Produces a random integer between lowest and highest
    -----------------------------------
    Parameters  - lowest - minimum value
                - highest - maximum value
    Returns - an integer
    */
    int getRandomInt(int lowest, int highest)
    {
        //http://www.daniweb.com/software-development/cpp/threads/1769/c-random-numbers
        //int range=(highest-lowest)+1;

        // Float casting to make this work.(float)
        //int random_integer = lowest+(range* ((float)rand()) / ((float)(RAND_MAX + 1.0)));

        return lowest+(((highest-lowest)+1)* ((float)rand()) / ((float)(RAND_MAX + 1.0)));
    }

    void trimAngle(float& angle)
    {
        if(angle < 0.0)
        {
            angle += 360.0;
        }
        else if(angle >= 360.0)
        {
            angle -= 360.0;
        }
    }

    float calculateAngle(VecXY_Float current, VecXY_Float target)
    {
        float angle = 0.0;
        VecXY_Float diff = current - target;

        angle = atan2(diff.getY(),diff.getX())*180/constants::PIE;

    //    std::cerr << std::endl << "AI pos: " << _AI.currentPos.getX()<< " , " << _AI.currentPos.getY() << std::endl;
    //    std::cerr << "target pos: " << target.getX()<< " , " << target.getY() << std::endl;
    //    std::cerr << "angle1: " << angle << std::endl;

        angle += 180.0; // shifted because of the coordinate system used.

        //std::cerr << "angle: " << angle << std::endl;
        utils::trimAngle(angle);

        return angle;
    }

    bool check_Point_Within_Box(Box A, VecXY_Float point)
    {
        bool within = false;

        if((point.getX() > A.get_x()) && (point.getY() > A.get_y()) && (point.getX() < (A.get_x() + A.get_w())) && (point.getY() < (A.get_y() + A.get_h())))
        {
            within = true;
        }

        return within;
    }
}
