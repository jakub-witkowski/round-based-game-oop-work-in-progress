#ifndef MAP_H
#define MAP_H

#include <string>

class Map
{
    private:
    int map_data{};

    public:

    void load_map_data(std::string);

    bool can_move_to(int, int);

};

#endif