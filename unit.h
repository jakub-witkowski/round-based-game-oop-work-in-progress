#ifndef UNIT_H
#define UNIT_H

//#include "base.h"
#include <vector>

class Unit
{
    public:
    static int number_of_active_units;
 
    char type;
    char affiliation;
    int id;
    /*int x_coord;
    int y_coord;*/
    std::pair<int, int> coordinates;
    int movement_points_left; 
    int current_stamina;
    bool can_attack_enemy_units;
    int training_time_left;
    int cost;
    int attack_range;
    bool is_base_busy;

    void update_training_time(std::vector<Unit*>);

    void move(int (*)(int, int), char, const int, const int);

    void attack();
};

#endif