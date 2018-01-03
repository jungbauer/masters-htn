#include "Draw.h"

Draw::Draw()
{}

void Draw::show_Graph(Graph &graph, Level &level, Box camera)
{
    for(unsigned int n = 0; n < graph.nodes_.size(); n++)
    {
        int x = 0, y =0, x_centre = 0, y_centre = 0;

        if(level.getPixelPositionFromGrid(graph.nodes_[n].x_pos, graph.nodes_[n].y_pos, x, y))
        {
            // drawing node
            x_centre = x - camera.get_x();
            y_centre = y - camera.get_y();

            RGBA colour = colours::gold;
            filledCircleRGBA(mapView, x_centre, y_centre, 5, colour.getRed(), colour.getGreen(), colour.getBlue(), colour.getAlpha());

            // drawing connections
            int half_width  = constants::TILE_WIDTH / 2;
            int half_height = constants::TILE_HEIGHT / 2;
            if(graph.nodes_[n].connections[0].getValid() == true)
            {
                lineRGBA(mapView, x_centre, y_centre, x_centre, y_centre - half_height, colour.getRed(), colour.getGreen(), colour.getBlue(), colour.getAlpha());
            }
            if(graph.nodes_[n].connections[1].getValid() == true)
            {
                lineRGBA(mapView, x_centre, y_centre, x_centre + half_width, y_centre - half_height, colour.getRed(), colour.getGreen(), colour.getBlue(), colour.getAlpha());
            }
            if(graph.nodes_[n].connections[2].getValid() == true)
            {
                lineRGBA(mapView, x_centre, y_centre, x_centre + half_width, y_centre, colour.getRed(), colour.getGreen(), colour.getBlue(), colour.getAlpha());
            }
            if(graph.nodes_[n].connections[3].getValid() == true)
            {
                lineRGBA(mapView, x_centre, y_centre, x_centre + half_width, y_centre + half_height, colour.getRed(), colour.getGreen(), colour.getBlue(), colour.getAlpha());
            }
            if(graph.nodes_[n].connections[4].getValid() == true)
            {
                lineRGBA(mapView, x_centre, y_centre, x_centre, y_centre + half_height, colour.getRed(), colour.getGreen(), colour.getBlue(), colour.getAlpha());
            }
            if(graph.nodes_[n].connections[5].getValid() == true)
            {
                lineRGBA(mapView, x_centre, y_centre, x_centre - half_width, y_centre + half_height, colour.getRed(), colour.getGreen(), colour.getBlue(), colour.getAlpha());
            }
            if(graph.nodes_[n].connections[6].getValid() == true)
            {
                lineRGBA(mapView, x_centre, y_centre, x_centre - half_width, y_centre, colour.getRed(), colour.getGreen(), colour.getBlue(), colour.getAlpha());
            }
            if(graph.nodes_[n].connections[7].getValid() == true)
            {
                lineRGBA(mapView, x_centre, y_centre, x_centre - half_width, y_centre - half_height, colour.getRed(), colour.getGreen(), colour.getBlue(), colour.getAlpha());
            }
        }
    }
}

void Draw::show_Level(Level &level, Box camera, bool grid)
{
    //Show the tiles
    for(unsigned int t = 0; t < level.tiles_.size(); t++ )
    {
        show_Tile(level.tiles_[t], camera, grid);
    }

    RGBA colour = colours::black;
    for(unsigned int c =0; c < level.corridors.size(); c++){
        filledCircleRGBA(mapView, (level.corridors[c].pos.getX() * 40)+20, (level.corridors[c].pos.getY() * 40)+20, 10, colour.getRed(), colour.getGreen(), colour.getBlue(), colour.getAlpha());
        for(unsigned int x =0; x < level.corridors[c].connectedNodes.size(); x++){
            lineRGBA(mapView, (level.corridors[c].pos.getX() * 40)+20, (level.corridors[c].pos.getY() * 40)+20,
                     (level.corridors[level.corridors[c].connectedNodes[x]].pos.getX() * 40)+20,
                     (level.corridors[level.corridors[c].connectedNodes[x]].pos.getY() * 40)+20, colour.getRed(), colour.getGreen(), colour.getBlue(), colour.getAlpha());
        }
    }
}

