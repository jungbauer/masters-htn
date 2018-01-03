#include "Command_Influence.h"

Command_Influence::Command_Influence(int width, int height)
{
    _width = width;
    _height = height;

    setupInfluenceMaps();

    friendly_max =0;
    friendly_min=0;

    opponent_max=0;
    opponent_min=0;

    gen_max=0;
    gen_min=0;

    ten_max=0;
    ten_min=0;

    vul_max=0;
    vul_min=0;

    vulnerableA = Coord(0,0);
    vulAVal = 0;
    vulnerableB = Coord(0,0);
    vulBVal = 0;
    enemyMax = Coord(0,0);
}

Command_Influence::Command_Influence()
{
    friendly_max =0;
    friendly_min=0;

    opponent_max=0;
    opponent_min=0;

    gen_max=0;
    gen_min=0;

    ten_max=0;
    ten_min=0;

    vul_max=0;
    vul_min=0;

    vulnerableA = Coord(0,0);
    vulnerableB = Coord(0,0);
    enemyMax = Coord(0,0);
}

void Command_Influence::set_Height(int h)
{
    _height = h;
}

void Command_Influence::set_Width(int w)
{
    _width = w;
}

int Command_Influence::get_Height()
{
    return _height;
}

int Command_Influence::get_Width()
{
    return _width;
}

// Walls DO block influence.
void Command_Influence::calcInfluence(vector<VecXY_Float> &friendlies, vector<VecXY_Float> &enemies, Level &level, vector<vector<int> > &crude_visibility)
{
    float Id=0, currInf=0, inf=0;
    float I0=5.0;
    int source_grid_x=0, source_grid_y=0, grid_x=0, grid_y=0;
    VecXY_Float sourcePos;
    Influence_Type type = EXPONENTIAL;
    Tile source_tile;
    Tile propagate_tile;

    /// clear influence
    friendly_inf.clear();
    friendly_inf.resize(_height, vector<float>(_width, 0));
    opponent_inf.clear();
    opponent_inf.resize(_height, vector<float>(_width, 0));
    friendly_max =0;
    friendly_min=0;
    opponent_max=0;
    opponent_min=0;

    /// apply friendly sources
    for(unsigned int i = 0; i < friendlies.size(); i++)
    {
        sourcePos = friendlies[i];
        level.getGridPositionFromPixels(sourcePos.getX(), sourcePos.getY(), source_grid_x, source_grid_y);
        sourcePos.setX(source_grid_x);
        sourcePos.setY(source_grid_y);

        //TODO (imp#3#) Add influence type to agent info.
        level.get_tile(source_grid_x, source_grid_y, source_tile);

        /// propagate influence
        for(unsigned int p = 0; p < level.get_total_tiles(); p++)
        {
            level.get_tile(p, propagate_tile);
            propagate_tile.GetGridPosition(grid_x, grid_y);
            if(propagate_tile.get_type() == 3) { Id = 0; }
            else { Id = applyFormula(type, I0, sourcePos, grid_x, grid_y); }

            currInf = friendly_inf[grid_y][grid_x];
            inf = currInf + Id;

            /// set influence
            friendly_inf[grid_y][grid_x] = inf;

            friendly_max = maximum(friendly_max, inf);
            friendly_min = minimum(friendly_min, inf);
        }
    }

    // Apply enemy sources
    for(unsigned int i = 0; i < enemies.size(); i++)
    {
        sourcePos = enemies[i];
        level.getGridPositionFromPixels(sourcePos.getX(), sourcePos.getY(), source_grid_x, source_grid_y);
        sourcePos.setX(source_grid_x);
        sourcePos.setY(source_grid_y);

        //TODO (imp#3#) Add influence type to agent info.
        level.get_tile(source_grid_x, source_grid_y, source_tile);

        /// propagate influence
        for(unsigned int p = 0; p < level.get_total_tiles(); p++)
        {
            level.get_tile(p, propagate_tile);
            propagate_tile.GetGridPosition(grid_x, grid_y);
            if(propagate_tile.get_type() == 3) { Id = 0; }
            else { Id = applyFormula(type, I0, sourcePos, grid_x, grid_y); }

            currInf = opponent_inf[grid_y][grid_x];
            inf = currInf + Id;

            /// set influence
            opponent_inf[grid_y][grid_x] = inf;

            opponent_max = maximum(opponent_max, inf);
            opponent_min = minimum(opponent_min, inf);

            if(inf >= opponent_max) { enemyMax = Coord(grid_x, grid_y); }
        }
    }

    /// Other map configs
    calcGeneralInfluence();
    calcTension();
    calcVulnerability();

    vulAVisPts.clear();
    vulBVisPts.clear();

    for (int j = 0; j < level.corridors.size(); ++j) {
        int corrNodeX = (level.corridors[j].pos.getX() * 40) +20;
        int corrNodeY = (level.corridors[j].pos.getY() * 40) +20;
        int vulAX = (vulnerableA.getX() * 40) +20;
        int vulAY = (vulnerableA.getY() * 40) +20;
        int vulBX = (vulnerableB.getX() * 40) +20;
        int vulBY = (vulnerableB.getY() * 40) +20;

        if(checkLOS(vulAX, vulAY, corrNodeX, corrNodeY, level)) {
            vulAVisPts.push_back(level.corridors[j].pos);
        }

        if(checkLOS(vulBX, vulBY, corrNodeX, corrNodeY, level)) {
            vulBVisPts.push_back(level.corridors[j].pos);
        }
    }
}

