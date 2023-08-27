#ifndef MAP_H
#define MAP_H

#include <string>
#include <vector>

class Map
{
    private:
    std::vector<std::vector<int>> map_data;

    public:

    Map(std::string f)
    {

    }

    int line_count(std::string);

    int col_count(std::string);

    void load_map_data(std::string);

    bool can_move_to(int, int);
};

#endif