void Draw::show_Tile(Tile &tile, Box camera, bool grid)
{
    Box box = tile.get_box();
    //If the tile is on screen
    if(utils::check_collision(camera, box) == true)
    {
        //Show the tile
        surfaces::apply_surface(box.get_x() - camera.get_x(), box.get_y() - camera.get_y(), tileSheet, mapView, &clips[tile.get_type()] );
    }

    if(grid == true)
    {
        RGBA colour = colours::white;
        rectangleRGBA(mapView, box.get_x() - camera.get_x(), box.get_y() - camera.get_y(), box.get_x() + box.get_w() - 1, box.get_y() + box.get_h() - 1, colour.getRed(), colour.getGreen(), colour.getBlue(), colour.getAlpha());
    }
}

void Draw::show_Bullet(Bullet &bullet, Box camera)
{
    RGBA colour = colours::black;
    int x_offset = bullet.get_Position().getX() - camera.get_x();
    int y_offset = bullet.get_Position().getY() - camera.get_y();
    filledCircleRGBA(mapView, x_offset, y_offset, bullet.get_Radius(), colour.getRed(), colour.getGreen(), colour.getBlue(), colour.getAlpha());
}

void Draw::show_Path(Path &path, Graph &graph, Level &level, Box camera)
{
    for(unsigned int c =0; c < path._path.size(); c++)
    {
        Node from_node = graph.getNode(path._path[c].getFromNode());
        Tile from_tile;
        if(level.get_tile(from_node.x_pos, from_node.y_pos, from_tile) == true)
        {
            int x_f = 0, y_f =0, x_f_offset = 0, y_f_offset = 0;
            from_tile.GetCentrePixels(x_f,y_f);
            x_f_offset = x_f - camera.get_x();
            y_f_offset = y_f - camera.get_y();

            RGBA colour = colours::blue_violet;
            filledCircleRGBA(mapView, x_f_offset, y_f_offset, 10, colour.getRed(), colour.getGreen(), colour.getBlue(), colour.getAlpha());

            Node to_node = graph.getNode(path._path[c].getToNode());
            Tile to_tile;
            if(level.get_tile(to_node.x_pos, to_node.y_pos, to_tile) == true)
            {
                int x_t = 0, y_t =0, x_t_offset = 0, y_t_offset = 0;
                to_tile.GetCentrePixels(x_t,y_t);
                x_t_offset = x_t - camera.get_x();
                y_t_offset = y_t - camera.get_y();

                filledCircleRGBA(mapView, x_t_offset, y_t_offset, 10, colour.getRed(), colour.getGreen(), colour.getBlue(), colour.getAlpha());
                lineRGBA(mapView, x_f_offset, y_f_offset, x_t_offset, y_t_offset, colour.getRed(), colour.getGreen(), colour.getBlue(), colour.getAlpha());
            }
        }
    }
}

void Draw::show_culled_Path(Path &path, Box camera)
{
    for(unsigned int c =0; c < path._culled_path.size(); c++)
    {
        int x_offset = path._culled_path[c].getX() - camera.get_x();
        int y_offset = path._culled_path[c].getY() - camera.get_y();

        RGBA colour = colours::burlywood;
        filledCircleRGBA(mapView, x_offset, y_offset, 7, colour.getRed(), colour.getGreen(), colour.getBlue(), colour.getAlpha());

        if(c < path._culled_path.size()-1)
        {
            int x_t_offset = path._culled_path[c+1].getX() - camera.get_x();
            int y_t_offset = path._culled_path[c+1].getY() - camera.get_y();
            lineRGBA(mapView, x_offset, y_offset, x_t_offset, y_t_offset, colour.getRed(), colour.getGreen(), colour.getBlue(), colour.getAlpha());
        }
    }
}