// Friendly influence minus opponent influence
void Command_Influence::calcGeneralInfluence()
{
    float inf = 0;

    /// clear influence
    general.clear();
    general.resize(_height, vector<float>(_width, 0));
    gen_max=0;
    gen_min=0;

    for(int row = 0; row < _height; row++)
    {
        for(int col = 0; col < _width; col++)
        {
            inf = friendly_inf[row][col] - opponent_inf[row][col];
            general[row][col] = inf;

            gen_max = maximum(gen_max, inf);
            gen_min = minimum(gen_min, inf);
        }
    }
}

// Friendly influence plus opponent influence. A sum of all influence.
void Command_Influence::calcTension()
{
    float inf = 0;

    /// clear influence
    tension.clear();
    tension.resize(_height, vector<float>(_width, 0));
    ten_max=0;
    ten_min=0;


    for(int row = 0; row < _height; row++)
    {
        for(int col = 0; col < _width; col++)
        {
            inf = friendly_inf[row][col] +opponent_inf[row][col];
            tension[row][col] = inf;
            ten_max = maximum(ten_max, inf);
            ten_min = minimum(ten_min, inf);
        }
    }
}

void Command_Influence::calcVulnerability()
{
    float inf = 0;

    /// clear influence
    vulnerability.clear();
    vulnerability.resize(_height, vector<float>(_width, 0));
    vul_max=0;
    vul_min=0;
    vulAVal = 0;
    vulBVal = 0;

    // set inf and vulA
    for(int row = 0; row < _height; row++)
    {
        for(int col = 0; col < _width; col++)
        {
            inf = tension[row][col] - abs(general[row][col]);
            vulnerability[row][col] = inf;
            vul_max = maximum(vul_max, inf);
            vul_min = minimum(vul_min, inf);

            if(inf > vulAVal) {
                vulAVal = inf;
                vulnerableA = Coord(col, row);
            }
        }
    }

    // set vulB
    float test = 0;
    for(int row = 0; row < _height; row++)
    {
        for(int col = 0; col < _width; col++)
        {
            test = vulnerability[row][col];
            float currDist = sqrt(pow((float)(vulnerableA.getX() - col), 2.0f) + pow((float)(vulnerableA.getY() - row), 2.0f));
            if(test > vulBVal && currDist >= 6.0f) {
                vulBVal = test;
                vulnerableB = Coord(col, row);
//                std::cout << "vul dist: " << currDist << std::endl;
            }
        }
    }
}

void Command_Influence::setupInfluenceMaps()
{
    friendly_inf.resize(_height, vector<float>(_width, 0));
    opponent_inf.resize(_height, vector<float>(_width, 0));
    general.resize(_height, vector<float>(_width, 0));
    tension.resize(_height, vector<float>(_width, 0));
    vulnerability.resize(_height, vector<float>(_width, 0));
}

//void InfluenceMaps::reCalculateAll(vector<AI_Agent> &allyAgents, vector<AI_Agent> &oppAgents)
//{
//    calcAllyInfluence(allyAgents);
//    calcOppInfluence(oppAgents);
//
//    calcGeneralInfluence();
//    calcTension();
//    calcVulnerability();
//}

