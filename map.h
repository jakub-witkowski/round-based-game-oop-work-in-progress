#ifndef MAP_H
#define MAP_H

#include <string>
#include <vector>

#include "map_size.h"

class Map
{
    private:
    int map[map_size_y][map_size_x];

    public:

    Map(std::string f)
    {
        parse_map(f, map_size_y, map);
    }

    //int line_count(std::string);

    //int col_count(std::string);

    void parse_map(std::string, int, int[][map_size_x]);

    //bool can_move_to(int, int);
};

#endif