void Draw::show_AI_Agent(AI_Agent &agent, Level &level, Box camera, bool debug)
{
    //TODO (cleaner#3#) Use Coord to clean up the x's & y's here.
    RGBA char_colour, fov_colour, orient_colour;
    RGBA life_colour = colours::lime;
    int fov_alpha = 255;

    /// path
    if(debug == true)
    {
        show_culled_Path(agent.info.path, camera);
    }

    if(agent.info.team == 1)
    {
        char_colour = colours::blue;
        fov_colour = colours::blue;
        fov_alpha = 20;
    }
    else
    {
        char_colour = colours::red;
        fov_colour = colours::red;
        fov_alpha = 20;
    }

    /// General character circle
    int x_offset = agent.info.current_position.getX() - camera.get_x();
    int y_offset = agent.info.current_position.getY() - camera.get_y();
    filledCircleRGBA(mapView, x_offset, y_offset, (int)agent.info.radius, char_colour.getRed(), char_colour.getGreen(), char_colour.getBlue(), char_colour.getAlpha());
    float health = (agent.info.health/agent.info.max_health)*359;
    filledPieRGBA(mapView, x_offset, y_offset, (int)agent.info.radius - 2, 0, health, life_colour.getRed(), life_colour.getGreen(), life_colour.getBlue(), life_colour.getAlpha());
    filledCircleRGBA(mapView, x_offset, y_offset, (int)agent.info.radius - 5, char_colour.getRed(), char_colour.getGreen(), char_colour.getBlue(), char_colour.getAlpha());

    /// Orientation line
    int p_x = ((int)agent.info.radius + 5) * cos(agent.info.orientation*constants::PIE/180);
    int p_y = ((int)agent.info.radius + 5) * sin(agent.info.orientation*constants::PIE/180);
    orient_colour = colours::black;
    lineRGBA(mapView, x_offset, y_offset, x_offset + p_x, y_offset + p_y, orient_colour.getRed(), orient_colour.getGreen(), orient_colour.getBlue(), orient_colour.getAlpha());

    /// pathing target
//    int x_path_offset = _AI.nextPathCoord.getX() - camera.x;
//    int y_path_offset = _AI.nextPathCoord.getY() - camera.y;
//    filledCircleRGBA(mapView, x_path_offset, y_path_offset, (int)_AI.radius, orient_colour.getRed(), orient_colour.getGreen(), orient_colour.getBlue(), orient_colour.getAlpha());

//    // Field Of View
//    float a = _AI.orientation - (_AI.fov / 2);
//    float b = _AI.orientation + (_AI.fov / 2);
//    filledPieRGBA(mapView, x_offset, y_offset, _AI.vision_range, a, b, fov_colour.getRed(), fov_colour.getGreen(), fov_colour.getBlue(), fov_alpha);

    // Attack range
    float a = agent.info.orientation - (agent.info.fov / 2);
    float b = agent.info.orientation + (agent.info.fov / 2);
    filledPieRGBA(mapView, x_offset, y_offset, agent.info.attack_range, a, b, fov_colour.getRed(), fov_colour.getGreen(), fov_colour.getBlue(), fov_alpha);

    // seen enemies
    if(debug)
    {
        for(unsigned int i = 0; i < agent.info.seen_enemies.size(); i++)
        {
            VecXY_Float pos = agent.info.seen_enemies[i].current_position;
            int enemy_x = pos.getX() - camera.get_x();
            int enemy_y = pos.getY() - camera.get_y();
            lineRGBA(mapView, x_offset, y_offset, enemy_x, enemy_y, orient_colour.getRed(), orient_colour.getGreen(), orient_colour.getBlue(), orient_colour.getAlpha());
            //filledCircleRGBA(mapView, enemy_x, enemy_y, 5, orient_colour.getRed(), orient_colour.getGreen(), orient_colour.getBlue(), orient_colour.getAlpha());
        }
    }


    // target enemy
    if(debug)
    {
        if(agent.info.validateTarget(agent.info.attack_target))
        {
            int target_x_off = agent.info.attack_target.current_position.getX() - camera.get_x();
            int target_y_off = agent.info.attack_target.current_position.getY() - camera.get_y();
            lineRGBA(mapView, x_offset, y_offset, target_x_off, target_y_off, 255, 255, 255, 255);
            //filledCircleRGBA(mapView, x_off, y_off, 5, 255, 255, 255, 255);
        }
    }

    // support positions
//    if(debug && agent.info.squad_leader)
//    {
//        vector<VecXY_Float> support_positions;
//        agent.info.get_Support_Positions(support_positions);
//
//        //VecXY_Float offset = VecXY_Float(x_offset, y_offset);
//
//        for(unsigned int i = 0; i < support_positions.size(); i++)
//        {
//            if(level.levelCollisionCheck_Circle(support_positions[i], agent.info.radius) == false)
//            {
//                filledCircleRGBA(mapView, support_positions[i].getX() - camera.get_x(), support_positions[i].getY() - camera.get_y(), 5, orient_colour.getRed(), orient_colour.getGreen(), orient_colour.getBlue(), orient_colour.getAlpha());
//                circleRGBA(mapView, support_positions[i].getX() - camera.get_x(), support_positions[i].getY() - camera.get_y(), agent.info.radius, orient_colour.getRed(), orient_colour.getGreen(), orient_colour.getBlue(), orient_colour.getAlpha());
//            }
//            else
//            {
//                filledCircleRGBA(mapView, support_positions[i].getX() - camera.get_x(), support_positions[i].getY() - camera.get_y(), 5, 255, 0, 0, 255);
//                circleRGBA(mapView, support_positions[i].getX() - camera.get_x(), support_positions[i].getY() - camera.get_y(), agent.info.radius, 255, 0, 0, 255);
//            }
//        }
//    }
}