float Command_Influence::applyFormula(Influence_Type type, float I0, VecXY_Float sourcePos, int column, int row)
{
    float Id = 0;

    switch(type)
    {
        case LINEAR:
        {
            Id = infFormula_A(I0, sourcePos, column, row);
        }
        break;

        case EXPONENTIAL:
        {
            Id = infFormula_B(I0, sourcePos, column, row);
        }
        break;

        default:
        {}

    }

    return Id;
}

float Command_Influence::infFormula_A(float &I0, VecXY_Float &sourcePos, int &column, int &row)
{
    float Id=0, xDiff=0, yDiff=0;
    float d=0;

    xDiff = sourcePos.getX() - (float)column;
    yDiff = sourcePos.getY() - (float)row;
    d = sqrt( xDiff*xDiff + yDiff*yDiff);

    Id = I0/(d+1);

    return Id;
}

float Command_Influence::infFormula_B(float &I0, VecXY_Float &sourcePos, int &column, int &row)
{
    /// from Game Progamming Gems 2 : Influence Mapping
    float Id=0, xDiff=0, yDiff=0;
    float d=0, fallOff=0, multi=0;

    xDiff = sourcePos.getX() - (float)column;
    yDiff = sourcePos.getY() - (float)row;
    d = sqrt( xDiff*xDiff + yDiff*yDiff);

//    fallOff = 0.75;
//    fallOff = 0.25;
    fallOff = 0.5;
    multi = pow(fallOff,d);

    Id = I0 * multi;

    return Id;
}

float Command_Influence::maximum(float m1, float m2)
{
    if(m1>m2)
    {
        return m1;
    }
    else
    {
        return m2;
    }
}

float Command_Influence::minimum(float m1, float m2)
{
    if(m1<m2)
    {
        return m1;
    }
    else
    {
        return m2;
    }
}

/// checks LOS
bool Command_Influence::checkLOS(int x1, int y1, int x2, int y2, Level& level)
{
    /// from http://playtechs.blogspot.com/2007/03/raytracing-on-grid.html
    //cerr << "Game.checkLOS()" << endl;
    bool LOS = true;
    int gx1 = -1, gy1 = -1, gx2 = -1, gy2 = -1;

    if ((level.getGridPositionFromPixels(x1,y1,gx1, gy1)) && (level.getGridPositionFromPixels(x2,y2,gx2, gy2)))
    {
        int dx = abs(x2 - x1);
        int dy = abs(y2 - y1);
        int x = x1;
        int y = y1;
        int n = 1 + dx + dy;
        int x_inc = (x2 > x1) ? 1 : -1;
        int y_inc = (y2 > y1) ? 1 : -1;
        int error = dx - dy;
        dx *= 2;
        dy *= 2;

        Tile check_tile;
        Box tile_box;
        level.get_tile(gx1, gy1, check_tile);
        tile_box = check_tile.get_box();

        while((LOS != false) && (n > 0))
        {
            // check if tile is an obstacle
            if(check_tile.get_type() == constants::ENUM_HIGH_WALL)
            {
                // LOS is blocked
                LOS = false;
            }
            else
            {
                // check if x&y are within bounds of the current tile
                if((x >= tile_box.get_x()) && (x < tile_box.get_x() + tile_box.get_w()) && (y >= tile_box.get_y()) && (y < tile_box.get_y() + tile_box.get_h()))
                {
                    // within bounds thus continue
                    // step to next pixel
                    if (error > 0)
                    {
                        x += x_inc;
                        error -= dy;
                    }
                    else
                    {
                        y += y_inc;
                        error += dx;
                    }

                    //pixelRGBA(mapView, x, y, 255,255,255,255);

                    n--;
                }
                else
                {
                    // get new tile
                    if(level.getGridPositionFromPixels(x,y,gx1, gy1))
                    {
                        // if not get new tile
                        if(level.get_tile(gx1, gy1, check_tile) == false)
                        {
                            LOS = false;
                            break;
                        }
                        else
                        {
                            tile_box = check_tile.get_box();
                        }
                    }
                    else
                    {
                        LOS = false;
                        break;
                    }

                }
            }
        }
    }

    return LOS;
}
