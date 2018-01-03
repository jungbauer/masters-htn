#ifndef DRAW_H
#define DRAW_H

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_gfxPrimitives.h>
#include <SDL/SDL_ttf.h>

#include <vector>

#include "Level.h"
#include "Bullet.h"

#include "Locations/Location.h"

#include "AI/AI_Agent.h"
#include "AI/Squad.h"
//#include "AI/InfluenceMaps.h"
#include "AI/Command_Influence.h"

#include "Pathfinding/Graph.h"
#include "Pathfinding/Path.h"
#include "Pathfinding/Connection.h"

#include "Utils/Constants.h"
#include "Utils/Box.h"
#include "Utils/Surfaces.h"
#include "Utils/Colours.h"
#include "Utils/RGBA.h"
#include "Utils/Coord.h"
#include "Utils/VecXY_Float.h"

class Draw {
	public:
        Draw();

        void show_Graph(Graph &graph, Level &level, Box camera);
        void show_Level(Level &level, Box camera, bool grid);
        void show_Tile(Tile &tile, Box camera, bool grid);
        void show_Bullet(Bullet &bullet, Box camera);
        void show_Path(Path &path, Graph &graph, Level &level, Box camera);
        void show_culled_Path(Path &path, Box camera);
        void show_AI_Agent(AI_Agent &agent, Level &level, Box camera, bool debug);
        void show_Location(Location &loc, Box camera, bool debug);
        void show_Squad(Squad &sqd, Box camera);

//        void show_Influence_Mini_Level(Level &level);
//        void show_Influence_Mini_Agent(VecXY_Float pos, float rad, int team);
//        void show_Influence_Mini_Power(InfluenceMaps &inf_maps);

		void show_Influence_Main(Command_Influence &inf_maps, int map_type);
		void show_Influence_Main_Values(Command_Influence &inf_maps, int map_type);
		void show_EnemyMaxInf(Coord pos);
		void show_VulnerablePoint(Coord pos);
		void show_VulnerableAssPoint(Coord pos);

        void show_Crude_Vision(Level &level, vector<vector<int> > crude_visibility, Box camera, bool values);

        void night(int w, int h);

        void get_Location_Colours(constants::Locations tileType, RGBA &colour, SDL_Color &text);

    private:
};

#endif