void Draw::show_Squad(Squad &sqd, Box camera)
{
    float orientation = 0;
    VecXY_Float desired;
    vector<VecXY_Float> valid_pos;

    RGBA colour = colours::black;

    sqd.get_Draw_Info(orientation, desired, valid_pos);

    int p_x = (20) * cos(orientation*constants::PIE/180);
    int p_y = (20) * sin(orientation*constants::PIE/180);
    lineRGBA(mapView, desired.getX() - camera.get_x(), desired.getY() - camera.get_y(), desired.getX() - camera.get_x() + p_x, desired.getY() - camera.get_y() + p_y, colour.getRed(), colour.getGreen(), colour.getBlue(), colour.getAlpha());

    for(unsigned int i = 0; i < valid_pos.size(); i++)
    {
        filledCircleRGBA(mapView, valid_pos[i].getX() - camera.get_x(), valid_pos[i].getY() - camera.get_y(), 5, colour.getRed(), colour.getGreen(), colour.getBlue(), colour.getAlpha());
    }
}

void Draw::show_Location(Location &loc, Box camera, bool debug)
{
    RGBA colour;
    SDL_Color textColor;
    get_Location_Colours(loc.get_type(), colour, textColor);

    int x, y;
    loc.GetCentrePixels(x, y);

    Coord draw_position = Coord(loc.get_box().get_x() - camera.get_x(), loc.get_box().get_y() - camera.get_y());

    boxRGBA(mapView, draw_position.getX(), draw_position.getY(), loc.get_box().get_x() + loc.get_box().get_w() - 1, loc.get_box().get_y() + loc.get_box().get_h() - 1, colour.getRed(), colour.getGreen(), colour.getBlue(), colour.getAlpha());
    filledCircleRGBA(mapView, x, y, 3, textColor.r, textColor.g, textColor.b, colour.getAlpha());

    if(debug)
    {
        surfaces::textToSurface(loc.get_Text(loc.get_type()), textColor, mapView, draw_position.getX(), draw_position.getY());
        surfaces::textToSurface(loc.get_Name(), textColor, mapView, draw_position.getX(), draw_position.getY() + 10);

        surfaces::textToSurface("Items:", textColor, mapView, draw_position.getX(), draw_position.getY() + 30);
        for(unsigned int i = 0; i < loc.items.size(); i++)
        {
            std::string text = loc.items[i].get_Text(loc.items[i].item_type) + " - " + utils::floatToString(loc.items[i].item_quantity);
            surfaces::textToSurface(text, textColor, mapView, draw_position.getX(), draw_position.getY() + (40 +(10*i)));
        }
    }
}

