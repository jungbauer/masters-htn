#ifndef COMMAND_INFLUENCE_H
#define COMMAND_INFLUENCE_H

#include <vector>
#include <cmath>
#include <iostream>
#include <cstdlib>

//#include "AI_Agent.h"

#include "../Utils/VecXY_Float.h"
#include "../Level.h"
#include "../Utils/Coord.h"

enum InfMapType
{
    FRIENDLY = 0,
    OPPONENT = 1,
    GENERAL = 2,
    TENSION = 3,
    VULNERABILITY = 4,
    NO_INF = 5
};

enum Influence_Type
{
    LINEAR = 0,
    EXPONENTIAL = 1
};

using namespace std;

class Command_Influence
{
    public:
        Command_Influence(int width, int height);
        Command_Influence();

        void set_Height(int h);
        void set_Width(int w);
        int get_Height();
        int get_Width();
        void setupInfluenceMaps();

        void calcInfluence(vector<VecXY_Float> &friendlies, vector<VecXY_Float> &enemies, Level &level, vector<vector<int> > &crude_visibility);

        void calcGeneralInfluence();
        void calcTension();
        void calcVulnerability();

        float applyFormula(Influence_Type type, float I0, VecXY_Float sourcePos, int column, int row);

        float infFormula_A(float &I0, VecXY_Float &sourcePos, int &column, int &row);
        float infFormula_B(float &I0, VecXY_Float &sourcePos, int &column, int &row);

        float maximum(float m1, float m2);
        float minimum(float m1, float m2);

        vector<vector<float> > friendly_inf;
        vector<vector<float> > opponent_inf;
        vector<vector<float> > general;
        vector<vector<float> > tension;
        vector<vector<float> > vulnerability;

        //TODO (general#1#) These should probably have coords attached at some point.
        float friendly_max;
        float friendly_min;

        float opponent_max;
        float opponent_min;

        float gen_max;
        float gen_min;

        float ten_max;
        float ten_min;

        float vul_max;
        float vul_min;

        Coord vulnerableA;
        float vulAVal;
        std::vector<Coord> vulAVisPts;

        Coord vulnerableB;
        float vulBVal;
        std::vector<Coord> vulBVisPts;

        Coord enemyMax;

    private:
        bool checkLOS(int x1, int y1, int x2, int y2, Level& level);

        int _width;
        int _height;
};

#endif
