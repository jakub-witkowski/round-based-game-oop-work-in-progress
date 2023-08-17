#include <iostream>
#include "unit.h"
#include "map_size.h"

class Archer : public Unit
{
    public:

    Archer(char aff, long* g)
    {
        type = 'A';
        current_stamina = 40;
        movement_points_left = 2;
        can_attack_enemy_units = true;
        cost = 250;
        training_time_left = 3;
        attack_range = 5;

        id = number_of_active_units;
        number_of_active_units++;
        *g -= cost;

        if ((affiliation = aff) == 'P')
        {
            coordinates.first = 0;
            coordinates.second = 0;
        } 
        else
        {
            coordinates.first = map_size_x - 1;
            coordinates.second = map_size_y - 1;
        }

        std::cout
        << "\nArcher: " << std::endl
        << "affiliation: " << affiliation << std::endl
        << "unit id: " << id <<std::endl
        << "x coord: " << coordinates.first << std::endl
        << "y coord: " << coordinates.second << std::endl
        << "stamina: " << current_stamina << std::endl
        << "movement points left: " << movement_points_left << std::endl
        << "attack possible?: " << can_attack_enemy_units << std::endl
        << "gold left: " << *g << std::endl
        << "number of units on the map: " << number_of_active_units << std::endl;
    }
};