void Draw::get_Location_Colours(constants::Locations tileType, RGBA &colour, SDL_Color &text)
{
    switch(tileType)
    {
        case constants::LOC_DEFAULT:
            {
                colour = colours::black;
                text.r = 0;
                text.g = 0;
                text.b = 0;
                //text = { 0, 0,0};
            }
        break;

//        default:
//            return colours::gold;
    }
}

void Draw::night(int w, int h)
{
    RGBA colour = colours::black;
    colour.setAlpha(100);

    boxRGBA(mapView,0,0,w,h,colour.getRed(), colour.getGreen(), colour.getBlue(), colour.getAlpha());
}

//void Draw::show_Influence_Mini_Level(Level &level)
//{
//    int x = 0, y = 0;
//    int mini_size = 15; //TODO (better#3#) Put the 15 size inside Constants.h as inf_mini_size or similar.
//    RGBA open_space = colours::black;
//    RGBA blocked_space = colours::dark_grey;
//
//    for(unsigned int t = 0; t < level.tiles_.size(); t++ )
//    {
//        level.tiles_[t].GetGridPosition(x, y);
//        if((level.tiles_[t].get_type() == 1) || (level.tiles_[t].get_type() == 2))
//        {
//            boxRGBA(influenceMini, x * mini_size, y * mini_size, x * mini_size + mini_size - 1, y * mini_size + mini_size - 1,open_space.getRed(), open_space.getGreen(), open_space.getBlue(), open_space.getAlpha());
//        }
//
//        level.tiles_[t].GetGridPosition(x, y);
//        if((level.tiles_[t].get_type() == 3) || (level.tiles_[t].get_type() == 4))
//        {
//            boxRGBA(influenceMini, x * mini_size, y * mini_size, x * mini_size + mini_size - 1, y * mini_size + mini_size - 1,blocked_space.getRed(), blocked_space.getGreen(), blocked_space.getBlue(), blocked_space.getAlpha());
//        }
//    }
//}
//
//void Draw::show_Influence_Mini_Agent(VecXY_Float pos, float rad, int team)
//{
//    RGBA colour = colours::white;
//    RGBA team1 = colours::blue;
//    RGBA team2 = colours::red;
//
//    // The mini block size is 15. That is 37.5% of the normal block size of 40.
//    VecXY_Float new_pos = (pos / 1000) * 375;
//    float new_rad = (rad / 1000) * 357;
//    filledCircleRGBA(influenceMini, new_pos.getX(), new_pos.getY(), new_rad, colour.getRed(), colour.getGreen(), colour.getBlue(), colour.getAlpha());
//
//    if(team == 1)
//    {
//        filledCircleRGBA(influenceMini, new_pos.getX(), new_pos.getY(), new_rad/1.5, team1.getRed(), team1.getGreen(), team1.getBlue(), team1.getAlpha());
//    }
//    else
//    {
//        filledCircleRGBA(influenceMini, new_pos.getX(), new_pos.getY(), new_rad/1.5, team2.getRed(), team2.getGreen(), team2.getBlue(), team2.getAlpha());
//    }
//}
//
////TODO (imp#3#) Make it possible to shift between the different influence views.
//void Draw::show_Influence_Mini_Power(InfluenceMaps &inf_maps)
//{
//    float inf=0, alpha=0;
//    float infMax = inf_maps.team1_max;
//    float infMin = inf_maps.team1_min;
//    RGBA colour = colours::blue;
//    RGBA text = colours::white;
//    int mini_size = 15; //TODO (better#3#) Put the 15 size inside Constants.h as inf_mini_size or similar.
//
//    for(int row = 0; row < inf_maps.get_Height(); row++)
//    {
//        for(int col = 0; col < inf_maps.get_Width(); col++)
//        {
//            inf = inf_maps.team1[row][col];
//            if(inf >= 0)
//            {
//                alpha = ((inf/infMax)*255.0);
//            }
//            else
//            {
//                alpha = ((inf/infMin)*255.0);
//            }
//            colour.setAlpha((int)alpha);
//            boxRGBA(influenceMini, col * mini_size, row * mini_size, col * mini_size + mini_size - 1, row * mini_size + mini_size - 1,colour.getRed(), colour.getGreen(), colour.getBlue(), colour.getAlpha());
////            std::string infstr = utils::intToString((int)inf);
////            stringRGBA(influenceMini, col * mini_size, row * mini_size, infstr.c_str(), text.getRed(), text.getGreen(), text.getBlue(), text.getAlpha());
//        }
//    }
//}

void Draw::show_Influence_Main(Command_Influence &inf_maps, int map_type)
{
    float inf=0, alpha=0;
    float infMax = 0;
    float infMin = 0;
    RGBA colour = colours::blue;

    /// Setting max and min alpha
    //TODO (gen#3#) Clean up this mess.
    if(map_type == 1)
    {
        infMax = inf_maps.friendly_max;
        infMin = inf_maps.friendly_min;
    }
    if(map_type == 2)
    {
        infMax = inf_maps.opponent_max;
        infMin = inf_maps.opponent_min;
    }
    if(map_type == 3)
    {
        infMax = inf_maps.gen_max;
        infMin = inf_maps.gen_min;
    }
    if(map_type == 4)
    {
        infMax = inf_maps.ten_max;
        infMin = inf_maps.ten_min;
    }
    if(map_type == 5)
    {
        infMax = inf_maps.vul_max;
        infMin = inf_maps.vul_min;
    }

    for(int row = 0; row < inf_maps.get_Height(); row++)
    {
        for(int col = 0; col < inf_maps.get_Width(); col++)
        {
            /// getting inf
            //TODO (gen#3#) Clean up this mess.
            if(map_type == 1)
            {
                inf = inf_maps.friendly_inf[row][col];
            }
            if(map_type == 2)
            {
                inf = inf_maps.opponent_inf[row][col];
            }
            if(map_type == 3)
            {
                inf = inf_maps.general[row][col];
            }
            if(map_type == 4)
            {
                inf = inf_maps.tension[row][col];
            }
            if(map_type == 5)
            {
                inf = inf_maps.vulnerability[row][col];
            }

            /// work
            if(inf >= 0)
            {
                alpha = ((inf/infMax)*255.0);
                colour = colours::blue;
            }
            else
            {
                alpha = ((inf/infMin)*255.0);
                colour = colours::red;
            }
            colour.setAlpha((int)alpha);

            /// drawing
            boxRGBA(mapView, col * 40, row * 40, col * 40 + 40 - 1, row * 40 + 40 - 1,colour.getRed(), colour.getGreen(), colour.getBlue(), colour.getAlpha());
        }
    }
}

void Draw::show_Influence_Main_Values(Command_Influence &inf_maps, int map_type)
{
    float inf = 0;
    RGBA text = colours::white;

    for(int row = 0; row < inf_maps.get_Height(); row++)
    {
        for(int col = 0; col < inf_maps.get_Width(); col++)
        {
            //TODO (gen#3#) Clean up this mess.
            if(map_type == 1)
            {
                inf = inf_maps.friendly_inf[row][col];
            }
            if(map_type == 2)
            {
                inf = inf_maps.opponent_inf[row][col];
            }
            if(map_type == 3)
            {
                inf = inf_maps.general[row][col];
            }
            if(map_type == 4)
            {
                inf = inf_maps.tension[row][col];
            }
            if(map_type == 5)
            {
                inf = inf_maps.vulnerability[row][col];
            }

            //Draw
            std::string infstr = utils::intToString((int)inf);
            stringRGBA(mapView, col * 40, row * 40, infstr.c_str(), text.getRed(), text.getGreen(), text.getBlue(), text.getAlpha());
        }
    }
}

void Draw::show_EnemyMaxInf(Coord pos) {
    RGBA colour = colours::gainsboro;
    /// General character circle
    filledCircleRGBA(mapView, (pos.getX() * 40) + 20, (pos.getY() * 40) + 20, 10, colour.getRed(), colour.getGreen(), colour.getBlue(), colour.getAlpha());
}

void Draw::show_VulnerablePoint(Coord pos) {
    RGBA colour = colours::blue_violet;
    /// General character circle
    filledCircleRGBA(mapView, (pos.getX() * 40) + 20, (pos.getY() * 40) + 20, 10, colour.getRed(), colour.getGreen(), colour.getBlue(), colour.getAlpha());
}

void Draw::show_VulnerableAssPoint(Coord pos) {
    RGBA colour = colours::brown;
    /// General character circle
    filledCircleRGBA(mapView, (pos.getX() * 40) + 20, (pos.getY() * 40) + 20, 10, colour.getRed(), colour.getGreen(), colour.getBlue(), colour.getAlpha());
}

void Draw::show_Crude_Vision(Level &level, vector<vector<int> > crude_visibility, Box camera, bool values)
{
    //Mouse offsets
    int x = 0, y = 0;

    //Get mouse offsets
    SDL_GetMouseState( &x, &y );

    x = x - constants::MAP_VIEW_X + camera.get_x();
    y = y - constants::MAP_VIEW_Y + camera.get_y();

    Tile hover_tile;
    Tile draw_tile;
    Box hover_box;
    Box draw_box;
    int gx=0, gy=0;
    //int pos_x=0, pos_y=0;
    RGBA hover_colour = colours::blue;
    RGBA text = colours::white;
    hover_colour.setAlpha(100);

    if(level.getGridPositionFromPixels(x,y,gx,gy))
    {
        level.get_tile(gx, gy, hover_tile);
        hover_box = hover_tile.get_box();
        boxRGBA(mapView, hover_box.get_x(), hover_box.get_y(), hover_box.get_x() + hover_box.get_w() -1, hover_box.get_y() + hover_box.get_h() -1, hover_colour.getRed(), hover_colour.getGreen(), hover_colour.getBlue(), hover_colour.getAlpha());

        if(values)
        {
            std::string val = utils::intToString(crude_visibility[hover_tile.map_ref].size());
            stringRGBA(mapView, gx * 40, gy * 40, val.c_str(), text.getRed(), text.getGreen(), text.getBlue(), text.getAlpha());
        }

        for(unsigned int i = 0; i < crude_visibility[hover_tile.map_ref].size(); i++)
        {
            level.get_tile(crude_visibility[hover_tile.map_ref][i], draw_tile);
            draw_box = draw_tile.get_box();
            boxRGBA(mapView, draw_box.get_x(), draw_box.get_y(), draw_box.get_x() + draw_box.get_w() -1, draw_box.get_y() + draw_box.get_h() -1, hover_colour.getRed(), hover_colour.getGreen(), hover_colour.getBlue(), hover_colour.getAlpha());
        }
//        pos_x = gx * constants::TILE_WIDTH;
//        pos_y = gy * constants::TILE_HEIGHT;
//        boxRGBA(mapView,pos_x,pos_y,pos_x+constants::TILE_WIDTH-1,pos_y+constants::TILE_HEIGHT-1,hover_colour.getRed(), hover_colour.getGreen(), hover_colour.getBlue(), hover_colour.getAlpha());

    }
}
